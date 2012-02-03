/*
 * File: lpf0.c
 *
 * Code generated for Simulink model 'lpf0'.
 *
 * Model version                  : 1.37
 * Simulink Coder version         : 8.0 (R2011a) 09-Mar-2011
 * TLC version                    : 8.0 (Feb  3 2011)
 * C/C++ source code generated on : Fri Feb 03 19:28:27 2012
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "lpf0.h"
#include "lpf0_private.h"

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
  real_T rtb_Memory;
  real_T rtb_Memory1;
  real_T rtb_Memory2;
  real_T rtb_Memory3;
  real_T rtb_Memory4;
  real_T rtb_Memory5;
  real_T rtb_Memory54;
  real_T rtb_Gain;
  real_T rtb_Memory6;
  real_T rtb_Memory7;
  real_T rtb_Memory8;
  real_T rtb_Memory9;
  real_T rtb_Memory10;
  real_T rtb_Memory11;
  real_T rtb_Memory58;
  real_T rtb_Gain1;
  real_T rtb_Memory16;
  real_T rtb_Memory63;
  real_T rtb_Memory64;
  real_T rtb_Memory65;
  real_T rtb_Memory12;
  real_T rtb_Memory13;
  real_T rtb_Memory14;
  real_T rtb_Gain2;
  real_T rtb_Memory40;
  real_T rtb_Memory67;
  real_T rtb_Memory68;
  real_T rtb_Memory69;
  real_T rtb_Memory36;
  real_T rtb_Memory37;
  real_T rtb_Memory38;
  real_T rtb_Gain6;
  real_T rtb_Memory46;
  real_T rtb_Memory71;
  real_T rtb_Memory72;
  real_T rtb_Memory73;
  real_T rtb_Memory42;
  real_T rtb_Memory43;
  real_T rtb_Memory44;
  real_T rtb_Gain7;
  real_T rtb_Memory52;
  real_T rtb_Memory75;
  real_T rtb_Memory76;
  real_T rtb_Memory77;
  real_T rtb_Memory48;
  real_T rtb_Memory49;
  real_T rtb_Memory50;
  real_T rtb_Gain8;
  real_T rtb_Memory22;
  real_T rtb_Memory79;
  real_T rtb_Memory80;
  real_T rtb_Memory81;
  real_T rtb_Memory18;
  real_T rtb_Memory19;
  real_T rtb_Memory20;
  real_T rtb_Gain3;
  real_T rtb_Memory28;
  real_T rtb_Memory83;
  real_T rtb_Memory84;
  real_T rtb_Memory85;
  real_T rtb_Memory24;
  real_T rtb_Memory25;
  real_T rtb_Memory26;
  real_T rtb_Gain4;
  real_T rtb_Memory34;
  real_T rtb_Memory87;
  real_T rtb_Memory88;
  real_T rtb_Memory89;
  real_T rtb_Memory30;
  real_T rtb_Memory31;
  real_T rtb_Memory32;
  real_T rtb_Gain5;

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

  /* Memory: '<S1>/Memory54' */
  rtb_Memory54 = lpf0_DWork.Memory54_PreviousInput;

  /* Gain: '<S1>/Gain' incorporates:
   *  Inport: '<Root>/acc_x'
   *  Inport: '<Root>/acc_x1'
   *  Inport: '<Root>/acc_x2'
   *  Memory: '<S1>/Memory'
   *  Memory: '<S1>/Memory1'
   *  Memory: '<S1>/Memory2'
   *  Memory: '<S1>/Memory3'
   *  Memory: '<S1>/Memory4'
   *  Memory: '<S1>/Memory5'
   *  Memory: '<S1>/Memory54'
   *  Memory: '<S1>/Memory55'
   *  Sum: '<S1>/Add'
   */
  rtb_Gain = (real_T)(real32_T)((((((((((lpf0_U.acc_x + lpf0_U.acc_x1) +
    lpf0_U.acc_x2) + lpf0_DWork.Memory_PreviousInput) +
    lpf0_DWork.Memory1_PreviousInput) + lpf0_DWork.Memory2_PreviousInput) +
    lpf0_DWork.Memory3_PreviousInput) + lpf0_DWork.Memory4_PreviousInput) +
    lpf0_DWork.Memory5_PreviousInput) + lpf0_DWork.Memory54_PreviousInput) +
    lpf0_DWork.Memory55_PreviousInput) * (real_T)lpf0_P.Gain_Gain;

  /* Outport: '<Root>/acc_x_f' */
  lpf0_Y.acc_x_f = rtb_Gain;

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

  /* Memory: '<S1>/Memory11' */
  rtb_Memory11 = lpf0_DWork.Memory11_PreviousInput;

  /* Memory: '<S1>/Memory58' */
  rtb_Memory58 = lpf0_DWork.Memory58_PreviousInput;

  /* Gain: '<S1>/Gain1' incorporates:
   *  Inport: '<Root>/acc_y'
   *  Inport: '<Root>/acc_y1'
   *  Inport: '<Root>/acc_y2'
   *  Memory: '<S1>/Memory10'
   *  Memory: '<S1>/Memory11'
   *  Memory: '<S1>/Memory17'
   *  Memory: '<S1>/Memory58'
   *  Memory: '<S1>/Memory6'
   *  Memory: '<S1>/Memory7'
   *  Memory: '<S1>/Memory8'
   *  Memory: '<S1>/Memory9'
   *  Sum: '<S1>/Add1'
   */
  rtb_Gain1 = (real_T)(real32_T)((((((((((lpf0_U.acc_y + lpf0_U.acc_y1) +
    lpf0_U.acc_y2) + lpf0_DWork.Memory6_PreviousInput) +
    lpf0_DWork.Memory7_PreviousInput) + lpf0_DWork.Memory8_PreviousInput) +
    lpf0_DWork.Memory9_PreviousInput) + lpf0_DWork.Memory10_PreviousInput) +
    lpf0_DWork.Memory11_PreviousInput) + lpf0_DWork.Memory58_PreviousInput) +
    lpf0_DWork.Memory17_PreviousInput) * (real_T)lpf0_P.Gain1_Gain;

  /* Outport: '<Root>/acc_y_f' */
  lpf0_Y.acc_y_f = rtb_Gain1;

  /* Memory: '<S1>/Memory16' */
  rtb_Memory16 = lpf0_DWork.Memory16_PreviousInput;

  /* Memory: '<S1>/Memory63' */
  rtb_Memory63 = lpf0_DWork.Memory63_PreviousInput;

  /* Memory: '<S1>/Memory64' */
  rtb_Memory64 = lpf0_DWork.Memory64_PreviousInput;

  /* Memory: '<S1>/Memory65' */
  rtb_Memory65 = lpf0_DWork.Memory65_PreviousInput;

  /* Memory: '<S1>/Memory12' */
  rtb_Memory12 = lpf0_DWork.Memory12_PreviousInput;

  /* Memory: '<S1>/Memory13' */
  rtb_Memory13 = lpf0_DWork.Memory13_PreviousInput;

  /* Memory: '<S1>/Memory14' */
  rtb_Memory14 = lpf0_DWork.Memory14_PreviousInput;

  /* Gain: '<S1>/Gain2' incorporates:
   *  Inport: '<Root>/acc_z'
   *  Inport: '<Root>/acc_z1'
   *  Inport: '<Root>/acc_z2'
   *  Memory: '<S1>/Memory12'
   *  Memory: '<S1>/Memory13'
   *  Memory: '<S1>/Memory14'
   *  Memory: '<S1>/Memory15'
   *  Memory: '<S1>/Memory16'
   *  Memory: '<S1>/Memory63'
   *  Memory: '<S1>/Memory64'
   *  Memory: '<S1>/Memory65'
   *  Sum: '<S1>/Add2'
   */
  rtb_Gain2 = (real_T)(real32_T)((((((((((lpf0_U.acc_z + lpf0_U.acc_z1) +
    lpf0_U.acc_z2) + lpf0_DWork.Memory16_PreviousInput) +
    lpf0_DWork.Memory63_PreviousInput) + lpf0_DWork.Memory64_PreviousInput) +
    lpf0_DWork.Memory65_PreviousInput) + lpf0_DWork.Memory12_PreviousInput) +
    lpf0_DWork.Memory13_PreviousInput) + lpf0_DWork.Memory14_PreviousInput) +
    lpf0_DWork.Memory15_PreviousInput) * (real_T)lpf0_P.Gain2_Gain;

  /* Outport: '<Root>/acc_z_f' */
  lpf0_Y.acc_z_f = rtb_Gain2;

  /* Memory: '<S1>/Memory40' */
  rtb_Memory40 = lpf0_DWork.Memory40_PreviousInput;

  /* Memory: '<S1>/Memory67' */
  rtb_Memory67 = lpf0_DWork.Memory67_PreviousInput;

  /* Memory: '<S1>/Memory68' */
  rtb_Memory68 = lpf0_DWork.Memory68_PreviousInput;

  /* Memory: '<S1>/Memory69' */
  rtb_Memory69 = lpf0_DWork.Memory69_PreviousInput;

  /* Memory: '<S1>/Memory36' */
  rtb_Memory36 = lpf0_DWork.Memory36_PreviousInput;

  /* Memory: '<S1>/Memory37' */
  rtb_Memory37 = lpf0_DWork.Memory37_PreviousInput;

  /* Memory: '<S1>/Memory38' */
  rtb_Memory38 = lpf0_DWork.Memory38_PreviousInput;

  /* Gain: '<S1>/Gain6' incorporates:
   *  Inport: '<Root>/gyro_x'
   *  Inport: '<Root>/gyro_x1'
   *  Inport: '<Root>/gyro_x2'
   *  Memory: '<S1>/Memory36'
   *  Memory: '<S1>/Memory37'
   *  Memory: '<S1>/Memory38'
   *  Memory: '<S1>/Memory39'
   *  Memory: '<S1>/Memory40'
   *  Memory: '<S1>/Memory67'
   *  Memory: '<S1>/Memory68'
   *  Memory: '<S1>/Memory69'
   *  Sum: '<S1>/Add6'
   */
  rtb_Gain6 = (real_T)(real32_T)((((((((((lpf0_U.gyro_x + lpf0_U.gyro_x1) +
    lpf0_U.gyro_x2) + lpf0_DWork.Memory40_PreviousInput) +
    lpf0_DWork.Memory67_PreviousInput) + lpf0_DWork.Memory68_PreviousInput) +
    lpf0_DWork.Memory69_PreviousInput) + lpf0_DWork.Memory36_PreviousInput) +
    lpf0_DWork.Memory37_PreviousInput) + lpf0_DWork.Memory38_PreviousInput) +
    lpf0_DWork.Memory39_PreviousInput) * (real_T)lpf0_P.Gain6_Gain;

  /* Outport: '<Root>/gyro_x_f' */
  lpf0_Y.gyro_x_f = rtb_Gain6;

  /* Memory: '<S1>/Memory46' */
  rtb_Memory46 = lpf0_DWork.Memory46_PreviousInput;

  /* Memory: '<S1>/Memory71' */
  rtb_Memory71 = lpf0_DWork.Memory71_PreviousInput;

  /* Memory: '<S1>/Memory72' */
  rtb_Memory72 = lpf0_DWork.Memory72_PreviousInput;

  /* Memory: '<S1>/Memory73' */
  rtb_Memory73 = lpf0_DWork.Memory73_PreviousInput;

  /* Memory: '<S1>/Memory42' */
  rtb_Memory42 = lpf0_DWork.Memory42_PreviousInput;

  /* Memory: '<S1>/Memory43' */
  rtb_Memory43 = lpf0_DWork.Memory43_PreviousInput;

  /* Memory: '<S1>/Memory44' */
  rtb_Memory44 = lpf0_DWork.Memory44_PreviousInput;

  /* Gain: '<S1>/Gain7' incorporates:
   *  Inport: '<Root>/gyro_y'
   *  Inport: '<Root>/gyro_y1'
   *  Inport: '<Root>/gyro_y2'
   *  Memory: '<S1>/Memory42'
   *  Memory: '<S1>/Memory43'
   *  Memory: '<S1>/Memory44'
   *  Memory: '<S1>/Memory45'
   *  Memory: '<S1>/Memory46'
   *  Memory: '<S1>/Memory71'
   *  Memory: '<S1>/Memory72'
   *  Memory: '<S1>/Memory73'
   *  Sum: '<S1>/Add7'
   */
  rtb_Gain7 = (real_T)(real32_T)((((((((((lpf0_U.gyro_y + lpf0_U.gyro_y1) +
    lpf0_U.gyro_y2) + lpf0_DWork.Memory46_PreviousInput) +
    lpf0_DWork.Memory71_PreviousInput) + lpf0_DWork.Memory72_PreviousInput) +
    lpf0_DWork.Memory73_PreviousInput) + lpf0_DWork.Memory42_PreviousInput) +
    lpf0_DWork.Memory43_PreviousInput) + lpf0_DWork.Memory44_PreviousInput) +
    lpf0_DWork.Memory45_PreviousInput) * (real_T)lpf0_P.Gain7_Gain;

  /* Outport: '<Root>/gyro_y_f' */
  lpf0_Y.gyro_y_f = rtb_Gain7;

  /* Memory: '<S1>/Memory52' */
  rtb_Memory52 = lpf0_DWork.Memory52_PreviousInput;

  /* Memory: '<S1>/Memory75' */
  rtb_Memory75 = lpf0_DWork.Memory75_PreviousInput;

  /* Memory: '<S1>/Memory76' */
  rtb_Memory76 = lpf0_DWork.Memory76_PreviousInput;

  /* Memory: '<S1>/Memory77' */
  rtb_Memory77 = lpf0_DWork.Memory77_PreviousInput;

  /* Memory: '<S1>/Memory48' */
  rtb_Memory48 = lpf0_DWork.Memory48_PreviousInput;

  /* Memory: '<S1>/Memory49' */
  rtb_Memory49 = lpf0_DWork.Memory49_PreviousInput;

  /* Memory: '<S1>/Memory50' */
  rtb_Memory50 = lpf0_DWork.Memory50_PreviousInput;

  /* Gain: '<S1>/Gain8' incorporates:
   *  Inport: '<Root>/gyro_z'
   *  Inport: '<Root>/gyro_z1'
   *  Inport: '<Root>/gyro_z2'
   *  Memory: '<S1>/Memory48'
   *  Memory: '<S1>/Memory49'
   *  Memory: '<S1>/Memory50'
   *  Memory: '<S1>/Memory51'
   *  Memory: '<S1>/Memory52'
   *  Memory: '<S1>/Memory75'
   *  Memory: '<S1>/Memory76'
   *  Memory: '<S1>/Memory77'
   *  Sum: '<S1>/Add8'
   */
  rtb_Gain8 = (real_T)(real32_T)((((((((((lpf0_U.gyro_z + lpf0_U.gyro_z1) +
    lpf0_U.gyro_z2) + lpf0_DWork.Memory52_PreviousInput) +
    lpf0_DWork.Memory75_PreviousInput) + lpf0_DWork.Memory76_PreviousInput) +
    lpf0_DWork.Memory77_PreviousInput) + lpf0_DWork.Memory48_PreviousInput) +
    lpf0_DWork.Memory49_PreviousInput) + lpf0_DWork.Memory50_PreviousInput) +
    lpf0_DWork.Memory51_PreviousInput) * (real_T)lpf0_P.Gain8_Gain;

  /* Outport: '<Root>/gyro_z_f' */
  lpf0_Y.gyro_z_f = rtb_Gain8;

  /* Memory: '<S1>/Memory22' */
  rtb_Memory22 = lpf0_DWork.Memory22_PreviousInput;

  /* Memory: '<S1>/Memory79' */
  rtb_Memory79 = lpf0_DWork.Memory79_PreviousInput;

  /* Memory: '<S1>/Memory80' */
  rtb_Memory80 = lpf0_DWork.Memory80_PreviousInput;

  /* Memory: '<S1>/Memory81' */
  rtb_Memory81 = lpf0_DWork.Memory81_PreviousInput;

  /* Memory: '<S1>/Memory18' */
  rtb_Memory18 = lpf0_DWork.Memory18_PreviousInput;

  /* Memory: '<S1>/Memory19' */
  rtb_Memory19 = lpf0_DWork.Memory19_PreviousInput;

  /* Memory: '<S1>/Memory20' */
  rtb_Memory20 = lpf0_DWork.Memory20_PreviousInput;

  /* Gain: '<S1>/Gain3' incorporates:
   *  Inport: '<Root>/mag_x'
   *  Inport: '<Root>/mag_x1'
   *  Inport: '<Root>/mag_x2'
   *  Memory: '<S1>/Memory18'
   *  Memory: '<S1>/Memory19'
   *  Memory: '<S1>/Memory20'
   *  Memory: '<S1>/Memory21'
   *  Memory: '<S1>/Memory22'
   *  Memory: '<S1>/Memory79'
   *  Memory: '<S1>/Memory80'
   *  Memory: '<S1>/Memory81'
   *  Sum: '<S1>/Add3'
   */
  rtb_Gain3 = (real_T)(real32_T)((((((((((lpf0_U.mag_x + lpf0_U.mag_x1) +
    lpf0_U.mag_x2) + lpf0_DWork.Memory22_PreviousInput) +
    lpf0_DWork.Memory79_PreviousInput) + lpf0_DWork.Memory80_PreviousInput) +
    lpf0_DWork.Memory81_PreviousInput) + lpf0_DWork.Memory18_PreviousInput) +
    lpf0_DWork.Memory19_PreviousInput) + lpf0_DWork.Memory20_PreviousInput) +
    lpf0_DWork.Memory21_PreviousInput) * (real_T)lpf0_P.Gain3_Gain;

  /* Outport: '<Root>/mag_x_f' */
  lpf0_Y.mag_x_f = rtb_Gain3;

  /* Memory: '<S1>/Memory28' */
  rtb_Memory28 = lpf0_DWork.Memory28_PreviousInput;

  /* Memory: '<S1>/Memory83' */
  rtb_Memory83 = lpf0_DWork.Memory83_PreviousInput;

  /* Memory: '<S1>/Memory84' */
  rtb_Memory84 = lpf0_DWork.Memory84_PreviousInput;

  /* Memory: '<S1>/Memory85' */
  rtb_Memory85 = lpf0_DWork.Memory85_PreviousInput;

  /* Memory: '<S1>/Memory24' */
  rtb_Memory24 = lpf0_DWork.Memory24_PreviousInput;

  /* Memory: '<S1>/Memory25' */
  rtb_Memory25 = lpf0_DWork.Memory25_PreviousInput;

  /* Memory: '<S1>/Memory26' */
  rtb_Memory26 = lpf0_DWork.Memory26_PreviousInput;

  /* Gain: '<S1>/Gain4' incorporates:
   *  Inport: '<Root>/mag_y'
   *  Inport: '<Root>/mag_y1'
   *  Inport: '<Root>/mag_y2'
   *  Memory: '<S1>/Memory24'
   *  Memory: '<S1>/Memory25'
   *  Memory: '<S1>/Memory26'
   *  Memory: '<S1>/Memory27'
   *  Memory: '<S1>/Memory28'
   *  Memory: '<S1>/Memory83'
   *  Memory: '<S1>/Memory84'
   *  Memory: '<S1>/Memory85'
   *  Sum: '<S1>/Add4'
   */
  rtb_Gain4 = (real_T)(real32_T)((((((((((lpf0_U.mag_y + lpf0_U.mag_y1) +
    lpf0_U.mag_y2) + lpf0_DWork.Memory28_PreviousInput) +
    lpf0_DWork.Memory83_PreviousInput) + lpf0_DWork.Memory84_PreviousInput) +
    lpf0_DWork.Memory85_PreviousInput) + lpf0_DWork.Memory24_PreviousInput) +
    lpf0_DWork.Memory25_PreviousInput) + lpf0_DWork.Memory26_PreviousInput) +
    lpf0_DWork.Memory27_PreviousInput) * (real_T)lpf0_P.Gain4_Gain;

  /* Outport: '<Root>/mag_y_f' */
  lpf0_Y.mag_y_f = rtb_Gain4;

  /* Memory: '<S1>/Memory34' */
  rtb_Memory34 = lpf0_DWork.Memory34_PreviousInput;

  /* Memory: '<S1>/Memory87' */
  rtb_Memory87 = lpf0_DWork.Memory87_PreviousInput;

  /* Memory: '<S1>/Memory88' */
  rtb_Memory88 = lpf0_DWork.Memory88_PreviousInput;

  /* Memory: '<S1>/Memory89' */
  rtb_Memory89 = lpf0_DWork.Memory89_PreviousInput;

  /* Memory: '<S1>/Memory30' */
  rtb_Memory30 = lpf0_DWork.Memory30_PreviousInput;

  /* Memory: '<S1>/Memory31' */
  rtb_Memory31 = lpf0_DWork.Memory31_PreviousInput;

  /* Memory: '<S1>/Memory32' */
  rtb_Memory32 = lpf0_DWork.Memory32_PreviousInput;

  /* Gain: '<S1>/Gain5' incorporates:
   *  Inport: '<Root>/mag_z'
   *  Inport: '<Root>/mag_z1'
   *  Inport: '<Root>/mag_z2'
   *  Memory: '<S1>/Memory30'
   *  Memory: '<S1>/Memory31'
   *  Memory: '<S1>/Memory32'
   *  Memory: '<S1>/Memory33'
   *  Memory: '<S1>/Memory34'
   *  Memory: '<S1>/Memory87'
   *  Memory: '<S1>/Memory88'
   *  Memory: '<S1>/Memory89'
   *  Sum: '<S1>/Add5'
   */
  rtb_Gain5 = (real_T)(real32_T)((((((((((lpf0_U.mag_z + lpf0_U.mag_z1) +
    lpf0_U.mag_z2) + lpf0_DWork.Memory34_PreviousInput) +
    lpf0_DWork.Memory87_PreviousInput) + lpf0_DWork.Memory88_PreviousInput) +
    lpf0_DWork.Memory89_PreviousInput) + lpf0_DWork.Memory30_PreviousInput) +
    lpf0_DWork.Memory31_PreviousInput) + lpf0_DWork.Memory32_PreviousInput) +
    lpf0_DWork.Memory33_PreviousInput) * (real_T)lpf0_P.Gain5_Gain;

  /* Outport: '<Root>/mag_z_f' */
  lpf0_Y.mag_z_f = rtb_Gain5;

  /* Update for Memory: '<S1>/Memory' */
  lpf0_DWork.Memory_PreviousInput = rtb_Gain;

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

  /* Update for Memory: '<S1>/Memory54' */
  lpf0_DWork.Memory54_PreviousInput = rtb_Memory5;

  /* Update for Memory: '<S1>/Memory55' */
  lpf0_DWork.Memory55_PreviousInput = rtb_Memory54;

  /* Update for Memory: '<S1>/Memory6' */
  lpf0_DWork.Memory6_PreviousInput = rtb_Gain1;

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

  /* Update for Memory: '<S1>/Memory58' */
  lpf0_DWork.Memory58_PreviousInput = rtb_Memory11;

  /* Update for Memory: '<S1>/Memory17' */
  lpf0_DWork.Memory17_PreviousInput = rtb_Memory58;

  /* Update for Memory: '<S1>/Memory16' */
  lpf0_DWork.Memory16_PreviousInput = rtb_Gain2;

  /* Update for Memory: '<S1>/Memory63' */
  lpf0_DWork.Memory63_PreviousInput = rtb_Memory16;

  /* Update for Memory: '<S1>/Memory64' */
  lpf0_DWork.Memory64_PreviousInput = rtb_Memory63;

  /* Update for Memory: '<S1>/Memory65' */
  lpf0_DWork.Memory65_PreviousInput = rtb_Memory64;

  /* Update for Memory: '<S1>/Memory12' */
  lpf0_DWork.Memory12_PreviousInput = rtb_Memory65;

  /* Update for Memory: '<S1>/Memory13' */
  lpf0_DWork.Memory13_PreviousInput = rtb_Memory12;

  /* Update for Memory: '<S1>/Memory14' */
  lpf0_DWork.Memory14_PreviousInput = rtb_Memory13;

  /* Update for Memory: '<S1>/Memory15' */
  lpf0_DWork.Memory15_PreviousInput = rtb_Memory14;

  /* Update for Memory: '<S1>/Memory40' */
  lpf0_DWork.Memory40_PreviousInput = rtb_Gain6;

  /* Update for Memory: '<S1>/Memory67' */
  lpf0_DWork.Memory67_PreviousInput = rtb_Memory40;

  /* Update for Memory: '<S1>/Memory68' */
  lpf0_DWork.Memory68_PreviousInput = rtb_Memory67;

  /* Update for Memory: '<S1>/Memory69' */
  lpf0_DWork.Memory69_PreviousInput = rtb_Memory68;

  /* Update for Memory: '<S1>/Memory36' */
  lpf0_DWork.Memory36_PreviousInput = rtb_Memory69;

  /* Update for Memory: '<S1>/Memory37' */
  lpf0_DWork.Memory37_PreviousInput = rtb_Memory36;

  /* Update for Memory: '<S1>/Memory38' */
  lpf0_DWork.Memory38_PreviousInput = rtb_Memory37;

  /* Update for Memory: '<S1>/Memory39' */
  lpf0_DWork.Memory39_PreviousInput = rtb_Memory38;

  /* Update for Memory: '<S1>/Memory46' */
  lpf0_DWork.Memory46_PreviousInput = rtb_Gain7;

  /* Update for Memory: '<S1>/Memory71' */
  lpf0_DWork.Memory71_PreviousInput = rtb_Memory46;

  /* Update for Memory: '<S1>/Memory72' */
  lpf0_DWork.Memory72_PreviousInput = rtb_Memory71;

  /* Update for Memory: '<S1>/Memory73' */
  lpf0_DWork.Memory73_PreviousInput = rtb_Memory72;

  /* Update for Memory: '<S1>/Memory42' */
  lpf0_DWork.Memory42_PreviousInput = rtb_Memory73;

  /* Update for Memory: '<S1>/Memory43' */
  lpf0_DWork.Memory43_PreviousInput = rtb_Memory42;

  /* Update for Memory: '<S1>/Memory44' */
  lpf0_DWork.Memory44_PreviousInput = rtb_Memory43;

  /* Update for Memory: '<S1>/Memory45' */
  lpf0_DWork.Memory45_PreviousInput = rtb_Memory44;

  /* Update for Memory: '<S1>/Memory52' */
  lpf0_DWork.Memory52_PreviousInput = rtb_Gain8;

  /* Update for Memory: '<S1>/Memory75' */
  lpf0_DWork.Memory75_PreviousInput = rtb_Memory52;

  /* Update for Memory: '<S1>/Memory76' */
  lpf0_DWork.Memory76_PreviousInput = rtb_Memory75;

  /* Update for Memory: '<S1>/Memory77' */
  lpf0_DWork.Memory77_PreviousInput = rtb_Memory76;

  /* Update for Memory: '<S1>/Memory48' */
  lpf0_DWork.Memory48_PreviousInput = rtb_Memory77;

  /* Update for Memory: '<S1>/Memory49' */
  lpf0_DWork.Memory49_PreviousInput = rtb_Memory48;

  /* Update for Memory: '<S1>/Memory50' */
  lpf0_DWork.Memory50_PreviousInput = rtb_Memory49;

  /* Update for Memory: '<S1>/Memory51' */
  lpf0_DWork.Memory51_PreviousInput = rtb_Memory50;

  /* Update for Memory: '<S1>/Memory22' */
  lpf0_DWork.Memory22_PreviousInput = rtb_Gain3;

  /* Update for Memory: '<S1>/Memory79' */
  lpf0_DWork.Memory79_PreviousInput = rtb_Memory22;

  /* Update for Memory: '<S1>/Memory80' */
  lpf0_DWork.Memory80_PreviousInput = rtb_Memory79;

  /* Update for Memory: '<S1>/Memory81' */
  lpf0_DWork.Memory81_PreviousInput = rtb_Memory80;

  /* Update for Memory: '<S1>/Memory18' */
  lpf0_DWork.Memory18_PreviousInput = rtb_Memory81;

  /* Update for Memory: '<S1>/Memory19' */
  lpf0_DWork.Memory19_PreviousInput = rtb_Memory18;

  /* Update for Memory: '<S1>/Memory20' */
  lpf0_DWork.Memory20_PreviousInput = rtb_Memory19;

  /* Update for Memory: '<S1>/Memory21' */
  lpf0_DWork.Memory21_PreviousInput = rtb_Memory20;

  /* Update for Memory: '<S1>/Memory28' */
  lpf0_DWork.Memory28_PreviousInput = rtb_Gain4;

  /* Update for Memory: '<S1>/Memory83' */
  lpf0_DWork.Memory83_PreviousInput = rtb_Memory28;

  /* Update for Memory: '<S1>/Memory84' */
  lpf0_DWork.Memory84_PreviousInput = rtb_Memory83;

  /* Update for Memory: '<S1>/Memory85' */
  lpf0_DWork.Memory85_PreviousInput = rtb_Memory84;

  /* Update for Memory: '<S1>/Memory24' */
  lpf0_DWork.Memory24_PreviousInput = rtb_Memory85;

  /* Update for Memory: '<S1>/Memory25' */
  lpf0_DWork.Memory25_PreviousInput = rtb_Memory24;

  /* Update for Memory: '<S1>/Memory26' */
  lpf0_DWork.Memory26_PreviousInput = rtb_Memory25;

  /* Update for Memory: '<S1>/Memory27' */
  lpf0_DWork.Memory27_PreviousInput = rtb_Memory26;

  /* Update for Memory: '<S1>/Memory34' */
  lpf0_DWork.Memory34_PreviousInput = rtb_Gain5;

  /* Update for Memory: '<S1>/Memory87' */
  lpf0_DWork.Memory87_PreviousInput = rtb_Memory34;

  /* Update for Memory: '<S1>/Memory88' */
  lpf0_DWork.Memory88_PreviousInput = rtb_Memory87;

  /* Update for Memory: '<S1>/Memory89' */
  lpf0_DWork.Memory89_PreviousInput = rtb_Memory88;

  /* Update for Memory: '<S1>/Memory30' */
  lpf0_DWork.Memory30_PreviousInput = rtb_Memory89;

  /* Update for Memory: '<S1>/Memory31' */
  lpf0_DWork.Memory31_PreviousInput = rtb_Memory30;

  /* Update for Memory: '<S1>/Memory32' */
  lpf0_DWork.Memory32_PreviousInput = rtb_Memory31;

  /* Update for Memory: '<S1>/Memory33' */
  lpf0_DWork.Memory33_PreviousInput = rtb_Memory32;
}

