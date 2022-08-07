#include <dht.h>
#include <esp_err.h>
#include <esp_wifi.h>
#include <esp_wifi_types.h>
#include <hal/gpio_types.h>
#include <nvs.h>
#include <nvs_flash.h>
#include <stdio.h>
#include <sys/_stdint.h>
#include <sys/unistd.h>
#include <wifi.h>

#define SENSOR_PIN GPIO_NUM_4

void app_main(void)
{

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    // initialize wifi
    wifi_init_sta();

    while (1)
    {
    	int16_t humidity = 0, temperature = 0;
		ESP_ERROR_CHECK(dht_read_data(DHT_TYPE_AM2301, SENSOR_PIN, &
				humidity, &temperature));
		printf("Temperature: %d\n", temperature);
		printf("Humidity:    %d\n", humidity);

		wifi_ap_record_t ap;
		esp_wifi_sta_get_ap_info(&ap);
		printf("RSSI: %d\n", ap.rssi);

		sleep(1);
    }
}
