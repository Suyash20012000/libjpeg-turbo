#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_log.h>
#include <esp_err.h>

#include "esp_audio_mem.h"
#include "smtp_client.h"
#include "decoder.h"
#define INPUT_BUF_SIZE 20 //kb
#define INP_IMG_WIDTH 94
#define INP_IMG_HEIGHT 94

static const char *TAG = "jpeg_decoding";

extern uint8_t raw_image_start[] asm("_binary_esp_img_col_jpeg_start");
extern uint8_t raw_image_end[]   asm("_binary_esp_img_col_jpeg_end");

static void jpeg_decoder_task(void *pvParameters)
{
    int ret;
    (void) pvParameters;
    decoder_context dec;
    dec.in_buf_sz = INPUT_BUF_SIZE * 1024;
    dec.out_buf_mem_alloc = INP_IMG_WIDTH * INP_IMG_HEIGHT * 12;
    dec.out_buf = malloc(dec.out_buf_mem_alloc);
    dec.out_color_space = JCS_GRAYSCALE;
    dec.in_buf_start = raw_image_start;
    dec.in_buf_end = raw_image_end;
    ESP_LOGI(TAG, "Decoding an image");
    ret = decode_jpeg(&dec);
    if (ret == ERR_INVALID_ARG) {
        ESP_LOGE(TAG, "Invalid Arguments Passed\tAborting program");
        abort();
    }
    if (ret == SUCCESS) {
        ESP_LOGI(TAG, "Success");
    }
    if (ret == OUT_OF_MEMORY) {
        ESP_LOGE(TAG, "Out of memory\tAborting program");
        abort();
    }
    /* sending an email */
    send_email(dec.out_buf, dec.out_buf_sz);
    free(dec.out_buf);
    vTaskDelete(NULL);
}

void app_main()
{
    int codec_task_stack_size = 12 * 1024;
    init_smtp_client();

    xTaskCreate(&jpeg_decoder_task,
                "jpeg_dec_task",
                codec_task_stack_size,
                NULL,
                5,
                NULL);

    vTaskDelay(1000);
}
