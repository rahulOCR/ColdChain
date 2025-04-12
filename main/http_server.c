#include "http_server.h"
#include "storage.h"

static const char *TAG = "TEMP_SERVER";
#define MIN(a,b) ((a) < (b) ? (a) : (b))

static const char *html_form = "<!DOCTYPE html><html><head><title>Adjust Box Temperature</title></head><body>\
<h2>Set Temperature</h2>\
<form action=\"/set\" method=\"post\">\
  Temperature: <input type=\"text\" name=\"temp\" value=\"%.2f\">\
  <input type=\"submit\" value=\"Set\">\
</form>\
<p>Current Set Temperature: %.2f °C</p>\
</body></html>";

static float set_temperature = 25.0f; // default
esp_err_t root_get_handler(httpd_req_t *req) {
    char resp[512];
    snprintf(resp, sizeof(resp), html_form, set_temperature, set_temperature);
    httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN);
    return ESP_OK;
}

float get_temperature() {
    return set_temperature;
}

esp_err_t set_temp_post_handler(httpd_req_t *req) {
    char buf[100];
    int ret = httpd_req_recv(req, buf, MIN(req->content_len, sizeof(buf)-1));
    if (ret <= 0) {
        return ESP_FAIL;
    }
    buf[ret] = '\0';

    // Expecting data like "temp=28.5"
    char *temp_str = strchr(buf, '=');
    if (temp_str) {
        set_temperature = atof(temp_str + 1);
        ESP_LOGI(TAG, "New temperature set: %.2f", set_temperature);
        save_temperature_to_nvs(set_temperature);
    }

    httpd_resp_set_status(req, "303 See Other");
    httpd_resp_set_hdr(req, "Location", "/");
    httpd_resp_send(req, NULL, 0);
    return ESP_OK;
}

httpd_handle_t start_webserver(void) {
    set_temperature = load_temperature_from_nvs();
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;

    if (httpd_start(&server, &config) == ESP_OK) {
        httpd_uri_t root = {
            .uri       = "/",
            .method    = HTTP_GET,
            .handler   = root_get_handler
        };
        httpd_register_uri_handler(server, &root);

        httpd_uri_t set_temp = {
            .uri       = "/set",
            .method    = HTTP_POST,
            .handler   = set_temp_post_handler
        };
        httpd_register_uri_handler(server, &set_temp);
    }
    return server;
}

void wifi_init_softap() {
    esp_netif_create_default_wifi_ap();
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    wifi_config_t ap_config = {
        .ap = {
            .ssid = "ColdChain",
            .ssid_len = 0,
            .channel = 1,
            .password = "12345678@",
            .max_connection = 2,
            .authmode = WIFI_AUTH_WPA_WPA2_PSK
        },
    };
    if (strlen((char *)ap_config.ap.password) == 0) {
        ap_config.ap.authmode = WIFI_AUTH_OPEN;
    }

    esp_wifi_set_mode(WIFI_MODE_AP);
    esp_wifi_set_config(WIFI_IF_AP, &ap_config);
    esp_wifi_start();
}
