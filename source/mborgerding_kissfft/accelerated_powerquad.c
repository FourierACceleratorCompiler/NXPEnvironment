#include "../LPC55S69_Project.h"

#ifdef PROJ_mborgerding_kissfft

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

void kfc_fft_accel_internal(int nfft,kiss_fft_cpx * fin,kiss_fft_cpx * fout) {

if ((PRIM_EQUAL(nfft, 16384)) || ((PRIM_EQUAL(nfft, 8192)) || ((PRIM_EQUAL(nfft, 4096)) || ((PRIM_EQUAL(nfft, 2048)) || ((PRIM_EQUAL(nfft, 1024)) || ((PRIM_EQUAL(nfft, 512)) || ((PRIM_EQUAL(nfft, 256)) || ((PRIM_EQUAL(nfft, 128)) || (PRIM_EQUAL(nfft, 64)) || (PRIM_EQUAL(nfft, 32)) || (PRIM_EQUAL(nfft, 16)))))))))) {
int power_quad_acc_n;;
        power_quad_acc_n = nfft;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));;
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));;
        for (int i12 = 0; i12 < power_quad_acc_n; i12++) {
                power_quad_acc_input[i12].im = fin[i12].i;
        };
        for (int i13 = 0; i13 < power_quad_acc_n; i13++) {
                power_quad_acc_input[i13].re = fin[i13].r;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i14 = 0; i14 < power_quad_acc_n; i14++) {
                fout[i14].r = power_quad_acc_output[i14].re;
        };
        for (int i15 = 0; i15 < power_quad_acc_n; i15++) {
                fout[i15].i = power_quad_acc_output[i15].im;
        };

;

;


} else {
kfc_fft(nfft, fin, fout);
}
}

void kfc_fft_accel(int nfft, kiss_fft_cpx * fin, kiss_fft_cpx * fout) {
kfc_fft_accel_internal((int) nfft, (kiss_fft_cpx *) fin, (kiss_fft_cpx *) fout);
}
void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

kiss_fft_cpx *input = mborgerding_kissfft_generate_inputs(n);
kiss_fft_cpx  out[n];

clock_t begin = clock();

for (int i = 0; i < TIMES; i ++) {
	kfc_fft_accel(n, input, out);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
}
free(input);

#endif
