#include "../LPC55S69_Project.h"

#ifdef PROJ_mozanunal_SimpleDSP

/* Orignal skeleton is: 
Pre: SKELETON:

With the array index wrappers adi_acc_output,Annon
And (fromvars) []
Under dimensions [adi_acc_n = N]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_n
And (fromvars) [N]
Under dimensions []
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_input,re
And (fromvars) [x, re]
Under dimensions [adi_acc_n = N]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_input,im
And (fromvars) [x, im]
Under dimensions [adi_acc_n = N]
With conversion function IdentityConversion
Post: SKELETON:

With the array index wrappers returnv,Annon
And (fromvars) []
Under dimensions [N = adi_acc_n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers returnv,im
And (fromvars) [adi_acc_output, im]
Under dimensions [N = adi_acc_n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers returnv,re
And (fromvars) [adi_acc_output, re]
Under dimensions [N = adi_acc_n]
With conversion function IdentityConversion
*/


#include "self_contained_code.h"
#include"../clib/synthesizer.h"
#include "../clib/fft_synth/lib.h"
#include "defines.h"
#include<time.h>
#include<stdio.h>
#include "../fft_api.h"
#include <complex.h>



clock_t AcceleratorStart;
long AcceleratorTotalNanos = 0;
void StartAcceleratorTimer() {
	AcceleratorStart = clock();
}

void StopAcceleratorTimer() {
	AcceleratorTotalNanos +=
		(clock()) - AcceleratorStart;
}

void FFT_accel_internal(COMPLEX * Y,int N) {

if (PRIM_EQUAL(N, 64)) {
int power_quad_acc_n;;
        power_quad_acc_n = N;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i12 = 0; i12 < power_quad_acc_n; i12++) {
                power_quad_acc_input[i12].im = Y[i12].imag;
        };
        for (int i13 = 0; i13 < power_quad_acc_n; i13++) {
                power_quad_acc_input[i13].re = Y[i13].real;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i14 = 0; i14 < power_quad_acc_n; i14++) {
                Y[i14].real = power_quad_acc_output[i14].re;
        };
        for (int i15 = 0; i15 < power_quad_acc_n; i15++) {
                Y[i15].imag = power_quad_acc_output[i15].im;
        };

;

;


} else {
FFT(Y, N);
}
}
void FFT_accel(COMPLEX * Y, int N) {
FFT_accel_internal((COMPLEX *) Y, (int) N);
}

void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

COMPLEX *input = mozanunal_SimpleDSP_generate_inputs(n);

clock_t begin = clock();

for (int i = 0; i < TIMES; i ++) {
	FFT_accel(input, n);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
}
free(input);

#endif
