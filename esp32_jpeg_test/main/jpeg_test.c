#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_log.h>
#include <esp_err.h>

#include "jpeglib.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_log.h>
#include <esp_err.h>

#include "esp_audio_mem.h"
#include "smtp_client.h"
#include "decoder.h"
#include "mbedtls/md5.h"

#define INPUT_BUFFER_SIZE 20
#define INP_IMG_WIDTH 94
#define INP_IMG_HEIGHT 94

static const char *TAG = "jpeg-testing";


extern uint8_t raw_image_start[] asm("_binary_test_100_jpeg_start");
extern uint8_t raw_image_end[]   asm("_binary_test_100_jpeg_end");

static const char hex[] = "0123456789abcdef";

static void md5_bytes_to_hex(uint8_t *in_buf, uint8_t *out_buf)
{
    for (int i = 0; i < 16; i++) {
        out_buf[i + i] = hex[in_buf[i] >> 4];
        out_buf[i + i + 1] = hex[in_buf[i] & 0x0f];
    }
    out_buf[32] = '\0';
}

static void jpeg_test_task(void *pvParameters)
{
    (void) pvParameters;
    int ret;
    ESP_LOGI(TAG, "Testing md5sum of jpeg image");
    decoder_context dec;
    dec.in_buf_sz = INPUT_BUFFER_SIZE * 1024; // 12 kb
    dec.out_buf_mem_alloc = INP_IMG_WIDTH * INP_IMG_HEIGHT * 2;
    dec.out_buf = malloc(dec.out_buf_mem_alloc);
    dec.out_color_space = JCS_RGB;
    dec.in_buf_start = raw_image_start;
    dec.in_buf_end = raw_image_end;
    ret = decode_jpeg(&dec);

    if (ret == ERR_INVALID_ARG) {
        ESP_LOGE(TAG, "Invalid Arguments Passed\n Aborting program");
        abort();
    }
    if (ret == SUCCESS) {
        ESP_LOGI(TAG, "Success");
    }
    if (ret == OUT_OF_MEMORY) {
        ESP_LOGE(TAG, "Input buffer size is less than the image size\n Aborting program");
        abort();
    }

    /* Calculate MD5sum */
    mbedtls_md5_context ctx;
    mbedtls_md5_init(&ctx);
    mbedtls_md5_starts_ret(&ctx);
    mbedtls_md5_update_ret(&ctx, dec.out_buf, dec.out_buf_sz);
    uint8_t *md5_buf = malloc(16 + 1);
    uint8_t *md5_hex = malloc(32 + 1);
    mbedtls_md5_finish_ret(&ctx, md5_buf);
    md5_bytes_to_hex(md5_buf, md5_hex);
    printf("md5sum(hex) is: %s\n", md5_hex);

    /* Compare this with reference MD5sum */

    if (strcmp((char *) md5_hex, "<reference md5_sum here!>")) {
        ESP_LOGE(TAG, "Test FAILED");
    } else {
        ESP_LOGI(TAG, "Test PASSED");
    }

    free(md5_buf);
    free(md5_hex);
    free(dec.out_buf);
    vTaskDelete(NULL);
}

void app_main()
{
    int codec_task_stack_size = 12 * 1024;
    init_smtp_client();
    xTaskCreate(&jpeg_test_task,
                "jpeg_test_task",
                codec_task_stack_size,
                NULL,
                5,
                NULL);
    vTaskDelay(1000);
}