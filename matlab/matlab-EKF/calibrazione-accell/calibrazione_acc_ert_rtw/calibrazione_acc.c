/*
 * File: calibrazione_acc.c
 *
 * Code generated for Simulink model 'calibrazione_acc'.
 *
 * Model version                  : 1.50
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Tue Nov 01 13:08:29 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "calibrazione_acc.h"
#include "calibrazione_acc_private.h"

/* External inputs (root inport signals with auto storage) */
ExternalInputs_calibrazione_acc calibrazione_acc_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_calibrazione_ac calibrazione_acc_Y;

/* Real-time model */
RT_MODEL_calibrazione_acc calibrazione_acc_M_;
RT_MODEL_calibrazione_acc *const calibrazione_acc_M = &calibrazione_acc_M_;

/* Forward declaration for local functions */
static void calibrazione_acc_invNxN(const real_T x[16], real_T y[16]);
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

/* Function for MATLAB Function Block: '<S1>/acc_calibration' */
static void calibrazione_acc_invNxN(const real_T x[16], real_T y[16])
{
  int8_T p[4];
  real_T A[16];
  int8_T ipiv[4];
  int32_T mmj;
  int32_T jj;
  int32_T jp1j;
  int32_T b_j;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T b_ix;
  int32_T jy;
  int32_T ijA;
  int32_T pipk;
  int32_T c_i;
  for (b_j = 0; b_j < 16; b_j++) {
    y[b_j] = 0.0;
    A[b_j] = x[b_j];
  }

  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (b_j = 0; b_j < 3; b_j++) {
    mmj = -b_j;
    jj = b_j * 5;
    jp1j = jj + 1;
    jy = 0;
    ix = jj;
    smax = fabs(A[jj]);
    for (pipk = 2; pipk <= mmj + 4; pipk++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        jy = pipk - 1;
        smax = s;
      }
    }

    if (A[jj + jy] != 0.0) {
      if (jy != 0) {
        ipiv[b_j] = (int8_T)((b_j + jy) + 1);
        pipk = b_j + jy;
        smax = A[b_j];
        A[b_j] = A[pipk];
        A[pipk] = smax;
        b_ix = b_j + 4;
        pipk += 4;
        smax = A[b_ix];
        A[b_ix] = A[pipk];
        A[pipk] = smax;
        b_ix += 4;
        pipk += 4;
        smax = A[b_ix];
        A[b_ix] = A[pipk];
        A[pipk] = smax;
        b_ix += 4;
        pipk += 4;
        smax = A[b_ix];
        A[b_ix] = A[pipk];
        A[pipk] = smax;
      }

      ix = (jp1j + mmj) + 3;
      for (pipk = jp1j; pipk + 1 <= ix; pipk++) {
        A[pipk] /= A[jj];
      }
    }

    pipk = 3 - b_j;
    jy = jj + 4;
    for (c_i = 1; c_i <= pipk; c_i++) {
      if (A[jy] != 0.0) {
        smax = A[jy] * -1.0;
        ix = jp1j;
        b_ix = (mmj + jj) + 8;
        for (ijA = 5 + jj; ijA + 1 <= b_ix; ijA++) {
          A[ijA] += A[ix] * smax;
          ix++;
        }
      }

      jy += 4;
      jj += 4;
    }
  }

  p[0] = 1;
  p[1] = 2;
  p[2] = 3;
  p[3] = 4;
  if (ipiv[0] > 1) {
    pipk = p[ipiv[0] - 1];
    p[ipiv[0] - 1] = 1;
    p[0] = (int8_T)pipk;
  }

  if (ipiv[1] > 2) {
    pipk = p[ipiv[1] - 1];
    p[ipiv[1] - 1] = p[1];
    p[1] = (int8_T)pipk;
  }

  if (ipiv[2] > 3) {
    pipk = p[ipiv[2] - 1];
    p[ipiv[2] - 1] = p[2];
    p[2] = (int8_T)pipk;
  }

  y[(p[0] - 1) << 2] = 1.0;
  for (pipk = 0; pipk + 1 < 5; pipk++) {
    if (y[((p[0] - 1) << 2) + pipk] != 0.0) {
      for (jy = pipk + 1; jy + 1 < 5; jy++) {
        y[jy + ((p[0] - 1) << 2)] = y[((p[0] - 1) << 2) + jy] - y[((p[0] - 1) <<
          2) + pipk] * A[(pipk << 2) + jy];
      }
    }
  }

  y[1 + ((p[1] - 1) << 2)] = 1.0;
  for (pipk = 1; pipk + 1 < 5; pipk++) {
    if (y[((p[1] - 1) << 2) + pipk] != 0.0) {
      for (jy = pipk + 1; jy + 1 < 5; jy++) {
        y[jy + ((p[1] - 1) << 2)] = y[((p[1] - 1) << 2) + jy] - y[((p[1] - 1) <<
          2) + pipk] * A[(pipk << 2) + jy];
      }
    }
  }

  y[2 + ((p[2] - 1) << 2)] = 1.0;
  for (pipk = 2; pipk + 1 < 5; pipk++) {
    if (y[((p[2] - 1) << 2) + pipk] != 0.0) {
      for (jy = pipk + 1; jy + 1 < 5; jy++) {
        y[jy + ((p[2] - 1) << 2)] = y[((p[2] - 1) << 2) + jy] - y[((p[2] - 1) <<
          2) + pipk] * A[(pipk << 2) + jy];
      }
    }
  }

  y[3 + ((p[3] - 1) << 2)] = 1.0;
  for (pipk = 3; pipk + 1 < 5; pipk++) {
    if (y[((p[3] - 1) << 2) + pipk] != 0.0) {
      for (jy = pipk + 1; jy + 1 < 5; jy++) {
        y[jy + ((p[3] - 1) << 2)] = y[((p[3] - 1) << 2) + jy] - y[((p[3] - 1) <<
          2) + pipk] * A[(pipk << 2) + jy];
      }
    }
  }

  for (ix = 0; ix < 4; ix++) {
    pipk = ix << 2;
    if (y[3 + pipk] != 0.0) {
      y[3 + pipk] /= A[15];
      for (c_i = 0; c_i + 1 < 4; c_i++) {
        y[c_i + pipk] -= y[3 + pipk] * A[c_i + 12];
      }
    }

    if (y[2 + pipk] != 0.0) {
      y[2 + pipk] /= A[10];
      for (c_i = 0; c_i + 1 < 3; c_i++) {
        y[c_i + pipk] -= y[2 + pipk] * A[c_i + 8];
      }
    }

    if (y[1 + pipk] != 0.0) {
      y[1 + pipk] /= A[5];
      for (c_i = 0; c_i + 1 < 2; c_i++) {
        y[c_i + pipk] -= y[1 + pipk] * A[c_i + 4];
      }
    }

    if (y[pipk] != 0.0) {
      y[pipk] /= A[0];
      for (c_i = 0; c_i + 1 < 1; c_i++) {
        y[c_i + pipk] -= y[pipk] * A[c_i];
      }
    }
  }
}

