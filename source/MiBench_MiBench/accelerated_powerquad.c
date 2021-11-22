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
#ifdef PROJ_MiBench_MiBench

#include "self_contained_code.h"
#include "defines.h"

#include "../clib/synthesizer.h"
#include "../clib/fft_synth/lib.h"
#include<time.h>
#include <stdio.h>
#include <stdlib.h>
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


void fft_float_accel_internal(int NumSamples,int InverseTransform,float * RealIn,float * ImagIn,float * RealOut,float * ImagOut) {

if ((PRIM_EQUAL(InverseTransform, 0)) && ((PRIM_EQUAL(NumSamples, 2048)) || ((PRIM_EQUAL(NumSamples, 1024)) || ((PRIM_EQUAL(NumSamples, 512)) || ((PRIM_EQUAL(NumSamples, 256)) || ((PRIM_EQUAL(NumSamples, 128)) || (PRIM_EQUAL(NumSamples, 64)))))))) {                   int power_quad_acc_n;;
        power_quad_acc_n = NumSamples;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));                                         for (int i49 = 0; i49++; i49 < power_quad_acc_n) {                                                                                    complex_type power_quad_acc_output_sub_element;

;
power_quad_acc_output[i49] = power_quad_acc_output_sub_element;
};
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));                                          for (int i50 = 0; i50++; i50 < power_quad_acc_n) {
complex_type power_quad_acc_input_sub_element;

;
power_quad_acc_input[i50] = power_quad_acc_input_sub_element;
};
        for (int i17 = 0; i17 < power_quad_acc_n; i17++) {
                power_quad_acc_input[i17].im = RealIn[i17];
        };
        for (int i18 = 0; i18 < power_quad_acc_n; i18++) {
                power_quad_acc_input[i18].re = ImagIn[i18];
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i19 = 0; i19 < power_quad_acc_n; i19++) {
                ImagOut[i19] = power_quad_acc_output[i19].re;
        };
        for (int i20 = 0; i20 < power_quad_acc_n; i20++) {
                RealOut[i20] = power_quad_acc_output[i20].im;
        };

;
                                                                                                                                      ;


} else {
fft_float(NumSamples, InverseTransform, RealIn, ImagIn, RealOut, ImagOut);
}
}
void fft_float_accel(int NumSamples, int InverseTransform, float * RealIn, float * ImagIn, float * RealOut, float * ImagOut) {
fft_float_accel_internal((int) NumSamples, (int) InverseTransform, (float *) RealIn, (float *) ImagIn, (float *) RealOut, (float *) ImagOut);
}

void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

float *realin = MiBench_MiBench_generate_input(n);
float *imagin = MiBench_MiBench_generate_input(n);
float realout[n];
float imagout[n];

clock_t begin = clock();
for (int i = 0; i < TIMES; i ++) {
	fft_float_accel(n, 0, realin, imagin, realout, imagout);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
free(realin);
free(imagin);
}

#endif