/* Model initialize function */
void lpf0_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(lpf0_M, (NULL));

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

  /* InitializeConditions for Memory: '<S1>/Memory54' */
  lpf0_DWork.Memory54_PreviousInput = lpf0_P.Memory54_X0;

  /* InitializeConditions for Memory: '<S1>/Memory55' */
  lpf0_DWork.Memory55_PreviousInput = lpf0_P.Memory55_X0;

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

  /* InitializeConditions for Memory: '<S1>/Memory58' */
  lpf0_DWork.Memory58_PreviousInput = lpf0_P.Memory58_X0;

  /* InitializeConditions for Memory: '<S1>/Memory17' */
  lpf0_DWork.Memory17_PreviousInput = lpf0_P.Memory17_X0;

  /* InitializeConditions for Memory: '<S1>/Memory16' */
  lpf0_DWork.Memory16_PreviousInput = lpf0_P.Memory16_X0;

  /* InitializeConditions for Memory: '<S1>/Memory63' */
  lpf0_DWork.Memory63_PreviousInput = lpf0_P.Memory63_X0;

  /* InitializeConditions for Memory: '<S1>/Memory64' */
  lpf0_DWork.Memory64_PreviousInput = lpf0_P.Memory64_X0;

  /* InitializeConditions for Memory: '<S1>/Memory65' */
  lpf0_DWork.Memory65_PreviousInput = lpf0_P.Memory65_X0;

  /* InitializeConditions for Memory: '<S1>/Memory12' */
  lpf0_DWork.Memory12_PreviousInput = lpf0_P.Memory12_X0;

  /* InitializeConditions for Memory: '<S1>/Memory13' */
  lpf0_DWork.Memory13_PreviousInput = lpf0_P.Memory13_X0;

  /* InitializeConditions for Memory: '<S1>/Memory14' */
  lpf0_DWork.Memory14_PreviousInput = lpf0_P.Memory14_X0;

  /* InitializeConditions for Memory: '<S1>/Memory15' */
  lpf0_DWork.Memory15_PreviousInput = lpf0_P.Memory15_X0;

  /* InitializeConditions for Memory: '<S1>/Memory40' */
  lpf0_DWork.Memory40_PreviousInput = lpf0_P.Memory40_X0;

  /* InitializeConditions for Memory: '<S1>/Memory67' */
  lpf0_DWork.Memory67_PreviousInput = lpf0_P.Memory67_X0;

  /* InitializeConditions for Memory: '<S1>/Memory68' */
  lpf0_DWork.Memory68_PreviousInput = lpf0_P.Memory68_X0;

  /* InitializeConditions for Memory: '<S1>/Memory69' */
  lpf0_DWork.Memory69_PreviousInput = lpf0_P.Memory69_X0;

  /* InitializeConditions for Memory: '<S1>/Memory36' */
  lpf0_DWork.Memory36_PreviousInput = lpf0_P.Memory36_X0;

  /* InitializeConditions for Memory: '<S1>/Memory37' */
  lpf0_DWork.Memory37_PreviousInput = lpf0_P.Memory37_X0;

  /* InitializeConditions for Memory: '<S1>/Memory38' */
  lpf0_DWork.Memory38_PreviousInput = lpf0_P.Memory38_X0;

  /* InitializeConditions for Memory: '<S1>/Memory39' */
  lpf0_DWork.Memory39_PreviousInput = lpf0_P.Memory39_X0;

  /* InitializeConditions for Memory: '<S1>/Memory46' */
  lpf0_DWork.Memory46_PreviousInput = lpf0_P.Memory46_X0;

  /* InitializeConditions for Memory: '<S1>/Memory71' */
  lpf0_DWork.Memory71_PreviousInput = lpf0_P.Memory71_X0;

  /* InitializeConditions for Memory: '<S1>/Memory72' */
  lpf0_DWork.Memory72_PreviousInput = lpf0_P.Memory72_X0;

  /* InitializeConditions for Memory: '<S1>/Memory73' */
  lpf0_DWork.Memory73_PreviousInput = lpf0_P.Memory73_X0;

  /* InitializeConditions for Memory: '<S1>/Memory42' */
  lpf0_DWork.Memory42_PreviousInput = lpf0_P.Memory42_X0;

  /* InitializeConditions for Memory: '<S1>/Memory43' */
  lpf0_DWork.Memory43_PreviousInput = lpf0_P.Memory43_X0;

  /* InitializeConditions for Memory: '<S1>/Memory44' */
  lpf0_DWork.Memory44_PreviousInput = lpf0_P.Memory44_X0;

  /* InitializeConditions for Memory: '<S1>/Memory45' */
  lpf0_DWork.Memory45_PreviousInput = lpf0_P.Memory45_X0;

  /* InitializeConditions for Memory: '<S1>/Memory52' */
  lpf0_DWork.Memory52_PreviousInput = lpf0_P.Memory52_X0;

  /* InitializeConditions for Memory: '<S1>/Memory75' */
  lpf0_DWork.Memory75_PreviousInput = lpf0_P.Memory75_X0;

  /* InitializeConditions for Memory: '<S1>/Memory76' */
  lpf0_DWork.Memory76_PreviousInput = lpf0_P.Memory76_X0;

  /* InitializeConditions for Memory: '<S1>/Memory77' */
  lpf0_DWork.Memory77_PreviousInput = lpf0_P.Memory77_X0;

  /* InitializeConditions for Memory: '<S1>/Memory48' */
  lpf0_DWork.Memory48_PreviousInput = lpf0_P.Memory48_X0;

  /* InitializeConditions for Memory: '<S1>/Memory49' */
  lpf0_DWork.Memory49_PreviousInput = lpf0_P.Memory49_X0;

  /* InitializeConditions for Memory: '<S1>/Memory50' */
  lpf0_DWork.Memory50_PreviousInput = lpf0_P.Memory50_X0;

  /* InitializeConditions for Memory: '<S1>/Memory51' */
  lpf0_DWork.Memory51_PreviousInput = lpf0_P.Memory51_X0;

  /* InitializeConditions for Memory: '<S1>/Memory22' */
  lpf0_DWork.Memory22_PreviousInput = lpf0_P.Memory22_X0;

  /* InitializeConditions for Memory: '<S1>/Memory79' */
  lpf0_DWork.Memory79_PreviousInput = lpf0_P.Memory79_X0;

  /* InitializeConditions for Memory: '<S1>/Memory80' */
  lpf0_DWork.Memory80_PreviousInput = lpf0_P.Memory80_X0;

  /* InitializeConditions for Memory: '<S1>/Memory81' */
  lpf0_DWork.Memory81_PreviousInput = lpf0_P.Memory81_X0;

  /* InitializeConditions for Memory: '<S1>/Memory18' */
  lpf0_DWork.Memory18_PreviousInput = lpf0_P.Memory18_X0;

  /* InitializeConditions for Memory: '<S1>/Memory19' */
  lpf0_DWork.Memory19_PreviousInput = lpf0_P.Memory19_X0;

  /* InitializeConditions for Memory: '<S1>/Memory20' */
  lpf0_DWork.Memory20_PreviousInput = lpf0_P.Memory20_X0;

  /* InitializeConditions for Memory: '<S1>/Memory21' */
  lpf0_DWork.Memory21_PreviousInput = lpf0_P.Memory21_X0;

  /* InitializeConditions for Memory: '<S1>/Memory28' */
  lpf0_DWork.Memory28_PreviousInput = lpf0_P.Memory28_X0;

  /* InitializeConditions for Memory: '<S1>/Memory83' */
  lpf0_DWork.Memory83_PreviousInput = lpf0_P.Memory83_X0;

  /* InitializeConditions for Memory: '<S1>/Memory84' */
  lpf0_DWork.Memory84_PreviousInput = lpf0_P.Memory84_X0;

  /* InitializeConditions for Memory: '<S1>/Memory85' */
  lpf0_DWork.Memory85_PreviousInput = lpf0_P.Memory85_X0;

  /* InitializeConditions for Memory: '<S1>/Memory24' */
  lpf0_DWork.Memory24_PreviousInput = lpf0_P.Memory24_X0;

  /* InitializeConditions for Memory: '<S1>/Memory25' */
  lpf0_DWork.Memory25_PreviousInput = lpf0_P.Memory25_X0;

  /* InitializeConditions for Memory: '<S1>/Memory26' */
  lpf0_DWork.Memory26_PreviousInput = lpf0_P.Memory26_X0;

  /* InitializeConditions for Memory: '<S1>/Memory27' */
  lpf0_DWork.Memory27_PreviousInput = lpf0_P.Memory27_X0;

  /* InitializeConditions for Memory: '<S1>/Memory34' */
  lpf0_DWork.Memory34_PreviousInput = lpf0_P.Memory34_X0;

  /* InitializeConditions for Memory: '<S1>/Memory87' */
  lpf0_DWork.Memory87_PreviousInput = lpf0_P.Memory87_X0;

  /* InitializeConditions for Memory: '<S1>/Memory88' */
  lpf0_DWork.Memory88_PreviousInput = lpf0_P.Memory88_X0;

  /* InitializeConditions for Memory: '<S1>/Memory89' */
  lpf0_DWork.Memory89_PreviousInput = lpf0_P.Memory89_X0;

  /* InitializeConditions for Memory: '<S1>/Memory30' */
  lpf0_DWork.Memory30_PreviousInput = lpf0_P.Memory30_X0;

  /* InitializeConditions for Memory: '<S1>/Memory31' */
  lpf0_DWork.Memory31_PreviousInput = lpf0_P.Memory31_X0;

  /* InitializeConditions for Memory: '<S1>/Memory32' */
  lpf0_DWork.Memory32_PreviousInput = lpf0_P.Memory32_X0;

  /* InitializeConditions for Memory: '<S1>/Memory33' */
  lpf0_DWork.Memory33_PreviousInput = lpf0_P.Memory33_X0;
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
