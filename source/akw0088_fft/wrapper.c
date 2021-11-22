#include "../LPC55S69_Project.h"
#ifdef PROJ_akw0088_fft

#include "../clib/synthesizer.h"
#include <time.h>
#include <stdio.h>
#include "self_contained_code.h"
#include "../LPC55S69_Project.h"
#include "defines.h"
#include<stdlib.h>
char *output_file; 
char *pre_accel_dump_file; // optional dump file. 

void run_original(int n) {

	j_complex_t *input = akw0088_fft_generate_input(n);
	j_complex_t w[n];
	init_w(n, w); // would be dead-code eliminated

	clock_t begin = clock();
	for (int i = 0; i < TIMES; i ++) {
		fft_c(n, input, w);
	}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: 0\n");
free(input);
}

#endif
