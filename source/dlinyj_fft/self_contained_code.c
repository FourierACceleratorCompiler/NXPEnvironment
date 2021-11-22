
#include "../LPC55S69_Project.h"
#ifdef PROJ_dlinyj_fft

/*                                                                                                                                         * ÐŸÐµÑ€ÐµÐ½Ð¾Ñ�Ð¸Ð¼Ð°Ñ� Ñ€ÐµÐ°Ð»Ð¸Ð·Ð°Ñ†Ð¸Ñ� Ð‘ÐŸÐ¤ Ð´Ð»Ñ� Ð¿Ñ€Ð¾Ñ†ÐµÑ�Ñ�Ð¾Ñ€Ð¾Ð² Ñ�Ñ‚Ð°Ð½Ð´Ð°Ñ€Ñ‚Ð½Ð¾Ð¹ Ð°Ñ€Ñ…Ð¸Ñ‚ÐµÐºÑ‚ÑƒÑ€Ñ‹                                                                      * Ð’ÐµÑ€Ñ�Ð¸Ñ�: 0.2b
 * Ð¤Ð°Ð¹Ð»: "fft.h"
 * ÐšÐ¾Ð´Ð¸Ñ€Ð¾Ð²ÐºÐ°: UTF-8
 * Ð�Ð²Ñ‚Ð¾Ñ€Ñ‹: Ð”Ð¼Ð¸Ñ‚Ñ€Ð¸Ð¹ Ð¡ÑƒÑ�Ð»Ñ�ÐºÐ¾Ð², Ð�Ð»ÐµÐºÑ�Ð°Ð½Ð´Ñ€ Ð“Ñ€Ð¸Ð½ÑŒÐºÐ¾Ð²                                                                                            * Ð”Ð°Ñ‚Ð° Ð¼Ð¾Ð´Ð¸Ñ„Ð¸ÐºÐ°Ñ†Ð¸Ð¸: 2011.11.23
 */

