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
And (fromvars) [x, im]
Under dimensions [adi_acc_n = N]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers adi_acc_input,im
And (fromvars) [x, re]
Under dimensions [adi_acc_n = N]
With conversion function IdentityConversion
Post: SKELETON:

With the array index wrappers returnvar,Annon
And (fromvars) []
Under dimensions [N = adi_acc_n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers returnvar,im
And (fromvars) [adi_acc_output, re]
Under dimensions [N = adi_acc_n]
With conversion function IdentityConversion

>(new binding): 

With the array index wrappers returnvar,re
And (fromvars) [adi_acc_output, im]
Under dimensions [N = adi_acc_n]
With conversion function IdentityConversion
*/

#include "../LPC55S69_Project.h"
#ifdef PROJ_omnister_fftp


#include"../clib/synthesizer.h"
#include "defines.h"
#include<time.h>
#include<stdio.h>
#include "../fft_api.h"

clock_t AcceleratorStart;
long AcceleratorTotalNanos = 0;
void StartAcceleratorTimer() {
	AcceleratorStart = clock();
}

void StopAcceleratorTimer() {
	AcceleratorTotalNanos +=
		(clock()) - AcceleratorStart;
}

COMPLEX * fft_1d_accel_internal(COMPLEX * array,int n) {

if ((PRIM_EQUAL(n, 2048)) || ((PRIM_EQUAL(n, 1024)) || ((PRIM_EQUAL(n, 512)) || ((PRIM_EQUAL(n, 256)) || ((PRIM_EQUAL(n, 128)) || (PRIM_EQUAL(n, 64))))))) {
int power_quad_acc_n;;
        power_quad_acc_n = n;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));
for (int i41 = 0; i41++; i41 < power_quad_acc_n) {
complex_type power_quad_acc_output_sub_element;

;
power_quad_acc_output[i41] = power_quad_acc_output_sub_element;
};
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));
for (int i42 = 0; i42++; i42 < power_quad_acc_n) {
complex_type power_quad_acc_input_sub_element;

;
power_quad_acc_input[i42] = power_quad_acc_input_sub_element;
};
        for (int i2 = 0; i2 < power_quad_acc_n; i2++) {
                power_quad_acc_input[i2].im = array[i2].im;
        };
        for (int i3 = 0; i3 < power_quad_acc_n; i3++) {
                power_quad_acc_input[i3].re = array[i3].re;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i4 = 0; i4 < power_quad_acc_n; i4++) {
                array[i4].im = power_quad_acc_output[i4].im;
        };
        for (int i5 = 0; i5 < power_quad_acc_n; i5++) {
                array[i5].re = power_quad_acc_output[i5].re;
        };

return array;;

;

;


} else {

return fft_1d(array, n);;
}
}
COMPLEX * fft_1d_accel(COMPLEX * array, int n) {
return (COMPLEX *)fft_1d_accel_internal((COMPLEX *) array, (int) n);
}

void run_accelerator(int n) {
COMPLEX *array = omnister_fftp_generate_inputs(n);

AcceleratorTotalNanos = 0;
clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	array = fft_1d_accel(array, n);
}
clock_t end = clock();


printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);

free(array);
}

#endif