/* Model step function */
void calibrazione_acc_step(void)
{
  real_T W[24];
  real_T X[12];
  real_T rtb_sinphi2;
  real_T rtb_Product4;
  real_T W_0[16];
  real_T tmp[16];
  int32_T i;
  real_T tmp_0[24];
  real_T tmp_1[18];
  int32_T i_0;
  int32_T i_1;

  /* Trigonometry: '<S2>/sin(phi)' incorporates:
   *  Inport: '<Root>/position'
   */
  rtb_sinphi2 = sin(calibrazione_acc_U.position[0]);

  /* Math: '<S2>/sin(phi)^2' */
  rtb_sinphi2 *= rtb_sinphi2;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S2>/First Eccentricity'
   *  Constant: '<S2>/One'
   *  Math: '<S2>/eps^2'
   *  Product: '<S2>/Product'
   */
  rtb_Product4 = calibrazione_acc_P.One_Value -
    calibrazione_acc_P.FirstEccentricity_Value *
    calibrazione_acc_P.FirstEccentricity_Value * rtb_sinphi2;

  /* Math: '<S2>/Math Function1' incorporates:
   *  Constant: '<S2>/1//2'
   */
  if ((rtb_Product4 < 0.0) && (calibrazione_acc_P.u_Value > floor
       (calibrazione_acc_P.u_Value))) {
    rtb_Product4 = -rt_powd_snf(-rtb_Product4, calibrazione_acc_P.u_Value);
  } else {
    rtb_Product4 = rt_powd_snf(rtb_Product4, calibrazione_acc_P.u_Value);
  }

  /* End of Math: '<S2>/Math Function1' */

  /* Product: '<S2>/Product4' incorporates:
   *  Constant: '<S2>/Gravity at Equator'
   *  Constant: '<S2>/Gravity formula const'
   *  Constant: '<S2>/One'
   *  Product: '<S2>/Product3'
   *  Sum: '<S2>/Sum2'
   */
  rtb_Product4 = (calibrazione_acc_P.Gravityformulaconst_Value * rtb_sinphi2 +
                  calibrazione_acc_P.One_Value) *
    calibrazione_acc_P.GravityatEquator_Value / rtb_Product4;

  /* Fcn: '<S2>/g(phi,h)' incorporates:
   *  Inport: '<Root>/position'
   */
  rtb_sinphi2 = (rtb_Product4 - (3.0877e-006 - 4.4e-009 * rtb_sinphi2) *
                 calibrazione_acc_U.position[2]) + 7.2e-014 *
    calibrazione_acc_U.position[2] * calibrazione_acc_U.position[2];

  /* MATLAB Function Block: '<S1>/acc_calibration' incorporates:
   *  Inport: '<Root>/w1'
   *  Inport: '<Root>/w2'
   *  Inport: '<Root>/w3'
   *  Inport: '<Root>/w4'
   *  Inport: '<Root>/w5'
   *  Inport: '<Root>/w6'
   */

  /* MATLAB Function 'calibrazione_acc/acc_calibration': '<S3>:1' */
  /* '<S3>:1:3' */
  /* '<S3>:1:10' */
  W[0] = calibrazione_acc_U.w1[0];
  W[6] = calibrazione_acc_U.w1[1];
  W[12] = calibrazione_acc_U.w1[2];
  W[18] = calibrazione_acc_U.w1[3];
  W[1] = calibrazione_acc_U.w2[0];
  W[7] = calibrazione_acc_U.w2[1];
  W[13] = calibrazione_acc_U.w2[2];
  W[19] = calibrazione_acc_U.w2[3];
  W[2] = calibrazione_acc_U.w3[0];
  W[8] = calibrazione_acc_U.w3[1];
  W[14] = calibrazione_acc_U.w3[2];
  W[20] = calibrazione_acc_U.w3[3];
  W[3] = calibrazione_acc_U.w4[0];
  W[9] = calibrazione_acc_U.w4[1];
  W[15] = calibrazione_acc_U.w4[2];
  W[21] = calibrazione_acc_U.w4[3];
  W[4] = calibrazione_acc_U.w5[0];
  W[10] = calibrazione_acc_U.w5[1];
  W[16] = calibrazione_acc_U.w5[2];
  W[22] = calibrazione_acc_U.w5[3];
  W[5] = calibrazione_acc_U.w6[0];
  W[11] = calibrazione_acc_U.w6[1];
  W[17] = calibrazione_acc_U.w6[2];
  W[23] = calibrazione_acc_U.w6[3];

  /* '<S3>:1:11' */
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      W_0[i + (i_0 << 2)] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        W_0[i + (i_0 << 2)] = W[6 * i + i_1] * W[6 * i_0 + i_1] + W_0[(i_0 << 2)
          + i];
      }
    }
  }

  calibrazione_acc_invNxN(W_0, tmp);
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 6; i_0++) {
      tmp_0[i + (i_0 << 2)] = 0.0;
      tmp_0[i + (i_0 << 2)] = tmp_0[(i_0 << 2) + i] + tmp[i] * W[i_0];
      tmp_0[i + (i_0 << 2)] = tmp_0[(i_0 << 2) + i] + tmp[i + 4] * W[i_0 + 6];
      tmp_0[i + (i_0 << 2)] = tmp_0[(i_0 << 2) + i] + tmp[i + 8] * W[i_0 + 12];
      tmp_0[i + (i_0 << 2)] = tmp_0[(i_0 << 2) + i] + tmp[i + 12] * W[i_0 + 18];
    }
  }

  tmp_1[0] = 0.0;
  tmp_1[6] = 0.0;
  tmp_1[12] = rtb_sinphi2;
  tmp_1[1] = 0.0;
  tmp_1[7] = 0.0;
  tmp_1[13] = -rtb_sinphi2;
  tmp_1[2] = 0.0;
  tmp_1[8] = rtb_sinphi2;
  tmp_1[14] = 0.0;
  tmp_1[3] = 0.0;
  tmp_1[9] = -rtb_sinphi2;
  tmp_1[15] = 0.0;
  tmp_1[4] = rtb_sinphi2;
  tmp_1[10] = 0.0;
  tmp_1[16] = 0.0;
  tmp_1[5] = -rtb_sinphi2;
  tmp_1[11] = 0.0;
  tmp_1[17] = 0.0;
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      X[i + (i_0 << 2)] = 0.0;
      for (i_1 = 0; i_1 < 6; i_1++) {
        X[i + (i_0 << 2)] = tmp_0[(i_1 << 2) + i] * tmp_1[6 * i_0 + i_1] + X
          [(i_0 << 2) + i];
      }
    }
  }

  /* End of MATLAB Function Block: '<S1>/acc_calibration' */

  /* Outport: '<Root>/G' incorporates:
   *  MATLAB Function Block: '<S1>/acc_calibration'
   */
  /* '<S3>:1:12' */
  /* '<S3>:1:15' */
  /* X=(inv(W'*W))*W'*Y; */
  calibrazione_acc_Y.G[0] = X[0];
  calibrazione_acc_Y.G[3] = X[4];
  calibrazione_acc_Y.G[6] = X[8];
  calibrazione_acc_Y.G[1] = X[1];
  calibrazione_acc_Y.G[4] = X[5];
  calibrazione_acc_Y.G[7] = X[9];
  calibrazione_acc_Y.G[2] = X[2];
  calibrazione_acc_Y.G[5] = X[6];
  calibrazione_acc_Y.G[8] = X[10];

  /* Outport: '<Root>/B' incorporates:
   *  MATLAB Function Block: '<S1>/acc_calibration'
   */
  calibrazione_acc_Y.B[0] = X[3];
  calibrazione_acc_Y.B[1] = X[7];
  calibrazione_acc_Y.B[2] = X[11];
}

/* Model initialize function */
void calibrazione_acc_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(calibrazione_acc_M, (NULL));

  /* external inputs */
  (void) memset((void *)&calibrazione_acc_U, 0,
                sizeof(ExternalInputs_calibrazione_acc));

  /* external outputs */
  (void) memset((void *)&calibrazione_acc_Y, 0,
                sizeof(ExternalOutputs_calibrazione_ac));
}

/* Model terminate function */
void calibrazione_acc_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
