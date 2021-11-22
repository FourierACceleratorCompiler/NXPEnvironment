#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_StockhamFFT

#include "../clib/synthesizer.h"
#include <time.h>
#include <stdio.h>
#include "self_contained_code.h"
#include "defines.h"
#include<stdlib.h>
char *output_file; 
char *pre_accel_dump_file; // optional dump file. 

void run_original(int n) {

complex_t *input = cpuimage_StockhamFFT_generate_input(n);

clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	fft(input, n);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: 0\n");
free(input);
}

#endif
