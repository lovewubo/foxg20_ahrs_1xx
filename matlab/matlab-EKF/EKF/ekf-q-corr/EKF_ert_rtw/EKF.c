/*
 * File: EKF.c
 *
 * Code generated for Simulink model 'EKF'.
 *
 * Model version                  : 1.474
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Tue Dec 27 14:06:11 2011
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

/* Function for MATLAB Function Block: '<S5>/QUEST' */
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

/* Function for MATLAB Function Block: '<S5>/QUEST' */
static real_T EKF_dot(const real_T a[3], const real_T b[3])
{
  return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2];
}

/* Function for MATLAB Function Block: '<S5>/QUEST' */
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
  real_T rtb_Product2_ee[16];

  /* local scratch DWork variables */
  real_T Product2_DWORK1[16];
  real_T Product2_DWORK3[16];
  real_T Product2_DWORK1_a[16];
  real_T Product2_DWORK3_m[16];
  int32_T Product2_DWORK2[4];
  int32_T Product2_DWORK2_n[4];
  real_T V[3];
  real_T W[3];
  real_T S[9];
  real_T adjS[9];
  real_T X[3];
  real_T e_B[9];
  int32_T r;
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T rtb_Add;
  real_T rtb_fcn2;
  real_T rtb_UnitConversion_j;
  real_T rtb_gphih;
  real_T rtb_Sum;
  boolean_T rtb_RelationalOperator;
  real_T rtb_u80deg;
  real_T rtb_u0deg;
  real_T rtb_Gain;
  boolean_T rtb_LogicalOperator;
  real_T rtb_Product_d;
  real_T rtb_Product1;
  int32_T s49_iter;
  real_T rtb_Gain1[3];
  real_T rtb_MatrixConcatenate[12];
  real_T rtb_Sum1_c[7];
  real_T rtb_Sum_m;
  int32_T s98_iter;
  real_T rtb_b2;
  real_T rtb_a2;
  real_T rtb_q;
  real_T rtb_d;
  real_T rtb_Sum4;
  int32_T s57_iter;
  real_T rtb_TmpSignalConversionAtSFun_a[3];
  real_T rtb_MatrixConcatenate_a[28];
  real_T rtb_MatrixConcatenate_i[28];
  real_T rtb_MatrixConcatenate_l[28];
  real_T rtb_MatrixConcatenate1[21];
  real_T rtb_Add1[3];
  real_T rtb_mag_calibrate[3];
  real_T rtb_TmpSignalConversionAtspm1In[13];
  real_T rtb_Memory1[49];
  real_T rtb_Memory[7];
  real_T rtb_q_matrix[16];
  real_T rtb_MatrixMultiply2[16];
  real_T rtb_Product4_l[28];
  real_T rtb_Product1_pl[28];
  real_T rtb_Sum_h[49];
  real_T rtb_Sum_l[49];
  real_T rtb_tc_old[169];
  real_T UnitDelay2_DSTATE[4];
  real_T Assignment_f[169];
  real_T Assignment[169];
  int32_T i;
  real_T rtb_Add_0[3];
  real_T rtb_TmpSignalConversionAtSFun_0[3];
  real_T tmp[9];
  real_T rtb_TmpSignalConversionAtSFun_1[9];
  real_T rtb_Add_1[9];
  real_T W_0[9];
  real_T V_0[9];
  real_T rtb_MatrixConcatenate_0[16];
  real_T rtb_MatrixConcatenate_1[16];
  real_T rtb_MatrixConcatenate_a_0[28];
  real_T UnitDelay2_DSTATE_0[4];
  real_T rtb_Sum_h_0[49];
  real_T rtb_Sum_l_0[49];
  real_T tmp_0[13];
  real_T rtb_sincos_o1_m_idx;
  real_T rtb_sincos_o1_m_idx_0;
  real_T rtb_gyrounbiased_idx;
  real_T rtb_gyrounbiased_idx_0;
  real_T rtb_gyrounbiased_idx_1;
  real_T rtb_sincos_o1_idx;
  real_T rtb_sincos_o2_idx;
  real_T rtb_Sum1_d_idx;
  real_T rtb_Sum1_d_idx_0;
  real_T rtb_Sum1_d_idx_1;
  real_T rtb_Sum1_d_idx_2;
  real_T rtb_u_o_idx;
  real_T rtb_u_o_idx_0;
  real_T rtb_u_o_idx_1;
  real_T rtb_u_o_idx_2;
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

  /* MATLAB Function 'EKF/Gyro-bias': '<S4>:1' */
  /* '<S4>:1:4' */
  rtb_gyrounbiased_idx = rtb_Add1[0] - EKF_U.Gyro_Cal[0];
  rtb_gyrounbiased_idx_0 = rtb_Add1[1] - EKF_U.Gyro_Cal[1];
  rtb_gyrounbiased_idx_1 = rtb_Add1[2] - EKF_U.Gyro_Cal[2];

  /* SignalConversion: '<S106>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function Block: '<S10>/quat_derivative1'
   */
  rtb_Add1[0] = rtb_gyrounbiased_idx_1;
  rtb_Add1[1] = rtb_gyrounbiased_idx_0;
  rtb_Add1[2] = rtb_gyrounbiased_idx;

  /* MATLAB Function Block: '<S10>/quat_derivative1' */

  /* MATLAB Function 'EKF/complementar_filter/quat_derivative1': '<S106>:1' */
  /* '<S106>:1:2' */
  /* '<S106>:1:7' */
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

  /* End of MATLAB Function Block: '<S10>/quat_derivative1' */

  /* Product: '<S10>/Product2' incorporates:
   *  MATLAB Function Block: '<S10>/quat_derivative1'
   *  Memory: '<S1>/Memory1'
   */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    rtb_d = rtb_MatrixConcatenate_1[qY_3 + 12] *
      EKF_DWork.Memory1_PreviousInput_m[3] + (rtb_MatrixConcatenate_1[qY_3 + 8] *
      EKF_DWork.Memory1_PreviousInput_m[2] + (rtb_MatrixConcatenate_1[qY_3 + 4] *
      EKF_DWork.Memory1_PreviousInput_m[1] + rtb_MatrixConcatenate_1[qY_3] *
      EKF_DWork.Memory1_PreviousInput_m[0]));
    UnitDelay2_DSTATE_0[qY_3] = rtb_d;
  }

  /* End of Product: '<S10>/Product2' */

  /* Sum: '<S10>/Sum' incorporates:
   *  Inport: '<Root>/dt'
   *  Memory: '<S1>/Memory1'
   *  Product: '<S10>/Product2'
   */
  rtb_u_o_idx = UnitDelay2_DSTATE_0[0] * EKF_U.dt +
    EKF_DWork.Memory1_PreviousInput_m[0];
  rtb_u_o_idx_0 = UnitDelay2_DSTATE_0[1] * EKF_U.dt +
    EKF_DWork.Memory1_PreviousInput_m[1];
  rtb_u_o_idx_1 = UnitDelay2_DSTATE_0[2] * EKF_U.dt +
    EKF_DWork.Memory1_PreviousInput_m[2];
  rtb_u_o_idx_2 = UnitDelay2_DSTATE_0[3] * EKF_U.dt +
    EKF_DWork.Memory1_PreviousInput_m[3];

  /* Sum: '<S10>/Add' incorporates:
   *  Constant: '<S10>/Constant'
   *  Inport: '<Root>/tau'
   */
  rtb_Add = EKF_P.Constant_Value_j - EKF_U.tau;

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

  /* MATLAB Function 'EKF/mag-cal': '<S11>:1' */
  /* '<S11>:1:4' */
  /* '<S11>:1:8' */
  /* '<S11>:1:12' */
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

  /* Trigonometry: '<S7>/sin(phi)' incorporates:
   *  Inport: '<Root>/lat-lon-alti'
   */
  rtb_fcn2 = sin(EKF_U.latlonalti[0]);

  /* Math: '<S7>/sin(phi)^2' */
  rtb_fcn2 *= rtb_fcn2;

  /* Sum: '<S7>/Sum1' incorporates:
   *  Constant: '<S7>/First Eccentricity'
   *  Constant: '<S7>/One'
   *  Math: '<S7>/eps^2'
   *  Product: '<S7>/Product'
   */
  rtb_UnitConversion_j = EKF_P.One_Value - EKF_P.FirstEccentricity_Value *
    EKF_P.FirstEccentricity_Value * rtb_fcn2;

  /* Math: '<S7>/Math Function1' incorporates:
   *  Constant: '<S7>/1//2'
   */
  if ((rtb_UnitConversion_j < 0.0) && (EKF_P.u_Value_k > floor(EKF_P.u_Value_k)))
  {
    rtb_UnitConversion_j = -rt_powd_snf(-rtb_UnitConversion_j, EKF_P.u_Value_k);
  } else {
    rtb_UnitConversion_j = rt_powd_snf(rtb_UnitConversion_j, EKF_P.u_Value_k);
  }

  /* End of Math: '<S7>/Math Function1' */

  /* Product: '<S7>/Product4' incorporates:
   *  Constant: '<S7>/Gravity at Equator'
   *  Constant: '<S7>/Gravity formula const'
   *  Constant: '<S7>/One'
   *  Product: '<S7>/Product3'
   *  Sum: '<S7>/Sum2'
   */
  rtb_UnitConversion_j = (EKF_P.Gravityformulaconst_Value * rtb_fcn2 +
    EKF_P.One_Value) * EKF_P.GravityatEquator_Value / rtb_UnitConversion_j;

  /* Fcn: '<S7>/g(phi,h)' incorporates:
   *  Inport: '<Root>/lat-lon-alti'
   */
  rtb_gphih = (rtb_UnitConversion_j - (3.0877e-006 - 4.4e-009 * rtb_fcn2) *
               EKF_U.latlonalti[2]) + 7.2e-014 * EKF_U.latlonalti[2] *
    EKF_U.latlonalti[2];

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S8>/Date'
   *  Gain: '<S8>/DayToYear'
   *  Gain: '<S8>/MonthToYear'
   */
  rtb_Sum = (EKF_P.DayToYear_Gain * EKF_P.Date_Value[0] + EKF_P.MonthToYear_Gain
             * EKF_P.Date_Value[1]) + EKF_P.Date_Value[2];

  /* Sum: '<S47>/Sum' incorporates:
   *  Constant: '<S47>/epoch'
   */
  rtb_Sum_m = rtb_Sum - EKF_P.epoch_Value;

  /* RelationalOperator: '<S55>/Relational Operator' incorporates:
   *  Memory: '<S55>/otime'
   */
  rtb_RelationalOperator = (rtb_Sum != EKF_DWork.otime_PreviousInput);

  /* Saturate: '<S40>/+//- 180 deg' incorporates:
   *  Inport: '<Root>/lat-lon-alti'
   */
  rtb_u80deg = EKF_U.latlonalti[1] >= EKF_P.u80deg_UpperSat ?
    EKF_P.u80deg_UpperSat : EKF_U.latlonalti[1] <= EKF_P.u80deg_LowerSat ?
    EKF_P.u80deg_LowerSat : EKF_U.latlonalti[1];

  /* Saturate: '<S40>/+//- 90 deg' incorporates:
   *  Inport: '<Root>/lat-lon-alti'
   */
  rtb_u0deg = EKF_U.latlonalti[0] >= EKF_P.u0deg_UpperSat ? EKF_P.u0deg_UpperSat
    : EKF_U.latlonalti[0] <= EKF_P.u0deg_LowerSat ? EKF_P.u0deg_LowerSat :
    EKF_U.latlonalti[0];

  /* Gain: '<S99>/Unit Conversion' */
  rtb_sincos_o1_m_idx = EKF_P.UnitConversion_Gain * rtb_u80deg;
  rtb_sincos_o1_m_idx_0 = EKF_P.UnitConversion_Gain * rtb_u0deg;

  /* Trigonometry: '<S52>/sincos' */
  rtb_sincos_o1_idx = sin(rtb_sincos_o1_m_idx_0);
  rtb_sincos_o2_idx = cos(rtb_sincos_o1_m_idx_0);

  /* Outputs for Enabled SubSystem: '<S47>/Convert from geodetic to  spherical coordinates ' incorporates:
   *  EnablePort: '<S51>/Enable'
   */
  /* RelationalOperator: '<S54>/Relational Operator' incorporates:
   *  Constant: '<S51>/cp[1]'
   *  Constant: '<S51>/sp[1]'
   *  Inport: '<S51>/cp[2]'
   *  Inport: '<S51>/sp[2]'
   *  Memory: '<S54>/olon'
   *  Trigonometry: '<S52>/sincos'
   */
  if (rtb_u80deg != EKF_DWork.olon_PreviousInput) {
    EKF_B.sp2 = sin(rtb_sincos_o1_m_idx);
    EKF_B.cp2 = cos(rtb_sincos_o1_m_idx);

    /* Outputs for Iterator SubSystem: '<S51>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S98>/For Iterator'
     */
    for (s98_iter = 1; (real_T)s98_iter <= EKF_P.ForIterator_IterationLimit;
         s98_iter++) {
      rtb_Product_d = (real_T)s98_iter;

      /* UnitDelay: '<S98>/Unit Delay1' */
      rtb_d = EKF_DWork.UnitDelay1_DSTATE[0];
      rtb_sincos_o1_m_idx_0 = EKF_DWork.UnitDelay1_DSTATE[1];

      /* Switch: '<S98>/cp[m-1] sp[m-1]' */
      if (!(rtb_Product_d > EKF_P.cpm1spm1_Threshold)) {
        rtb_d = EKF_B.cp2;
        rtb_sincos_o1_m_idx_0 = EKF_B.sp2;
      }

      /* End of Switch: '<S98>/cp[m-1] sp[m-1]' */

      /* Sum: '<S98>/Sum2' incorporates:
       *  Product: '<S98>/Product1'
       *  Product: '<S98>/Product2'
       */
      rtb_a2 = rtb_d * EKF_B.sp2 + rtb_sincos_o1_m_idx_0 * EKF_B.cp2;
      for (i = 0; i < 11; i++) {
        /* Assignment: '<S98>/Assignment' incorporates:
         *  Constant: '<S98>/Constant'
         */
        if (s98_iter == 1) {
          EKF_B.Assignment[i] = EKF_P.Constant_Value_eo[i];
        }

        /* End of Assignment: '<S98>/Assignment' */

        /* Assignment: '<S98>/Assignment1' incorporates:
         *  Constant: '<S98>/Constant1'
         */
        if (s98_iter == 1) {
          EKF_B.Assignment1[i] = EKF_P.Constant1_Value_b[i];
        }

        /* End of Assignment: '<S98>/Assignment1' */
      }

      /* Assignment: '<S98>/Assignment' */
      EKF_B.Assignment[(int32_T)rtb_Product_d - 1] = rtb_a2;

      /* Sum: '<S98>/Sum1' incorporates:
       *  Product: '<S98>/Product3'
       *  Product: '<S98>/Product8'
       */
      rtb_q = rtb_d * EKF_B.cp2 - rtb_sincos_o1_m_idx_0 * EKF_B.sp2;

      /* Assignment: '<S98>/Assignment1' */
      EKF_B.Assignment1[(int32_T)rtb_Product_d - 1] = rtb_q;

      /* Update for UnitDelay: '<S98>/Unit Delay1' */
      EKF_DWork.UnitDelay1_DSTATE[0] = rtb_q;
      EKF_DWork.UnitDelay1_DSTATE[1] = rtb_a2;
    }

    /* End of Outputs for SubSystem: '<S51>/For Iterator Subsystem' */
    EKF_B.cp1 = EKF_P.cp1_Value;
    EKF_B.sp1 = EKF_P.sp1_Value;
  }

  /* End of RelationalOperator: '<S54>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S47>/Convert from geodetic to  spherical coordinates ' */

  /* Gain: '<S46>/Unit Conversion' incorporates:
   *  Inport: '<Root>/lat-lon-alti'
   */
  rtb_UnitConversion_j = EKF_P.UnitConversion_Gain_a * EKF_U.latlonalti[2];

  /* Gain: '<S40>/Gain' incorporates:
   *  Saturate: '<S40>/0 to 1,000,000 m'
   */
  rtb_Gain = (rtb_UnitConversion_j >= EKF_P.to1000000m_UpperSat ?
              EKF_P.to1000000m_UpperSat : rtb_UnitConversion_j <=
              EKF_P.to1000000m_LowerSat ? EKF_P.to1000000m_LowerSat :
              rtb_UnitConversion_j) * EKF_P.Gain_Gain_k;

  /* Logic: '<S53>/Logical Operator' incorporates:
   *  Memory: '<S53>/oalt'
   *  Memory: '<S53>/olat'
   *  RelationalOperator: '<S53>/Relational Operator'
   *  RelationalOperator: '<S53>/Relational Operator1'
   */
  rtb_LogicalOperator = ((rtb_u0deg != EKF_DWork.olat_PreviousInput) ||
    (rtb_Gain != EKF_DWork.oalt_PreviousInput));

  /* Product: '<S52>/Product' */
  rtb_Product_d = rtb_sincos_o1_idx * rtb_sincos_o1_idx;

  /* Product: '<S52>/Product1' */
  rtb_Product1 = rtb_sincos_o2_idx * rtb_sincos_o2_idx;

  /* Outputs for Enabled SubSystem: '<S47>/Convert from geodetic to  spherical coordinates' incorporates:
   *  EnablePort: '<S50>/Enable'
   */
  if (rtb_LogicalOperator) {
    /* Product: '<S50>/b2' incorporates:
     *  Constant: '<S50>/b'
     */
    rtb_b2 = EKF_P.b_Value * EKF_P.b_Value;

    /* Product: '<S50>/a2' incorporates:
     *  Constant: '<S50>/a'
     */
    rtb_a2 = EKF_P.a_Value * EKF_P.a_Value;

    /* Sqrt: '<S93>/sqrt' incorporates:
     *  Product: '<S93>/Product'
     *  Sum: '<S93>/Sum'
     *  Sum: '<S93>/Sum1'
     */
    rtb_q = sqrt(rtb_a2 - (rtb_a2 - rtb_b2) * rtb_Product_d);

    /* Product: '<S50>/Product1' */
    rtb_fcn2 = rtb_q * rtb_Gain;

    /* Sqrt: '<S92>/sqrt' incorporates:
     *  Product: '<S92>/Product10'
     *  Product: '<S92>/Product9'
     *  Sum: '<S92>/Sum7'
     */
    rtb_d = sqrt(rtb_Product1 * rtb_a2 + rtb_b2 * rtb_Product_d);

    /* Product: '<S95>/a4' */
    rtb_Sum4 = rtb_a2 * rtb_a2;

    /* Sqrt: '<S50>/sqrt' incorporates:
     *  Gain: '<S95>/Gain'
     *  Product: '<S95>/Product1'
     *  Product: '<S95>/Product6'
     *  Product: '<S95>/Product7'
     *  Product: '<S95>/Product8'
     *  Product: '<S95>/b4'
     *  Sum: '<S95>/Sum5'
     *  Sum: '<S95>/Sum6'
     *  Sum: '<S95>/Sum9'
     */
    EKF_B.sqrt_g = sqrt((rtb_Sum4 - (rtb_Sum4 - rtb_b2 * rtb_b2) * rtb_Product_d)
                        / (rtb_q * rtb_q) + (EKF_P.Gain_Gain_n * rtb_fcn2 +
      rtb_Gain * rtb_Gain));

    /* Product: '<S90>/Product11' incorporates:
     *  Sum: '<S90>/Sum8'
     */
    EKF_B.Product11 = (rtb_Gain + rtb_d) / EKF_B.sqrt_g;

    /* Sum: '<S94>/Sum2' */
    rtb_Sum4 = rtb_a2 + rtb_fcn2;

    /* Sum: '<S94>/Sum1' */
    rtb_fcn2 += rtb_b2;

    /* Product: '<S91>/Product4' incorporates:
     *  Product: '<S91>/Product3'
     *  Product: '<S94>/Product1'
     *  Product: '<S94>/Product2'
     *  Sqrt: '<S91>/sqrt'
     *  Sum: '<S91>/Sum3'
     */
    EKF_B.Product4 = rtb_sincos_o1_idx / sqrt(rtb_Sum4 * rtb_Sum4 / (rtb_fcn2 *
      rtb_fcn2) * rtb_Product1 + rtb_Product_d);

    /* Product: '<S96>/Product12' incorporates:
     *  Product: '<S96>/Product1'
     *  Sum: '<S96>/Sum1'
     */
    EKF_B.Product12 = (rtb_a2 - rtb_b2) / (EKF_B.sqrt_g * rtb_d) *
      rtb_sincos_o2_idx * rtb_sincos_o1_idx;

    /* Sqrt: '<S97>/sqrt' incorporates:
     *  Constant: '<S97>/Constant'
     *  Product: '<S97>/Product5'
     *  Sum: '<S97>/Sum4'
     */
    EKF_B.sqrt_h = sqrt(EKF_P.Constant_Value_a2 - EKF_B.Product4 *
                        EKF_B.Product4);
  }

  /* End of Outputs for SubSystem: '<S47>/Convert from geodetic to  spherical coordinates' */

  /* Product: '<S47>/aor' incorporates:
   *  Constant: '<S47>/re'
   */
  rtb_fcn2 = EKF_P.re_Value / EKF_B.sqrt_g;

  /* Outputs for Iterator SubSystem: '<S47>/Compute magnetic vector in spherical coordinates' incorporates:
   *  ForIterator: '<S49>/For Iterator'
   */
  /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
  rtb_Product1 = EKF_P.UnitDelay_X0_c;

  /* InitializeConditions for UnitDelay: '<S49>/Unit Delay2' */
  UnitDelay2_DSTATE[0] = EKF_P.UnitDelay2_X0_e[0];
  UnitDelay2_DSTATE[1] = EKF_P.UnitDelay2_X0_e[1];
  UnitDelay2_DSTATE[2] = EKF_P.UnitDelay2_X0_e[2];
  UnitDelay2_DSTATE[3] = EKF_P.UnitDelay2_X0_e[3];
  for (s49_iter = 1; s49_iter <= EKF_P.ForIterator_IterationLimit_l; s49_iter++)
  {
    /* Switch: '<S49>/ar(n)' incorporates:
     *  Product: '<S47>/ar'
     */
    if (!(s49_iter > EKF_P.arn_Threshold)) {
      rtb_Product1 = rtb_fcn2 * rtb_fcn2;
    }

    /* End of Switch: '<S49>/ar(n)' */

    /* Product: '<S49>/Product8' */
    rtb_Product1 *= rtb_fcn2;

    /* Sum: '<S49>/Sum' incorporates:
     *  Constant: '<S49>/Constant'
     */
    qY = s49_iter + EKF_P.Constant_Value_ln;
    if ((s49_iter < 0) && ((EKF_P.Constant_Value_ln < 0) && (qY >= 0))) {
      qY = MIN_int32_T;
    } else {
      if ((s49_iter > 0) && ((EKF_P.Constant_Value_ln > 0) && (qY <= 0))) {
        qY = MAX_int32_T;
      }
    }

    /* End of Sum: '<S49>/Sum' */

    /* Outputs for Iterator SubSystem: '<S49>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S57>/For Iterator'
     */
    if (EKF_DWork.ForIterator_IterationMarker[4] != 0) {
      /* InitializeConditions for UnitDelay: '<S58>/Unit Delay1' */
      EKF_DWork.UnitDelay1_DSTATE_d = EKF_P.UnitDelay1_X0_p;

      /* InitializeConditions for UnitDelay: '<S58>/Unit Delay3' */
      EKF_DWork.UnitDelay3_DSTATE = EKF_P.UnitDelay3_X0;

      /* InitializeConditions for UnitDelay: '<S58>/Unit Delay2' */
      EKF_DWork.UnitDelay2_DSTATE_a = EKF_P.UnitDelay2_X0;

      /* InitializeConditions for UnitDelay: '<S58>/Unit Delay4' */
      EKF_DWork.UnitDelay4_DSTATE = EKF_P.UnitDelay4_X0;
    }

    for (i = 0; i < 7; i++) {
      EKF_DWork.ForIterator_IterationMarker[i] = 1U;
    }

    /* Sum: '<S49>/Sum' incorporates:
     *  Constant: '<S64>/Constant'
     *  Constant: '<S64>/Constant1'
     *  Logic: '<S64>/Logical Operator'
     *  RelationalOperator: '<S64>/Relational Operator'
     *  RelationalOperator: '<S64>/Relational Operator1'
     *  Sum: '<S57>/Sum1'
     */
    for (s57_iter = 1; s57_iter <= qY; s57_iter++) {
      /* Sum: '<S57>/Sum1' incorporates:
       *  Constant: '<S57>/Constant'
       */
      qY_4 = s57_iter - EKF_P.Constant_Value_km;
      if ((s57_iter < 0) && ((EKF_P.Constant_Value_km >= 0) && (qY_4 >= 0))) {
        qY_4 = MIN_int32_T;
      } else {
        if ((s57_iter >= 0) && ((EKF_P.Constant_Value_km < 0) && (qY_4 < 0))) {
          qY_4 = MAX_int32_T;
        }
      }

      /* End of Sum: '<S57>/Sum1' */

      /* Outputs for Enabled SubSystem: '<S57>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' incorporates:
       *  EnablePort: '<S59>/Enable'
       */
      if (rtb_LogicalOperator) {
        /* Sum: '<S59>/Sum' incorporates:
         *  Constant: '<S59>/Constant'
         *  Sum: '<S57>/Sum1'
         */
        qY_3 = s49_iter + EKF_P.Constant_Value_h;
        if ((s49_iter < 0) && ((EKF_P.Constant_Value_h < 0) && (qY_3 >= 0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((s49_iter > 0) && ((EKF_P.Constant_Value_h > 0) && (qY_3 <= 0))) {
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

        /* End of Sum: '<S59>/Sum' */

        /* If: '<S59>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' incorporates:
         *  Sum: '<S57>/Sum1'
         */
        if (s49_iter == qY_4) {
          /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
           *  ActionPort: '<S73>/Action Port'
           */
          /* Sum: '<S77>/Sum2' incorporates:
           *  Constant: '<S77>/Constant'
           */
          qY_1 = qY_4 - EKF_P.Constant_Value_c;
          if ((qY_4 < 0) && ((EKF_P.Constant_Value_c >= 0) && (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((qY_4 >= 0) && ((EKF_P.Constant_Value_c < 0) && (qY_1 < 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          /* End of Sum: '<S77>/Sum2' */

          /* Gain: '<S77>/Gain' incorporates:
           *  Sum: '<S77>/Sum2'
           */
          s98_iter = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_c, qY_1);

          /* Selector: '<S73>/Selector' incorporates:
           *  Sum: '<S77>/Sum1'
           */
          qY_1 = s49_iter + s98_iter;
          if ((s49_iter < 0) && ((s98_iter < 0) && (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((s49_iter > 0) && ((s98_iter > 0) && (qY_1 <= 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          /* End of Selector: '<S73>/Selector' */

          /* Product: '<S73>/Product1' incorporates:
           *  Selector: '<S73>/Selector'
           *  Sum: '<S77>/Sum1'
           *  UnitDelay: '<S59>/Unit Delay1'
           */
          EKF_B.Merge_j[0] = EKF_DWork.UnitDelay1_DSTATE_h[qY_1 - 1] *
            EKF_B.sqrt_h;

          /* Selector: '<S73>/Selector' incorporates:
           *  Sum: '<S77>/Sum1'
           */
          qY_1 = s49_iter + s98_iter;
          if ((s49_iter < 0) && ((s98_iter < 0) && (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((s49_iter > 0) && ((s98_iter > 0) && (qY_1 <= 0))) {
              qY_1 = MAX_int32_T;
            }
          }

          /* End of Selector: '<S73>/Selector' */

          /* Sum: '<S73>/Sum' incorporates:
           *  Product: '<S73>/Product'
           *  Product: '<S73>/Product2'
           *  Selector: '<S73>/Selector'
           *  Selector: '<S73>/Selector1'
           *  Sum: '<S77>/Sum1'
           *  UnitDelay: '<S59>/Unit Delay1'
           */
          EKF_B.Merge_j[1] = EKF_DWork.UnitDelay_DSTATE_d[((s49_iter - 1) * 13 +
            qY_4) - 1] * EKF_B.sqrt_h + EKF_DWork.UnitDelay1_DSTATE_h[qY_1 - 1] *
            EKF_B.Product4;

          /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
        } else if ((s49_iter == 1) && (qY_4 == 0)) {
          /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S74>/Action Port'
           */
          /* Selector: '<S74>/Selector' incorporates:
           *  Gain: '<S79>/Gain'
           *  Sum: '<S79>/Sum1'
           */
          r = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_e, 0);
          qY_1 = 1 + r;
          if ((r > 0) && (qY_1 <= 0)) {
            qY_1 = MAX_int32_T;
          }

          /* End of Selector: '<S74>/Selector' */

          /* Product: '<S74>/Product3' incorporates:
           *  Selector: '<S74>/Selector'
           *  Sum: '<S79>/Sum1'
           *  UnitDelay: '<S59>/Unit Delay1'
           */
          EKF_B.Merge_j[0] = EKF_DWork.UnitDelay1_DSTATE_h[qY_1 - 1] *
            EKF_B.Product4;

          /* Selector: '<S74>/Selector1' incorporates:
           *  Constant: '<S80>/Constant'
           *  Sum: '<S80>/Sum'
           */
          qY_1 = EKF_P.Constant_Value_ix;

          /* Selector: '<S74>/Selector' incorporates:
           *  Gain: '<S79>/Gain'
           *  Sum: '<S79>/Sum1'
           */
          r = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_e, 0);
          qY_0 = 1 + r;
          if ((r > 0) && (qY_0 <= 0)) {
            qY_0 = MAX_int32_T;
          }

          /* End of Selector: '<S74>/Selector' */

          /* Sum: '<S74>/Sum' incorporates:
           *  Product: '<S74>/Product'
           *  Product: '<S74>/Product2'
           *  Selector: '<S74>/Selector'
           *  Selector: '<S74>/Selector1'
           *  Sum: '<S79>/Sum1'
           *  Sum: '<S80>/Sum'
           *  UnitDelay: '<S59>/Unit Delay1'
           */
          EKF_B.Merge_j[1] = EKF_DWork.UnitDelay_DSTATE_d[qY_1 - 1] *
            EKF_B.Product4 - EKF_DWork.UnitDelay1_DSTATE_h[qY_0 - 1] *
            EKF_B.sqrt_h;

          /* End of Outputs for SubSystem: '<S59>/If Action Subsystem1' */
        } else {
          if ((s49_iter > 1) && (s49_iter != qY_4)) {
            /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S75>/Action Port'
             */
            /* Sum: '<S83>/Sum' incorporates:
             *  Constant: '<S83>/Constant'
             */
            qY_1 = qY_4 + EKF_P.Constant_Value_f;
            if ((qY_4 < 0) && ((EKF_P.Constant_Value_f < 0) && (qY_1 >= 0))) {
              qY_1 = MIN_int32_T;
            } else {
              if ((qY_4 > 0) && ((EKF_P.Constant_Value_f > 0) && (qY_1 <= 0))) {
                qY_1 = MAX_int32_T;
              }
            }

            s98_iter = qY_1 - 1;

            /* End of Sum: '<S83>/Sum' */

            /* Sum: '<S83>/Sum2' incorporates:
             *  Constant: '<S83>/Constant1'
             */
            qY_1 = s49_iter - EKF_P.Constant1_Value_f;
            if ((EKF_P.Constant1_Value_f < 0) && (qY_1 < 0)) {
              qY_1 = MAX_int32_T;
            }

            /* End of Sum: '<S83>/Sum2' */

            /* Product: '<S75>/Product' incorporates:
             *  Selector: '<S75>/Selector1'
             */
            rtb_Product_d = EKF_DWork.UnitDelay_DSTATE_d[(s49_iter - 1) * 13 +
              s98_iter] * EKF_B.Product4;

            /* Sum: '<S84>/Sum2' incorporates:
             *  Constant: '<S84>/Constant1'
             */
            qY_0 = s49_iter - EKF_P.Constant1_Value_bw;
            if ((EKF_P.Constant1_Value_bw < 0) && (qY_0 < 0)) {
              qY_0 = MAX_int32_T;
            }

            /* End of Sum: '<S84>/Sum2' */

            /* Switch: '<S75>/Switch' incorporates:
             *  Constant: '<S75>/Constant'
             *  DataTypeConversion: '<S84>/Data Type Conversion'
             *  RelationalOperator: '<S84>/Relational Operator'
             *  Selector: '<S75>/Selector1'
             *  Sum: '<S83>/Sum2'
             *  Sum: '<S84>/Sum2'
             */
            if ((real_T)(qY_0 >= qY_4) > EKF_P.Switch_Threshold) {
              rtb_a2 = EKF_DWork.UnitDelay_DSTATE_d[(qY_1 - 1) * 13 + s98_iter];
            } else {
              rtb_a2 = EKF_P.Constant_Value_gy;
            }

            /* End of Switch: '<S75>/Switch' */

            /* Sum: '<S82>/Sum' incorporates:
             *  Constant: '<S82>/Constant'
             */
            qY_1 = s49_iter + EKF_P.Constant_Value_fu;
            if ((EKF_P.Constant_Value_fu > 0) && (qY_1 <= 0)) {
              qY_1 = MAX_int32_T;
            }

            qY_0 = qY_4 + EKF_P.Constant_Value_fu;
            if ((qY_4 < 0) && ((EKF_P.Constant_Value_fu < 0) && (qY_0 >= 0))) {
              qY_0 = MIN_int32_T;
            } else {
              if ((qY_4 > 0) && ((EKF_P.Constant_Value_fu > 0) && (qY_0 <= 0)))
              {
                qY_0 = MAX_int32_T;
              }
            }

            /* End of Sum: '<S82>/Sum' */

            /* Product: '<S75>/Product1' incorporates:
             *  Constant: '<S75>/k[13][13]'
             *  Selector: '<S75>/Selector2'
             *  Sum: '<S82>/Sum'
             */
            rtb_q = EKF_P.k1313_Value_k[((qY_1 - 1) * 13 + qY_0) - 1] * rtb_a2;

            /* Gain: '<S81>/Gain' */
            s98_iter = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_d, qY_4);

            /* Sum: '<S85>/Sum2' incorporates:
             *  Constant: '<S85>/Constant1'
             */
            r = s49_iter - EKF_P.Constant1_Value_kv;
            if ((EKF_P.Constant1_Value_kv < 0) && (r < 0)) {
              r = MAX_int32_T;
            }

            /* End of Sum: '<S85>/Sum2' */

            /* Switch: '<S75>/Switch1' incorporates:
             *  Constant: '<S75>/Constant1'
             *  DataTypeConversion: '<S85>/Data Type Conversion'
             *  RelationalOperator: '<S85>/Relational Operator'
             *  Selector: '<S75>/Selector'
             *  Sum: '<S81>/Sum1'
             *  Sum: '<S85>/Sum2'
             *  UnitDelay: '<S59>/Unit Delay1'
             */
            if ((real_T)(r >= qY_4) > EKF_P.Switch1_Threshold) {
              /* Selector: '<S75>/Selector' incorporates:
               *  Constant: '<S81>/Constant1'
               *  Sum: '<S81>/Sum1'
               *  Sum: '<S81>/Sum2'
               */
              r = s49_iter - EKF_P.Constant1_Value_d;
              if ((EKF_P.Constant1_Value_d < 0) && (r < 0)) {
                r = MAX_int32_T;
              }

              i = r + s98_iter;
              if ((r < 0) && ((s98_iter < 0) && (i >= 0))) {
                i = MIN_int32_T;
              } else {
                if ((r > 0) && ((s98_iter > 0) && (i <= 0))) {
                  i = MAX_int32_T;
                }
              }

              /* End of Selector: '<S75>/Selector' */
              rtb_a2 = EKF_DWork.UnitDelay1_DSTATE_h[i - 1];
            } else {
              rtb_a2 = EKF_P.Constant1_Value_j;
            }

            /* End of Switch: '<S75>/Switch1' */

            /* Selector: '<S75>/Selector' incorporates:
             *  Sum: '<S81>/Sum1'
             */
            r = s49_iter + s98_iter;
            if ((s98_iter > 0) && (r <= 0)) {
              r = MAX_int32_T;
            }

            /* End of Selector: '<S75>/Selector' */

            /* Sum: '<S75>/Sum' incorporates:
             *  Product: '<S75>/Product4'
             *  Selector: '<S75>/Selector'
             *  Sum: '<S81>/Sum1'
             *  UnitDelay: '<S59>/Unit Delay1'
             */
            EKF_B.Merge_j[1] = (rtb_Product_d - EKF_DWork.UnitDelay1_DSTATE_h[r
                                - 1] * EKF_B.sqrt_h) - rtb_q;

            /* Selector: '<S75>/Selector' incorporates:
             *  Sum: '<S81>/Sum1'
             */
            r = s49_iter + s98_iter;
            if ((s98_iter > 0) && (r <= 0)) {
              r = MAX_int32_T;
            }

            /* End of Selector: '<S75>/Selector' */

            /* Sum: '<S75>/Sum1' incorporates:
             *  Constant: '<S75>/k[13][13]'
             *  Product: '<S75>/Product2'
             *  Product: '<S75>/Product3'
             *  Selector: '<S75>/Selector'
             *  Selector: '<S75>/Selector2'
             *  Sum: '<S81>/Sum1'
             *  Sum: '<S82>/Sum'
             *  UnitDelay: '<S59>/Unit Delay1'
             */
            EKF_B.Merge_j[0] = EKF_DWork.UnitDelay1_DSTATE_h[r - 1] *
              EKF_B.Product4 - EKF_P.k1313_Value_k[((qY_1 - 1) * 13 + qY_0) - 1]
              * rtb_a2;

            /* End of Outputs for SubSystem: '<S59>/If Action Subsystem2' */
          }
        }

        /* End of If: '<S59>/if n == m elseif (n==1&m==0) elseif (n>1&m~=n)' */

        /* Assignment: '<S59>/Assignment' incorporates:
         *  Sum: '<S59>/Sum'
         *  UnitDelay: '<S59>/Unit Delay'
         */
        if (EKF_DWork.ForIterator_IterationMarker[2] < 2) {
          EKF_DWork.ForIterator_IterationMarker[2] = 2U;
          memcpy((void *)(&EKF_B.Assignment_g[0]), (void *)
                 EKF_DWork.UnitDelay_DSTATE_d, 169U * sizeof(real_T));
        }

        EKF_B.Assignment_g[(qY_2 + 13 * (qY_3 - 1)) - 1] = EKF_B.Merge_j[1];

        /* End of Assignment: '<S59>/Assignment' */

        /* Assignment: '<S59>/Assignment_snorm' incorporates:
         *  Constant: '<S76>/Constant'
         *  Gain: '<S76>/Gain'
         *  Sum: '<S59>/Sum'
         *  Sum: '<S76>/Sum1'
         *  Sum: '<S76>/Sum2'
         *  UnitDelay: '<S59>/Unit Delay1'
         */
        if (EKF_DWork.ForIterator_IterationMarker[3] < 2) {
          EKF_DWork.ForIterator_IterationMarker[3] = 2U;
          memcpy((void *)(&EKF_B.Assignment_snorm[0]), (void *)
                 EKF_DWork.UnitDelay1_DSTATE_h, 169U * sizeof(real_T));
        }

        qY_1 = qY_2 - EKF_P.Constant_Value_ie;
        if ((qY_2 < 0) && ((EKF_P.Constant_Value_ie >= 0) && (qY_1 >= 0))) {
          qY_1 = MIN_int32_T;
        } else {
          if ((qY_2 >= 0) && ((EKF_P.Constant_Value_ie < 0) && (qY_1 < 0))) {
            qY_1 = MAX_int32_T;
          }
        }

        EKF_B.Assignment_snorm[(int32_T)((real_T)qY_3 + (real_T)
          mul_s32_s32_s32_sat(EKF_P.Gain_Gain_j, qY_1)) - 1] = EKF_B.Merge_j[0];
        for (i = 0; i < 169; i++) {
          /* Update for UnitDelay: '<S59>/Unit Delay' */
          EKF_DWork.UnitDelay_DSTATE_d[i] = EKF_B.Assignment_g[i];

          /* Update for UnitDelay: '<S59>/Unit Delay1' */
          EKF_DWork.UnitDelay1_DSTATE_h[i] = EKF_B.Assignment_snorm[i];
        }

        /* End of Assignment: '<S59>/Assignment_snorm' */
      }

      /* End of Outputs for SubSystem: '<S57>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

      /* Sum: '<S58>/Sum' incorporates:
       *  Constant: '<S58>/Constant'
       *  Sum: '<S57>/Sum1'
       */
      qY_3 = s49_iter + EKF_P.Constant_Value_l;
      if ((s49_iter < 0) && ((EKF_P.Constant_Value_l < 0) && (qY_3 >= 0))) {
        qY_3 = MIN_int32_T;
      } else {
        if ((s49_iter > 0) && ((EKF_P.Constant_Value_l > 0) && (qY_3 <= 0))) {
          qY_3 = MAX_int32_T;
        }
      }

      qY_2 = qY_4 + EKF_P.Constant_Value_l;
      if ((qY_4 < 0) && ((EKF_P.Constant_Value_l < 0) && (qY_2 >= 0))) {
        qY_2 = MIN_int32_T;
      } else {
        if ((qY_4 > 0) && ((EKF_P.Constant_Value_l > 0) && (qY_2 <= 0))) {
          qY_2 = MAX_int32_T;
        }
      }

      /* End of Sum: '<S58>/Sum' */

      /* Selector: '<S58>/dp[n][m]' incorporates:
       *  Sum: '<S58>/Sum'
       */
      rtb_Product_d = EKF_B.Assignment_g[((qY_3 - 1) * 13 + qY_2) - 1];

      /* Outputs for Enabled SubSystem: '<S57>/Time adjust the gauss coefficients' incorporates:
       *  EnablePort: '<S60>/Enable'
       */
      if (rtb_RelationalOperator) {
        /* Outputs for Atomic SubSystem: '<S60>/If Action Subsystem' */
        /* Sum: '<S86>/Sum1' incorporates:
         *  Constant: '<S86>/Constant1'
         *  Sum: '<S57>/Sum1'
         */
        qY_3 = qY_4 + EKF_P.Constant1_Value_jr;
        if ((qY_4 < 0) && ((EKF_P.Constant1_Value_jr < 0) && (qY_3 >= 0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((qY_4 > 0) && ((EKF_P.Constant1_Value_jr > 0) && (qY_3 <= 0))) {
            qY_3 = MAX_int32_T;
          }
        }

        s98_iter = qY_3 - 1;

        /* End of Sum: '<S86>/Sum1' */

        /* Sum: '<S86>/Sum2' incorporates:
         *  Constant: '<S86>/Constant'
         */
        qY_3 = s49_iter + EKF_P.Constant_Value_b;
        if ((s49_iter < 0) && ((EKF_P.Constant_Value_b < 0) && (qY_3 >= 0))) {
          qY_3 = MIN_int32_T;
        } else {
          if ((s49_iter > 0) && ((EKF_P.Constant_Value_b > 0) && (qY_3 <= 0))) {
            qY_3 = MAX_int32_T;
          }
        }

        i = qY_3 - 1;

        /* End of Sum: '<S86>/Sum2' */
        /* End of Outputs for SubSystem: '<S60>/If Action Subsystem' */

        /* Assignment: '<S60>/Assignment' incorporates:
         *  Constant: '<S60>/c[maxdef][maxdef]'
         *  Constant: '<S60>/cd[maxdef][maxdef]'
         *  Product: '<S86>/Product'
         *  Selector: '<S86>/c[m][n]'
         *  Selector: '<S86>/cd[m][n]'
         *  Sum: '<S86>/Sum'
         *  UnitDelay: '<S60>/Unit Delay'
         */
        if (EKF_DWork.ForIterator_IterationMarker[5] < 2) {
          EKF_DWork.ForIterator_IterationMarker[5] = 2U;
          memcpy((void *)&Assignment_f[0], (void *)EKF_DWork.UnitDelay_DSTATE_g,
                 169U * sizeof(real_T));
        }

        /* Outputs for Atomic SubSystem: '<S60>/If Action Subsystem' */
        Assignment_f[s98_iter + 13 * i] = EKF_P.cdmaxdefmaxdef_Value[13 * i +
          s98_iter] * rtb_Sum_m + EKF_P.cmaxdefmaxdef_Value[13 * i + s98_iter];

        /* End of Assignment: '<S60>/Assignment' */
        /* End of Outputs for SubSystem: '<S60>/If Action Subsystem' */

        /* Switch: '<S87>/tc_old' incorporates:
         *  Constant: '<S87>/zeros(maxdef+1,maxdef+1)'
         *  UnitDelay: '<S87>/Unit Delay'
         */
        for (i = 0; i < 169; i++) {
          if (s49_iter > EKF_P.tc_old_Threshold) {
            rtb_tc_old[i] = EKF_DWork.UnitDelay_DSTATE_o[i];
          } else {
            rtb_tc_old[i] = EKF_P.zerosmaxdef1maxdef1_Value[i];
          }
        }

        /* End of Switch: '<S87>/tc_old' */

        /* If: '<S87>/If' incorporates:
         *  Sum: '<S57>/Sum1'
         */
        if (qY_4 != 0) {
          /* Outputs for IfAction SubSystem: '<S87>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S88>/Action Port'
           */
          /* Sum: '<S88>/Sum2' incorporates:
           *  Constant: '<S88>/Constant'
           */
          qY_3 = s49_iter + EKF_P.Constant_Value_ik;
          if ((s49_iter < 0) && ((EKF_P.Constant_Value_ik < 0) && (qY_3 >= 0)))
          {
            qY_3 = MIN_int32_T;
          } else {
            if ((s49_iter > 0) && ((EKF_P.Constant_Value_ik > 0) && (qY_3 <= 0)))
            {
              qY_3 = MAX_int32_T;
            }
          }

          s98_iter = qY_3 - 1;

          /* End of Sum: '<S88>/Sum2' */

          /* Assignment: '<S88>/Assignment2' incorporates:
           *  Constant: '<S60>/c[maxdef][maxdef]'
           *  Constant: '<S60>/cd[maxdef][maxdef]'
           *  Product: '<S88>/Product'
           *  Selector: '<S88>/c[m][n]'
           *  Selector: '<S88>/cd[m][n]'
           *  Sum: '<S88>/Sum'
           */
          if (EKF_DWork.ForIterator_IterationMarker[6] < 2) {
            EKF_DWork.ForIterator_IterationMarker[6] = 2U;
            memcpy((void *)&Assignment[0], (void *)&rtb_tc_old[0], 169U * sizeof
                   (real_T));
          }

          Assignment[s98_iter + 13 * (qY_4 - 1)] = EKF_P.cdmaxdefmaxdef_Value
            [(qY_4 - 1) * 13 + s98_iter] * rtb_Sum_m +
            EKF_P.cmaxdefmaxdef_Value[(qY_4 - 1) * 13 + s98_iter];

          /* End of Assignment: '<S88>/Assignment2' */

          /* Gain: '<S88>/Gain' */
          for (i = 0; i < 169; i++) {
            rtb_tc_old[i] = EKF_P.Gain_Gain * Assignment[i];
          }

          /* End of Gain: '<S88>/Gain' */
          /* End of Outputs for SubSystem: '<S87>/If Action Subsystem1' */
        } else {
        }

        for (i = 0; i < 169; i++) {
          /* Sum: '<S60>/Sum2' */
          EKF_B.Sum2_j[i] = Assignment_f[i] + rtb_tc_old[i];

          /* Update for UnitDelay: '<S60>/Unit Delay' */
          EKF_DWork.UnitDelay_DSTATE_g[i] = Assignment_f[i];

          /* Update for UnitDelay: '<S87>/Unit Delay' */
          EKF_DWork.UnitDelay_DSTATE_o[i] = rtb_tc_old[i];
        }

        /* End of If: '<S87>/If' */
      }

      /* End of Outputs for SubSystem: '<S57>/Time adjust the gauss coefficients' */

      /* Sum: '<S63>/Sum4' incorporates:
       *  Constant: '<S63>/Constant1'
       *  Sum: '<S57>/Sum1'
       */
      rtb_a2 = (real_T)qY_4 + EKF_P.Constant1_Value_p;

      /* Selector: '<S63>/cp[m+1]' incorporates:
       *  SignalConversion: '<S63>/TmpSignal ConversionAtcp[m+1]Inport1'
       */
      tmp_0[0] = EKF_B.cp1;
      tmp_0[1] = EKF_B.cp2;

      /* SignalConversion: '<S63>/TmpSignal ConversionAtsp[m+1]Inport1' */
      rtb_TmpSignalConversionAtspm1In[0] = EKF_B.sp1;
      rtb_TmpSignalConversionAtspm1In[1] = EKF_B.sp2;
      for (qY_3 = 0; qY_3 < 11; qY_3++) {
        /* Selector: '<S63>/cp[m+1]' incorporates:
         *  SignalConversion: '<S63>/TmpSignal ConversionAtcp[m+1]Inport1'
         */
        tmp_0[qY_3 + 2] = EKF_B.Assignment1[qY_3];
        rtb_TmpSignalConversionAtspm1In[qY_3 + 2] = EKF_B.Assignment[qY_3];
      }

      /* End of SignalConversion: '<S63>/TmpSignal ConversionAtsp[m+1]Inport1' */

      /* If: '<S63>/If' incorporates:
       *  Sum: '<S57>/Sum1'
       */
      if (qY_4 == 0) {
        /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem' incorporates:
         *  ActionPort: '<S69>/Action Port'
         */
        /* Sum: '<S69>/Sum' incorporates:
         *  Constant: '<S69>/Constant'
         */
        rtb_sincos_o1_m_idx = (real_T)s49_iter + EKF_P.Constant_Value_ip;

        /* Product: '<S69>/Product' incorporates:
         *  Constant: '<S69>/Constant'
         *  Selector: '<S63>/cp[m+1]'
         *  Selector: '<S63>/sp[m+1]'
         *  Selector: '<S69>/Selector'
         *  Sum: '<S69>/Sum'
         */
        EKF_B.Merge[0] = EKF_B.Sum2_j[(((int32_T)rtb_sincos_o1_m_idx - 1) * 13 +
                                       (int32_T)EKF_P.Constant_Value_ip) - 1] *
          tmp_0[(int32_T)rtb_a2 - 1];
        EKF_B.Merge[1] = EKF_B.Sum2_j[(((int32_T)rtb_sincos_o1_m_idx - 1) * 13 +
                                       (int32_T)EKF_P.Constant_Value_ip) - 1] *
          rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_a2 - 1];

        /* End of Outputs for SubSystem: '<S63>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S63>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S70>/Action Port'
         */
        /* Sum: '<S71>/Sum' incorporates:
         *  Constant: '<S71>/Constant'
         */
        rtb_sincos_o1_m_idx = (real_T)s49_iter + EKF_P.Constant_Value_a;
        rtb_sincos_o1_m_idx_0 = (real_T)qY_4 + EKF_P.Constant_Value_a;

        /* Selector: '<S70>/Selector' */
        rtb_d = rtb_sincos_o1_m_idx;

        /* Product: '<S70>/Product' incorporates:
         *  Selector: '<S63>/cp[m+1]'
         *  Selector: '<S63>/sp[m+1]'
         *  Selector: '<S70>/Selector'
         */
        rtb_sincos_o1_m_idx = EKF_B.Sum2_j[(((int32_T)rtb_sincos_o1_m_idx - 1) *
          13 + (int32_T)rtb_sincos_o1_m_idx_0) - 1] * tmp_0[(int32_T)rtb_a2 - 1];
        rtb_sincos_o1_m_idx_0 = EKF_B.Sum2_j[(((int32_T)rtb_d - 1) * 13 +
          (int32_T)rtb_sincos_o1_m_idx_0) - 1] *
          rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_a2 - 1];

        /* Sum: '<S70>/Sum' incorporates:
         *  Constant: '<S72>/Constant'
         *  Product: '<S70>/Product1'
         *  Selector: '<S63>/sp[m+1]'
         *  Selector: '<S70>/Selector1'
         *  Sum: '<S72>/Sum'
         */
        EKF_B.Merge[0] = EKF_B.Sum2_j[((qY_4 - 1) * 13 + (int32_T)((real_T)
          s49_iter + EKF_P.Constant_Value_e)) - 1] *
          rtb_TmpSignalConversionAtspm1In[(int32_T)rtb_a2 - 1] +
          rtb_sincos_o1_m_idx;

        /* Sum: '<S70>/Sum1' incorporates:
         *  Constant: '<S72>/Constant'
         *  Product: '<S70>/Product1'
         *  Selector: '<S63>/cp[m+1]'
         *  Selector: '<S70>/Selector1'
         *  Sum: '<S72>/Sum'
         */
        EKF_B.Merge[1] = rtb_sincos_o1_m_idx_0 - EKF_B.Sum2_j[((qY_4 - 1) * 13 +
          (int32_T)((real_T)s49_iter + EKF_P.Constant_Value_e)) - 1] * tmp_0
          [(int32_T)rtb_a2 - 1];

        /* End of Outputs for SubSystem: '<S63>/If Action Subsystem1' */
      }

      /* End of If: '<S63>/If' */

      /* Selector: '<S58>/snorm[n+m*13]' incorporates:
       *  Constant: '<S62>/Constant'
       *  Gain: '<S62>/Gain'
       *  Sum: '<S57>/Sum1'
       *  Sum: '<S62>/Sum1'
       */
      qY_3 = EKF_P.Constant_Value_kz + s49_iter;
      if ((EKF_P.Constant_Value_kz < 0) && ((s49_iter < 0) && (qY_3 >= 0))) {
        qY_3 = MIN_int32_T;
      } else {
        if ((EKF_P.Constant_Value_kz > 0) && ((s49_iter > 0) && (qY_3 <= 0))) {
          qY_3 = MAX_int32_T;
        }
      }

      r = mul_s32_s32_s32_sat(EKF_P.Gain_Gain_np, qY_4);
      qY_2 = qY_3 + r;
      if ((qY_3 < 0) && ((r < 0) && (qY_2 >= 0))) {
        qY_2 = MIN_int32_T;
      } else {
        if ((qY_3 > 0) && ((r > 0) && (qY_2 <= 0))) {
          qY_2 = MAX_int32_T;
        }
      }

      /* End of Selector: '<S58>/snorm[n+m*13]' */

      /* Product: '<S58>/par' incorporates:
       *  Selector: '<S58>/snorm[n+m*13]'
       *  Sum: '<S62>/Sum1'
       */
      rtb_a2 = EKF_B.Assignment_snorm[qY_2 - 1] * rtb_Product1;

      /* Sum: '<S58>/Sum4' incorporates:
       *  Constant: '<S58>/Constant1'
       *  Sum: '<S57>/Sum1'
       */
      qY_3 = s49_iter + EKF_P.Constant1_Value_ji;
      if ((s49_iter < 0) && ((EKF_P.Constant1_Value_ji < 0) && (qY_3 >= 0))) {
        qY_3 = MIN_int32_T;
      } else {
        if ((s49_iter > 0) && ((EKF_P.Constant1_Value_ji > 0) && (qY_3 <= 0))) {
          qY_3 = MAX_int32_T;
        }
      }

      qY_2 = qY_4 + EKF_P.Constant1_Value_ji;
      if ((qY_4 < 0) && ((EKF_P.Constant1_Value_ji < 0) && (qY_2 >= 0))) {
        qY_2 = MIN_int32_T;
      } else {
        if ((qY_4 > 0) && ((EKF_P.Constant1_Value_ji > 0) && (qY_2 <= 0))) {
          qY_2 = MAX_int32_T;
        }
      }

      /* End of Sum: '<S58>/Sum4' */

      /* Outputs for Enabled SubSystem: '<S58>/Special case - North//South Geographic Pole' incorporates:
       *  EnablePort: '<S61>/Enable'
       */
      if ((EKF_B.sqrt_h == EKF_P.Constant1_Value_a) && (EKF_P.Constant_Value_d ==
           qY_4)) {
        if (!EKF_DWork.SpecialcaseNorthSouthGeographic) {
          EKF_DWork.SpecialcaseNorthSouthGeographic = TRUE;
        }

        /* If: '<S61>/n ==1' */
        if (s49_iter == 1) {
          /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S65>/Action Port'
           */
          /* Assignment: '<S65>/Assignment2' incorporates:
           *  Constant: '<S65>/Constant'
           *  Selector: '<S65>/pp[n-1]'
           *  Sum: '<S65>/Sum2'
           *  UnitDelay: '<S61>/Unit Delay1'
           */
          if (EKF_DWork.ForIterator_IterationMarker[0] < 2) {
            EKF_DWork.ForIterator_IterationMarker[0] = 2U;
            memcpy((void *)(&EKF_B.Assignment2_d[0]), (void *)
                   EKF_DWork.UnitDelay1_DSTATE_dg, 13U * sizeof(real_T));
          }

          EKF_B.Assignment2_d[(int32_T)(1.0 + EKF_P.Constant_Value_g) - 1] =
            EKF_DWork.UnitDelay1_DSTATE_dg[0];

          /* End of Assignment: '<S65>/Assignment2' */
          /* End of Outputs for SubSystem: '<S61>/If Action Subsystem1' */
        } else {
          /* Outputs for IfAction SubSystem: '<S61>/If Action Subsystem2' incorporates:
           *  ActionPort: '<S66>/Action Port'
           */
          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/Constant'
           */
          qY_1 = s49_iter + EKF_P.Constant_Value_k;
          if ((s49_iter < 0) && ((EKF_P.Constant_Value_k < 0) && (qY_1 >= 0))) {
            qY_1 = MIN_int32_T;
          } else {
            if ((s49_iter > 0) && ((EKF_P.Constant_Value_k > 0) && (qY_1 <= 0)))
            {
              qY_1 = MAX_int32_T;
            }
          }

          qY_0 = qY_4 + EKF_P.Constant_Value_k;
          if ((qY_4 < 0) && ((EKF_P.Constant_Value_k < 0) && (qY_0 >= 0))) {
            qY_0 = MIN_int32_T;
          } else {
            if ((qY_4 > 0) && ((EKF_P.Constant_Value_k > 0) && (qY_0 <= 0))) {
              qY_0 = MAX_int32_T;
            }
          }

          /* End of Sum: '<S68>/Sum' */

          /* Assignment: '<S66>/Assignment2' incorporates:
           *  Constant: '<S66>/Constant'
           *  Sum: '<S66>/Sum2'
           *  UnitDelay: '<S61>/Unit Delay1'
           */
          if (EKF_DWork.ForIterator_IterationMarker[1] < 2) {
            EKF_DWork.ForIterator_IterationMarker[1] = 2U;
            memcpy((void *)(&EKF_B.Assignment2_h[0]), (void *)
                   EKF_DWork.UnitDelay1_DSTATE_dg, 13U * sizeof(real_T));
          }

          qY_4 = s49_iter + EKF_P.Constant_Value_er;
          if ((s49_iter < 0) && ((EKF_P.Constant_Value_er < 0) && (qY_4 >= 0)))
          {
            qY_4 = MIN_int32_T;
          } else {
            if ((s49_iter > 0) && ((EKF_P.Constant_Value_er > 0) && (qY_4 <= 0)))
            {
              qY_4 = MAX_int32_T;
            }
          }

          /* End of Assignment: '<S66>/Assignment2' */

          /* Selector: '<S66>/pp[n-2] pp[n-1]' incorporates:
           *  Constant: '<S67>/Constant1'
           *  Sum: '<S67>/Sum2'
           */
          r = s49_iter - EKF_P.Constant1_Value_ao;
          if ((s49_iter < 0) && ((EKF_P.Constant1_Value_ao >= 0) && (r >= 0))) {
            r = MIN_int32_T;
          } else {
            if ((s49_iter >= 0) && ((EKF_P.Constant1_Value_ao < 0) && (r < 0)))
            {
              r = MAX_int32_T;
            }
          }

          /* End of Selector: '<S66>/pp[n-2] pp[n-1]' */

          /* Assignment: '<S66>/Assignment2' incorporates:
           *  Constant: '<S66>/k[13][13]'
           *  Product: '<S66>/Product1'
           *  Product: '<S66>/Product2'
           *  Selector: '<S66>/Selector2'
           *  Selector: '<S66>/pp[n-2] pp[n-1]'
           *  Sum: '<S66>/Sum1'
           *  Sum: '<S66>/Sum2'
           *  Sum: '<S67>/Sum2'
           *  Sum: '<S68>/Sum'
           *  UnitDelay: '<S61>/Unit Delay1'
           */
          EKF_B.Assignment2_h[qY_4 - 1] =
            EKF_DWork.UnitDelay1_DSTATE_dg[s49_iter - 1] * EKF_B.Product4 -
            EKF_P.k1313_Value[((qY_1 - 1) * 13 + qY_0) - 1] *
            EKF_DWork.UnitDelay1_DSTATE_dg[r - 1];

          /* End of Outputs for SubSystem: '<S61>/If Action Subsystem2' */
        }

        /* End of If: '<S61>/n ==1' */

        /* SignalConversion: '<S61>/TmpSignal ConversionAtpp[n]Inport1' incorporates:
         *  UnitDelay: '<S61>/Unit Delay1'
         */
        rtb_TmpSignalConversionAtspm1In[0] = EKF_DWork.UnitDelay1_DSTATE_dg[0];
        rtb_TmpSignalConversionAtspm1In[1] = EKF_B.Assignment2_d[1];
        memcpy((void *)&rtb_TmpSignalConversionAtspm1In[2], (void *)
               (&EKF_B.Assignment2_h[2]), 11U * sizeof(real_T));

        /* Product: '<S61>/Product2' incorporates:
         *  Constant: '<S61>/Constant'
         *  Constant: '<S61>/Constant1'
         *  Selector: '<S61>/pp[n]'
         *  Sum: '<S61>/Sum2'
         */
        EKF_B.Product2 = rtb_TmpSignalConversionAtspm1In[(int32_T)((real_T)
          s49_iter + EKF_P.Constant1_Value) - 1] * rtb_Product1 *
          EKF_P.Constant_Value_i * EKF_B.Merge[1];

        /* Update for UnitDelay: '<S61>/Unit Delay1' */
        memcpy((void *)EKF_DWork.UnitDelay1_DSTATE_dg, (void *)
               &rtb_TmpSignalConversionAtspm1In[0], 13U * sizeof(real_T));
      } else {
        if (EKF_DWork.SpecialcaseNorthSouthGeographic) {
          /* Disable for Outport: '<S61>/bpp' */
          EKF_B.Product2 = EKF_P.bpp_Y0;
          EKF_DWork.SpecialcaseNorthSouthGeographic = FALSE;
        }
      }

      /* End of Outputs for SubSystem: '<S58>/Special case - North//South Geographic Pole' */

      /* Sum: '<S58>/Sum1' incorporates:
       *  Constant: '<S64>/Constant'
       *  Constant: '<S64>/Constant1'
       *  Logic: '<S64>/Logical Operator'
       *  Product: '<S58>/Product'
       *  RelationalOperator: '<S64>/Relational Operator'
       *  RelationalOperator: '<S64>/Relational Operator1'
       *  Sum: '<S57>/Sum1'
       *  UnitDelay: '<S58>/Unit Delay1'
       */
      EKF_B.Sum1 = EKF_DWork.UnitDelay1_DSTATE_d - EKF_B.Merge[0] *
        rtb_Product_d * rtb_Product1;

      /* Sum: '<S58>/Sum2' incorporates:
       *  Constant: '<S58>/fm'
       *  Product: '<S58>/Product1'
       *  Selector: '<S58>/fm[m]'
       *  Sum: '<S58>/Sum4'
       *  UnitDelay: '<S58>/Unit Delay3'
       */
      EKF_B.Sum2 = EKF_P.fm_Value[qY_2 - 1] * rtb_a2 * EKF_B.Merge[1] +
        EKF_DWork.UnitDelay3_DSTATE;

      /* Sum: '<S58>/Sum3' incorporates:
       *  Constant: '<S58>/fn'
       *  Product: '<S58>/Product2'
       *  Selector: '<S58>/fn[m]'
       *  Sum: '<S58>/Sum4'
       *  UnitDelay: '<S58>/Unit Delay2'
       */
      EKF_B.Sum3 = EKF_P.fn_Value[qY_3 - 1] * rtb_a2 * EKF_B.Merge[0] +
        EKF_DWork.UnitDelay2_DSTATE_a;

      /* Sum: '<S58>/Sum5' incorporates:
       *  UnitDelay: '<S58>/Unit Delay4'
       */
      EKF_B.Sum5 = EKF_DWork.UnitDelay4_DSTATE + EKF_B.Product2;

      /* Update for UnitDelay: '<S58>/Unit Delay1' */
      EKF_DWork.UnitDelay1_DSTATE_d = EKF_B.Sum1;

      /* Update for UnitDelay: '<S58>/Unit Delay3' */
      EKF_DWork.UnitDelay3_DSTATE = EKF_B.Sum2;

      /* Update for UnitDelay: '<S58>/Unit Delay2' */
      EKF_DWork.UnitDelay2_DSTATE_a = EKF_B.Sum3;

      /* Update for UnitDelay: '<S58>/Unit Delay4' */
      EKF_DWork.UnitDelay4_DSTATE = EKF_B.Sum5;
    }

    /* End of Sum: '<S49>/Sum' */
    /* End of Outputs for SubSystem: '<S49>/For Iterator Subsystem' */

    /* Sum: '<S49>/Sum1' incorporates:
     *  UnitDelay: '<S49>/Unit Delay2'
     */
    rtb_Sum1_d_idx_1 = UnitDelay2_DSTATE[0] + EKF_B.Sum1;
    rtb_Sum1_d_idx_0 = UnitDelay2_DSTATE[1] + EKF_B.Sum2;
    rtb_Sum1_d_idx_2 = UnitDelay2_DSTATE[2] + EKF_B.Sum3;
    rtb_Sum1_d_idx = UnitDelay2_DSTATE[3] + EKF_B.Sum5;

    /* Update for UnitDelay: '<S49>/Unit Delay2' */
    UnitDelay2_DSTATE[0] = rtb_Sum1_d_idx_1;
    UnitDelay2_DSTATE[1] = rtb_Sum1_d_idx_0;
    UnitDelay2_DSTATE[2] = rtb_Sum1_d_idx_2;
    UnitDelay2_DSTATE[3] = rtb_Sum1_d_idx;
  }

  /* End of Outputs for SubSystem: '<S47>/Compute magnetic vector in spherical coordinates' */

  /* Switch: '<S101>/Switch' incorporates:
   *  Product: '<S101>/Product'
   */
  if (EKF_B.sqrt_h != 0.0) {
    rtb_fcn2 = rtb_Sum1_d_idx_0 / EKF_B.sqrt_h;
  } else {
    rtb_fcn2 = rtb_Sum1_d_idx;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Sum: '<S100>/Sum1' incorporates:
   *  Product: '<S100>/Product1'
   *  Product: '<S100>/Product4'
   */
  rtb_Product1 = (0.0 - EKF_B.Product11 * rtb_Sum1_d_idx_1) - rtb_Sum1_d_idx_2 *
    EKF_B.Product12;

  /* Trigonometry: '<S103>/Trigonometric Function1' */
  rtb_Product_d = rt_atan2d_snf(rtb_fcn2, rtb_Product1);

  /* Sum: '<S102>/Sum1' incorporates:
   *  Product: '<S102>/Product1'
   *  Product: '<S102>/Product4'
   */
  rtb_b2 = EKF_B.Product12 * rtb_Sum1_d_idx_1 - rtb_Sum1_d_idx_2 *
    EKF_B.Product11;

  /* Sum: '<S103>/Sum' incorporates:
   *  Product: '<S103>/Product'
   *  Product: '<S103>/Product1'
   */
  rtb_Product1 = rtb_fcn2 * rtb_fcn2 + rtb_Product1 * rtb_Product1;

  /* Gain: '<S48>/Unit Conversion' incorporates:
   *  Gain: '<S104>/Unit Conversion'
   *  Gain: '<S105>/Unit Conversion'
   *  Sqrt: '<S103>/sqrt1'
   *  Trigonometry: '<S103>/Trigonometric Function'
   */
  rtb_sincos_o1_m_idx = EKF_P.UnitConversion_Gain_e * rtb_Product_d *
    EKF_P.UnitConversion_Gain_ax;
  rtb_sincos_o1_m_idx_0 = EKF_P.UnitConversion_Gain_o * rt_atan2d_snf(rtb_b2,
    sqrt(rtb_Product1)) * EKF_P.UnitConversion_Gain_ax;

  /* Trigonometry: '<S44>/sincos' */
  rtb_d = cos(rtb_sincos_o1_m_idx);
  rtb_sincos_o1_m_idx = sin(rtb_sincos_o1_m_idx);

  /* Sum: '<S103>/Sum1' incorporates:
   *  Product: '<S103>/Product2'
   */
  rtb_Product1 += rtb_b2 * rtb_b2;

  /* Sqrt: '<S103>/sqrt' */
  rtb_Product1 = sqrt(rtb_Product1);

  /* Product: '<S44>/h1' incorporates:
   *  Trigonometry: '<S44>/sincos'
   */
  rtb_b2 = cos(rtb_sincos_o1_m_idx_0) * rtb_Product1;

  /* Product: '<S44>/x1' */
  rtb_a2 = rtb_d * rtb_b2;

  /* Product: '<S44>/y1' */
  rtb_b2 *= rtb_sincos_o1_m_idx;

  /* Product: '<S44>/z1' incorporates:
   *  Trigonometry: '<S44>/sincos'
   */
  rtb_Product1 *= sin(rtb_sincos_o1_m_idx_0);

  /* Gain: '<S8>/Gain1' incorporates:
   *  Gain: '<S40>/Power Conversion'
   */
  rtb_Gain1[0] = EKF_P.PowerConversion_Gain * rtb_a2 * EKF_P.Gain1_Gain;
  rtb_Gain1[1] = EKF_P.PowerConversion_Gain * rtb_b2 * EKF_P.Gain1_Gain;
  rtb_Gain1[2] = EKF_P.PowerConversion_Gain * rtb_Product1 * EKF_P.Gain1_Gain;

  /* SignalConversion: '<S30>/TmpSignal ConversionAt SFunction Inport3' incorporates:
   *  Constant: '<S1>/c'
   *  MATLAB Function Block: '<S5>/QUEST'
   */
  rtb_TmpSignalConversionAtSFun_a[0] = EKF_P.c_Value;
  rtb_TmpSignalConversionAtSFun_a[1] = EKF_P.c_Value;
  rtb_TmpSignalConversionAtSFun_a[2] = rtb_gphih;

  /* MATLAB Function Block: '<S5>/QUEST' incorporates:
   *  Inport: '<Root>/deviazione_std_accell'
   *  Inport: '<Root>/deviazione_std_magneto'
   */

  /* MATLAB Function 'EKF/QUEST_Pqq/QUEST': '<S30>:1' */
  /* '<S30>:1:3' */
  rtb_Product_d = EKF_norm(rtb_Add1);
  rtb_Add1[0] /= rtb_Product_d;
  rtb_Add1[1] /= rtb_Product_d;
  rtb_Add1[2] /= rtb_Product_d;

  /* '<S30>:1:4' */
  rtb_Product_d = EKF_norm(rtb_mag_calibrate);
  V[0] = rtb_mag_calibrate[0] / rtb_Product_d;
  V[1] = rtb_mag_calibrate[1] / rtb_Product_d;
  V[2] = rtb_mag_calibrate[2] / rtb_Product_d;

  /* '<S30>:1:5' */
  rtb_Product_d = EKF_norm(rtb_TmpSignalConversionAtSFun_a);
  rtb_TmpSignalConversionAtSFun_a[0] /= rtb_Product_d;
  rtb_TmpSignalConversionAtSFun_a[1] /= rtb_Product_d;
  rtb_TmpSignalConversionAtSFun_a[2] /= rtb_Product_d;

  /* '<S30>:1:6' */
  rtb_Product_d = EKF_norm(rtb_Gain1);
  W[0] = rtb_Gain1[0] / rtb_Product_d;
  W[1] = rtb_Gain1[1] / rtb_Product_d;
  W[2] = rtb_Gain1[2] / rtb_Product_d;

  /* '<S30>:1:8' */
  rtb_sincos_o2_idx = rt_powd_snf(EKF_U.deviazione_std_accell, 2.0);

  /* '<S30>:1:9' */
  rtb_Sum4 = rt_powd_snf(EKF_U.deviazione_std_magneto, 2.0);

  /* '<S30>:1:10' */
  rtb_sincos_o1_idx = 1.0 / (1.0 / rtb_sincos_o2_idx + 1.0 / rtb_Sum4);

  /* '<S30>:1:11' */
  rtb_a2 = rtb_sincos_o1_idx / rtb_sincos_o2_idx;

  /* '<S30>:1:12' */
  rtb_d = rtb_sincos_o1_idx / rtb_Sum4;

  /* '<S30>:1:14' */
  /* '<S30>:1:15' */
  rtb_Add_0[0] = rtb_Add1[1] * V[2] - rtb_Add1[2] * V[1];
  rtb_Add_0[1] = rtb_Add1[2] * V[0] - rtb_Add1[0] * V[2];
  rtb_Add_0[2] = rtb_Add1[0] * V[1] - rtb_Add1[1] * V[0];
  rtb_TmpSignalConversionAtSFun_0[0] = rtb_TmpSignalConversionAtSFun_a[1] * W[2]
    - rtb_TmpSignalConversionAtSFun_a[2] * W[1];
  rtb_TmpSignalConversionAtSFun_0[1] = rtb_TmpSignalConversionAtSFun_a[2] * W[0]
    - rtb_TmpSignalConversionAtSFun_a[0] * W[2];
  rtb_TmpSignalConversionAtSFun_0[2] = rtb_TmpSignalConversionAtSFun_a[0] * W[1]
    - rtb_TmpSignalConversionAtSFun_a[1] * W[0];
  rtb_b2 = sqrt(2.0 * rtb_a2 * rtb_d * (EKF_dot(rtb_Add1, V) * EKF_dot
    (rtb_TmpSignalConversionAtSFun_a, W) + EKF_norm(rtb_Add_0) * EKF_norm
    (rtb_TmpSignalConversionAtSFun_0)) + (rt_powd_snf(rtb_a2, 2.0) + rt_powd_snf
                 (rtb_d, 2.0)));

  /* '<S30>:1:16' */
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_TmpSignalConversionAtSFun_1[3 * qY_3] = rtb_TmpSignalConversionAtSFun_a
      [0] * rtb_Add1[qY_3];
    rtb_TmpSignalConversionAtSFun_1[1 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFun_a[1] * rtb_Add1[qY_3];
    rtb_TmpSignalConversionAtSFun_1[2 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFun_a[2] * rtb_Add1[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_Add_1[3 * qY_3] = rtb_Add1[0] * rtb_TmpSignalConversionAtSFun_a[qY_3];
    rtb_Add_1[1 + 3 * qY_3] = rtb_Add1[1] * rtb_TmpSignalConversionAtSFun_a[qY_3];
    rtb_Add_1[2 + 3 * qY_3] = rtb_Add1[2] * rtb_TmpSignalConversionAtSFun_a[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    W_0[3 * qY_3] = W[0] * V[qY_3];
    W_0[1 + 3 * qY_3] = W[1] * V[qY_3];
    W_0[2 + 3 * qY_3] = W[2] * V[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    V_0[3 * qY_3] = V[0] * W[qY_3];
    V_0[1 + 3 * qY_3] = V[1] * W[qY_3];
    V_0[2 + 3 * qY_3] = V[2] * W[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    S[3 * qY_3] = (rtb_TmpSignalConversionAtSFun_1[3 * qY_3] + rtb_Add_1[3 *
                   qY_3]) * rtb_a2 + (W_0[3 * qY_3] + V_0[3 * qY_3]) * rtb_d;
    S[1 + 3 * qY_3] = (rtb_TmpSignalConversionAtSFun_1[3 * qY_3 + 1] +
                       rtb_Add_1[3 * qY_3 + 1]) * rtb_a2 + (W_0[3 * qY_3 + 1] +
      V_0[3 * qY_3 + 1]) * rtb_d;
    S[2 + 3 * qY_3] = (rtb_TmpSignalConversionAtSFun_1[3 * qY_3 + 2] +
                       rtb_Add_1[3 * qY_3 + 2]) * rtb_a2 + (W_0[3 * qY_3 + 2] +
      V_0[3 * qY_3 + 2]) * rtb_d;
  }

  /* '<S30>:1:17' */
  rtb_Product_d = EKF_det(S);
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    adjS[3 * qY_3] = S[qY_3];
    adjS[1 + 3 * qY_3] = S[qY_3 + 3];
    adjS[2 + 3 * qY_3] = S[qY_3 + 6];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    e_B[3 * qY_3] = rtb_Product_d * (real_T)b[qY_3];
    e_B[1 + 3 * qY_3] = (real_T)b[qY_3 + 3] * rtb_Product_d;
    e_B[2 + 3 * qY_3] = (real_T)b[qY_3 + 6] * rtb_Product_d;
  }

  i = 0;
  s49_iter = 1;
  r = 2;
  rtb_fcn2 = fabs(adjS[0]);
  rtb_Product_d = fabs(adjS[1]);
  if (rtb_Product_d > rtb_fcn2) {
    rtb_fcn2 = rtb_Product_d;
    i = 1;
    s49_iter = 0;
  }

  if (fabs(adjS[2]) > rtb_fcn2) {
    i = 2;
    s49_iter = 1;
    r = 0;
  }

  adjS[s49_iter] /= adjS[i];
  adjS[r] /= adjS[i];
  adjS[3 + s49_iter] -= adjS[3 + i] * adjS[s49_iter];
  adjS[3 + r] -= adjS[3 + i] * adjS[r];
  adjS[6 + s49_iter] -= adjS[6 + i] * adjS[s49_iter];
  adjS[6 + r] -= adjS[6 + i] * adjS[r];
  if (fabs(adjS[3 + r]) > fabs(adjS[3 + s49_iter])) {
    s98_iter = s49_iter;
    s49_iter = r;
    r = s98_iter;
  }

  adjS[3 + r] /= adjS[3 + s49_iter];
  adjS[6 + r] -= adjS[3 + r] * adjS[6 + s49_iter];
  rtb_Add_1[0] = e_B[i];
  rtb_Add_1[1] = e_B[s49_iter] - rtb_Add_1[0] * adjS[s49_iter];
  rtb_Add_1[2] = (e_B[r] - rtb_Add_1[0] * adjS[r]) - adjS[3 + r] * rtb_Add_1[1];
  rtb_Add_1[2] /= adjS[6 + r];
  rtb_Add_1[0] -= adjS[6 + i] * rtb_Add_1[2];
  rtb_Add_1[1] -= adjS[6 + s49_iter] * rtb_Add_1[2];
  rtb_Add_1[1] /= adjS[3 + s49_iter];
  rtb_Add_1[0] -= adjS[3 + i] * rtb_Add_1[1];
  rtb_Add_1[0] /= adjS[i];
  rtb_Add_1[3] = e_B[i + 3];
  rtb_Add_1[4] = e_B[s49_iter + 3] - rtb_Add_1[3] * adjS[s49_iter];
  rtb_Add_1[5] = (e_B[r + 3] - rtb_Add_1[3] * adjS[r]) - adjS[3 + r] *
    rtb_Add_1[4];
  rtb_Add_1[5] /= adjS[6 + r];
  rtb_Add_1[3] -= adjS[6 + i] * rtb_Add_1[5];
  rtb_Add_1[4] -= adjS[6 + s49_iter] * rtb_Add_1[5];
  rtb_Add_1[4] /= adjS[3 + s49_iter];
  rtb_Add_1[3] -= adjS[3 + i] * rtb_Add_1[4];
  rtb_Add_1[3] /= adjS[i];
  rtb_Add_1[6] = e_B[i + 6];
  rtb_Add_1[7] = e_B[s49_iter + 6] - rtb_Add_1[6] * adjS[s49_iter];
  rtb_Add_1[8] = (e_B[r + 6] - rtb_Add_1[6] * adjS[r]) - adjS[3 + r] *
    rtb_Add_1[7];
  rtb_Add_1[8] /= adjS[6 + r];
  rtb_Add_1[6] -= adjS[6 + i] * rtb_Add_1[8];
  rtb_Add_1[7] -= adjS[6 + s49_iter] * rtb_Add_1[8];
  rtb_Add_1[7] /= adjS[3 + s49_iter];
  rtb_Add_1[6] -= adjS[3 + i] * rtb_Add_1[7];
  rtb_Add_1[6] /= adjS[i];
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    adjS[3 * qY_3] = rtb_Add_1[qY_3];
    adjS[1 + 3 * qY_3] = rtb_Add_1[qY_3 + 3];
    adjS[2 + 3 * qY_3] = rtb_Add_1[qY_3 + 6];
  }

  /* '<S30>:1:18' */
  rtb_Product_d = ((S[0] + S[4]) + S[8]) * 0.5;

  /* '<S30>:1:19' */
  /* '<S30>:1:20' */
  /* '<S30>:1:21' */
  /* '<S30>:1:22' */
  rtb_fcn2 = ((adjS[0] + adjS[4]) + adjS[8]) + (rt_powd_snf(rtb_b2, 2.0) -
    rt_powd_snf(rtb_Product_d, 2.0));

  /* '<S30>:1:23' */
  rtb_Product1 = rtb_b2 - rtb_Product_d;

  /* '<S30>:1:24' */
  rtb_q = (rtb_b2 + rtb_Product_d) * rtb_fcn2 - EKF_det(S);

  /* '<S30>:1:26' */
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    for (r = 0; r < 3; r++) {
      V_0[qY_3 + 3 * r] = ((S[3 * r + 1] * S[qY_3 + 3] + S[3 * r] * S[qY_3]) +
                           S[3 * r + 2] * S[qY_3 + 6]) + ((real_T)b[3 * r + qY_3]
        * rtb_fcn2 + S[3 * r + qY_3] * rtb_Product1);
    }
  }

  rtb_sincos_o1_m_idx_0 = (rtb_TmpSignalConversionAtSFun_a[1] * rtb_Add1[2] -
    rtb_TmpSignalConversionAtSFun_a[2] * rtb_Add1[1]) * rtb_a2 + (W[1] * V[2] -
    W[2] * V[1]) * rtb_d;
  rtb_sincos_o1_m_idx = (rtb_TmpSignalConversionAtSFun_a[2] * rtb_Add1[0] -
    rtb_TmpSignalConversionAtSFun_a[0] * rtb_Add1[2]) * rtb_a2 + (W[2] * V[0] -
    W[0] * V[2]) * rtb_d;
  rtb_d = (rtb_TmpSignalConversionAtSFun_a[0] * rtb_Add1[1] -
           rtb_TmpSignalConversionAtSFun_a[1] * rtb_Add1[0]) * rtb_a2 + (W[0] *
    V[1] - W[1] * V[0]) * rtb_d;
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    X[qY_3] = V_0[qY_3 + 6] * rtb_d + (V_0[qY_3 + 3] * rtb_sincos_o1_m_idx +
      V_0[qY_3] * rtb_sincos_o1_m_idx_0);
  }

  /* '<S30>:1:28' */
  rtb_b2 = 1.0 / sqrt(rt_powd_snf(rtb_q, 2.0) + rt_powd_snf(EKF_norm(X), 2.0));

  /* '<S30>:1:30' */
  rtb_TmpSignalConversionAtSFun_0[0] = rtb_TmpSignalConversionAtSFun_a[1] * W[2]
    - rtb_TmpSignalConversionAtSFun_a[2] * W[1];
  rtb_TmpSignalConversionAtSFun_0[1] = rtb_TmpSignalConversionAtSFun_a[2] * W[0]
    - rtb_TmpSignalConversionAtSFun_a[0] * W[2];
  rtb_TmpSignalConversionAtSFun_0[2] = rtb_TmpSignalConversionAtSFun_a[0] * W[1]
    - rtb_TmpSignalConversionAtSFun_a[1] * W[0];
  rtb_a2 = rt_powd_snf(EKF_norm(rtb_TmpSignalConversionAtSFun_0), -2.0);
  rtb_fcn2 = rtb_Sum4 - rtb_sincos_o1_idx;
  rtb_Product_d = rtb_sincos_o2_idx - rtb_sincos_o1_idx;
  rtb_Product1 = rtb_sincos_o1_idx * EKF_dot(rtb_TmpSignalConversionAtSFun_a, W);
  UnitDelay2_DSTATE[0] = rtb_b2 * X[0];
  UnitDelay2_DSTATE[1] = rtb_b2 * X[1];
  UnitDelay2_DSTATE[2] = rtb_b2 * X[2];
  UnitDelay2_DSTATE[3] = rtb_b2 * rtb_q;
  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    V_0[3 * qY_3] = rtb_fcn2 * rtb_TmpSignalConversionAtSFun_a[0] *
      rtb_TmpSignalConversionAtSFun_a[qY_3];
    V_0[1 + 3 * qY_3] = rtb_fcn2 * rtb_TmpSignalConversionAtSFun_a[1] *
      rtb_TmpSignalConversionAtSFun_a[qY_3];
    V_0[2 + 3 * qY_3] = rtb_fcn2 * rtb_TmpSignalConversionAtSFun_a[2] *
      rtb_TmpSignalConversionAtSFun_a[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_Add_1[3 * qY_3] = rtb_Product_d * W[0] * W[qY_3];
    rtb_Add_1[1 + 3 * qY_3] = rtb_Product_d * W[1] * W[qY_3];
    rtb_Add_1[2 + 3 * qY_3] = rtb_Product_d * W[2] * W[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    rtb_TmpSignalConversionAtSFun_1[3 * qY_3] = rtb_TmpSignalConversionAtSFun_a
      [0] * W[qY_3];
    rtb_TmpSignalConversionAtSFun_1[1 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFun_a[1] * W[qY_3];
    rtb_TmpSignalConversionAtSFun_1[2 + 3 * qY_3] =
      rtb_TmpSignalConversionAtSFun_a[2] * W[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    W_0[3 * qY_3] = W[0] * rtb_TmpSignalConversionAtSFun_a[qY_3];
    W_0[1 + 3 * qY_3] = W[1] * rtb_TmpSignalConversionAtSFun_a[qY_3];
    W_0[2 + 3 * qY_3] = W[2] * rtb_TmpSignalConversionAtSFun_a[qY_3];
  }

  for (qY_3 = 0; qY_3 < 3; qY_3++) {
    tmp[3 * qY_3] = (((rtb_TmpSignalConversionAtSFun_1[3 * qY_3] + W_0[3 * qY_3])
                      * rtb_Product1 + (V_0[3 * qY_3] + rtb_Add_1[3 * qY_3])) *
                     rtb_a2 + (real_T)b[3 * qY_3] * rtb_sincos_o1_idx) * 0.25;
    tmp[1 + 3 * qY_3] = (((rtb_TmpSignalConversionAtSFun_1[3 * qY_3 + 1] + W_0[3
      * qY_3 + 1]) * rtb_Product1 + (V_0[3 * qY_3 + 1] + rtb_Add_1[3 * qY_3 + 1]))
                         * rtb_a2 + (real_T)b[3 * qY_3 + 1] * rtb_sincos_o1_idx)
      * 0.25;
    tmp[2 + 3 * qY_3] = (((rtb_TmpSignalConversionAtSFun_1[3 * qY_3 + 2] + W_0[3
      * qY_3 + 2]) * rtb_Product1 + (V_0[3 * qY_3 + 2] + rtb_Add_1[3 * qY_3 + 2]))
                         * rtb_a2 + (real_T)b[3 * qY_3 + 2] * rtb_sincos_o1_idx)
      * 0.25;
  }

  memcpy((void *)&rtb_MatrixConcatenate[0], (void *)&tmp[0], 9U * sizeof(real_T));

  /* End of MATLAB Function Block: '<S5>/QUEST' */

  /* Sqrt: '<S35>/sqrt' incorporates:
   *  Product: '<S36>/Product'
   *  Product: '<S36>/Product1'
   *  Product: '<S36>/Product2'
   *  Product: '<S36>/Product3'
   *  Sum: '<S36>/Sum'
   */
  rtb_b2 = sqrt(((UnitDelay2_DSTATE[3] * UnitDelay2_DSTATE[3] +
                  UnitDelay2_DSTATE[0] * UnitDelay2_DSTATE[0]) +
                 UnitDelay2_DSTATE[1] * UnitDelay2_DSTATE[1]) +
                UnitDelay2_DSTATE[2] * UnitDelay2_DSTATE[2]);

  /* Product: '<S34>/Product' */
  rtb_a2 = UnitDelay2_DSTATE[3] / rtb_b2;

  /* Product: '<S34>/Product1' */
  rtb_Product1 = UnitDelay2_DSTATE[0] / rtb_b2;

  /* Product: '<S34>/Product2' */
  rtb_fcn2 = UnitDelay2_DSTATE[1] / rtb_b2;

  /* Product: '<S34>/Product3' */
  rtb_b2 = UnitDelay2_DSTATE[2] / rtb_b2;

  /* Trigonometry: '<S31>/Trigonometric Function1' incorporates:
   *  Fcn: '<S31>/fcn1'
   *  Fcn: '<S31>/fcn2'
   */
  rtb_Add1[0] = rt_atan2d_snf((rtb_fcn2 * rtb_b2 - rtb_a2 * rtb_Product1) * -2.0,
                              ((rtb_a2 * rtb_a2 - rtb_Product1 * rtb_Product1) -
    rtb_fcn2 * rtb_fcn2) + rtb_b2 * rtb_b2);

  /* Trigonometry: '<S31>/trigFcn' incorporates:
   *  Fcn: '<S31>/fcn3'
   */
  rtb_d = (rtb_Product1 * rtb_b2 + rtb_a2 * rtb_fcn2) * 2.0;
  rtb_Add1[1] = asin(rtb_d >= 1.0 ? 1.0 : rtb_d <= -1.0 ? -1.0 : rtb_d);

  /* Fcn: '<S31>/fcn4' */
  rtb_q = (rtb_Product1 * rtb_fcn2 - rtb_a2 * rtb_b2) * -2.0;

  /* Fcn: '<S31>/fcn5' */
  rtb_a2 = ((rtb_a2 * rtb_a2 + rtb_Product1 * rtb_Product1) - rtb_fcn2 *
            rtb_fcn2) - rtb_b2 * rtb_b2;

  /* Trigonometry: '<S31>/Trigonometric Function3' */
  rtb_Add1[2] = rt_atan2d_snf(rtb_q, rtb_a2);

  /* Gain: '<S32>/1//2' incorporates:
   *  MATLAB Function Block: '<S5>/MATLAB Function1'
   */

  /* MATLAB Function 'EKF/QUEST_Pqq/MATLAB Function1': '<S29>:1' */
  /* '<S29>:1:3' */
  /* '<S29>:1:7' */
  /* '<S29>:1:10' */
  rtb_TmpSignalConversionAtSFun_a[0] = EKF_P.u_Gain * rtb_Add1[0];
  rtb_TmpSignalConversionAtSFun_a[1] = EKF_P.u_Gain * rtb_Add1[1];
  rtb_TmpSignalConversionAtSFun_a[2] = -rt_atan2d_snf(cos(rtb_Add1[0]) *
    rtb_mag_calibrate[1] + -sin(rtb_Add1[0]) * rtb_mag_calibrate[2], (sin
    (rtb_Add1[0]) * sin(rtb_Add1[1]) * rtb_mag_calibrate[1] + cos(rtb_Add1[1]) *
    rtb_mag_calibrate[0]) + cos(rtb_Add1[0]) * sin(rtb_Add1[1]) *
    rtb_mag_calibrate[2]) * EKF_P.u_Gain;

  /* Trigonometry: '<S32>/sincos' */
  rtb_d = cos(rtb_TmpSignalConversionAtSFun_a[0]);
  rtb_TmpSignalConversionAtSFun_a[0] = sin(rtb_TmpSignalConversionAtSFun_a[0]);
  rtb_sincos_o1_m_idx_0 = cos(rtb_TmpSignalConversionAtSFun_a[1]);
  rtb_TmpSignalConversionAtSFun_a[1] = sin(rtb_TmpSignalConversionAtSFun_a[1]);
  rtb_Product_d = cos(rtb_TmpSignalConversionAtSFun_a[2]);
  rtb_sincos_o1_m_idx = rtb_Product_d;
  rtb_TmpSignalConversionAtSFun_a[2] = sin(rtb_TmpSignalConversionAtSFun_a[2]);

  /* Fcn: '<S32>/q1' incorporates:
   *  Trigonometry: '<S32>/sincos'
   */
  rtb_a2 = rtb_d * rtb_TmpSignalConversionAtSFun_a[1] *
    rtb_TmpSignalConversionAtSFun_a[2] + rtb_TmpSignalConversionAtSFun_a[0] *
    rtb_sincos_o1_m_idx_0 * rtb_Product_d;

  /* Fcn: '<S32>/q2' incorporates:
   *  Trigonometry: '<S32>/sincos'
   */
  rtb_q = rtb_d * rtb_TmpSignalConversionAtSFun_a[1] * rtb_Product_d -
    rtb_TmpSignalConversionAtSFun_a[0] * rtb_sincos_o1_m_idx_0 *
    rtb_TmpSignalConversionAtSFun_a[2];

  /* Fcn: '<S32>/q3' incorporates:
   *  Trigonometry: '<S32>/sincos'
   */
  rtb_Product_d = rtb_d * rtb_sincos_o1_m_idx_0 *
    rtb_TmpSignalConversionAtSFun_a[2] + rtb_TmpSignalConversionAtSFun_a[0] *
    rtb_TmpSignalConversionAtSFun_a[1] * rtb_Product_d;

  /* Fcn: '<S32>/q0' */
  rtb_Product1 = rtb_d * rtb_sincos_o1_m_idx_0 * rtb_sincos_o1_m_idx -
    rtb_TmpSignalConversionAtSFun_a[0] * rtb_TmpSignalConversionAtSFun_a[1] *
    rtb_TmpSignalConversionAtSFun_a[2];

  /* Sum: '<S10>/Add1' incorporates:
   *  Inport: '<Root>/tau'
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   *  Saturate: '<S10>/Saturation'
   */
  UnitDelay2_DSTATE[0] = (rtb_u_o_idx >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o_idx <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o_idx) * rtb_Add + EKF_U.tau * rtb_a2;
  UnitDelay2_DSTATE[1] = (rtb_u_o_idx_0 >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o_idx_0 <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o_idx_0) * rtb_Add + EKF_U.tau * rtb_q;
  UnitDelay2_DSTATE[2] = (rtb_u_o_idx_1 >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o_idx_1 <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o_idx_1) * rtb_Add + EKF_U.tau *
    rtb_Product_d;
  UnitDelay2_DSTATE[3] = (rtb_u_o_idx_2 >= EKF_P.Saturation_UpperSat ?
    EKF_P.Saturation_UpperSat : rtb_u_o_idx_2 <= EKF_P.Saturation_LowerSat ?
    EKF_P.Saturation_LowerSat : rtb_u_o_idx_2) * rtb_Add + EKF_U.tau *
    rtb_Product1;

  /* MATLAB Function Block: '<S5>/q_matrix' */

  /* MATLAB Function 'EKF/QUEST_Pqq/q_matrix': '<S33>:1' */
  /* '<S33>:1:3' */
  rtb_q_matrix[0] = rtb_Product1;
  rtb_q_matrix[4] = -rtb_Product_d;
  rtb_q_matrix[8] = rtb_q;
  rtb_q_matrix[12] = rtb_a2;
  rtb_q_matrix[1] = rtb_Product_d;
  rtb_q_matrix[5] = rtb_Product1;
  rtb_q_matrix[9] = -rtb_a2;
  rtb_q_matrix[13] = rtb_q;
  rtb_q_matrix[2] = -rtb_q;
  rtb_q_matrix[6] = rtb_a2;
  rtb_q_matrix[10] = rtb_Product1;
  rtb_q_matrix[14] = rtb_Product_d;
  rtb_q_matrix[3] = -rtb_a2;
  rtb_q_matrix[7] = -rtb_q;
  rtb_q_matrix[11] = -rtb_Product_d;
  rtb_q_matrix[15] = rtb_Product1;

  /* Constant: '<S5>/Constant' */
  rtb_MatrixConcatenate[9] = EKF_P.Constant_Value_n[0];
  rtb_MatrixConcatenate[10] = EKF_P.Constant_Value_n[1];
  rtb_MatrixConcatenate[11] = EKF_P.Constant_Value_n[2];

  /* Product: '<S5>/Matrix Multiply1' incorporates:
   *  Concatenate: '<S5>/Matrix Concatenate1'
   *  Constant: '<S5>/Constant1'
   *  Math: '<S5>/ 1'
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

  /* End of Product: '<S5>/Matrix Multiply1' */

  /* Product: '<S5>/Matrix Multiply2' incorporates:
   *  Math: '<S5>/ '
   *  Product: '<S5>/Matrix Multiply1'
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

  /* End of Product: '<S5>/Matrix Multiply2' */

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
      rtb_Product1_pl[r + 7 * qY_3] = rtb_MatrixConcatenate_a[(r << 2) + qY_3];
    }
  }

  /* End of Math: '<S17>/Math Function' */

  /* Product: '<S17>/Product1' */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_Product4_l[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Product4_l[qY_3 + 7 * r] = EKF_DWork.Memory1_PreviousInput[7 * i +
          qY_3] * rtb_Product1_pl[7 * r + i] + rtb_Product4_l[7 * r + qY_3];
      }
    }
  }

  /* End of Product: '<S17>/Product1' */

  /* Product: '<S17>/Product3' */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_MatrixConcatenate_a_0[qY_3 + (r << 2)] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_MatrixConcatenate_a_0[qY_3 + (r << 2)] = rtb_MatrixConcatenate_a[(i <<
          2) + qY_3] * EKF_DWork.Memory1_PreviousInput[7 * r + i] +
          rtb_MatrixConcatenate_a_0[(r << 2) + qY_3];
      }
    }
  }

  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_Product2_ee[qY_3 + (r << 2)] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Product2_ee[qY_3 + (r << 2)] = rtb_MatrixConcatenate_a_0[(i << 2) +
          qY_3] * rtb_Product1_pl[7 * r + i] + rtb_Product2_ee[(r << 2) + qY_3];
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

  /* Product: '<S13>/Product1' incorporates:
   *  Inport: '<Root>/GPS_Reset'
   *  Product: '<S17>/Product4'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = 0.0;
      rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = rtb_MatrixConcatenate_a_0[7 * r
        + qY_3] + rtb_Product2_ee[r << 2] * rtb_Product4_l[qY_3];
      rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 1] *
        rtb_Product4_l[qY_3 + 7] + rtb_MatrixConcatenate_a_0[7 * r + qY_3];
      rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 2] *
        rtb_Product4_l[qY_3 + 14] + rtb_MatrixConcatenate_a_0[7 * r + qY_3];
      rtb_MatrixConcatenate_a_0[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 3] *
        rtb_Product4_l[qY_3 + 21] + rtb_MatrixConcatenate_a_0[7 * r + qY_3];
    }
  }

  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Product1_pl[r + 7 * qY_3] = rtb_MatrixConcatenate_a_0[7 * qY_3 + r] *
        EKF_U.GPS_Reset;
    }
  }

  /* End of Product: '<S13>/Product1' */

  /* Logic: '<S13>/Logical Operator' incorporates:
   *  Inport: '<Root>/GPS_Reset'
   */
  rtb_RelationalOperator = !(EKF_U.GPS_Reset != 0.0);

  /* Math: '<S16>/Math Function' */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Product4_l[r + 7 * qY_3] = rtb_MatrixConcatenate_a[(r << 2) + qY_3];
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
          qY_3] * rtb_Product4_l[7 * r + i] + rtb_Product2_ee[(r << 2) + qY_3];
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
          rtb_Product4_l[7 * r + i] + rtb_MatrixConcatenate_a_0[7 * r + qY_3];
      }
    }
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 4; r++) {
      rtb_Product4_l[qY_3 + 7 * r] = 0.0;
      rtb_Product4_l[qY_3 + 7 * r] = rtb_Product4_l[7 * r + qY_3] +
        rtb_Product2_ee[r << 2] * rtb_MatrixConcatenate_a_0[qY_3];
      rtb_Product4_l[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 1] *
        rtb_MatrixConcatenate_a_0[qY_3 + 7] + rtb_Product4_l[7 * r + qY_3];
      rtb_Product4_l[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 2] *
        rtb_MatrixConcatenate_a_0[qY_3 + 14] + rtb_Product4_l[7 * r + qY_3];
      rtb_Product4_l[qY_3 + 7 * r] = rtb_Product2_ee[(r << 2) + 3] *
        rtb_MatrixConcatenate_a_0[qY_3 + 21] + rtb_Product4_l[7 * r + qY_3];
    }
  }

  /* End of Product: '<S16>/Product4' */

  /* Sum: '<S13>/Sum' incorporates:
   *  Product: '<S13>/Product2'
   */
  for (qY_3 = 0; qY_3 < 28; qY_3++) {
    rtb_Product1_pl[qY_3] += (real_T)rtb_RelationalOperator *
      rtb_Product4_l[qY_3];
  }

  /* End of Sum: '<S13>/Sum' */

  /* Sum: '<S15>/Sum' incorporates:
   *  Constant: '<S15>/Constant'
   *  Product: '<S15>/Product1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Sum_h[qY_3 + 7 * r] = EKF_P.Constant_Value[7 * r + qY_3] -
        (((rtb_MatrixConcatenate_a[(r << 2) + 1] * rtb_Product1_pl[qY_3 + 7] +
           rtb_MatrixConcatenate_a[r << 2] * rtb_Product1_pl[qY_3]) +
          rtb_MatrixConcatenate_a[(r << 2) + 2] * rtb_Product1_pl[qY_3 + 14]) +
         rtb_MatrixConcatenate_a[(r << 2) + 3] * rtb_Product1_pl[qY_3 + 21]);
    }
  }

  /* End of Sum: '<S15>/Sum' */

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
    rtb_d = 0.0;
    for (r = 0; r < 7; r++) {
      rtb_d += rtb_MatrixConcatenate_i[(r << 2) + qY_3] * rtb_Memory[r];
    }

    UnitDelay2_DSTATE_0[qY_3] = UnitDelay2_DSTATE[qY_3] - rtb_d;
  }

  /* End of Product: '<S18>/Product1' */

  /* Sum: '<S18>/Sum1' incorporates:
   *  Product: '<S18>/Product1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum1_c[qY_3] = (((rtb_Product1_pl[qY_3 + 7] * UnitDelay2_DSTATE_0[1] +
                          rtb_Product1_pl[qY_3] * UnitDelay2_DSTATE_0[0]) +
                         rtb_Product1_pl[qY_3 + 14] * UnitDelay2_DSTATE_0[2]) +
                        rtb_Product1_pl[qY_3 + 21] * UnitDelay2_DSTATE_0[3]) +
      rtb_Memory[qY_3];
  }

  /* End of Sum: '<S18>/Sum1' */
  /* End of Outputs for SubSystem: '<S3>/Correction' */

  /* Sqrt: '<S38>/sqrt' incorporates:
   *  Product: '<S39>/Product'
   *  Product: '<S39>/Product1'
   *  Product: '<S39>/Product2'
   *  Product: '<S39>/Product3'
   *  Sum: '<S39>/Sum'
   */
  rtb_q = sqrt(((rtb_Sum1_c[3] * rtb_Sum1_c[3] + rtb_Sum1_c[0] * rtb_Sum1_c[0])
                + rtb_Sum1_c[1] * rtb_Sum1_c[1]) + rtb_Sum1_c[2] * rtb_Sum1_c[2]);

  /* Product: '<S37>/Product' */
  rtb_Product_d = rtb_Sum1_c[3] / rtb_q;

  /* Product: '<S37>/Product1' */
  rtb_b2 = rtb_Sum1_c[0] / rtb_q;

  /* Product: '<S37>/Product2' */
  rtb_a2 = rtb_Sum1_c[1] / rtb_q;

  /* Product: '<S37>/Product3' */
  rtb_q = rtb_Sum1_c[2] / rtb_q;

  /* Trigonometry: '<S6>/Trigonometric Function1' incorporates:
   *  Fcn: '<S6>/fcn1'
   *  Fcn: '<S6>/fcn2'
   */
  rtb_Add1[0] = rt_atan2d_snf((rtb_a2 * rtb_q - rtb_Product_d * rtb_b2) * -2.0,
                              ((rtb_Product_d * rtb_Product_d - rtb_b2 * rtb_b2)
    - rtb_a2 * rtb_a2) + rtb_q * rtb_q);

  /* Trigonometry: '<S6>/trigFcn' incorporates:
   *  Fcn: '<S6>/fcn3'
   */
  rtb_d = (rtb_b2 * rtb_q + rtb_Product_d * rtb_a2) * 2.0;
  rtb_Add1[1] = asin(rtb_d >= 1.0 ? 1.0 : rtb_d <= -1.0 ? -1.0 : rtb_d);

  /* Fcn: '<S6>/fcn4' */
  rtb_Product1 = (rtb_b2 * rtb_a2 - rtb_Product_d * rtb_q) * -2.0;

  /* Fcn: '<S6>/fcn5' */
  rtb_Product_d = ((rtb_Product_d * rtb_Product_d + rtb_b2 * rtb_b2) - rtb_a2 *
                   rtb_a2) - rtb_q * rtb_q;

  /* Trigonometry: '<S6>/Trigonometric Function3' */
  rtb_Add1[2] = rt_atan2d_snf(rtb_Product1, rtb_Product_d);

  /* Outport: '<Root>/eulero' incorporates:
   *  Gain: '<S2>/Unit Conversion'
   */
  EKF_Y.eulero[0] = EKF_P.UnitConversion_Gain_ol * rtb_Add1[0];
  EKF_Y.eulero[1] = EKF_P.UnitConversion_Gain_ol * rtb_Add1[1];
  EKF_Y.eulero[2] = EKF_P.UnitConversion_Gain_ol * rtb_Add1[2];

  /* Outport: '<Root>/quaternioni' */
  EKF_Y.quaternioni[0] = rtb_Sum1_c[3];
  EKF_Y.quaternioni[1] = rtb_Sum1_c[0];
  EKF_Y.quaternioni[2] = rtb_Sum1_c[1];
  EKF_Y.quaternioni[3] = rtb_Sum1_c[2];

  /* Outport: '<Root>/p-q-r' incorporates:
   *  Sum: '<S1>/Add'
   */
  EKF_Y.pqr[0] = rtb_gyrounbiased_idx - rtb_Memory_k_idx;
  EKF_Y.pqr[1] = rtb_gyrounbiased_idx_0 - rtb_Memory_k_idx_0;
  EKF_Y.pqr[2] = rtb_gyrounbiased_idx_1 - rtb_Memory_k_idx_1;

  /* Outport: '<Root>/WMM' */
  EKF_Y.WMM[0] = rtb_Gain1[0];
  EKF_Y.WMM[1] = rtb_Gain1[1];
  EKF_Y.WMM[2] = rtb_Gain1[2];

  /* Outport: '<Root>/WGS' incorporates:
   *  Constant: '<S1>/c'
   */
  EKF_Y.WGS[0] = EKF_P.c_Value;
  EKF_Y.WGS[1] = EKF_P.c_Value;
  EKF_Y.WGS[2] = rtb_gphih;

  /* MATLAB Function Block: '<S1>/quat_derivative' */

  /* MATLAB Function 'EKF/quat_derivative': '<S12>:1' */
  /* '<S12>:1:2' */
  /* '<S12>:1:7' */
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
   *  SignalConversion: '<S12>/TmpSignal ConversionAt SFunction Inport2'
   */
  for (qY_3 = 0; qY_3 < 4; qY_3++) {
    EKF_Y.quat_dot[qY_3] = 0.0;
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3] * rtb_Sum1_c[3];
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3 + 4] * rtb_Sum1_c[0];
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3 + 8] * rtb_Sum1_c[1];
    EKF_Y.quat_dot[qY_3] += rtb_MatrixConcatenate_1[qY_3 + 12] * rtb_Sum1_c[2];
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
  rtb_Sum_l_0[0] = 0.0;
  rtb_Sum_l_0[7] = 0.5 * rtb_gyrounbiased_idx_1 - 0.5 * rtb_Sum1_c[6];
  rtb_Sum_l_0[14] = -0.5 * rtb_gyrounbiased_idx_0 + 0.5 * rtb_Sum1_c[5];
  rtb_Sum_l_0[21] = 0.5 * rtb_gyrounbiased_idx - 0.5 * rtb_Sum1_c[4];
  rtb_Sum_l_0[28] = -0.5 * rtb_Sum1_c[3];
  rtb_Sum_l_0[35] = 0.5 * rtb_Sum1_c[2];
  rtb_Sum_l_0[42] = -0.5 * rtb_Sum1_c[1];
  rtb_Sum_l_0[1] = -0.5 * rtb_gyrounbiased_idx_1 + 0.5 * rtb_Sum1_c[6];
  rtb_Sum_l_0[8] = 0.0;
  rtb_Sum_l_0[15] = 0.5 * rtb_gyrounbiased_idx - 0.5 * rtb_Sum1_c[4];
  rtb_Sum_l_0[22] = 0.5 * rtb_gyrounbiased_idx_0 - 0.5 * rtb_Sum1_c[5];
  rtb_Sum_l_0[29] = -0.5 * rtb_Sum1_c[2];
  rtb_Sum_l_0[36] = -0.5 * rtb_Sum1_c[3];
  rtb_Sum_l_0[43] = 0.5 * rtb_Sum1_c[0];
  rtb_Sum_l_0[2] = 0.5 * rtb_gyrounbiased_idx_0 - 0.5 * rtb_Sum1_c[5];
  rtb_Sum_l_0[9] = -0.5 * rtb_gyrounbiased_idx + 0.5 * rtb_Sum1_c[4];
  rtb_Sum_l_0[16] = 0.0;
  rtb_Sum_l_0[23] = 0.5 * rtb_gyrounbiased_idx_1 - 0.5 * rtb_Sum1_c[6];
  rtb_Sum_l_0[30] = 0.5 * rtb_Sum1_c[1];
  rtb_Sum_l_0[37] = -0.5 * rtb_Sum1_c[0];
  rtb_Sum_l_0[44] = -0.5 * rtb_Sum1_c[3];
  rtb_Sum_l_0[3] = -0.5 * rtb_gyrounbiased_idx + 0.5 * rtb_Sum1_c[4];
  rtb_Sum_l_0[10] = -0.5 * rtb_gyrounbiased_idx_0 + 0.5 * rtb_Sum1_c[5];
  rtb_Sum_l_0[17] = -0.5 * rtb_gyrounbiased_idx_1 + 0.5 * rtb_Sum1_c[6];
  rtb_Sum_l_0[24] = 0.0;
  rtb_Sum_l_0[31] = 0.5 * rtb_Sum1_c[0];
  rtb_Sum_l_0[38] = 0.5 * rtb_Sum1_c[1];
  rtb_Sum_l_0[45] = 0.5 * rtb_Sum1_c[2];
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_l_0[4 + 7 * qY_3] = 0.0;
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_l_0[5 + 7 * qY_3] = 0.0;
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_l_0[6 + 7 * qY_3] = 0.0;
  }

  /* End of Product: '<S22>/Product' */

  /* Sum: '<S22>/Sum' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Inport: '<Root>/dt'
   *  Product: '<S22>/Product'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Sum_l[r + 7 * qY_3] = rtb_Sum_l_0[7 * qY_3 + r] * EKF_U.dt +
        EKF_P.Constant2_Value[7 * qY_3 + r];
    }
  }

  /* End of Sum: '<S22>/Sum' */

  /* Product: '<S21>/Product' incorporates:
   *  Inport: '<Root>/dt'
   *  MATLAB Function Block: '<S24>/f(xk) '
   */

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
  rtb_Memory[0] = ((0.5 * rtb_Sum1_c[3] * (rtb_gyrounbiased_idx - rtb_Sum1_c[4])
                    - 0.5 * rtb_Sum1_c[2] * (rtb_gyrounbiased_idx_0 -
    rtb_Sum1_c[5])) + 0.5 * rtb_Sum1_c[1] * (rtb_gyrounbiased_idx_1 -
    rtb_Sum1_c[6])) * EKF_U.dt;
  rtb_Memory[1] = ((0.5 * rtb_Sum1_c[2] * (rtb_gyrounbiased_idx - rtb_Sum1_c[4])
                    + 0.5 * rtb_Sum1_c[3] * (rtb_gyrounbiased_idx_0 -
    rtb_Sum1_c[5])) - 0.5 * rtb_Sum1_c[0] * (rtb_gyrounbiased_idx_1 -
    rtb_Sum1_c[6])) * EKF_U.dt;
  rtb_Memory[2] = ((-0.5 * rtb_Sum1_c[1] * (rtb_gyrounbiased_idx - rtb_Sum1_c[4])
                    + 0.5 * rtb_Sum1_c[0] * (rtb_gyrounbiased_idx_0 -
    rtb_Sum1_c[5])) + 0.5 * rtb_Sum1_c[3] * (rtb_gyrounbiased_idx_1 -
    rtb_Sum1_c[6])) * EKF_U.dt;
  rtb_Memory[3] = ((-0.5 * rtb_Sum1_c[0] * (rtb_gyrounbiased_idx - rtb_Sum1_c[4])
                    - 0.5 * rtb_Sum1_c[1] * (rtb_gyrounbiased_idx_0 -
    rtb_Sum1_c[5])) - 0.5 * rtb_Sum1_c[2] * (rtb_gyrounbiased_idx_1 -
    rtb_Sum1_c[6])) * EKF_U.dt;
  rtb_Memory[4] = EKF_U.dt * 0.0;
  rtb_Memory[5] = EKF_U.dt * 0.0;
  rtb_Memory[6] = EKF_U.dt * 0.0;
  for (i = 0; i < 12; i++) {
    /* Constant: '<S23>/ ' */
    rtb_MatrixConcatenate_l[i + 16] = EKF_P._Value[i];

    /* Constant: '<S23>/ 1' */
    rtb_MatrixConcatenate1[i] = EKF_P.u_Value[i];
  }

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

  /* Assertion: '<S41>/Assertion' incorporates:
   *  Constant: '<S41>/max_val'
   *  Constant: '<S41>/min_val'
   *  Logic: '<S41>/conjunction'
   *  RelationalOperator: '<S41>/max_relop'
   *  RelationalOperator: '<S41>/min_relop'
   */
  utAssert((EKF_P.min_val_Value <= rtb_UnitConversion_j) &&
           (rtb_UnitConversion_j <= EKF_P.max_val_Value));

  /* Assertion: '<S42>/Assertion' incorporates:
   *  Constant: '<S42>/max_val'
   *  Constant: '<S42>/min_val'
   *  Inport: '<Root>/lat-lon-alti'
   *  Logic: '<S42>/conjunction'
   *  RelationalOperator: '<S42>/max_relop'
   *  RelationalOperator: '<S42>/min_relop'
   */
  utAssert((EKF_P.min_val_Value_k <= EKF_U.latlonalti[0]) && (EKF_U.latlonalti[0]
            <= EKF_P.max_val_Value_d));

  /* Assertion: '<S43>/Assertion' incorporates:
   *  Constant: '<S43>/max_val'
   *  Constant: '<S43>/min_val'
   *  Inport: '<Root>/lat-lon-alti'
   *  Logic: '<S43>/conjunction'
   *  RelationalOperator: '<S43>/max_relop'
   *  RelationalOperator: '<S43>/min_relop'
   */
  utAssert((EKF_P.min_val_Value_c <= EKF_U.latlonalti[1]) && (EKF_U.latlonalti[1]
            <= EKF_P.max_val_Value_p));

  /* Assertion: '<S45>/Assertion' incorporates:
   *  Constant: '<S45>/max_val'
   *  Constant: '<S45>/min_val'
   *  Logic: '<S45>/conjunction'
   *  RelationalOperator: '<S45>/max_relop'
   *  RelationalOperator: '<S45>/min_relop'
   */
  utAssert((EKF_P.min_val_Value_i <= rtb_Sum_m) && (rtb_Sum_m <=
            EKF_P.max_val_Value_c));

  /* Outputs for Atomic SubSystem: '<S3>/Prediction' */
  /* Outputs for Atomic SubSystem: '<S3>/Correction' */
  /* Product: '<S21>/Product1' incorporates:
   *  Product: '<S15>/Product3'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Sum_h_0[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Sum_h_0[qY_3 + 7 * r] = rtb_Sum_h[7 * i + qY_3] * rtb_Memory1[7 * r
          + i] + rtb_Sum_h_0[7 * r + qY_3];
      }
    }
  }

  /* End of Outputs for SubSystem: '<S3>/Correction' */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      rtb_Sum_l_0[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Sum_l_0[qY_3 + 7 * r] = rtb_Sum_l[7 * i + qY_3] * rtb_Sum_h_0[7 * r
          + i] + rtb_Sum_l_0[7 * r + qY_3];
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
      rtb_Memory1[qY_3 + 7 * r] = 0.0;
      for (i = 0; i < 7; i++) {
        rtb_Memory1[qY_3 + 7 * r] = rtb_Sum_l_0[7 * i + qY_3] * rtb_Sum_l[7 * i
          + r] + rtb_Memory1[7 * r + qY_3];
      }
    }
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_l_0[7 * qY_3] = rtb_MatrixConcatenate_l[qY_3 << 2];
    rtb_Sum_l_0[1 + 7 * qY_3] = rtb_MatrixConcatenate_l[(qY_3 << 2) + 1];
    rtb_Sum_l_0[2 + 7 * qY_3] = rtb_MatrixConcatenate_l[(qY_3 << 2) + 2];
    rtb_Sum_l_0[3 + 7 * qY_3] = rtb_MatrixConcatenate_l[(qY_3 << 2) + 3];
  }

  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    rtb_Sum_l_0[4 + 7 * qY_3] = rtb_MatrixConcatenate1[3 * qY_3];
    rtb_Sum_l_0[5 + 7 * qY_3] = rtb_MatrixConcatenate1[3 * qY_3 + 1];
    rtb_Sum_l_0[6 + 7 * qY_3] = rtb_MatrixConcatenate1[3 * qY_3 + 2];
  }

  /* End of Sum: '<S21>/Sum1' */

  /* Update for Memory: '<S3>/Memory1' incorporates:
   *  Sum: '<S21>/Sum1'
   */
  for (qY_3 = 0; qY_3 < 7; qY_3++) {
    for (r = 0; r < 7; r++) {
      EKF_DWork.Memory1_PreviousInput[r + 7 * qY_3] = rtb_Memory1[7 * qY_3 + r]
        + rtb_Sum_l_0[7 * qY_3 + r];
    }
  }

  /* End of Memory: '<S3>/Memory1' */
  /* End of Outputs for SubSystem: '<S3>/Prediction' */

  /* Update for Memory: '<S3>/Memory' incorporates:
   *  Sum: '<S21>/Sum'
   */
  for (i = 0; i < 7; i++) {
    /* Outputs for Atomic SubSystem: '<S3>/Prediction' */
    EKF_DWork.Memory_PreviousInput[i] = rtb_Memory[i] + rtb_Sum1_c[i];

    /* End of Outputs for SubSystem: '<S3>/Prediction' */
  }

  /* End of Memory: '<S3>/Memory' */

  /* Update for Memory: '<S1>/Memory' */
  EKF_DWork.Memory_PreviousInput_i[0] = rtb_Sum1_c[4];
  EKF_DWork.Memory_PreviousInput_i[1] = rtb_Sum1_c[5];
  EKF_DWork.Memory_PreviousInput_i[2] = rtb_Sum1_c[6];

  /* Update for Memory: '<S1>/Memory1' */
  EKF_DWork.Memory1_PreviousInput_m[0] = rtb_Sum1_c[0];
  EKF_DWork.Memory1_PreviousInput_m[1] = rtb_Sum1_c[1];
  EKF_DWork.Memory1_PreviousInput_m[2] = rtb_Sum1_c[2];
  EKF_DWork.Memory1_PreviousInput_m[3] = rtb_Sum1_c[3];

  /* Update for Memory: '<S55>/otime' */
  EKF_DWork.otime_PreviousInput = rtb_Sum;

  /* Update for Memory: '<S54>/olon' */
  EKF_DWork.olon_PreviousInput = rtb_u80deg;

  /* Update for Memory: '<S53>/olat' */
  EKF_DWork.olat_PreviousInput = rtb_u0deg;

  /* Update for Memory: '<S53>/oalt' */
  EKF_DWork.oalt_PreviousInput = rtb_Gain;
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
      EKF_B.Sum2_j[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      EKF_B.Assignment_g[i] = 0.0;
    }

    for (i = 0; i < 169; i++) {
      EKF_B.Assignment_snorm[i] = 0.0;
    }

    for (i = 0; i < 13; i++) {
      EKF_B.Assignment2_h[i] = 0.0;
    }

    for (i = 0; i < 13; i++) {
      EKF_B.Assignment2_d[i] = 0.0;
    }

    EKF_B.sp2 = 0.0;
    EKF_B.cp2 = 0.0;
    EKF_B.cp1 = 0.0;
    EKF_B.sp1 = 0.0;
    EKF_B.sqrt_g = 0.0;
    EKF_B.Product11 = 0.0;
    EKF_B.Product4 = 0.0;
    EKF_B.Product12 = 0.0;
    EKF_B.sqrt_h = 0.0;
    EKF_B.Merge[0] = 0.0;
    EKF_B.Merge[1] = 0.0;
    EKF_B.Sum1 = 0.0;
    EKF_B.Sum2 = 0.0;
    EKF_B.Sum3 = 0.0;
    EKF_B.Sum5 = 0.0;
    EKF_B.Merge_j[0] = 0.0;
    EKF_B.Merge_j[1] = 0.0;
    EKF_B.Product2 = 0.0;
  }

  /* states (dwork) */
  (void) memset((void *)&EKF_DWork, 0,
                sizeof(D_Work_EKF));
  EKF_DWork.UnitDelay1_DSTATE[0] = 0.0;
  EKF_DWork.UnitDelay1_DSTATE[1] = 0.0;
  EKF_DWork.UnitDelay1_DSTATE_d = 0.0;
  EKF_DWork.UnitDelay3_DSTATE = 0.0;
  EKF_DWork.UnitDelay2_DSTATE_a = 0.0;
  EKF_DWork.UnitDelay4_DSTATE = 0.0;

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay_DSTATE_g[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay_DSTATE_o[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay_DSTATE_d[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 169; i++) {
      EKF_DWork.UnitDelay1_DSTATE_h[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 13; i++) {
      EKF_DWork.UnitDelay1_DSTATE_dg[i] = 0.0;
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

    /* Start for Enabled SubSystem: '<S47>/Convert from geodetic to  spherical coordinates ' */
    /* Start for Iterator SubSystem: '<S51>/For Iterator Subsystem' */
    /* InitializeConditions for UnitDelay: '<S98>/Unit Delay1' */
    EKF_DWork.UnitDelay1_DSTATE[0] = EKF_P.UnitDelay1_X0_o;
    EKF_DWork.UnitDelay1_DSTATE[1] = EKF_P.UnitDelay1_X0_o;

    /* End of Start for SubSystem: '<S51>/For Iterator Subsystem' */

    /* VirtualOutportStart for Outport: '<S51>/sp[13]' */
    EKF_B.sp1 = EKF_P.sp13_Y0[0];
    EKF_B.sp2 = EKF_P.sp13_Y0[1];

    /* VirtualOutportStart for Outport: '<S51>/cp[13]' */
    EKF_B.cp1 = EKF_P.cp13_Y0[0];
    EKF_B.cp2 = EKF_P.cp13_Y0[1];
    for (i = 0; i < 11; i++) {
      /* VirtualOutportStart for Outport: '<S51>/sp[13]' */
      EKF_B.Assignment[i] = EKF_P.sp13_Y0[i + 2];
      EKF_B.Assignment1[i] = EKF_P.cp13_Y0[i + 2];
    }

    /* End of Start for SubSystem: '<S47>/Convert from geodetic to  spherical coordinates ' */

    /* Start for Iterator SubSystem: '<S47>/Compute magnetic vector in spherical coordinates' */
    /* Start for Iterator SubSystem: '<S49>/For Iterator Subsystem' */
    /* Start for Enabled SubSystem: '<S57>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */
    /* Start for Enabled SubSystem: '<S57>/Time adjust the gauss coefficients' */
    for (i = 0; i < 169; i++) {
      /* InitializeConditions for UnitDelay: '<S59>/Unit Delay' */
      EKF_DWork.UnitDelay_DSTATE_d[i] = EKF_P.UnitDelay_X0[i];

      /* InitializeConditions for UnitDelay: '<S59>/Unit Delay1' */
      EKF_DWork.UnitDelay1_DSTATE_h[i] = EKF_P.UnitDelay1_X0_g[i];

      /* InitializeConditions for UnitDelay: '<S60>/Unit Delay' */
      EKF_DWork.UnitDelay_DSTATE_g[i] = EKF_P.UnitDelay_X0_e[i];

      /* InitializeConditions for UnitDelay: '<S87>/Unit Delay' */
      EKF_DWork.UnitDelay_DSTATE_o[i] = EKF_P.UnitDelay_X0_h[i];
    }

    /* End of Outport: '<S51>/cp[13]' */
    /* End of Start for SubSystem: '<S57>/Time adjust the gauss coefficients' */
    /* End of Start for SubSystem: '<S57>/Compute unnormalized associated  legendre polynomials and  derivatives via recursion relations' */

    /* Start for Enabled SubSystem: '<S58>/Special case - North//South Geographic Pole' */
    /* InitializeConditions for UnitDelay: '<S61>/Unit Delay1' */
    memcpy((void *)EKF_DWork.UnitDelay1_DSTATE_dg, (void *)EKF_P.UnitDelay1_X0,
           13U * sizeof(real_T));

    /* VirtualOutportStart for Outport: '<S61>/bpp' */
    EKF_B.Product2 = EKF_P.bpp_Y0;

    /* End of Start for SubSystem: '<S58>/Special case - North//South Geographic Pole' */

    /* InitializeConditions for UnitDelay: '<S58>/Unit Delay1' */
    EKF_DWork.UnitDelay1_DSTATE_d = EKF_P.UnitDelay1_X0_p;

    /* InitializeConditions for UnitDelay: '<S58>/Unit Delay3' */
    EKF_DWork.UnitDelay3_DSTATE = EKF_P.UnitDelay3_X0;

    /* InitializeConditions for UnitDelay: '<S58>/Unit Delay2' */
    EKF_DWork.UnitDelay2_DSTATE_a = EKF_P.UnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S58>/Unit Delay4' */
    EKF_DWork.UnitDelay4_DSTATE = EKF_P.UnitDelay4_X0;

    /* End of Start for SubSystem: '<S49>/For Iterator Subsystem' */
    /* End of Start for SubSystem: '<S47>/Compute magnetic vector in spherical coordinates' */

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

    /* InitializeConditions for Memory: '<S55>/otime' */
    EKF_DWork.otime_PreviousInput = EKF_P.otime_X0;

    /* InitializeConditions for Memory: '<S54>/olon' */
    EKF_DWork.olon_PreviousInput = EKF_P.olon_X0;

    /* InitializeConditions for Memory: '<S53>/olat' */
    EKF_DWork.olat_PreviousInput = EKF_P.olat_X0;

    /* InitializeConditions for Memory: '<S53>/oalt' */
    EKF_DWork.oalt_PreviousInput = EKF_P.oalt_X0;
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
