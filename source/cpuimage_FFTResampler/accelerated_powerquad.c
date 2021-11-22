/* Orignal skeleton is: 
Pre: SKELETON:

With the array index wrappers adi_acc_output,Annon
And (fromvars) []
Under dimensions [adi_acc_n = n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_n
And (fromvars) [n]
Under dimensions []
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_input,re
And (fromvars) [input, real]
Under dimensions [adi_acc_n = n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_input,im
And (fromvars) [input, imag]
Under dimensions [adi_acc_n = n]
With conversion function IdentityConversion
Post: SKELETON:

With the array index wrappers output,imag
And (fromvars) [adi_acc_output, im]
Under dimensions [n = adi_acc_n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers output,real
And (fromvars) [adi_acc_output, re]
Under dimensions [n = adi_acc_n]
With conversion function IdentityConversion
*/

#include "../LPC55S69_Project.h"
#ifdef PROJ_cpuimage_FFTResampler

#include "self_contained_code.h"
#include "defines.h"

#include "../clib/synthesizer.h"
#include<time.h>
#include "../fft_api.h"
#include <stdio.h>
#include <stdlib.h>


clock_t AcceleratorStart;
clock_t AcceleratorTotalNanos = 0;
void StartAcceleratorTimer() {
	AcceleratorStart = clock();
}

void StopAcceleratorTimer() {
	AcceleratorTotalNanos +=
		(clock()) - AcceleratorStart;
}


void STB_FFT_accel_internal(cmplx * input,cmplx * output,int n) {

if ((PRIM_EQUAL(n, 16384)) || ((PRIM_EQUAL(n, 8192)) || ((PRIM_EQUAL(n, 4096)) || ((PRIM_EQUAL(n, 2048)) || ((PRIM_EQUAL(n, 1024)) || ((PRIM_EQUAL(n, 512)) || ((PRIM_EQUAL(n, 256)) || ((PRIM_EQUAL(n, 128)) || (PRIM_EQUAL(n, 64)) || PRIM_EQUAL(n, 32) || PRIM_EQUAL(n, 16))))))))) {
int power_quad_acc_n;;
        power_quad_acc_n = n;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i17 = 0; i17 < power_quad_acc_n; i17++) {
                power_quad_acc_input[i17].im = input[i17].imag;
        };
        for (int i18 = 0; i18 < power_quad_acc_n; i18++) {
                power_quad_acc_input[i18].re = input[i18].real;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i19 = 0; i19 < power_quad_acc_n; i19++) {
                output[i19].imag = power_quad_acc_output[i19].im;
        };
        for (int i20 = 0; i20 < power_quad_acc_n; i20++) {
                output[i20].real = power_quad_acc_output[i20].re;
        };

;

;


} else {
STB_FFT(input, output, n);
}
}
void STB_FFT_accel(cmplx * input, cmplx * output, int n) {
STB_FFT_accel_internal((cmplx *) input, (cmplx *) output, (int) n);
}
void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

cmplx *input = cpuimage_FFTResampler_generate_input(n);
cmplx output[n];
clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	STB_FFT_accel(input, output, n);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
free(input);
}

#endif
