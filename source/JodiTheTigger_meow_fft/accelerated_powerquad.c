/* Orignal skeleton is: 
Pre: SKELETON:

With the array index wrappers adi_acc_output,Annon
And (fromvars) []
Under dimensions [adi_acc_n = data.N]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_n
And (fromvars) [data.N]
Under dimensions []
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_input,re
And (fromvars) [in, r]
Under dimensions [adi_acc_n = data.N]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_input,im
And (fromvars) [in, j]
Under dimensions [adi_acc_n = data.N]
With conversion function IdentityConversion
Post: SKELETON:

With the array index wrappers out,j
And (fromvars) [adi_acc_output, im]
Under dimensions [data.N = adi_acc_n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers out,r
And (fromvars) [adi_acc_output, re]
Under dimensions [data.N = adi_acc_n]
With conversion function IdentityConversion
*/
#include "../LPC55S69_Project.h"

#ifdef PROJ_JodiTheTigger_meow_fft


#include "context_code.h"

#include "defines.h"

#include "../clib/synthesizer.h"
#include<time.h>
#include "../fft_api.h"
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

clock_t AcceleratorStart;
long AcceleratorTotalNanos = 0;
void StartAcceleratorTimer() {
	AcceleratorStart = clock();
}

void StopAcceleratorTimer() {
	AcceleratorTotalNanos +=
		(clock()) - AcceleratorStart;
}

void meow_fft_accel_internal(Meow_FFT_Workset * data,Meow_FFT_Complex * in,Meow_FFT_Complex * out) {                                  int power_quad_acc_n;;
        power_quad_acc_n = data->N;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;                                                complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;                                                 for (int i17 = 0; i17 < power_quad_acc_n; i17++) {
                power_quad_acc_input[i17].im = in[i17].j;
        };
        for (int i18 = 0; i18 < power_quad_acc_n; i18++) {
                power_quad_acc_input[i18].re = in[i18].r;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i19 = 0; i19 < power_quad_acc_n; i19++) {
                out[i19].j = power_quad_acc_output[i19].im;
        };
        for (int i20 = 0; i20 < power_quad_acc_n; i20++) {
                out[i20].r = power_quad_acc_output[i20].re;
        };
                                                                                                                                      ;
;


}

void meow_fft_accel(Meow_FFT_Workset * data, Meow_FFT_Complex * in, Meow_FFT_Complex * out) {
meow_fft_accel_internal((Meow_FFT_Workset *) data, (Meow_FFT_Complex *) in, (Meow_FFT_Complex *) out);
}
void run_accelerator(int n) {
	AcceleratorTotalNanos = 0;
Meow_FFT_Complex *in = JodiTheTigger_meow_fft_generate_inputs(n);
size_t workset_bytes = meow_fft_generate_workset(n, NULL);
Meow_FFT_Workset* data =
	(Meow_FFT_Workset *) malloc(workset_bytes);
meow_fft_generate_workset(n, data);
Meow_FFT_Complex out[data->N];
clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	meow_fft_accel(data, in, out);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
free(in);
free(data);
}

#endif
