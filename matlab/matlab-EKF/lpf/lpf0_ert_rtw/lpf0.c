/*
 * File: lpf0.c
 *
 * Code generated for Simulink model 'lpf0'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Tue Nov 01 12:44:21 2011
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
  real_T rtb_Memory5;
  real_T rtb_Memory6;
  real_T rtb_Memory8;
  real_T rtb_Memory9;
  real_T rtb_Memory10;
  real_T rtb_Memory11;
  real_T rtb_Memory12;
  real_T rtb_Memory13;
  real_T rtb_Memory14;
  real_T rtb_Memory15;
  real_T rtb_Memory17;
  real_T rtb_Memory26;
  real_T rtb_Memory18;
  real_T rtb_Memory19;
  real_T rtb_Memory20;
  real_T rtb_Memory21;
  real_T rtb_Memory22;
  real_T rtb_Memory23;
  real_T rtb_Memory25;

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

  /* Memory: '<S1>/Memory5' */
  rtb_Memory5 = lpf0_DWork.Memory5_PreviousInput;

  /* Memory: '<S1>/Memory6' */
  rtb_Memory6 = lpf0_DWork.Memory6_PreviousInput;

  /* Memory: '<S1>/Memory8' */
  rtb_Memory8 = lpf0_DWork.Memory8_PreviousInput;

  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/acc_x'
   *  Memory: '<S1>/Memory'
   *  Memory: '<S1>/Memory1'
   *  Memory: '<S1>/Memory2'
   *  Memory: '<S1>/Memory3'
   *  Memory: '<S1>/Memory4'
   *  Memory: '<S1>/Memory5'
   *  Memory: '<S1>/Memory6'
   *  Memory: '<S1>/Memory7'
   *  Memory: '<S1>/Memory8'
   *  Sum: '<S1>/Add'
   */
  lpf0_B.Gain = (real_T)(real32_T)(((((((((lpf0_U.acc_x +
    lpf0_DWork.Memory_PreviousInput) + lpf0_DWork.Memory1_PreviousInput) +
    lpf0_DWork.Memory2_PreviousInput) + lpf0_DWork.Memory3_PreviousInput) +
    lpf0_DWork.Memory4_PreviousInput) + lpf0_DWork.Memory5_PreviousInput) +
    lpf0_DWork.Memory6_PreviousInput) + lpf0_DWork.Memory8_PreviousInput) +
    lpf0_DWork.Memory7_PreviousInput) * (real_T)lpf0_P.Gain_Gain;

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

  /* Memory: '<S1>/Memory9' */
  rtb_Memory9 = lpf0_DWork.Memory9_PreviousInput;

  /* Memory: '<S1>/Memory10' */
  rtb_Memory10 = lpf0_DWork.Memory10_PreviousInput;

  /* Memory: '<S1>/Memory11' */
  rtb_Memory11 = lpf0_DWork.Memory11_PreviousInput;

  /* Memory: '<S1>/Memory12' */
  rtb_Memory12 = lpf0_DWork.Memory12_PreviousInput;

  /* Memory: '<S1>/Memory13' */
  rtb_Memory13 = lpf0_DWork.Memory13_PreviousInput;

  /* Memory: '<S1>/Memory14' */
  rtb_Memory14 = lpf0_DWork.Memory14_PreviousInput;

  /* Memory: '<S1>/Memory15' */
  rtb_Memory15 = lpf0_DWork.Memory15_PreviousInput;

  /* Memory: '<S1>/Memory17' */
  rtb_Memory17 = lpf0_DWork.Memory17_PreviousInput;

  /* Gain: '<S1>/Gain1' incorporates:
   *  Inport: '<Root>/acc_y'
   *  Memory: '<S1>/Memory10'
   *  Memory: '<S1>/Memory11'
   *  Memory: '<S1>/Memory12'
   *  Memory: '<S1>/Memory13'
   *  Memory: '<S1>/Memory14'
   *  Memory: '<S1>/Memory15'
   *  Memory: '<S1>/Memory16'
   *  Memory: '<S1>/Memory17'
   *  Memory: '<S1>/Memory9'
   *  Sum: '<S1>/Add1'
   */
  lpf0_B.Gain1 = (real_T)(real32_T)(((((((((lpf0_U.acc_y +
    lpf0_DWork.Memory9_PreviousInput) + lpf0_DWork.Memory10_PreviousInput) +
    lpf0_DWork.Memory11_PreviousInput) + lpf0_DWork.Memory12_PreviousInput) +
    lpf0_DWork.Memory13_PreviousInput) + lpf0_DWork.Memory14_PreviousInput) +
    lpf0_DWork.Memory15_PreviousInput) + lpf0_DWork.Memory17_PreviousInput) +
    lpf0_DWork.Memory16_PreviousInput) * (real_T)lpf0_P.Gain1_Gain;

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

  /* Memory: '<S1>/Memory26' */
  rtb_Memory26 = lpf0_DWork.Memory26_PreviousInput;

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

  /* Memory: '<S1>/Memory23' */
  rtb_Memory23 = lpf0_DWork.Memory23_PreviousInput;

  /* Memory: '<S1>/Memory25' */
  rtb_Memory25 = lpf0_DWork.Memory25_PreviousInput;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Inport: '<Root>/acc_z'
   *  Memory: '<S1>/Memory18'
   *  Memory: '<S1>/Memory19'
   *  Memory: '<S1>/Memory20'
   *  Memory: '<S1>/Memory21'
   *  Memory: '<S1>/Memory22'
   *  Memory: '<S1>/Memory23'
   *  Memory: '<S1>/Memory24'
   *  Memory: '<S1>/Memory25'
   *  Memory: '<S1>/Memory26'
   *  Sum: '<S1>/Add2'
   */
  lpf0_B.Gain2 = (real_T)(real32_T)(((((((((lpf0_U.acc_z +
    lpf0_DWork.Memory26_PreviousInput) + lpf0_DWork.Memory18_PreviousInput) +
    lpf0_DWork.Memory19_PreviousInput) + lpf0_DWork.Memory20_PreviousInput) +
    lpf0_DWork.Memory21_PreviousInput) + lpf0_DWork.Memory22_PreviousInput) +
    lpf0_DWork.Memory23_PreviousInput) + lpf0_DWork.Memory25_PreviousInput) +
    lpf0_DWork.Memory24_PreviousInput) * (real_T)lpf0_P.Gain2_Gain;

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

  /* S-Function (sdspfilter2): '<S14>/Stage1' incorporates:
   *  Inport: '<Root>/gyro_x'
   */
  accum = lpf0_U.gyro_x * lpf0_P.Stage1_RTP1COEFF_h[0];
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

  lpf0_DWork.Stage1_FILT_STATES_g[cfIdx] = lpf0_U.gyro_x;
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

  /* S-Function (sdspfilter2): '<S15>/Stage1' incorporates:
   *  Inport: '<Root>/gyro_y'
   */
  accum = lpf0_U.gyro_y * lpf0_P.Stage1_RTP1COEFF_gn[0];
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

  lpf0_DWork.Stage1_FILT_STATES_f1[cfIdx] = lpf0_U.gyro_y;
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

  /* S-Function (sdspfilter2): '<S16>/Stage1' incorporates:
   *  Inport: '<Root>/gyro_z'
   */
  accum = lpf0_U.gyro_z * lpf0_P.Stage1_RTP1COEFF_a[0];
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

  lpf0_DWork.Stage1_FILT_STATES_o[cfIdx] = lpf0_U.gyro_z;
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

  /* S-Function (sdspfilter2): '<S17>/Stage1' incorporates:
   *  Inport: '<Root>/mag_x'
   */
  accum = lpf0_U.mag_x * lpf0_P.Stage1_RTP1COEFF_e[0];
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

  lpf0_DWork.Stage1_FILT_STATES_a[cfIdx] = lpf0_U.mag_x;
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

  /* S-Function (sdspfilter2): '<S18>/Stage1' incorporates:
   *  Inport: '<Root>/mag_y'
   */
  accum = lpf0_U.mag_y * lpf0_P.Stage1_RTP1COEFF_hv[0];
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

  lpf0_DWork.Stage1_FILT_STATES_d[cfIdx] = lpf0_U.mag_y;
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

  /* S-Function (sdspfilter2): '<S19>/Stage1' incorporates:
   *  Inport: '<Root>/mag_z'
   */
  accum = lpf0_U.mag_z * lpf0_P.Stage1_RTP1COEFF_o[0];
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

  lpf0_DWork.Stage1_FILT_STATES_n[cfIdx] = lpf0_U.mag_z;
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
  lpf0_DWork.Memory6_PreviousInput = rtb_Memory5;

  /* Update for Memory: '<S1>/Memory8' */
  lpf0_DWork.Memory8_PreviousInput = rtb_Memory6;

  /* Update for Memory: '<S1>/Memory7' */
  lpf0_DWork.Memory7_PreviousInput = rtb_Memory8;

  /* Update for Memory: '<S1>/Memory9' */
  lpf0_DWork.Memory9_PreviousInput = lpf0_B.Gain1;

  /* Update for Memory: '<S1>/Memory10' */
  lpf0_DWork.Memory10_PreviousInput = rtb_Memory9;

  /* Update for Memory: '<S1>/Memory11' */
  lpf0_DWork.Memory11_PreviousInput = rtb_Memory10;

  /* Update for Memory: '<S1>/Memory12' */
  lpf0_DWork.Memory12_PreviousInput = rtb_Memory11;

  /* Update for Memory: '<S1>/Memory13' */
  lpf0_DWork.Memory13_PreviousInput = rtb_Memory12;

  /* Update for Memory: '<S1>/Memory14' */
  lpf0_DWork.Memory14_PreviousInput = rtb_Memory13;

  /* Update for Memory: '<S1>/Memory15' */
  lpf0_DWork.Memory15_PreviousInput = rtb_Memory14;

  /* Update for Memory: '<S1>/Memory17' */
  lpf0_DWork.Memory17_PreviousInput = rtb_Memory15;

  /* Update for Memory: '<S1>/Memory16' */
  lpf0_DWork.Memory16_PreviousInput = rtb_Memory17;

  /* Update for Memory: '<S1>/Memory26' */
  lpf0_DWork.Memory26_PreviousInput = lpf0_B.Gain2;

  /* Update for Memory: '<S1>/Memory18' */
  lpf0_DWork.Memory18_PreviousInput = rtb_Memory26;

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

  /* Update for Memory: '<S1>/Memory25' */
  lpf0_DWork.Memory25_PreviousInput = rtb_Memory23;

  /* Update for Memory: '<S1>/Memory24' */
  lpf0_DWork.Memory24_PreviousInput = rtb_Memory25;
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

  /* InitializeConditions for Memory: '<S1>/Memory8' */
  lpf0_DWork.Memory8_PreviousInput = lpf0_P.Memory8_X0;

  /* InitializeConditions for Memory: '<S1>/Memory7' */
  lpf0_DWork.Memory7_PreviousInput = lpf0_P.Memory7_X0;

  /* InitializeConditions for Memory: '<S1>/Memory9' */
  lpf0_DWork.Memory9_PreviousInput = lpf0_P.Memory9_X0;

  /* InitializeConditions for Memory: '<S1>/Memory10' */
  lpf0_DWork.Memory10_PreviousInput = lpf0_P.Memory10_X0;

  /* InitializeConditions for Memory: '<S1>/Memory11' */
  lpf0_DWork.Memory11_PreviousInput = lpf0_P.Memory11_X0;

  /* InitializeConditions for Memory: '<S1>/Memory12' */
  lpf0_DWork.Memory12_PreviousInput = lpf0_P.Memory12_X0;

  /* InitializeConditions for Memory: '<S1>/Memory13' */
  lpf0_DWork.Memory13_PreviousInput = lpf0_P.Memory13_X0;

  /* InitializeConditions for Memory: '<S1>/Memory14' */
  lpf0_DWork.Memory14_PreviousInput = lpf0_P.Memory14_X0;

  /* InitializeConditions for Memory: '<S1>/Memory15' */
  lpf0_DWork.Memory15_PreviousInput = lpf0_P.Memory15_X0;

  /* InitializeConditions for Memory: '<S1>/Memory17' */
  lpf0_DWork.Memory17_PreviousInput = lpf0_P.Memory17_X0;

  /* InitializeConditions for Memory: '<S1>/Memory16' */
  lpf0_DWork.Memory16_PreviousInput = lpf0_P.Memory16_X0;

  /* InitializeConditions for Memory: '<S1>/Memory26' */
  lpf0_DWork.Memory26_PreviousInput = lpf0_P.Memory26_X0;

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

  /* InitializeConditions for Memory: '<S1>/Memory25' */
  lpf0_DWork.Memory25_PreviousInput = lpf0_P.Memory25_X0;

  /* InitializeConditions for Memory: '<S1>/Memory24' */
  lpf0_DWork.Memory24_PreviousInput = lpf0_P.Memory24_X0;
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
