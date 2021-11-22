#include "../LPC55S69_Project.h"
#ifdef PROJ_JodiTheTigger_meow_fft

#include "../clib/synthesizer.h"
#include<time.h>
#include "context_code.h"
#include <stdio.h>
#include "defines.h"


void run_original(int n) {
// This is the original, but in the bencharmking context.  Mostly,
// we're using the pre-defined functions to generate the inputs,
// rather than using a handwritten input-generator to pick valid ones.
Meow_FFT_Complex *in = JodiTheTigger_meow_fft_generate_inputs(n);
clock_t begin = clock();
size_t workset_bytes = meow_fft_generate_workset(n, NULL);
Meow_FFT_Workset* data =
	(Meow_FFT_Workset *) malloc(workset_bytes);
meow_fft_generate_workset(n, data);
Meow_FFT_Complex out[data->N];

for (int i = 0; i < TIMES; i ++) {
	meow_fft(data, in, out);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) 0 / CLOCKS_PER_SEC);
// avoid leaks with repeats.
free(in);
free(data);
}

#endif
