idf_component_register(SRCS TempController.c MLX90614.c actuator.c LCD.c storage.c http_server.c
                    INCLUDE_DIRS ".")

# idf_component_register(SRCS test.c
#                     INCLUDE_DIRS ".")

set(EXTRA_COMPONENT_DIRS components/esp-idf-ssd1306)