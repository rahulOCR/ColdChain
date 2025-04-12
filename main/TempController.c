#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <esp_err.h>
 #include <stdbool.h>

#include "MLX90614.h"
#include "actuator.h"
#include "LCD.h"
#include "http_server.h"

static const char *TAG = "MAIN";

void app_main(void)
{
    nvs_flash_init();
    esp_netif_init();
    esp_event_loop_create_default();

    wifi_init_softap();
    start_webserver();


    if ( DefaultBusInit( ) == true ) {
        printf( "Display init successfully...\n" );
    }

    actuator_init();
    ESP_ERROR_CHECK(i2c_master_init());
    uint16_t ambient_temp, object_temp;
    float amb_temp;
    float ob_temp;
    float set_temp = 30.0f;
    char display_data1[24];
    char display_data2[24];
    char display_data3[24];

    while (1) 
    {

        if (mlx90614_read(MLX90614_AMBIENT_TEMP, &ambient_temp) == ESP_OK) {
            amb_temp = ambient_temp * 0.02 - 273.15;
            ESP_LOGI(TAG, "Ambient Temperature: %.2f°C", amb_temp);
            
        } else {
            amb_temp = 0.0f;
            ESP_LOGE(TAG, "Failed to read ambient temperature");
        }
    
        if (mlx90614_read(MLX90614_OBJECT_TEMP, &object_temp) == ESP_OK) {
            ob_temp = object_temp * 0.02 - 273.15;
            ESP_LOGI(TAG, "Object Temperature: %.2f°C", ob_temp);
        
        } else {
            ob_temp = 0.0f;
            ESP_LOGE(TAG, "Failed to read object temperature");
        }

        set_temp = get_temperature();

        snprintf(display_data1, sizeof(display_data1), "AmbientTemp: %.2f °C", amb_temp);

        snprintf(display_data2, sizeof(display_data2), "Object Temp: %.2f °C", ob_temp);
        
        snprintf(display_data3, sizeof(display_data3), "Set Temp: %.2f °C", set_temp);

        screen_print(display_data1, display_data2, display_data3);

        control_actuator(ob_temp, set_temp);


        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }

    

}
