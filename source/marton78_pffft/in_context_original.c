#include "../LPC55S69_Project.h"
#ifdef PROJ_marton78_pffft


#include "../clib/synthesizer.h"
#include <stdio.h>
#include<time.h>
#include "self_contained_code.h"

int run_original(int n) {
float*input = marton78_pffft_generate_inputs(n);
float work[2 * n];
float output[2 * n];

clock_t begin = clock();
struct PFFFT_Setup *setup = pffft_new_setup(n, PFFFT_COMPLEX);
pffft_direction_t direction = PFFFT_FORWARD;
for (int i = 0; i < TIMES; i ++) {
	pffft_transform_ordered(setup, input, output, work, direction);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) 0);
free(input);
}
#endif
