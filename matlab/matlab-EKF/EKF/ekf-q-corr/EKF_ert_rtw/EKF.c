/*
 * File: EKF.c
 *
 * Code generated for Simulink model 'EKF'.
 *
 * Model version                  : 1.662
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Fri Feb 03 19:39:16 2012
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 9
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "EKF.h"
#include "EKF_private.h"

/* Block signals (auto storage) */
BlockIO_EKF EKF_B;

/* Block states (auto storage) */
D_Work_EKF EKF_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_EKF EKF_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_EKF EKF_Y;

/* Real-time model */
RT_MODEL_EKF EKF_M_;
RT_MODEL_EKF *const EKF_M = &EKF_M_;

/* Forward declaration for local functions */
static real_T EKF_norm(const real_T x[3]);
static real_T EKF_dot(const real_T a[3], const real_T b[3]);
static real_T EKF_det(const real_T x[9]);
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

/* Function for MATLAB Function Block: '<S6>/QUEST' */
static real_T EKF_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  boolean_T firstNonZero;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 0.0;
  firstNonZero = TRUE;
  if (x[0] != 0.0) {
    scale = fabs(x[0]);
    y = 1.0;
    firstNonZero = FALSE;
  }

  if (x[1] != 0.0) {
    absxk = fabs(x[1]);
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

  if (x[2] != 0.0) {
    absxk = fabs(x[2]);
    if (firstNonZero) {
      scale = absxk;
      y = 1.0;
    } else if (scale < absxk) {
      t = scale / absxk;
      y = y * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

/* Function for MATLAB Function Block: '<S6>/QUEST' */
static real_T EKF_dot(const real_T a[3], const real_T b[3])
{
  return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2];
}

/* Function for MATLAB Function Block: '<S6>/QUEST' */
static real_T EKF_det(const real_T x[9])
{
  real_T y;
  boolean_T isodd;
  real_T A[9];
  int8_T ipiv[3];
  int32_T mmj;
  int32_T jj;
  int32_T jp1j;
  int32_T j;
  int32_T idxmax;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T b_ix;
  int32_T jy;
  int32_T ijA;
  int32_T b_loop_ub;
  memcpy((void *)&A[0], (void *)&x[0], 9U * sizeof(real_T));
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 2; j++) {
    mmj = -j;
    jj = j << 2;
    jp1j = jj + 1;
    idxmax = 0;
    ix = jj;
    smax = fabs(A[jj]);
    for (jy = 2; jy <= mmj + 3; jy++) {
      ix++;
      s = fabs(A[ix]);
      if (s > smax) {
        idxmax = jy - 1;
        smax = s;
      }
    }

    if (A[jj + idxmax] != 0.0) {
      if (idxmax != 0) {
        ipiv[j] = (int8_T)((j + idxmax) + 1);
        ix = j + idxmax;
        smax = A[j];
        A[j] = A[ix];
        A[ix] = smax;
        b_ix = j + 3;
        ix += 3;
        smax = A[b_ix];
        A[b_ix] = A[ix];
        A[ix] = smax;
        b_ix += 3;
        ix += 3;
        smax = A[b_ix];
        A[b_ix] = A[ix];
        A[ix] = smax;
      }

      ix = (jp1j + mmj) + 2;
      for (jy = jp1j; jy + 1 <= ix; jy++) {
        A[jy] /= A[jj];
      }
    }

    ix = 2 - j;
    jy = jj + 3;
    for (idxmax = 1; idxmax <= ix; idxmax++) {
      if (A[jy] != 0.0) {
        smax = A[jy] * -1.0;
        b_ix = jp1j;
        b_loop_ub = (mmj + jj) + 6;
        for (ijA = 4 + jj; ijA + 1 <= b_loop_ub; ijA++) {
          A[ijA] += A[b_ix] * smax;
          b_ix++;
        }
      }

      jy += 3;
      jj += 3;
    }
  }

  y = A[0] * A[4] * A[8];
  isodd = FALSE;
  if (ipiv[0] > 1) {
    isodd = TRUE;
  }

  if (ipiv[1] > 2) {
    isodd = !isodd;
  }

  if (isodd) {
    y = -y;
  }

  return y;
}

/* Model step function */
void EKF_step(void)
{
  /* local block i/o variables */
  real_T rtb_PowerConversion2;
  real_T rtb_Product2_ee[16];
  real_T rtb_UnitConversion;
  real_T rtb_PowerConversion1;
  real_T rtb_Reshape1;

  /* local scratch DWork variables */
  real_T Product2_DWORK1[16];
  real_T Product2_DWORK3[16];
  real_T Product2_DWORK1_a[16];
  real_T Product2_DWORK3_m[16];
  int32_T Product2_DWORK2[4];
  int32_T Product2_DWORK2_n[4];
  real_T W[3];
  real_T S[9];
  real_T adjS[9];
  real_T X[3];
  real_T e_B[9];
  int32_T r;
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T rtb_u_o[4];
  real_T rtb_MatrixConcatenate[12];
  real_T rtb_Sum1_cs[7];
  real_T rtb_VectorConcatenate[3];
  real_T rtb_y1;
  real_T rtb_x1;
  real_T rtb_Product2_a;
  real_T rtb_Sum_g;
  boolean_T rtb_RelationalOperator;
  real_T rtb_u80deg;
  real_T rtb_u0deg;
  boolean_T rtb_RelationalOperator_n;
  real_T rtb_Gain_i;
  int32_T s40_iter;
  real_T rtb_Sum_l;
  real_T rtb_TmpSignalConversionAtSFu_am[3];
  real_T rtb_MatrixConcatenate_a[28];
  real_T rtb_MatrixConcatenate_i[28];
  real_T rtb_MatrixConcatenate_l[28];
  real_T rtb_MatrixConcatenate1[21];
  real_T rtb_Add1[3];
  real_T rtb_mag_calibrate[3];
  int32_T s89_iter;
  real_T rtb_b2;
  real_T rtb_q;
  real_T rtb_Sum1_f;
  real_T rtb_d;
  real_T rtb_Sum4;
  int32_T s48_iter;
  real_T rtb_TmpSignalConversionAtspm1In[13];
  real_T rtb_Memory1[49];
  real_T rtb_Memory[7];
  real_T rtb_q_matrix[16];
  real_T rtb_MatrixMultiply2[16];
  real_T rtb_Product4_lu[28];
  real_T rtb_Product1_pl[28];
  real_T rtb_Sum_ll[49];
  real_T rtb_tc_old[169];
  real_T Assignment_n[169];
  real_T Assignment[169];
  int32_T i;
  real_T rtb_Add_0[3];
  real_T rtb_TmpSignalConversionAtSFu__0[3];
  real_T tmp[9];
  real_T rtb_TmpSignalConversionAtSFu__1[9];
  real_T rtb_Add_1[9];
  real_T W_0[9];
  real_T rtb_VectorConcatenate_0[9];
  real_T rtb_MatrixConcatenate_0[16];
  real_T rtb_MatrixConcatenate_1[16];
  real_T rtb_MatrixConcatenate_a_0[28];
  real_T rtb_Memory_0[28];
  real_T rtb_u_o_0[4];
  real_T tmp_0[49];
  real_T rtb_Sum_ll_0[49];
  real_T tmp_1[13];
  real_T rtb_sincos_o1_k_idx;
  real_T rtb_sincos_o1_k_idx_0;
  real_T rtb_Sum1_c_idx;
  real_T rtb_gyrounbiased_idx;
  real_T rtb_gyrounbiased_idx_0;
  real_T rtb_gyrounbiased_idx_1;
  real_T rtb_sincos_o1_idx;
  real_T rtb_Sum1_c_idx_0;
  real_T rtb_Sum1_c_idx_1;
  real_T rtb_Sum1_c_idx_2;
  real_T rtb_sincos_o2_f_idx;
  real_T rtb_Saturation_idx;
  real_T rtb_Saturation_idx_0;
  real_T rtb_Saturation_idx_1;
  real_T rtb_Saturation_idx_2;
  real_T rtb_Memory_k_idx;
  real_T rtb_Memory_k_idx_0;
  real_T rtb_Memory_k_idx_1;
  int32_T qY;
  int32_T qY_0;
  int32_T qY_1;
  int32_T qY_2;
  int32_T qY_3;
  int32_T qY_4;

  /* Memory: '<S3>/Memory1' */
  memcpy((void *)&rtb_Memory1[0], (void *)EKF_DWork.Memory1_PreviousInput, 49U *
         sizeof(real_T));

  /* Memory: '<S3>/Memory' */
  for (i = 0; i < 7; i++) {
    rtb_Memory[i] = EKF_DWork.Memory_PreviousInput[i];
  }

  /* End of Memory: '<S3>/Memory' */

  /* Memory: '<S1>/Memory' */
  rtb_Memory_k_idx = EKF_DWork.Memory_PreviousInput_i[0];
  rtb_Memory_k_idx_0 = EKF_DWork.Memory_PreviousInput_i[1];
  rtb_Memory_k_idx_1 = EKF_DWork.Memory_PreviousInput_i[2];

  /* Sum: '<S1>/Add1' incorporates:
   *  Inport: '<Root>/gyro'
   *  Memory: '<S1>/Memory'
   */
  rtb_Add1[0] = EKF_U.gyro[0] - EKF_DWork.Memory_PreviousInput_i[0];
  rtb_Add1[1] = EKF_U.gyro[1] - EKF_DWork.Memory_PreviousInput_i[1];
  rtb_Add1[2] = EKF_U.gyro[2] - EKF_DWork.Memory_PreviousInput_i[2];

  /* MATLAB Function Block: '<S1>/Gyro-bias' incorporates:
   *  Inport: '<Root>/Gyro_Cal'
   */

  /* MATLAB Function 'EKF/Gyro-bias': '<S5>:1' */
  /* '<S5>:1:4' */
  rtb_gyrounbiased_idx = rtb_Add1[0] - EKF_U.Gyro_Cal[0];
  rtb_gyrounbiased_idx_0 = rtb_Add1[1] - EKF_U.Gyro_Cal[1];
  rtb_gyrounbiased_idx_1 = rtb_Add1[2] - EKF_U.Gyro_Cal[2];

  /* SignalConversion: '<S111>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function Block: '<S108>/quat_derivative'
   */
  rtb_Add1[0] = rtb_gyrounbiased_idx_1;
  rtb_Add1[1] = rtb_gyrounbiased_idx_0;
  rtb_Add1[2] = rtb_gyrounbiased_idx;

  /* MATLAB Function Block: '<S108>/quat_derivative' */

  /* MATLAB Function 'EKF/unione comp filter/complementar_filter/quat_derivative': '<S111>:1' */
  /* '<S111>:1:2' */
  /* '<S111>:1:7' */
  rtb_MatrixConcatenate_0[0] = 0.0;
  rtb_MatrixConcatenate_0[4] = -rtb_Add1[0];
  rtb_MatrixConcatenate_0[8] = -rtb_Add1[1];
  rtb_MatrixConcatenate_0[12] = -rtb_Add1[2];
  rtb_MatrixConcatenate_0[1] = rtb_Add1[0];
  rtb_MatrixConcatenate_0[5] = 0.0;
  rtb_MatrixConcatenate_0[9] = rtb_Add1[2];
  rtb_MatrixConcatenate_0[13] = -rtb_Add1[1];
  rtb_MatrixConcatenate_0[2] = rtb_Add1[1];
  rtb_MatrixConcatenate_0[6] = -rtb_Add1[2];
  rtb_MatrixConcatenate_0[10] = 0.0;
  rtb_MatrixConcatenate_0[14] = rtb_Add1[0];
  rtb_MatrixConcatenate_0[3] = rtb_Add1[2];
  rtb_MatrixConcatenate_0[7] = rtb_Add1[1];
  rtb_MatrixConcatenate_0[11] = -rtb_Add1[0];
  rtb_MatrixConcatenate_0[15] = 0.0;
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    rtb_MatrixConcatenate_1[qY_3 << 2] = rtb_MatrixConcatenate_0[qY_3 << 2] *
      0.5;
    rtb_MatrixConcatenate_1[1 + (qY_3 << 2)] = rtb_MatrixConcatenate_0[(qY_3 <<
      2) + 1] * 0.5;
    rtb_MatrixConcatenate_1[2 + (qY_3 << 2)] = rtb_MatrixConcatenate_0[(qY_3 <<
      2) + 2] * 0.5;
    rtb_MatrixConcatenate_1[3 + (qY_3 << 2)] = rtb_MatrixConcatenate_0[(qY_3 <<
      2) + 3] * 0.5;
  }

  /* End of MATLAB Function Block: '<S108>/quat_derivative' */

  /* Product: '<S108>/Product2' incorporates:
   *  MATLAB Function Block: '<S108>/quat_derivative'
   *  Memory: '<S1>/Memory1'
   */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    rtb_sincos_o2_f_idx = rtb_MatrixConcatenate_1[qY_3 + 12] *
      EKF_DWork.Memory1_PreviousInput_m[3] + (rtb_MatrixConcatenate_1[qY_3 + 8] *
      EKF_DWork.Memory1_PreviousInput_m[2] + (rtb_MatrixConcatenate_1[qY_3 + 4] *
      EKF_DWork.Memory1_PreviousInput_m[1] + rtb_MatrixConcatenate_1[qY_3] *
      EKF_DWork.Memory1_PreviousInput_m[0]));
    rtb_u_o_0[qY_3] = rtb_sincos_o2_f_idx;
  }

  /* End of Product: '<S108>/Product2' */

  /* Sum: '<S108>/Sum' incorporates:
   *  Inport: '<Root>/dt'
   *  Memory: '<S1>/Memory1'
   *  Product: '<S108>/Product2'
   */
  rtb_u_o[0] = rtb_u_o_0[0] * EKF_U.dt + EKF_DWork.Memory1_PreviousInput_m[0];
  rtb_u_o[1] = rtb_u_o_0[1] * EKF_U.dt + EKF_DWork.Memory1_PreviousInput_m[1];
  rtb_u_o[2] = rtb_u_o_0[2] * EKF_U.dt + EKF_DWork.Memory1_PreviousInput_m[2];
  rtb_u_o[3] = rtb_u_o_0[3] * EKF_U.dt + EKF_DWork.Memory1_PreviousInput_m[3];

  /* Saturate: '<S108>/Saturation' */
  rtb_Saturation_idx = rtb_u_o[0] >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o[0] <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o[0];
  rtb_Saturation_idx_0 = rtb_u_o[1] >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o[1] <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o[1];
  rtb_Saturation_idx_1 = rtb_u_o[2] >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o[2] <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o[2];
  rtb_Saturation_idx_2 = rtb_u_o[3] >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o[3] <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o[3];

  /* MATLAB Function Block: '<S1>/acc-cal' incorporates:
   *  Inport: '<Root>/Accel_Cal'
   *  Inport: '<Root>/accell'
   */

  /* MATLAB Function 'EKF/acc-cal': '<S9>:1' */
  /* '<S9>:1:4' */
  /* '<S9>:1:8' */
  /* '<S9>:1:12' */
  tmp[0] = EKF_U.Accel_Cal[0];
  tmp[3] = EKF_U.Accel_Cal[1];
  tmp[6] = EKF_U.Accel_Cal[2];
  tmp[1] = EKF_U.Accel_Cal[3];
  tmp[4] = EKF_U.Accel_Cal[4];
  tmp[7] = EKF_U.Accel_Cal[5];
  tmp[2] = EKF_U.Accel_Cal[6];
  tmp[5] = EKF_U.Accel_Cal[7];
  tmp[8] = EKF_U.Accel_Cal[8];
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_Add_0[qY_3] = tmp[qY_3 + 6] * EKF_U.accell[2] + (tmp[qY_3 + 3] *
      EKF_U.accell[1] + tmp[qY_3] * EKF_U.accell[0]);
  }

  rtb_Add1[0] = rtb_Add_0[0] + EKF_U.Accel_Cal[9];
  rtb_Add1[1] = rtb_Add_0[1] + EKF_U.Accel_Cal[10];
  rtb_Add1[2] = rtb_Add_0[2] + EKF_U.Accel_Cal[11];

  /* End of MATLAB Function Block: '<S1>/acc-cal' */

  /* MATLAB Function Block: '<S1>/mag-cal' incorporates:
   *  Inport: '<Root>/Mag_Cal'
   *  Inport: '<Root>/mag'
   */

  /* MATLAB Function 'EKF/mag-cal': '<S10>:1' */
  /* '<S10>:1:4' */
  /* '<S10>:1:8' */
  /* '<S10>:1:12' */
  tmp[0] = EKF_U.Mag_Cal[0];
  tmp[3] = EKF_U.Mag_Cal[1];
  tmp[6] = EKF_U.Mag_Cal[2];
  tmp[1] = EKF_U.Mag_Cal[3];
  tmp[4] = EKF_U.Mag_Cal[4];
  tmp[7] = EKF_U.Mag_Cal[5];
  tmp[2] = EKF_U.Mag_Cal[6];
  tmp[5] = EKF_U.Mag_Cal[7];
  tmp[8] = EKF_U.Mag_Cal[8];
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_Add_0[qY_3] = tmp[qY_3 + 6] * EKF_U.mag[2] + (tmp[qY_3 + 3] * EKF_U.mag
      [1] + tmp[qY_3] * EKF_U.mag[0]);
  }

  rtb_mag_calibrate[0] = rtb_Add_0[0] + EKF_U.Mag_Cal[9];
  rtb_mag_calibrate[1] = rtb_Add_0[1] + EKF_U.Mag_Cal[10];
  rtb_mag_calibrate[2] = rtb_Add_0[2] + EKF_U.Mag_Cal[11];

  /* End of MATLAB Function Block: '<S1>/mag-cal' */

  /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Inport: '<Root>/trig' */
  if (EKF_U.trig > 0.0) {
    if (!EKF_DWork.EnabledSubsystem_MODE) {
      EKF_DWork.EnabledSubsystem_MODE = TRUE;
    }

    /* Math: '<S29>/eps^2' incorporates:
     *  Constant: '<S29>/First Eccentricity'
     */
    rtb_y1 = EKF_P.FirstEccentricity_Value * EKF_P.FirstEccentricity_Value;

    /* Trigonometry: '<S29>/sin(phi)' incorporates:
     *  Inport: '<Root>/lat-lon-alti'
     */
    rtb_x1 = sin(EKF_U.latlonalti[0]);

    /* Math: '<S29>/sin(phi)^2' */
    rtb_x1 *= rtb_x1;

    /* Sum: '<S29>/Sum1' incorporates:
     *  Constant: '<S29>/One'
     *  Product: '<S29>/Product'
     */
    rtb_PowerConversion1 = EKF_P.One_Value - rtb_y1 * rtb_x1;

    /* Math: '<S29>/Math Function' incorporates:
     *  Constant: '<S29>/3//2'
     */
    if ((rtb_PowerConversion1 < 0.0) && (EKF_P.u_Value_h > floor(EKF_P.u_Value_h)))
    {
      rtb_UnitConversion = -rt_powd_snf(
        -rtb_PowerConversion1, EKF_P.u_Value_h);
    } else {
      rtb_UnitConversion = rt_powd_snf(
        rtb_PowerConversion1, EKF_P.u_Value_h);
    }

    /* End of Math: '<S29>/Math Function' */

    /* Math: '<S29>/Math Function1' incorporates:
     *  Constant: '<S29>/1//2'
     */
    if ((rtb_PowerConversion1 < 0.0) && (EKF_P.u_Value_e > floor(EKF_P.u_Value_e)))
    {
      rtb_PowerConversion1 = -rt_powd_snf(
        -rtb_PowerConversion1, EKF_P.u_Value_e);
    } else {
      rtb_PowerConversion1 = rt_powd_snf(
        rtb_PowerConversion1, EKF_P.u_Value_e);
    }

    /* End of Math: '<S29>/Math Function1' */

    /* Product: '<S29>/Product2' incorporates:
     *  Constant: '<S29>/Equatorial Radius'
     */
    rtb_Product2_a = EKF_P.EquatorialRadius_Value / rtb_PowerConversion1;

    /* Product: '<S29>/Product4' incorporates:
     *  Constant: '<S29>/Gravity at Equator'
     *  Constant: '<S29>/Gravity formula const'
     *  Constant: '<S29>/One'
     *  Product: '<S29>/Product3'
     *  Sum: '<S29>/Sum2'
     */
    rtb_PowerConversion1 = (EKF_P.Gravityformulaconst_Value * rtb_x1 +
      EKF_P.One_Value) * EKF_P.GravityatEquator_Value / rtb_PowerConversion1;

    /* Product: '<S29>/Product5' incorporates:
     *  Constant: '<S29>/Equatorial Radius'
     *  Constant: '<S29>/One'
     *  Product: '<S29>/Product1'
     *  Sum: '<S29>/Sum'
     */
    rtb_UnitConversion = (EKF_P.One_Value - rtb_y1) *
      EKF_P.EquatorialRadius_Value / rtb_UnitConversion * rtb_Product2_a;

    /* Fcn: '<S29>/g(phi,h)' incorporates:
     *  Inport: '<Root>/lat-lon-alti'
     */
    EKF_B.gphih = (rtb_PowerConversion1 - (3.0877e-006 - 4.4e-009 * rtb_x1) *
                   EKF_U.latlonalti[2]) + 7.2e-014 * EKF_U.latlonalti[2] *
      EKF_U.latlonalti[2];

    /* Math: '<S29>/sqrt'
     *
     * About '<S29>/sqrt':
     *  Operator: sqrt
     */
    rtb_UnitConversion = rtb_UnitConversion < 0.0 ? -sqrt(fabs
      (rtb_UnitConversion)) : sqrt(rtb_UnitConversion);

    /* Sum: '<S30>/Sum' incorporates:
     *  Constant: '<S30>/Date'
     *  Gain: '<S30>/DayToYear'
     *  Gain: '<S30>/MonthToYear'
     */
    rtb_Sum_g = (EKF_P.DayToYear_Gain * EKF_P.Date_Value[0] +
                 EKF_P.MonthToYear_Gain * EKF_P.Date_Value[1]) +
      EKF_P.Date_Value[2];

    /* Sum: '<S38>/Sum' incorporates:
     *  Constant: '<S38>/epoch'
     */
    rtb_Sum_l = rtb_Sum_g - EKF_P.epoch_Value;

    /* Memory: '<S46>/otime' */
    rtb_UnitConversion = EKF_DWork.otime_PreviousInput;

    /* RelationalOperator: '<S46>/Relational Operator' */
    rtb_RelationalOperator = (rtb_Sum_g != rtb_UnitConversion);

    /* Saturate: '<S31>/+//- 180 deg' incorporates:
     *  Inport: '<Root>/lat-lon-alti'
     */
    rtb_u80deg = EKF_U.latlonalti[1] >= EKF_P.u80deg_UpperSat ?
      EKF_P.u80deg_UpperSat : EKF_U.latlonalti[1] <= EKF_P.u80deg_LowerSat ?
      EKF_P.u80deg_LowerSat : EKF_U.latlonalti[1];

    /* Saturate: '<S31>/+//- 90 deg' incorporates:
     *  Inport: '<Root>/lat-lon-alti'
     */
    rtb_u0deg = EKF_U.latlonalti[0] >= EKF_P.u0deg_UpperSat ?
      EKF_P.u0deg_UpperSat : EKF_U.latlonalti[0] <= EKF_P.u0deg_LowerSat ?
      EKF_P.u0deg_LowerSat : EKF_U.latlonalti[0];

    /* Gain: '<S90>/Unit Conversion' */
    rtb_sincos_o1_k_idx = EKF_P.UnitConversion_Gain * rtb_u80deg;
    rtb_sincos_o1_k_idx_0 = EKF_P.UnitConversion_Gain * rtb_u0deg;

    /* Trigonometry: '<S43>/sincos' */
    rtb_sincos_o1_idx = sin(rtb_sincos_o1_k_idx_0);
    rtb_sincos_o1_k_idx_0 = cos(rtb_sincos_o1_k_idx_0);

    /* Memory: '<S45>/olon' */
    rtb_UnitConversion = EKF_DWork.olon_PreviousInput;

    /* Outputs for Enabled SubSystem: '<S38>/Convert from geodetic to  spherical coordinates ' incorporates:
     *  EnablePort: '<S42>/Enable'
     */
    /* RelationalOperator: '<S45>/Relational Operator' incorporates:
     *  Constant: '<S42>/cp[1]'
     *  Constant: '<S42>/sp[1]'
     *  Inport: '<S42>/cp[2]'
     *  Inport: '<S42>/sp[2]'
     *  Trigonometry: '<S43>/sincos'
     */
    if (rtb_u80deg != rtb_UnitConversion) {
      EKF_B.sp2 = sin(rtb_sincos_o1_k_idx);
      EKF_B.cp2 = cos(rtb_sincos_o1_k_idx);

      /* Outputs for Iterator SubSystem: '<S42>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S89>/For Iterator'
       */
      for (s89_iter = 1; (real_T)s89_iter <= EKF_P.ForIterator_IterationLimit;
           s89_iter++) {
        rtb_y1 = (real_T)s89_iter;

        /* UnitDelay: '<S89>/Unit Delay1' */
        rtb_sincos_o2_f_idx = EKF_DWork.UnitDelay1_DSTATE[0];
        rtb_sincos_o1_k_idx = EKF_DWork.UnitDelay1_DSTATE[1];

        /* Switch: '<S89>/cp[m-1] sp[m-1]' */
        if (!(rtb_y1 > EKF_P.cpm1spm1_Threshold)) {
          rtb_sincos_o2_f_idx = EKF_B.cp2;
          rtb_sincos_o1_k_idx = EKF_B.sp2;
        }

        /* End of Switch: '<S89>/cp[m-1] sp[m-1]' */

        /* Sum: '<S89>/Sum2' incorporates:
         *  Product: '<S89>/Product1'
         *  Product: '<S89>/Product2'
         */
        rtb_Product2_a = rtb_sincos_o2_f_idx * EKF_B.sp2 + rtb_sincos_o1_k_idx *
          EKF_B.cp2;
        for (i = 0; i < 11; i++) {
          /* Assignment: '<S89>/Assignment' incorporates:
           *  Constant: '<S89>/Constant'
           */
          if (s89_iter == 1) {
            EKF_B.Assignment[i] = EKF_P.Constant_Value_o[i];
          }

          /* End of Assignment: '<S89>/Assignment' */

          /* Assignment: '<S89>/Assignment1' incorporates:
           *  Constant: '<S89>/Constant1'
           */
          if (s89_iter == 1) {
            EKF_B.Assignment1[i] = EKF_P.Constant1_Value_j[i];
          }

          /* End of Assignment: '<S89>/Assignment1' */
        }

        /* Assignment: '<S89>/Assignment' */
        EKF_B.Assignment[(int32_T)rtb_y1 - 1] = rtb_Product2_a;

        /* Sum: '<S89>/Sum1' incorporates:
         *  Product: '<S89>/Product3'
         *  Product: '<S89>/Product8'
         */
        rtb_q = rtb_sincos_o2_f_idx * EKF_B.cp2 - rtb_sincos_o1_k_idx *
          EKF_B.sp2;

        /* Assignment: '<S89>/Assignment1' */
        EKF_B.Assignment1[(int32_T)rtb_y1 - 1] = rtb_q;

        /* Update for UnitDelay: '<S89>/Unit Delay1' */
        EKF_DWork.UnitDelay1_DSTATE[0] = rtb_q;
        EKF_DWork.UnitDelay1_DSTATE[1] = rtb_Product2_a;
      }

      /* End of Outputs for SubSystem: '<S42>/For Iterator Subsystem' */
      EKF_B.cp1 = EKF_P.cp1_Value;
      EKF_B.sp1 = EKF_P.sp1_Value;
    }

    /* End of RelationalOperator: '<S45>/Relational Operator' */
    /* End of Outputs for SubSystem: '<S38>/Convert from geodetic to  spherical coordinates ' */

    /* Memory: '<S44>/olat' */
    rtb_UnitConversion = EKF_DWork.olat_PreviousInput;

    /* RelationalOperator: '<S44>/Relational Operator' */
    rtb_RelationalOperator_n = (rtb_u0deg != rtb_UnitConversion);

    /* Gain: '<S37>/Unit Conversion' incorporates:
     *  Inport: '<Root>/lat-lon-alti'
     */
    rtb_UnitConversion = EKF_P.UnitConversion_Gain_h * EKF_U.latlonalti[2];

    /* Gain: '<S31>/Gain' incorporates:
     *  Saturate: '<S31>/0 to 1,000,000 m'
     */
    rtb_Gain_i = (rtb_UnitConversion >= EKF_P.to1000000m_UpperSat ?
                  EKF_P.to1000000m_UpperSat : rtb_UnitConversion <=
                  EKF_P.to1000000m_LowerSat ? EKF_P.to1000000m_LowerSat :
                  rtb_UnitConversion) * EKF_P.Gain_Gain_g;

    /* Memory: '<S44>/oalt' */
    rtb_PowerConversion1 = EKF_DWork.oalt_PreviousInput;

    /* Logic: '<S44>/Logical Operator' incorporates:
     *  RelationalOperator: '<S44>/Relational Operator1'
     */
    rtb_RelationalOperator_n = (rtb_RelationalOperator_n || (rtb_Gain_i !=
      rtb_PowerConversion1));

    /* Product: '<S43>/Product' */
    rtb_y1 = rtb_sincos_o1_idx * rtb_sincos_o1_idx;

    /* Product: '<S43>/Product1' */
    rtb_Product2_a = rtb_sincos_o1_k_idx_0 * rtb_sincos_o1_k_idx_0;

    /* Outputs for Enabled SubSystem: '<S38>/Convert from geodetic to  spherical coordinates' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    if (rtb_RelationalOperator_n) {
      /* Product: '<S41>/b2' incorporates:
       *  Constant: '<S41>/b'
       */
      rtb_b2 = EKF_P.b_Value * EKF_P.b_Value;

      /* Product: '<S41>/a2' incorporates:
       *  Constant: '<S41>/a'
       */
      rtb_x1 = EKF_P.a_Value * EKF_P.a_Value;

      /* Sqrt: '<S84>/sqrt' incorporates:
       *  Product: '<S84>/Product'
       *  Sum: '<S84>/Sum'
       *  Sum: '<S84>/Sum1'
       */
      rtb_q = sqrt(rtb_x1 - (rtb_x1 - rtb_b2) * rtb_y1);

      /* Product: '<S41>/Product1' */
      rtb_Sum1_f = rtb_q * rtb_Gain_i;

      /* Sqrt: '<S83>/sqrt' incorporates:
       *  Product: '<S83>/Product10'
       *  Product: '<S83>/Product9'
       *  Sum: '<S83>/Sum7'
       */
      rtb_d = sqrt(rtb_Product2_a * rtb_x1 + rtb_b2 * rtb_y1);

      /* Product: '<S86>/a4' */
      rtb_Sum4 = rtb_x1 * rtb_x1;

      /* Sqrt: '<S41>/sqrt' incorporates:
       *  Gain: '<S86>/Gain'
       *  Product: '<S86>/Product1'
       *  Product: '<S86>/Product6'
       *  Product: '<S86>/Product7'
       *  Product: '<S86>/Product8'
       *  Product: '<S86>/b4'
       *  Sum: '<S86>/Sum5'
       *  Sum: '<S86>/Sum6'
       *  Sum: '<S86>/Sum9'
       */
      EKF_B.sqrt_h = sqrt((rtb_Sum4 - (rtb_Sum4 - rtb_b2 * rtb_b2) * rtb_y1) /
                          (rtb_q * rtb_q) + (EKF_P.Gain_Gain_j * rtb_Sum1_f +
        rtb_Gain_i * rtb_Gain_i));

      /* Product: '<S81>/Product11' incorporates:
       *  Sum: '<S81>/Sum8'
       */
      EKF_B.Product11 = (rtb_Gain_i + rtb_d) / EKF_B.sqrt_h;

      /* Sum: '<S85>/Sum2' */
      rtb_Sum4 = rtb_x1 + rtb_Sum1_f;

      /* Sum: '<S85>/Sum1' */
      rtb_Sum1_f += rtb_b2;

      /* Product: '<S82>/Product4' incorporates:
       *  Product: '<S82>/Product3'
       *  Product: '<S85>/Product1'
       *  Product: '<S85>/Product2'
       *  Sqrt: '<S82>/sqrt'
       *  Sum: '<S82>/Sum3'
       */
      EKF_B.Product4 = rtb_sincos_o1_idx / sqrt(rtb_Sum4 * rtb_Sum4 /
        (rtb_Sum1_f * rtb_Sum1_f) * rtb_Product2_a + rtb_y1);

      /* Product: '<S87>/Product12' incorporates:
       *  Product: '<S87>/Product1'
       *  Sum: '<S87>/Sum1'
       */
      EKF_B.Product12 = (rtb_x1 - rtb_b2) / (EKF_B.sqrt_h * rtb_d) *
        rtb_sincos_o1_k_idx_0 * rtb_sincos_o1_idx;

      /* Sqrt: '<S88>/sqrt' incorporates:
       *  Constant: '<S88>/Constant'
       *  Product: '<S88>/Product5'
       *  Sum: '<S88>/Sum4'
       */
      EKF_B.sqrt_n = sqrt(EKF_P.Constant_Value_lx - EKF_B.Product4 *
                          EKF_B.Product4);
    }

    /* End of Outputs for SubSystem: '<S38>/Convert from geodetic to  spherical coordinates' */

    /* Product: '<S38>/aor' incorporates:
     *  Constant: '<S38>/re'
     */
    rtb_b2 = EKF_P.re_Value / EKF_B.sqrt_h;

    /* Outputs for Iterator SubSystem: '<S38>/Compute magnetic vector in spherical coordinates' incorporates:
     *  ForIterator: '<S40>/For Iterator'
     */
    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
    rtb_q = EKF_P.UnitDelay_X0_m;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay2' */
    rtb_u_o[0] = EKF_P.UnitDelay2_X0_j[0];
    rtb_u_o[1] = EKF_P.UnitDelay2_X0_j[1];
    rtb_u_o[2] = EKF_P.UnitDelay2_X0_j[2];
    rtb_u_o[3] = EKF_P.UnitDelay2_X0_j[3];
    for (s40_iter = 1; s40_iter <= EKF_P.ForIterator_IterationLimit_b; s40_iter
         ++) {
      /* Switch: '<S40>/ar(n)' incorporates:
       *  Product: '<S38>/ar'
       */
      if (!(s40_iter > EKF_P.arn_Threshold)) {
        rtb_q = rtb_b2 * rtb_b2;
      }

      /* End of Switch: '<S40>/ar(n)' */

      /* Product: '<S40>/Product8' */
      rtb_q *= rtb_b2;

      /* Sum: '<S40>/Sum' incorporates:
       *  Constant: '<S40>/Constant'
       */
      qY = s40_iter + EKF_P.Constant_Value_li;
      if ((s40_iter < 0) && ((EKF_P.Constant_Value_li < 0) && (qY >= 0))) {
        qY = MIN_int32_T;
      } else {
        if ((s40_iter > 0) && ((EKF_P.Constant_Value_li > 0) && (qY <= 0))) {
          qY = MAX_int32_T;
        }
      }

      /* End of Sum: '<S40>/Sum' */

      /* Outputs for Iterator SubSystem: '<S40>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S48>/For Iterator'
       */
      if (EKF_DWork.ForIterator_IterationMarker[4] != 0) {
        /* InitializeConditions for UnitDelay: '<S49>/Unit Delay1' */
        EKF_DWork.UnitDelay1_DSTATE_m = EKF_P.UnitDelay1_X0_c;

        /* InitializeConditions for UnitDelay: '<S49>/Unit Delay3' */
        EKF_DWork.UnitDelay3_DSTATE = EKF_P.UnitDelay3_X0;

        /* InitializeConditions for UnitDelay: '<S49>/Unit Delay2' */
        EKF_DWork.UnitDelay2_DSTATE_f = EKF_P.UnitDelay2_X0;

        /* InitializeConditions for UnitDelay: '<S49>/Unit Delay4' */
        EKF_DWork.UnitDelay4_DSTATE = EKF_P.UnitDelay4_X0;
      }

      for (i = 0; i < 7; i++) {
        EKF_DWork.ForIterator_IterationMarker[i] = 1U;
      }

      /* Sum: '<S40>/Sum' incorporates:
       *  Constant: '<S55>/Constant'
       *  Constant: '<S55>/Constant1'
       *  Logic: '<S55>/Logical Operator'
       *  RelationalOperator: '<S55>/Relational Operator'
       *  RelationalOperator: '<S55>/Relational Operator1'
       *  Sum: '<S48>/Sum1'
       */
      for (s48_iter = 1; s48_iter <= qY; s48_iter++) {
        /* Sum: '<S48>/Sum1' incorporates:
         *  Constant: '<S48>/Constant'
         */
        qY_4 = s48_iter - EKF_P.Constant_Value_i;
        if ((s48_iter < 0) && ((EKF_P.Constant_Value_i >= 0) && (qY_4 >= 0))) {
          qY_4 = MIN_int32_T;
        } else {
          if ((s48_iter >= 0) && ((EKF_P.Constant_Value_i < 0) && (qY_4 < 0))) {
            qY_4 = MAX_int32_T;
          }
        }

        /* End of Sum: '<S48>/Sum1' */

        /* Outputs for Enabled SubSystem: '<S48>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' incorporates:
         *  EnablePort: '<S50>/Enable'
         */
        if (rtb_RelationalOperator_n) {
          /* Sum: '<S50>/Sum' incorporates:
           *  Constant: '<S50>/Constant'
           *  Sum: '<S48>/Sum1'
           */
          qY_3 = s40_iter + EKF_P.Constant_Value_h;
          if ((s40_iter < 0) && ((EKF_P.Constant_Value_h < 0) && (qY_3 >= 0))) {
            qY_3 = MIN_int32_T;
          } else {
            if ((s40_iter > 0) && ((EKF_P.Constant_Value_h > 0) && (qY_3 <= 0)))
            {
              qY_3 = MAX_int32_T;
            }
          }

          qY_2 = qY_4 + EKF_P.Constant_Value_h;
          if ((qY_4 < 0) && ((EKF_P.Constant_Value_h < 0) && (qY_2 >= 0))) {
            qY_2 = MIN_int32_T;
          } else {
            if ((qY_4 > 0) && ((EKF_P.Constant_Value_h > 0) && (qY_2 <= 0))) {
              qY_2 = MAX_int32_T;
            }
          }

          /* End of Sum: '<S50>/Sum' */

          /* If: '<S50>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' incorporates:
           *  Sum: '<S48>/Sum1'
           */
          if (s40_iter == qY_4) {
            /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* Sum: '<S68>/Sum2' incorporates:
             *  Constant: '<S68>/Constant'
             */
            qY_1 = qY_4 - EKF_P.Constant_Value_las;
            if ((qY_4 < 0) && ((EKF_P.Constant_Value_las >= 0) && (qY_1 >= 0)))
            {
              qY_1 = MIN_int32_T;
            } else {
              if ((qY_4 >= 0) && ((EKF_P.Constant_Value_las < 0) && (qY_1 < 0)))
              {
                qY_1 = MAX_int32_T;
              }
            }

            /* End of Sum: '<S68>/Sum2' */

            /* Gain: '<S68>/Gain' incorporates:
             *  Sum: '<S68>/Sum2'
             */
            s89_iter = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_l, qY_1);

            /* Selector: '<S64>/Selector' incorporates:
             *  Sum: '<S68>/Sum1'
             */
            qY_1 = s40_iter + s89_iter;
            if ((s40_iter < 0) && ((s89_iter < 0) && (qY_1 >= 0))) {
              qY_1 = MIN_int32_T;
            } else {
              if ((s40_iter > 0) && ((s89_iter > 0) && (qY_1 <= 0))) {
                qY_1 = MAX_int32_T;
              }
            }

            /* End of Selector: '<S64>/Selector' */

            /* Product: '<S64>/Product1' incorporates:
             *  Selector: '<S64>/Selector'
             *  Sum: '<S68>/Sum1'
             *  UnitDelay: '<S50>/Unit Delay1'
             */
            EKF_B.Merge_o[0] = EKF_DWork.UnitDelay1_DSTATE_p[qY_1 - 1] *
              EKF_B.sqrt_n;

            /* Selector: '<S64>/Selector' incorporates:
             *  Sum: '<S68>/Sum1'
             */
            qY_1 = s40_iter + s89_iter;
            if ((s40_iter < 0) && ((s89_iter < 0) && (qY_1 >= 0))) {
              qY_1 = MIN_int32_T;
            } else {
              if ((s40_iter > 0) && ((s89_iter > 0) && (qY_1 <= 0))) {
                qY_1 = MAX_int32_T;
              }
            }

            /* End of Selector: '<S64>/Selector' */

            /* Sum: '<S64>/Sum' incorporates:
             *  Product: '<S64>/Product'
             *  Product: '<S64>/Product2'
             *  Selector: '<S64>/Selector'
             *  Selector: '<S64>/Selector1'
             *  Sum: '<S68>/Sum1'
             *  UnitDelay: '<S50>/Unit Delay1'
             */
            EKF_B.Merge_o[1] = EKF_DWork.UnitDelay_DSTATE_ka[((s40_iter - 1) *
              13 + qY_4) - 1] * EKF_B.sqrt_n +
              EKF_DWork.UnitDelay1_DSTATE_p[qY_1 - 1] * EKF_B.Product4;

            /* End of Outputs for SubSystem: '<S50>/If Action Subsystem' */
          } else if ((s40_iter == 1) && (qY_4 == 0)) {
            /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S65>/Action Port'
             */
            /* Selector: '<S65>/Selector' incorporates:
             *  Gain: '<S70>/Gain'
             *  Sum: '<S70>/Sum1'
             */
            r = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_la, 0);
            qY_1 = 1 + r;
            if ((r > 0) && (qY_1 <= 0)) {
              qY_1 = MAX_int32_T;
            }

            /* End of Selector: '<S65>/Selector' */

            /* Product: '<S65>/Product3' incorporates:
             *  Selector: '<S65>/Selector'
             *  Sum: '<S70>/Sum1'
             *  UnitDelay: '<S50>/Unit Delay1'
             */
            EKF_B.Merge_o[0] = EKF_DWork.UnitDelay1_DSTATE_p[qY_1 - 1] *
              EKF_B.Product4;

            /* Selector: '<S65>/Selector1' incorporates:
             *  Constant: '<S71>/Constant'
             *  Sum: '<S71>/Sum'
             */
            qY_1 = EKF_P.Constant_Value_lase;

            /* Selector: '<S65>/Selector' incorporates:
             *  Gain: '<S70>/Gain'
             *  Sum: '<S70>/Sum1'
             */
            r = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_la, 0);
            qY_0 = 1 + r;
            if ((r > 0) && (qY_0 <= 0)) {
              qY_0 = MAX_int32_T;
            }

            /* End of Selector: '<S65>/Selector' */

            /* Sum: '<S65>/Sum' incorporates:
             *  Product: '<S65>/Product'
             *  Product: '<S65>/Product2'
             *  Selector: '<S65>/Selector'
             *  Selector: '<S65>/Selector1'
             *  Sum: '<S70>/Sum1'
             *  Sum: '<S71>/Sum'
             *  UnitDelay: '<S50>/Unit Delay1'
             */
            EKF_B.Merge_o[1] = EKF_DWork.UnitDelay_DSTATE_ka[qY_1 - 1] *
              EKF_B.Product4 - EKF_DWork.UnitDelay1_DSTATE_p[qY_0 - 1] *
              EKF_B.sqrt_n;

            /* End of Outputs for SubSystem: '<S50>/If Action Subsystem1' */
          } else {
            if ((s40_iter > 1) && (s40_iter != qY_4)) {
              /* Outputs for IfAction SubSystem: '<S50>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S66>/Action Port'
               */
              /* Sum: '<S74>/Sum' incorporates:
               *  Constant: '<S74>/Constant'
               */
              qY_1 = qY_4 + EKF_P.Constant_Value_laseq;
              if ((qY_4 < 0) && ((EKF_P.Constant_Value_laseq < 0) && (qY_1 >= 0)))
              {
                qY_1 = MIN_int32_T;
              } else {
                if ((qY_4 > 0) && ((EKF_P.Constant_Value_laseq > 0) && (qY_1 <=
                      0))) {
                  qY_1 = MAX_int32_T;
                }
              }

              s89_iter = qY_1 - 1;

              /* End of Sum: '<S74>/Sum' */

              /* Sum: '<S74>/Sum2' incorporates:
               *  Constant: '<S74>/Constant1'
               */
              qY_1 = s40_iter - EKF_P.Constant1_Value_la;
              if ((EKF_P.Constant1_Value_la < 0) && (qY_1 < 0)) {
                qY_1 = MAX_int32_T;
              }

              /* End of Sum: '<S74>/Sum2' */

              /* Product: '<S66>/Product' incorporates:
               *  Selector: '<S66>/Selector1'
               */
              rtb_y1 = EKF_DWork.UnitDelay_DSTATE_ka[(s40_iter - 1) * 13 +
                s89_iter] * EKF_B.Product4;

              /* Sum: '<S75>/Sum2' incorporates:
               *  Constant: '<S75>/Constant1'
               */
              qY_0 = s40_iter - EKF_P.Constant1_Value_las;
              if ((EKF_P.Constant1_Value_las < 0) && (qY_0 < 0)) {
                qY_0 = MAX_int32_T;
              }

              /* End of Sum: '<S75>/Sum2' */

              /* Switch: '<S66>/Switch' incorporates:
               *  Constant: '<S66>/Constant'
               *  DataTypeConversion: '<S75>/Data Type Conversion'
               *  RelationalOperator: '<S75>/Relational Operator'
               *  Selector: '<S66>/Selector1'
               *  Sum: '<S74>/Sum2'
               *  Sum: '<S75>/Sum2'
               */
              if ((real_T)(qY_0 >= qY_4) > EKF_P.Switch_Threshold) {
                rtb_Product2_a = EKF_DWork.UnitDelay_DSTATE_ka[(qY_1 - 1) * 13 +
                  s89_iter];
              } else {
                rtb_Product2_a = EKF_P.Constant_Value_la;
              }

              /* End of Switch: '<S66>/Switch' */

              /* Sum: '<S73>/Sum' incorporates:
               *  Constant: '<S73>/Constant'
               */
              qY_1 = s40_iter + EKF_P.Constant_Value_laseqo;
              if ((EKF_P.Constant_Value_laseqo > 0) && (qY_1 <= 0)) {
                qY_1 = MAX_int32_T;
              }

              qY_0 = qY_4 + EKF_P.Constant_Value_laseqo;
              if ((qY_4 < 0) && ((EKF_P.Constant_Value_laseqo < 0) && (qY_0 >= 0)))
              {
                qY_0 = MIN_int32_T;
              } else {
                if ((qY_4 > 0) && ((EKF_P.Constant_Value_laseqo > 0) && (qY_0 <=
                      0))) {
                  qY_0 = MAX_int32_T;
                }
              }

              /* End of Sum: '<S73>/Sum' */

              /* Product: '<S66>/Product1' incorporates:
               *  Constant: '<S66>/k[13][13]'
               *  Selector: '<S66>/Selector2'
               *  Sum: '<S73>/Sum'
               */
              rtb_x1 = EKF_P.k1313_Value_l[((qY_1 - 1) * 13 + qY_0) - 1] *
                rtb_Product2_a;

              /* Gain: '<S72>/Gain' */
              s89_iter = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_las, qY_4);

              /* Sum: '<S76>/Sum2' incorporates:
               *  Constant: '<S76>/Constant1'
               */
              r = s40_iter - EKF_P.Constant1_Value_laseq;
              if ((EKF_P.Constant1_Value_laseq < 0) && (r < 0)) {
                r = MAX_int32_T;
              }

              /* End of Sum: '<S76>/Sum2' */

              /* Switch: '<S66>/Switch1' incorporates:
               *  Constant: '<S66>/Constant1'
               *  DataTypeConversion: '<S76>/Data Type Conversion'
               *  RelationalOperator: '<S76>/Relational Operator'
               *  Selector: '<S66>/Selector'
               *  Sum: '<S72>/Sum1'
               *  Sum: '<S76>/Sum2'
               *  UnitDelay: '<S50>/Unit Delay1'
               */
              if ((real_T)(r >= qY_4) > EKF_P.Switch1_Threshold) {
                /* Selector: '<S66>/Selector' incorporates:
                 *  Constant: '<S72>/Constant1'
                 *  Sum: '<S72>/Sum1'
                 *  Sum: '<S72>/Sum2'
                 */
                r = s40_iter - EKF_P.Constant1_Value_lase;
                if ((EKF_P.Constant1_Value_lase < 0) && (r < 0)) {
                  r = MAX_int32_T;
                }

                i = r + s89_iter;
                if ((r < 0) && ((s89_iter < 0) && (i >= 0))) {
                  i = MIN_int32_T;
                } else {
                  if ((r > 0) && ((s89_iter > 0) && (i <= 0))) {
                    i = MAX_int32_T;
                  }
                }

                /* End of Selector: '<S66>/Selector' */
                rtb_Product2_a = EKF_DWork.UnitDelay1_DSTATE_p[i - 1];
              } else {
                rtb_Product2_a = EKF_P.Constant1_Value_l;
              }

              /* End of Switch: '<S66>/Switch1' */

              /* Selector: '<S66>/Selector' incorporates:
               *  Sum: '<S72>/Sum1'
               */
              r = s40_iter + s89_iter;
              if ((s89_iter > 0) && (r <= 0)) {
                r = MAX_int32_T;
              }

              /* End of Selector: '<S66>/Selector' */

              /* Sum: '<S66>/Sum' incorporates:
               *  Product: '<S66>/Product4'
               *  Selector: '<S66>/Selector'
               *  Sum: '<S72>/Sum1'
               *  UnitDelay: '<S50>/Unit Delay1'
               */
              EKF_B.Merge_o[1] = (rtb_y1 - EKF_DWork.UnitDelay1_DSTATE_p[r - 1] *
                                  EKF_B.sqrt_n) - rtb_x1;

              /* Selector: '<S66>/Selector' incorporates:
               *  Sum: '<S72>/Sum1'
               */
              r = s40_iter + s89_iter;
              if ((s89_iter > 0) && (r <= 0)) {
                r = MAX_int32_T;
              }

              /* End of Selector: '<S66>/Selector' */

              /* Sum: '<S66>/Sum1' incorporates:
               *  Constant: '<S66>/k[13][13]'
               *  Product: '<S66>/Product2'
               *  Product: '<S66>/Product3'
               *  Selector: '<S66>/Selector'
               *  Selector: '<S66>/Selector2'
               *  Sum: '<S72>/Sum1'
               *  Sum: '<S73>/Sum'
               *  UnitDelay: '<S50>/Unit Delay1'
               */
              EKF_B.Merge_o[0] = EKF_DWork.UnitDelay1_DSTATE_p[r - 1] *
                EKF_B.Product4 - EKF_P.k1313_Value_l[((qY_1 - 1) * 13 + qY_0) -
                1] * rtb_Product2_a;

              /* End of Outputs for SubSystem: '<S50>/If Action Subsystem2' */
            }
          }

          /* End of If: '<S50>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' */

          /* Assignment: '<S50>/Assignment' incorporates:
           *  Sum: '<S50>/Sum'
           *  UnitDelay: '<S50>/Unit Delay'
           */
          if (EKF_DWork.ForIterator_IterationMarker[2] < 2) {
            EKF_DWork.ForIterator_IterationMarker[2] = 2U;
            memcpy((void *)(&EKF_B.Assignment_k[0]), (void *)
                   EKF_DWork.UnitDelay_DSTATE_ka, 169U * sizeof(real_T));
          }

          EKF_B.Assignment_k[(qY_2 + 13 * (qY_3 - 1)) - 1] = EKF_B.Merge_o[1];

          /* End of Assignment: '<S50>/Assignment' */

          /* Assignment: '<S50>/Assignment_snorm' incorporates:
           *  Constant: '<S67>/Constant'
           *  Gain: '<S67>/Gain'
           *  Sum: '<S50>/Sum'
           *  Sum: '<S67>/Sum1'
           *  Sum: '<S67>/Sum2'
           *  UnitDelay: '<S50>/Unit Delay1'
           */
          if (EKF_DWork.ForIterator_IterationMarker[3] < 2) {
            EKF_DWork.ForIterator_IterationMarker[3] = 2U;
            memcpy((void *)(&EKF_B.Assignment_snorm[0]), (void *)
                   EKF_DWork.UnitDelay1_DSTATE_p, 169U * sizeof(real_T));
          }

          qY_1 = qY_2 - EKF_P.Constant_Value_op;
          if ((qY_2 < 0) && ((EKF_P.Constant_Value_op >= 0) && (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((qY_2 >= 0) && ((EKF_P.Constant_Value_op < 0) && (qY_1 < 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          EKF_B.Assignment_snorm[(int32_T)((real_T)qY_3 + (real_T)
            mul_s32_s32_s32_sat(EKF_P.Gain_Gain_oa, qY_1)) - 1] = EKF_B.Merge_o
            [0];
          for (i = 0; i < 169; i++) {
            /* Update for UnitDelay: '<S50>/Unit Delay' */
            EKF_DWork.UnitDelay_DSTATE_ka[i] = EKF_B.Assignment_k[i];

            /* Update for UnitDelay: '<S50>/Unit Delay1' */
            EKF_DWork.UnitDelay1_DSTATE_p[i] = EKF_B.Assignment_snorm[i];
          }

          /* End of Assignment: '<S50>/Assignment_snorm' */
        }

        /* End of Outputs for SubSystem: '<S48>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

        /* Sum: '<S49>/Sum' incorporates:
         *  Constant: '<S49>/Constant'
         *  Sum: '<S48>/Sum1'
         */
        qY_3 = s40_iter + EKF_P.Constant_Value_d;
        if ((s40_iter < 0) && ((EKF_P.Constant_Value_d < 0) && (qY_3 >= 0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((s40_iter > 0) && ((EKF_P.Constant_Value_d > 0) && (qY_3 <= 0))) {
            qY_3 = MAX_int32_T;
          }
        }

        qY_2 = qY_4 + EKF_P.Constant_Value_d;
        if ((qY_4 < 0) && ((EKF_P.Constant_Value_d < 0) && (qY_2 >= 0))) {
          qY_2 = MIN_int32_T;
        } else {
          if ((qY_4 > 0) && ((EKF_P.Constant_Value_d > 0) && (qY_2 <= 0))) {
            qY_2 = MAX_int32_T;
          }
        }

        /* End of Sum: '<S49>/Sum' */

        /* Selector: '<S49>/dp[n][m]' incorporates:
         *  Sum: '<S49>/Sum'
         */
        rtb_y1 = EKF_B.Assignment_k[((qY_3 - 1) * 13 + qY_2) - 1];

        /* Outputs for Enabled SubSystem: '<S48>/Time adjust the gauss coefficients' incorporates:
         *  EnablePort: '<S51>/Enable'
         */
        if (rtb_RelationalOperator) {
          /* Outputs for Atomic SubSystem: '<S51>/If Action Subsystem' */
          /* Sum: '<S77>/Sum1' incorporates:
           *  Constant: '<S77>/Constant1'
           *  Sum: '<S48>/Sum1'
           */
          qY_3 = qY_4 + EKF_P.Constant1_Value_b;
          if ((qY_4 < 0) && ((EKF_P.Constant1_Value_b < 0) && (qY_3 >= 0))) {
            qY_3 = MIN_int32_T;
          } else {
            if ((qY_4 > 0) && ((EKF_P.Constant1_Value_b > 0) && (qY_3 <= 0))) {
              qY_3 = MAX_int32_T;
            }
          }

          s89_iter = qY_3 - 1;

          /* End of Sum: '<S77>/Sum1' */

          /* Sum: '<S77>/Sum2' incorporates:
           *  Constant: '<S77>/Constant'
           */
          qY_3 = s40_iter + EKF_P.Constant_Value_f;
          if ((s40_iter < 0) && ((EKF_P.Constant_Value_f < 0) && (qY_3 >= 0))) {
            qY_3 = MIN_int32_T;
          } else {
            if ((s40_iter > 0) && ((EKF_P.Constant_Value_f > 0) && (qY_3 <= 0)))
            {
              qY_3 = MAX_int32_T;
            }
          }

          i = qY_3 - 1;

          /* End of Sum: '<S77>/Sum2' */
          /* End of Outputs for SubSystem: '<S51>/If Action Subsystem' */

          /* Assignment: '<S51>/Assignment' incorporates:
           *  Constant: '<S51>/c[maxdef][maxdef]'
           *  Constant: '<S51>/cd[maxdef][maxdef]'
           *  Product: '<S77>/Product'
           *  Selector: '<S77>/c[m][n]'
           *  Selector: '<S77>/cd[m][n]'
           *  Sum: '<S77>/Sum'
           *  UnitDelay: '<S51>/Unit Delay'
           */
          if (EKF_DWork.ForIterator_IterationMarker[5] < 2) {
            EKF_DWork.ForIterator_IterationMarker[5] = 2U;
            memcpy((void *)&Assignment_n[0], (void *)
                   EKF_DWork.UnitDelay_DSTATE_o, 169U * sizeof(real_T));
          }

          /* Outputs for Atomic SubSystem: '<S51>/If Action Subsystem' */
          Assignment_n[s89_iter + 13 * i] = EKF_P.cdmaxdefmaxdef_Value[13 * i +
            s89_iter] * rtb_Sum_l + EKF_P.cmaxdefmaxdef_Value[13 * i + s89_iter];

          /* End of Assignment: '<S51>/Assignment' */
          /* End of Outputs for SubSystem: '<S51>/If Action Subsystem' */

          /* Switch: '<S78>/tc_old' incorporates:
           *  Constant: '<S78>/zeros(maxdef+1,maxdef+1)'
           *  UnitDelay: '<S78>/Unit Delay'
           */
          for (i = 0; i < 169; i++) {
            if (s40_iter > EKF_P.tc_old_Threshold) {
              rtb_tc_old[i] = EKF_DWork.UnitDelay_DSTATE_k[i];
            } else {
              rtb_tc_old[i] = EKF_P.zerosmaxdef1maxdef1_Value[i];
            }
          }

          /* End of Switch: '<S78>/tc_old' */

          /* If: '<S78>/If' incorporates:
           *  Sum: '<S48>/Sum1'
           */
          if (qY_4 != 0) {
            /* Outputs for IfAction SubSystem: '<S78>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S79>/Action Port'
             */
            /* Sum: '<S79>/Sum2' incorporates:
             *  Constant: '<S79>/Constant'
             */
            qY_3 = s40_iter + EKF_P.Constant_Value_ks;
            if ((s40_iter < 0) && ((EKF_P.Constant_Value_ks < 0) && (qY_3 >= 0)))
            {
              qY_3 = MIN_int32_T;
            } else {
              if ((s40_iter > 0) && ((EKF_P.Constant_Value_ks > 0) && (qY_3 <= 0)))
              {
                qY_3 = MAX_int32_T;
              }
            }

            s89_iter = qY_3 - 1;

            /* End of Sum: '<S79>/Sum2' */

            /* Assignment: '<S79>/Assignment2' incorporates:
             *  Constant: '<S51>/c[maxdef][maxdef]'
             *  Constant: '<S51>/cd[maxdef][maxdef]'
             *  Product: '<S79>/Product'
             *  Selector: '<S79>/c[m][n]'
             *  Selector: '<S79>/cd[m][n]'
             *  Sum: '<S79>/Sum'
             */
            if (EKF_DWork.ForIterator_IterationMarker[6] < 2) {
              EKF_DWork.ForIterator_IterationMarker[6] = 2U;
              memcpy((void *)&Assignment[0], (void *)&rtb_tc_old[0], 169U *
                     sizeof(real_T));
            }

            Assignment[s89_iter + 13 * (qY_4 - 1)] = EKF_P.cdmaxdefmaxdef_Value
              [(qY_4 - 1) * 13 + s89_iter] * rtb_Sum_l +
              EKF_P.cmaxdefmaxdef_Value[(qY_4 - 1) * 13 + s89_iter];

            /* End of Assignment: '<S79>/Assignment2' */

            /* Gain: '<S79>/Gain' */
            for (i = 0; i < 169; i++) {
              rtb_tc_old[i] = EKF_P.Gain_Gain * Assignment[i];
            }

            /* End of Gain: '<S79>/Gain' */
            /* End of Outputs for SubSystem: '<S78>/If Action Subsystem1' */
          } else {
          }

          for (i = 0; i < 169; i++) {
            /* Sum: '<S51>/Sum2' */
            EKF_B.Sum2_c[i] = Assignment_n[i] + rtb_tc_old[i];

            /* Update for UnitDelay: '<S51>/Unit Delay' */
            EKF_DWork.UnitDelay_DSTATE_o[i] = Assignment_n[i];

            /* Update for UnitDelay: '<S78>/Unit Delay' */
            EKF_DWork.UnitDelay_DSTATE_k[i] = rtb_tc_old[i];
          }

          /* End of If: '<S78>/If' */
        }

        /* End of Outputs for SubSystem: '<S48>/Time adjust the gauss coefficients' */

        /* Sum: '<S54>/Sum4' incorporates:
         *  Constant: '<S54>/Constant1'
         *  Sum: '<S48>/Sum1'
         */
        rtb_Product2_a = (real_T)qY_4 + EKF_P.Constant1_Value_p;

        /* Selector: '<S54>/cp[m+1]' incorporates:
         *  SignalConversion: '<S54>/TmpSignal ConversionAtcp[m+1]Inport1'
         */
        tmp_1[0] = EKF_B.cp1;
        tmp_1[1] = EKF_B.cp2;

        /* SignalConversion: '<S54>/TmpSignal ConversionAtsp[m+1]Inport1' */
        rtb_TmpSignalConversionAtspm1In[0] = EKF_B.sp1;
        rtb_TmpSignalConversionAtspm1In[1] = EKF_B.sp2;
        for (qY_3 = 0; qY_3 < 11; qY_3++) {
          /* Selector: '<S54>/cp[m+1]' incorporates:
           *  SignalConversion: '<S54>/TmpSignal ConversionAtcp[m+1]Inport1'
           */
          tmp_1[qY_3 + 2] = EKF_B.Assignment1[qY_3];
          rtb_TmpSignalConversionAtspm1In[qY_3 + 2] = EKF_B.Assignment[qY_3];
        }

        /* End of SignalConversion: '<S54>/TmpSignal ConversionAtsp[m+1]Inport1' */

        /* If: '<S54>/If' incorporates:
         *  Sum: '<S48>/Sum1'
         */
        if (qY_4 == 0) {
          /* Outputs for IfAction SubSystem: '<S54>/If Action Subsystem' incorporates:
           *  ActionPort: '<S60>/Action Port'
           */
          /* Sum: '<S60>/Sum' incorporates:
           *  Constant: '<S60>/Constant'
           */
          rtb_sincos_o1_k_idx = (real_T)s40_iter + EKF_P.Constant_Value_l;

          /* Product: '<S60>/Product' incorporates:
           *  Constant: '<S60>/Constant'
           *  Selector: '<S54>/cp[m+1]'
           *  Selector: '<S54>/sp[m+1]'
           *  Selector: '<S60>/Selector'
           *  Sum: '<S60>/Sum'
           */
          EKF_B.Merge[0] = EKF_B.Sum2_c[(((int32_T)rtb_sincos_o1_k_idx - 1) * 13
            + (int32_T)EKF_P.Constant_Value_l) - 1] * tmp_1[(int32_T)
            rtb_Product2_a - 1];
          EKF_B.Merge[1] = EKF_B.Sum2_c[(((int32_T)rtb_sincos_o1_k_idx - 1) * 13
            + (int32_T)EKF_P.Constant_Value_l) - 1] *
            rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_Product2_a - 1];

          /* End of Outputs for SubSystem: '<S54>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S54>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S61>/Action Port'
           */
          /* Sum: '<S62>/Sum' incorporates:
           *  Constant: '<S62>/Constant'
           */
          rtb_sincos_o1_k_idx = (real_T)s40_iter + EKF_P.Constant_Value_p;
          rtb_sincos_o1_k_idx_0 = (real_T)qY_4 + EKF_P.Constant_Value_p;

          /* Selector: '<S61>/Selector' */
          rtb_sincos_o2_f_idx = rtb_sincos_o1_k_idx;

          /* Product: '<S61>/Product' incorporates:
           *  Selector: '<S54>/cp[m+1]'
           *  Selector: '<S54>/sp[m+1]'
           *  Selector: '<S61>/Selector'
           */
          rtb_sincos_o1_k_idx = EKF_B.Sum2_c[(((int32_T)rtb_sincos_o1_k_idx - 1)
            * 13 + (int32_T)rtb_sincos_o1_k_idx_0) - 1] * tmp_1[(int32_T)
            rtb_Product2_a - 1];
          rtb_sincos_o1_k_idx_0 = EKF_B.Sum2_c[(((int32_T)rtb_sincos_o2_f_idx -
            1) * 13 + (int32_T)rtb_sincos_o1_k_idx_0) - 1] *
            rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_Product2_a - 1];

          /* Sum: '<S61>/Sum' incorporates:
           *  Constant: '<S63>/Constant'
           *  Product: '<S61>/Product1'
           *  Selector: '<S54>/sp[m+1]'
           *  Selector: '<S61>/Selector1'
           *  Sum: '<S63>/Sum'
           */
          EKF_B.Merge[0] = EKF_B.Sum2_c[((qY_4 - 1) * 13 + (int32_T)((real_T)
            s40_iter + EKF_P.Constant_Value_k)) - 1] *
            rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_Product2_a - 1] +
            rtb_sincos_o1_k_idx;

          /* Sum: '<S61>/Sum1' incorporates:
           *  Constant: '<S63>/Constant'
           *  Product: '<S61>/Product1'
           *  Selector: '<S54>/cp[m+1]'
           *  Selector: '<S61>/Selector1'
           *  Sum: '<S63>/Sum'
           */
          EKF_B.Merge[1] = rtb_sincos_o1_k_idx_0 - EKF_B.Sum2_c[((qY_4 - 1) * 13
            + (int32_T)((real_T)s40_iter + EKF_P.Constant_Value_k)) - 1] *
            tmp_1[(int32_T)rtb_Product2_a - 1];

          /* End of Outputs for SubSystem: '<S54>/If Action Subsystem1' */
        }

        /* End of If: '<S54>/If' */

        /* Selector: '<S49>/snorm[n+m*13]' incorporates:
         *  Constant: '<S53>/Constant'
         *  Gain: '<S53>/Gain'
         *  Sum: '<S48>/Sum1'
         *  Sum: '<S53>/Sum1'
         */
        qY_3 = EKF_P.Constant_Value_opp + s40_iter;
        if ((EKF_P.Constant_Value_opp < 0) && ((s40_iter < 0) && (qY_3 >= 0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((EKF_P.Constant_Value_opp > 0) && ((s40_iter > 0) && (qY_3 <= 0)))
          {
            qY_3 = MAX_int32_T;
          }
        }

        r = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_e, qY_4);
        qY_2 = qY_3 + r;
        if ((qY_3 < 0) && ((r < 0) && (qY_2 >= 0))) {
          qY_2 = MIN_int32_T;
        } else {
          if ((qY_3 > 0) && ((r > 0) && (qY_2 <= 0))) {
            qY_2 = MAX_int32_T;
          }
        }

        /* End of Selector: '<S49>/snorm[n+m*13]' */

        /* Product: '<S49>/par' incorporates:
         *  Selector: '<S49>/snorm[n+m*13]'
         *  Sum: '<S53>/Sum1'
         */
        rtb_Product2_a = EKF_B.Assignment_snorm[qY_2 - 1] * rtb_q;

        /* Sum: '<S49>/Sum4' incorporates:
         *  Constant: '<S49>/Constant1'
         *  Sum: '<S48>/Sum1'
         */
        qY_3 = s40_iter + EKF_P.Constant1_Value_bs;
        if ((s40_iter < 0) && ((EKF_P.Constant1_Value_bs < 0) && (qY_3 >= 0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((s40_iter > 0) && ((EKF_P.Constant1_Value_bs > 0) && (qY_3 <= 0)))
          {
            qY_3 = MAX_int32_T;
          }
        }

        qY_2 = qY_4 + EKF_P.Constant1_Value_bs;
        if ((qY_4 < 0) && ((EKF_P.Constant1_Value_bs < 0) && (qY_2 >= 0))) {
          qY_2 = MIN_int32_T;
        } else {
          if ((qY_4 > 0) && ((EKF_P.Constant1_Value_bs > 0) && (qY_2 <= 0))) {
            qY_2 = MAX_int32_T;
          }
        }

        /* End of Sum: '<S49>/Sum4' */

        /* Outputs for Enabled SubSystem: '<S49>/Special case - North//South Geographic Pole' incorporates:
         *  EnablePort: '<S52>/Enable'
         */
        if ((EKF_B.sqrt_n == EKF_P.Constant1_Value_n) &&
            (EKF_P.Constant_Value_kh == qY_4)) {
          if (!EKF_DWork.SpecialcaseNorthSouthGeographic) {
            EKF_DWork.SpecialcaseNorthSouthGeographic = TRUE;
          }

          /* If: '<S52>/n ==1' */
          if (s40_iter == 1) {
            /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S56>/Action Port'
             */
            /* Assignment: '<S56>/Assignment2' incorporates:
             *  Constant: '<S56>/Constant'
             *  Selector: '<S56>/pp[n-1]'
             *  Sum: '<S56>/Sum2'
             *  UnitDelay: '<S52>/Unit Delay1'
             */
            if (EKF_DWork.ForIterator_IterationMarker[0] < 2) {
              EKF_DWork.ForIterator_IterationMarker[0] = 2U;
              memcpy((void *)(&EKF_B.Assignment2_nk[0]), (void *)
                     EKF_DWork.UnitDelay1_DSTATE_p4, 13U * sizeof(real_T));
            }

            EKF_B.Assignment2_nk[(int32_T)(1.0 + EKF_P.Constant_Value_c) - 1] =
              EKF_DWork.UnitDelay1_DSTATE_p4[0];

            /* End of Assignment: '<S56>/Assignment2' */
            /* End of Outputs for SubSystem: '<S52>/If Action Subsystem1' */
          } else {
            /* Outputs for IfAction SubSystem: '<S52>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S57>/Action Port'
             */
            /* Sum: '<S59>/Sum' incorporates:
             *  Constant: '<S59>/Constant'
             */
            qY_1 = s40_iter + EKF_P.Constant_Value_cg;
            if ((s40_iter < 0) && ((EKF_P.Constant_Value_cg < 0) && (qY_1 >= 0)))
            {
              qY_1 = MIN_int32_T;
            } else {
              if ((s40_iter > 0) && ((EKF_P.Constant_Value_cg > 0) && (qY_1 <= 0)))
              {
                qY_1 = MAX_int32_T;
              }
            }

            qY_0 = qY_4 + EKF_P.Constant_Value_cg;
            if ((qY_4 < 0) && ((EKF_P.Constant_Value_cg < 0) && (qY_0 >= 0))) {
              qY_0 = MIN_int32_T;
            } else {
              if ((qY_4 > 0) && ((EKF_P.Constant_Value_cg > 0) && (qY_0 <= 0)))
              {
                qY_0 = MAX_int32_T;
              }
            }

            /* End of Sum: '<S59>/Sum' */

            /* Assignment: '<S57>/Assignment2' incorporates:
             *  Constant: '<S57>/Constant'
             *  Sum: '<S57>/Sum2'
             *  UnitDelay: '<S52>/Unit Delay1'
             */
            if (EKF_DWork.ForIterator_IterationMarker[1] < 2) {
              EKF_DWork.ForIterator_IterationMarker[1] = 2U;
              memcpy((void *)(&EKF_B.Assignment2_n[0]), (void *)
                     EKF_DWork.UnitDelay1_DSTATE_p4, 13U * sizeof(real_T));
            }

            qY_4 = s40_iter + EKF_P.Constant_Value_cgz;
            if ((s40_iter < 0) && ((EKF_P.Constant_Value_cgz < 0) && (qY_4 >= 0)))
            {
              qY_4 = MIN_int32_T;
            } else {
              if ((s40_iter > 0) && ((EKF_P.Constant_Value_cgz > 0) && (qY_4 <=
                    0))) {
                qY_4 = MAX_int32_T;
              }
            }

            /* End of Assignment: '<S57>/Assignment2' */

            /* Selector: '<S57>/pp[n-2] pp[n-1]' incorporates:
             *  Constant: '<S58>/Constant1'
             *  Sum: '<S58>/Sum2'
             */
            r = s40_iter - EKF_P.Constant1_Value_c;
            if ((s40_iter < 0) && ((EKF_P.Constant1_Value_c >= 0) && (r >= 0)))
            {
              r = MIN_int32_T;
            } else {
              if ((s40_iter >= 0) && ((EKF_P.Constant1_Value_c < 0) && (r < 0)))
              {
                r = MAX_int32_T;
              }
            }

            /* End of Selector: '<S57>/pp[n-2] pp[n-1]' */

            /* Assignment: '<S57>/Assignment2' incorporates:
             *  Constant: '<S57>/k[13][13]'
             *  Product: '<S57>/Product1'
             *  Product: '<S57>/Product2'
             *  Selector: '<S57>/Selector2'
             *  Selector: '<S57>/pp[n-2] pp[n-1]'
             *  Sum: '<S57>/Sum1'
             *  Sum: '<S57>/Sum2'
             *  Sum: '<S58>/Sum2'
             *  Sum: '<S59>/Sum'
             *  UnitDelay: '<S52>/Unit Delay1'
             */
            EKF_B.Assignment2_n[qY_4 - 1] =
              EKF_DWork.UnitDelay1_DSTATE_p4[s40_iter - 1] * EKF_B.Product4 -
              EKF_P.k1313_Value[((qY_1 - 1) * 13 + qY_0) - 1] *
              EKF_DWork.UnitDelay1_DSTATE_p4[r - 1];

            /* End of Outputs for SubSystem: '<S52>/If Action Subsystem2' */
          }

          /* End of If: '<S52>/n ==1' */

          /* SignalConversion: '<S52>/TmpSignal ConversionAtpp[n]Inport1' incorporates:
           *  UnitDelay: '<S52>/Unit Delay1'
           */
          rtb_TmpSignalConversionAtspm1In[0] = EKF_DWork.UnitDelay1_DSTATE_p4[0];
          rtb_TmpSignalConversionAtspm1In[1] = EKF_B.Assignment2_nk[1];
          memcpy((void *)&rtb_TmpSignalConversionAtspm1In[2], (void *)
                 (&EKF_B.Assignment2_n[2]), 11U * sizeof(real_T));

          /* Product: '<S52>/Product2' incorporates:
           *  Constant: '<S52>/Constant'
           *  Constant: '<S52>/Constant1'
           *  Selector: '<S52>/pp[n]'
           *  Sum: '<S52>/Sum2'
           */
          EKF_B.Product2 = rtb_TmpSignalConversionAtspm1In[(int32_T)((real_T)
            s40_iter + EKF_P.Constant1_Value) - 1] * rtb_q *
            EKF_P.Constant_Value_a * EKF_B.Merge[1];

          /* Update for UnitDelay: '<S52>/Unit Delay1' */
          memcpy((void *)EKF_DWork.UnitDelay1_DSTATE_p4, (void *)
                 &rtb_TmpSignalConversionAtspm1In[0], 13U * sizeof(real_T));
        } else {
          if (EKF_DWork.SpecialcaseNorthSouthGeographic) {
            /* Disable for Outport: '<S52>/bpp' */
            EKF_B.Product2 = EKF_P.bpp_Y0;
            EKF_DWork.SpecialcaseNorthSouthGeographic = FALSE;
          }
        }

        /* End of Outputs for SubSystem: '<S49>/Special case - North//South Geographic Pole' */

        /* Sum: '<S49>/Sum1' incorporates:
         *  Constant: '<S55>/Constant'
         *  Constant: '<S55>/Constant1'
         *  Logic: '<S55>/Logical Operator'
         *  Product: '<S49>/Product'
         *  RelationalOperator: '<S55>/Relational Operator'
         *  RelationalOperator: '<S55>/Relational Operator1'
         *  Sum: '<S48>/Sum1'
         *  UnitDelay: '<S49>/Unit Delay1'
         */
        EKF_B.Sum1 = EKF_DWork.UnitDelay1_DSTATE_m - EKF_B.Merge[0] * rtb_y1 *
          rtb_q;

        /* Sum: '<S49>/Sum2' incorporates:
         *  Constant: '<S49>/fm'
         *  Product: '<S49>/Product1'
         *  Selector: '<S49>/fm[m]'
         *  Sum: '<S49>/Sum4'
         *  UnitDelay: '<S49>/Unit Delay3'
         */
        EKF_B.Sum2 = EKF_P.fm_Value[qY_2 - 1] * rtb_Product2_a * EKF_B.Merge[1]
          + EKF_DWork.UnitDelay3_DSTATE;

        /* Sum: '<S49>/Sum3' incorporates:
         *  Constant: '<S49>/fn'
         *  Product: '<S49>/Product2'
         *  Selector: '<S49>/fn[m]'
         *  Sum: '<S49>/Sum4'
         *  UnitDelay: '<S49>/Unit Delay2'
         */
        EKF_B.Sum3 = EKF_P.fn_Value[qY_3 - 1] * rtb_Product2_a * EKF_B.Merge[0]
          + EKF_DWork.UnitDelay2_DSTATE_f;

        /* Sum: '<S49>/Sum5' incorporates:
         *  UnitDelay: '<S49>/Unit Delay4'
         */
        EKF_B.Sum5 = EKF_DWork.UnitDelay4_DSTATE + EKF_B.Product2;

        /* Update for UnitDelay: '<S49>/Unit Delay1' */
        EKF_DWork.UnitDelay1_DSTATE_m = EKF_B.Sum1;

        /* Update for UnitDelay: '<S49>/Unit Delay3' */
        EKF_DWork.UnitDelay3_DSTATE = EKF_B.Sum2;

        /* Update for UnitDelay: '<S49>/Unit Delay2' */
        EKF_DWork.UnitDelay2_DSTATE_f = EKF_B.Sum3;

        /* Update for UnitDelay: '<S49>/Unit Delay4' */
        EKF_DWork.UnitDelay4_DSTATE = EKF_B.Sum5;
      }

      /* End of Sum: '<S40>/Sum' */
      /* End of Outputs for SubSystem: '<S40>/For Iterator Subsystem' */

      /* Sum: '<S40>/Sum1' incorporates:
       *  UnitDelay: '<S40>/Unit Delay2'
       */
      rtb_Sum1_c_idx_1 = rtb_u_o[0] + EKF_B.Sum1;
      rtb_Sum1_c_idx_0 = rtb_u_o[1] + EKF_B.Sum2;
      rtb_Sum1_c_idx_2 = rtb_u_o[2] + EKF_B.Sum3;
      rtb_Sum1_c_idx = rtb_u_o[3] + EKF_B.Sum5;

      /* Update for UnitDelay: '<S40>/Unit Delay2' */
      rtb_u_o[0] = rtb_Sum1_c_idx_1;
      rtb_u_o[1] = rtb_Sum1_c_idx_0;
      rtb_u_o[2] = rtb_Sum1_c_idx_2;
      rtb_u_o[3] = rtb_Sum1_c_idx;
    }

    /* End of Outputs for SubSystem: '<S38>/Compute magnetic vector in spherical coordinates' */

    /* Switch: '<S92>/Switch' incorporates:
     *  Product: '<S92>/Product'
     */
    if (EKF_B.sqrt_n != 0.0) {
      rtb_PowerConversion1 = rtb_Sum1_c_idx_0 / EKF_B.sqrt_n;
    } else {
      rtb_PowerConversion1 = rtb_Sum1_c_idx;
    }

    /* End of Switch: '<S92>/Switch' */

    /* Sum: '<S91>/Sum1' incorporates:
     *  Product: '<S91>/Product1'
     *  Product: '<S91>/Product4'
     */
    rtb_x1 = (0.0 - EKF_B.Product11 * rtb_Sum1_c_idx_1) - rtb_Sum1_c_idx_2 *
      EKF_B.Product12;

    /* Trigonometry: '<S94>/Trigonometric Function1' */
    rtb_y1 = rt_atan2d_snf(
      rtb_PowerConversion1, rtb_x1);

    /* Sum: '<S93>/Sum1' incorporates:
     *  Product: '<S93>/Product1'
     *  Product: '<S93>/Product4'
     */
    rtb_PowerConversion2 = EKF_B.Product12 * rtb_Sum1_c_idx_1 - rtb_Sum1_c_idx_2
      * EKF_B.Product11;

    /* Sum: '<S94>/Sum' incorporates:
     *  Product: '<S94>/Product'
     *  Product: '<S94>/Product1'
     */
    rtb_PowerConversion1 = rtb_PowerConversion1 * rtb_PowerConversion1 + rtb_x1 *
      rtb_x1;

    /* Gain: '<S39>/Unit Conversion' incorporates:
     *  Gain: '<S95>/Unit Conversion'
     *  Gain: '<S96>/Unit Conversion'
     *  Sqrt: '<S94>/sqrt1'
     *  Trigonometry: '<S94>/Trigonometric Function'
     */
    rtb_sincos_o1_k_idx = EKF_P.UnitConversion_Gain_m * rtb_y1 *
      EKF_P.UnitConversion_Gain_d;
    rtb_sincos_o1_k_idx_0 = EKF_P.UnitConversion_Gain_mi * rt_atan2d_snf(
      rtb_PowerConversion2,
      sqrt(rtb_PowerConversion1)) * EKF_P.UnitConversion_Gain_d;

    /* Trigonometry: '<S35>/sincos' */
    rtb_sincos_o2_f_idx = cos(rtb_sincos_o1_k_idx);
    rtb_sincos_o1_k_idx = sin(rtb_sincos_o1_k_idx);

    /* Sum: '<S94>/Sum1' incorporates:
     *  Product: '<S94>/Product2'
     */
    rtb_PowerConversion1 += rtb_PowerConversion2 * rtb_PowerConversion2;

    /* Sqrt: '<S94>/sqrt' */
    rtb_PowerConversion1 = sqrt(rtb_PowerConversion1);

    /* Product: '<S35>/h1' incorporates:
     *  Trigonometry: '<S35>/sincos'
     */
    rtb_PowerConversion2 = cos(rtb_sincos_o1_k_idx_0) * rtb_PowerConversion1;

    /* Outport: '<Root>/WMM' incorporates:
     *  Gain: '<S30>/Gain1'
     *  Gain: '<S31>/Power Conversion'
     *  Product: '<S35>/x1'
     *  Product: '<S35>/y1'
     *  Product: '<S35>/z1'
     *  Trigonometry: '<S35>/sincos'
     */
    EKF_Y.WMM[0] = rtb_sincos_o2_f_idx * rtb_PowerConversion2 *
      EKF_P.PowerConversion_Gain * EKF_P.Gain1_Gain;
    EKF_Y.WMM[1] = rtb_sincos_o1_k_idx * rtb_PowerConversion2 *
      EKF_P.PowerConversion_Gain * EKF_P.Gain1_Gain;
    EKF_Y.WMM[2] = sin(rtb_sincos_o1_k_idx_0) * rtb_PowerConversion1 *
      EKF_P.PowerConversion_Gain * EKF_P.Gain1_Gain;

    /* Assertion: '<S32>/Assertion' incorporates:
     *  Constant: '<S32>/max_val'
     *  Constant: '<S32>/min_val'
     *  Logic: '<S32>/conjunction'
     *  RelationalOperator: '<S32>/max_relop'
     *  RelationalOperator: '<S32>/min_relop'
     */
    utAssert((EKF_P.min_val_Value <= rtb_UnitConversion) && (rtb_UnitConversion <=
              EKF_P.max_val_Value));

    /* Assertion: '<S33>/Assertion' incorporates:
     *  Constant: '<S33>/max_val'
     *  Constant: '<S33>/min_val'
     *  Inport: '<Root>/lat-lon-alti'
     *  Logic: '<S33>/conjunction'
     *  RelationalOperator: '<S33>/max_relop'
     *  RelationalOperator: '<S33>/min_relop'
     */
    utAssert((EKF_P.min_val_Value_p <= EKF_U.latlonalti[0]) &&
             (EKF_U.latlonalti[0] <= EKF_P.max_val_Value_h));

    /* Assertion: '<S34>/Assertion' incorporates:
     *  Constant: '<S34>/max_val'
     *  Constant: '<S34>/min_val'
     *  Inport: '<Root>/lat-lon-alti'
     *  Logic: '<S34>/conjunction'
     *  RelationalOperator: '<S34>/max_relop'
     *  RelationalOperator: '<S34>/min_relop'
     */
    utAssert((EKF_P.min_val_Value_i <= EKF_U.latlonalti[1]) &&
             (EKF_U.latlonalti[1] <= EKF_P.max_val_Value_m));

    /* Assertion: '<S36>/Assertion' incorporates:
     *  Constant: '<S36>/max_val'
     *  Constant: '<S36>/min_val'
     *  DataTypeConversion: '<S36>/maxtype'
     *  DataTypeConversion: '<S36>/mintype'
     *  Logic: '<S36>/conjunction'
     *  RelationalOperator: '<S36>/max_relop'
     *  RelationalOperator: '<S36>/min_relop'
     */
    utAssert((EKF_P.min_val_Value_f <= rtb_Sum_l) && (rtb_Sum_l <=
              EKF_P.max_val_Value_ht));

    /* Gain: '<S31>/Power Conversion1' */
    rtb_PowerConversion1 *= EKF_P.PowerConversion1_Gain;

    /* Gain: '<S31>/Power Conversion2' */
    rtb_PowerConversion2 *= EKF_P.PowerConversion2_Gain;

    /* Constant: '<S4>/c' */
    EKF_B.c = EKF_P.c_Value;

    /* Update for Memory: '<S46>/otime' */
    EKF_DWork.otime_PreviousInput = rtb_Sum_g;

    /* Update for Memory: '<S45>/olon' */
    EKF_DWork.olon_PreviousInput = rtb_u80deg;

    /* Update for Memory: '<S44>/olat' */
    EKF_DWork.olat_PreviousInput = rtb_u0deg;

    /* Update for Memory: '<S44>/oalt' */
    EKF_DWork.oalt_PreviousInput = rtb_Gain_i;
  } else {
    if (EKF_DWork.EnabledSubsystem_MODE) {
      /* Disable for Iterator SubSystem: '<S38>/Compute magnetic vector in spherical coordinates' */
      /* Disable for Iterator SubSystem: '<S40>/For Iterator Subsystem' */
      /* Disable for Enabled SubSystem: '<S49>/Special case - North//South Geographic Pole' */
      /* Disable for Outport: '<S52>/bpp' */
      EKF_B.Product2 = EKF_P.bpp_Y0;
      EKF_DWork.SpecialcaseNorthSouthGeographic = FALSE;

      /* End of Disable for SubSystem: '<S49>/Special case - North//South Geographic Pole' */
      /* End of Disable for SubSystem: '<S40>/For Iterator Subsystem' */
      /* End of Disable for SubSystem: '<S38>/Compute magnetic vector in spherical coordinates' */
      EKF_DWork.EnabledSubsystem_MODE = FALSE;
    }
  }

  /* End of Inport: '<Root>/trig' */
  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem' */

  /* SignalConversion: '<S98>/TmpSignal ConversionAt SFunction Inport3' incorporates:
   *  MATLAB Function Block: '<S6>/QUEST'
   */
  rtb_TmpSignalConversionAtSFu_am[0] = EKF_B.c;
  rtb_TmpSignalConversionAtSFu_am[1] = EKF_B.c;
  rtb_TmpSignalConversionAtSFu_am[2] = EKF_B.gphih;

  /* MATLAB Function Block: '<S6>/QUEST' incorporates:
   *  Inport: '<Root>/deviazione_std_accell'
   *  Inport: '<Root>/deviazione_std_magneto'
   */

  /* MATLAB Function 'EKF/QUEST_Pqq/QUEST': '<S98>:1' */
  /* '<S98>:1:3' */
  rtb_y1 = EKF_norm(rtb_Add1);
  rtb_Add1[0] /= rtb_y1;
  rtb_Add1[1] /= rtb_y1;
  rtb_Add1[2] /= rtb_y1;

  /* '<S98>:1:4' */
  rtb_y1 = EKF_norm(rtb_mag_calibrate);
  rtb_VectorConcatenate[0] = rtb_mag_calibrate[0] / rtb_y1;
  rtb_VectorConcatenate[1] = rtb_mag_calibrate[1] / rtb_y1;
  rtb_VectorConcatenate[2] = rtb_mag_calibrate[2] / rtb_y1;

  /* '<S98>:1:5' */
  rtb_y1 = EKF_norm(rtb_TmpSignalConversionAtSFu_am);
  rtb_TmpSignalConversionAtSFu_am[0] /= rtb_y1;
  rtb_TmpSignalConversionAtSFu_am[1] /= rtb_y1;
  rtb_TmpSignalConversionAtSFu_am[2] /= rtb_y1;

  /* '<S98>:1:6' */
  rtb_y1 = EKF_norm(EKF_Y.WMM);
  W[0] = EKF_Y.WMM[0] / rtb_y1;
  W[1] = EKF_Y.WMM[1] / rtb_y1;
  W[2] = EKF_Y.WMM[2] / rtb_y1;

  /* '<S98>:1:8' */
  rtb_Gain_i = rt_powd_snf(EKF_U.deviazione_std_accell, 2.0);

  /* '<S98>:1:9' */
  rtb_Sum4 = rt_powd_snf(EKF_U.deviazione_std_magneto, 2.0);

  /* '<S98>:1:10' */
  rtb_Sum_g = 1.0 / (1.0 / rtb_Gain_i + 1.0 / rtb_Sum4);

  /* '<S98>:1:11' */
  rtb_q = rtb_Sum_g / rtb_Gain_i;

  /* '<S98>:1:12' */
  rtb_d = rtb_Sum_g / rtb_Sum4;

  /* '<S98>:1:14' */
  /* '<S98>:1:15' */
  rtb_Add_0[0] = rtb_Add1[1] * rtb_VectorConcatenate[2] - rtb_Add1[2] *
    rtb_VectorConcatenate[1];
  rtb_Add_0[1] = rtb_Add1[2] * rtb_VectorConcatenate[0] - rtb_Add1[0] *
    rtb_VectorConcatenate[2];
  rtb_Add_0[2] = rtb_Add1[0] * rtb_VectorConcatenate[1] - rtb_Add1[1] *
    rtb_VectorConcatenate[0];
  rtb_TmpSignalConversionAtSFu__0[0] = rtb_TmpSignalConversionAtSFu_am[1] * W[2]
    - rtb_TmpSignalConversionAtSFu_am[2] * W[1];
  rtb_TmpSignalConversionAtSFu__0[1] = rtb_TmpSignalConversionAtSFu_am[2] * W[0]
    - rtb_TmpSignalConversionAtSFu_am[0] * W[2];
  rtb_TmpSignalConversionAtSFu__0[2] = rtb_TmpSignalConversionAtSFu_am[0] * W[1]
    - rtb_TmpSignalConversionAtSFu_am[1] * W[0];
  rtb_x1 = sqrt(2.0 * rtb_q * rtb_d * (EKF_dot(rtb_Add1, rtb_VectorConcatenate) *
    EKF_dot(rtb_TmpSignalConversionAtSFu_am, W) + EKF_norm(rtb_Add_0) * EKF_norm
                 (rtb_TmpSignalConversionAtSFu__0)) + (rt_powd_snf(rtb_q, 2.0) +
    rt_powd_snf(rtb_d, 2.0)));

  /* '<S98>:1:16' */
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_TmpSignalConversionAtSFu__1[3 * qY_3] = rtb_TmpSignalConversionAtSFu_am
      [0] * rtb_Add1[qY_3];
    rtb_TmpSignalConversionAtSFu__1[1 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFu_am[1] * rtb_Add1[qY_3];
    rtb_TmpSignalConversionAtSFu__1[2 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFu_am[2] * rtb_Add1[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_Add_1[3 * qY_3] = rtb_Add1[0] * rtb_TmpSignalConversionAtSFu_am[qY_3];
    rtb_Add_1[1 + 3 * qY_3] = rtb_Add1[1] * rtb_TmpSignalConversionAtSFu_am[qY_3];
    rtb_Add_1[2 + 3 * qY_3] = rtb_Add1[2] * rtb_TmpSignalConversionAtSFu_am[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    W_0[3 * qY_3] = W[0] * rtb_VectorConcatenate[qY_3];
    W_0[1 + 3 * qY_3] = W[1] * rtb_VectorConcatenate[qY_3];
    W_0[2 + 3 * qY_3] = W[2] * rtb_VectorConcatenate[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_VectorConcatenate_0[3 * qY_3] = rtb_VectorConcatenate[0] * W[qY_3];
    rtb_VectorConcatenate_0[1 + 3 * qY_3] = rtb_VectorConcatenate[1] * W[qY_3];
    rtb_VectorConcatenate_0[2 + 3 * qY_3] = rtb_VectorConcatenate[2] * W[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    S[3 * qY_3] = (rtb_TmpSignalConversionAtSFu__1[3 * qY_3] + rtb_Add_1[3 *
                   qY_3]) * rtb_q + (W_0[3 * qY_3] + rtb_VectorConcatenate_0[3 *
      qY_3]) * rtb_d;
    S[1 + 3 * qY_3] = (rtb_TmpSignalConversionAtSFu__1[3 * qY_3 + 1] +
                       rtb_Add_1[3 * qY_3 + 1]) * rtb_q + (W_0[3 * qY_3 + 1] +
      rtb_VectorConcatenate_0[3 * qY_3 + 1]) * rtb_d;
    S[2 + 3 * qY_3] = (rtb_TmpSignalConversionAtSFu__1[3 * qY_3 + 2] +
                       rtb_Add_1[3 * qY_3 + 2]) * rtb_q + (W_0[3 * qY_3 + 2] +
      rtb_VectorConcatenate_0[3 * qY_3 + 2]) * rtb_d;
  }

  /* '<S98>:1:17' */
  rtb_y1 = EKF_det(S);
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    adjS[3 * qY_3] = S[qY_3];
    adjS[1 + 3 * qY_3] = S[qY_3 + 3];
    adjS[2 + 3 * qY_3] = S[qY_3 + 6];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    e_B[3 * qY_3] = rtb_y1 * (real_T)b[qY_3];
    e_B[1 + 3 * qY_3] = (real_T)b[qY_3 + 3] * rtb_y1;
    e_B[2 + 3 * qY_3] = (real_T)b[qY_3 + 6] * rtb_y1;
  }

  i = 0;
  s40_iter = 1;
  r = 2;
  rtb_y1 = fabs(adjS[0]);
  rtb_Product2_a = fabs(adjS[1]);
  if (rtb_Product2_a > rtb_y1) {
    rtb_y1 = rtb_Product2_a;
    i = 1;
    s40_iter = 0;
  }

  if (fabs(adjS[2]) > rtb_y1) {
    i = 2;
    s40_iter = 1;
    r = 0;
  }

  adjS[s40_iter] /= adjS[i];
  adjS[r] /= adjS[i];
  adjS[3 + s40_iter] -= adjS[3 + i] * adjS[s40_iter];
  adjS[3 + r] -= adjS[3 + i] * adjS[r];
  adjS[6 + s40_iter] -= adjS[6 + i] * adjS[s40_iter];
  adjS[6 + r] -= adjS[6 + i] * adjS[r];
  if (fabs(adjS[3 + r]) > fabs(adjS[3 + s40_iter])) {
    s89_iter = s40_iter;
    s40_iter = r;
    r = s89_iter;
  }

  adjS[3 + r] /= adjS[3 + s40_iter];
  adjS[6 + r] -= adjS[3 + r] * adjS[6 + s40_iter];
  rtb_Add_1[0] = e_B[i];
  rtb_Add_1[1] = e_B[s40_iter] - rtb_Add_1[0] * adjS[s40_iter];
  rtb_Add_1[2] = (e_B[r] - rtb_Add_1[0] * adjS[r]) - adjS[3 + r] * rtb_Add_1[1];
  rtb_Add_1[2] /= adjS[6 + r];
  rtb_Add_1[0] -= adjS[6 + i] * rtb_Add_1[2];
  rtb_Add_1[1] -= adjS[6 + s40_iter] * rtb_Add_1[2];
  rtb_Add_1[1] /= adjS[3 + s40_iter];
  rtb_Add_1[0] -= adjS[3 + i] * rtb_Add_1[1];
  rtb_Add_1[0] /= adjS[i];
  rtb_Add_1[3] = e_B[i + 3];
  rtb_Add_1[4] = e_B[s40_iter + 3] - rtb_Add_1[3] * adjS[s40_iter];
  rtb_Add_1[5] = (e_B[r + 3] - rtb_Add_1[3] * adjS[r]) - adjS[3 + r] *
    rtb_Add_1[4];
  rtb_Add_1[5] /= adjS[6 + r];
  rtb_Add_1[3] -= adjS[6 + i] * rtb_Add_1[5];
  rtb_Add_1[4] -= adjS[6 + s40_iter] * rtb_Add_1[5];
  rtb_Add_1[4] /= adjS[3 + s40_iter];
  rtb_Add_1[3] -= adjS[3 + i] * rtb_Add_1[4];
  rtb_Add_1[3] /= adjS[i];
  rtb_Add_1[6] = e_B[i + 6];
  rtb_Add_1[7] = e_B[s40_iter + 6] - rtb_Add_1[6] * adjS[s40_iter];
  rtb_Add_1[8] = (e_B[r + 6] - rtb_Add_1[6] * adjS[r]) - adjS[3 + r] *
    rtb_Add_1[7];
  rtb_Add_1[8] /= adjS[6 + r];
  rtb_Add_1[6] -= adjS[6 + i] * rtb_Add_1[8];
  rtb_Add_1[7] -= adjS[6 + s40_iter] * rtb_Add_1[8];
  rtb_Add_1[7] /= adjS[3 + s40_iter];
  rtb_Add_1[6] -= adjS[3 + i] * rtb_Add_1[7];
  rtb_Add_1[6] /= adjS[i];
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    adjS[3 * qY_3] = rtb_Add_1[qY_3];
    adjS[1 + 3 * qY_3] = rtb_Add_1[qY_3 + 3];
    adjS[2 + 3 * qY_3] = rtb_Add_1[qY_3 + 6];
  }

  /* '<S98>:1:18' */
  rtb_Product2_a = ((S[0] + S[4]) + S[8]) * 0.5;

  /* '<S98>:1:19' */
  /* '<S98>:1:20' */
  /* '<S98>:1:21' */
  /* '<S98>:1:22' */
  rtb_y1 = ((adjS[0] + adjS[4]) + adjS[8]) + (rt_powd_snf(rtb_x1, 2.0) -
    rt_powd_snf(rtb_Product2_a, 2.0));

  /* '<S98>:1:23' */
  rtb_b2 = rtb_x1 - rtb_Product2_a;

  /* '<S98>:1:24' */
  rtb_Sum1_f = (rtb_x1 + rtb_Product2_a) * rtb_y1 - EKF_det(S);

  /* '<S98>:1:26' */
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    for (r = 0; r < 3; r++) {
      rtb_VectorConcatenate_0[qY_3 + 3 * r] = ((S[3 * r + 1] * S[qY_3 + 3] + S[3
        * r] * S[qY_3]) + S[3 * r + 2] * S[qY_3 + 6]) + ((real_T)b[3 * r + qY_3]
        * rtb_y1 + S[3 * r + qY_3] * rtb_b2);
    }
  }

  rtb_sincos_o1_k_idx = (rtb_TmpSignalConversionAtSFu_am[1] * rtb_Add1[2] -
    rtb_TmpSignalConversionAtSFu_am[2] * rtb_Add1[1]) * rtb_q + (W[1] *
    rtb_VectorConcatenate[2] - W[2] * rtb_VectorConcatenate[1]) * rtb_d;
  rtb_sincos_o1_k_idx_0 = (rtb_TmpSignalConversionAtSFu_am[2] * rtb_Add1[0] -
    rtb_TmpSignalConversionAtSFu_am[0] * rtb_Add1[2]) * rtb_q + (W[2] *
    rtb_VectorConcatenate[0] - W[0] * rtb_VectorConcatenate[2]) * rtb_d;
  rtb_sincos_o2_f_idx = (rtb_TmpSignalConversionAtSFu_am[0] * rtb_Add1[1] -
    rtb_TmpSignalConversionAtSFu_am[1] * rtb_Add1[0]) * rtb_q + (W[0] *
    rtb_VectorConcatenate[1] - W[1] * rtb_VectorConcatenate[0]) * rtb_d;
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    X[qY_3] = rtb_VectorConcatenate_0[qY_3 + 6] * rtb_sincos_o2_f_idx +
      (rtb_VectorConcatenate_0[qY_3 + 3] * rtb_sincos_o1_k_idx_0 +
       rtb_VectorConcatenate_0[qY_3] * rtb_sincos_o1_k_idx);
  }

  /* '<S98>:1:28' */
  rtb_x1 = 1.0 / sqrt(rt_powd_snf(rtb_Sum1_f, 2.0) + rt_powd_snf(EKF_norm(X),
    2.0));

  /* '<S98>:1:30' */
  rtb_TmpSignalConversionAtSFu__0[0] = rtb_TmpSignalConversionAtSFu_am[1] * W[2]
    - rtb_TmpSignalConversionAtSFu_am[2] * W[1];
  rtb_TmpSignalConversionAtSFu__0[1] = rtb_TmpSignalConversionAtSFu_am[2] * W[0]
    - rtb_TmpSignalConversionAtSFu_am[0] * W[2];
  rtb_TmpSignalConversionAtSFu__0[2] = rtb_TmpSignalConversionAtSFu_am[0] * W[1]
    - rtb_TmpSignalConversionAtSFu_am[1] * W[0];
  rtb_q = rt_powd_snf(EKF_norm(rtb_TmpSignalConversionAtSFu__0), -2.0);
  rtb_b2 = rtb_Sum4 - rtb_Sum_g;
  rtb_y1 = rtb_Gain_i - rtb_Sum_g;
  rtb_Product2_a = rtb_Sum_g * EKF_dot(rtb_TmpSignalConversionAtSFu_am, W);
  rtb_Sum1_c_idx_1 = rtb_x1 * X[0];
  rtb_Sum1_c_idx_0 = rtb_x1 * X[1];
  rtb_Sum1_c_idx_2 = rtb_x1 * X[2];
  rtb_Sum1_c_idx = rtb_x1 * rtb_Sum1_f;
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_Add_1[3 * qY_3] = rtb_b2 * rtb_TmpSignalConversionAtSFu_am[0] *
      rtb_TmpSignalConversionAtSFu_am[qY_3];
    rtb_Add_1[1 + 3 * qY_3] = rtb_b2 * rtb_TmpSignalConversionAtSFu_am[1] *
      rtb_TmpSignalConversionAtSFu_am[qY_3];
    rtb_Add_1[2 + 3 * qY_3] = rtb_b2 * rtb_TmpSignalConversionAtSFu_am[2] *
      rtb_TmpSignalConversionAtSFu_am[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_VectorConcatenate_0[3 * qY_3] = rtb_y1 * W[0] * W[qY_3];
    rtb_VectorConcatenate_0[1 + 3 * qY_3] = rtb_y1 * W[1] * W[qY_3];
    rtb_VectorConcatenate_0[2 + 3 * qY_3] = rtb_y1 * W[2] * W[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_TmpSignalConversionAtSFu__1[3 * qY_3] = rtb_TmpSignalConversionAtSFu_am
      [0] * W[qY_3];
    rtb_TmpSignalConversionAtSFu__1[1 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFu_am[1] * W[qY_3];
    rtb_TmpSignalConversionAtSFu__1[2 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFu_am[2] * W[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    W_0[3 * qY_3] = W[0] * rtb_TmpSignalConversionAtSFu_am[qY_3];
    W_0[1 + 3 * qY_3] = W[1] * rtb_TmpSignalConversionAtSFu_am[qY_3];
    W_0[2 + 3 * qY_3] = W[2] * rtb_TmpSignalConversionAtSFu_am[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    tmp[3 * qY_3] = (((rtb_TmpSignalConversionAtSFu__1[3 * qY_3] + W_0[3 * qY_3])
                      * rtb_Product2_a + (rtb_Add_1[3 * qY_3] +
      rtb_VectorConcatenate_0[3 * qY_3])) * rtb_q + (real_T)b[3 * qY_3] *
                     rtb_Sum_g) * 0.25;
    tmp[1 + 3 * qY_3] = (((rtb_TmpSignalConversionAtSFu__1[3 * qY_3 + 1] + W_0[3
      * qY_3 + 1]) * rtb_Product2_a + (rtb_Add_1[3 * qY_3 + 1] +
      rtb_VectorConcatenate_0[3 * qY_3 + 1])) * rtb_q + (real_T)b[3 * qY_3 + 1] *
                         rtb_Sum_g) * 0.25;
    tmp[2 + 3 * qY_3] = (((rtb_TmpSignalConversionAtSFu__1[3 * qY_3 + 2] + W_0[3
      * qY_3 + 2]) * rtb_Product2_a + (rtb_Add_1[3 * qY_3 + 2] +
      rtb_VectorConcatenate_0[3 * qY_3 + 2])) * rtb_q + (real_T)b[3 * qY_3 + 2] *
                         rtb_Sum_g) * 0.25;
  }

  memcpy((void *)&rtb_MatrixConcatenate[0], (void *)&tmp[0], 9U * sizeof(real_T));

  /* End of MATLAB Function Block: '<S6>/QUEST' */

  /* Sqrt: '<S103>/sqrt' incorporates:
   *  Product: '<S104>/Product'
   *  Product: '<S104>/Product1'
   *  Product: '<S104>/Product2'
   *  Product: '<S104>/Product3'
   *  Sum: '<S104>/Sum'
   */
  rtb_y1 = sqrt(((rtb_Sum1_c_idx * rtb_Sum1_c_idx + rtb_Sum1_c_idx_1 *
                  rtb_Sum1_c_idx_1) + rtb_Sum1_c_idx_0 * rtb_Sum1_c_idx_0) +
                rtb_Sum1_c_idx_2 * rtb_Sum1_c_idx_2);

  /* Product: '<S102>/Product' */
  rtb_Product2_a = rtb_Sum1_c_idx / rtb_y1;

  /* Product: '<S102>/Product1' */
  rtb_b2 = rtb_Sum1_c_idx_1 / rtb_y1;

  /* Product: '<S102>/Product2' */
  rtb_x1 = rtb_Sum1_c_idx_0 / rtb_y1;

  /* Product: '<S102>/Product3' */
  rtb_y1 = rtb_Sum1_c_idx_2 / rtb_y1;

  /* Fcn: '<S99>/fcn2' */
  rtb_Reshape1 = ((rtb_Product2_a * rtb_Product2_a - rtb_b2 * rtb_b2) - rtb_x1 *
                  rtb_x1) + rtb_y1 * rtb_y1;

  /* Trigonometry: '<S99>/Trigonometric Function1' incorporates:
   *  Fcn: '<S99>/fcn1'
   */
  rtb_TmpSignalConversionAtSFu_am[0] = rt_atan2d_snf((rtb_x1 * rtb_y1 -
    rtb_Product2_a * rtb_b2) * -2.0,
    rtb_Reshape1);

  /* Fcn: '<S99>/fcn3' */
  rtb_Reshape1 = (rtb_b2 * rtb_y1 + rtb_Product2_a * rtb_x1) * 2.0;

  /* Trigonometry: '<S99>/trigFcn' */
  rtb_TmpSignalConversionAtSFu_am[1] = asin(rtb_Reshape1 >= 1.0 ? 1.0 :
    rtb_Reshape1 <= -1.0 ? -1.0 : rtb_Reshape1);

  /* Fcn: '<S99>/fcn4' */
  rtb_Reshape1 = (rtb_b2 * rtb_x1 - rtb_Product2_a * rtb_y1) * -2.0;

  /* Fcn: '<S99>/fcn5' */
  rtb_Product2_a = ((rtb_Product2_a * rtb_Product2_a + rtb_b2 * rtb_b2) - rtb_x1
                    * rtb_x1) - rtb_y1 * rtb_y1;

  /* Trigonometry: '<S99>/Trigonometric Function3' */
  rtb_TmpSignalConversionAtSFu_am[2] = rt_atan2d_snf(
    rtb_Reshape1, rtb_Product2_a);

  /* Gain: '<S100>/1//2' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  rtb_sincos_o2_f_idx = rtb_TmpSignalConversionAtSFu_am[1];
  rtb_TmpSignalConversionAtSFu_am[0] *= EKF_P.u_Gain;
  rtb_TmpSignalConversionAtSFu_am[1] = EKF_P.u_Gain * rtb_sincos_o2_f_idx;
  rtb_TmpSignalConversionAtSFu_am[2] = EKF_P.u_Gain * EKF_P.Constant2_Value_g;

  /* Trigonometry: '<S100>/sincos' */
  rtb_sincos_o1_k_idx_0 = cos(rtb_TmpSignalConversionAtSFu_am[0]);
  rtb_TmpSignalConversionAtSFu_am[0] = sin(rtb_TmpSignalConversionAtSFu_am[0]);
  rtb_sincos_o1_idx = cos(rtb_TmpSignalConversionAtSFu_am[1]);
  rtb_TmpSignalConversionAtSFu_am[1] = sin(rtb_TmpSignalConversionAtSFu_am[1]);
  rtb_y1 = cos(rtb_TmpSignalConversionAtSFu_am[2]);
  rtb_TmpSignalConversionAtSFu_am[2] = sin(rtb_TmpSignalConversionAtSFu_am[2]);

  /* Fcn: '<S100>/q1' incorporates:
   *  Trigonometry: '<S100>/sincos'
   */
  rtb_Gain_i = rtb_sincos_o1_k_idx_0 * rtb_TmpSignalConversionAtSFu_am[1] *
    rtb_TmpSignalConversionAtSFu_am[2] + rtb_TmpSignalConversionAtSFu_am[0] *
    rtb_sincos_o1_idx * rtb_y1;

  /* Fcn: '<S100>/q2' incorporates:
   *  Trigonometry: '<S100>/sincos'
   */
  rtb_Sum_g = rtb_sincos_o1_k_idx_0 * rtb_TmpSignalConversionAtSFu_am[1] *
    rtb_y1 - rtb_TmpSignalConversionAtSFu_am[0] * rtb_sincos_o1_idx *
    rtb_TmpSignalConversionAtSFu_am[2];

  /* Fcn: '<S100>/q3' incorporates:
   *  Trigonometry: '<S100>/sincos'
   */
  rtb_Sum_l = rtb_sincos_o1_k_idx_0 * rtb_sincos_o1_idx *
    rtb_TmpSignalConversionAtSFu_am[2] + rtb_TmpSignalConversionAtSFu_am[0] *
    rtb_TmpSignalConversionAtSFu_am[1] * rtb_y1;

  /* Fcn: '<S100>/q0' incorporates:
   *  Trigonometry: '<S100>/sincos'
   */
  rtb_u80deg = rtb_sincos_o1_k_idx_0 * rtb_sincos_o1_idx * rtb_y1 -
    rtb_TmpSignalConversionAtSFu_am[0] * rtb_TmpSignalConversionAtSFu_am[1] *
    rtb_TmpSignalConversionAtSFu_am[2];

  /* Sum: '<S108>/Add3' incorporates:
   *  Memory: '<S108>/Memory'
   */
  rtb_u_o[0] = rtb_Gain_i - EKF_DWork.Memory_PreviousInput_o[0];
  rtb_u_o[1] = rtb_Sum_g - EKF_DWork.Memory_PreviousInput_o[1];
  rtb_u_o[2] = rtb_Sum_l - EKF_DWork.Memory_PreviousInput_o[2];
  rtb_u_o[3] = rtb_u80deg - EKF_DWork.Memory_PreviousInput_o[3];

  /* Abs: '<S108>/Abs' */
  rtb_u_o[0] = fabs(rtb_u_o[0]);
  rtb_u_o[1] = fabs(rtb_u_o[1]);
  rtb_u_o[2] = fabs(rtb_u_o[2]);
  rtb_u_o[3] = fabs(rtb_u_o[3]);

  /* MATLAB Function Block: '<S108>/correzione inversione quat' incorporates:
   *  Sum: '<S108>/Add4'
   */

  /* MATLAB Function 'EKF/unione comp filter/complementar_filter/correzione inversione quat': '<S110>:1' */
  if (((rtb_u_o[0] + rtb_u_o[1]) + rtb_u_o[2]) + rtb_u_o[3] > 1.5) {
    /* '<S110>:1:4' */
    /* '<S110>:1:5' */
    rtb_y1 = 0.85;
  } else {
    /* '<S110>:1:7' */
    rtb_y1 = 0.0;
  }

  /* End of MATLAB Function Block: '<S108>/correzione inversione quat' */

  /* Sum: '<S108>/Add2' incorporates:
   *  Inport: '<Root>/tau'
   */
  rtb_Reshape1 = EKF_U.tau + rtb_y1;

  /* Sum: '<S108>/Add' incorporates:
   *  Constant: '<S108>/Constant'
   */
  rtb_y1 = EKF_P.Constant_Value_kq - rtb_Reshape1;

  /* Sum: '<S108>/Add1' incorporates:
   *  Product: '<S108>/Product'
   *  Product: '<S108>/Product1'
   */
  rtb_u_o[0] = rtb_Saturation_idx * rtb_y1 + rtb_Reshape1 * rtb_Gain_i;
  rtb_u_o[1] = rtb_Saturation_idx_0 * rtb_y1 + rtb_Reshape1 * rtb_Sum_g;
  rtb_u_o[2] = rtb_Saturation_idx_1 * rtb_y1 + rtb_Reshape1 * rtb_Sum_l;
  rtb_u_o[3] = rtb_Saturation_idx_2 * rtb_y1 + rtb_Reshape1 * rtb_u80deg;

  /* MATLAB Function Block: '<S6>/q_matrix' */

  /* MATLAB Function 'EKF/QUEST_Pqq/q_matrix': '<S101>:1' */
  /* '<S101>:1:3' */
  rtb_q_matrix[0] = rtb_Sum1_c_idx;
  rtb_q_matrix[4] = -rtb_Sum1_c_idx_2;
  rtb_q_matrix[8] = rtb_Sum1_c_idx_0;
  rtb_q_matrix[12] = rtb_Sum1_c_idx_1;
  rtb_q_matrix[1] = rtb_Sum1_c_idx_2;
  rtb_q_matrix[5] = rtb_Sum1_c_idx;
  rtb_q_matrix[9] = -rtb_Sum1_c_idx_1;
  rtb_q_matrix[13] = rtb_Sum1_c_idx_0;
  rtb_q_matrix[2] = -rtb_Sum1_c_idx_0;
  rtb_q_matrix[6] = rtb_Sum1_c_idx_1;
  rtb_q_matrix[10] = rtb_Sum1_c_idx;
  rtb_q_matrix[14] = rtb_Sum1_c_idx_2;
  rtb_q_matrix[3] = -rtb_Sum1_c_idx_1;
  rtb_q_matrix[7] = -rtb_Sum1_c_idx_0;
  rtb_q_matrix[11] = -rtb_Sum1_c_idx_2;
  rtb_q_matrix[15] = rtb_Sum1_c_idx;

  /* Constant: '<S6>/Constant' */
  rtb_MatrixConcatenate[9] = EKF_P.Constant_Value_n[0];
  rtb_MatrixConcatenate[10] = EKF_P.Constant_Value_n[1];
  rtb_MatrixConcatenate[11] = EKF_P.Constant_Value_n[2];

  /* Product: '<S6>/Matrix Multiply1' incorporates:
   *  Concatenate: '<S6>/Matrix Concatenate1'
   *  Constant: '<S6>/Constant1'
   *  Math: '<S6>/ 1'
   */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    rtb_MatrixConcatenate_0[qY_3 << 2] = rtb_MatrixConcatenate[3 * qY_3];
    rtb_MatrixConcatenate_0[1 + (qY_3 << 2)] = rtb_MatrixConcatenate[3 * qY_3 +
      1];
    rtb_MatrixConcatenate_0[2 + (qY_3 << 2)] = rtb_MatrixConcatenate[3 * qY_3 +
      2];
  }

  rtb_MatrixConcatenate_0[3] = EKF_P.Constant1_Value_k[0];
  rtb_MatrixConcatenate_0[7] = EKF_P.Constant1_Value_k[1];
  rtb_MatrixConcatenate_0[11] = EKF_P.Constant1_Value_k[2];
  rtb_MatrixConcatenate_0[15] = EKF_P.Constant1_Value_k[3];

  /* End of Product: '<S6>/Matrix Multiply1' */

  /* Product: '<S6>/Matrix Multiply2' incorporates:
   *  Math: '<S6>/ '
   *  Product: '<S6>/Matrix Multiply1'
   */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_MatrixConcatenate_1[qY_3 + (r << 2)] = 0.0;
      rtb_MatrixConcatenate_1[qY_3 + (r << 2)] = rtb_MatrixConcatenate_1[(r << 2)
        + qY_3] + rtb_MatrixConcatenate_0[qY_3] * rtb_q_matrix[r];
      rtb_MatrixConcatenate_1[qY_3 + (r << 2)] = rtb_MatrixConcatenate_1[(r << 2)
        + qY_3] + rtb_MatrixConcatenate_0[qY_3 + 4] * rtb_q_matrix[r + 4];
      rtb_MatrixConcatenate_1[qY_3 + (r << 2)] = rtb_MatrixConcatenate_1[(r << 2)
        + qY_3] + rtb_MatrixConcatenate_0[qY_3 + 8] * rtb_q_matrix[r + 8];
      rtb_MatrixConcatenate_1[qY_3 + (r << 2)] = rtb_MatrixConcatenate_1[(r << 2)
        + qY_3] + rtb_MatrixConcatenate_0[qY_3 + 12] * rtb_q_matrix[r + 12];
    }
  }

  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_MatrixMultiply2[qY_3 + (r << 2)] = 0.0;
      rtb_MatrixMultiply2[qY_3 + (r << 2)] = rtb_MatrixMultiply2[(r << 2) + qY_3]
        + rtb_MatrixConcatenate_1[r << 2] * rtb_q_matrix[qY_3];
      rtb_MatrixMultiply2[qY_3 + (r << 2)] = rtb_MatrixConcatenate_1[(r << 2) +
        1] * rtb_q_matrix[qY_3 + 4] + rtb_MatrixMultiply2[(r << 2) + qY_3];
      rtb_MatrixMultiply2[qY_3 + (r << 2)] = rtb_MatrixConcatenate_1[(r << 2) +
        2] * rtb_q_matrix[qY_3 + 8] + rtb_MatrixMultiply2[(r << 2) + qY_3];
      rtb_MatrixMultiply2[qY_3 + (r << 2)] = rtb_MatrixConcatenate_1[(r << 2) +
        3] * rtb_q_matrix[qY_3 + 12] + rtb_MatrixMultiply2[(r << 2) + qY_3];
    }
  }

  /* End of Product: '<S6>/Matrix Multiply2' */

  /* Outputs for Atomic SubSystem: '<S3>/Correction' */
  /* Constant: '<S19>/R matrix' */
  memcpy((void *)&rtb_MatrixConcatenate_a[0], (void *)EKF_P.Rmatrix_Value,
         sizeof(real_T) << 4U);

  /* Constant: '<S19>/R matrix1' */
  memcpy((void *)&rtb_MatrixConcatenate_a[16], (void *)EKF_P.Rmatrix1_Value, 12U
         * sizeof(real_T));

  /* Math: '<S17>/Math Function' */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Product4_lu[r + 7 * qY_3] = rtb_MatrixConcatenate_a[(r << 2) + qY_3];
    }
  }

  /* End of Math: '<S17>/Math Function' */

  /* Product: '<S17>/Product3' */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_MatrixConcatenate_a_0[qY_3 + (r << 2)] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_MatrixConcatenate_a_0[qY_3 + (r << 2)] = rtb_MatrixConcatenate_a[(i <<
          2) + qY_3] * rtb_Memory1[7 * r + i] + rtb_MatrixConcatenate_a_0[(r <<
          2) + qY_3];
      }
    }
  }

  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_Product2_ee[qY_3 + (r << 2)] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Product2_ee[qY_3 + (r << 2)] = rtb_MatrixConcatenate_a_0[(i << 2) +
          qY_3] * rtb_Product4_lu[7 * r + i] + rtb_Product2_ee[(r << 2) + qY_3];
      }
    }
  }

  /* End of Product: '<S17>/Product3' */

  /* Sum: '<S17>/Sum' */
  for (qY_3 = 0; qY_3 < 16; qY_3++) {
    rtb_Product2_ee[qY_3] += rtb_MatrixMultiply2[qY_3];
  }

  /* End of Sum: '<S17>/Sum' */

  /* Product: '<S17>/Product2' */
  {
    static const int_T dims[3] = { 4, 4, 4 };

    rt_MatDivRR_Dbl(rtb_Product2_ee, rtb_Product2_ee,
                    &EKF_DWork.Product2_DWORK4[0], (real_T*)&Product2_DWORK1[0],
                    &Product2_DWORK2[0], (real_T*)&Product2_DWORK3[0],
                    &dims[0]);
  }

  /* Product: '<S17>/Product4' incorporates:
   *  Product: '<S17>/Product1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = rtb_Memory1[7 * i + qY_3] *
          rtb_Product4_lu[7 * r + i] + rtb_MatrixConcatenate_a_0[7 * r + qY_3];
      }
    }
  }

  /* End of Product: '<S17>/Product4' */

  /* Product: '<S13>/Product1' incorporates:
   *  Inport: '<Root>/GPS_Reset'
   *  Product: '<S17>/Product4'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_Memory_0[qY_3 + 7 * r] = 0.0;
      rtb_Memory_0[qY_3 + 7 * r] = rtb_Memory_0[7 * r + qY_3] +
        rtb_Product2_ee[r << 2] * rtb_MatrixConcatenate_a_0[qY_3];
      rtb_Memory_0[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 1] *
        rtb_MatrixConcatenate_a_0[qY_3 + 7] + rtb_Memory_0[7 * r + qY_3];
      rtb_Memory_0[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 2] *
        rtb_MatrixConcatenate_a_0[qY_3 + 14] + rtb_Memory_0[7 * r + qY_3];
      rtb_Memory_0[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 3] *
        rtb_MatrixConcatenate_a_0[qY_3 + 21] + rtb_Memory_0[7 * r + qY_3];
    }
  }

  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Product1_pl[r + 7 * qY_3] = rtb_Memory_0[7 * qY_3 + r] *
        EKF_U.GPS_Reset;
    }
  }

  /* End of Product: '<S13>/Product1' */

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  Inport: '<Root>/GPS_Reset'
   */
  rtb_RelationalOperator_n = !(EKF_U.GPS_Reset != 0.0);

  /* Math: '<S16>/Math Function' */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Product4_lu[r + 7 * qY_3] = rtb_MatrixConcatenate_a[(r << 2) + qY_3];
    }
  }

  /* End of Math: '<S16>/Math Function' */

  /* Product: '<S16>/Product3' */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_MatrixConcatenate_a_0[qY_3 + (r << 2)] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_MatrixConcatenate_a_0[qY_3 + (r << 2)] = rtb_MatrixConcatenate_a[(i <<
          2) + qY_3] * rtb_Memory1[7 * r + i] + rtb_MatrixConcatenate_a_0[(r <<
          2) + qY_3];
      }
    }
  }

  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_Product2_ee[qY_3 + (r << 2)] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Product2_ee[qY_3 + (r << 2)] = rtb_MatrixConcatenate_a_0[(i << 2) +
          qY_3] * rtb_Product4_lu[7 * r + i] + rtb_Product2_ee[(r << 2) + qY_3];
      }
    }
  }

  /* End of Product: '<S16>/Product3' */

  /* Sum: '<S16>/Sum' */
  for (qY_3 = 0; qY_3 < 16; qY_3++) {
    rtb_Product2_ee[qY_3] += rtb_MatrixMultiply2[qY_3];
  }

  /* End of Sum: '<S16>/Sum' */

  /* Product: '<S16>/Product2' */
  {
    static const int_T dims[3] = { 4, 4, 4 };

    rt_MatDivRR_Dbl(rtb_Product2_ee, rtb_Product2_ee,
                    &EKF_DWork.Product2_DWORK4_k[0], (real_T*)
                    &Product2_DWORK1_a[0],
                    &Product2_DWORK2_n[0], (real_T*)&Product2_DWORK3_m[0],
                    &dims[0]);
  }

  /* Product: '<S16>/Product4' incorporates:
   *  Product: '<S16>/Product1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = rtb_Memory1[7 * i + qY_3] *
          rtb_Product4_lu[7 * r + i] + rtb_MatrixConcatenate_a_0[7 * r + qY_3];
      }
    }
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_Product4_lu[qY_3 + 7 * r] = 0.0;
      rtb_Product4_lu[qY_3 + 7 * r] = rtb_Product4_lu[7 * r + qY_3] +
        rtb_Product2_ee[r << 2] * rtb_MatrixConcatenate_a_0[qY_3];
      rtb_Product4_lu[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 1] *
        rtb_MatrixConcatenate_a_0[qY_3 + 7] + rtb_Product4_lu[7 * r + qY_3];
      rtb_Product4_lu[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 2] *
        rtb_MatrixConcatenate_a_0[qY_3 + 14] + rtb_Product4_lu[7 * r + qY_3];
      rtb_Product4_lu[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 3] *
        rtb_MatrixConcatenate_a_0[qY_3 + 21] + rtb_Product4_lu[7 * r + qY_3];
    }
  }

  /* End of Product: '<S16>/Product4' */

  /* Sum: '<S13>/Sum' incorporates:
   *  Product: '<S13>/Product2'
   */
  for (qY_3 = 0; qY_3 < 28; qY_3++) {
    rtb_Product4_lu[qY_3] = (real_T)rtb_RelationalOperator_n *
      rtb_Product4_lu[qY_3] + rtb_Product1_pl[qY_3];
  }

  /* End of Sum: '<S13>/Sum' */

  /* Constant: '<S20>/R matrix' */
  memcpy((void *)&rtb_MatrixConcatenate_i[0], (void *)EKF_P.Rmatrix_Value_h,
         sizeof(real_T) << 4U);

  /* Constant: '<S20>/R matrix1' */
  memcpy((void *)&rtb_MatrixConcatenate_i[16], (void *)EKF_P.Rmatrix1_Value_h,
         12U * sizeof(real_T));

  /* Product: '<S18>/Product1' incorporates:
   *  Product: '<S18>/Product2'
   *  Sum: '<S18>/Sum'
   */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    rtb_sincos_o2_f_idx = 0.0;
    for (r = 0; r < 7; r++) {
      rtb_sincos_o2_f_idx += rtb_MatrixConcatenate_i[(r << 2) + qY_3] *
        rtb_Memory[r];
    }

    rtb_u_o_0[qY_3] = rtb_u_o[qY_3] - rtb_sincos_o2_f_idx;
  }

  /* End of Product: '<S18>/Product1' */

  /* Sum: '<S18>/Sum1' incorporates:
   *  Product: '<S18>/Product1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum1_cs[qY_3] = (((rtb_Product4_lu[qY_3 + 7] * rtb_u_o_0[1] +
      rtb_Product4_lu[qY_3] * rtb_u_o_0[0]) + rtb_Product4_lu[qY_3 + 14] *
                          rtb_u_o_0[2]) + rtb_Product4_lu[qY_3 + 21] *
                         rtb_u_o_0[3]) + rtb_Memory[qY_3];
  }

  /* End of Sum: '<S18>/Sum1' */
  /* End of Outputs for SubSystem: '<S3>/Correction' */

  /* Sum: '<S107>/Sum' incorporates:
   *  Product: '<S107>/Product'
   *  Product: '<S107>/Product1'
   *  Product: '<S107>/Product2'
   *  Product: '<S107>/Product3'
   */
  rtb_Reshape1 = ((rtb_Sum1_cs[3] * rtb_Sum1_cs[3] + rtb_Sum1_cs[0] *
                   rtb_Sum1_cs[0]) + rtb_Sum1_cs[1] * rtb_Sum1_cs[1]) +
    rtb_Sum1_cs[2] * rtb_Sum1_cs[2];

  /* Sqrt: '<S106>/sqrt' */
  rtb_Reshape1 = sqrt(rtb_Reshape1);

  /* Product: '<S105>/Product' */
  rtb_y1 = rtb_Sum1_cs[3] / rtb_Reshape1;

  /* Product: '<S105>/Product1' */
  rtb_x1 = rtb_Sum1_cs[0] / rtb_Reshape1;

  /* Product: '<S105>/Product2' */
  rtb_b2 = rtb_Sum1_cs[1] / rtb_Reshape1;

  /* Product: '<S105>/Product3' */
  rtb_Reshape1 = rtb_Sum1_cs[2] / rtb_Reshape1;

  /* Trigonometry: '<S7>/Trigonometric Function1' incorporates:
   *  Fcn: '<S7>/fcn1'
   *  Fcn: '<S7>/fcn2'
   */
  rtb_VectorConcatenate[0] = rt_atan2d_snf(
    (rtb_b2 * rtb_Reshape1 - rtb_y1 * rtb_x1) * -2.0,
    ((rtb_y1 * rtb_y1 - rtb_x1 * rtb_x1) - rtb_b2 * rtb_b2) + rtb_Reshape1 *
    rtb_Reshape1);

  /* Trigonometry: '<S7>/trigFcn' incorporates:
   *  Fcn: '<S7>/fcn3'
   */
  rtb_sincos_o2_f_idx = (rtb_x1 * rtb_Reshape1 + rtb_y1 * rtb_b2) * 2.0;
  rtb_VectorConcatenate[1] = asin(rtb_sincos_o2_f_idx >= 1.0 ? 1.0 :
    rtb_sincos_o2_f_idx <= -1.0 ? -1.0 : rtb_sincos_o2_f_idx);

  /* Fcn: '<S7>/fcn4' */
  rtb_Product2_a = (rtb_x1 * rtb_b2 - rtb_y1 * rtb_Reshape1) * -2.0;

  /* Fcn: '<S7>/fcn5' */
  rtb_y1 = ((rtb_y1 * rtb_y1 + rtb_x1 * rtb_x1) - rtb_b2 * rtb_b2) -
    rtb_Reshape1 * rtb_Reshape1;

  /* Trigonometry: '<S7>/Trigonometric Function3' */
  rtb_VectorConcatenate[2] = rt_atan2d_snf(rtb_Product2_a, rtb_y1);

  /* Gain: '<S1>/Gain' */
  rtb_Sum4 = EKF_P.Gain_Gain_f * rtb_VectorConcatenate[1];

  /* Memory: '<S109>/Memory1' */
  rtb_Reshape1 = EKF_DWork.Memory1_PreviousInput_f;

  /* SignalConversion: '<S113>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  Gain: '<S109>/Gain'
   *  Gain: '<S109>/Gain1'
   *  Gain: '<S109>/Gain2'
   *  MATLAB Function Block: '<S109>/yaw_complementar_calculator'
   */
  rtb_Add1[0] = EKF_P.Gain1_Gain_b * rtb_gyrounbiased_idx;
  rtb_Add1[1] = EKF_P.Gain2_Gain * rtb_gyrounbiased_idx_0;
  rtb_Add1[2] = EKF_P.Gain_Gain_gj * rtb_gyrounbiased_idx_1;

  /* Sum: '<S109>/Sum' incorporates:
   *  Inport: '<Root>/dt'
   *  MATLAB Function Block: '<S109>/yaw_complementar_calculator'
   *  Memory: '<S1>/Memory2'
   *  Product: '<S109>/Product2'
   */

  /* MATLAB Function 'EKF/unione comp filter/complementar_filter_yaw/yaw_complementar_calculator': '<S113>:1' */
  /* '<S113>:1:2' */
  rtb_Reshape1 += ((rtb_Add1[2] * cos(EKF_DWork.Memory2_PreviousInput[0]) * cos
                    (EKF_DWork.Memory2_PreviousInput[1]) + rtb_Add1[0] * sin
                    (EKF_DWork.Memory2_PreviousInput[1])) + rtb_Add1[1] * sin
                   (EKF_DWork.Memory2_PreviousInput[0])) * EKF_U.dt;

  /* Saturate: '<S109>/saturation 2pi' */
  rtb_Product2_a = rtb_Reshape1 >= EKF_P.saturation2pi_UpperSat ?
    EKF_P.saturation2pi_UpperSat : rtb_Reshape1 <= EKF_P.saturation2pi_LowerSat ?
    EKF_P.saturation2pi_LowerSat : rtb_Reshape1;

  /* Gain: '<S6>/Gain' incorporates:
   *  Memory: '<S1>/Memory2'
   */
  rtb_y1 = EKF_P.Gain_Gain_o * EKF_DWork.Memory2_PreviousInput[1];

  /* MATLAB Function Block: '<S6>/MATLAB Function2' incorporates:
   *  Memory: '<S1>/Memory2'
   */

  /* MATLAB Function 'EKF/QUEST_Pqq/MATLAB Function2': '<S97>:1' */
  /* '<S97>:1:3' */
  /* '<S97>:1:7' */
  /* '<S97>:1:10' */
  rtb_d = -rt_atan2d_snf(cos(EKF_DWork.Memory2_PreviousInput[0]) *
    rtb_mag_calibrate[1] + -sin(EKF_DWork.Memory2_PreviousInput[0]) *
    rtb_mag_calibrate[2], (sin(EKF_DWork.Memory2_PreviousInput[0]) * sin(rtb_y1)
    * rtb_mag_calibrate[1] + cos(rtb_y1) * rtb_mag_calibrate[0]) + cos
    (EKF_DWork.Memory2_PreviousInput[0]) * sin(rtb_y1) * rtb_mag_calibrate[2]);

  /* Memory: '<S109>/Memory' */
  rtb_Reshape1 = EKF_DWork.Memory_PreviousInput_a;

  /* Sum: '<S109>/Add3' */
  rtb_Reshape1 = rtb_d - rtb_Reshape1;

  /* MATLAB Function Block: '<S109>/corezione passaggio 360' incorporates:
   *  Abs: '<S109>/Abs'
   */

  /* MATLAB Function 'EKF/unione comp filter/complementar_filter_yaw/corezione passaggio 360': '<S112>:1' */
  if (fabs(rtb_Reshape1) > 3.14) {
    /* '<S112>:1:4' */
    /* '<S112>:1:5' */
    rtb_y1 = 0.85;
  } else {
    /* '<S112>:1:7' */
    rtb_y1 = 0.0;
  }

  /* End of MATLAB Function Block: '<S109>/corezione passaggio 360' */

  /* Sum: '<S109>/Add2' incorporates:
   *  Inport: '<Root>/tau'
   */
  rtb_Reshape1 = EKF_U.tau + rtb_y1;

  /* Sum: '<S109>/Add1' incorporates:
   *  Constant: '<S109>/Constant'
   *  Product: '<S109>/Product'
   *  Product: '<S109>/Product1'
   *  Sum: '<S109>/Add'
   */
  rtb_x1 = (EKF_P.Constant_Value_ko - rtb_Reshape1) * rtb_Product2_a +
    rtb_Reshape1 * rtb_d;

  /* Gain: '<S1>/Gain1' */
  rtb_Sum1_f = EKF_P.Gain1_Gain_f * rtb_x1;

  /* Outport: '<Root>/eulero' incorporates:
   *  Gain: '<S2>/Unit Conversion'
   */
  EKF_Y.eulero[0] = EKF_P.UnitConversion_Gain_o * rtb_VectorConcatenate[0];
  EKF_Y.eulero[1] = EKF_P.UnitConversion_Gain_o * rtb_Sum4;
  EKF_Y.eulero[2] = EKF_P.UnitConversion_Gain_o * rtb_Sum1_f;

  /* Gain: '<S8>/1//2' */
  rtb_sincos_o1_k_idx_0 = EKF_P.u_Gain_g * rtb_VectorConcatenate[0];
  rtb_sincos_o1_idx = EKF_P.u_Gain_g * rtb_Sum4;
  rtb_sincos_o2_f_idx = EKF_P.u_Gain_g * rtb_Sum1_f;

  /* Trigonometry: '<S8>/sincos' */
  rtb_TmpSignalConversionAtSFu_am[0] = cos(rtb_sincos_o1_k_idx_0);
  rtb_sincos_o1_k_idx_0 = sin(rtb_sincos_o1_k_idx_0);
  rtb_TmpSignalConversionAtSFu_am[1] = cos(rtb_sincos_o1_idx);
  rtb_sincos_o1_idx = sin(rtb_sincos_o1_idx);
  rtb_sincos_o1_k_idx = sin(rtb_sincos_o2_f_idx);
  rtb_TmpSignalConversionAtSFu_am[2] = cos(rtb_sincos_o2_f_idx);

  /* Fcn: '<S8>/q1' */
  rtb_y1 = rtb_TmpSignalConversionAtSFu_am[0] * rtb_TmpSignalConversionAtSFu_am
    [1] * rtb_sincos_o1_k_idx - rtb_sincos_o1_k_idx_0 * rtb_sincos_o1_idx *
    rtb_TmpSignalConversionAtSFu_am[2];

  /* Fcn: '<S8>/q2' */
  rtb_Product2_a = rtb_TmpSignalConversionAtSFu_am[0] * rtb_sincos_o1_idx *
    rtb_TmpSignalConversionAtSFu_am[2] + rtb_sincos_o1_k_idx_0 *
    rtb_TmpSignalConversionAtSFu_am[1] * rtb_sincos_o1_k_idx;

  /* Fcn: '<S8>/q3' */
  rtb_q = rtb_sincos_o1_k_idx_0 * rtb_TmpSignalConversionAtSFu_am[1] *
    rtb_TmpSignalConversionAtSFu_am[2] - rtb_TmpSignalConversionAtSFu_am[0] *
    rtb_sincos_o1_idx * rtb_sincos_o1_k_idx;

  /* Fcn: '<S8>/q0' */
  rtb_b2 = rtb_TmpSignalConversionAtSFu_am[0] * rtb_TmpSignalConversionAtSFu_am
    [1] * rtb_TmpSignalConversionAtSFu_am[2] + rtb_sincos_o1_k_idx_0 *
    rtb_sincos_o1_idx * rtb_sincos_o1_k_idx;

  /* Outport: '<Root>/quaternioni' */
  EKF_Y.quaternioni[0] = rtb_y1;
  EKF_Y.quaternioni[1] = rtb_Product2_a;
  EKF_Y.quaternioni[2] = rtb_q;
  EKF_Y.quaternioni[3] = rtb_b2;

  /* Outport: '<Root>/p-q-r' incorporates:
   *  Sum: '<S1>/Add'
   */
  EKF_Y.pqr[0] = rtb_gyrounbiased_idx - rtb_Memory_k_idx;
  EKF_Y.pqr[1] = rtb_gyrounbiased_idx_0 - rtb_Memory_k_idx_0;
  EKF_Y.pqr[2] = rtb_gyrounbiased_idx_1 - rtb_Memory_k_idx_1;

  /* Outport: '<Root>/WGS' */
  EKF_Y.WGS[0] = EKF_B.c;
  EKF_Y.WGS[1] = EKF_B.c;
  EKF_Y.WGS[2] = EKF_B.gphih;

  /* MATLAB Function Block: '<S1>/quat_derivative' */

  /* MATLAB Function 'EKF/quat_derivative': '<S11>:1' */
  /* '<S11>:1:2' */
  /* '<S11>:1:7' */
  rtb_MatrixConcatenate_0[0] = 0.0;
  rtb_MatrixConcatenate_0[4] = -rtb_gyrounbiased_idx;
  rtb_MatrixConcatenate_0[8] = -rtb_gyrounbiased_idx_0;
  rtb_MatrixConcatenate_0[12] = -rtb_gyrounbiased_idx_1;
  rtb_MatrixConcatenate_0[1] = rtb_gyrounbiased_idx;
  rtb_MatrixConcatenate_0[5] = 0.0;
  rtb_MatrixConcatenate_0[9] = rtb_gyrounbiased_idx_1;
  rtb_MatrixConcatenate_0[13] = -rtb_gyrounbiased_idx_0;
  rtb_MatrixConcatenate_0[2] = rtb_gyrounbiased_idx_0;
  rtb_MatrixConcatenate_0[6] = -rtb_gyrounbiased_idx_1;
  rtb_MatrixConcatenate_0[10] = 0.0;
  rtb_MatrixConcatenate_0[14] = rtb_gyrounbiased_idx;
  rtb_MatrixConcatenate_0[3] = rtb_gyrounbiased_idx_1;
  rtb_MatrixConcatenate_0[7] = rtb_gyrounbiased_idx_0;
  rtb_MatrixConcatenate_0[11] = -rtb_gyrounbiased_idx;
  rtb_MatrixConcatenate_0[15] = 0.0;
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    rtb_MatrixConcatenate_1[qY_3 << 2] = rtb_MatrixConcatenate_0[qY_3 << 2] *
      0.5;
    rtb_MatrixConcatenate_1[1 + (qY_3 << 2)] = rtb_MatrixConcatenate_0[(qY_3 <<
      2) + 1] * 0.5;
    rtb_MatrixConcatenate_1[2 + (qY_3 << 2)] = rtb_MatrixConcatenate_0[(qY_3 <<
      2) + 2] * 0.5;
    rtb_MatrixConcatenate_1[3 + (qY_3 << 2)] = rtb_MatrixConcatenate_0[(qY_3 <<
      2) + 3] * 0.5;
  }

  /* End of MATLAB Function Block: '<S1>/quat_derivative' */

  /* Outport: '<Root>/quat_dot' incorporates:
   *  MATLAB Function Block: '<S1>/quat_derivative'
   *  SignalConversion: '<S11>/TmpSignal ConversionAt SFunction Inport2'
   */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    EKF_Y.quat_dot[qY_3] = 0.0;
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3] * rtb_y1;
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3 + 4] * rtb_Product2_a;
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3 + 8] * rtb_q;
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3 + 12] * rtb_b2;
  }

  /* End of Outport: '<Root>/quat_dot' */

  /* Outputs for Atomic SubSystem: '<S3>/Prediction' */
  /* Product: '<S22>/Product' incorporates:
   *  MATLAB Function Block: '<S22>/d f(x) // dx'
   */

  /* MATLAB Function 'EKF/EKF_AHRS/Prediction/Prediction/Phi(k)/d f(x) / dx': '<S25>:1' */
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /* '<S25>:1:5' */
  /* '<S25>:1:6' */
  /* '<S25>:1:7' */
  /* '<S25>:1:8' */
  /* '<S25>:1:9' */
  /* '<S25>:1:10' */
  /* '<S25>:1:11' */
  /* '<S25>:1:13' */
  rtb_Sum_ll_0[0] = 0.0;
  rtb_Sum_ll_0[7] = 0.5 * rtb_gyrounbiased_idx_1 - 0.5 * rtb_Sum1_cs[6];
  rtb_Sum_ll_0[14] = -0.5 * rtb_gyrounbiased_idx_0 + 0.5 * rtb_Sum1_cs[5];
  rtb_Sum_ll_0[21] = 0.5 * rtb_gyrounbiased_idx - 0.5 * rtb_Sum1_cs[4];
  rtb_Sum_ll_0[28] = -0.5 * rtb_Sum1_cs[3];
  rtb_Sum_ll_0[35] = 0.5 * rtb_Sum1_cs[2];
  rtb_Sum_ll_0[42] = -0.5 * rtb_Sum1_cs[1];
  rtb_Sum_ll_0[1] = -0.5 * rtb_gyrounbiased_idx_1 + 0.5 * rtb_Sum1_cs[6];
  rtb_Sum_ll_0[8] = 0.0;
  rtb_Sum_ll_0[15] = 0.5 * rtb_gyrounbiased_idx - 0.5 * rtb_Sum1_cs[4];
  rtb_Sum_ll_0[22] = 0.5 * rtb_gyrounbiased_idx_0 - 0.5 * rtb_Sum1_cs[5];
  rtb_Sum_ll_0[29] = -0.5 * rtb_Sum1_cs[2];
  rtb_Sum_ll_0[36] = -0.5 * rtb_Sum1_cs[3];
  rtb_Sum_ll_0[43] = 0.5 * rtb_Sum1_cs[0];
  rtb_Sum_ll_0[2] = 0.5 * rtb_gyrounbiased_idx_0 - 0.5 * rtb_Sum1_cs[5];
  rtb_Sum_ll_0[9] = -0.5 * rtb_gyrounbiased_idx + 0.5 * rtb_Sum1_cs[4];
  rtb_Sum_ll_0[16] = 0.0;
  rtb_Sum_ll_0[23] = 0.5 * rtb_gyrounbiased_idx_1 - 0.5 * rtb_Sum1_cs[6];
  rtb_Sum_ll_0[30] = 0.5 * rtb_Sum1_cs[1];
  rtb_Sum_ll_0[37] = -0.5 * rtb_Sum1_cs[0];
  rtb_Sum_ll_0[44] = -0.5 * rtb_Sum1_cs[3];
  rtb_Sum_ll_0[3] = -0.5 * rtb_gyrounbiased_idx + 0.5 * rtb_Sum1_cs[4];
  rtb_Sum_ll_0[10] = -0.5 * rtb_gyrounbiased_idx_0 + 0.5 * rtb_Sum1_cs[5];
  rtb_Sum_ll_0[17] = -0.5 * rtb_gyrounbiased_idx_1 + 0.5 * rtb_Sum1_cs[6];
  rtb_Sum_ll_0[24] = 0.0;
  rtb_Sum_ll_0[31] = 0.5 * rtb_Sum1_cs[0];
  rtb_Sum_ll_0[38] = 0.5 * rtb_Sum1_cs[1];
  rtb_Sum_ll_0[45] = 0.5 * rtb_Sum1_cs[2];
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_ll_0[4 + 7 * qY_3] = 0.0;
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_ll_0[5 + 7 * qY_3] = 0.0;
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_ll_0[6 + 7 * qY_3] = 0.0;
  }

  /* End of Product: '<S22>/Product' */

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/dt'
   *  Product: '<S22>/Product'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Sum_ll[r + 7 * qY_3] = rtb_Sum_ll_0[7 * qY_3 + r] * EKF_U.dt +
        EKF_P.Constant2_Value[7 * qY_3 + r];
    }
  }

  /* MATLAB Function 'EKF/EKF_AHRS/Prediction/Prediction/f(x_k)/f(xk) ': '<S28>:1' */
  /*  This block supports the Embedded MATLAB subset. */
  /*  See the help menu for details.  */
  /* '<S28>:1:5' */
  /* '<S28>:1:6' */
  /* '<S28>:1:7' */
  /* '<S28>:1:8' */
  /* '<S28>:1:9' */
  /* '<S28>:1:10' */
  /* '<S28>:1:11' */
  /* '<S28>:1:14' */
  for (i = 0; i < 12; i++) {
    /* Constant: '<S23>/ ' */
    rtb_MatrixConcatenate_l[i + 16] = EKF_P._Value[i];

    /* Constant: '<S23>/ 1' */
    rtb_MatrixConcatenate1[i] = EKF_P.u_Value[i];
  }

  /* End of Sum: '<S22>/Sum' */

  /* MATLAB Function Block: '<S23>/MATLAB Function' incorporates:
   *  Inport: '<Root>/Q_quat'
   */

  /* MATLAB Function 'EKF/EKF_AHRS/Prediction/Prediction/Q_matrix/MATLAB Function': '<S26>:1' */
  /* '<S26>:1:4' */
  for (i = 0; i < 16; i++) {
    rtb_MatrixConcatenate_l[i] = 0.0;
  }

  rtb_MatrixConcatenate_l[0] = EKF_U.Q_quat[0];
  rtb_MatrixConcatenate_l[5] = EKF_U.Q_quat[1];
  rtb_MatrixConcatenate_l[10] = EKF_U.Q_quat[2];
  rtb_MatrixConcatenate_l[15] = EKF_U.Q_quat[3];

  /* End of MATLAB Function Block: '<S23>/MATLAB Function' */

  /* MATLAB Function Block: '<S23>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/Q_bias'
   */

  /* MATLAB Function 'EKF/EKF_AHRS/Prediction/Prediction/Q_matrix/MATLAB Function1': '<S27>:1' */
  /* '<S27>:1:4' */
  for (i = 0; i < 9; i++) {
    rtb_MatrixConcatenate1[i + 12] = 0.0;
  }

  rtb_MatrixConcatenate1[12] = EKF_U.Q_bias[0];
  rtb_MatrixConcatenate1[16] = EKF_U.Q_bias[1];
  rtb_MatrixConcatenate1[20] = EKF_U.Q_bias[2];

  /* End of MATLAB Function Block: '<S23>/MATLAB Function1' */
  /* End of Outputs for SubSystem: '<S3>/Prediction' */

  /* Reshape: '<S3>/Reshape1' */
  rtb_Reshape1 = 0.0;

  /* Outputs for Atomic SubSystem: '<S3>/Correction' */
  /* Product: '<S15>/Product3' incorporates:
   *  Constant: '<S15>/Constant'
   *  Product: '<S15>/Product1'
   *  Sum: '<S15>/Sum'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Sum_ll_0[qY_3 + 7 * r] = EKF_P.Constant_Value[7 * r + qY_3] -
        (((rtb_MatrixConcatenate_a[(r << 2) + 1] * rtb_Product4_lu[qY_3 + 7] +
           rtb_MatrixConcatenate_a[r << 2] * rtb_Product4_lu[qY_3]) +
          rtb_MatrixConcatenate_a[(r << 2) + 2] * rtb_Product4_lu[qY_3 + 14]) +
         rtb_MatrixConcatenate_a[(r << 2) + 3] * rtb_Product4_lu[qY_3 + 21]);
    }
  }

  /* End of Product: '<S15>/Product3' */

  /* Outputs for Atomic SubSystem: '<S3>/Prediction' */
  /* Product: '<S21>/Product1' incorporates:
   *  Product: '<S15>/Product3'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      tmp_0[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        tmp_0[qY_3 + 7 * r] = rtb_Sum_ll_0[7 * i + qY_3] * rtb_Memory1[7 * r + i]
          + tmp_0[7 * r + qY_3];
      }
    }
  }

  /* End of Outputs for SubSystem: '<S3>/Correction' */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Memory1[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Memory1[qY_3 + 7 * r] = rtb_Sum_ll[7 * i + qY_3] * tmp_0[7 * r + i]
          + rtb_Memory1[7 * r + qY_3];
      }
    }
  }

  /* End of Product: '<S21>/Product1' */

  /* Sum: '<S21>/Sum1' incorporates:
   *  Concatenate: '<S23>/Matrix Concatenate2'
   *  Math: '<S21>/Math Function'
   *  Product: '<S21>/Product1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Sum_ll_0[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Sum_ll_0[qY_3 + 7 * r] = rtb_Memory1[7 * i + qY_3] * rtb_Sum_ll[7 *
          i + r] + rtb_Sum_ll_0[7 * r + qY_3];
      }
    }
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Memory1[7 * qY_3] = rtb_MatrixConcatenate_l[qY_3 << 2];
    rtb_Memory1[1 + 7 * qY_3] = rtb_MatrixConcatenate_l[(qY_3 << 2) + 1];
    rtb_Memory1[2 + 7 * qY_3] = rtb_MatrixConcatenate_l[(qY_3 << 2) + 2];
    rtb_Memory1[3 + 7 * qY_3] = rtb_MatrixConcatenate_l[(qY_3 << 2) + 3];
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Memory1[4 + 7 * qY_3] = rtb_MatrixConcatenate1[3 * qY_3];
    rtb_Memory1[5 + 7 * qY_3] = rtb_MatrixConcatenate1[3 * qY_3 + 1];
    rtb_Memory1[6 + 7 * qY_3] = rtb_MatrixConcatenate1[3 * qY_3 + 2];
  }

  /* End of Sum: '<S21>/Sum1' */

  /* Update for Memory: '<S3>/Memory1' incorporates:
   *  Sum: '<S21>/Sum1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      EKF_DWork.Memory1_PreviousInput[r + 7 * qY_3] = rtb_Sum_ll_0[7 * qY_3 + r]
        + rtb_Memory1[7 * qY_3 + r];
    }
  }

  /* End of Memory: '<S3>/Memory1' */

  /* Update for Memory: '<S3>/Memory' incorporates:
   *  Inport: '<Root>/dt'
   *  MATLAB Function Block: '<S24>/f(xk) '
   *  Product: '<S21>/Product'
   *  Sum: '<S21>/Sum'
   */
  EKF_DWork.Memory_PreviousInput[0] = ((0.5 * rtb_Sum1_cs[3] *
    (rtb_gyrounbiased_idx - rtb_Sum1_cs[4]) - 0.5 * rtb_Sum1_cs[2] *
    (rtb_gyrounbiased_idx_0 - rtb_Sum1_cs[5])) + 0.5 * rtb_Sum1_cs[1] *
    (rtb_gyrounbiased_idx_1 - rtb_Sum1_cs[6])) * EKF_U.dt + rtb_Sum1_cs[0];
  EKF_DWork.Memory_PreviousInput[1] = ((0.5 * rtb_Sum1_cs[2] *
    (rtb_gyrounbiased_idx - rtb_Sum1_cs[4]) + 0.5 * rtb_Sum1_cs[3] *
    (rtb_gyrounbiased_idx_0 - rtb_Sum1_cs[5])) - 0.5 * rtb_Sum1_cs[0] *
    (rtb_gyrounbiased_idx_1 - rtb_Sum1_cs[6])) * EKF_U.dt + rtb_Sum1_cs[1];
  EKF_DWork.Memory_PreviousInput[2] = ((-0.5 * rtb_Sum1_cs[1] *
    (rtb_gyrounbiased_idx - rtb_Sum1_cs[4]) + 0.5 * rtb_Sum1_cs[0] *
    (rtb_gyrounbiased_idx_0 - rtb_Sum1_cs[5])) + 0.5 * rtb_Sum1_cs[3] *
    (rtb_gyrounbiased_idx_1 - rtb_Sum1_cs[6])) * EKF_U.dt + rtb_Sum1_cs[2];
  EKF_DWork.Memory_PreviousInput[3] = ((-0.5 * rtb_Sum1_cs[0] *
    (rtb_gyrounbiased_idx - rtb_Sum1_cs[4]) - 0.5 * rtb_Sum1_cs[1] *
    (rtb_gyrounbiased_idx_0 - rtb_Sum1_cs[5])) - 0.5 * rtb_Sum1_cs[2] *
    (rtb_gyrounbiased_idx_1 - rtb_Sum1_cs[6])) * EKF_U.dt + rtb_Sum1_cs[3];
  EKF_DWork.Memory_PreviousInput[4] = EKF_U.dt * 0.0 + rtb_Sum1_cs[4];
  EKF_DWork.Memory_PreviousInput[5] = EKF_U.dt * 0.0 + rtb_Sum1_cs[5];
  EKF_DWork.Memory_PreviousInput[6] = EKF_U.dt * 0.0 + rtb_Sum1_cs[6];

  /* End of Outputs for SubSystem: '<S3>/Prediction' */

  /* Update for Memory: '<S1>/Memory' */
  EKF_DWork.Memory_PreviousInput_i[0] = rtb_Sum1_cs[4];
  EKF_DWork.Memory_PreviousInput_i[1] = rtb_Sum1_cs[5];
  EKF_DWork.Memory_PreviousInput_i[2] = rtb_Sum1_cs[6];

  /* Update for Memory: '<S1>/Memory1' */
  EKF_DWork.Memory1_PreviousInput_m[0] = rtb_Sum1_cs[0];
  EKF_DWork.Memory1_PreviousInput_m[1] = rtb_Sum1_cs[1];
  EKF_DWork.Memory1_PreviousInput_m[2] = rtb_Sum1_cs[2];
  EKF_DWork.Memory1_PreviousInput_m[3] = rtb_Sum1_cs[3];

  /* Update for Memory: '<S108>/Memory' */
  EKF_DWork.Memory_PreviousInput_o[0] = rtb_Gain_i;
  EKF_DWork.Memory_PreviousInput_o[1] = rtb_Sum_g;
  EKF_DWork.Memory_PreviousInput_o[2] = rtb_Sum_l;
  EKF_DWork.Memory_PreviousInput_o[3] = rtb_u80deg;

  /* Update for Memory: '<S109>/Memory1' */
  EKF_DWork.Memory1_PreviousInput_f = rtb_x1;

  /* Update for Memory: '<S1>/Memory2' */
  EKF_DWork.Memory2_PreviousInput[0] = rtb_VectorConcatenate[0];
  EKF_DWork.Memory2_PreviousInput[1] = rtb_Sum4;
  EKF_DWork.Memory2_PreviousInput[2] = rtb_Sum1_f;

  /* Update for Memory: '<S109>/Memory' */
  EKF_DWork.Memory_PreviousInput_a = rtb_d;
}

