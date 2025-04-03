
#include "MLX90614.h"
#include <stdio.h>
#include "driver/i2c.h"
#include "esp_log.h"

static const char *TAG = "I2C_MLX90614";

esp_err_t i2c_master_init(void) {
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ,
    };
    i2c_param_config(I2C_MASTER_NUM, &conf);
    return i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}



esp_err_t mlx90614_read(uint8_t reg, uint16_t *data) {
    uint8_t buf[3];
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (MLX90614_I2CDEFAULTADDR << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, reg, true);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (MLX90614_I2CDEFAULTADDR << 1) | I2C_MASTER_READ, true);
    i2c_master_read(cmd, buf, 3, I2C_MASTER_LAST_NACK);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_MASTER_NUM, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);

    if (ret == ESP_OK) {
        *data = (uint16_t)(buf[0] | (buf[1] << 8));
    }
    return ret;
}


// void db_start_control_module() {
//     ESP_ERROR_CHECK(i2c_master_init());
//     xTaskCreate(&_timer, "MLX90614", 40960, NULL, 5, NULL);
// }