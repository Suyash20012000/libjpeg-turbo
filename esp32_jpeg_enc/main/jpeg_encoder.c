/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include <esp_log.h>
#include <esp_err.h>

#include "esp_audio_mem.h"
#include "smtp_client.h"
#include "encoder.h"

static const char *TAG = "jpeg_enc";

extern const uint8_t raw_image_start[] asm("_binary_raw_image_start");
extern const uint8_t raw_image_end[]   asm("_binary_raw_image_end");

/* Introduced by ESP. Encode raw mono-chrome image */

unsigned long out_buf_sz = img_wdth * img_ht * 4;

static void jpeg_encoder_task(void *pvParameters)
{
    (void) pvParameters;
    encoder_context mgr;
    mgr.image_height = img_ht;
    mgr.image_width = img_wdth;
    mgr.out_buf_sz = mgr.image_height * mgr.image_width;
    mgr.output_buffer = malloc(img_ht * img_wdth * 4);
    ESP_LOGI(TAG, "Encoding an image");
    encode_greyscale((unsigned char *) raw_image_start, mgr , &out_buf_sz);

    ESP_LOGI(TAG, "Encoded an image. out_size = %lu", mgr.out_buf_sz);

    /* sending an email */
    send_email(mgr.output_buffer, out_buf_sz);
    free(mgr.output_buffer);
    vTaskDelete(NULL);
}

void app_main()
{
    int codec_task_stack_size = 24 * 1024;
    xTaskCreate(&jpeg_encoder_task,
                "jpeg_enc_task",
                codec_task_stack_size,
                NULL,
                5,
                NULL);

    vTaskDelay(1000);
}
