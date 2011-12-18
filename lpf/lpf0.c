/*
 * File: lpf0.c
 *
 * Code generated for Simulink model 'lpf0'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Sun Dec 18 15:19:41 2011
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lpf0.h"
#include "lpf0_private.h"

/* Block signals (auto storage) */
BlockIO_lpf0 lpf0_B;

/* Block states (auto storage) */
D_Work_lpf0 lpf0_DWork;

/* External inputs (root inport signals with auto storage) */
ExternalInputs_lpf0 lpf0_U;

/* External outputs (root outports fed by signals with auto storage) */
ExternalOutputs_lpf0 lpf0_Y;

/* Real-time model */
RT_MODEL_lpf0 lpf0_M_;
RT_MODEL_lpf0 *const lpf0_M = &lpf0_M_;

/* Model step function */
void lpf0_step(void)
{
  real_T accum;
  int32_T cfIdx;
  int32_T j;
  real_T rtb_Memory;
  real_T rtb_Memory1;
  real_T rtb_Memory2;
  real_T rtb_Memory3;
  real_T rtb_Memory4;
  real_T rtb_Memory6;
  real_T rtb_Memory7;
  real_T rtb_Memory8;
  real_T rtb_Memory9;
  real_T rtb_Memory10;
  real_T rtb_Memory14;
  real_T rtb_Memory15;
  real_T rtb_Memory16;
  real_T rtb_Memory17;
  real_T rtb_Memory12;
  real_T rtb_Memory36;
  real_T rtb_Memory37;
  real_T rtb_Memory38;
  real_T rtb_Memory39;
  real_T rtb_Memory40;
  real_T rtb_Memory42;
  real_T rtb_Memory43;
  real_T rtb_Memory44;
  real_T rtb_Memory45;
  real_T rtb_Memory46;
  real_T rtb_Memory48;
  real_T rtb_Memory49;
  real_T rtb_Memory50;
  real_T rtb_Memory51;
  real_T rtb_Memory52;
  real_T rtb_Memory18;
  real_T rtb_Memory19;
  real_T rtb_Memory20;
  real_T rtb_Memory21;
  real_T rtb_Memory22;
  real_T rtb_Memory24;
  real_T rtb_Memory25;
  real_T rtb_Memory26;
  real_T rtb_Memory27;
  real_T rtb_Memory28;
  real_T rtb_Memory30;
  real_T rtb_Memory31;
  real_T rtb_Memory32;
  real_T rtb_Memory33;
  real_T rtb_Memory34;

  /* Memory: '<S1>/Memory' */
  rtb_Memory = lpf0_DWork.Memory_PreviousInput;

  /* Memory: '<S1>/Memory1' */
  rtb_Memory1 = lpf0_DWork.Memory1_PreviousInput;

  /* Memory: '<S1>/Memory2' */
  rtb_Memory2 = lpf0_DWork.Memory2_PreviousInput;

  /* Memory: '<S1>/Memory3' */
  rtb_Memory3 = lpf0_DWork.Memory3_PreviousInput;

  /* Memory: '<S1>/Memory4' */
  rtb_Memory4 = lpf0_DWork.Memory4_PreviousInput;

  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/acc_x'
   *  Memory: '<S1>/Memory'
   *  Memory: '<S1>/Memory1'
   *  Memory: '<S1>/Memory2'
   *  Memory: '<S1>/Memory3'
   *  Memory: '<S1>/Memory4'
   *  Memory: '<S1>/Memory5'
   *  Sum: '<S1>/Add'
   */
  lpf0_B.Gain = (real_T)(real32_T)((((((lpf0_U.acc_x +
    lpf0_DWork.Memory_PreviousInput) + lpf0_DWork.Memory1_PreviousInput) +
    lpf0_DWork.Memory2_PreviousInput) + lpf0_DWork.Memory3_PreviousInput) +
    lpf0_DWork.Memory4_PreviousInput) + lpf0_DWork.Memory5_PreviousInput) *
    (real_T)lpf0_P.Gain_Gain;

  /* S-Function (sdspfilter2): '<S11>/Stage1' */
  accum = lpf0_B.Gain * lpf0_P.Stage1_RTP1COEFF[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX; j < 6; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES[j] * lpf0_P.Stage1_RTP1COEFF[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES[j] * lpf0_P.Stage1_RTP1COEFF[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX - 1;
  if (cfIdx < 0) {
    cfIdx = 5;
  }

  lpf0_DWork.Stage1_FILT_STATES[cfIdx] = lpf0_B.Gain;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX = cfIdx;

  /* End of S-Function (sdspfilter2): '<S11>/Stage1' */

  /* S-Function (sdspfilter2): '<S11>/Stage2' */
  accum = lpf0_B.Stage2 * lpf0_P.Stage2_RTP1COEFF[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX; j < 39; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES[j] * lpf0_P.Stage2_RTP1COEFF[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES[j] * lpf0_P.Stage2_RTP1COEFF[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX - 1;
  if (cfIdx < 0) {
    cfIdx = 38;
  }

  lpf0_DWork.Stage2_FILT_STATES[cfIdx] = lpf0_B.Stage2;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX = cfIdx;

  /* End of S-Function (sdspfilter2): '<S11>/Stage2' */

  /* Outport: '<Root>/acc_x_f' */
  lpf0_Y.acc_x_f = lpf0_B.Stage1;

  /* Memory: '<S1>/Memory6' */
  rtb_Memory6 = lpf0_DWork.Memory6_PreviousInput;

  /* Memory: '<S1>/Memory7' */
  rtb_Memory7 = lpf0_DWork.Memory7_PreviousInput;

  /* Memory: '<S1>/Memory8' */
  rtb_Memory8 = lpf0_DWork.Memory8_PreviousInput;

  /* Memory: '<S1>/Memory9' */
  rtb_Memory9 = lpf0_DWork.Memory9_PreviousInput;

  /* Memory: '<S1>/Memory10' */
  rtb_Memory10 = lpf0_DWork.Memory10_PreviousInput;

  /* Gain: '<S1>/Gain1' incorporates:
   *  Inport: '<Root>/acc_y'
   *  Memory: '<S1>/Memory10'
   *  Memory: '<S1>/Memory11'
   *  Memory: '<S1>/Memory6'
   *  Memory: '<S1>/Memory7'
   *  Memory: '<S1>/Memory8'
   *  Memory: '<S1>/Memory9'
   *  Sum: '<S1>/Add1'
   */
  lpf0_B.Gain1 = (real_T)(real32_T)((((((lpf0_U.acc_y +
    lpf0_DWork.Memory6_PreviousInput) + lpf0_DWork.Memory7_PreviousInput) +
    lpf0_DWork.Memory8_PreviousInput) + lpf0_DWork.Memory9_PreviousInput) +
    lpf0_DWork.Memory10_PreviousInput) + lpf0_DWork.Memory11_PreviousInput) *
    (real_T)lpf0_P.Gain1_Gain;

  /* S-Function (sdspfilter2): '<S12>/Stage1' */
  accum = lpf0_B.Gain1 * lpf0_P.Stage1_RTP1COEFF_p[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_n; j < 6; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_f[j] *
      lpf0_P.Stage1_RTP1COEFF_p[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_n; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_f[j] *
      lpf0_P.Stage1_RTP1COEFF_p[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_n - 1;
  if (cfIdx < 0) {
    cfIdx = 5;
  }

  lpf0_DWork.Stage1_FILT_STATES_f[cfIdx] = lpf0_B.Gain1;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_n = cfIdx;

  /* End of S-Function (sdspfilter2): '<S12>/Stage1' */

  /* S-Function (sdspfilter2): '<S12>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_d[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_m; j < 39; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_b[j] *
      lpf0_P.Stage2_RTP1COEFF_d[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_m; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_b[j] *
      lpf0_P.Stage2_RTP1COEFF_d[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_m - 1;
  if (cfIdx < 0) {
    cfIdx = 38;
  }

  lpf0_DWork.Stage2_FILT_STATES_b[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_m = cfIdx;

  /* End of S-Function (sdspfilter2): '<S12>/Stage2' */

  /* Outport: '<Root>/acc_y_f' */
  lpf0_Y.acc_y_f = lpf0_B.Stage2;

  /* Memory: '<S1>/Memory14' */
  rtb_Memory14 = lpf0_DWork.Memory14_PreviousInput;

  /* Memory: '<S1>/Memory15' */
  rtb_Memory15 = lpf0_DWork.Memory15_PreviousInput;

  /* Memory: '<S1>/Memory16' */
  rtb_Memory16 = lpf0_DWork.Memory16_PreviousInput;

  /* Memory: '<S1>/Memory17' */
  rtb_Memory17 = lpf0_DWork.Memory17_PreviousInput;

  /* Memory: '<S1>/Memory12' */
  rtb_Memory12 = lpf0_DWork.Memory12_PreviousInput;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Inport: '<Root>/acc_z'
   *  Memory: '<S1>/Memory12'
   *  Memory: '<S1>/Memory13'
   *  Memory: '<S1>/Memory14'
   *  Memory: '<S1>/Memory15'
   *  Memory: '<S1>/Memory16'
   *  Memory: '<S1>/Memory17'
   *  Sum: '<S1>/Add2'
   */
  lpf0_B.Gain2 = (real_T)(real32_T)((((((lpf0_U.acc_z +
    lpf0_DWork.Memory14_PreviousInput) + lpf0_DWork.Memory15_PreviousInput) +
    lpf0_DWork.Memory16_PreviousInput) + lpf0_DWork.Memory17_PreviousInput) +
    lpf0_DWork.Memory12_PreviousInput) + lpf0_DWork.Memory13_PreviousInput) *
    (real_T)lpf0_P.Gain2_Gain;

  /* S-Function (sdspfilter2): '<S13>/Stage1' */
  accum = lpf0_B.Gain2 * lpf0_P.Stage1_RTP1COEFF_g[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_g; j < 6; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_c[j] *
      lpf0_P.Stage1_RTP1COEFF_g[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_g; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_c[j] *
      lpf0_P.Stage1_RTP1COEFF_g[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_g - 1;
  if (cfIdx < 0) {
    cfIdx = 5;
  }

  lpf0_DWork.Stage1_FILT_STATES_c[cfIdx] = lpf0_B.Gain2;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_g = cfIdx;

  /* End of S-Function (sdspfilter2): '<S13>/Stage1' */

  /* S-Function (sdspfilter2): '<S13>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_m[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_c; j < 39; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_a[j] *
      lpf0_P.Stage2_RTP1COEFF_m[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_c; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_a[j] *
      lpf0_P.Stage2_RTP1COEFF_m[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_c - 1;
  if (cfIdx < 0) {
    cfIdx = 38;
  }

  lpf0_DWork.Stage2_FILT_STATES_a[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_c = cfIdx;

  /* End of S-Function (sdspfilter2): '<S13>/Stage2' */

  /* Outport: '<Root>/acc_z_f' */
  lpf0_Y.acc_z_f = lpf0_B.Stage2;

  /* Memory: '<S1>/Memory36' */
  rtb_Memory36 = lpf0_DWork.Memory36_PreviousInput;

  /* Memory: '<S1>/Memory37' */
  rtb_Memory37 = lpf0_DWork.Memory37_PreviousInput;

  /* Memory: '<S1>/Memory38' */
  rtb_Memory38 = lpf0_DWork.Memory38_PreviousInput;

  /* Memory: '<S1>/Memory39' */
  rtb_Memory39 = lpf0_DWork.Memory39_PreviousInput;

  /* Memory: '<S1>/Memory40' */
  rtb_Memory40 = lpf0_DWork.Memory40_PreviousInput;

  /* Gain: '<S1>/Gain6' incorporates:
   *  Inport: '<Root>/gyro_x'
   *  Memory: '<S1>/Memory36'
   *  Memory: '<S1>/Memory37'
   *  Memory: '<S1>/Memory38'
   *  Memory: '<S1>/Memory39'
   *  Memory: '<S1>/Memory40'
   *  Memory: '<S1>/Memory41'
   *  Sum: '<S1>/Add6'
   */
  lpf0_B.Gain6 = (real_T)(real32_T)((((((lpf0_U.gyro_x +
    lpf0_DWork.Memory36_PreviousInput) + lpf0_DWork.Memory37_PreviousInput) +
    lpf0_DWork.Memory38_PreviousInput) + lpf0_DWork.Memory39_PreviousInput) +
    lpf0_DWork.Memory40_PreviousInput) + lpf0_DWork.Memory41_PreviousInput) *
    (real_T)lpf0_P.Gain6_Gain;

  /* S-Function (sdspfilter2): '<S14>/Stage1' */
  accum = lpf0_B.Gain6 * lpf0_P.Stage1_RTP1COEFF_h[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_d; j < 6; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_g[j] *
      lpf0_P.Stage1_RTP1COEFF_h[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_d; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_g[j] *
      lpf0_P.Stage1_RTP1COEFF_h[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_d - 1;
  if (cfIdx < 0) {
    cfIdx = 5;
  }

  lpf0_DWork.Stage1_FILT_STATES_g[cfIdx] = lpf0_B.Gain6;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_d = cfIdx;

  /* End of S-Function (sdspfilter2): '<S14>/Stage1' */

  /* S-Function (sdspfilter2): '<S14>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_i[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_p; j < 39; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_d[j] *
      lpf0_P.Stage2_RTP1COEFF_i[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_p; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_d[j] *
      lpf0_P.Stage2_RTP1COEFF_i[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_p - 1;
  if (cfIdx < 0) {
    cfIdx = 38;
  }

  lpf0_DWork.Stage2_FILT_STATES_d[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_p = cfIdx;

  /* End of S-Function (sdspfilter2): '<S14>/Stage2' */

  /* Outport: '<Root>/gyro_x_f' */
  lpf0_Y.gyro_x_f = lpf0_B.Stage2;

  /* Memory: '<S1>/Memory42' */
  rtb_Memory42 = lpf0_DWork.Memory42_PreviousInput;

  /* Memory: '<S1>/Memory43' */
  rtb_Memory43 = lpf0_DWork.Memory43_PreviousInput;

  /* Memory: '<S1>/Memory44' */
  rtb_Memory44 = lpf0_DWork.Memory44_PreviousInput;

  /* Memory: '<S1>/Memory45' */
  rtb_Memory45 = lpf0_DWork.Memory45_PreviousInput;

  /* Memory: '<S1>/Memory46' */
  rtb_Memory46 = lpf0_DWork.Memory46_PreviousInput;

  /* Gain: '<S1>/Gain7' incorporates:
   *  Inport: '<Root>/gyro_y'
   *  Memory: '<S1>/Memory42'
   *  Memory: '<S1>/Memory43'
   *  Memory: '<S1>/Memory44'
   *  Memory: '<S1>/Memory45'
   *  Memory: '<S1>/Memory46'
   *  Memory: '<S1>/Memory47'
   *  Sum: '<S1>/Add7'
   */
  lpf0_B.Gain7 = (real_T)(real32_T)((((((lpf0_U.gyro_y +
    lpf0_DWork.Memory42_PreviousInput) + lpf0_DWork.Memory43_PreviousInput) +
    lpf0_DWork.Memory44_PreviousInput) + lpf0_DWork.Memory45_PreviousInput) +
    lpf0_DWork.Memory46_PreviousInput) + lpf0_DWork.Memory47_PreviousInput) *
    (real_T)lpf0_P.Gain7_Gain;

  /* S-Function (sdspfilter2): '<S15>/Stage1' */
  accum = lpf0_B.Gain7 * lpf0_P.Stage1_RTP1COEFF_gn[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_d3; j < 6; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_f1[j] *
      lpf0_P.Stage1_RTP1COEFF_gn[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_d3; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_f1[j] *
      lpf0_P.Stage1_RTP1COEFF_gn[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_d3 - 1;
  if (cfIdx < 0) {
    cfIdx = 5;
  }

  lpf0_DWork.Stage1_FILT_STATES_f1[cfIdx] = lpf0_B.Gain7;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_d3 = cfIdx;

  /* End of S-Function (sdspfilter2): '<S15>/Stage1' */

  /* S-Function (sdspfilter2): '<S15>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_h[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_o; j < 39; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_m[j] *
      lpf0_P.Stage2_RTP1COEFF_h[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_o; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_m[j] *
      lpf0_P.Stage2_RTP1COEFF_h[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_o - 1;
  if (cfIdx < 0) {
    cfIdx = 38;
  }

  lpf0_DWork.Stage2_FILT_STATES_m[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_o = cfIdx;

  /* End of S-Function (sdspfilter2): '<S15>/Stage2' */

  /* Outport: '<Root>/gyro_y_f' */
  lpf0_Y.gyro_y_f = lpf0_B.Stage2;

  /* Memory: '<S1>/Memory48' */
  rtb_Memory48 = lpf0_DWork.Memory48_PreviousInput;

  /* Memory: '<S1>/Memory49' */
  rtb_Memory49 = lpf0_DWork.Memory49_PreviousInput;

  /* Memory: '<S1>/Memory50' */
  rtb_Memory50 = lpf0_DWork.Memory50_PreviousInput;

  /* Memory: '<S1>/Memory51' */
  rtb_Memory51 = lpf0_DWork.Memory51_PreviousInput;

  /* Memory: '<S1>/Memory52' */
  rtb_Memory52 = lpf0_DWork.Memory52_PreviousInput;

  /* Gain: '<S1>/Gain8' incorporates:
   *  Inport: '<Root>/gyro_z'
   *  Memory: '<S1>/Memory48'
   *  Memory: '<S1>/Memory49'
   *  Memory: '<S1>/Memory50'
   *  Memory: '<S1>/Memory51'
   *  Memory: '<S1>/Memory52'
   *  Memory: '<S1>/Memory53'
   *  Sum: '<S1>/Add8'
   */
  lpf0_B.Gain8 = (real_T)(real32_T)((((((lpf0_U.gyro_z +
    lpf0_DWork.Memory48_PreviousInput) + lpf0_DWork.Memory49_PreviousInput) +
    lpf0_DWork.Memory50_PreviousInput) + lpf0_DWork.Memory51_PreviousInput) +
    lpf0_DWork.Memory52_PreviousInput) + lpf0_DWork.Memory53_PreviousInput) *
    (real_T)lpf0_P.Gain8_Gain;

  /* S-Function (sdspfilter2): '<S16>/Stage1' */
  accum = lpf0_B.Gain8 * lpf0_P.Stage1_RTP1COEFF_a[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_k; j < 6; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_o[j] *
      lpf0_P.Stage1_RTP1COEFF_a[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_k; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_o[j] *
      lpf0_P.Stage1_RTP1COEFF_a[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_k - 1;
  if (cfIdx < 0) {
    cfIdx = 5;
  }

  lpf0_DWork.Stage1_FILT_STATES_o[cfIdx] = lpf0_B.Gain8;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_k = cfIdx;

  /* End of S-Function (sdspfilter2): '<S16>/Stage1' */

  /* S-Function (sdspfilter2): '<S16>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_p[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_ov; j < 39; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_k[j] *
      lpf0_P.Stage2_RTP1COEFF_p[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_ov; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_k[j] *
      lpf0_P.Stage2_RTP1COEFF_p[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_ov - 1;
  if (cfIdx < 0) {
    cfIdx = 38;
  }

  lpf0_DWork.Stage2_FILT_STATES_k[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_ov = cfIdx;

  /* End of S-Function (sdspfilter2): '<S16>/Stage2' */

  /* Outport: '<Root>/gyro_z_f' */
  lpf0_Y.gyro_z_f = lpf0_B.Stage2;

  /* Memory: '<S1>/Memory18' */
  rtb_Memory18 = lpf0_DWork.Memory18_PreviousInput;

  /* Memory: '<S1>/Memory19' */
  rtb_Memory19 = lpf0_DWork.Memory19_PreviousInput;

  /* Memory: '<S1>/Memory20' */
  rtb_Memory20 = lpf0_DWork.Memory20_PreviousInput;

  /* Memory: '<S1>/Memory21' */
  rtb_Memory21 = lpf0_DWork.Memory21_PreviousInput;

  /* Memory: '<S1>/Memory22' */
  rtb_Memory22 = lpf0_DWork.Memory22_PreviousInput;

  /* Gain: '<S1>/Gain3' incorporates:
   *  Inport: '<Root>/mag_x'
   *  Memory: '<S1>/Memory18'
   *  Memory: '<S1>/Memory19'
   *  Memory: '<S1>/Memory20'
   *  Memory: '<S1>/Memory21'
   *  Memory: '<S1>/Memory22'
   *  Memory: '<S1>/Memory23'
   *  Sum: '<S1>/Add3'
   */
  lpf0_B.Gain3 = (real_T)(real32_T)((((((lpf0_U.mag_x +
    lpf0_DWork.Memory18_PreviousInput) + lpf0_DWork.Memory19_PreviousInput) +
    lpf0_DWork.Memory20_PreviousInput) + lpf0_DWork.Memory21_PreviousInput) +
    lpf0_DWork.Memory22_PreviousInput) + lpf0_DWork.Memory23_PreviousInput) *
    (real_T)lpf0_P.Gain3_Gain;

  /* S-Function (sdspfilter2): '<S17>/Stage1' */
  accum = lpf0_B.Gain3 * lpf0_P.Stage1_RTP1COEFF_e[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_c; j < 5; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_a[j] *
      lpf0_P.Stage1_RTP1COEFF_e[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_c; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_a[j] *
      lpf0_P.Stage1_RTP1COEFF_e[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_c - 1;
  if (cfIdx < 0) {
    cfIdx = 4;
  }

  lpf0_DWork.Stage1_FILT_STATES_a[cfIdx] = lpf0_B.Gain3;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_c = cfIdx;

  /* End of S-Function (sdspfilter2): '<S17>/Stage1' */

  /* S-Function (sdspfilter2): '<S17>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_pd[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_mf; j < 28; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_h[j] *
      lpf0_P.Stage2_RTP1COEFF_pd[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_mf; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_h[j] *
      lpf0_P.Stage2_RTP1COEFF_pd[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_mf - 1;
  if (cfIdx < 0) {
    cfIdx = 27;
  }

  lpf0_DWork.Stage2_FILT_STATES_h[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_mf = cfIdx;

  /* End of S-Function (sdspfilter2): '<S17>/Stage2' */

  /* Outport: '<Root>/mag_x_f' */
  lpf0_Y.mag_x_f = lpf0_B.Stage2;

  /* Memory: '<S1>/Memory24' */
  rtb_Memory24 = lpf0_DWork.Memory24_PreviousInput;

  /* Memory: '<S1>/Memory25' */
  rtb_Memory25 = lpf0_DWork.Memory25_PreviousInput;

  /* Memory: '<S1>/Memory26' */
  rtb_Memory26 = lpf0_DWork.Memory26_PreviousInput;

  /* Memory: '<S1>/Memory27' */
  rtb_Memory27 = lpf0_DWork.Memory27_PreviousInput;

  /* Memory: '<S1>/Memory28' */
  rtb_Memory28 = lpf0_DWork.Memory28_PreviousInput;

  /* Gain: '<S1>/Gain4' incorporates:
   *  Inport: '<Root>/mag_y'
   *  Memory: '<S1>/Memory24'
   *  Memory: '<S1>/Memory25'
   *  Memory: '<S1>/Memory26'
   *  Memory: '<S1>/Memory27'
   *  Memory: '<S1>/Memory28'
   *  Memory: '<S1>/Memory29'
   *  Sum: '<S1>/Add4'
   */
  lpf0_B.Gain4 = (real_T)(real32_T)((((((lpf0_U.mag_y +
    lpf0_DWork.Memory24_PreviousInput) + lpf0_DWork.Memory25_PreviousInput) +
    lpf0_DWork.Memory26_PreviousInput) + lpf0_DWork.Memory27_PreviousInput) +
    lpf0_DWork.Memory28_PreviousInput) + lpf0_DWork.Memory29_PreviousInput) *
    (real_T)lpf0_P.Gain4_Gain;

  /* S-Function (sdspfilter2): '<S18>/Stage1' */
  accum = lpf0_B.Gain4 * lpf0_P.Stage1_RTP1COEFF_hv[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_a; j < 5; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_d[j] *
      lpf0_P.Stage1_RTP1COEFF_hv[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_a; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_d[j] *
      lpf0_P.Stage1_RTP1COEFF_hv[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_a - 1;
  if (cfIdx < 0) {
    cfIdx = 4;
  }

  lpf0_DWork.Stage1_FILT_STATES_d[cfIdx] = lpf0_B.Gain4;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_a = cfIdx;

  /* End of S-Function (sdspfilter2): '<S18>/Stage1' */

  /* S-Function (sdspfilter2): '<S18>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_f[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_l; j < 28; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_ao[j] *
      lpf0_P.Stage2_RTP1COEFF_f[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_l; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_ao[j] *
      lpf0_P.Stage2_RTP1COEFF_f[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_l - 1;
  if (cfIdx < 0) {
    cfIdx = 27;
  }

  lpf0_DWork.Stage2_FILT_STATES_ao[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_l = cfIdx;

  /* End of S-Function (sdspfilter2): '<S18>/Stage2' */

  /* Outport: '<Root>/mag_y_f' */
  lpf0_Y.mag_y_f = lpf0_B.Stage2;

  /* Memory: '<S1>/Memory30' */
  rtb_Memory30 = lpf0_DWork.Memory30_PreviousInput;

  /* Memory: '<S1>/Memory31' */
  rtb_Memory31 = lpf0_DWork.Memory31_PreviousInput;

  /* Memory: '<S1>/Memory32' */
  rtb_Memory32 = lpf0_DWork.Memory32_PreviousInput;

  /* Memory: '<S1>/Memory33' */
  rtb_Memory33 = lpf0_DWork.Memory33_PreviousInput;

  /* Memory: '<S1>/Memory34' */
  rtb_Memory34 = lpf0_DWork.Memory34_PreviousInput;

  /* Gain: '<S1>/Gain5' incorporates:
   *  Inport: '<Root>/mag_z'
   *  Memory: '<S1>/Memory30'
   *  Memory: '<S1>/Memory31'
   *  Memory: '<S1>/Memory32'
   *  Memory: '<S1>/Memory33'
   *  Memory: '<S1>/Memory34'
   *  Memory: '<S1>/Memory35'
   *  Sum: '<S1>/Add5'
   */
  lpf0_B.Gain5 = (real_T)(real32_T)((((((lpf0_U.mag_z +
    lpf0_DWork.Memory30_PreviousInput) + lpf0_DWork.Memory31_PreviousInput) +
    lpf0_DWork.Memory32_PreviousInput) + lpf0_DWork.Memory33_PreviousInput) +
    lpf0_DWork.Memory34_PreviousInput) + lpf0_DWork.Memory35_PreviousInput) *
    (real_T)lpf0_P.Gain5_Gain;

  /* S-Function (sdspfilter2): '<S19>/Stage1' */
  accum = lpf0_B.Gain5 * lpf0_P.Stage1_RTP1COEFF_o[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage1_CIRCBUFFIDX_m; j < 5; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_n[j] *
      lpf0_P.Stage1_RTP1COEFF_o[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage1_CIRCBUFFIDX_m; j++) {
    accum += lpf0_DWork.Stage1_FILT_STATES_n[j] *
      lpf0_P.Stage1_RTP1COEFF_o[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage1_CIRCBUFFIDX_m - 1;
  if (cfIdx < 0) {
    cfIdx = 4;
  }

  lpf0_DWork.Stage1_FILT_STATES_n[cfIdx] = lpf0_B.Gain5;
  lpf0_B.Stage1 = accum;
  lpf0_DWork.Stage1_CIRCBUFFIDX_m = cfIdx;

  /* End of S-Function (sdspfilter2): '<S19>/Stage1' */

  /* S-Function (sdspfilter2): '<S19>/Stage2' */
  accum = lpf0_B.Stage1 * lpf0_P.Stage2_RTP1COEFF_l[0];
  cfIdx = 1;
  for (j = lpf0_DWork.Stage2_CIRCBUFFIDX_d; j < 28; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_f[j] *
      lpf0_P.Stage2_RTP1COEFF_l[cfIdx];
    cfIdx++;
  }

  for (j = 0; j < lpf0_DWork.Stage2_CIRCBUFFIDX_d; j++) {
    accum += lpf0_DWork.Stage2_FILT_STATES_f[j] *
      lpf0_P.Stage2_RTP1COEFF_l[cfIdx];
    cfIdx++;
  }

  cfIdx = lpf0_DWork.Stage2_CIRCBUFFIDX_d - 1;
  if (cfIdx < 0) {
    cfIdx = 27;
  }

  lpf0_DWork.Stage2_FILT_STATES_f[cfIdx] = lpf0_B.Stage1;
  lpf0_B.Stage2 = accum;
  lpf0_DWork.Stage2_CIRCBUFFIDX_d = cfIdx;

  /* End of S-Function (sdspfilter2): '<S19>/Stage2' */

  /* Outport: '<Root>/mag_z_f' */
  lpf0_Y.mag_z_f = lpf0_B.Stage2;

  /* Update for Memory: '<S1>/Memory' */
  lpf0_DWork.Memory_PreviousInput = lpf0_B.Gain;

  /* Update for Memory: '<S1>/Memory1' */
  lpf0_DWork.Memory1_PreviousInput = rtb_Memory;

  /* Update for Memory: '<S1>/Memory2' */
  lpf0_DWork.Memory2_PreviousInput = rtb_Memory1;

  /* Update for Memory: '<S1>/Memory3' */
  lpf0_DWork.Memory3_PreviousInput = rtb_Memory2;

  /* Update for Memory: '<S1>/Memory4' */
  lpf0_DWork.Memory4_PreviousInput = rtb_Memory3;

  /* Update for Memory: '<S1>/Memory5' */
  lpf0_DWork.Memory5_PreviousInput = rtb_Memory4;

  /* Update for Memory: '<S1>/Memory6' */
  lpf0_DWork.Memory6_PreviousInput = lpf0_B.Gain1;

  /* Update for Memory: '<S1>/Memory7' */
  lpf0_DWork.Memory7_PreviousInput = rtb_Memory6;

  /* Update for Memory: '<S1>/Memory8' */
  lpf0_DWork.Memory8_PreviousInput = rtb_Memory7;

  /* Update for Memory: '<S1>/Memory9' */
  lpf0_DWork.Memory9_PreviousInput = rtb_Memory8;

  /* Update for Memory: '<S1>/Memory10' */
  lpf0_DWork.Memory10_PreviousInput = rtb_Memory9;

  /* Update for Memory: '<S1>/Memory11' */
  lpf0_DWork.Memory11_PreviousInput = rtb_Memory10;

  /* Update for Memory: '<S1>/Memory14' */
  lpf0_DWork.Memory14_PreviousInput = lpf0_B.Gain2;

  /* Update for Memory: '<S1>/Memory15' */
  lpf0_DWork.Memory15_PreviousInput = rtb_Memory14;

  /* Update for Memory: '<S1>/Memory16' */
  lpf0_DWork.Memory16_PreviousInput = rtb_Memory15;

  /* Update for Memory: '<S1>/Memory17' */
  lpf0_DWork.Memory17_PreviousInput = rtb_Memory16;

  /* Update for Memory: '<S1>/Memory12' */
  lpf0_DWork.Memory12_PreviousInput = rtb_Memory17;

  /* Update for Memory: '<S1>/Memory13' */
  lpf0_DWork.Memory13_PreviousInput = rtb_Memory12;

  /* Update for Memory: '<S1>/Memory36' */
  lpf0_DWork.Memory36_PreviousInput = lpf0_B.Gain6;

  /* Update for Memory: '<S1>/Memory37' */
  lpf0_DWork.Memory37_PreviousInput = rtb_Memory36;

  /* Update for Memory: '<S1>/Memory38' */
  lpf0_DWork.Memory38_PreviousInput = rtb_Memory37;

  /* Update for Memory: '<S1>/Memory39' */
  lpf0_DWork.Memory39_PreviousInput = rtb_Memory38;

  /* Update for Memory: '<S1>/Memory40' */
  lpf0_DWork.Memory40_PreviousInput = rtb_Memory39;

  /* Update for Memory: '<S1>/Memory41' */
  lpf0_DWork.Memory41_PreviousInput = rtb_Memory40;

  /* Update for Memory: '<S1>/Memory42' */
  lpf0_DWork.Memory42_PreviousInput = lpf0_B.Gain7;

  /* Update for Memory: '<S1>/Memory43' */
  lpf0_DWork.Memory43_PreviousInput = rtb_Memory42;

  /* Update for Memory: '<S1>/Memory44' */
  lpf0_DWork.Memory44_PreviousInput = rtb_Memory43;

  /* Update for Memory: '<S1>/Memory45' */
  lpf0_DWork.Memory45_PreviousInput = rtb_Memory44;

  /* Update for Memory: '<S1>/Memory46' */
  lpf0_DWork.Memory46_PreviousInput = rtb_Memory45;

  /* Update for Memory: '<S1>/Memory47' */
  lpf0_DWork.Memory47_PreviousInput = rtb_Memory46;

  /* Update for Memory: '<S1>/Memory48' */
  lpf0_DWork.Memory48_PreviousInput = lpf0_B.Gain8;

  /* Update for Memory: '<S1>/Memory49' */
  lpf0_DWork.Memory49_PreviousInput = rtb_Memory48;

  /* Update for Memory: '<S1>/Memory50' */
  lpf0_DWork.Memory50_PreviousInput = rtb_Memory49;

  /* Update for Memory: '<S1>/Memory51' */
  lpf0_DWork.Memory51_PreviousInput = rtb_Memory50;

  /* Update for Memory: '<S1>/Memory52' */
  lpf0_DWork.Memory52_PreviousInput = rtb_Memory51;

  /* Update for Memory: '<S1>/Memory53' */
  lpf0_DWork.Memory53_PreviousInput = rtb_Memory52;

  /* Update for Memory: '<S1>/Memory18' */
  lpf0_DWork.Memory18_PreviousInput = lpf0_B.Gain3;

  /* Update for Memory: '<S1>/Memory19' */
  lpf0_DWork.Memory19_PreviousInput = rtb_Memory18;

  /* Update for Memory: '<S1>/Memory20' */
  lpf0_DWork.Memory20_PreviousInput = rtb_Memory19;

  /* Update for Memory: '<S1>/Memory21' */
  lpf0_DWork.Memory21_PreviousInput = rtb_Memory20;

  /* Update for Memory: '<S1>/Memory22' */
  lpf0_DWork.Memory22_PreviousInput = rtb_Memory21;

  /* Update for Memory: '<S1>/Memory23' */
  lpf0_DWork.Memory23_PreviousInput = rtb_Memory22;

  /* Update for Memory: '<S1>/Memory24' */
  lpf0_DWork.Memory24_PreviousInput = lpf0_B.Gain4;

  /* Update for Memory: '<S1>/Memory25' */
  lpf0_DWork.Memory25_PreviousInput = rtb_Memory24;

  /* Update for Memory: '<S1>/Memory26' */
  lpf0_DWork.Memory26_PreviousInput = rtb_Memory25;

  /* Update for Memory: '<S1>/Memory27' */
  lpf0_DWork.Memory27_PreviousInput = rtb_Memory26;

  /* Update for Memory: '<S1>/Memory28' */
  lpf0_DWork.Memory28_PreviousInput = rtb_Memory27;

  /* Update for Memory: '<S1>/Memory29' */
  lpf0_DWork.Memory29_PreviousInput = rtb_Memory28;

  /* Update for Memory: '<S1>/Memory30' */
  lpf0_DWork.Memory30_PreviousInput = lpf0_B.Gain5;

  /* Update for Memory: '<S1>/Memory31' */
  lpf0_DWork.Memory31_PreviousInput = rtb_Memory30;

  /* Update for Memory: '<S1>/Memory32' */
  lpf0_DWork.Memory32_PreviousInput = rtb_Memory31;

  /* Update for Memory: '<S1>/Memory33' */
  lpf0_DWork.Memory33_PreviousInput = rtb_Memory32;

  /* Update for Memory: '<S1>/Memory34' */
  lpf0_DWork.Memory34_PreviousInput = rtb_Memory33;

  /* Update for Memory: '<S1>/Memory35' */
  lpf0_DWork.Memory35_PreviousInput = rtb_Memory34;
}

/* Model initialize function */
void lpf0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(lpf0_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &lpf0_B), 0,
                sizeof(BlockIO_lpf0));

  /* states (dwork) */
  (void) memset((void *)&lpf0_DWork, 0,
                sizeof(D_Work_lpf0));

  /* external inputs */
  (void) memset((void *)&lpf0_U, 0,
                sizeof(ExternalInputs_lpf0));

  /* external outputs */
  (void) memset((void *)&lpf0_Y, 0,
                sizeof(ExternalOutputs_lpf0));

  /* InitializeConditions for Memory: '<S1>/Memory' */
  lpf0_DWork.Memory_PreviousInput = lpf0_P.Memory_X0;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  lpf0_DWork.Memory1_PreviousInput = lpf0_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S1>/Memory2' */
  lpf0_DWork.Memory2_PreviousInput = lpf0_P.Memory2_X0;

  /* InitializeConditions for Memory: '<S1>/Memory3' */
  lpf0_DWork.Memory3_PreviousInput = lpf0_P.Memory3_X0;

  /* InitializeConditions for Memory: '<S1>/Memory4' */
  lpf0_DWork.Memory4_PreviousInput = lpf0_P.Memory4_X0;

  /* InitializeConditions for Memory: '<S1>/Memory5' */
  lpf0_DWork.Memory5_PreviousInput = lpf0_P.Memory5_X0;

  /* InitializeConditions for Memory: '<S1>/Memory6' */
  lpf0_DWork.Memory6_PreviousInput = lpf0_P.Memory6_X0;

  /* InitializeConditions for Memory: '<S1>/Memory7' */
  lpf0_DWork.Memory7_PreviousInput = lpf0_P.Memory7_X0;

  /* InitializeConditions for Memory: '<S1>/Memory8' */
  lpf0_DWork.Memory8_PreviousInput = lpf0_P.Memory8_X0;

  /* InitializeConditions for Memory: '<S1>/Memory9' */
  lpf0_DWork.Memory9_PreviousInput = lpf0_P.Memory9_X0;

  /* InitializeConditions for Memory: '<S1>/Memory10' */
  lpf0_DWork.Memory10_PreviousInput = lpf0_P.Memory10_X0;

  /* InitializeConditions for Memory: '<S1>/Memory11' */
  lpf0_DWork.Memory11_PreviousInput = lpf0_P.Memory11_X0;

  /* InitializeConditions for Memory: '<S1>/Memory14' */
  lpf0_DWork.Memory14_PreviousInput = lpf0_P.Memory14_X0;

  /* InitializeConditions for Memory: '<S1>/Memory15' */
  lpf0_DWork.Memory15_PreviousInput = lpf0_P.Memory15_X0;

  /* InitializeConditions for Memory: '<S1>/Memory16' */
  lpf0_DWork.Memory16_PreviousInput = lpf0_P.Memory16_X0;

  /* InitializeConditions for Memory: '<S1>/Memory17' */
  lpf0_DWork.Memory17_PreviousInput = lpf0_P.Memory17_X0;

  /* InitializeConditions for Memory: '<S1>/Memory12' */
  lpf0_DWork.Memory12_PreviousInput = lpf0_P.Memory12_X0;

  /* InitializeConditions for Memory: '<S1>/Memory13' */
  lpf0_DWork.Memory13_PreviousInput = lpf0_P.Memory13_X0;

  /* InitializeConditions for Memory: '<S1>/Memory36' */
  lpf0_DWork.Memory36_PreviousInput = lpf0_P.Memory36_X0;

  /* InitializeConditions for Memory: '<S1>/Memory37' */
  lpf0_DWork.Memory37_PreviousInput = lpf0_P.Memory37_X0;

  /* InitializeConditions for Memory: '<S1>/Memory38' */
  lpf0_DWork.Memory38_PreviousInput = lpf0_P.Memory38_X0;

  /* InitializeConditions for Memory: '<S1>/Memory39' */
  lpf0_DWork.Memory39_PreviousInput = lpf0_P.Memory39_X0;

  /* InitializeConditions for Memory: '<S1>/Memory40' */
  lpf0_DWork.Memory40_PreviousInput = lpf0_P.Memory40_X0;

  /* InitializeConditions for Memory: '<S1>/Memory41' */
  lpf0_DWork.Memory41_PreviousInput = lpf0_P.Memory41_X0;

  /* InitializeConditions for Memory: '<S1>/Memory42' */
  lpf0_DWork.Memory42_PreviousInput = lpf0_P.Memory42_X0;

  /* InitializeConditions for Memory: '<S1>/Memory43' */
  lpf0_DWork.Memory43_PreviousInput = lpf0_P.Memory43_X0;

  /* InitializeConditions for Memory: '<S1>/Memory44' */
  lpf0_DWork.Memory44_PreviousInput = lpf0_P.Memory44_X0;

  /* InitializeConditions for Memory: '<S1>/Memory45' */
  lpf0_DWork.Memory45_PreviousInput = lpf0_P.Memory45_X0;

  /* InitializeConditions for Memory: '<S1>/Memory46' */
  lpf0_DWork.Memory46_PreviousInput = lpf0_P.Memory46_X0;

  /* InitializeConditions for Memory: '<S1>/Memory47' */
  lpf0_DWork.Memory47_PreviousInput = lpf0_P.Memory47_X0;

  /* InitializeConditions for Memory: '<S1>/Memory48' */
  lpf0_DWork.Memory48_PreviousInput = lpf0_P.Memory48_X0;

  /* InitializeConditions for Memory: '<S1>/Memory49' */
  lpf0_DWork.Memory49_PreviousInput = lpf0_P.Memory49_X0;

  /* InitializeConditions for Memory: '<S1>/Memory50' */
  lpf0_DWork.Memory50_PreviousInput = lpf0_P.Memory50_X0;

  /* InitializeConditions for Memory: '<S1>/Memory51' */
  lpf0_DWork.Memory51_PreviousInput = lpf0_P.Memory51_X0;

  /* InitializeConditions for Memory: '<S1>/Memory52' */
  lpf0_DWork.Memory52_PreviousInput = lpf0_P.Memory52_X0;

  /* InitializeConditions for Memory: '<S1>/Memory53' */
  lpf0_DWork.Memory53_PreviousInput = lpf0_P.Memory53_X0;

  /* InitializeConditions for Memory: '<S1>/Memory18' */
  lpf0_DWork.Memory18_PreviousInput = lpf0_P.Memory18_X0;

  /* InitializeConditions for Memory: '<S1>/Memory19' */
  lpf0_DWork.Memory19_PreviousInput = lpf0_P.Memory19_X0;

  /* InitializeConditions for Memory: '<S1>/Memory20' */
  lpf0_DWork.Memory20_PreviousInput = lpf0_P.Memory20_X0;

  /* InitializeConditions for Memory: '<S1>/Memory21' */
  lpf0_DWork.Memory21_PreviousInput = lpf0_P.Memory21_X0;

  /* InitializeConditions for Memory: '<S1>/Memory22' */
  lpf0_DWork.Memory22_PreviousInput = lpf0_P.Memory22_X0;

  /* InitializeConditions for Memory: '<S1>/Memory23' */
  lpf0_DWork.Memory23_PreviousInput = lpf0_P.Memory23_X0;

  /* InitializeConditions for Memory: '<S1>/Memory24' */
  lpf0_DWork.Memory24_PreviousInput = lpf0_P.Memory24_X0;

  /* InitializeConditions for Memory: '<S1>/Memory25' */
  lpf0_DWork.Memory25_PreviousInput = lpf0_P.Memory25_X0;

  /* InitializeConditions for Memory: '<S1>/Memory26' */
  lpf0_DWork.Memory26_PreviousInput = lpf0_P.Memory26_X0;

  /* InitializeConditions for Memory: '<S1>/Memory27' */
  lpf0_DWork.Memory27_PreviousInput = lpf0_P.Memory27_X0;

  /* InitializeConditions for Memory: '<S1>/Memory28' */
  lpf0_DWork.Memory28_PreviousInput = lpf0_P.Memory28_X0;

  /* InitializeConditions for Memory: '<S1>/Memory29' */
  lpf0_DWork.Memory29_PreviousInput = lpf0_P.Memory29_X0;

  /* InitializeConditions for Memory: '<S1>/Memory30' */
  lpf0_DWork.Memory30_PreviousInput = lpf0_P.Memory30_X0;

  /* InitializeConditions for Memory: '<S1>/Memory31' */
  lpf0_DWork.Memory31_PreviousInput = lpf0_P.Memory31_X0;

  /* InitializeConditions for Memory: '<S1>/Memory32' */
  lpf0_DWork.Memory32_PreviousInput = lpf0_P.Memory32_X0;

  /* InitializeConditions for Memory: '<S1>/Memory33' */
  lpf0_DWork.Memory33_PreviousInput = lpf0_P.Memory33_X0;

  /* InitializeConditions for Memory: '<S1>/Memory34' */
  lpf0_DWork.Memory34_PreviousInput = lpf0_P.Memory34_X0;

  /* InitializeConditions for Memory: '<S1>/Memory35' */
  lpf0_DWork.Memory35_PreviousInput = lpf0_P.Memory35_X0;
}

/* Model terminate function */
void lpf0_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
