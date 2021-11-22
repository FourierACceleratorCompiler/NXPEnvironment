#include "../LPC55S69_Project.h"
#ifdef PROJ_mborgerding_kissfft


#include "../clib/synthesizer.h"
#include <stdio.h>
#include<time.h>
#include "self_contained_code.h"

int run_original(int n) {
	kiss_fft_cpx *input = mborgerding_kissfft_generate_inputs(n);
	kiss_fft_cpx  out[n];

	clock_t begin = clock();

	for (int i = 0; i < TIMES; i ++) {
		kfc_fft(n, input, out);
	}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) 0);
}
free(input);
#endif
