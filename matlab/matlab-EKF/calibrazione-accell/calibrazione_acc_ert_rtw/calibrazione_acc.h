/*
 * File: calibrazione_acc.h
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

#ifndef RTW_HEADER_calibrazione_acc_h_
#define RTW_HEADER_calibrazione_acc_h_
#ifndef calibrazione_acc_COMMON_INCLUDES_
# define calibrazione_acc_COMMON_INCLUDES_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* calibrazione_acc_COMMON_INCLUDES_ */

#include "calibrazione_acc_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T position[3];                  /* '<Root>/position' */
  real_T w1[4];                        /* '<Root>/w1' */
  real_T w2[4];                        /* '<Root>/w2' */
  real_T w3[4];                        /* '<Root>/w3' */
  real_T w4[4];                        /* '<Root>/w4' */
  real_T w5[4];                        /* '<Root>/w5' */
  real_T w6[4];                        /* '<Root>/w6' */
} ExternalInputs_calibrazione_acc;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T G[9];                         /* '<Root>/G' */
  real_T B[3];                         /* '<Root>/B' */
} ExternalOutputs_calibrazione_ac;

/* Parameters (auto storage) */
struct Parameters_calibrazione_acc_ {
  real_T GravityatEquator_Value;       /* Expression: 9.7803267714
                                        * Referenced by: '<S2>/Gravity at Equator'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S2>/One'
                                        */
  real_T Gravityformulaconst_Value;    /* Expression: 0.00193185138639
                                        * Referenced by: '<S2>/Gravity formula const'
                                        */
  real_T FirstEccentricity_Value;      /* Expression: 0.0818191908426
                                        * Referenced by: '<S2>/First Eccentricity'
                                        */
  real_T u_Value;                      /* Expression: 1/2
                                        * Referenced by: '<S2>/1//2'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_calibrazione_acc {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_calibrazione_acc calibrazione_acc_P;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_calibrazione_acc calibrazione_acc_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_calibrazione_ac calibrazione_acc_Y;

/* Model entry point functions */
extern void calibrazione_acc_initialize(void);
extern void calibrazione_acc_step(void);
extern void calibrazione_acc_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_calibrazione_acc *const calibrazione_acc_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('calibrazione/calibrazione_acc')    - opens subsystem calibrazione/calibrazione_acc
 * hilite_system('calibrazione/calibrazione_acc/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : calibrazione
 * '<S1>'   : calibrazione/calibrazione_acc
 * '<S2>'   : calibrazione/calibrazione_acc/WGS-84
 * '<S3>'   : calibrazione/calibrazione_acc/acc_calibration
 */
#endif                                 /* RTW_HEADER_calibrazione_acc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