#ifndef FFT_H
#define FFT_H
#define M_PI 3.14159265358979323846
//----------------------------------------------------------------------------
// Ð¾Ð¿Ñ†Ð¸Ñ� Ð¾Ñ‚Ð»Ð°Ð´Ð¾Ñ‡Ð½Ð¾Ð¹ Ð¿ÐµÑ‡Ð°Ñ‚Ð¸ Ð½Ð° stderr
#define FFT_DEBUG // FIXME
//----------------------------------------------------------------------------
#ifdef FFT_DEBUG
#  include <stdio.h> // fprintf()
#  ifdef FFT_WIN32
#    define FFT_DBG(fmt, ...) fprintf(stderr, "RK: " fmt "\n", __VA_ARGS__)
#  else
#    define FFT_DBG(fmt, arg...) fprintf(stderr, "RK: " fmt "\n", ## arg)
#  endif
#else
#  ifdef FFT_WIN32
#    define FFT_DBG(fmt, ...)
#  else
#    define FFT_DBG(fmt, arg...)
#  endif
#endif // FFT_DEBUG
//---------------------------------------------------------------------------
// inline macro
#ifndef FFT_INLINE
#  if __GNUC__
#    define FFT_INLINE static inline
#  else
#    define FFT_INLINE inline
#  endif
#endif // FFT_INLINE
//---------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ñ€Ð°Ñ�Ñ‡Ñ‘Ñ‚Ð° Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ Ð´Ð»Ñ� Ð‘ÐŸÐ¤
void fft_make(
  int p,     // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� Ð‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  float *c); // Ñ€ÐµÐ·ÑƒÐ»ÑŒÑ‚Ð¸Ñ€ÑƒÑŽÑ‰Ð¸Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ c[1 << p]
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ñ€Ð°Ñ�Ñ‡Ñ‘Ñ‚Ð° Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ Ð´Ð»Ñ� ÐžÐ‘ÐŸÐ¤
void fft_make_reverse(
  int p,     // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� ÐžÐ‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  float *c); // Ñ€ÐµÐ·ÑƒÐ»ÑŒÑ‚Ð¸Ñ€ÑƒÑŽÑ‰Ð¸Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ c[1 << p]
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ð±Ð¸Ð½Ð°Ñ€Ð½Ð¾Ð¹ Ð¸Ð½Ð²ÐµÑ€Ñ�Ð¸Ð¸ Ð¸Ð½Ð´ÐµÐºÑ�Ð°
FFT_INLINE int fft_binary_inversion(
  int p, // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� Ð‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  int i) // Ð¸Ñ�Ñ…Ð¾Ð´Ð½Ñ‹Ð¹ Ð¸Ð½Ð´ÐµÐºÑ� [0, (1 << p) - 1]
{
  int j = 0;
  while (p-- > 0)
  {
    j <<= 1;
    j |= i & 1;
    i >>= 1;
  }
  return j;
}
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ð¿Ñ€Ñ�Ð¼Ð¾Ð³Ð¾ Ð‘ÐŸÐ¤
void fft_calc(
  int p,           // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� Ð‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  const float *c,  // Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ Ð‘ÐŸÐ¤
  const float *in, // Ð²Ñ…Ð¾Ð´Ð½Ð¾Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð²
  float *out,      // Ð²Ñ‹Ñ…Ð¾Ð´Ð½Ð¾Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð²
  int norm);       // Ð¿Ñ€Ð¸Ð·Ð½Ð°Ðº Ð½Ð¾Ñ€Ð¼Ð¸Ñ€Ð¾Ð²ÐºÐ¸
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ð¾Ð±Ñ€Ð°Ñ‚Ð½Ð¾Ð³Ð¾ Ð‘ÐŸÐ¤
FFT_INLINE void fft_calc_reverse(
  int p,           // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� Ð‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  const float *c,  // Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ ÐžÐ‘ÐŸÐ¤
  const float *in, // Ð²Ñ…Ð¾Ð´Ð½Ð¾Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð²
  float *out,      // Ð²Ñ‹Ñ…Ð¾Ð´Ð½Ð¾Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð²
  int norm)        // Ð¿Ñ€Ð¸Ð·Ð½Ð°Ðº Ð½Ð¾Ñ€Ð¼Ð¸Ñ€Ð¾Ð²ÐºÐ¸
{
  fft_calc(p, c, in, out, !norm); // Ð‘ÐŸÐ¤
}
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ð¿ÐµÑ€ÐµÑ�Ñ‚Ð°Ð½Ð¾Ð²ÐºÐ¸ Ð¾Ñ‚Ñ�Ñ‡Ñ‘Ñ‚Ð¾Ð² Ñ�Ð¿ÐµÐºÑ‚Ñ€Ð° (Ñ‡Ñ‚Ð¾ Ð±Ñ‹ "0" Ð² Ñ†ÐµÐ½Ñ‚Ñ€Ðµ)
void fft_shift(
  int p,        // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� Ð‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  float *data); // Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ñ�Ð»Ðµ Ð‘ÐŸÐ¤
//----------------------------------------------------------------------------
#ifdef __cplusplus
}
#endif // __cplusplus
//----------------------------------------------------------------------------
#endif // FFT_H

/*** end of "fft.h" file ***/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ñ€Ð°Ñ�Ñ‡Ñ‘Ñ‚Ð° Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ Ð´Ð»Ñ� Ð‘ÐŸÐ¤
void fft_make(
  int p,    // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� Ð‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  float *c) // Ñ€ÐµÐ·ÑƒÐ»ÑŒÑ‚Ð¸Ñ€ÑƒÑŽÑ‰Ð¸Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ c[1 << p]
{
  int n, i;
  float w, f;
  n = 1 << p; // Ñ€Ð°Ð·Ð¼ÐµÑ€ Ð¼Ð°Ñ�Ñ�Ð¸Ð²Ð° (Ñ‡Ð¸Ñ�Ð»Ð¾ Ñ‚Ð¾Ñ‡ÐµÐº Ð‘ÐŸÐ¤)
  w = (2. * M_PI) / (float) n;
  f = 0.;
  for (i = 0; i < n; i++)
  {
    *c++ =  cos(f);
    *c++ = -sin(f);
    f += w;
  }
}
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ñ€Ð°Ñ�Ñ‡Ñ‘Ñ‚Ð° Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ Ð´Ð»Ñ� ÐžÐ‘ÐŸÐ¤
void fft_make_reverse(
  int p,    // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� ÐžÐ‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  float *c) // Ñ€ÐµÐ·ÑƒÐ»ÑŒÑ‚Ð¸Ñ€ÑƒÑŽÑ‰Ð¸Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ c[1 << p]
{
  int n, i;
  float w, f;
  n = 1 << p; // Ñ€Ð°Ð·Ð¼ÐµÑ€ Ð¼Ð°Ñ�Ñ�Ð¸Ð²Ð° (Ñ‡Ð¸Ñ�Ð»Ð¾ Ñ‚Ð¾Ñ‡ÐµÐº ÐžÐ‘ÐŸÐ¤)
  w = (2. * M_PI) / (float) n;
  f = 0.;
  for (i = 0; i < n; i++)
  {
    *c++ = cos(f);
    *c++ = sin(f);
    f += w;
  }
}
//----------------------------------------------------------------------------
// Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ð¿Ñ€Ñ�Ð¼Ð¾Ð³Ð¾ Ð‘ÐŸÐ¤
void fft_calc(
  int p,           // Ð¿Ð¾ÐºÐ°Ð·Ð°Ñ‚ÐµÐ»ÑŒ Ð´Ð²Ð¾Ð¹ÐºÐ¸ (Ð½Ð°Ð¿Ñ€Ð¸Ð¼ÐµÑ€, Ð´Ð»Ñ� Ð‘ÐŸÐ¤ Ð½Ð° 256 Ñ‚Ð¾Ñ‡ÐµÐº Ñ�Ñ‚Ð¾ 8)
  const float *c,  // Ð¼Ð°Ñ�Ñ�Ð¸Ð² Ð¿Ð¾Ð²Ð¾Ñ€Ð¾Ñ‚Ð½Ñ‹Ñ… Ð¼Ð½Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÐµÐ¹ Ð‘ÐŸÐ¤
  const float *in, // Ð²Ñ…Ð¾Ð´Ð½Ð¾Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð²
  float *out,      // Ð²Ñ‹Ñ…Ð¾Ð´Ð½Ð¾Ð¹ Ð¼Ð°Ñ�Ñ�Ð¸Ð²
  int norm)        // Ð¿Ñ€Ð¸Ð·Ð½Ð°Ðº Ð½Ð¾Ñ€Ð¼Ð¸Ñ€Ð¾Ð²ÐºÐ¸
{
  int i;
  int n = 1 << p;  // Ñ‡Ð¸Ñ�Ð»Ð¾ Ñ‚Ð¾Ñ‡ÐµÐº Ð‘ÐŸÐ¤
  int n2 = n >> 1; // n/2
  float re, im, re1, im1, re2, im2; // c, c1, c2
  float *p1, *p2;
  const float *p0;

  // ÐºÐ¾Ð¿Ð¸Ñ€Ð¾Ð²Ð°Ñ‚ÑŒ Ñ�Ð»ÐµÐ¼ÐµÐ½Ñ‚Ñ‹ Ð¼Ð°Ñ�Ñ�Ð¸Ð²Ð° `in` Ð² Ð¼Ð°Ñ�Ñ�Ð¸Ð² `out` Ñ� Ð±Ð¸Ñ‚Ð¾Ð²Ð¾Ð¹ Ð¸Ð½Ð²ÐµÑ€Ñ�Ð¸ÐµÐ¹
  for (i = 0; i < n; i++)
  {
    int j = fft_binary_inversion(p, i) << 1;
    int k = i << 1;

    p0 = in  + j;
    p1 = out + k;
    *p1++ = *p0++; // out[i] = in[j]
    *p1   = *p0;   //

    p0 = in  + k;
    p1 = out + j;
    *p1++ = *p0++; // out[j] = in[i]
    *p1   = *p0;   //
  }

  // Ð²Ñ‹Ð¿Ð¾Ð»Ð½ÐµÐ½Ð¸Ðµ Ð±Ð°Ð±Ð¾Ñ‡ÐµÐº ("Ð¿Ð¾Ð½ÐµÑ�Ð»Ð°Ñ�ÑŒ Ð´ÑƒÑˆÐ° Ð² Ñ€Ð°Ð¹" (C) Hokum)
  for (i = 0; i < p; i++)
  {
    int m = 1 << (i + 1); // Ñ‡ÐµÑ€ÐµÐ· Ñ�ÐºÐ¾Ð»ÑŒÐºÐ¾ Ñ�Ð»-Ñ‚Ð¾Ð² Ð±Ð°Ð±Ð¾Ñ‡ÐºÐ° * 2
    int r = m << 1;       // Ñ€Ð°Ð·Ð¼ÐµÑ€ Ð³Ñ€ÑƒÐ¿Ð¿Ñ‹ * 2
    int nom = 0;          // Ð½Ð¾Ð¼ÐµÑ€ Ð³Ñ€ÑƒÐ¿Ð¿Ñ‹ * r
    int k = 0;            // Ð½Ð¾Ð¼ÐµÑ€ Ñ�Ð»-Ñ‚Ð° Ð² Ð³Ñ€ÑƒÐ¿Ð¿Ðµ * 2
    int y = 0;            // Ð¸Ð½Ð´ÐµÐºÑ� W * 2
    int z = 0;
    int h = 1 << (p - i); // ÑˆÐ°Ð³ Ð´Ð»Ñ� W * 2
    int j;

    for (j = n2; j > 0; j--)
    {
      if (k >= m)
      {
        k = y = 0;
        nom += r;
        z = nom;
      }

      // c <= c[y]
      p0 = c + y;
      re = *p0++;
      im = *p0;

      // c2 <= out[z + m]
      p1  = out + (z + m);
      re2 = *p1++;
      im2 = *p1;

      // c1 <= c2 * c
      re1 = re2 * re - im2 * im;
      im1 = im2 * re + re2 * im;

      // c2 <= out[z]
      p2  = out + z;
      re2 = *p2++;
      im2 = *p2;

      // out[z]     <= c2 + c1
      // out[z + m] <= c2 - c1
      *p2-- = im2 + im1;
      *p1-- = im2 - im1;
      *p2   = re2 + re1;
      *p1   = re2 - re1;

      k += 2;
      z += 2;
      y += h;
    }
  }

  if (norm)
  { // Ð½Ð¾Ñ€Ð¼Ð¸Ñ€Ð¾Ð²ÐºÐ°
    re = 1. / ((float) n);
    p1 = out;
    for (i = n; i > 0; i--)
    {
      *p1++ *= re;
      *p1++ *= re;
    }
  }
}
#endif
