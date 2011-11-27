/*
 * File: calibrazione0.c
 *
 * Code generated for Simulink model 'calibrazione0'.
 *
 * Model version                  : 1.70
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Tue Nov 01 13:14:50 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "calibrazione0.h"
#include "calibrazione0_private.h"

/* Block signals (auto storage) */
BlockIO_calibrazione0 calibrazione0_B;

/* Block states (auto storage) */
D_Work_calibrazione0 calibrazione0_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_calibrazione0 calibrazione0_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_calibrazione0 calibrazione0_Y;

/* Real-time model */
RT_MODEL_calibrazione0 calibrazione0_M_;
RT_MODEL_calibrazione0 *const calibrazione0_M = &calibrazione0_M_;

/* Forward declaration for local functions */
static void calibrazione0_eml_xscal(int32_T n, real_T a, real_T x[100], int32_T
  ix0);
static void calibrazione0_eml_xswap(real_T x[100], int32_T ix0, int32_T iy0);
static void calibrazione0_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
static void calibrazione0_eml_xrot(real_T x[100], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T calibrazione0_max(const real_T varargin_1[5]);
static real_T calibrazione0_eml_xdotc(int32_T n, const real_T x[100], int32_T
  ix0, const real_T y[100], int32_T iy0);
static void calibrazione0_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y
  [100], int32_T iy0);
static real_T calibrazione0_eml_xnrm2(int32_T n, const real_T x[100], int32_T
  ix0);
static real_T calibrazione0_eml_xnrm2_d(int32_T n, const real_T x[10], int32_T
  ix0);
static void calibrazione0_eml_xscal_d(int32_T n, real_T a, real_T x[10], int32_T
  ix0);
static void calibrazione0_eml_xaxpy_dq(int32_T n, real_T a, const real_T x[10],
  int32_T ix0, real_T y[100], int32_T iy0);
static void calibrazione0_eml_xaxpy_d(int32_T n, real_T a, const real_T x[100],
  int32_T ix0, real_T y[10], int32_T iy0);
static void calibrazione0_eml_xgesvd(const real_T A[100], real_T U[100], real_T
  S[10], real_T V[100]);
static void calibrazione0_svd(const real_T A[100], real_T U[100], real_T S[100],
  real_T V[100]);
static void calibrazione0_inv(const real_T x[9], real_T y[9]);
static real_T calibrazione0_eml_xnrm2_dq(int32_T n, const real_T x[9], int32_T
  ix0);
static void calibrazione0_eml_xscal_dq(int32_T n, real_T a, real_T x[9], int32_T
  ix0);
static real_T calibrazione0_eml_xnrm2_dqu(int32_T n, const real_T x[3], int32_T
  ix0);
static void calibrazione0_eml_xscal_dqu(int32_T n, real_T a, real_T x[3],
  int32_T ix0);
static void calibrazione0_eml_xswap_d(real_T x[9], int32_T ix0, int32_T iy0);
static void calibrazione0_eml_xrot_d(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s);
static real_T calibrazione0_eml_xdotc_d(int32_T n, const real_T x[9], int32_T
  ix0, const real_T y[9], int32_T iy0);
static void calibrazione0_eml_xaxpy_dqu(int32_T n, real_T a, int32_T ix0, real_T
  y[9], int32_T iy0);
static void calibrazione0_eml_xaxpy_dquua(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[9], int32_T iy0);
static void calibrazione0_eml_xaxpy_dquu(int32_T n, real_T a, const real_T x[9],
  int32_T ix0, real_T y[3], int32_T iy0);
static void calibrazione0_eml_xgesvd_d(const real_T A[9], real_T U[9], real_T S
  [3], real_T V[9]);
static void calibrazione0_svd_d(const real_T A[9], real_T U[9], real_T S[9],
  real_T V[9]);
static void calibrazione0_sqrt(real_T x[9]);
void mul_wide_s32(int32_T in0, int32_T in1, uint32_T *ptrOutBitsHi, uint32_T
                  *ptrOutBitsLo)
{
  uint32_T absIn;
  uint32_T absIn_0;
  uint32_T in0Lo;
  uint32_T in0Hi;
  uint32_T in1Hi;
  uint32_T productHiLo;
  uint32_T productLoHi;
  absIn = (uint32_T)(in0 < 0 ? -in0 : in0);
  absIn_0 = (uint32_T)(in1 < 0 ? -in1 : in1);
  in0Hi = absIn >> 16;
  in0Lo = absIn & 65535U;
  in1Hi = absIn_0 >> 16;
  absIn = absIn_0 & 65535U;
  productHiLo = in0Hi * absIn;
  productLoHi = in0Lo * in1Hi;
  absIn *= in0Lo;
  absIn_0 = 0;
  in0Lo = (productLoHi << 16) + absIn;
  if (in0Lo < absIn) {
    absIn_0 = (uint32_T)1;
  }

  absIn = in0Lo;
  in0Lo += productHiLo << 16;
  if (in0Lo < absIn) {
    absIn_0++;
  }

  absIn = ((in0Hi * in1Hi + absIn_0) + (productLoHi >> 16)) + (productHiLo >> 16);
  if (!((in0 == 0) || (in1 == 0) || ((in0 > 0) == (in1 > 0)))) {
    absIn = ~absIn;
    in0Lo = ~in0Lo;
    in0Lo++;
    if (in0Lo == 0) {
      absIn++;
    }
  }

  *ptrOutBitsHi = absIn;
  *ptrOutBitsLo = in0Lo;
}

