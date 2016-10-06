
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

void main_task(void *pvParameter)
{
    printf("\n");

    const char* version = system_get_sdk_version();
    printf("SDK Version: %s\n", version);

    uint32_t heap = system_get_free_heap_size();
    printf("Heap size: %i\n", (int)heap);

    /*
    uint8_t mac[6];
    system_efuse_read_mac(mac);

    printf("MAC address: %02x:%02x:%02x:%02x:%02x:%02x\n",
        (int)mac[0], (int)mac[1], (int)mac[2], (int)mac[3], (int)mac[4], (int)mac[5]);
	*/
    while(1) {
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
    //vTaskDelete(NULL);
}

void app_main()
{
    nvs_flash_init();
    system_init();

    xTaskCreate(&main_task, "main_task", 512, NULL, 5, NULL);
}
