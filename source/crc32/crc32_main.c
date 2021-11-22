#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "LPC55S69_Project.h"
#include <time.h>


#include "fsl_crc.h"
#include "crc32_api.h"

#ifdef CRC
#define LEN 1

uint32_t *generate_data(int len) {
	uint32_t *d = (uint32_t *) malloc(len * sizeof(uint32_t));
	for (int i = 0; i < len; i ++) {
		d[i] = rand();
	}
	return d;
}

int main(void) {

	srand(0);

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
    uint32_t flag = 0xFFFFFFFF;

    printf("Hello World\n");
    uint32_t *testdata = generate_data(LEN);
    clock_t start = clock();
    uint32_t res;
    for (int i = 0; i < TIMES_CRC; i ++) {
    	res = crc32(testdata, LEN);
    }
    clock_t orig_end = clock();
    uint32_t other_res;
    for (int i = 0; i < TIMES_CRC; i ++) {
    	other_res = accel_crc32(0, testdata, LEN);
    }
    clock_t accel_end = clock();
    printf("CRC32 is %x\n", res);
    printf("Accel CRC32 is %x\n", other_res);
    printf("Time diff is %.12f (orig), %.12f (acc)\n", (double) (orig_end - start) / CLOCKS_PER_SEC, (double) (accel_end - orig_end) / CLOCKS_PER_SEC);

    return 0;
	/*for (int i = 0; i < BENCHMARK_TIMES; i ++) {
		for (int i = 0; i < SIZES; i ++) {
			int runsize = TEST_SIZES[i];
			printf("Starting runs for size %d:\n", runsize);
			RUNFUN(runsize);
			printf("Runs finished for size %d\n", runsize);
		}
	}*/

    /*complex_type *test_inputs = generate_test_inputs(NUM);
    complex_type test_outputs[NUM];
    printf("Pointer %p\n", test_inputs);

    for (int i = 0; i < NUM; i ++) {
    	printf("Inputs (%d): \n", i);
    	printf("%.12f, %.12f\n", test_inputs[i].re, test_inputs[i].im);
    }

    fft_api(test_inputs, test_outputs, NUM);

	printf("Outputs:\n");
    for (int i = 0; i < NUM; i ++) {
    	printf("%.12f, %.12f\n", test_outputs[i].re, test_outputs[i].im);
    }*/

    return 0 ;
}

#endif
