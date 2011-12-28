#ifndef __c19_ekffede_h__
#define __c19_ekffede_h__

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
} c19_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c19_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c19_doneDoubleBufferReInit;
  boolean_T c19_isStable;
  uint8_T c19_is_active_c19_ekffede;
  ChartInfoStruct chartInfo;
} SFc19_ekffedeInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c19_ekffede_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c19_ekffede_get_check_sum(mxArray *plhs[]);
extern void c19_ekffede_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
