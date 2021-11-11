/*
 * File: nifunction_initialize.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 07-Nov-2021 14:13:36
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "nifunction.h"
#include "nifunction_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void nifunction_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

/*
 * File trailer for nifunction_initialize.c
 *
 * [EOF]
 */
