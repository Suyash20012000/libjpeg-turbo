#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>
#include <esp_err.h>
#include "esp_audio_mem.h"
#include "jpeg_kernels.h"


static const char *TAG = "jpeg_example-testing";

static void jpeg_test_task(void *pvParameters)
{
    (void) pvParameters;

    buf_ptr1 out_buf;
    short test_arr[64];
    int i;
    for(i=0;i<64;i++)
    {
        test_arr[i]=i; // array to perform idct on 
    }
    out_buf = malloc(128);
    jsimd_idct_test(test_arr,out_buf);

    vTaskDelete(NULL);
}

void app_main()
{
    int codec_task_stack_size = 12 * 1024;
    xTaskCreate(&jpeg_test_task,
                "jpeg_test_task",
                codec_task_stack_size,
                NULL,
                5,
                NULL);
    vTaskDelay(1000);
}
