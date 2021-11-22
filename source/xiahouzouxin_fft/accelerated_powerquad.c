#include "../LPC55S69_Project.h"

#ifdef PROJ_xiahouzouxin_fft

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

void fft_accel_internal(COMPLEX * x,int N) {

if ((PRIM_EQUAL(N, 2048)) || (PRIM_EQUAL(N, 1024)) || (PRIM_EQUAL(N, 512)) || ((PRIM_EQUAL(N, 256)) || ((PRIM_EQUAL(N, 128)) || (PRIM_EQUAL(N, 64)) || PRIM_EQUAL(N, 32) || PRIM_EQUAL(N, 16)))) {
int power_quad_acc_n;;
        power_quad_acc_n = N;;
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


} else {
fft(x, N);
}
}

void fft_accel(COMPLEX * x, int N) {
fft_accel_internal((COMPLEX *) x, (int) N);
}
void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

COMPLEX *input = xiahouzouxin_fft_generate_inputs(n);

clock_t begin = clock(); // Measure after setup because a good codegen would do DCE on all of that.

for (int i = 0; i < TIMES; i ++) {
	fft_accel(input, n);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
}
free(input);

#endif
