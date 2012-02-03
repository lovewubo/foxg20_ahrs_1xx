/*
 * File: lpf0.h
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

#ifndef RTW_HEADER_lpf0_h_
#define RTW_HEADER_lpf0_h_
#ifndef lpf0_COMMON_INCLUDES_
# define lpf0_COMMON_INCLUDES_
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* lpf0_COMMON_INCLUDES_ */

#include "lpf0_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  real_T Memory1_PreviousInput;        /* '<S1>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S1>/Memory3' */
  real_T Memory4_PreviousInput;        /* '<S1>/Memory4' */
  real_T Memory5_PreviousInput;        /* '<S1>/Memory5' */
  real_T Memory54_PreviousInput;       /* '<S1>/Memory54' */
  real_T Memory55_PreviousInput;       /* '<S1>/Memory55' */
  real_T Memory6_PreviousInput;        /* '<S1>/Memory6' */
  real_T Memory7_PreviousInput;        /* '<S1>/Memory7' */
  real_T Memory8_PreviousInput;        /* '<S1>/Memory8' */
  real_T Memory9_PreviousInput;        /* '<S1>/Memory9' */
  real_T Memory10_PreviousInput;       /* '<S1>/Memory10' */
  real_T Memory11_PreviousInput;       /* '<S1>/Memory11' */
  real_T Memory58_PreviousInput;       /* '<S1>/Memory58' */
  real_T Memory17_PreviousInput;       /* '<S1>/Memory17' */
  real_T Memory16_PreviousInput;       /* '<S1>/Memory16' */
  real_T Memory63_PreviousInput;       /* '<S1>/Memory63' */
  real_T Memory64_PreviousInput;       /* '<S1>/Memory64' */
  real_T Memory65_PreviousInput;       /* '<S1>/Memory65' */
  real_T Memory12_PreviousInput;       /* '<S1>/Memory12' */
  real_T Memory13_PreviousInput;       /* '<S1>/Memory13' */
  real_T Memory14_PreviousInput;       /* '<S1>/Memory14' */
  real_T Memory15_PreviousInput;       /* '<S1>/Memory15' */
  real_T Memory40_PreviousInput;       /* '<S1>/Memory40' */
  real_T Memory67_PreviousInput;       /* '<S1>/Memory67' */
  real_T Memory68_PreviousInput;       /* '<S1>/Memory68' */
  real_T Memory69_PreviousInput;       /* '<S1>/Memory69' */
  real_T Memory36_PreviousInput;       /* '<S1>/Memory36' */
  real_T Memory37_PreviousInput;       /* '<S1>/Memory37' */
  real_T Memory38_PreviousInput;       /* '<S1>/Memory38' */
  real_T Memory39_PreviousInput;       /* '<S1>/Memory39' */
  real_T Memory46_PreviousInput;       /* '<S1>/Memory46' */
  real_T Memory71_PreviousInput;       /* '<S1>/Memory71' */
  real_T Memory72_PreviousInput;       /* '<S1>/Memory72' */
  real_T Memory73_PreviousInput;       /* '<S1>/Memory73' */
  real_T Memory42_PreviousInput;       /* '<S1>/Memory42' */
  real_T Memory43_PreviousInput;       /* '<S1>/Memory43' */
  real_T Memory44_PreviousInput;       /* '<S1>/Memory44' */
  real_T Memory45_PreviousInput;       /* '<S1>/Memory45' */
  real_T Memory52_PreviousInput;       /* '<S1>/Memory52' */
  real_T Memory75_PreviousInput;       /* '<S1>/Memory75' */
  real_T Memory76_PreviousInput;       /* '<S1>/Memory76' */
  real_T Memory77_PreviousInput;       /* '<S1>/Memory77' */
  real_T Memory48_PreviousInput;       /* '<S1>/Memory48' */
  real_T Memory49_PreviousInput;       /* '<S1>/Memory49' */
  real_T Memory50_PreviousInput;       /* '<S1>/Memory50' */
  real_T Memory51_PreviousInput;       /* '<S1>/Memory51' */
  real_T Memory22_PreviousInput;       /* '<S1>/Memory22' */
  real_T Memory79_PreviousInput;       /* '<S1>/Memory79' */
  real_T Memory80_PreviousInput;       /* '<S1>/Memory80' */
  real_T Memory81_PreviousInput;       /* '<S1>/Memory81' */
  real_T Memory18_PreviousInput;       /* '<S1>/Memory18' */
  real_T Memory19_PreviousInput;       /* '<S1>/Memory19' */
  real_T Memory20_PreviousInput;       /* '<S1>/Memory20' */
  real_T Memory21_PreviousInput;       /* '<S1>/Memory21' */
  real_T Memory28_PreviousInput;       /* '<S1>/Memory28' */
  real_T Memory83_PreviousInput;       /* '<S1>/Memory83' */
  real_T Memory84_PreviousInput;       /* '<S1>/Memory84' */
  real_T Memory85_PreviousInput;       /* '<S1>/Memory85' */
  real_T Memory24_PreviousInput;       /* '<S1>/Memory24' */
  real_T Memory25_PreviousInput;       /* '<S1>/Memory25' */
  real_T Memory26_PreviousInput;       /* '<S1>/Memory26' */
  real_T Memory27_PreviousInput;       /* '<S1>/Memory27' */
  real_T Memory34_PreviousInput;       /* '<S1>/Memory34' */
  real_T Memory87_PreviousInput;       /* '<S1>/Memory87' */
  real_T Memory88_PreviousInput;       /* '<S1>/Memory88' */
  real_T Memory89_PreviousInput;       /* '<S1>/Memory89' */
  real_T Memory30_PreviousInput;       /* '<S1>/Memory30' */
  real_T Memory31_PreviousInput;       /* '<S1>/Memory31' */
  real_T Memory32_PreviousInput;       /* '<S1>/Memory32' */
  real_T Memory33_PreviousInput;       /* '<S1>/Memory33' */
} D_Work_lpf0;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T acc_x;                        /* '<Root>/acc_x' */
  real_T acc_y;                        /* '<Root>/acc_y' */
  real_T acc_z;                        /* '<Root>/acc_z' */
  real_T gyro_x;                       /* '<Root>/gyro_x' */
  real_T gyro_y;                       /* '<Root>/gyro_y' */
  real_T gyro_z;                       /* '<Root>/gyro_z' */
  real_T mag_x;                        /* '<Root>/mag_x' */
  real_T mag_y;                        /* '<Root>/mag_y' */
  real_T mag_z;                        /* '<Root>/mag_z' */
  real_T acc_x1;                       /* '<Root>/acc_x1' */
  real_T acc_x2;                       /* '<Root>/acc_x2' */
  real_T acc_y1;                       /* '<Root>/acc_y1' */
  real_T acc_y2;                       /* '<Root>/acc_y2' */
  real_T acc_z1;                       /* '<Root>/acc_z1' */
  real_T acc_z2;                       /* '<Root>/acc_z2' */
  real_T gyro_x1;                      /* '<Root>/gyro_x1' */
  real_T gyro_x2;                      /* '<Root>/gyro_x2' */
  real_T gyro_y1;                      /* '<Root>/gyro_y1' */
  real_T gyro_y2;                      /* '<Root>/gyro_y2' */
  real_T gyro_z1;                      /* '<Root>/gyro_z1' */
  real_T gyro_z2;                      /* '<Root>/gyro_z2' */
  real_T mag_x1;                       /* '<Root>/mag_x1' */
  real_T mag_x2;                       /* '<Root>/mag_x2' */
  real_T mag_y1;                       /* '<Root>/mag_y1' */
  real_T mag_y2;                       /* '<Root>/mag_y2' */
  real_T mag_z1;                       /* '<Root>/mag_z1' */
  real_T mag_z2;                       /* '<Root>/mag_z2' */
} ExternalInputs_lpf0;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T acc_x_f;                      /* '<Root>/acc_x_f' */
  real_T acc_y_f;                      /* '<Root>/acc_y_f' */
  real_T acc_z_f;                      /* '<Root>/acc_z_f' */
  real_T gyro_x_f;                     /* '<Root>/gyro_x_f' */
  real_T gyro_y_f;                     /* '<Root>/gyro_y_f' */
  real_T gyro_z_f;                     /* '<Root>/gyro_z_f' */
  real_T mag_x_f;                      /* '<Root>/mag_x_f' */
  real_T mag_y_f;                      /* '<Root>/mag_y_f' */
  real_T mag_z_f;                      /* '<Root>/mag_z_f' */
} ExternalOutputs_lpf0;

