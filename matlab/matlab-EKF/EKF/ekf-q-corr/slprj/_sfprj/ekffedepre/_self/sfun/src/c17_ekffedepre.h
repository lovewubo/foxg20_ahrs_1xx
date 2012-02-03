#ifndef __c17_ekffedepre_h__
#define __c17_ekffedepre_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c17_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c17_doneDoubleBufferReInit;
  boolean_T c17_isStable;
  uint8_T c17_is_active_c17_ekffedepre;
  ChartInfoStruct chartInfo;
} SFc17_ekffedepreInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_ekffedepre_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_ekffedepre_get_check_sum(mxArray *plhs[]);
extern void c17_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
