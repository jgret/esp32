#include <driver/dac_common.h>
#include <hal/dac_types.h>
#include <stdio.h>
#include <sys/_stdint.h>
#include <sys/unistd.h>

void app_main(void)
{

	dac_output_enable(DAC_CHANNEL_1);

	printf("Hello from app_main!\n");
	uint8_t dacval = 0;

    while (1) {
        dac_output_voltage(DAC_CHANNEL_1, dacval);
    	dacval++;
    	usleep(1);
    }

}
