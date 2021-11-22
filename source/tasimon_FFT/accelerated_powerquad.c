#include "../LPC55S69_Project.h"

#ifdef PROJ_tasimon_FFT

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

void fft64_accel_internal(facc_2xf32_t * Z) {
int power_quad_acc_n;;
        power_quad_acc_n = 64;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i2 = 0; i2 < 64; i2++) {
                power_quad_acc_input[i2].im = Z[i2].f32_1;
        };
        for (int i3 = 0; i3 < 64; i3++) {
                power_quad_acc_input[i3].re = Z[i3].f32_2;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i4 = 0; i4 < 64; i4++) {
                Z[i4].f32_2 = power_quad_acc_output[i4].re;
        };
        for (int i5 = 0; i5 < 64; i5++) {
                Z[i5].f32_1 = power_quad_acc_output[i5].im;
        };

;

;


}

void fft64_accel(float * Z) {
fft64_accel_internal((facc_2xf32_t *) Z);
}

void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

float *input = tasimon_FFT_generate_inputs(n);

clock_t begin = clock();

for (int i = 0; i < TIMES; i ++) {
	fft64_accel(input);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
}
free(input);

#endif
