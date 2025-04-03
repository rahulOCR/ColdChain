#ifndef MLX90614_MLX90614_H
#define MLX90614_DRIVER_H
#include "defines.h"
#include "esp_log.h"
#include <esp_err.h>

esp_err_t i2c_master_init(void);
esp_err_t mlx90614_read(uint8_t reg, uint16_t *data);

#endif