int32_T mul_s32_s32_s32_sat(int32_T a, int32_T b)
{
  int32_T result;
  uint32_T u32_chi;
  uint32_T u32_clo;
  mul_wide_s32(a, b, &u32_chi, &u32_clo);
  if (((int32_T)u32_chi > 0) || ((u32_chi == 0) && (u32_clo >= 2147483648U))) {
    result = MAX_int32_T;
  } else if (((int32_T)u32_chi < -1) || (((int32_T)u32_chi == -1) && (u32_clo <
               2147483648U))) {
    result = MIN_int32_T;
  } else {
    result = (int32_T)u32_clo;
  }

  return result;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    y = atan2(u0 > 0.0 ? 1.0 : -1.0, u1 > 0.0 ? 1.0 : -1.0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = (rtNaN);
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xscal(int32_T n, real_T a, real_T x[100], int32_T
  ix0)
{
  int32_T k;
  int32_T loop_ub;
  loop_ub = (ix0 + n) - 1;
  for (k = ix0; k <= loop_ub; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xswap(real_T x[100], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 10; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xrotg(real_T *a, real_T *b, real_T *c, real_T *s)
{
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale;
  real_T ads;
  real_T bds;
  real_T r;
  roe = *b;
  absa = fabs(*a);
  absb = fabs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    bds = 0.0;
    ads = 1.0;
    r = 0.0;
    scale = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    r = sqrt(ads * ads + bds * bds) * scale;
    if (roe < 0.0) {
      r = -r;
    }

    ads = *a / r;
    bds = *b / r;
    if (absa > absb) {
      scale = bds;
    } else if (ads != 0.0) {
      scale = 1.0 / ads;
    } else {
      scale = 1.0;
    }
  }

  *a = r;
  *b = scale;
  *c = ads;
  *s = bds;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xrot(real_T x[100], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  real_T y;
  real_T b_y;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 10; k++) {
    y = c * x[ix];
    b_y = s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = y + b_y;
    iy++;
    ix++;
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static real_T calibrazione0_max(const real_T varargin_1[5])
{
  real_T mtmp;
  int32_T itmp;
  int32_T ix;
  boolean_T searchingForNonNaN;
  int32_T k;
  boolean_T guard;
  boolean_T exitg;
  mtmp = varargin_1[0];
  itmp = 1;
  ix = 0;
  guard = FALSE;
  if (rtIsNaN(varargin_1[0])) {
    searchingForNonNaN = TRUE;
    k = 2;
    exitg = FALSE;
    while (((uint32_T)exitg == 0U) && (k < 6)) {
      ix++;
      if (!rtIsNaN(varargin_1[ix])) {
        mtmp = varargin_1[ix];
        itmp = k;
        searchingForNonNaN = FALSE;
        exitg = TRUE;
      } else {
        k++;
      }
    }

    if (!searchingForNonNaN) {
      guard = TRUE;
    }
  } else {
    guard = TRUE;
  }

  if (guard) {
    while (itmp + 1 < 6) {
      if (varargin_1[itmp] > mtmp) {
        mtmp = varargin_1[itmp];
      }

      itmp++;
    }
  }

  return mtmp;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static real_T calibrazione0_eml_xdotc(int32_T n, const real_T x[100], int32_T
  ix0, const real_T y[100], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (!(n < 1)) {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y
  [100], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k <= n - 1; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static real_T calibrazione0_eml_xnrm2(int32_T n, const real_T x[100], int32_T
  ix0)
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 0.0;
      firstNonZero = TRUE;
      kend = (ix0 + n) - 1;
      for (k = ix0 - 1; k + 1 <= kend; k++) {
        if (x[k] != 0.0) {
          absxk = fabs(x[k]);
          if (firstNonZero) {
            scale = absxk;
            y = 1.0;
            firstNonZero = FALSE;
          } else if (scale < absxk) {
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static real_T calibrazione0_eml_xnrm2_d(int32_T n, const real_T x[10], int32_T
  ix0)
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 0.0;
      firstNonZero = TRUE;
      kend = (ix0 + n) - 1;
      for (k = ix0 - 1; k + 1 <= kend; k++) {
        if (x[k] != 0.0) {
          absxk = fabs(x[k]);
          if (firstNonZero) {
            scale = absxk;
            y = 1.0;
            firstNonZero = FALSE;
          } else if (scale < absxk) {
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xscal_d(int32_T n, real_T a, real_T x[10], int32_T
  ix0)
{
  int32_T k;
  int32_T loop_ub;
  loop_ub = (ix0 + n) - 1;
  for (k = ix0; k <= loop_ub; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xaxpy_dq(int32_T n, real_T a, const real_T x[10],
  int32_T ix0, real_T y[100], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k <= n - 1; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xaxpy_d(int32_T n, real_T a, const real_T x[100],
  int32_T ix0, real_T y[10], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k <= n - 1; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xgesvd(const real_T A[100], real_T U[100], real_T
  S[10], real_T V[100])
{
  real_T b_A[100];
  real_T s[10];
  real_T e[10];
  real_T work[10];
  int32_T q;
  int32_T qp;
  int32_T iter;
  real_T snorm;
  real_T ztest;
  int32_T kase;
  int32_T qs;
  real_T ztest_0;
  real_T f;
  int32_T km1;
  real_T scale;
  real_T sm;
  real_T sqds;
  real_T b;
  boolean_T exitg;
  int32_T i;
  real_T tmp[5];
  memcpy((void *)&b_A[0], (void *)&A[0], 100U * sizeof(real_T));
  for (i = 0; i < 10; i++) {
    s[i] = 0.0;
    e[i] = 0.0;
    work[i] = 0.0;
  }

  for (i = 0; i < 100; i++) {
    U[i] = 0.0;
    V[i] = 0.0;
  }

  for (i = 0; i < 9; i++) {
    qp = i + 2;
    iter = (10 * i + i) + 1;
    km1 = 9 - i;
    qs = km1 + 1;
    ztest = calibrazione0_eml_xnrm2(qs, b_A, iter);
    if (ztest == 0.0) {
      s[i] = 0.0;
    } else {
      if (b_A[iter - 1] < 0.0) {
        ztest = -ztest;
      }

      s[i] = ztest;
      calibrazione0_eml_xscal(qs, 1.0 / s[i], b_A, iter);
      b_A[iter - 1]++;
      s[i] = -s[i];
    }

    for (kase = qp; kase < 11; kase++) {
      q = ((kase - 1) * 10 + i) + 1;
      if (s[i] != 0.0) {
        calibrazione0_eml_xaxpy(qs, -(calibrazione0_eml_xdotc(qs, b_A, iter, b_A,
          q) / b_A[i + 10 * i]), iter, b_A, q);
      }

      e[kase - 1] = b_A[q - 1];
    }

    for (kase = i; kase + 1 < 11; kase++) {
      U[kase + 10 * i] = b_A[10 * i + kase];
    }

    if (i + 1 <= 8) {
      iter = 9 - i;
      ztest = calibrazione0_eml_xnrm2_d(iter, e, qp);
      if (ztest == 0.0) {
        e[i] = 0.0;
      } else {
        if (e[qp - 1] < 0.0) {
          ztest = -ztest;
        }

        e[i] = ztest;
        calibrazione0_eml_xscal_d(iter, 1.0 / e[i], e, qp);
        e[qp - 1]++;
      }

      e[i] = -e[i];
      if (e[i] != 0.0) {
        for (kase = qp; kase < 11; kase++) {
          work[kase - 1] = 0.0;
        }

        for (kase = qp; kase < 11; kase++) {
          calibrazione0_eml_xaxpy_d(km1, e[kase - 1], b_A, qp + 10 * (kase - 1),
            work, qp);
        }

        for (kase = qp; kase < 11; kase++) {
          calibrazione0_eml_xaxpy_dq(km1, -e[kase - 1] / e[qp - 1], work, qp,
            b_A, qp + 10 * (kase - 1));
        }
      }

      for (kase = qp; kase < 11; kase++) {
        V[(kase + 10 * i) - 1] = e[kase - 1];
      }
    }
  }

  i = 10;
  s[9] = b_A[99];
  e[8] = b_A[98];
  e[9] = 0.0;
  for (kase = 0; kase < 10; kase++) {
    U[90 + kase] = 0.0;
  }

  U[99] = 1.0;
  for (km1 = 8; km1 >= 0; km1 += -1) {
    qs = 10 - km1;
    iter = 10 * km1 + km1;
    if (s[km1] != 0.0) {
      for (kase = km1 + 1; kase + 1 < 11; kase++) {
        q = (10 * kase + km1) + 1;
        calibrazione0_eml_xaxpy(qs, -(calibrazione0_eml_xdotc(qs, U, iter + 1, U,
          q) / U[iter]), iter + 1, U, q);
      }

      for (kase = km1; kase + 1 < 11; kase++) {
        U[kase + 10 * km1] = -U[10 * km1 + kase];
      }

      U[iter]++;
      for (kase = 1; kase <= km1; kase++) {
        U[(kase + 10 * km1) - 1] = 0.0;
      }
    } else {
      for (kase = 0; kase < 10; kase++) {
        U[kase + 10 * km1] = 0.0;
      }

      U[iter] = 1.0;
    }
  }

  for (q = 9; q >= 0; q += -1) {
    if ((q + 1 <= 8) && (e[q] != 0.0)) {
      qp = q + 2;
      iter = 9 - q;
      kase = 10 * q + qp;
      for (km1 = qp; km1 < 11; km1++) {
        qs = (km1 - 1) * 10 + qp;
        calibrazione0_eml_xaxpy(iter, -(calibrazione0_eml_xdotc(iter, V, kase, V,
          qs) / V[kase - 1]), kase, V, qs);
      }
    }

    for (kase = 0; kase < 10; kase++) {
      V[kase + 10 * q] = 0.0;
    }

    V[q + 10 * q] = 1.0;
  }

  for (kase = 0; kase < 10; kase++) {
    f = e[kase];
    if (s[kase] != 0.0) {
      ztest_0 = fabs(s[kase]);
      ztest = s[kase] / ztest_0;
      s[kase] = ztest_0;
      if (kase + 1 < 10) {
        f = e[kase] / ztest;
      }

      calibrazione0_eml_xscal(10, ztest, U, 1 + 10 * kase);
    }

    if ((kase + 1 < 10) && (f != 0.0)) {
      ztest_0 = fabs(f);
      ztest = ztest_0 / f;
      f = ztest_0;
      s[kase + 1] *= ztest;
      calibrazione0_eml_xscal(10, ztest, V, 1 + 10 * (kase + 1));
    }

    e[kase] = f;
  }

  iter = 0;
  snorm = 0.0;
  for (kase = 0; kase < 10; kase++) {
    f = fabs(s[kase]);
    b = fabs(e[kase]);
    f = (f >= b) || rtIsNaN(b) ? f : b;
    snorm = (snorm >= f) || rtIsNaN(f) ? snorm : f;
  }

  while ((i > 0) && (!(iter >= 75))) {
    km1 = i - 1;
    do {
      kase = 0;
      q = km1;
      if (km1 == 0) {
        kase = 1;
      } else {
        ztest = fabs(e[km1 - 1]);
        if ((ztest <= (fabs(s[km1 - 1]) + fabs(s[km1])) * 2.2204460492503131E-16)
            || (ztest <= 1.0020841800044864E-292) || ((iter > 20) && (ztest <=
              2.2204460492503131E-16 * snorm))) {
          e[km1 - 1] = 0.0;
          kase = 1;
        } else {
          km1--;
        }
      }
    } while ((uint32_T)kase == 0U);

    if (i - 1 == km1) {
      kase = 4;
    } else {
      qs = i;
      kase = i;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (kase >= km1)) {
        qs = kase;
        if (kase == km1) {
          exitg = TRUE;
        } else {
          ztest = 0.0;
          if (kase < i) {
            ztest = fabs(e[kase - 1]);
          }

          if (kase > km1 + 1) {
            ztest += fabs(e[kase - 2]);
          }

          ztest_0 = fabs(s[kase - 1]);
          if ((ztest_0 <= 2.2204460492503131E-16 * ztest) || (ztest_0 <=
               1.0020841800044864E-292)) {
            s[kase - 1] = 0.0;
            exitg = TRUE;
          } else {
            kase--;
          }
        }
      }

      if (qs == km1) {
        kase = 3;
      } else if (qs == i) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      f = e[i - 2];
      e[i - 2] = 0.0;
      for (kase = i - 2; kase + 1 >= q + 1; kase--) {
        ztest = s[kase];
        calibrazione0_eml_xrotg(&ztest, &f, &ztest_0, &b);
        s[kase] = ztest;
        if (kase + 1 > q + 1) {
          km1 = kase - 1;
          f = -b * e[km1];
          e[km1] *= ztest_0;
        }

        calibrazione0_eml_xrot(V, 1 + 10 * kase, 1 + 10 * (i - 1), ztest_0, b);
      }
      break;

     case 2:
      kase = q - 1;
      f = e[kase];
      e[kase] = 0.0;
      while (q + 1 <= i) {
        ztest = s[q];
        calibrazione0_eml_xrotg(&ztest, &f, &ztest_0, &b);
        s[q] = ztest;
        f = -b * e[q];
        e[q] *= ztest_0;
        calibrazione0_eml_xrot(U, 1 + 10 * q, 1 + 10 * kase, ztest_0, b);
        q++;
      }
      break;

     case 3:
      kase = i - 2;
      tmp[0] = fabs(s[i - 1]);
      tmp[1] = fabs(s[kase]);
      tmp[2] = fabs(e[kase]);
      tmp[3] = fabs(s[q]);
      tmp[4] = fabs(e[q]);
      scale = calibrazione0_max(tmp);
      sm = s[i - 1] / scale;
      ztest = s[kase] / scale;
      ztest_0 = e[kase] / scale;
      sqds = s[q] / scale;
      b = ((ztest + sm) * (ztest - sm) + ztest_0 * ztest_0) / 2.0;
      ztest = sm * ztest_0;
      ztest *= ztest;
      ztest_0 = 0.0;
      if ((b != 0.0) || (ztest != 0.0)) {
        ztest_0 = sqrt(b * b + ztest);
        if (b < 0.0) {
          ztest_0 = -ztest_0;
        }

        ztest_0 = ztest / (b + ztest_0);
      }

      f = (sqds + sm) * (sqds - sm) + ztest_0;
      ztest = e[q] / scale * sqds;
      for (km1 = q; km1 + 1 <= kase + 1; km1++) {
        qs = km1 + 1;
        calibrazione0_eml_xrotg(&f, &ztest, &sm, &scale);
        if (km1 + 1 > q + 1) {
          e[km1 - 1] = f;
        }

        ztest = sm * s[km1];
        ztest_0 = scale * e[km1];
        e[km1] = sm * e[km1] - scale * s[km1];
        b = s[qs];
        s[qs] *= sm;
        calibrazione0_eml_xrot(V, 1 + 10 * km1, 1 + 10 * (km1 + 1), sm, scale);
        ztest_0 += ztest;
        ztest = scale * b;
        calibrazione0_eml_xrotg(&ztest_0, &ztest, &b, &sm);
        s[km1] = ztest_0;
        f = b * e[km1] + sm * s[qs];
        s[qs] = -sm * e[km1] + b * s[qs];
        ztest = sm * e[qs];
        e[qs] *= b;
        calibrazione0_eml_xrot(U, 1 + 10 * km1, 1 + 10 * (km1 + 1), b, sm);
      }

      e[i - 2] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        calibrazione0_eml_xscal(10, -1.0, V, 1 + 10 * q);
      }

      qp = q + 1;
      while ((q + 1 < 10) && (s[q] < s[qp])) {
        ztest_0 = s[q];
        s[q] = s[qp];
        s[qp] = ztest_0;
        calibrazione0_eml_xswap(V, 1 + 10 * q, 1 + 10 * (q + 1));
        calibrazione0_eml_xswap(U, 1 + 10 * q, 1 + 10 * (q + 1));
        q = qp;
        qp++;
      }

      iter = 0;
      i--;
      break;
    }
  }

  memcpy((void *)&S[0], (void *)&s[0], 10U * sizeof(real_T));
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_svd(const real_T A[100], real_T U[100], real_T S[100],
  real_T V[100])
{
  real_T s[10];
  int32_T k;
  calibrazione0_eml_xgesvd(A, U, s, V);
  for (k = 0; k < 100; k++) {
    S[k] = 0.0;
  }

  for (k = 0; k < 10; k++) {
    S[k + 10 * k] = s[k];
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_inv(const real_T x[9], real_T y[9])
{
  real_T b_x[9];
  int32_T p;
  int32_T p_0;
  int32_T p_1;
  real_T absx;
  real_T absx_0;
  real_T absx_1;
  int32_T itmp;
  memcpy((void *)&b_x[0], (void *)&x[0], 9U * sizeof(real_T));
  p = 0;
  p_0 = 3;
  p_1 = 6;
  absx = fabs(x[0]);
  absx_0 = fabs(x[1]);
  absx_1 = fabs(x[2]);
  if ((absx_0 > absx) && (absx_0 > absx_1)) {
    p = 3;
    p_0 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    absx = b_x[3];
    b_x[3] = b_x[4];
    b_x[4] = absx;
    absx = b_x[6];
    b_x[6] = b_x[7];
    b_x[7] = absx;
  } else {
    if (absx_1 > absx) {
      p = 6;
      p_1 = 0;
      b_x[0] = x[2];
      b_x[2] = x[0];
      absx = b_x[3];
      b_x[3] = b_x[5];
      b_x[5] = absx;
      absx = b_x[6];
      b_x[6] = b_x[8];
      b_x[8] = absx;
    }
  }

  b_x[1] /= b_x[0];
  b_x[2] /= b_x[0];
  b_x[4] -= b_x[1] * b_x[3];
  b_x[5] -= b_x[2] * b_x[3];
  b_x[7] -= b_x[1] * b_x[6];
  b_x[8] -= b_x[2] * b_x[6];
  if (fabs(b_x[5]) > fabs(b_x[4])) {
    itmp = p_0;
    p_0 = p_1;
    p_1 = itmp;
    absx = b_x[1];
    b_x[1] = b_x[2];
    b_x[2] = absx;
    absx = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx;
    absx = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx;
  }

  b_x[5] /= b_x[4];
  b_x[8] -= b_x[5] * b_x[7];
  absx = (b_x[5] * b_x[1] - b_x[2]) / b_x[8];
  absx_0 = -(b_x[7] * absx + b_x[1]) / b_x[4];
  y[p] = ((1.0 - b_x[3] * absx_0) - b_x[6] * absx) / b_x[0];
  y[p + 1] = absx_0;
  y[p + 2] = absx;
  absx = -b_x[5] / b_x[8];
  absx_0 = (1.0 - b_x[7] * absx) / b_x[4];
  y[p_0] = -(b_x[3] * absx_0 + b_x[6] * absx) / b_x[0];
  y[p_0 + 1] = absx_0;
  y[p_0 + 2] = absx;
  absx = 1.0 / b_x[8];
  absx_0 = -b_x[7] * absx / b_x[4];
  y[p_1] = -(b_x[3] * absx_0 + b_x[6] * absx) / b_x[0];
  y[p_1 + 1] = absx_0;
  y[p_1 + 2] = absx;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static real_T calibrazione0_eml_xnrm2_dq(int32_T n, const real_T x[9], int32_T
  ix0)
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 0.0;
      firstNonZero = TRUE;
      kend = (ix0 + n) - 1;
      for (k = ix0 - 1; k + 1 <= kend; k++) {
        if (x[k] != 0.0) {
          absxk = fabs(x[k]);
          if (firstNonZero) {
            scale = absxk;
            y = 1.0;
            firstNonZero = FALSE;
          } else if (scale < absxk) {
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xscal_dq(int32_T n, real_T a, real_T x[9], int32_T
  ix0)
{
  int32_T k;
  int32_T loop_ub;
  loop_ub = (ix0 + n) - 1;
  for (k = ix0; k <= loop_ub; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static real_T calibrazione0_eml_xnrm2_dqu(int32_T n, const real_T x[3], int32_T
  ix0)
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (!(n < 1)) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      scale = 0.0;
      firstNonZero = TRUE;
      kend = (ix0 + n) - 1;
      for (k = ix0 - 1; k + 1 <= kend; k++) {
        if (x[k] != 0.0) {
          absxk = fabs(x[k]);
          if (firstNonZero) {
            scale = absxk;
            y = 1.0;
            firstNonZero = FALSE;
          } else if (scale < absxk) {
            t = scale / absxk;
            y = y * t * t + 1.0;
            scale = absxk;
          } else {
            t = absxk / scale;
            y += t * t;
          }
        }
      }

      y = scale * sqrt(y);
    }
  }

  return y;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xscal_dqu(int32_T n, real_T a, real_T x[3],
  int32_T ix0)
{
  int32_T k;
  int32_T loop_ub;
  loop_ub = (ix0 + n) - 1;
  for (k = ix0; k <= loop_ub; k++) {
    x[k - 1] *= a;
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xswap_d(real_T x[9], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xrot_d(real_T x[9], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T y;
  real_T b_y;
  ix = ix0 - 1;
  iy = iy0 - 1;
  y = c * x[ix];
  b_y = s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = y + b_y;
  iy++;
  ix++;
  y = c * x[ix];
  b_y = s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = y + b_y;
  iy++;
  ix++;
  y = c * x[ix];
  b_y = s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = y + b_y;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static real_T calibrazione0_eml_xdotc_d(int32_T n, const real_T x[9], int32_T
  ix0, const real_T y[9], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (!(n < 1)) {
    ix = ix0;
    iy = iy0;
    for (k = 1; k <= n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xaxpy_dqu(int32_T n, real_T a, int32_T ix0, real_T
  y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k <= n - 1; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xaxpy_dquua(int32_T n, real_T a, const real_T x[3],
  int32_T ix0, real_T y[9], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k <= n - 1; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xaxpy_dquu(int32_T n, real_T a, const real_T x[9],
  int32_T ix0, real_T y[3], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if (!((n < 1) || (a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k <= n - 1; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_eml_xgesvd_d(const real_T A[9], real_T U[9], real_T S
  [3], real_T V[9])
{
  real_T b_A[9];
  real_T s[3];
  real_T e[3];
  real_T work[3];
  int32_T q;
  int32_T qp;
  int32_T m;
  int32_T iter;
  real_T snorm;
  real_T ztest;
  int32_T kase;
  int32_T qs;
  real_T ztest_0;
  real_T f;
  int32_T mm;
  real_T scale;
  real_T sm;
  real_T sqds;
  real_T b;
  boolean_T exitg;
  real_T tmp[5];
  s[0] = 0.0;
  s[1] = 0.0;
  s[2] = 0.0;
  e[0] = 0.0;
  e[1] = 0.0;
  e[2] = 0.0;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  for (qp = 0; qp < 9; qp++) {
    b_A[qp] = A[qp];
    U[qp] = 0.0;
    V[qp] = 0.0;
  }

  ztest = calibrazione0_eml_xnrm2_dq(3, b_A, 1);
  if (ztest == 0.0) {
    s[0] = 0.0;
  } else {
    if (b_A[0] < 0.0) {
      ztest = -ztest;
    }

    s[0] = ztest;
    calibrazione0_eml_xscal_dq(3, 1.0 / s[0], b_A, 1);
    b_A[0]++;
    s[0] = -s[0];
  }

  for (qp = 2; qp < 4; qp++) {
    qs = (qp - 1) * 3 + 1;
    if (s[0] != 0.0) {
      calibrazione0_eml_xaxpy_dqu(3, -(calibrazione0_eml_xdotc_d(3, b_A, 1, b_A,
        qs) / b_A[0]), 1, b_A, qs);
    }

    e[qp - 1] = b_A[qs - 1];
  }

  for (kase = 0; kase + 1 < 4; kase++) {
    U[kase] = b_A[kase];
  }

  ztest = calibrazione0_eml_xnrm2_dqu(2, e, 2);
  if (ztest == 0.0) {
    e[0] = 0.0;
  } else {
    if (e[1] < 0.0) {
      ztest = -ztest;
    }

    e[0] = ztest;
    calibrazione0_eml_xscal_dqu(2, 1.0 / e[0], e, 2);
    e[1]++;
  }

  e[0] = -e[0];
  if (e[0] != 0.0) {
    for (kase = 2; kase < 4; kase++) {
      work[kase - 1] = 0.0;
    }

    for (kase = 2; kase < 4; kase++) {
      calibrazione0_eml_xaxpy_dquu(2, e[kase - 1], b_A, 2 + 3 * (kase - 1), work,
        2);
    }

    for (kase = 2; kase < 4; kase++) {
      calibrazione0_eml_xaxpy_dquua(2, -e[kase - 1] / e[1], work, 2, b_A, 2 + 3 *
                                    (kase - 1));
    }
  }

  for (kase = 2; kase < 4; kase++) {
    V[kase - 1] = e[kase - 1];
  }

  ztest = calibrazione0_eml_xnrm2_dq(2, b_A, 5);
  if (ztest == 0.0) {
    s[1] = 0.0;
  } else {
    if (b_A[4] < 0.0) {
      ztest = -ztest;
    }

    s[1] = ztest;
    calibrazione0_eml_xscal_dq(2, 1.0 / s[1], b_A, 5);
    b_A[4]++;
    s[1] = -s[1];
  }

  qp = 3;
  while (qp < 4) {
    if (s[1] != 0.0) {
      calibrazione0_eml_xaxpy_dqu(2, -(calibrazione0_eml_xdotc_d(2, b_A, 5, b_A,
        8) / b_A[4]), 5, b_A, 8);
    }

    e[2] = b_A[7];
    qp = 4;
  }

  for (kase = 1; kase + 1 < 4; kase++) {
    U[kase + 3] = b_A[kase + 3];
  }

  m = 3;
  s[2] = b_A[8];
  e[1] = b_A[7];
  e[2] = 0.0;
  U[6] = 0.0;
  U[7] = 0.0;
  U[8] = 0.0;
  U[8] = 1.0;
  for (mm = 1; mm >= 0; mm += -1) {
    kase = 3 - mm;
    q = 3 * mm + mm;
    if (s[mm] != 0.0) {
      for (qp = mm + 1; qp + 1 < 4; qp++) {
        qs = (3 * qp + mm) + 1;
        calibrazione0_eml_xaxpy_dqu(kase, -(calibrazione0_eml_xdotc_d(kase, U, q
          + 1, U, qs) / U[q]), q + 1, U, qs);
      }

      for (kase = mm; kase + 1 < 4; kase++) {
        U[kase + 3 * mm] = -U[3 * mm + kase];
      }

      U[q]++;
      kase = 1;
      while (kase <= mm) {
        U[3] = 0.0;
        kase = 2;
      }
    } else {
      U[3 * mm] = 0.0;
      U[1 + 3 * mm] = 0.0;
      U[2 + 3 * mm] = 0.0;
      U[q] = 1.0;
    }
  }

  for (qp = 2; qp >= 0; qp += -1) {
    if ((qp + 1 <= 1) && (e[0] != 0.0)) {
      for (kase = 2; kase < 4; kase++) {
        mm = (kase - 1) * 3 + 2;
        calibrazione0_eml_xaxpy_dqu(2, -(calibrazione0_eml_xdotc_d(2, V, 2, V,
          mm) / V[1]), 2, V, mm);
      }
    }

    V[3 * qp] = 0.0;
    V[1 + 3 * qp] = 0.0;
    V[2 + 3 * qp] = 0.0;
    V[qp + 3 * qp] = 1.0;
  }

  f = e[0];
  if (s[0] != 0.0) {
    ztest_0 = fabs(s[0]);
    ztest = s[0] / ztest_0;
    s[0] = ztest_0;
    f = e[0] / ztest;
    calibrazione0_eml_xscal_dq(3, ztest, U, 1);
  }

  if (f != 0.0) {
    ztest_0 = fabs(f);
    ztest = ztest_0 / f;
    f = ztest_0;
    s[1] *= ztest;
    calibrazione0_eml_xscal_dq(3, ztest, V, 4);
  }

  e[0] = f;
  f = e[1];
  if (s[1] != 0.0) {
    ztest_0 = fabs(s[1]);
    ztest = s[1] / ztest_0;
    s[1] = ztest_0;
    f = e[1] / ztest;
    calibrazione0_eml_xscal_dq(3, ztest, U, 4);
  }

  if (f != 0.0) {
    ztest_0 = fabs(f);
    ztest = ztest_0 / f;
    f = ztest_0;
    s[2] *= ztest;
    calibrazione0_eml_xscal_dq(3, ztest, V, 7);
  }

  e[1] = f;
  if (s[2] != 0.0) {
    ztest_0 = fabs(s[2]);
    ztest = s[2] / ztest_0;
    s[2] = ztest_0;
    calibrazione0_eml_xscal_dq(3, ztest, U, 7);
  }

  e[2] = 0.0;
  iter = 0;
  f = (s[0] >= e[0]) || rtIsNaN(e[0]) ? s[0] : e[0];
  snorm = (0.0 >= f) || rtIsNaN(f) ? 0.0 : f;
  f = (s[1] >= e[1]) || rtIsNaN(e[1]) ? s[1] : e[1];
  snorm = (snorm >= f) || rtIsNaN(f) ? snorm : f;
  snorm = (snorm >= s[2]) || rtIsNaN(s[2]) ? snorm : s[2];
  while ((m > 0) && (!(iter >= 75))) {
    qp = m - 1;
    do {
      kase = 0;
      q = qp;
      if (qp == 0) {
        kase = 1;
      } else {
        ztest = fabs(e[qp - 1]);
        if ((ztest <= (fabs(s[qp - 1]) + fabs(s[qp])) * 2.2204460492503131E-16) ||
            (ztest <= 1.0020841800044864E-292) || ((iter > 20) && (ztest <=
              2.2204460492503131E-16 * snorm))) {
          e[qp - 1] = 0.0;
          kase = 1;
        } else {
          qp--;
        }
      }
    } while ((uint32_T)kase == 0U);

    if (m - 1 == qp) {
      kase = 4;
    } else {
      qs = m;
      mm = m;
      exitg = FALSE;
      while (((uint32_T)exitg == 0U) && (mm >= qp)) {
        qs = mm;
        if (mm == qp) {
          exitg = TRUE;
        } else {
          ztest = 0.0;
          if (mm < m) {
            ztest = fabs(e[mm - 1]);
          }

          if (mm > qp + 1) {
            ztest += fabs(e[mm - 2]);
          }

          ztest_0 = fabs(s[mm - 1]);
          if ((ztest_0 <= 2.2204460492503131E-16 * ztest) || (ztest_0 <=
               1.0020841800044864E-292)) {
            s[mm - 1] = 0.0;
            exitg = TRUE;
          } else {
            mm--;
          }
        }
      }

      if (qs == qp) {
        kase = 3;
      } else if (qs == m) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      f = e[m - 2];
      e[m - 2] = 0.0;
      for (kase = m - 2; kase + 1 >= q + 1; kase--) {
        ztest = s[kase];
        calibrazione0_eml_xrotg(&ztest, &f, &ztest_0, &b);
        s[kase] = ztest;
        if (kase + 1 > q + 1) {
          f = -b * e[0];
          e[0] *= ztest_0;
        }

        calibrazione0_eml_xrot_d(V, 1 + 3 * kase, 1 + 3 * (m - 1), ztest_0, b);
      }
      break;

     case 2:
      kase = q - 1;
      f = e[kase];
      e[kase] = 0.0;
      while (q + 1 <= m) {
        ztest = s[q];
        calibrazione0_eml_xrotg(&ztest, &f, &ztest_0, &b);
        s[q] = ztest;
        f = -b * e[q];
        e[q] *= ztest_0;
        calibrazione0_eml_xrot_d(U, 1 + 3 * q, 1 + 3 * kase, ztest_0, b);
        q++;
      }
      break;

     case 3:
      mm = m - 2;
      tmp[0] = fabs(s[m - 1]);
      tmp[1] = fabs(s[mm]);
      tmp[2] = fabs(e[mm]);
      tmp[3] = fabs(s[q]);
      tmp[4] = fabs(e[q]);
      scale = calibrazione0_max(tmp);
      sm = s[m - 1] / scale;
      ztest = s[mm] / scale;
      ztest_0 = e[mm] / scale;
      sqds = s[q] / scale;
      b = ((ztest + sm) * (ztest - sm) + ztest_0 * ztest_0) / 2.0;
      ztest = sm * ztest_0;
      ztest *= ztest;
      ztest_0 = 0.0;
      if ((b != 0.0) || (ztest != 0.0)) {
        ztest_0 = sqrt(b * b + ztest);
        if (b < 0.0) {
          ztest_0 = -ztest_0;
        }

        ztest_0 = ztest / (b + ztest_0);
      }

      f = (sqds + sm) * (sqds - sm) + ztest_0;
      ztest = e[q] / scale * sqds;
      for (qp = q; qp + 1 <= mm + 1; qp++) {
        kase = qp + 1;
        calibrazione0_eml_xrotg(&f, &ztest, &sm, &scale);
        if (qp + 1 > q + 1) {
          e[0] = f;
        }

        ztest = sm * s[qp];
        ztest_0 = scale * e[qp];
        e[qp] = sm * e[qp] - scale * s[qp];
        b = s[kase];
        s[kase] *= sm;
        calibrazione0_eml_xrot_d(V, 1 + 3 * qp, 1 + 3 * (qp + 1), sm, scale);
        ztest_0 += ztest;
        ztest = scale * b;
        calibrazione0_eml_xrotg(&ztest_0, &ztest, &b, &sm);
        s[qp] = ztest_0;
        f = b * e[qp] + sm * s[kase];
        s[kase] = -sm * e[qp] + b * s[kase];
        ztest = sm * e[kase];
        e[kase] *= b;
        calibrazione0_eml_xrot_d(U, 1 + 3 * qp, 1 + 3 * (qp + 1), b, sm);
      }

      e[m - 2] = f;
      iter++;
      break;

     default:
      if (s[q] < 0.0) {
        s[q] = -s[q];
        calibrazione0_eml_xscal_dq(3, -1.0, V, 1 + 3 * q);
      }

      qp = q + 1;
      while ((q + 1 < 3) && (s[q] < s[qp])) {
        ztest_0 = s[q];
        s[q] = s[qp];
        s[qp] = ztest_0;
        calibrazione0_eml_xswap_d(V, 1 + 3 * q, 1 + 3 * (q + 1));
        calibrazione0_eml_xswap_d(U, 1 + 3 * q, 1 + 3 * (q + 1));
        q = qp;
        qp++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  S[0] = s[0];
  S[1] = s[1];
  S[2] = s[2];
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_svd_d(const real_T A[9], real_T U[9], real_T S[9],
  real_T V[9])
{
  real_T s[3];
  int32_T i;
  calibrazione0_eml_xgesvd_d(A, U, s, V);
  for (i = 0; i < 9; i++) {
    S[i] = 0.0;
  }

  S[0] = s[0];
  S[4] = s[1];
  S[8] = s[2];
}

/* Function for MATLAB Function Block: '<S1>/calibration-mag' */
static void calibrazione0_sqrt(real_T x[9])
{
  int32_T k;
  for (k = 0; k < 9; k++) {
    x[k] = sqrt(x[k]);
  }
}

/* Model step function */
void calibrazione0_step(void)
{
  real_T H[400];
  real_T h;
  real_T gsi[10];
  real_T K[100];
  real_T P[100];
  real_T L[100];
  real_T U[9];
  real_T A[9];
  real_T V[9];
  real_T rtb_b[3];
  real_T rtb_Sum;
  real_T rtb_UnitConversion;
  boolean_T rtb_RelationalOperator;
  real_T rtb_u80deg;
  real_T rtb_u0deg;
  real_T rtb_Gain;
  boolean_T rtb_LogicalOperator;
  real_T rtb_Product1;
  int32_T s13_iter;
  real_T rtb_Sum_o;
  int32_T s62_iter;
  real_T rtb_b2;
  real_T rtb_a2;
  real_T rtb_q;
  real_T rtb_Sum1_mz;
  real_T rtb_d;
  real_T rtb_Sum4;
  int32_T s21_iter;
  real_T rtb_TmpSignalConversionAtspm1In[13];
  int32_T rtb_Sum2_n;
  real_T rtb_G[9];
  real_T rtb_tc_old[169];
  real_T Assignment_e[169];
  real_T Assignment[169];
  int32_T i;
  real_T K_0[9];
  real_T H_0[100];
  real_T tmp[13];
  real_T rtb_sincos_o1_h_idx;
  real_T rtb_sincos_o1_h_idx_0;
  real_T rtb_sincos_o1_idx;
  real_T rtb_sincos_o2_idx;
  real_T rtb_Sum1_m_idx;
  real_T rtb_Sum1_m_idx_0;
  real_T rtb_Sum1_m_idx_1;
  real_T rtb_Sum1_m_idx_2;
  int32_T qY;
  int32_T qY_0;
  int32_T qY_1;
  int32_T qY_2;
  int32_T qY_3;
  int32_T qY_4;

  /* MATLAB Function Block: '<S1>/calibration-mag' incorporates:
   *  Inport: '<Root>/mag_x'
   *  Inport: '<Root>/mag_y'
   *  Inport: '<Root>/mag_z'
   *  Inport: '<Root>/w'
   */

  /* MATLAB Function 'calibrazione _magnetometro/calibration-mag': '<S3>:1' */
  /* H=[]; */
  /* '<S3>:1:5' */
  for (qY_3 = 0; qY_3 < 400; qY_3++) {
    H[qY_3] = 0.0;
  }

  /* '<S3>:1:8' */
  for (i = 0; i < 9; i++) {
    rtb_G[i] = 0.0;
  }

  /* f=[0:1000:1]; */
  /* j=[0:1000:1]; */
  /* k=[0:1000:1]; */
  /* B=[]; */
  /* G=[]; */
  /* Hb=[]; */
  /* '<S3>:1:15' */
  h = calibrazione0_U.w[0];

  /* '<S3>:1:19' */
  for (s62_iter = 0; s62_iter < 10; s62_iter++) {
    /* '<S3>:1:19' */
    /* per far si che H abbia almeno 10 elemnti così m>n */
    /* '<S3>:1:20' */
    H[s62_iter] = rt_powd_snf(calibrazione0_U.mag_x[s62_iter], 2.0);

    /* '<S3>:1:21' */
    H[40 + s62_iter] = 2.0 * calibrazione0_U.mag_x[s62_iter] *
      calibrazione0_U.mag_y[s62_iter];

    /* '<S3>:1:22' */
    H[80 + s62_iter] = 2.0 * calibrazione0_U.mag_x[s62_iter] *
      calibrazione0_U.mag_z[s62_iter];

    /* '<S3>:1:23' */
    H[120 + s62_iter] = rt_powd_snf(calibrazione0_U.mag_y[s62_iter], 2.0);

    /* '<S3>:1:24' */
    H[160 + s62_iter] = 2.0 * calibrazione0_U.mag_y[s62_iter] *
      calibrazione0_U.mag_z[s62_iter];

    /* '<S3>:1:25' */
    H[200 + s62_iter] = rt_powd_snf(calibrazione0_U.mag_z[s62_iter], 2.0);

    /* '<S3>:1:26' */
    H[240 + s62_iter] = calibrazione0_U.mag_x[s62_iter];

    /* '<S3>:1:27' */
    H[280 + s62_iter] = calibrazione0_U.mag_y[s62_iter];

    /* '<S3>:1:28' */
    H[320 + s62_iter] = calibrazione0_U.mag_z[s62_iter];

    /* '<S3>:1:29' */
    H[360 + s62_iter] = 1.0;

    /* '<S3>:1:19' */
  }

  /* for i=11:1:length(magx)-1 %ora inizia l'algoritmo */
  /* '<S3>:1:35' */
  for (s62_iter = 0; s62_iter < 29; s62_iter++) {
    /* '<S3>:1:35' */
    /* ora inizia l'algoritmo */
    /* '<S3>:1:37' */
    H[s62_iter + 10] = rt_powd_snf(calibrazione0_U.mag_x[s62_iter + 10], 2.0);

    /* '<S3>:1:38' */
    H[s62_iter + 50] = calibrazione0_U.mag_x[s62_iter + 10] * 2.0 *
      calibrazione0_U.mag_y[s62_iter + 10];

    /* '<S3>:1:39' */
    H[s62_iter + 90] = calibrazione0_U.mag_x[s62_iter + 10] * 2.0 *
      calibrazione0_U.mag_z[s62_iter + 10];

    /* '<S3>:1:40' */
    H[s62_iter + 130] = rt_powd_snf(calibrazione0_U.mag_y[s62_iter + 10], 2.0);

    /* '<S3>:1:41' */
    H[s62_iter + 170] = calibrazione0_U.mag_y[s62_iter + 10] * 2.0 *
      calibrazione0_U.mag_z[s62_iter + 10];

    /* '<S3>:1:42' */
    H[s62_iter + 210] = rt_powd_snf(calibrazione0_U.mag_z[s62_iter + 10], 2.0);

    /* '<S3>:1:43' */
    H[s62_iter + 250] = calibrazione0_U.mag_x[s62_iter + 10];

    /* '<S3>:1:44' */
    H[s62_iter + 290] = calibrazione0_U.mag_y[s62_iter + 10];

    /* '<S3>:1:45' */
    H[s62_iter + 330] = calibrazione0_U.mag_z[s62_iter + 10];

    /* '<S3>:1:46' */
    H[s62_iter + 370] = 1.0;

    /* '<S3>:1:47' */
    /*  uso la notazione dell'articolo e creo HH */
    for (qY_3 = 0; qY_3 < 10; qY_3++) {
      for (i = 0; i < 10; i++) {
        H_0[qY_3 + 10 * i] = 0.0;
        for (rtb_Sum2_n = 0; rtb_Sum2_n < 40; rtb_Sum2_n++) {
          H_0[qY_3 + 10 * i] = H[40 * qY_3 + rtb_Sum2_n] * H[40 * i + rtb_Sum2_n]
            + H_0[10 * i + qY_3];
        }
      }
    }

    calibrazione0_svd(H_0, K, P, L);

    /* HH è una matrice quadrata da cui k è uguale a L */
    /* '<S3>:1:49' */
    /*  mi fido dell'articolo e prendo la decima colonna che in effetti è relativa al 10° valore singolare che è il + piccolo */
    /* '<S3>:1:50' */
    /* '<S3>:1:51' */
    /* '<S3>:1:52' */
    /* '<S3>:1:53' */
    /* '<S3>:1:54' */
    /* '<S3>:1:55' */
    /* '<S3>:1:56' */
    /* '<S3>:1:57' */
    /* '<S3>:1:58' */
    /* '<S3>:1:59' */
    /* '<S3>:1:60' */
    /* '<S3>:1:61' */
    K_0[0] = K[90];
    K_0[3] = K[91];
    K_0[6] = K[92];
    K_0[1] = K[91];
    K_0[4] = K[93];
    K_0[7] = K[94];
    K_0[2] = K[92];
    K_0[5] = K[94];
    K_0[8] = K[95];
    calibrazione0_inv(K_0, U);
    for (qY_3 = 0; qY_3 < 3; qY_3++) {
      rtb_b[qY_3] = U[qY_3 + 6] * -0.5 * K[98] + (U[qY_3 + 3] * -0.5 * K[97] +
        -0.5 * U[qY_3] * K[96]);
    }

    /* '<S3>:1:62' */
    /* '<S3>:1:63' */
    /* '<S3>:1:64' */
    /* creo B per notare una convergenza */
    /* '<S3>:1:68' */
    rtb_Product1 = rt_powd_snf((((((2.0 * K[91] * rtb_b[0] * rtb_b[1] + K[90] *
      rt_powd_snf(rtb_b[0], 2.0)) + 2.0 * K[92] * rtb_b[0] * rtb_b[2]) + K[93] *
      rt_powd_snf(rtb_b[1], 2.0)) + 2.0 * K[94] * rtb_b[1] * rtb_b[2]) + 2.0 *
      K[95] * rt_powd_snf(rtb_b[2], 2.0)) - K[99], -1.0) * (h * h);

    /*  credo di poter elevare alla -1 tanto è uno scalare */
    /* '<S3>:1:69' */
    for (qY_3 = 0; qY_3 < 10; qY_3++) {
      gsi[qY_3] = K[90 + qY_3] * rtb_Product1;
    }

    /* '<S3>:1:70' */
    /* '<S3>:1:71' */
    /* '<S3>:1:72' */
    /* '<S3>:1:73' */
    /* '<S3>:1:74' */
    /* '<S3>:1:75' */
    /* '<S3>:1:80' */
    K_0[0] = gsi[0];
    K_0[3] = gsi[1];
    K_0[6] = gsi[2];
    K_0[1] = gsi[1];
    K_0[4] = gsi[3];
    K_0[7] = gsi[4];
    K_0[2] = gsi[2];
    K_0[5] = gsi[4];
    K_0[8] = gsi[5];
    calibrazione0_svd_d(K_0, U, A, V);

    /* per come è costruita gamma è quadrata e simmetrica da cui U è uguale a V */
    /* '<S3>:1:82' */
    calibrazione0_sqrt(A);
    for (qY_3 = 0; qY_3 < 3; qY_3++) {
      for (i = 0; i < 3; i++) {
        K_0[qY_3 + 3 * i] = 0.0;
        K_0[qY_3 + 3 * i] = K_0[3 * i + qY_3] + A[3 * i] * V[qY_3];
        K_0[qY_3 + 3 * i] = A[3 * i + 1] * V[qY_3 + 3] + K_0[3 * i + qY_3];
        K_0[qY_3 + 3 * i] = A[3 * i + 2] * V[qY_3 + 6] + K_0[3 * i + qY_3];
      }
    }

    for (qY_3 = 0; qY_3 < 3; qY_3++) {
      for (i = 0; i < 3; i++) {
        rtb_G[qY_3 + 3 * i] = 0.0;
        rtb_G[qY_3 + 3 * i] = rtb_G[3 * i + qY_3] + K_0[qY_3] * V[i];
        rtb_G[qY_3 + 3 * i] = rtb_G[3 * i + qY_3] + K_0[qY_3 + 3] * V[i + 3];
        rtb_G[qY_3 + 3 * i] = rtb_G[3 * i + qY_3] + K_0[qY_3 + 6] * V[i + 6];
      }
    }

    /* '<S3>:1:83' */
    rtb_Sum1_mz = rtb_b[2];
    rtb_b[2] = rtb_Sum1_mz;

    /* f(i)=norm(hm); %norma del vettore misurato */
    /* j(i)=norm(hb); %norma del vettore calibrato */
    /* k(i)=norm(h);  %norma del vettore reale */
    /* '<S3>:1:35' */
  }

  /* End of MATLAB Function Block: '<S1>/calibration-mag' */

  /* Outport: '<Root>/G' */
  memcpy((void *)&calibrazione0_Y.G[0], (void *)&rtb_G[0], 9U * sizeof(real_T));

  /* Outport: '<Root>/b' */
  calibrazione0_Y.b[0] = rtb_b[0];
  calibrazione0_Y.b[1] = rtb_b[1];
  calibrazione0_Y.b[2] = rtb_b[2];

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S2>/Date'
   *  Gain: '<S2>/DayToYear'
   *  Gain: '<S2>/MonthToYear'
   */
  rtb_Sum = (calibrazione0_P.DayToYear_Gain * calibrazione0_P.Date_Value[0] +
             calibrazione0_P.MonthToYear_Gain * calibrazione0_P.Date_Value[1]) +
    calibrazione0_P.Date_Value[2];

  /* Sum: '<S11>/Sum' incorporates:
   *  Constant: '<S11>/epoch'
   */
  rtb_Sum_o = rtb_Sum - calibrazione0_P.epoch_Value;

  /* RelationalOperator: '<S19>/Relational Operator' incorporates:
   *  Memory: '<S19>/otime'
   */
  rtb_RelationalOperator = (rtb_Sum != calibrazione0_DWork.otime_PreviousInput);

  /* Saturate: '<S4>/+//- 180 deg' incorporates:
   *  Inport: '<Root>/posizione'
   */
  rtb_u80deg = calibrazione0_U.posizione[1] >= calibrazione0_P.u80deg_UpperSat ?
    calibrazione0_P.u80deg_UpperSat : calibrazione0_U.posizione[1] <=
    calibrazione0_P.u80deg_LowerSat ? calibrazione0_P.u80deg_LowerSat :
    calibrazione0_U.posizione[1];

  /* Saturate: '<S4>/+//- 90 deg' incorporates:
   *  Inport: '<Root>/posizione'
   */
  rtb_u0deg = calibrazione0_U.posizione[0] >= calibrazione0_P.u0deg_UpperSat ?
    calibrazione0_P.u0deg_UpperSat : calibrazione0_U.posizione[0] <=
    calibrazione0_P.u0deg_LowerSat ? calibrazione0_P.u0deg_LowerSat :
    calibrazione0_U.posizione[0];

  /* Gain: '<S63>/Unit Conversion' */
  rtb_sincos_o1_h_idx = calibrazione0_P.UnitConversion_Gain * rtb_u80deg;
  rtb_sincos_o1_h_idx_0 = calibrazione0_P.UnitConversion_Gain * rtb_u0deg;

  /* Trigonometry: '<S16>/sincos' */
  rtb_sincos_o1_idx = sin(rtb_sincos_o1_h_idx_0);
  rtb_sincos_o2_idx = cos(rtb_sincos_o1_h_idx_0);

  /* Outputs for Enabled SubSystem: '<S11>/Convert from geodetic to  spherical coordinates ' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* RelationalOperator: '<S18>/Relational Operator' incorporates:
   *  Constant: '<S15>/cp[1]'
   *  Constant: '<S15>/sp[1]'
   *  Inport: '<S15>/cp[2]'
   *  Inport: '<S15>/sp[2]'
   *  Memory: '<S18>/olon'
   *  Trigonometry: '<S16>/sincos'
   */
  if (rtb_u80deg != calibrazione0_DWork.olon_PreviousInput) {
    calibrazione0_B.sp2 = sin(rtb_sincos_o1_h_idx);
    calibrazione0_B.cp2 = cos(rtb_sincos_o1_h_idx);

    /* Outputs for Iterator SubSystem: '<S15>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S62>/For Iterator'
     */
    for (s62_iter = 1; (real_T)s62_iter <=
         calibrazione0_P.ForIterator_IterationLimit; s62_iter++) {
      h = (real_T)s62_iter;

      /* UnitDelay: '<S62>/Unit Delay1' */
      rtb_Sum1_mz = calibrazione0_DWork.UnitDelay1_DSTATE[0];
      rtb_d = calibrazione0_DWork.UnitDelay1_DSTATE[1];

      /* Switch: '<S62>/cp[m-1] sp[m-1]' */
      if (!(h > calibrazione0_P.cpm1spm1_Threshold)) {
        rtb_Sum1_mz = calibrazione0_B.cp2;
        rtb_d = calibrazione0_B.sp2;
      }

      /* End of Switch: '<S62>/cp[m-1] sp[m-1]' */

      /* Sum: '<S62>/Sum2' incorporates:
       *  Product: '<S62>/Product1'
       *  Product: '<S62>/Product2'
       */
      rtb_Product1 = rtb_Sum1_mz * calibrazione0_B.sp2 + rtb_d *
        calibrazione0_B.cp2;
      for (i = 0; i < 11; i++) {
        /* Assignment: '<S62>/Assignment' incorporates:
         *  Constant: '<S62>/Constant'
         */
        if (s62_iter == 1) {
          calibrazione0_B.Assignment[i] = calibrazione0_P.Constant_Value_k[i];
        }

        /* End of Assignment: '<S62>/Assignment' */

        /* Assignment: '<S62>/Assignment1' incorporates:
         *  Constant: '<S62>/Constant1'
         */
        if (s62_iter == 1) {
          calibrazione0_B.Assignment1[i] = calibrazione0_P.Constant1_Value_p[i];
        }

        /* End of Assignment: '<S62>/Assignment1' */
      }

      /* Assignment: '<S62>/Assignment' */
      calibrazione0_B.Assignment[(int32_T)h - 1] = rtb_Product1;

      /* Sum: '<S62>/Sum1' incorporates:
       *  Product: '<S62>/Product3'
       *  Product: '<S62>/Product8'
       */
      rtb_a2 = rtb_Sum1_mz * calibrazione0_B.cp2 - rtb_d * calibrazione0_B.sp2;

      /* Assignment: '<S62>/Assignment1' */
      calibrazione0_B.Assignment1[(int32_T)h - 1] = rtb_a2;

      /* Update for UnitDelay: '<S62>/Unit Delay1' */
      calibrazione0_DWork.UnitDelay1_DSTATE[0] = rtb_a2;
      calibrazione0_DWork.UnitDelay1_DSTATE[1] = rtb_Product1;
    }

    /* End of Outputs for SubSystem: '<S15>/For Iterator Subsystem' */
    calibrazione0_B.cp1 = calibrazione0_P.cp1_Value;
    calibrazione0_B.sp1 = calibrazione0_P.sp1_Value;
  }

  /* End of RelationalOperator: '<S18>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S11>/Convert from geodetic to  spherical coordinates ' */

  /* Gain: '<S10>/Unit Conversion' incorporates:
   *  Inport: '<Root>/posizione'
   */
  rtb_UnitConversion = calibrazione0_P.UnitConversion_Gain_e *
    calibrazione0_U.posizione[2];

  /* Gain: '<S4>/Gain' incorporates:
   *  Saturate: '<S4>/0 to 1,000,000 m'
   */
  rtb_Gain = (rtb_UnitConversion >= calibrazione0_P.to1000000m_UpperSat ?
              calibrazione0_P.to1000000m_UpperSat : rtb_UnitConversion <=
              calibrazione0_P.to1000000m_LowerSat ?
              calibrazione0_P.to1000000m_LowerSat : rtb_UnitConversion) *
    calibrazione0_P.Gain_Gain_k;

  /* Logic: '<S17>/Logical Operator' incorporates:
   *  Memory: '<S17>/oalt'
   *  Memory: '<S17>/olat'
   *  RelationalOperator: '<S17>/Relational Operator'
   *  RelationalOperator: '<S17>/Relational Operator1'
   */
  rtb_LogicalOperator = ((rtb_u0deg != calibrazione0_DWork.olat_PreviousInput) ||
                         (rtb_Gain != calibrazione0_DWork.oalt_PreviousInput));

  /* Product: '<S16>/Product' */
  h = rtb_sincos_o1_idx * rtb_sincos_o1_idx;

  /* Product: '<S16>/Product1' */
  rtb_Product1 = rtb_sincos_o2_idx * rtb_sincos_o2_idx;

  /* Outputs for Enabled SubSystem: '<S11>/Convert from geodetic to  spherical coordinates' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtb_LogicalOperator) {
    /* Product: '<S14>/b2' incorporates:
     *  Constant: '<S14>/b'
     */
    rtb_b2 = calibrazione0_P.b_Value * calibrazione0_P.b_Value;

    /* Product: '<S14>/a2' incorporates:
     *  Constant: '<S14>/a'
     */
    rtb_a2 = calibrazione0_P.a_Value * calibrazione0_P.a_Value;

    /* Sqrt: '<S57>/sqrt' incorporates:
     *  Product: '<S57>/Product'
     *  Sum: '<S57>/Sum'
     *  Sum: '<S57>/Sum1'
     */
    rtb_q = sqrt(rtb_a2 - (rtb_a2 - rtb_b2) * h);

    /* Product: '<S14>/Product1' */
    rtb_Sum1_mz = rtb_q * rtb_Gain;

    /* Sqrt: '<S56>/sqrt' incorporates:
     *  Product: '<S56>/Product10'
     *  Product: '<S56>/Product9'
     *  Sum: '<S56>/Sum7'
     */
    rtb_d = sqrt(rtb_Product1 * rtb_a2 + rtb_b2 * h);

    /* Product: '<S59>/a4' */
    rtb_Sum4 = rtb_a2 * rtb_a2;

    /* Sqrt: '<S14>/sqrt' incorporates:
     *  Gain: '<S59>/Gain'
     *  Product: '<S59>/Product1'
     *  Product: '<S59>/Product6'
     *  Product: '<S59>/Product7'
     *  Product: '<S59>/Product8'
     *  Product: '<S59>/b4'
     *  Sum: '<S59>/Sum5'
     *  Sum: '<S59>/Sum6'
     *  Sum: '<S59>/Sum9'
     */
    calibrazione0_B.sqrt_g = sqrt((rtb_Sum4 - (rtb_Sum4 - rtb_b2 * rtb_b2) * h) /
                                  (rtb_q * rtb_q) + (calibrazione0_P.Gain_Gain_h
      * rtb_Sum1_mz + rtb_Gain * rtb_Gain));

    /* Product: '<S54>/Product11' incorporates:
     *  Sum: '<S54>/Sum8'
     */
    calibrazione0_B.Product11 = (rtb_Gain + rtb_d) / calibrazione0_B.sqrt_g;

    /* Sum: '<S58>/Sum2' */
    rtb_Sum4 = rtb_a2 + rtb_Sum1_mz;

    /* Sum: '<S58>/Sum1' */
    rtb_Sum1_mz += rtb_b2;

    /* Product: '<S55>/Product4' incorporates:
     *  Product: '<S55>/Product3'
     *  Product: '<S58>/Product1'
     *  Product: '<S58>/Product2'
     *  Sqrt: '<S55>/sqrt'
     *  Sum: '<S55>/Sum3'
     */
    calibrazione0_B.Product4 = rtb_sincos_o1_idx / sqrt(rtb_Sum4 * rtb_Sum4 /
      (rtb_Sum1_mz * rtb_Sum1_mz) * rtb_Product1 + h);

    /* Product: '<S60>/Product12' incorporates:
     *  Product: '<S60>/Product1'
     *  Sum: '<S60>/Sum1'
     */
    calibrazione0_B.Product12 = (rtb_a2 - rtb_b2) / (calibrazione0_B.sqrt_g *
      rtb_d) * rtb_sincos_o2_idx * rtb_sincos_o1_idx;

    /* Sqrt: '<S61>/sqrt' incorporates:
     *  Constant: '<S61>/Constant'
     *  Product: '<S61>/Product5'
     *  Sum: '<S61>/Sum4'
     */
    calibrazione0_B.sqrt_i = sqrt(calibrazione0_P.Constant_Value_h -
      calibrazione0_B.Product4 * calibrazione0_B.Product4);
  }

  /* End of Outputs for SubSystem: '<S11>/Convert from geodetic to  spherical coordinates' */

  /* Product: '<S11>/aor' incorporates:
   *  Constant: '<S11>/re'
   */
  rtb_b2 = calibrazione0_P.re_Value / calibrazione0_B.sqrt_g;

  /* Outputs for Iterator SubSystem: '<S11>/Compute magnetic vector in spherical coordinates' incorporates:
   *  ForIterator: '<S13>/For Iterator'
   */
  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  rtb_q = calibrazione0_P.UnitDelay_X0_e;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay2' */
  rtb_d = calibrazione0_P.UnitDelay2_X0_l[0];
  rtb_Sum4 = calibrazione0_P.UnitDelay2_X0_l[1];
  rtb_sincos_o2_idx = calibrazione0_P.UnitDelay2_X0_l[2];
  rtb_sincos_o1_idx = calibrazione0_P.UnitDelay2_X0_l[3];
  for (s13_iter = 1; s13_iter <= calibrazione0_P.ForIterator_IterationLimit_j;
       s13_iter++) {
    /* Switch: '<S13>/ar(n)' incorporates:
     *  Product: '<S11>/ar'
     */
    if (!(s13_iter > calibrazione0_P.arn_Threshold)) {
      rtb_q = rtb_b2 * rtb_b2;
    }

    /* End of Switch: '<S13>/ar(n)' */

    /* Product: '<S13>/Product8' */
    rtb_q *= rtb_b2;

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S13>/Constant'
     */
    qY = s13_iter + calibrazione0_P.Constant_Value_mw;
    if ((s13_iter < 0) && ((calibrazione0_P.Constant_Value_mw < 0) && (qY >= 0)))
    {
      qY = MIN_int32_T;
    } else {
      if ((s13_iter > 0) && ((calibrazione0_P.Constant_Value_mw > 0) && (qY <= 0)))
      {
        qY = MAX_int32_T;
      }
    }

    /* End of Sum: '<S13>/Sum' */

    /* Outputs for Iterator SubSystem: '<S13>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S21>/For Iterator'
     */
    if (calibrazione0_DWork.ForIterator_IterationMarker[4] != 0) {
      /* InitializeConditions for UnitDelay: '<S22>/Unit Delay1' */
      calibrazione0_DWork.UnitDelay1_DSTATE_d = calibrazione0_P.UnitDelay1_X0_l;

      /* InitializeConditions for UnitDelay: '<S22>/Unit Delay3' */
      calibrazione0_DWork.UnitDelay3_DSTATE = calibrazione0_P.UnitDelay3_X0;

      /* InitializeConditions for UnitDelay: '<S22>/Unit Delay2' */
      calibrazione0_DWork.UnitDelay2_DSTATE_b = calibrazione0_P.UnitDelay2_X0;

      /* InitializeConditions for UnitDelay: '<S22>/Unit Delay4' */
      calibrazione0_DWork.UnitDelay4_DSTATE = calibrazione0_P.UnitDelay4_X0;
    }

    for (i = 0; i < 7; i++) {
      calibrazione0_DWork.ForIterator_IterationMarker[i] = 1U;
    }

    /* Sum: '<S13>/Sum' incorporates:
     *  Constant: '<S28>/Constant'
     *  Constant: '<S28>/Constant1'
     *  Logic: '<S28>/Logical Operator'
     *  RelationalOperator: '<S28>/Relational Operator'
     *  RelationalOperator: '<S28>/Relational Operator1'
     *  Sum: '<S21>/Sum1'
     */
    for (s21_iter = 1; s21_iter <= qY; s21_iter++) {
      /* Sum: '<S21>/Sum1' incorporates:
       *  Constant: '<S21>/Constant'
       */
      qY_4 = s21_iter - calibrazione0_P.Constant_Value_bf;
      if ((s21_iter < 0) && ((calibrazione0_P.Constant_Value_bf >= 0) && (qY_4 >=
            0))) {
        qY_4 = MIN_int32_T;
      } else {
        if ((s21_iter >= 0) && ((calibrazione0_P.Constant_Value_bf < 0) && (qY_4
              < 0))) {
          qY_4 = MAX_int32_T;
        }
      }

      /* End of Sum: '<S21>/Sum1' */

      /* Outputs for Enabled SubSystem: '<S21>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' incorporates:
       *  EnablePort: '<S23>/Enable'
       */
      if (rtb_LogicalOperator) {
        /* Sum: '<S23>/Sum' incorporates:
         *  Constant: '<S23>/Constant'
         *  Sum: '<S21>/Sum1'
         */
        qY_3 = s13_iter + calibrazione0_P.Constant_Value_f;
        if ((s13_iter < 0) && ((calibrazione0_P.Constant_Value_f < 0) && (qY_3 >=
              0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((s13_iter > 0) && ((calibrazione0_P.Constant_Value_f > 0) && (qY_3
                <= 0))) {
            qY_3 = MAX_int32_T;
          }
        }

        qY_2 = qY_4 + calibrazione0_P.Constant_Value_f;
        if ((qY_4 < 0) && ((calibrazione0_P.Constant_Value_f < 0) && (qY_2 >= 0)))
        {
          qY_2 = MIN_int32_T;
        } else {
          if ((qY_4 > 0) && ((calibrazione0_P.Constant_Value_f > 0) && (qY_2 <=
                0))) {
            qY_2 = MAX_int32_T;
          }
        }

        /* End of Sum: '<S23>/Sum' */

        /* If: '<S23>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' incorporates:
         *  Sum: '<S21>/Sum1'
         */
        if (s13_iter == qY_4) {
          /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
           *  ActionPort: '<S37>/Action Port'
           */
          /* Sum: '<S41>/Sum2' incorporates:
           *  Constant: '<S41>/Constant'
           */
          qY_1 = qY_4 - calibrazione0_P.Constant_Value_as;
          if ((qY_4 < 0) && ((calibrazione0_P.Constant_Value_as >= 0) && (qY_1 >=
                0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((qY_4 >= 0) && ((calibrazione0_P.Constant_Value_as < 0) && (qY_1
                  < 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          /* End of Sum: '<S41>/Sum2' */

          /* Gain: '<S41>/Gain' incorporates:
           *  Sum: '<S41>/Sum2'
           */
          s62_iter = mul_s32_s32_s32_sat(calibrazione0_P.Gain_Gain_a, qY_1);

          /* Selector: '<S37>/Selector' incorporates:
           *  Sum: '<S41>/Sum1'
           */
          qY_1 = s13_iter + s62_iter;
          if ((s13_iter < 0) && ((s62_iter < 0) && (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((s13_iter > 0) && ((s62_iter > 0) && (qY_1 <= 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          /* End of Selector: '<S37>/Selector' */

          /* Product: '<S37>/Product1' incorporates:
           *  Selector: '<S37>/Selector'
           *  Sum: '<S41>/Sum1'
           *  UnitDelay: '<S23>/Unit Delay1'
           */
          calibrazione0_B.Merge_j[0] =
            calibrazione0_DWork.UnitDelay1_DSTATE_b[qY_1 - 1] *
            calibrazione0_B.sqrt_i;

          /* Selector: '<S37>/Selector' incorporates:
           *  Sum: '<S41>/Sum1'
           */
          qY_1 = s13_iter + s62_iter;
          if ((s13_iter < 0) && ((s62_iter < 0) && (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((s13_iter > 0) && ((s62_iter > 0) && (qY_1 <= 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          /* End of Selector: '<S37>/Selector' */

          /* Sum: '<S37>/Sum' incorporates:
           *  Product: '<S37>/Product'
           *  Product: '<S37>/Product2'
           *  Selector: '<S37>/Selector'
           *  Selector: '<S37>/Selector1'
           *  Sum: '<S41>/Sum1'
           *  UnitDelay: '<S23>/Unit Delay1'
           */
          calibrazione0_B.Merge_j[1] = calibrazione0_DWork.UnitDelay_DSTATE_m
            [((s13_iter - 1) * 13 + qY_4) - 1] * calibrazione0_B.sqrt_i +
            calibrazione0_DWork.UnitDelay1_DSTATE_b[qY_1 - 1] *
            calibrazione0_B.Product4;

          /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */
        } else if ((s13_iter == 1) && (qY_4 == 0)) {
          /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Selector: '<S38>/Selector' incorporates:
           *  Gain: '<S43>/Gain'
           *  Sum: '<S43>/Sum1'
           */
          i = mul_s32_s32_s32_sat(calibrazione0_P.Gain_Gain_as, 0);
          qY_1 = 1 + i;
          if ((i > 0) && (qY_1 <= 0)) {
            qY_1 = MAX_int32_T;
          }

          /* End of Selector: '<S38>/Selector' */

          /* Product: '<S38>/Product3' incorporates:
           *  Selector: '<S38>/Selector'
           *  Sum: '<S43>/Sum1'
           *  UnitDelay: '<S23>/Unit Delay1'
           */
          calibrazione0_B.Merge_j[0] =
            calibrazione0_DWork.UnitDelay1_DSTATE_b[qY_1 - 1] *
            calibrazione0_B.Product4;

          /* Selector: '<S38>/Selector1' incorporates:
           *  Constant: '<S44>/Constant'
           *  Sum: '<S44>/Sum'
           */
          qY_1 = calibrazione0_P.Constant_Value_asp;

          /* Selector: '<S38>/Selector' incorporates:
           *  Gain: '<S43>/Gain'
           *  Sum: '<S43>/Sum1'
           */
          i = mul_s32_s32_s32_sat(calibrazione0_P.Gain_Gain_as, 0);
          qY_0 = 1 + i;
          if ((i > 0) && (qY_0 <= 0)) {
            qY_0 = MAX_int32_T;
          }

          /* End of Selector: '<S38>/Selector' */

          /* Sum: '<S38>/Sum' incorporates:
           *  Product: '<S38>/Product'
           *  Product: '<S38>/Product2'
           *  Selector: '<S38>/Selector'
           *  Selector: '<S38>/Selector1'
           *  Sum: '<S43>/Sum1'
           *  Sum: '<S44>/Sum'
           *  UnitDelay: '<S23>/Unit Delay1'
           */
          calibrazione0_B.Merge_j[1] =
            calibrazione0_DWork.UnitDelay_DSTATE_m[qY_1 - 1] *
            calibrazione0_B.Product4 -
            calibrazione0_DWork.UnitDelay1_DSTATE_b[qY_0 - 1] *
            calibrazione0_B.sqrt_i;

          /* End of Outputs for SubSystem: '<S23>/If Action Subsystem1' */
        } else {
          if ((s13_iter > 1) && (s13_iter != qY_4)) {
            /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S39>/Action Port'
             */
            /* Sum: '<S47>/Sum' incorporates:
             *  Constant: '<S47>/Constant'
             */
            qY_1 = qY_4 + calibrazione0_P.Constant_Value_aspr;
            if ((qY_4 < 0) && ((calibrazione0_P.Constant_Value_aspr < 0) &&
                               (qY_1 >= 0))) {
              qY_1 = MIN_int32_T;
            } else {
              if ((qY_4 > 0) && ((calibrazione0_P.Constant_Value_aspr > 0) &&
                                 (qY_1 <= 0))) {
                qY_1 = MAX_int32_T;
              }
            }

            s62_iter = qY_1 - 1;

            /* End of Sum: '<S47>/Sum' */

            /* Sum: '<S47>/Sum2' incorporates:
             *  Constant: '<S47>/Constant1'
             */
            qY_1 = s13_iter - calibrazione0_P.Constant1_Value_as;
            if ((calibrazione0_P.Constant1_Value_as < 0) && (qY_1 < 0)) {
              qY_1 = MAX_int32_T;
            }

            /* End of Sum: '<S47>/Sum2' */

            /* Product: '<S39>/Product' incorporates:
             *  Selector: '<S39>/Selector1'
             */
            h = calibrazione0_DWork.UnitDelay_DSTATE_m[(s13_iter - 1) * 13 +
              s62_iter] * calibrazione0_B.Product4;

            /* Sum: '<S48>/Sum2' incorporates:
             *  Constant: '<S48>/Constant1'
             */
            qY_0 = s13_iter - calibrazione0_P.Constant1_Value_asp;
            if ((calibrazione0_P.Constant1_Value_asp < 0) && (qY_0 < 0)) {
              qY_0 = MAX_int32_T;
            }

            /* End of Sum: '<S48>/Sum2' */

            /* Switch: '<S39>/Switch' incorporates:
             *  Constant: '<S39>/Constant'
             *  DataTypeConversion: '<S48>/Data Type Conversion'
             *  RelationalOperator: '<S48>/Relational Operator'
             *  Selector: '<S39>/Selector1'
             *  Sum: '<S47>/Sum2'
             *  Sum: '<S48>/Sum2'
             */
            if ((real_T)(qY_0 >= qY_4) > calibrazione0_P.Switch_Threshold) {
              rtb_a2 = calibrazione0_DWork.UnitDelay_DSTATE_m[(qY_1 - 1) * 13 +
                s62_iter];
            } else {
              rtb_a2 = calibrazione0_P.Constant_Value_a;
            }

            /* End of Switch: '<S39>/Switch' */

            /* Sum: '<S46>/Sum' incorporates:
             *  Constant: '<S46>/Constant'
             */
            qY_1 = s13_iter + calibrazione0_P.Constant_Value_aspro;
            if ((calibrazione0_P.Constant_Value_aspro > 0) && (qY_1 <= 0)) {
              qY_1 = MAX_int32_T;
            }

            qY_0 = qY_4 + calibrazione0_P.Constant_Value_aspro;
            if ((qY_4 < 0) && ((calibrazione0_P.Constant_Value_aspro < 0) &&
                               (qY_0 >= 0))) {
              qY_0 = MIN_int32_T;
            } else {
              if ((qY_4 > 0) && ((calibrazione0_P.Constant_Value_aspro > 0) &&
                                 (qY_0 <= 0))) {
                qY_0 = MAX_int32_T;
              }
            }

            /* End of Sum: '<S46>/Sum' */

            /* Product: '<S39>/Product1' incorporates:
             *  Constant: '<S39>/k[13][13]'
             *  Selector: '<S39>/Selector2'
             *  Sum: '<S46>/Sum'
             */
            rtb_Product1 = calibrazione0_P.k1313_Value_a[((qY_1 - 1) * 13 + qY_0)
              - 1] * rtb_a2;

            /* Gain: '<S45>/Gain' */
            s62_iter = mul_s32_s32_s32_sat(calibrazione0_P.Gain_Gain_asp, qY_4);

            /* Sum: '<S49>/Sum2' incorporates:
             *  Constant: '<S49>/Constant1'
             */
            i = s13_iter - calibrazione0_P.Constant1_Value_aspro;
            if ((calibrazione0_P.Constant1_Value_aspro < 0) && (i < 0)) {
              i = MAX_int32_T;
            }

            /* End of Sum: '<S49>/Sum2' */

            /* Switch: '<S39>/Switch1' incorporates:
             *  Constant: '<S39>/Constant1'
             *  DataTypeConversion: '<S49>/Data Type Conversion'
             *  RelationalOperator: '<S49>/Relational Operator'
             *  Selector: '<S39>/Selector'
             *  Sum: '<S45>/Sum1'
             *  Sum: '<S49>/Sum2'
             *  UnitDelay: '<S23>/Unit Delay1'
             */
            if ((real_T)(i >= qY_4) > calibrazione0_P.Switch1_Threshold) {
              /* Selector: '<S39>/Selector' incorporates:
               *  Constant: '<S45>/Constant1'
               *  Sum: '<S45>/Sum1'
               *  Sum: '<S45>/Sum2'
               */
              i = s13_iter - calibrazione0_P.Constant1_Value_aspr;
              if ((calibrazione0_P.Constant1_Value_aspr < 0) && (i < 0)) {
                i = MAX_int32_T;
              }

              rtb_Sum2_n = i + s62_iter;
              if ((i < 0) && ((s62_iter < 0) && (rtb_Sum2_n >= 0))) {
                rtb_Sum2_n = MIN_int32_T;
              } else {
                if ((i > 0) && ((s62_iter > 0) && (rtb_Sum2_n <= 0))) {
                  rtb_Sum2_n = MAX_int32_T;
                }
              }

              /* End of Selector: '<S39>/Selector' */
              rtb_a2 = calibrazione0_DWork.UnitDelay1_DSTATE_b[rtb_Sum2_n - 1];
            } else {
              rtb_a2 = calibrazione0_P.Constant1_Value_a;
            }

            /* End of Switch: '<S39>/Switch1' */

            /* Selector: '<S39>/Selector' incorporates:
             *  Sum: '<S45>/Sum1'
             */
            i = s13_iter + s62_iter;
            if ((s62_iter > 0) && (i <= 0)) {
              i = MAX_int32_T;
            }

            /* End of Selector: '<S39>/Selector' */

            /* Sum: '<S39>/Sum' incorporates:
             *  Product: '<S39>/Product4'
             *  Selector: '<S39>/Selector'
             *  Sum: '<S45>/Sum1'
             *  UnitDelay: '<S23>/Unit Delay1'
             */
            calibrazione0_B.Merge_j[1] = (h -
              calibrazione0_DWork.UnitDelay1_DSTATE_b[i - 1] *
              calibrazione0_B.sqrt_i) - rtb_Product1;

            /* Selector: '<S39>/Selector' incorporates:
             *  Sum: '<S45>/Sum1'
             */
            i = s13_iter + s62_iter;
            if ((s62_iter > 0) && (i <= 0)) {
              i = MAX_int32_T;
            }

            /* End of Selector: '<S39>/Selector' */

            /* Sum: '<S39>/Sum1' incorporates:
             *  Constant: '<S39>/k[13][13]'
             *  Product: '<S39>/Product2'
             *  Product: '<S39>/Product3'
             *  Selector: '<S39>/Selector'
             *  Selector: '<S39>/Selector2'
             *  Sum: '<S45>/Sum1'
             *  Sum: '<S46>/Sum'
             *  UnitDelay: '<S23>/Unit Delay1'
             */
            calibrazione0_B.Merge_j[0] =
              calibrazione0_DWork.UnitDelay1_DSTATE_b[i - 1] *
              calibrazione0_B.Product4 - calibrazione0_P.k1313_Value_a[((qY_1 -
              1) * 13 + qY_0) - 1] * rtb_a2;

            /* End of Outputs for SubSystem: '<S23>/If Action Subsystem2' */
          }
        }

        /* End of If: '<S23>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' */

        /* Assignment: '<S23>/Assignment' incorporates:
         *  Sum: '<S23>/Sum'
         *  UnitDelay: '<S23>/Unit Delay'
         */
        if (calibrazione0_DWork.ForIterator_IterationMarker[2] < 2) {
          calibrazione0_DWork.ForIterator_IterationMarker[2] = 2U;
          memcpy((void *)(&calibrazione0_B.Assignment_g[0]), (void *)
                 calibrazione0_DWork.UnitDelay_DSTATE_m, 169U * sizeof(real_T));
        }

        calibrazione0_B.Assignment_g[(qY_2 + 13 * (qY_3 - 1)) - 1] =
          calibrazione0_B.Merge_j[1];

        /* End of Assignment: '<S23>/Assignment' */

        /* Assignment: '<S23>/Assignment_snorm' incorporates:
         *  Constant: '<S40>/Constant'
         *  Gain: '<S40>/Gain'
         *  Sum: '<S23>/Sum'
         *  Sum: '<S40>/Sum1'
         *  Sum: '<S40>/Sum2'
         *  UnitDelay: '<S23>/Unit Delay1'
         */
        if (calibrazione0_DWork.ForIterator_IterationMarker[3] < 2) {
          calibrazione0_DWork.ForIterator_IterationMarker[3] = 2U;
          memcpy((void *)(&calibrazione0_B.Assignment_snorm[0]), (void *)
                 calibrazione0_DWork.UnitDelay1_DSTATE_b, 169U * sizeof(real_T));
        }

        qY_1 = qY_2 - calibrazione0_P.Constant_Value_l;
        if ((qY_2 < 0) && ((calibrazione0_P.Constant_Value_l >= 0) && (qY_1 >= 0)))
        {
          qY_1 = MIN_int32_T;
        } else {
          if ((qY_2 >= 0) && ((calibrazione0_P.Constant_Value_l < 0) && (qY_1 <
                0))) {
            qY_1 = MAX_int32_T;
          }
        }

        calibrazione0_B.Assignment_snorm[(int32_T)((real_T)qY_3 + (real_T)
          mul_s32_s32_s32_sat(calibrazione0_P.Gain_Gain_l, qY_1)) - 1] =
          calibrazione0_B.Merge_j[0];
        for (i = 0; i < 169; i++) {
          /* Update for UnitDelay: '<S23>/Unit Delay' */
          calibrazione0_DWork.UnitDelay_DSTATE_m[i] =
            calibrazione0_B.Assignment_g[i];

          /* Update for UnitDelay: '<S23>/Unit Delay1' */
          calibrazione0_DWork.UnitDelay1_DSTATE_b[i] =
            calibrazione0_B.Assignment_snorm[i];
        }

        /* End of Assignment: '<S23>/Assignment_snorm' */
      }

      /* End of Outputs for SubSystem: '<S21>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

      /* Sum: '<S22>/Sum' incorporates:
       *  Constant: '<S22>/Constant'
       *  Sum: '<S21>/Sum1'
       */
      qY_3 = s13_iter + calibrazione0_P.Constant_Value_i;
      if ((s13_iter < 0) && ((calibrazione0_P.Constant_Value_i < 0) && (qY_3 >=
            0))) {
        qY_3 = MIN_int32_T;
      } else {
        if ((s13_iter > 0) && ((calibrazione0_P.Constant_Value_i > 0) && (qY_3 <=
              0))) {
          qY_3 = MAX_int32_T;
        }
      }

      qY_2 = qY_4 + calibrazione0_P.Constant_Value_i;
      if ((qY_4 < 0) && ((calibrazione0_P.Constant_Value_i < 0) && (qY_2 >= 0)))
      {
        qY_2 = MIN_int32_T;
      } else {
        if ((qY_4 > 0) && ((calibrazione0_P.Constant_Value_i > 0) && (qY_2 <= 0)))
        {
          qY_2 = MAX_int32_T;
        }
      }

      /* End of Sum: '<S22>/Sum' */

      /* Selector: '<S22>/dp[n][m]' incorporates:
       *  Sum: '<S22>/Sum'
       */
      h = calibrazione0_B.Assignment_g[((qY_3 - 1) * 13 + qY_2) - 1];

      /* Outputs for Enabled SubSystem: '<S21>/Time adjust the gauss coefficients' incorporates:
       *  EnablePort: '<S24>/Enable'
       */
      if (rtb_RelationalOperator) {
        /* Outputs for Atomic SubSystem: '<S24>/If Action Subsystem' */
        /* Sum: '<S50>/Sum1' incorporates:
         *  Constant: '<S50>/Constant1'
         *  Sum: '<S21>/Sum1'
         */
        qY_3 = qY_4 + calibrazione0_P.Constant1_Value_d2;
        if ((qY_4 < 0) && ((calibrazione0_P.Constant1_Value_d2 < 0) && (qY_3 >=
              0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((qY_4 > 0) && ((calibrazione0_P.Constant1_Value_d2 > 0) && (qY_3 <=
                0))) {
            qY_3 = MAX_int32_T;
          }
        }

        s62_iter = qY_3 - 1;

        /* End of Sum: '<S50>/Sum1' */

        /* Sum: '<S50>/Sum2' incorporates:
         *  Constant: '<S50>/Constant'
         */
        qY_3 = s13_iter + calibrazione0_P.Constant_Value_b;
        if ((s13_iter < 0) && ((calibrazione0_P.Constant_Value_b < 0) && (qY_3 >=
              0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((s13_iter > 0) && ((calibrazione0_P.Constant_Value_b > 0) && (qY_3
                <= 0))) {
            qY_3 = MAX_int32_T;
          }
        }

        rtb_Sum2_n = qY_3 - 1;

        /* End of Sum: '<S50>/Sum2' */
        /* End of Outputs for SubSystem: '<S24>/If Action Subsystem' */

        /* Assignment: '<S24>/Assignment' incorporates:
         *  Constant: '<S24>/c[maxdef][maxdef]'
         *  Constant: '<S24>/cd[maxdef][maxdef]'
         *  Product: '<S50>/Product'
         *  Selector: '<S50>/c[m][n]'
         *  Selector: '<S50>/cd[m][n]'
         *  Sum: '<S50>/Sum'
         *  UnitDelay: '<S24>/Unit Delay'
         */
        if (calibrazione0_DWork.ForIterator_IterationMarker[5] < 2) {
          calibrazione0_DWork.ForIterator_IterationMarker[5] = 2U;
          memcpy((void *)&Assignment_e[0], (void *)
                 calibrazione0_DWork.UnitDelay_DSTATE_o, 169U * sizeof(real_T));
        }

        /* Outputs for Atomic SubSystem: '<S24>/If Action Subsystem' */
        Assignment_e[s62_iter + 13 * rtb_Sum2_n] =
          calibrazione0_P.cdmaxdefmaxdef_Value[13 * rtb_Sum2_n + s62_iter] *
          rtb_Sum_o + calibrazione0_P.cmaxdefmaxdef_Value[13 * rtb_Sum2_n +
          s62_iter];

        /* End of Assignment: '<S24>/Assignment' */
        /* End of Outputs for SubSystem: '<S24>/If Action Subsystem' */

        /* Switch: '<S51>/tc_old' incorporates:
         *  Constant: '<S51>/zeros(maxdef+1,maxdef+1)'
         *  UnitDelay: '<S51>/Unit Delay'
         */
        for (i = 0; i < 169; i++) {
          if (s13_iter > calibrazione0_P.tc_old_Threshold) {
            rtb_tc_old[i] = calibrazione0_DWork.UnitDelay_DSTATE_b[i];
          } else {
            rtb_tc_old[i] = calibrazione0_P.zerosmaxdef1maxdef1_Value[i];
          }
        }

        /* End of Switch: '<S51>/tc_old' */

        /* If: '<S51>/If' incorporates:
         *  Sum: '<S21>/Sum1'
         */
        if (qY_4 != 0) {
          /* Outputs for IfAction SubSystem: '<S51>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S52>/Action Port'
           */
          /* Sum: '<S52>/Sum2' incorporates:
           *  Constant: '<S52>/Constant'
           */
          qY_3 = s13_iter + calibrazione0_P.Constant_Value_lf;
          if ((s13_iter < 0) && ((calibrazione0_P.Constant_Value_lf < 0) &&
                                 (qY_3 >= 0))) {
            qY_3 = MIN_int32_T;
          } else {
            if ((s13_iter > 0) && ((calibrazione0_P.Constant_Value_lf > 0) &&
                                   (qY_3 <= 0))) {
              qY_3 = MAX_int32_T;
            }
          }

          s62_iter = qY_3 - 1;

          /* End of Sum: '<S52>/Sum2' */

          /* Assignment: '<S52>/Assignment2' incorporates:
           *  Constant: '<S24>/c[maxdef][maxdef]'
           *  Constant: '<S24>/cd[maxdef][maxdef]'
           *  Product: '<S52>/Product'
           *  Selector: '<S52>/c[m][n]'
           *  Selector: '<S52>/cd[m][n]'
           *  Sum: '<S52>/Sum'
           */
          if (calibrazione0_DWork.ForIterator_IterationMarker[6] < 2) {
            calibrazione0_DWork.ForIterator_IterationMarker[6] = 2U;
            memcpy((void *)&Assignment[0], (void *)&rtb_tc_old[0], 169U * sizeof
                   (real_T));
          }

          Assignment[s62_iter + 13 * (qY_4 - 1)] =
            calibrazione0_P.cdmaxdefmaxdef_Value[(qY_4 - 1) * 13 + s62_iter] *
            rtb_Sum_o + calibrazione0_P.cmaxdefmaxdef_Value[(qY_4 - 1) * 13 +
            s62_iter];

          /* End of Assignment: '<S52>/Assignment2' */

          /* Gain: '<S52>/Gain' */
          for (i = 0; i < 169; i++) {
            rtb_tc_old[i] = calibrazione0_P.Gain_Gain * Assignment[i];
          }

          /* End of Gain: '<S52>/Gain' */
          /* End of Outputs for SubSystem: '<S51>/If Action Subsystem1' */
        } else {
        }

        for (i = 0; i < 169; i++) {
          /* Sum: '<S24>/Sum2' */
          calibrazione0_B.Sum2_e[i] = Assignment_e[i] + rtb_tc_old[i];

          /* Update for UnitDelay: '<S24>/Unit Delay' */
          calibrazione0_DWork.UnitDelay_DSTATE_o[i] = Assignment_e[i];

          /* Update for UnitDelay: '<S51>/Unit Delay' */
          calibrazione0_DWork.UnitDelay_DSTATE_b[i] = rtb_tc_old[i];
        }

        /* End of If: '<S51>/If' */
      }

      /* End of Outputs for SubSystem: '<S21>/Time adjust the gauss coefficients' */

      /* Sum: '<S27>/Sum4' incorporates:
       *  Constant: '<S27>/Constant1'
       *  Sum: '<S21>/Sum1'
       */
      rtb_Product1 = (real_T)qY_4 + calibrazione0_P.Constant1_Value_g;

      /* Selector: '<S27>/cp[m+1]' incorporates:
       *  SignalConversion: '<S27>/TmpSignal ConversionAtcp[m+1]Inport1'
       */
      tmp[0] = calibrazione0_B.cp1;
      tmp[1] = calibrazione0_B.cp2;

      /* SignalConversion: '<S27>/TmpSignal ConversionAtsp[m+1]Inport1' */
      rtb_TmpSignalConversionAtspm1In[0] = calibrazione0_B.sp1;
      rtb_TmpSignalConversionAtspm1In[1] = calibrazione0_B.sp2;
      for (qY_3 = 0; qY_3 < 11; qY_3++) {
        /* Selector: '<S27>/cp[m+1]' incorporates:
         *  SignalConversion: '<S27>/TmpSignal ConversionAtcp[m+1]Inport1'
         */
        tmp[qY_3 + 2] = calibrazione0_B.Assignment1[qY_3];
        rtb_TmpSignalConversionAtspm1In[qY_3 + 2] =
          calibrazione0_B.Assignment[qY_3];
      }

      /* End of SignalConversion: '<S27>/TmpSignal ConversionAtsp[m+1]Inport1' */

      /* If: '<S27>/If' incorporates:
       *  Sum: '<S21>/Sum1'
       */
      if (qY_4 == 0) {
        /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem' incorporates:
         *  ActionPort: '<S33>/Action Port'
         */
        /* Sum: '<S33>/Sum' incorporates:
         *  Constant: '<S33>/Constant'
         */
        rtb_sincos_o1_h_idx = (real_T)s13_iter +
          calibrazione0_P.Constant_Value_j;

        /* Product: '<S33>/Product' incorporates:
         *  Constant: '<S33>/Constant'
         *  Selector: '<S27>/cp[m+1]'
         *  Selector: '<S27>/sp[m+1]'
         *  Selector: '<S33>/Selector'
         *  Sum: '<S33>/Sum'
         */
        calibrazione0_B.Merge[0] = calibrazione0_B.Sum2_e[(((int32_T)
          rtb_sincos_o1_h_idx - 1) * 13 + (int32_T)
          calibrazione0_P.Constant_Value_j) - 1] * tmp[(int32_T)rtb_Product1 - 1];
        calibrazione0_B.Merge[1] = calibrazione0_B.Sum2_e[(((int32_T)
          rtb_sincos_o1_h_idx - 1) * 13 + (int32_T)
          calibrazione0_P.Constant_Value_j) - 1] *
          rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_Product1 - 1];

        /* End of Outputs for SubSystem: '<S27>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S27>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Sum: '<S35>/Sum' incorporates:
         *  Constant: '<S35>/Constant'
         */
        rtb_sincos_o1_h_idx = (real_T)s13_iter +
          calibrazione0_P.Constant_Value_jd;
        rtb_sincos_o1_h_idx_0 = (real_T)qY_4 + calibrazione0_P.Constant_Value_jd;

        /* Selector: '<S34>/Selector' */
        rtb_Sum1_mz = rtb_sincos_o1_h_idx;

        /* Product: '<S34>/Product' incorporates:
         *  Selector: '<S27>/cp[m+1]'
         *  Selector: '<S27>/sp[m+1]'
         *  Selector: '<S34>/Selector'
         */
        rtb_sincos_o1_h_idx = calibrazione0_B.Sum2_e[(((int32_T)
          rtb_sincos_o1_h_idx - 1) * 13 + (int32_T)rtb_sincos_o1_h_idx_0) - 1] *
          tmp[(int32_T)rtb_Product1 - 1];
        rtb_sincos_o1_h_idx_0 = calibrazione0_B.Sum2_e[(((int32_T)rtb_Sum1_mz -
          1) * 13 + (int32_T)rtb_sincos_o1_h_idx_0) - 1] *
          rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_Product1 - 1];

        /* Sum: '<S34>/Sum' incorporates:
         *  Constant: '<S36>/Constant'
         *  Product: '<S34>/Product1'
         *  Selector: '<S27>/sp[m+1]'
         *  Selector: '<S34>/Selector1'
         *  Sum: '<S36>/Sum'
         */
        calibrazione0_B.Merge[0] = calibrazione0_B.Sum2_e[((qY_4 - 1) * 13 +
          (int32_T)((real_T)s13_iter + calibrazione0_P.Constant_Value_e)) - 1] *
          rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_Product1 - 1] +
          rtb_sincos_o1_h_idx;

        /* Sum: '<S34>/Sum1' incorporates:
         *  Constant: '<S36>/Constant'
         *  Product: '<S34>/Product1'
         *  Selector: '<S27>/cp[m+1]'
         *  Selector: '<S34>/Selector1'
         *  Sum: '<S36>/Sum'
         */
        calibrazione0_B.Merge[1] = rtb_sincos_o1_h_idx_0 -
          calibrazione0_B.Sum2_e[((qY_4 - 1) * 13 + (int32_T)((real_T)s13_iter +
          calibrazione0_P.Constant_Value_e)) - 1] * tmp[(int32_T)rtb_Product1 -
          1];

        /* End of Outputs for SubSystem: '<S27>/If Action Subsystem1' */
      }

      /* End of If: '<S27>/If' */

      /* Selector: '<S22>/snorm[n+m*13]' incorporates:
       *  Constant: '<S26>/Constant'
       *  Gain: '<S26>/Gain'
       *  Sum: '<S21>/Sum1'
       *  Sum: '<S26>/Sum1'
       */
      qY_3 = calibrazione0_P.Constant_Value_m + s13_iter;
      if ((calibrazione0_P.Constant_Value_m < 0) && ((s13_iter < 0) && (qY_3 >=
            0))) {
        qY_3 = MIN_int32_T;
      } else {
        if ((calibrazione0_P.Constant_Value_m > 0) && ((s13_iter > 0) && (qY_3 <=
              0))) {
          qY_3 = MAX_int32_T;
        }
      }

      i = mul_s32_s32_s32_sat(calibrazione0_P.Gain_Gain_o, qY_4);
      qY_2 = qY_3 + i;
      if ((qY_3 < 0) && ((i < 0) && (qY_2 >= 0))) {
        qY_2 = MIN_int32_T;
      } else {
        if ((qY_3 > 0) && ((i > 0) && (qY_2 <= 0))) {
          qY_2 = MAX_int32_T;
        }
      }

      /* End of Selector: '<S22>/snorm[n+m*13]' */

      /* Product: '<S22>/par' incorporates:
       *  Selector: '<S22>/snorm[n+m*13]'
       *  Sum: '<S26>/Sum1'
       */
      rtb_Product1 = calibrazione0_B.Assignment_snorm[qY_2 - 1] * rtb_q;

      /* Sum: '<S22>/Sum4' incorporates:
       *  Constant: '<S22>/Constant1'
       *  Sum: '<S21>/Sum1'
       */
      qY_3 = s13_iter + calibrazione0_P.Constant1_Value_pd;
      if ((s13_iter < 0) && ((calibrazione0_P.Constant1_Value_pd < 0) && (qY_3 >=
            0))) {
        qY_3 = MIN_int32_T;
      } else {
        if ((s13_iter > 0) && ((calibrazione0_P.Constant1_Value_pd > 0) && (qY_3
              <= 0))) {
          qY_3 = MAX_int32_T;
        }
      }

      qY_2 = qY_4 + calibrazione0_P.Constant1_Value_pd;
      if ((qY_4 < 0) && ((calibrazione0_P.Constant1_Value_pd < 0) && (qY_2 >= 0)))
      {
        qY_2 = MIN_int32_T;
      } else {
        if ((qY_4 > 0) && ((calibrazione0_P.Constant1_Value_pd > 0) && (qY_2 <=
              0))) {
          qY_2 = MAX_int32_T;
        }
      }

      /* End of Sum: '<S22>/Sum4' */

      /* Outputs for Enabled SubSystem: '<S22>/Special case - North//South Geographic Pole' incorporates:
       *  EnablePort: '<S25>/Enable'
       */
      if ((calibrazione0_B.sqrt_i == calibrazione0_P.Constant1_Value_d) &&
          (calibrazione0_P.Constant_Value_je == qY_4)) {
        if (!calibrazione0_DWork.SpecialcaseNorthSouthGeographic) {
          calibrazione0_DWork.SpecialcaseNorthSouthGeographic = TRUE;
        }

        /* If: '<S25>/n ==1' */
        if (s13_iter == 1) {
          /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S29>/Action Port'
           */
          /* Assignment: '<S29>/Assignment2' incorporates:
           *  Constant: '<S29>/Constant'
           *  Selector: '<S29>/pp[n-1]'
           *  Sum: '<S29>/Sum2'
           *  UnitDelay: '<S25>/Unit Delay1'
           */
          if (calibrazione0_DWork.ForIterator_IterationMarker[0] < 2) {
            calibrazione0_DWork.ForIterator_IterationMarker[0] = 2U;
            memcpy((void *)(&calibrazione0_B.Assignment2_dj[0]), (void *)
                   calibrazione0_DWork.UnitDelay1_DSTATE_f, 13U * sizeof(real_T));
          }

          calibrazione0_B.Assignment2_dj[(int32_T)(1.0 +
            calibrazione0_P.Constant_Value) - 1] =
            calibrazione0_DWork.UnitDelay1_DSTATE_f[0];

          /* End of Assignment: '<S29>/Assignment2' */
          /* End of Outputs for SubSystem: '<S25>/If Action Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S25>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S30>/Action Port'
           */
          /* Sum: '<S32>/Sum' incorporates:
           *  Constant: '<S32>/Constant'
           */
          qY_1 = s13_iter + calibrazione0_P.Constant_Value_ex;
          if ((s13_iter < 0) && ((calibrazione0_P.Constant_Value_ex < 0) &&
                                 (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((s13_iter > 0) && ((calibrazione0_P.Constant_Value_ex > 0) &&
                                   (qY_1 <= 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          qY_0 = qY_4 + calibrazione0_P.Constant_Value_ex;
          if ((qY_4 < 0) && ((calibrazione0_P.Constant_Value_ex < 0) && (qY_0 >=
                0))) {
            qY_0 = MIN_int32_T;
          } else {
            if ((qY_4 > 0) && ((calibrazione0_P.Constant_Value_ex > 0) && (qY_0 <=
                  0))) {
              qY_0 = MAX_int32_T;
            }
          }

          /* End of Sum: '<S32>/Sum' */

          /* Assignment: '<S30>/Assignment2' incorporates:
           *  Constant: '<S30>/Constant'
           *  Sum: '<S30>/Sum2'
           *  UnitDelay: '<S25>/Unit Delay1'
           */
          if (calibrazione0_DWork.ForIterator_IterationMarker[1] < 2) {
            calibrazione0_DWork.ForIterator_IterationMarker[1] = 2U;
            memcpy((void *)(&calibrazione0_B.Assignment2_d[0]), (void *)
                   calibrazione0_DWork.UnitDelay1_DSTATE_f, 13U * sizeof(real_T));
          }

          qY_4 = s13_iter + calibrazione0_P.Constant_Value_exo;
          if ((s13_iter < 0) && ((calibrazione0_P.Constant_Value_exo < 0) &&
                                 (qY_4 >= 0))) {
            qY_4 = MIN_int32_T;
          } else {
            if ((s13_iter > 0) && ((calibrazione0_P.Constant_Value_exo > 0) &&
                                   (qY_4 <= 0))) {
              qY_4 = MAX_int32_T;
            }
          }

          /* End of Assignment: '<S30>/Assignment2' */

          /* Selector: '<S30>/pp[n-2] pp[n-1]' incorporates:
           *  Constant: '<S31>/Constant1'
           *  Sum: '<S31>/Sum2'
           */
          i = s13_iter - calibrazione0_P.Constant1_Value_e;
          if ((s13_iter < 0) && ((calibrazione0_P.Constant1_Value_e >= 0) && (i >=
                0))) {
            i = MIN_int32_T;
          } else {
            if ((s13_iter >= 0) && ((calibrazione0_P.Constant1_Value_e < 0) &&
                                    (i < 0))) {
              i = MAX_int32_T;
            }
          }

          /* End of Selector: '<S30>/pp[n-2] pp[n-1]' */

          /* Assignment: '<S30>/Assignment2' incorporates:
           *  Constant: '<S30>/k[13][13]'
           *  Product: '<S30>/Product1'
           *  Product: '<S30>/Product2'
           *  Selector: '<S30>/Selector2'
           *  Selector: '<S30>/pp[n-2] pp[n-1]'
           *  Sum: '<S30>/Sum1'
           *  Sum: '<S30>/Sum2'
           *  Sum: '<S31>/Sum2'
           *  Sum: '<S32>/Sum'
           *  UnitDelay: '<S25>/Unit Delay1'
           */
          calibrazione0_B.Assignment2_d[qY_4 - 1] =
            calibrazione0_DWork.UnitDelay1_DSTATE_f[s13_iter - 1] *
            calibrazione0_B.Product4 - calibrazione0_P.k1313_Value[((qY_1 - 1) *
            13 + qY_0) - 1] * calibrazione0_DWork.UnitDelay1_DSTATE_f[i - 1];

          /* End of Outputs for SubSystem: '<S25>/If Action Subsystem2' */
        }

        /* End of If: '<S25>/n ==1' */

        /* SignalConversion: '<S25>/TmpSignal ConversionAtpp[n]Inport1' incorporates:
         *  UnitDelay: '<S25>/Unit Delay1'
         */
        rtb_TmpSignalConversionAtspm1In[0] =
          calibrazione0_DWork.UnitDelay1_DSTATE_f[0];
        rtb_TmpSignalConversionAtspm1In[1] = calibrazione0_B.Assignment2_dj[1];
        memcpy((void *)&rtb_TmpSignalConversionAtspm1In[2], (void *)
               (&calibrazione0_B.Assignment2_d[2]), 11U * sizeof(real_T));

        /* Product: '<S25>/Product2' incorporates:
         *  Constant: '<S25>/Constant'
         *  Constant: '<S25>/Constant1'
         *  Selector: '<S25>/pp[n]'
         *  Sum: '<S25>/Sum2'
         */
        calibrazione0_B.Product2 = rtb_TmpSignalConversionAtspm1In[(int32_T)
          ((real_T)s13_iter + calibrazione0_P.Constant1_Value) - 1] * rtb_q *
          calibrazione0_P.Constant_Value_g * calibrazione0_B.Merge[1];

        /* Update for UnitDelay: '<S25>/Unit Delay1' */
        memcpy((void *)calibrazione0_DWork.UnitDelay1_DSTATE_f, (void *)
               &rtb_TmpSignalConversionAtspm1In[0], 13U * sizeof(real_T));
      } else {
        if (calibrazione0_DWork.SpecialcaseNorthSouthGeographic) {
          /* Disable for Outport: '<S25>/bpp' */
          calibrazione0_B.Product2 = calibrazione0_P.bpp_Y0;
          calibrazione0_DWork.SpecialcaseNorthSouthGeographic = FALSE;
        }
      }

      /* End of Outputs for SubSystem: '<S22>/Special case - North//South Geographic Pole' */

      /* Sum: '<S22>/Sum1' incorporates:
       *  Constant: '<S28>/Constant'
       *  Constant: '<S28>/Constant1'
       *  Logic: '<S28>/Logical Operator'
       *  Product: '<S22>/Product'
       *  RelationalOperator: '<S28>/Relational Operator'
       *  RelationalOperator: '<S28>/Relational Operator1'
       *  Sum: '<S21>/Sum1'
       *  UnitDelay: '<S22>/Unit Delay1'
       */
      calibrazione0_B.Sum1 = calibrazione0_DWork.UnitDelay1_DSTATE_d -
        calibrazione0_B.Merge[0] * h * rtb_q;

      /* Sum: '<S22>/Sum2' incorporates:
       *  Constant: '<S22>/fm'
       *  Product: '<S22>/Product1'
       *  Selector: '<S22>/fm[m]'
       *  Sum: '<S22>/Sum4'
       *  UnitDelay: '<S22>/Unit Delay3'
       */
      calibrazione0_B.Sum2 = calibrazione0_P.fm_Value[qY_2 - 1] * rtb_Product1 *
        calibrazione0_B.Merge[1] + calibrazione0_DWork.UnitDelay3_DSTATE;

      /* Sum: '<S22>/Sum3' incorporates:
       *  Constant: '<S22>/fn'
       *  Product: '<S22>/Product2'
       *  Selector: '<S22>/fn[m]'
       *  Sum: '<S22>/Sum4'
       *  UnitDelay: '<S22>/Unit Delay2'
       */
      calibrazione0_B.Sum3 = calibrazione0_P.fn_Value[qY_3 - 1] * rtb_Product1 *
        calibrazione0_B.Merge[0] + calibrazione0_DWork.UnitDelay2_DSTATE_b;

      /* Sum: '<S22>/Sum5' incorporates:
       *  UnitDelay: '<S22>/Unit Delay4'
       */
      calibrazione0_B.Sum5 = calibrazione0_DWork.UnitDelay4_DSTATE +
        calibrazione0_B.Product2;

      /* Update for UnitDelay: '<S22>/Unit Delay1' */
      calibrazione0_DWork.UnitDelay1_DSTATE_d = calibrazione0_B.Sum1;

      /* Update for UnitDelay: '<S22>/Unit Delay3' */
      calibrazione0_DWork.UnitDelay3_DSTATE = calibrazione0_B.Sum2;

      /* Update for UnitDelay: '<S22>/Unit Delay2' */
      calibrazione0_DWork.UnitDelay2_DSTATE_b = calibrazione0_B.Sum3;

      /* Update for UnitDelay: '<S22>/Unit Delay4' */
      calibrazione0_DWork.UnitDelay4_DSTATE = calibrazione0_B.Sum5;
    }

    /* End of Sum: '<S13>/Sum' */
    /* End of Outputs for SubSystem: '<S13>/For Iterator Subsystem' */

    /* Sum: '<S13>/Sum1' incorporates:
     *  UnitDelay: '<S13>/Unit Delay2'
     */
    rtb_Sum1_m_idx_1 = rtb_d + calibrazione0_B.Sum1;
    rtb_Sum1_m_idx_0 = rtb_Sum4 + calibrazione0_B.Sum2;
    rtb_Sum1_m_idx_2 = rtb_sincos_o2_idx + calibrazione0_B.Sum3;
    rtb_Sum1_m_idx = rtb_sincos_o1_idx + calibrazione0_B.Sum5;

    /* Update for UnitDelay: '<S13>/Unit Delay2' */
    rtb_d = rtb_Sum1_m_idx_1;
    rtb_Sum4 = rtb_Sum1_m_idx_0;
    rtb_sincos_o2_idx = rtb_Sum1_m_idx_2;
    rtb_sincos_o1_idx = rtb_Sum1_m_idx;
  }

  /* End of Outputs for SubSystem: '<S11>/Compute magnetic vector in spherical coordinates' */

  /* Switch: '<S65>/Switch' incorporates:
   *  Product: '<S65>/Product'
   */
  if (calibrazione0_B.sqrt_i != 0.0) {
    h = rtb_Sum1_m_idx_0 / calibrazione0_B.sqrt_i;
  } else {
    h = rtb_Sum1_m_idx;
  }

  /* End of Switch: '<S65>/Switch' */

  /* Sum: '<S64>/Sum1' incorporates:
   *  Product: '<S64>/Product1'
   *  Product: '<S64>/Product4'
   */
  rtb_a2 = (0.0 - calibrazione0_B.Product11 * rtb_Sum1_m_idx_1) -
    rtb_Sum1_m_idx_2 * calibrazione0_B.Product12;

  /* Trigonometry: '<S67>/Trigonometric Function1' */
  rtb_Product1 = rt_atan2d_snf(h, rtb_a2);

  /* Sum: '<S66>/Sum1' incorporates:
   *  Product: '<S66>/Product1'
   *  Product: '<S66>/Product4'
   */
  rtb_q = calibrazione0_B.Product12 * rtb_Sum1_m_idx_1 - rtb_Sum1_m_idx_2 *
    calibrazione0_B.Product11;

  /* Sum: '<S67>/Sum' incorporates:
   *  Product: '<S67>/Product'
   *  Product: '<S67>/Product1'
   */
  rtb_a2 = h * h + rtb_a2 * rtb_a2;

  /* Gain: '<S12>/Unit Conversion' incorporates:
   *  Gain: '<S68>/Unit Conversion'
   *  Gain: '<S69>/Unit Conversion'
   *  Sqrt: '<S67>/sqrt1'
   *  Trigonometry: '<S67>/Trigonometric Function'
   */
  rtb_sincos_o1_h_idx = calibrazione0_P.UnitConversion_Gain_p * rtb_Product1 *
    calibrazione0_P.UnitConversion_Gain_g;
  rtb_sincos_o1_h_idx_0 = calibrazione0_P.UnitConversion_Gain_pl * rt_atan2d_snf
    (rtb_q, sqrt(rtb_a2)) * calibrazione0_P.UnitConversion_Gain_g;

  /* Trigonometry: '<S8>/sincos' */
  rtb_Sum1_mz = cos(rtb_sincos_o1_h_idx);
  rtb_sincos_o1_h_idx = sin(rtb_sincos_o1_h_idx);

  /* Sum: '<S67>/Sum1' incorporates:
   *  Product: '<S67>/Product2'
   */
  rtb_a2 += rtb_q * rtb_q;

  /* Sqrt: '<S67>/sqrt' */
  rtb_a2 = sqrt(rtb_a2);

  /* Product: '<S8>/h1' incorporates:
   *  Trigonometry: '<S8>/sincos'
   */
  rtb_q = cos(rtb_sincos_o1_h_idx_0) * rtb_a2;

  /* Product: '<S8>/x1' */
  h = rtb_Sum1_mz * rtb_q;

  /* Product: '<S8>/y1' */
  rtb_q *= rtb_sincos_o1_h_idx;

  /* Product: '<S8>/z1' incorporates:
   *  Trigonometry: '<S8>/sincos'
   */
  rtb_a2 *= sin(rtb_sincos_o1_h_idx_0);

  /* Outport: '<Root>/W' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S4>/Power Conversion'
   */
  calibrazione0_Y.W[0] = calibrazione0_P.PowerConversion_Gain * h *
    calibrazione0_P.Gain1_Gain * calibrazione0_P.Gain1_Gain_d;
  calibrazione0_Y.W[1] = calibrazione0_P.PowerConversion_Gain * rtb_q *
    calibrazione0_P.Gain1_Gain * calibrazione0_P.Gain1_Gain_d;
  calibrazione0_Y.W[2] = calibrazione0_P.PowerConversion_Gain * rtb_a2 *
    calibrazione0_P.Gain1_Gain * calibrazione0_P.Gain1_Gain_d;

  /* Assertion: '<S5>/Assertion' incorporates:
   *  Constant: '<S5>/max_val'
   *  Constant: '<S5>/min_val'
   *  Logic: '<S5>/conjunction'
   *  RelationalOperator: '<S5>/max_relop'
   *  RelationalOperator: '<S5>/min_relop'
   */
  utAssert((calibrazione0_P.min_val_Value <= rtb_UnitConversion) &&
           (rtb_UnitConversion <= calibrazione0_P.max_val_Value));

  /* Assertion: '<S6>/Assertion' incorporates:
   *  Constant: '<S6>/max_val'
   *  Constant: '<S6>/min_val'
   *  Inport: '<Root>/posizione'
   *  Logic: '<S6>/conjunction'
   *  RelationalOperator: '<S6>/max_relop'
   *  RelationalOperator: '<S6>/min_relop'
   */
  utAssert((calibrazione0_P.min_val_Value_c <= calibrazione0_U.posizione[0]) &&
           (calibrazione0_U.posizione[0] <= calibrazione0_P.max_val_Value_p));

  /* Assertion: '<S7>/Assertion' incorporates:
   *  Constant: '<S7>/max_val'
   *  Constant: '<S7>/min_val'
   *  Inport: '<Root>/posizione'
   *  Logic: '<S7>/conjunction'
   *  RelationalOperator: '<S7>/max_relop'
   *  RelationalOperator: '<S7>/min_relop'
   */
  utAssert((calibrazione0_P.min_val_Value_j <= calibrazione0_U.posizione[1]) &&
           (calibrazione0_U.posizione[1] <= calibrazione0_P.max_val_Value_m));

  /* Assertion: '<S9>/Assertion' incorporates:
   *  Constant: '<S9>/max_val'
   *  Constant: '<S9>/min_val'
   *  Logic: '<S9>/conjunction'
   *  RelationalOperator: '<S9>/max_relop'
   *  RelationalOperator: '<S9>/min_relop'
   */
  utAssert((calibrazione0_P.min_val_Value_k <= rtb_Sum_o) && (rtb_Sum_o <=
            calibrazione0_P.max_val_Value_k));

  /* Update for Memory: '<S19>/otime' */
  calibrazione0_DWork.otime_PreviousInput = rtb_Sum;

  /* Update for Memory: '<S18>/olon' */
  calibrazione0_DWork.olon_PreviousInput = rtb_u80deg;

  /* Update for Memory: '<S17>/olat' */
  calibrazione0_DWork.olat_PreviousInput = rtb_u0deg;

  /* Update for Memory: '<S17>/oalt' */
  calibrazione0_DWork.oalt_PreviousInput = rtb_Gain;
}

/* Model initialize function */
void calibrazione0_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(calibrazione0_M, (NULL));

  /* block I/O */
  {
    int_T i;
    for (i = 0; i < 11; i++) {
      calibrazione0_B.Assignment[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      calibrazione0_B.Assignment1[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      calibrazione0_B.Sum2_e[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      calibrazione0_B.Assignment_g[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      calibrazione0_B.Assignment_snorm[i] = 0.0;
    }

    for (i = 0; i < 13; i++) {
      calibrazione0_B.Assignment2_d[i] = 0.0;
    }

    for (i = 0; i < 13; i++) {
      calibrazione0_B.Assignment2_dj[i] = 0.0;
    }

    calibrazione0_B.sp2 = 0.0;
    calibrazione0_B.cp2 = 0.0;
    calibrazione0_B.cp1 = 0.0;
    calibrazione0_B.sp1 = 0.0;
    calibrazione0_B.sqrt_g = 0.0;
    calibrazione0_B.Product11 = 0.0;
    calibrazione0_B.Product4 = 0.0;
    calibrazione0_B.Product12 = 0.0;
    calibrazione0_B.sqrt_i = 0.0;
    calibrazione0_B.Merge[0] = 0.0;
    calibrazione0_B.Merge[1] = 0.0;
    calibrazione0_B.Sum1 = 0.0;
    calibrazione0_B.Sum2 = 0.0;
    calibrazione0_B.Sum3 = 0.0;
    calibrazione0_B.Sum5 = 0.0;
    calibrazione0_B.Merge_j[0] = 0.0;
    calibrazione0_B.Merge_j[1] = 0.0;
    calibrazione0_B.Product2 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&calibrazione0_DWork, 0,
                sizeof(D_Work_calibrazione0));
  calibrazione0_DWork.UnitDelay1_DSTATE[0] = 0.0;
  calibrazione0_DWork.UnitDelay1_DSTATE[1] = 0.0;
  calibrazione0_DWork.UnitDelay1_DSTATE_d = 0.0;
  calibrazione0_DWork.UnitDelay3_DSTATE = 0.0;
  calibrazione0_DWork.UnitDelay2_DSTATE_b = 0.0;
  calibrazione0_DWork.UnitDelay4_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      calibrazione0_DWork.UnitDelay_DSTATE_o[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      calibrazione0_DWork.UnitDelay_DSTATE_b[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      calibrazione0_DWork.UnitDelay_DSTATE_m[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      calibrazione0_DWork.UnitDelay1_DSTATE_b[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 13; i++) {
      calibrazione0_DWork.UnitDelay1_DSTATE_f[i] = 0.0;
    }
  }

  calibrazione0_DWork.otime_PreviousInput = 0.0;
  calibrazione0_DWork.olon_PreviousInput = 0.0;
  calibrazione0_DWork.olat_PreviousInput = 0.0;
  calibrazione0_DWork.oalt_PreviousInput = 0.0;

  /* external inputs */
  calibrazione0_U.posizione[0] = 0.0;
  calibrazione0_U.posizione[1] = 0.0;
  calibrazione0_U.posizione[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 168; i++) {
      calibrazione0_U.mag_x[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 168; i++) {
      calibrazione0_U.mag_y[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 168; i++) {
      calibrazione0_U.mag_z[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 504; i++) {
      calibrazione0_U.w[i] = 0.0;
    }
  }

  /* external outputs */
  {
    int_T i;
    for (i = 0; i < 9; i++) {
      calibrazione0_Y.G[i] = 0.0;
    }
  }

  calibrazione0_Y.b[0] = 0.0;
  calibrazione0_Y.b[1] = 0.0;
  calibrazione0_Y.b[2] = 0.0;
  calibrazione0_Y.W[0] = 0.0;
  calibrazione0_Y.W[1] = 0.0;
  calibrazione0_Y.W[2] = 0.0;

  {
    int32_T i;

    /* Start for Enabled SubSystem: '<S11>/Convert from geodetic to  spherical coordinates ' */
    /* Start for Iterator SubSystem: '<S15>/For Iterator Subsystem' */
    /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
    calibrazione0_DWork.UnitDelay1_DSTATE[0] = calibrazione0_P.UnitDelay1_X0_e;
    calibrazione0_DWork.UnitDelay1_DSTATE[1] = calibrazione0_P.UnitDelay1_X0_e;

    /* End of Start for SubSystem: '<S15>/For Iterator Subsystem' */

    /* VirtualOutportStart for Outport: '<S15>/sp[13]' */
    calibrazione0_B.sp1 = calibrazione0_P.sp13_Y0[0];
    calibrazione0_B.sp2 = calibrazione0_P.sp13_Y0[1];

    /* VirtualOutportStart for Outport: '<S15>/cp[13]' */
    calibrazione0_B.cp1 = calibrazione0_P.cp13_Y0[0];
    calibrazione0_B.cp2 = calibrazione0_P.cp13_Y0[1];
    for (i = 0; i < 11; i++) {
      /* VirtualOutportStart for Outport: '<S15>/sp[13]' */
      calibrazione0_B.Assignment[i] = calibrazione0_P.sp13_Y0[i + 2];
      calibrazione0_B.Assignment1[i] = calibrazione0_P.cp13_Y0[i + 2];
    }

    /* End of Start for SubSystem: '<S11>/Convert from geodetic to  spherical coordinates ' */

    /* Start for Iterator SubSystem: '<S11>/Compute magnetic vector in spherical coordinates' */
    /* Start for Iterator SubSystem: '<S13>/For Iterator Subsystem' */
    /* Start for Enabled SubSystem: '<S21>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */
    /* Start for Enabled SubSystem: '<S21>/Time adjust the gauss coefficients' */
    for (i = 0; i < 169; i++) {
      /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
      calibrazione0_DWork.UnitDelay_DSTATE_m[i] = calibrazione0_P.UnitDelay_X0[i];

      /* InitializeConditions for UnitDelay: '<S23>/Unit Delay1' */
      calibrazione0_DWork.UnitDelay1_DSTATE_b[i] =
        calibrazione0_P.UnitDelay1_X0_k[i];

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
      calibrazione0_DWork.UnitDelay_DSTATE_o[i] =
        calibrazione0_P.UnitDelay_X0_o[i];

      /* InitializeConditions for UnitDelay: '<S51>/Unit Delay' */
      calibrazione0_DWork.UnitDelay_DSTATE_b[i] =
        calibrazione0_P.UnitDelay_X0_f[i];
    }

    /* End of Outport: '<S15>/cp[13]' */
    /* End of Start for SubSystem: '<S21>/Time adjust the gauss coefficients' */
    /* End of Start for SubSystem: '<S21>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

    /* Start for Enabled SubSystem: '<S22>/Special case - North//South Geographic Pole' */
    /* InitializeConditions for UnitDelay: '<S25>/Unit Delay1' */
    memcpy((void *)calibrazione0_DWork.UnitDelay1_DSTATE_f, (void *)
           calibrazione0_P.UnitDelay1_X0, 13U * sizeof(real_T));

    /* VirtualOutportStart for Outport: '<S25>/bpp' */
    calibrazione0_B.Product2 = calibrazione0_P.bpp_Y0;

    /* End of Start for SubSystem: '<S22>/Special case - North//South Geographic Pole' */

    /* InitializeConditions for UnitDelay: '<S22>/Unit Delay1' */
    calibrazione0_DWork.UnitDelay1_DSTATE_d = calibrazione0_P.UnitDelay1_X0_l;

    /* InitializeConditions for UnitDelay: '<S22>/Unit Delay3' */
    calibrazione0_DWork.UnitDelay3_DSTATE = calibrazione0_P.UnitDelay3_X0;

    /* InitializeConditions for UnitDelay: '<S22>/Unit Delay2' */
    calibrazione0_DWork.UnitDelay2_DSTATE_b = calibrazione0_P.UnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S22>/Unit Delay4' */
    calibrazione0_DWork.UnitDelay4_DSTATE = calibrazione0_P.UnitDelay4_X0;

    /* End of Start for SubSystem: '<S13>/For Iterator Subsystem' */
    /* End of Start for SubSystem: '<S11>/Compute magnetic vector in spherical coordinates' */
  }

  /* InitializeConditions for Memory: '<S19>/otime' */
  calibrazione0_DWork.otime_PreviousInput = calibrazione0_P.otime_X0;

  /* InitializeConditions for Memory: '<S18>/olon' */
  calibrazione0_DWork.olon_PreviousInput = calibrazione0_P.olon_X0;

  /* InitializeConditions for Memory: '<S17>/olat' */
  calibrazione0_DWork.olat_PreviousInput = calibrazione0_P.olat_X0;

  /* InitializeConditions for Memory: '<S17>/oalt' */
  calibrazione0_DWork.oalt_PreviousInput = calibrazione0_P.oalt_X0;
}

/* Model terminate function */
void calibrazione0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
