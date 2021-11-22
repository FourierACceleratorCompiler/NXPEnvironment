#include "../LPC55S69_Project.h"

#ifdef PROJ_xbarin02_uFFT

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

int fft_wrapper_accel_internal(_float_complex_ * vector,long int N) {

if ((PRIM_EQUAL(N, 16384)) || ((PRIM_EQUAL(N, 8192)) || ((PRIM_EQUAL(N, 4096)) || ((PRIM_EQUAL(N, 2048)) || ((PRIM_EQUAL(N, 1024)) || ((PRIM_EQUAL(N, 512)) || ((PRIM_EQUAL(N, 256)) || ((PRIM_EQUAL(N, 128)) || (PRIM_EQUAL(N, 64)) || PRIM_EQUAL(N, 32) || PRIM_EQUAL(N, 16))))))))) {
int power_quad_acc_n;;
        power_quad_acc_n = N;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i47 = 0; i47 < power_quad_acc_n; i47++) {
                power_quad_acc_input[i47].im = vector[i47].im;
        };
        for (int i48 = 0; i48 < power_quad_acc_n; i48++) {
                power_quad_acc_input[i48].re = vector[i48].re;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i49 = 0; i49 < power_quad_acc_n; i49++) {
                vector[i49].im = power_quad_acc_output[i49].im;
        };
        for (int i50 = 0; i50 < power_quad_acc_n; i50++) {
                vector[i50].re = power_quad_acc_output[i50].re;
        };
        int returnv;;
        returnv = 0;;

return returnv;;

;

;


} else {

return fft_wrapper(vector, N);;
}
}

int fft_wrapper_accel(_float_complex_ * vector, long int N) {
return (int)fft_wrapper_accel_internal((_float_complex_ *) vector, (long int) N);
}

void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

_float_complex_ *input = xbarin02_uFFT_generate_inputs(n);

clock_t begin = clock();

for (int i = 0; i < TIMES; i ++) {
	int returnv = fft_wrapper_accel(input, n);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
}
free(input);

#endif
