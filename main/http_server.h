#pragma once
#include <string.h>
#include "esp_log.h"
#include "esp_http_server.h"
#include "nvs_flash.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"
#ifndef HTTP_SERVER_H

void wifi_init_softap();
httpd_handle_t start_webserver();
float get_temperature();
#define HTTP_SERVER_H
#endif