#include "../LPC55S69_Project.h"

#ifdef PROJ_liscio_fft

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

_complex_double_ * FFT_wrapper_accel_internal(_complex_double_ * x,int N) {

if ((PRIM_EQUAL(N, 2048)) || ((PRIM_EQUAL(N, 1024)) || ((PRIM_EQUAL(N, 512)) || ((PRIM_EQUAL(N, 256)) || ((PRIM_EQUAL(N, 128)) || (PRIM_EQUAL(N, 64)) || PRIM_EQUAL(N, 32) || PRIM_EQUAL(N, 16)))))) {
int power_quad_acc_n;;
        power_quad_acc_n = N;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i2 = 0; i2 < power_quad_acc_n; i2++) {
                power_quad_acc_input[i2].im = x[i2].re;
        };
        for (int i3 = 0; i3 < power_quad_acc_n; i3++) {
                power_quad_acc_input[i3].re = x[i3].im;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        _complex_double_* returnvar = (_complex_double_*) facc_malloc (0, sizeof(_complex_double_)*N);;
        for (int i4 = 0; i4 < power_quad_acc_n; i4++) {
                returnvar[i4].im = power_quad_acc_output[i4].re;
        };
        for (int i5 = 0; i5 < power_quad_acc_n; i5++) {
                returnvar[i5].re = power_quad_acc_output[i5].im;
        };

return returnvar;;

;

;


} else {

return FFT_wrapper(x, N);;
}
}

	_complex_double_ * FFT_wrapper_accel(_complex_double_ * x, int N) {
return (_complex_double_ *)FFT_wrapper_accel_internal((_complex_double_ *) x, (int) N);
}
void run_accelerator(int n) {
AcceleratorTotalNanos = 0;
complex *x = liscio_fft_generate_inputs(n);
int N = n;
clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	complex * returnv = FFT_wrapper_accel(x, N);
	facc_free(returnv);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
}

#endif
