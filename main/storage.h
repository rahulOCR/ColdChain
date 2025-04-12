#ifndef STORAGE_H
#define STORAGE_H
void save_temperature_to_nvs(float temperature);
float load_temperature_from_nvs();
#endif