/* Parameters (auto storage) */
struct Parameters_lpf0_ {
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory3'
                                        */
  real_T Memory4_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory4'
                                        */
  real_T Memory5_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory5'
                                        */
  real_T Memory54_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory54'
                                        */
  real_T Memory55_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory55'
                                        */
  real_T Memory6_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory6'
                                        */
  real_T Memory7_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory7'
                                        */
  real_T Memory8_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory8'
                                        */
  real_T Memory9_X0;                   /* Expression: 0
                                        * Referenced by: '<S1>/Memory9'
                                        */
  real_T Memory10_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory10'
                                        */
  real_T Memory11_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory11'
                                        */
  real_T Memory58_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory58'
                                        */
  real_T Memory17_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory17'
                                        */
  real_T Memory16_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory16'
                                        */
  real_T Memory63_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory63'
                                        */
  real_T Memory64_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory64'
                                        */
  real_T Memory65_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory65'
                                        */
  real_T Memory12_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory12'
                                        */
  real_T Memory13_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory13'
                                        */
  real_T Memory14_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory14'
                                        */
  real_T Memory15_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory15'
                                        */
  real_T Memory40_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory40'
                                        */
  real_T Memory67_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory67'
                                        */
  real_T Memory68_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory68'
                                        */
  real_T Memory69_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory69'
                                        */
  real_T Memory36_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory36'
                                        */
  real_T Memory37_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory37'
                                        */
  real_T Memory38_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory38'
                                        */
  real_T Memory39_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory39'
                                        */
  real_T Memory46_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory46'
                                        */
  real_T Memory71_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory71'
                                        */
  real_T Memory72_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory72'
                                        */
  real_T Memory73_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory73'
                                        */
  real_T Memory42_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory42'
                                        */
  real_T Memory43_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory43'
                                        */
  real_T Memory44_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory44'
                                        */
  real_T Memory45_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory45'
                                        */
  real_T Memory52_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory52'
                                        */
  real_T Memory75_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory75'
                                        */
  real_T Memory76_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory76'
                                        */
  real_T Memory77_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory77'
                                        */
  real_T Memory48_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory48'
                                        */
  real_T Memory49_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory49'
                                        */
  real_T Memory50_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory50'
                                        */
  real_T Memory51_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory51'
                                        */
  real_T Memory22_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory22'
                                        */
  real_T Memory79_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory79'
                                        */
  real_T Memory80_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory80'
                                        */
  real_T Memory81_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory81'
                                        */
  real_T Memory18_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory18'
                                        */
  real_T Memory19_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory19'
                                        */
  real_T Memory20_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory20'
                                        */
  real_T Memory21_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory21'
                                        */
  real_T Memory28_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory28'
                                        */
  real_T Memory83_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory83'
                                        */
  real_T Memory84_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory84'
                                        */
  real_T Memory85_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory85'
                                        */
  real_T Memory24_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory24'
                                        */
  real_T Memory25_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory25'
                                        */
  real_T Memory26_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory26'
                                        */
  real_T Memory27_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory27'
                                        */
  real_T Memory34_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory34'
                                        */
  real_T Memory87_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory87'
                                        */
  real_T Memory88_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory88'
                                        */
  real_T Memory89_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory89'
                                        */
  real_T Memory30_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory30'
                                        */
  real_T Memory31_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory31'
                                        */
  real_T Memory32_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory32'
                                        */
  real_T Memory33_X0;                  /* Expression: 0
                                        * Referenced by: '<S1>/Memory33'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S1>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real32_T Gain6_Gain;                 /* Computed Parameter: Gain6_Gain
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real32_T Gain7_Gain;                 /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S1>/Gain7'
                                        */
  real32_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<S1>/Gain8'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real32_T Gain4_Gain;                 /* Computed Parameter: Gain4_Gain
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real32_T Gain5_Gain;                 /* Computed Parameter: Gain5_Gain
                                        * Referenced by: '<S1>/Gain5'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_lpf0 {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern Parameters_lpf0 lpf0_P;

/* Block states (auto storage) */
extern D_Work_lpf0 lpf0_DWork;

/* External inputs (root inport signals with auto storage) */
extern ExternalInputs_lpf0 lpf0_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_lpf0 lpf0_Y;

/* Model entry point functions */
extern void lpf0_initialize(void);
extern void lpf0_step(void);
extern void lpf0_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_lpf0 *const lpf0_M;

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
 * hilite_system('lpf/lpf')    - opens subsystem lpf/lpf
 * hilite_system('lpf/lpf/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : lpf
 * '<S1>'   : lpf/lpf
 */
#endif                                 /* RTW_HEADER_lpf0_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
