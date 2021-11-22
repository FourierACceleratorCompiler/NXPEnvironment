#include "../LPC55S69_Project.h"
#ifdef PROJ_JodiTheTigger_meow_fft

#ifndef SELF_CONTAINED_H
#define SELF_CONTAINED_H
#include<stdlib.h>

typedef struct Meow_FFT_Complex
{
    float r;
    float j;
}
Meow_FFT_Complex;


typedef struct Meow_Fft_Stages
{
    unsigned  count;
    unsigned* radix;
    unsigned* remainder;
    unsigned* offsets;
}
Meow_Fft_Stages;

typedef struct Meow_FFT_Workset
{
    int               N;

    Meow_FFT_Complex* wn;
    // Non-null only defined if there is a slow-dft as one of the radix stages.

    Meow_FFT_Complex* wn_ordered;
    // Sequentially ordered per stage, will be duplicates between stages.

    Meow_Fft_Stages   stages;
}
Meow_FFT_Workset;


extern void meow_fft
(
      const Meow_FFT_Workset* data
    , const Meow_FFT_Complex* in
    , Meow_FFT_Complex* out
);

extern size_t meow_fft_generate_workset
(
      int                      N
    , struct Meow_FFT_Workset* workset
);

#endif
#endif
