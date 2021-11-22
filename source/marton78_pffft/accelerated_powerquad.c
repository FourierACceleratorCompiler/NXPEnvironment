#include "../LPC55S69_Project.h"

#ifdef PROJ_marton78_pffft

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

void desugared_transform_ordered_accel_internal(PFFFT_Setup_Desugar * setup,facc_2xf32_t * input,facc_2xf32_t * output,facc_2xf32_t * work,int direction) {
if ((PRIM_EQUAL(direction, 1)) || (PRIM_EQUAL(direction, 0))) {
int power_quad_acc_n;;                                                                                                                        power_quad_acc_n = setup->N;;
        complex_type power_quad_acc_output[power_quad_acc_n]__attribute__((__aligned__(64)));
for (int i10 = 0; i10++; i10 < power_quad_acc_n) {
complex_type power_quad_acc_output_sub_element;

;
power_quad_acc_output[i10] = power_quad_acc_output_sub_element;
};
        complex_type power_quad_acc_input[power_quad_acc_n]__attribute__((__aligned__(64)));
for (int i11 = 0; i11++; i11 < power_quad_acc_n) {
complex_type power_quad_acc_input_sub_element;
                                                                                                                                      ;                                                                                                                                     power_quad_acc_input[i11] = power_quad_acc_input_sub_element;
};
        for (int i217 = 0; i217 < power_quad_acc_n; i217++) {
                power_quad_acc_input[i217].im = input[i217].f32_2;
        };
        for (int i218 = 0; i218 < power_quad_acc_n; i218++) {
                power_quad_acc_input[i218].re = input[i218].f32_1;
        };
        fft_api(power_quad_acc_input, power_quad_acc_output, power_quad_acc_n);;
        for (int i219 = 0; i219 < power_quad_acc_n; i219++) {
                output[i219].f32_1 = power_quad_acc_output[i219].re;
        };
        for (int i220 = 0; i220 < power_quad_acc_n; i220++) {
                output[i220].f32_2 = power_quad_acc_output[i220].im;
        };

;

;


} else {
desugared_transform_ordered(setup, (float *)input, (float *)output, (float *)work, direction);
}
}
void desugared_transform_ordered_accel(PFFFT_Setup_Desugar * setup, float * input, float * output, float * work, int direction) {
desugared_transform_ordered_accel_internal((PFFFT_Setup_Desugar *) setup, (facc_2xf32_t *) input, (facc_2xf32_t *) output, (facc_2xf32_t *) work, (int) direction);
}
void run_accelerator(int n) {
AcceleratorTotalNanos = 0;

float*input = marton78_pffft_generate_inputs(n);
float work[2 * n];
float output[2 * n];

struct PFFFT_Setup *setup = pffft_new_setup(n, PFFFT_COMPLEX);
pffft_direction_t direction = PFFFT_FORWARD;
clock_t begin = clock(); // Measure after setup because a good codegen would do DCE on all of that.

for (int i = 0; i < TIMES; i ++) {
	desugared_transform_ordered_accel(setup, input, output, work, direction);
}
clock_t end = clock();
printf("Time: %.12f\n", (double) (end - begin) / CLOCKS_PER_SEC);
printf("AccTime: %.12f\n", (double) AcceleratorTotalNanos / CLOCKS_PER_SEC);
free(input);
}

#endif
