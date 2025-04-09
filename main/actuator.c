#include "driver/gpio.h"
#include "esp_log.h"
#include <esp_err.h>
#include "actuator.h"

static const char *ACT_TAG = "ACTUATOR";

void actuator_init() {
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << FAN_GPIO) | (1ULL << PELTIER_GPIO),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = 0,
        .pull_down_en = 0,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);
}

void fan_on() {
    gpio_set_level(FAN_GPIO, 0);
}

void fan_off() {
    gpio_set_level(FAN_GPIO, 1);
}

void peltier_on() {
    gpio_set_level(PELTIER_GPIO, 0);
}

void peltier_off() {
    gpio_set_level(PELTIER_GPIO, 1);
}

void control_actuator(float temperature, float set_point)
{
    if(temperature > set_point + 3.0f)
    {
        ESP_LOGI(ACT_TAG, "actuators are on");
        peltier_on();
        fan_on();   
    }

    else if (temperature < set_point - 3.0f)
    {
        ESP_LOGI(ACT_TAG, "actuators are off");
        peltier_off();
        fan_off();
    }
}