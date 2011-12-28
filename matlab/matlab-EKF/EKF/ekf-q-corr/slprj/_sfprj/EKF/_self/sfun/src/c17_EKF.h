#ifndef __c17_EKF_h__
#define __c17_EKF_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c17_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c17_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c17_doneDoubleBufferReInit;
  boolean_T c17_isStable;
  uint8_T c17_is_active_c17_EKF;
  ChartInfoStruct chartInfo;
} SFc17_EKFInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_EKF_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_EKF_get_check_sum(mxArray *plhs[]);
extern void c17_EKF_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
