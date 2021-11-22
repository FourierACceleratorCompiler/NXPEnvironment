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
#ifdef PROJ_jtfell_c_fft


#include "self_contained_code.h"
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

jcomplex * DFT_naive_accel_internal(jcomplex * x,int N) {

if ((PRIM_EQUAL(N, 2048)) || ((PRIM_EQUAL(N, 1024)) || ((PRIM_EQUAL(N, 512)) || ((PRIM_EQUAL(N, 256)) || ((PRIM_EQUAL(N, 128)) || (PRIM_EQUAL(N, 64)) || PRIM_EQUAL(N, 32) || PRIM_EQUAL(N, 16)))))) {
int power_quad_acc_n;;
        power_quad_acc_n = N;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i17 = 0; i17 < power_quad_acc_n; i17++) {
                power_quad_acc_input[i17].im = x[i17].im;
        };
        for (int i18 = 0; i18 < power_quad_acc_n; i18++) {
                power_quad_acc_input[i18].re = x[i18].re;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        jcomplex* returnv = (jcomplex*) facc_malloc (0, sizeof(jcomplex)*N);;
        for (int i19 = 0; i19 < power_quad_acc_n; i19++) {
                returnv[i19].im = power_quad_acc_output[i19].im;
        };
        for (int i20 = 0; i20 < power_quad_acc_n; i20++) {
                returnv[i20].re = power_quad_acc_output[i20].re;
        };

return returnv;;

;

;


} else {

return DFT_naive(x, N);;
}
}

jcomplex * DFT_naive_accel(jcomplex * x, int N) {
return (jcomplex *)DFT_naive_accel_internal((jcomplex *) x, (int) N);
}

void run_accelerator(int n) {
jcomplex *x = jtfell_c_fft_generate_inputs(n);

AcceleratorTotalNanos = 0;
clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	jcomplex * returnv = DFT_naive_accel(x, n);
	facc_free(returnv);
}
clock_t end = clock();


printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);

free(x);
}

#endif
