#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "driver/gpio.h"

#include "dht.h"

#define SENSOR_PIN GPIO_NUM_4

void app_main(void)
{

    while (1)
    {
    	int16_t humidity = 0, temperature = 0;
		ESP_ERROR_CHECK(dht_read_data(DHT_TYPE_AM2301, SENSOR_PIN, &humidity, &temperature));
		printf("Temperature: %d\n", temperature);
		printf("Humidity:    %d\n", humidity);
    	sleep(1);
    }
}
