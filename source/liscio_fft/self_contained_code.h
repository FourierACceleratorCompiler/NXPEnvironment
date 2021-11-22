#include "../LPC55S69_Project.h"

#ifdef PROJ_liscio_fft

#ifndef SELF_CONTAINED_CODE_H_
#define SELF_CONTAINED_CODE_H_

// We need these types to mirror the C99 complex types.
// The compiler knows the structure, we can't mirror the name
// since we need to integrate external to the compiler.
 typedef struct{ double re; double im;} _complex_double_;
_complex_double_ *FFT_wrapper (_complex_double_ *x, int N);

#endif
#endif
