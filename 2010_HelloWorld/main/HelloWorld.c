
/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_log.h"
#include "nvs_flash.h"

static const char *TAG = "example";

/* Can run 'make menuconfig' to set message and loop duration,
   or you can edit the following line and set them here.
*/
#define HELLO_MESSAGE CONFIG_HELLO_MESSAGE
#define LOOP_DURATION CONFIG_LOOP_DURATION

void main_task(void *pvParameter)
{
    while(1) {
        printf( "%s\n", HELLO_MESSAGE );

        vTaskDelay(LOOP_DURATION / portTICK_RATE_MS);
        ESP_LOGI(TAG, "Loop start again!");    }
}

void app_main()
{
    nvs_flash_init();
    system_init();

    xTaskCreate(&main_task, "main_task", 2048, NULL, 5, NULL);
}
