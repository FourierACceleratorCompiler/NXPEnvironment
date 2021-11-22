#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_cpuFFT

#include "../clib/synthesizer.h"
#include <time.h>
#include <stdio.h>
#include "self_contained_code.h"

#include "../LPC55S69_Project.h"
#include "defines.h"
#include<stdlib.h>

void run_original(int n) {

cmplx *input = cpuimage_cpuFFT_generate_input(n);
cmplx output[n];

clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	FFT(input, output, n);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: 0\n");
free(input);
}

#endif