/* Model initialize function */
void EKF_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(EKF_M, (NULL));

  /* block I/O */
  {
    int_T i;
    for (i = 0; i < 11; i++) {
      EKF_B.Assignment[i] = 0.0;
    }

    for (i = 0; i < 11; i++) {
      EKF_B.Assignment1[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      EKF_B.Sum2_c[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      EKF_B.Assignment_k[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      EKF_B.Assignment_snorm[i] = 0.0;
    }

    for (i = 0; i < 13; i++) {
      EKF_B.Assignment2_n[i] = 0.0;
    }

    for (i = 0; i < 13; i++) {
      EKF_B.Assignment2_nk[i] = 0.0;
    }

    EKF_B.gphih = 0.0;
    EKF_B.c = 0.0;
    EKF_B.sp2 = 0.0;
    EKF_B.cp2 = 0.0;
    EKF_B.cp1 = 0.0;
    EKF_B.sp1 = 0.0;
    EKF_B.sqrt_h = 0.0;
    EKF_B.Product11 = 0.0;
    EKF_B.Product4 = 0.0;
    EKF_B.Product12 = 0.0;
    EKF_B.sqrt_n = 0.0;
    EKF_B.Merge[0] = 0.0;
    EKF_B.Merge[1] = 0.0;
    EKF_B.Sum1 = 0.0;
    EKF_B.Sum2 = 0.0;
    EKF_B.Sum3 = 0.0;
    EKF_B.Sum5 = 0.0;
    EKF_B.Merge_o[0] = 0.0;
    EKF_B.Merge_o[1] = 0.0;
    EKF_B.Product2 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&EKF_DWork, 0,
                sizeof(D_Work_EKF));
  EKF_DWork.UnitDelay1_DSTATE[0] = 0.0;
  EKF_DWork.UnitDelay1_DSTATE[1] = 0.0;
  EKF_DWork.UnitDelay1_DSTATE_m = 0.0;
  EKF_DWork.UnitDelay3_DSTATE = 0.0;
  EKF_DWork.UnitDelay2_DSTATE_f = 0.0;
  EKF_DWork.UnitDelay4_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay_DSTATE_o[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay_DSTATE_k[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay_DSTATE_ka[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay1_DSTATE_p[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 13; i++) {
      EKF_DWork.UnitDelay1_DSTATE_p4[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 49; i++) {
      EKF_DWork.Memory1_PreviousInput[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 7; i++) {
      EKF_DWork.Memory_PreviousInput[i] = 0.0;
    }
  }

  EKF_DWork.Memory_PreviousInput_i[0] = 0.0;
  EKF_DWork.Memory_PreviousInput_i[1] = 0.0;
  EKF_DWork.Memory_PreviousInput_i[2] = 0.0;
  EKF_DWork.Memory1_PreviousInput_m[0] = 0.0;
  EKF_DWork.Memory1_PreviousInput_m[1] = 0.0;
  EKF_DWork.Memory1_PreviousInput_m[2] = 0.0;
  EKF_DWork.Memory1_PreviousInput_m[3] = 0.0;
  EKF_DWork.Memory_PreviousInput_o[0] = 0.0;
  EKF_DWork.Memory_PreviousInput_o[1] = 0.0;
  EKF_DWork.Memory_PreviousInput_o[2] = 0.0;
  EKF_DWork.Memory_PreviousInput_o[3] = 0.0;
  EKF_DWork.Memory1_PreviousInput_f = 0.0;
  EKF_DWork.Memory2_PreviousInput[0] = 0.0;
  EKF_DWork.Memory2_PreviousInput[1] = 0.0;
  EKF_DWork.Memory2_PreviousInput[2] = 0.0;
  EKF_DWork.Memory_PreviousInput_a = 0.0;
  EKF_DWork.otime_PreviousInput = 0.0;
  EKF_DWork.olon_PreviousInput = 0.0;
  EKF_DWork.olat_PreviousInput = 0.0;
  EKF_DWork.oalt_PreviousInput = 0.0;

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      EKF_DWork.Product2_DWORK4[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 16; i++) {
      EKF_DWork.Product2_DWORK4_k[i] = 0.0;
    }
  }

  /* external inputs */
  EKF_U.latlonalti[0] = 0.0;
  EKF_U.latlonalti[1] = 0.0;
  EKF_U.latlonalti[2] = 0.0;
  EKF_U.accell[0] = 0.0;
  EKF_U.accell[1] = 0.0;
  EKF_U.accell[2] = 0.0;
  EKF_U.mag[0] = 0.0;
  EKF_U.mag[1] = 0.0;
  EKF_U.mag[2] = 0.0;
  EKF_U.gyro[0] = 0.0;
  EKF_U.gyro[1] = 0.0;
  EKF_U.gyro[2] = 0.0;
  EKF_U.deviazione_std_accell = 0.0;
  EKF_U.deviazione_std_magneto = 0.0;
  EKF_U.dt = 0.0;
  EKF_U.Q_quat[0] = 0.0;
  EKF_U.Q_quat[1] = 0.0;
  EKF_U.Q_quat[2] = 0.0;
  EKF_U.Q_quat[3] = 0.0;
  EKF_U.Q_bias[0] = 0.0;
  EKF_U.Q_bias[1] = 0.0;
  EKF_U.Q_bias[2] = 0.0;
  EKF_U.GPS_Reset = 0.0;

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      EKF_U.Accel_Cal[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 12; i++) {
      EKF_U.Mag_Cal[i] = 0.0;
    }
  }

  EKF_U.Gyro_Cal[0] = 0.0;
  EKF_U.Gyro_Cal[1] = 0.0;
  EKF_U.Gyro_Cal[2] = 0.0;
  EKF_U.tau = 0.0;
  EKF_U.trig = 0.0;

  /* external outputs */
  EKF_Y.eulero[0] = 0.0;
  EKF_Y.eulero[1] = 0.0;
  EKF_Y.eulero[2] = 0.0;
  EKF_Y.quaternioni[0] = 0.0;
  EKF_Y.quaternioni[1] = 0.0;
  EKF_Y.quaternioni[2] = 0.0;
  EKF_Y.quaternioni[3] = 0.0;
  EKF_Y.pqr[0] = 0.0;
  EKF_Y.pqr[1] = 0.0;
  EKF_Y.pqr[2] = 0.0;
  EKF_Y.WMM[0] = 0.0;
  EKF_Y.WMM[1] = 0.0;
  EKF_Y.WMM[2] = 0.0;
  EKF_Y.WGS[0] = 0.0;
  EKF_Y.WGS[1] = 0.0;
  EKF_Y.WGS[2] = 0.0;
  EKF_Y.quat_dot[0] = 0.0;
  EKF_Y.quat_dot[1] = 0.0;
  EKF_Y.quat_dot[2] = 0.0;
  EKF_Y.quat_dot[3] = 0.0;

  {
    int32_T i;

    /* Start for Enabled SubSystem: '<S1>/Enabled Subsystem' */
    /* Start for Enabled SubSystem: '<S38>/Convert from geodetic to  spherical coordinates ' */
    /* Start for Iterator SubSystem: '<S42>/For Iterator Subsystem' */
    /* InitializeConditions for UnitDelay: '<S89>/Unit Delay1' */
    EKF_DWork.UnitDelay1_DSTATE[0] = EKF_P.UnitDelay1_X0_l;
    EKF_DWork.UnitDelay1_DSTATE[1] = EKF_P.UnitDelay1_X0_l;

    /* End of Start for SubSystem: '<S42>/For Iterator Subsystem' */

    /* VirtualOutportStart for Outport: '<S42>/sp[13]' */
    EKF_B.sp1 = EKF_P.sp13_Y0[0];
    EKF_B.sp2 = EKF_P.sp13_Y0[1];

    /* VirtualOutportStart for Outport: '<S42>/cp[13]' */
    EKF_B.cp1 = EKF_P.cp13_Y0[0];
    EKF_B.cp2 = EKF_P.cp13_Y0[1];
    for (i = 0; i < 11; i++) {
      /* VirtualOutportStart for Outport: '<S42>/sp[13]' */
      EKF_B.Assignment[i] = EKF_P.sp13_Y0[i + 2];
      EKF_B.Assignment1[i] = EKF_P.cp13_Y0[i + 2];
    }

    /* End of Start for SubSystem: '<S38>/Convert from geodetic to  spherical coordinates ' */

    /* Start for Iterator SubSystem: '<S38>/Compute magnetic vector in spherical coordinates' */
    /* Start for Iterator SubSystem: '<S40>/For Iterator Subsystem' */
    /* Start for Enabled SubSystem: '<S48>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */
    /* Start for Enabled SubSystem: '<S48>/Time adjust the gauss coefficients' */
    for (i = 0; i < 169; i++) {
      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay' */
      EKF_DWork.UnitDelay_DSTATE_ka[i] = EKF_P.UnitDelay_X0[i];

      /* InitializeConditions for UnitDelay: '<S50>/Unit Delay1' */
      EKF_DWork.UnitDelay1_DSTATE_p[i] = EKF_P.UnitDelay1_X0_m[i];

      /* InitializeConditions for UnitDelay: '<S51>/Unit Delay' */
      EKF_DWork.UnitDelay_DSTATE_o[i] = EKF_P.UnitDelay_X0_a[i];

      /* InitializeConditions for UnitDelay: '<S78>/Unit Delay' */
      EKF_DWork.UnitDelay_DSTATE_k[i] = EKF_P.UnitDelay_X0_g[i];
    }

    /* End of Outport: '<S42>/cp[13]' */
    /* End of Start for SubSystem: '<S48>/Time adjust the gauss coefficients' */
    /* End of Start for SubSystem: '<S48>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

    /* Start for Enabled SubSystem: '<S49>/Special case - North//South Geographic Pole' */
    /* InitializeConditions for UnitDelay: '<S52>/Unit Delay1' */
    memcpy((void *)EKF_DWork.UnitDelay1_DSTATE_p4, (void *)EKF_P.UnitDelay1_X0,
           13U * sizeof(real_T));

    /* VirtualOutportStart for Outport: '<S52>/bpp' */
    EKF_B.Product2 = EKF_P.bpp_Y0;

    /* End of Start for SubSystem: '<S49>/Special case - North//South Geographic Pole' */

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay1' */
    EKF_DWork.UnitDelay1_DSTATE_m = EKF_P.UnitDelay1_X0_c;

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay3' */
    EKF_DWork.UnitDelay3_DSTATE = EKF_P.UnitDelay3_X0;

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay2' */
    EKF_DWork.UnitDelay2_DSTATE_f = EKF_P.UnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay4' */
    EKF_DWork.UnitDelay4_DSTATE = EKF_P.UnitDelay4_X0;

    /* End of Start for SubSystem: '<S40>/For Iterator Subsystem' */
    /* End of Start for SubSystem: '<S38>/Compute magnetic vector in spherical coordinates' */

    /* InitializeConditions for Memory: '<S46>/otime' */
    EKF_DWork.otime_PreviousInput = EKF_P.otime_X0;

    /* InitializeConditions for Memory: '<S45>/olon' */
    EKF_DWork.olon_PreviousInput = EKF_P.olon_X0;

    /* InitializeConditions for Memory: '<S44>/olat' */
    EKF_DWork.olat_PreviousInput = EKF_P.olat_X0;

    /* InitializeConditions for Memory: '<S44>/oalt' */
    EKF_DWork.oalt_PreviousInput = EKF_P.oalt_X0;

    /* End of Start for SubSystem: '<S1>/Enabled Subsystem' */

    /* Start for Atomic SubSystem: '<S3>/Correction' */

    /* Create Identity Matrix for Block: '<S17>/Product2' */
    {
      int_T i;
      real_T *dWork = &EKF_DWork.Product2_DWORK4[0];
      for (i = 0; i < 16; i++) {
        *dWork++ = 0.0;
      }

      dWork = &EKF_DWork.Product2_DWORK4[0];
      while (dWork < &EKF_DWork.Product2_DWORK4[0]+16) {
        *dWork = 1;
        dWork += 5;
      }
    }

    /* Create Identity Matrix for Block: '<S16>/Product2' */
    {
      int_T i;
      real_T *dWork = &EKF_DWork.Product2_DWORK4_k[0];
      for (i = 0; i < 16; i++) {
        *dWork++ = 0.0;
      }

      dWork = &EKF_DWork.Product2_DWORK4_k[0];
      while (dWork < &EKF_DWork.Product2_DWORK4_k[0]+16) {
        *dWork = 1;
        dWork += 5;
      }
    }

    /* End of Start for SubSystem: '<S3>/Correction' */

    /* Start for Outport: '<Root>/WGS' */
    EKF_Y.WGS[0] = EKF_B.c;
    EKF_Y.WGS[1] = EKF_B.c;
    EKF_Y.WGS[2] = EKF_B.gphih;
  }

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S3>/Memory1' */
    memcpy((void *)EKF_DWork.Memory1_PreviousInput, (void *)EKF_P.Memory1_X0,
           49U * sizeof(real_T));

    /* InitializeConditions for Memory: '<S3>/Memory' */
    for (i = 0; i < 7; i++) {
      EKF_DWork.Memory_PreviousInput[i] = EKF_P.Memory_X0[i];
    }

    /* End of Memory: '<S3>/Memory' */

    /* InitializeConditions for Memory: '<S1>/Memory' */
    EKF_DWork.Memory_PreviousInput_i[0] = EKF_P.Memory_X0_k;
    EKF_DWork.Memory_PreviousInput_i[1] = EKF_P.Memory_X0_k;
    EKF_DWork.Memory_PreviousInput_i[2] = EKF_P.Memory_X0_k;

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    EKF_DWork.Memory1_PreviousInput_m[0] = EKF_P.Memory1_X0_i;
    EKF_DWork.Memory1_PreviousInput_m[1] = EKF_P.Memory1_X0_i;
    EKF_DWork.Memory1_PreviousInput_m[2] = EKF_P.Memory1_X0_i;
    EKF_DWork.Memory1_PreviousInput_m[3] = EKF_P.Memory1_X0_i;

    /* InitializeConditions for Memory: '<S108>/Memory' */
    EKF_DWork.Memory_PreviousInput_o[0] = EKF_P.Memory_X0_h;
    EKF_DWork.Memory_PreviousInput_o[1] = EKF_P.Memory_X0_h;
    EKF_DWork.Memory_PreviousInput_o[2] = EKF_P.Memory_X0_h;
    EKF_DWork.Memory_PreviousInput_o[3] = EKF_P.Memory_X0_h;

    /* InitializeConditions for Memory: '<S109>/Memory1' */
    EKF_DWork.Memory1_PreviousInput_f = EKF_P.Memory1_X0_o;

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    EKF_DWork.Memory2_PreviousInput[0] = EKF_P.Memory2_X0;
    EKF_DWork.Memory2_PreviousInput[1] = EKF_P.Memory2_X0;
    EKF_DWork.Memory2_PreviousInput[2] = EKF_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S109>/Memory' */
    EKF_DWork.Memory_PreviousInput_a = EKF_P.Memory_X0_l;
  }
}

/* Model terminate function */
void EKF_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
