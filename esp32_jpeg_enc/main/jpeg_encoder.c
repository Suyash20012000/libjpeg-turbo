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

extern uint8_t raw_image_start[] asm("_binary_raw_img_start");
extern uint8_t raw_image_end[]   asm("_binary_raw_img_end");

#define IMAGE_HEIGHT 94
#define IMAGE_WIDTH 94
#define QUALITY 500
static void jpeg_encoder_task(void *pvParameters)
{
    (void) pvParameters;

    int ret;
    ESP_LOGI(TAG, "Encoding an image");
    encoder_context enc;
    enc.image_height = IMAGE_HEIGHT;
    enc.image_width = IMAGE_WIDTH;
    enc.out_buf_sz = IMAGE_WIDTH * IMAGE_HEIGHT * 4;
    enc.in_col_components = 3;
    enc.in_col_space = JCS_RGB;
    enc.out_buf_mem_alloc = IMAGE_HEIGHT * IMAGE_WIDTH * 4;
    enc.output_buffer = malloc(enc.out_buf_mem_alloc);
    enc.inp_buf = raw_image_start;
    enc.quality = QUALITY;

    ret = encode_image(&enc);
    if (ret == ERR_INVALID_ARGS) {
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
    send_email(enc.output_buffer, enc.out_buf_sz);
    free(enc.output_buffer);
    vTaskDelete(NULL);
}

void app_main()
{
    int codec_task_stack_size = 12 * 1024;
    init_smtp_client();

    xTaskCreate(&jpeg_encoder_task,
                "jpeg_enc_task",
                codec_task_stack_size,
                NULL,
                5,
                NULL);

    vTaskDelay(1000);
}
