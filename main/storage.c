#include "nvs_flash.h"
#include "nvs.h"
#include "storage.h"
#include "esp_log.h"

static const char *TAG = "STORAGE";

void save_temperature_to_nvs(float temperature) {
    nvs_handle_t nvs_handle;
    esp_err_t err = nvs_open("storage", NVS_READWRITE, &nvs_handle);
    if (err == ESP_OK) {
        err = nvs_set_blob(nvs_handle, "set_temp", &temperature, sizeof(temperature));
        if (err == ESP_OK) {
            nvs_commit(nvs_handle);
            ESP_LOGI(TAG, "Temperature %.2f saved to NVS", temperature);
        } else {
            ESP_LOGE(TAG, "Failed to save temperature to NVS");
        }
        nvs_close(nvs_handle);
    } else {
        ESP_LOGE(TAG, "Error opening NVS handle");
    }
}


float load_temperature_from_nvs() {
    nvs_handle_t nvs_handle;
    float temp = 25.0;  // Default value
    esp_err_t err = nvs_open("storage", NVS_READONLY, &nvs_handle);
    if (err == ESP_OK) {
        size_t required_size = sizeof(temp);
        err = nvs_get_blob(nvs_handle, "set_temp", &temp, &required_size);
        if (err == ESP_OK) {
            ESP_LOGI(TAG, "Loaded temperature from NVS: %.2f", temp);
        } else {
            ESP_LOGW(TAG, "No saved temperature in NVS, using default");
        }
        nvs_close(nvs_handle);
    } else {
        ESP_LOGE(TAG, "Error opening NVS to read");
    }
    return temp;
}
