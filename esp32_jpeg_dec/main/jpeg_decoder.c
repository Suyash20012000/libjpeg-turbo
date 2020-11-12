#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_log.h>
#include <esp_err.h>

#include "esp_audio_mem.h"
#include "smtp_client.h"
#include "decoder.h"

static const char *TAG="jpeg_decoding";

extern const uint8_t raw_image_start[] asm("_binary_esp_img_jpeg_start");
extern const uint8_t raw_image_end[]   asm("_binary_esp_img_jpeg_end");
static void jpeg_decoder_task(void *pvParameters)
{
    (void) pvParameters;
    decoder_context dec;
    dec.in_buf_sz= input_buf_size *1024;// 12 kb
    dec.out_buf= malloc(inp_image_height * inp_image_width *12);
    ESP_LOGI(TAG, "Decoding an image");
    decode_jpeg((unsigned char *)raw_image_start , &dec , JCS_GRAYSCALE);
    /* sending an email */
    send_email(dec.out_buf,dec.out_buf_sz);
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