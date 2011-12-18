/*
 * File: lpf0_data.c
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

/* Block parameters (auto storage) */
Parameters_lpf0 lpf0_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory4'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory5'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S11>/Stage1'
   */
  { -0.0902313869601802, 0.140496340683596, 0.283568575451759, 0.355000308251925,
    0.283568575451759, 0.140496340683596, -0.0902313869601802 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S11>/Stage2'
   */
  { 0.04671512655697, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    -0.130765351430977, 0.0, 0.0, 0.0625138669794206, 0.0, 0.0,
    0.513967534602774, 0.0, 0.0, 0.513967534602774, 0.0, 0.0, 0.0625138669794206,
    0.0, 0.0, -0.130765351430977, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.04671512655697 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory11'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S12>/Stage1'
   */
  { -0.0902313869601802, 0.140496340683596, 0.283568575451759, 0.355000308251925,
    0.283568575451759, 0.140496340683596, -0.0902313869601802 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S12>/Stage2'
   */
  { 0.04671512655697, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    -0.130765351430977, 0.0, 0.0, 0.0625138669794206, 0.0, 0.0,
    0.513967534602774, 0.0, 0.0, 0.513967534602774, 0.0, 0.0, 0.0625138669794206,
    0.0, 0.0, -0.130765351430977, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.04671512655697 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory14'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory15'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory16'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory17'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory12'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory13'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S13>/Stage1'
   */
  { -0.0902313869601802, 0.140496340683596, 0.283568575451759, 0.355000308251925,
    0.283568575451759, 0.140496340683596, -0.0902313869601802 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S13>/Stage2'
   */
  { 0.04671512655697, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    -0.130765351430977, 0.0, 0.0, 0.0625138669794206, 0.0, 0.0,
    0.513967534602774, 0.0, 0.0, 0.513967534602774, 0.0, 0.0, 0.0625138669794206,
    0.0, 0.0, -0.130765351430977, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.04671512655697 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory36'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory37'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory38'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory39'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory40'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory41'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S14>/Stage1'
   */
  { -0.0902313869601802, 0.140496340683596, 0.283568575451759, 0.355000308251925,
    0.283568575451759, 0.140496340683596, -0.0902313869601802 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S14>/Stage2'
   */
  { 0.04671512655697, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    -0.130765351430977, 0.0, 0.0, 0.0625138669794206, 0.0, 0.0,
    0.513967534602774, 0.0, 0.0, 0.513967534602774, 0.0, 0.0, 0.0625138669794206,
    0.0, 0.0, -0.130765351430977, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.04671512655697 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory42'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory43'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory44'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory45'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory46'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory47'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S15>/Stage1'
   */
  { -0.0902313869601802, 0.140496340683596, 0.283568575451759, 0.355000308251925,
    0.283568575451759, 0.140496340683596, -0.0902313869601802 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S15>/Stage2'
   */
  { 0.04671512655697, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    -0.130765351430977, 0.0, 0.0, 0.0625138669794206, 0.0, 0.0,
    0.513967534602774, 0.0, 0.0, 0.513967534602774, 0.0, 0.0, 0.0625138669794206,
    0.0, 0.0, -0.130765351430977, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.04671512655697 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory48'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory49'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory50'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory51'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory52'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory53'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S16>/Stage1'
   */
  { -0.0902313869601802, 0.140496340683596, 0.283568575451759, 0.355000308251925,
    0.283568575451759, 0.140496340683596, -0.0902313869601802 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S16>/Stage2'
   */
  { 0.04671512655697, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    -0.130765351430977, 0.0, 0.0, 0.0625138669794206, 0.0, 0.0,
    0.513967534602774, 0.0, 0.0, 0.513967534602774, 0.0, 0.0, 0.0625138669794206,
    0.0, 0.0, -0.130765351430977, 0.0, 0.0, 0.0250382068180189, 0.0, 0.0,
    0.0712187728856005, 0.0, 0.0, -0.0928982592185713, 0.0, 0.0,
    0.04671512655697 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory18'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory19'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory20'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory21'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory22'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory23'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S17>/Stage1'
   */
  { -0.0964925902786576, 0.117674366507652, 0.465634978506778, 0.465634978506778,
    0.117674366507652, -0.0964925902786576 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S17>/Stage2'
   */
  { -0.0299134927996747, 0.0, 0.0352406961020747, 0.0, -0.0249130310815096, 0.0,
    -0.0200047558547463, 0.0, 0.0982448808700209, 0.0, -0.190394200215871, 0.0,
    0.265225479951801, 0.0, 0.705966189127093, 0.0, 0.265225479951801, 0.0,
    -0.190394200215871, 0.0, 0.0982448808700209, 0.0, -0.0200047558547463, 0.0,
    -0.0249130310815096, 0.0, 0.0352406961020747, 0.0, -0.0299134927996747 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory24'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory25'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory26'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory27'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory28'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory29'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S18>/Stage1'
   */
  { -0.0964925902786576, 0.117674366507652, 0.465634978506778, 0.465634978506778,
    0.117674366507652, -0.0964925902786576 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S18>/Stage2'
   */
  { -0.0299134927996747, 0.0, 0.0352406961020747, 0.0, -0.0249130310815096, 0.0,
    -0.0200047558547463, 0.0, 0.0982448808700209, 0.0, -0.190394200215871, 0.0,
    0.265225479951801, 0.0, 0.705966189127093, 0.0, 0.265225479951801, 0.0,
    -0.190394200215871, 0.0, 0.0982448808700209, 0.0, -0.0200047558547463, 0.0,
    -0.0249130310815096, 0.0, 0.0352406961020747, 0.0, -0.0299134927996747 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory30'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory31'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory32'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory33'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory34'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Memory35'
                                        */

  /*  Expression: NumCoeffs
   * Referenced by: '<S19>/Stage1'
   */
  { -0.0964925902786576, 0.117674366507652, 0.465634978506778, 0.465634978506778,
    0.117674366507652, -0.0964925902786576 },

  /*  Expression: NumCoeffs
   * Referenced by: '<S19>/Stage2'
   */
  { -0.0299134927996747, 0.0, 0.0352406961020747, 0.0, -0.0249130310815096, 0.0,
    -0.0200047558547463, 0.0, 0.0982448808700209, 0.0, -0.190394200215871, 0.0,
    0.265225479951801, 0.0, 0.705966189127093, 0.0, 0.265225479951801, 0.0,
    -0.190394200215871, 0.0, 0.0982448808700209, 0.0, -0.0200047558547463, 0.0,
    -0.0249130310815096, 0.0, 0.0352406961020747, 0.0, -0.0299134927996747 },
  0.142857F,                           /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  0.142857F,                           /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
  0.142857F,                           /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
  0.142857F,                           /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S1>/Gain6'
                                        */
  0.142857F,                           /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S1>/Gain7'
                                        */
  0.142857F,                           /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<S1>/Gain8'
                                        */
  0.142857F,                           /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S1>/Gain3'
                                        */
  0.142857F,                           /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S1>/Gain4'
                                        */
  0.142857F                            /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S1>/Gain5'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
