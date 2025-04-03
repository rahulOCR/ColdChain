#include <stdio.h>
#include "MLX90614.h"
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <esp_err.h>

static const char *TAG = "MLX90614";

void app_main(void)
{
    ESP_ERROR_CHECK(i2c_master_init());
    uint16_t ambient_temp, object_temp;


    while (1) 
    {
        if (mlx90614_read(MLX90614_AMBIENT_TEMP, &ambient_temp) == ESP_OK) {
            float temp = ambient_temp * 0.02 - 273.15;
            ESP_LOGI(TAG, "Ambient Temperature: %.2f°C", temp);
        } else {
            ESP_LOGE(TAG, "Failed to read ambient temperature");
        }
    
        if (mlx90614_read(MLX90614_OBJECT_TEMP, &object_temp) == ESP_OK) {
            float temp = object_temp * 0.02 - 273.15;
            ESP_LOGI(TAG, "Object Temperature: %.2f°C", temp);
        } else {
            ESP_LOGE(TAG, "Failed to read object temperature");
        }

        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }

    

}
