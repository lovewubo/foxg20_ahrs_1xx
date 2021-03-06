#ifndef __c20_ekffedepre_h__
#define __c20_ekffedepre_h__

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
} c20_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c20_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c20_doneDoubleBufferReInit;
  boolean_T c20_isStable;
  uint8_T c20_is_active_c20_ekffedepre;
  ChartInfoStruct chartInfo;
} SFc20_ekffedepreInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_ekffedepre_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c20_ekffedepre_get_check_sum(mxArray *plhs[]);
extern void c20_ekffedepre_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
