#include "../LPC55S69_Project.h"
#ifdef PROJ_MiBench_MiBench

#include "../clib/synthesizer.h"
#include <time.h>
#include <stdio.h>
#include "self_contained_code.h"
#include "defines.h"
#include<stdlib.h>
char *output_file; 
char *pre_accel_dump_file; // optional dump file. 

void run_original(int n) {

	float *realin = MiBench_MiBench_generate_input(n);
	float *imagin = MiBench_MiBench_generate_input(n);
	float realout[n];
	float imagout[n];

	clock_t begin = clock();
	for (int i = 0; i < TIMES; i ++) {
		fft_float(n, 0, realin, imagin, realout, imagout);
	}
	clock_t end = clock();
	printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
	printf("AccTime: %.12f\n", (double) 0 / CLOCKS_PER_SEC);
	free(realin);
	free(imagin);
}

#endif
