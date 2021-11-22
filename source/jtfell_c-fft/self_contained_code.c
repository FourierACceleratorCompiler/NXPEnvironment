#include "../LPC55S69_Project.h"

#ifdef PROJ_jtfell_c_fft
#include <math.h>
#include <stdlib.h>
#include "self_contained_code.h"

jcomplex conv_from_polar(double r, double radians) {
    jcomplex result;
    result.re = r * cos(radians);
    result.im = r * sin(radians);
    return result;
}

jcomplex add(jcomplex left, jcomplex right) {
    jcomplex result;
    result.re = left.re + right.re;
    result.im = left.im + right.im;
    return result;
}

jcomplex multiply(jcomplex left, jcomplex right) {
    jcomplex result;
    result.re = left.re*right.re - left.im*right.im;
    result.im = left.re*right.im + left.im*right.re;
    return result;
}
#define PI 3.1415926535897932384626434

jcomplex* DFT_naive(jcomplex* x, int N) {
    jcomplex* X = (jcomplex*) malloc(sizeof(struct complex_t) * N);
    int k, n;
    for(k = 0; k < N; k++) {
        X[k].re = 0.0;
        X[k].im = 0.0;
        for(n = 0; n < N; n++) {
            X[k] = add(X[k], multiply(x[n], conv_from_polar(1, -2*PI*n*k/N)));
        }
    }
    
    return X;
}

#endif
