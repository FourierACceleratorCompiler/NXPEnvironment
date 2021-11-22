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
#ifdef PROJ_akw0088_fft

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


void fft_c_accel_internal(int num,j_complex_t * x,j_complex_t * w) {

if ((PRIM_EQUAL(num, 16384)) || ((PRIM_EQUAL(num, 8192)) || ((PRIM_EQUAL(num, 4096)) || ((PRIM_EQUAL(num, 2048)) || ((PRIM_EQUAL(num, 1024)) || ((PRIM_EQUAL(num, 512)) || ((PRIM_EQUAL(num, 256)) || ((PRIM_EQUAL(num, 128)) || (PRIM_EQUAL(num, 64)) || PRIM_EQUAL(num, 32) || PRIM_EQUAL(num, 16))))))))) {
int power_quad_acc_n;;
        power_quad_acc_n = num;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i112 = 0; i112 < power_quad_acc_n; i112++) {
                power_quad_acc_input[i112].im = x[i112].imag;
        };
        for (int i113 = 0; i113 < power_quad_acc_n; i113++) {
                power_quad_acc_input[i113].re = x[i113].real;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i114 = 0; i114 < power_quad_acc_n; i114++) {
                x[i114].real = power_quad_acc_output[i114].re;
        };
        for (int i115 = 0; i115 < power_quad_acc_n; i115++) {
                x[i115].imag = power_quad_acc_output[i115].im;
        };

;

;


} else {
fft_c(num, x, w);
}
}
void fft_c_accel(int num, j_complex_t * x, j_complex_t * w) {
fft_c_accel_internal((int) num, (j_complex_t *) x, (j_complex_t *) w);
}

void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

j_complex_t *input = akw0088_fft_generate_input(n);
j_complex_t w[n];
init_w(n, w); // would be dead-code eliminated

clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	fft_c_accel(n, input, w);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
free(input);
}

#endif
