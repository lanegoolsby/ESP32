#include "freertos/FreeRTOS.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

#include "tsl2561/tsl2561.c"

//static const char *TAG = "example";

esp_err_t event_handler(void *ctx, system_event_t *event) {
	return ESP_OK;
}

void app_main(void) {
	init_2561();
	while (1) {
		read_current_lux( );
		vTaskDelay(2000 / portTICK_PERIOD_MS);
	}
}

