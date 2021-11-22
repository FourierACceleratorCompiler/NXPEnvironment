#include "../LPC55S69_Project.h"

#ifdef PROJ_dlinyj_fft

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

void fft_calc_accel_internal(int p,facc_2xf32_t * c,facc_2xf32_t * in,facc_2xf32_t * out,int norm) {

if ((PRIM_EQUAL(norm, 1)) && ((PRIM_EQUAL(p, 11)) || ((PRIM_EQUAL(p, 10)) || ((PRIM_EQUAL(p, 9)) || ((PRIM_EQUAL(p, 8)) || ((PRIM_EQUAL(p, 7)) || (PRIM_EQUAL(p, 6)) || PRIM_EQUAL(p, 5) || PRIM_EQUAL(p, 4))))))) {
int power_quad_acc_n;;
        power_quad_acc_n = Pow2(p);;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i52 = 0; i52 < power_quad_acc_n; i52++) {
                power_quad_acc_input[i52].im = in[i52].f32_2;
        };
        for (int i53 = 0; i53 < power_quad_acc_n; i53++) {
                power_quad_acc_input[i53].re = in[i53].f32_1;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i54 = 0; i54 < power_quad_acc_n; i54++) {
                out[i54].f32_1 = power_quad_acc_output[i54].re;
        };
        for (int i55 = 0; i55 < power_quad_acc_n; i55++) {
                out[i55].f32_2 = power_quad_acc_output[i55].im;
        };

;

;

;

if (GREATER_THAN(norm, -1)) {
long int bi_1;;
        bi_1 = Pow2(p);;;
        ARRAY_HALF_NORM(out, f32_1, bi_1);;
        ARRAY_HALF_NORM(out, f32_2, bi_1);
} else {
;
}
} else {
fft_calc(p, (float *)c, (float *)in, (float *)out, norm);
}
}

void fft_calc_accel(int p, float * c, float * in, float * out, int norm) {
fft_calc_accel_internal((int) p, (facc_2xf32_t *) c, (facc_2xf32_t *) in, (facc_2xf32_t *) out, (int) norm);
}

void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

float *input = dlinyj_fft_generate_inputs(n);
float output[2*n];
float c[n * 2];
int p = log(n);
fft_make(p, c);
clock_t begin = clock(); // Measure after setup because a good codegen would do DCE on all of that.

for (int i = 0; i < TIMES; i ++) {
	fft_calc_accel(p, c, input, output, 1);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
}
free(input);

#endif
