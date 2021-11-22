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
#ifdef PROJ_cpuimage_StockhamFFT

#include "self_contained_code.h"
#include "defines.h"

#include "../clib/synthesizer.h"
#include "../clib/fft_synth/lib.h"
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


void fft_accel_internal(complex_t * x,int n) {

if ((PRIM_EQUAL(n, 16384)) || ((PRIM_EQUAL(n, 8192)) || ((PRIM_EQUAL(n, 4096)) || ((PRIM_EQUAL(n, 2048)) || ((PRIM_EQUAL(n, 1024)) || ((PRIM_EQUAL(n, 512)) || ((PRIM_EQUAL(n, 256)) || ((PRIM_EQUAL(n, 128)) || (PRIM_EQUAL(n, 64)) || PRIM_EQUAL(n, 32) || PRIM_EQUAL(n, 16))))))))) {
int power_quad_acc_n;;
        power_quad_acc_n = n;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i12 = 0; i12 < power_quad_acc_n; i12++) {
                power_quad_acc_input[i12].im = x[i12].imag;
        };
        for (int i13 = 0; i13 < power_quad_acc_n; i13++) {
                power_quad_acc_input[i13].re = x[i13].real;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i14 = 0; i14 < power_quad_acc_n; i14++) {
                x[i14].real = power_quad_acc_output[i14].re;
        };
        for (int i15 = 0; i15 < power_quad_acc_n; i15++) {
                x[i15].imag = power_quad_acc_output[i15].im;
        };

;

;

;

if (GREATER_THAN(n, -1)) {
ARRAY_NORM(x, real, n);;
        ARRAY_NORM(x, imag, n);
} else {
;
}
} else {
fft(x, n);
}
}

void fft_accel(complex_t * x, int n) {
fft_accel_internal((complex_t *) x, (int) n);
}

void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

complex_t *input = cpuimage_StockhamFFT_generate_input(n);

clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	fft_accel(input, n);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
free(input);
}

#endif
