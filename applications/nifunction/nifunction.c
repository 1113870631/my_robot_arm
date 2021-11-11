/*
 * File: nifunction.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 07-Nov-2021 14:13:36
 */

/* Include Files */
#include <math.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "nifunction.h"

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * 逆解   位置求角度
 * Arguments    : double inputArg1
 *                double inputArg2
 *                double inputArg3
 *                double inputArg4
 *                double inputArg5
 *                double inputArg6
 *                double inputArg7
 *                double inputArg8
 *                double inputArg9
 *                double inputArg10
 *                double inputArg11
 *                double inputArg12
 *                double outputArg1[48]
 * Return Type  : void
 */
void nifunction(double inputArg1, double inputArg2, double inputArg3, double
                inputArg4, double inputArg5, double inputArg6, double inputArg7,
                double inputArg8, double inputArg9, double inputArg10, double
                inputArg11, double inputArg12, double outputArg1[48])
{
  double m2_1;
  double n2_1;
  double t11;
  double t12;
  double n3_1_tmp;
  double b_n3_1_tmp;
  double n3_1;
  double n3_2_tmp;
  double b_n3_2_tmp;
  double n3_2;
  double n2_2;
  double r_tmp;
  double b_r_tmp;
  double c_r_tmp;
  double d_r_tmp;
  double t45;
  double t42;
  double t43;
  double t41;
  double m2_2;
  double t58;
  double t57;
  double m2_3;
  double n2_3;
  double m2_4_tmp;
  double b_m2_4_tmp;
  double m2_4;
  double n2_4;
  double t21;
  double t22;
  double t23;
  double t24;
  double m5_2;
  double m5_4;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  (void)inputArg9;
  (void)inputArg10;

  /*     ti   di     ai-1     alphai-1  */
  /* t1(3,4) */
  m2_1 = sqrt(-inputArg4 * -inputArg4 + -inputArg8 * -inputArg8);
  n2_1 = -rt_atan2d_snf(-inputArg8, inputArg4);
  t11 = n2_1 + rt_atan2d_snf(-0.0, m2_1);
  t12 = n2_1 + rt_atan2d_snf(-0.0, -m2_1);

  /* t3 */
  n3_1_tmp = cos(t11);
  b_n3_1_tmp = sin(t11);
  n3_1 = (0.18 - inputArg4 * n3_1_tmp) - inputArg8 * b_n3_1_tmp;
  n3_2_tmp = cos(t12);
  b_n3_2_tmp = sin(t12);
  n3_2 = (0.18 - inputArg4 * n3_2_tmp) - inputArg8 * b_n3_2_tmp;
  m2_1 = -inputArg12 * -inputArg12;
  n2_2 = (((m2_1 + n3_1 * n3_1) - 0.36) - 0.016900000000000002) -
    0.39690000000000003;
  n2_1 = n2_2 / -1.0;
  r_tmp = rt_atan2d_snf(n2_1, sqrt(0.59587200000000007 - n2_2 * n2_2));
  b_r_tmp = rt_atan2d_snf(n2_1, -sqrt(0.59587200000000007 - n2_2 * n2_2));
  n2_2 = (((m2_1 + n3_2 * n3_2) - 0.36) - 0.016900000000000002) -
    0.39690000000000003;
  n2_1 = n2_2 / -1.0;
  c_r_tmp = rt_atan2d_snf(n2_1, sqrt(0.59587200000000007 - n2_2 * n2_2));
  d_r_tmp = rt_atan2d_snf(n2_1, -sqrt(0.59587200000000007 - n2_2 * n2_2));

  /* t2 */
  t45 = sin(0.20349304525756276 + r_tmp);
  t42 = cos(0.20349304525756276 + r_tmp);
  m2_1 = (0.6 + 0.13 * t42) + -0.63 * t45;
  n2_1 = 0.13 * t45 - -0.63 * t42;
  t43 = sin(0.20349304525756276 + b_r_tmp);
  t41 = cos(0.20349304525756276 + b_r_tmp);
  m2_2 = (0.6 + 0.13 * t41) + -0.63 * t43;
  n2_2 = 0.13 * t43 - -0.63 * t41;
  t58 = sin(0.20349304525756276 + c_r_tmp);
  t57 = cos(0.20349304525756276 + c_r_tmp);
  m2_3 = (0.6 + 0.13 * t57) + -0.63 * t58;
  n2_3 = 0.13 * t58 - -0.63 * t57;
  m2_4_tmp = sin(0.20349304525756276 + d_r_tmp);
  b_m2_4_tmp = cos(0.20349304525756276 + d_r_tmp);
  m2_4 = (0.6 + 0.13 * b_m2_4_tmp) + -0.63 * m2_4_tmp;
  n2_4 = 0.13 * m2_4_tmp - -0.63 * b_m2_4_tmp;
  t21 = rt_atan2d_snf(-inputArg12 * m2_1 + n2_1 * n3_1, -inputArg12 * n2_1 -
                      m2_1 * n3_1);
  t22 = rt_atan2d_snf(-inputArg12 * m2_2 + n2_2 * n3_1, -inputArg12 * n2_2 -
                      m2_2 * n3_1);
  t23 = rt_atan2d_snf(-inputArg12 * m2_3 + n2_3 * n3_2, -inputArg12 * n2_3 -
                      m2_3 * n3_2);
  t24 = rt_atan2d_snf(-inputArg12 * m2_4 + n2_4 * n3_2, -inputArg12 * n2_4 -
                      m2_4 * n3_2);

  /* t5 */
  m2_1 = cos(t21);
  m2_2 = inputArg3 * n3_1_tmp;
  n2_1 = sin(t21);
  n2_2 = inputArg7 * b_n3_1_tmp;
  n3_2 = (m2_2 * m2_1 + n2_2 * m2_1) + -inputArg11 * n2_1;
  n2_4 = -((m2_2 * n2_1 + n2_2 * n2_1) - -inputArg11 * m2_1);
  m2_1 = cos(t22);
  n2_1 = sin(t22);
  m5_2 = (m2_2 * m2_1 + n2_2 * m2_1) + -inputArg11 * n2_1;
  n2_3 = -((m2_2 * n2_1 + n2_2 * n2_1) - -inputArg11 * m2_1);
  m2_1 = cos(t23);
  m2_2 = inputArg3 * n3_2_tmp;
  n2_1 = sin(t23);
  n2_2 = inputArg7 * b_n3_2_tmp;
  n3_1 = (m2_2 * m2_1 + n2_2 * m2_1) + -inputArg11 * n2_1;
  m2_4 = -((m2_2 * n2_1 + n2_2 * n2_1) - -inputArg11 * m2_1);
  m2_1 = cos(t24);
  n2_1 = sin(t24);
  m5_4 = (m2_2 * m2_1 + n2_2 * m2_1) + -inputArg11 * n2_1;
  m2_3 = -((m2_2 * n2_1 + n2_2 * n2_1) - -inputArg11 * m2_1);
  n2_2 = inputArg7 * n3_1_tmp - inputArg3 * b_n3_1_tmp;
  m2_2 = n3_2 * t42 + n2_4 * t45;
  m2_1 = (n3_2 * sin(0.20349304525756276 + r_tmp) - n2_4 * cos
          (0.20349304525756276 + r_tmp)) / -1.0;
  t51 = rt_atan2d_snf(sqrt(n2_2 * n2_2 + m2_2 * m2_2), m2_1);
  t52 = rt_atan2d_snf(-sqrt(n2_2 * n2_2 + m2_2 * m2_2), m2_1);
  m2_2 = m5_2 * t41 + n2_3 * t43;
  m2_1 = (m5_2 * sin(0.20349304525756276 + b_r_tmp) - n2_3 * cos
          (0.20349304525756276 + b_r_tmp)) / -1.0;
  t53 = rt_atan2d_snf(sqrt(n2_2 * n2_2 + m2_2 * m2_2), m2_1);
  t54 = rt_atan2d_snf(-sqrt(n2_2 * n2_2 + m2_2 * m2_2), m2_1);
  m2_2 = inputArg7 * n3_2_tmp - inputArg3 * b_n3_2_tmp;
  n2_1 = n3_1 * t57 + m2_4 * t58;
  m2_1 = (n3_1 * sin(0.20349304525756276 + c_r_tmp) - m2_4 * cos
          (0.20349304525756276 + c_r_tmp)) / -1.0;
  t55 = rt_atan2d_snf(sqrt(m2_2 * m2_2 + n2_1 * n2_1), m2_1);
  t56 = rt_atan2d_snf(-sqrt(m2_2 * m2_2 + n2_1 * n2_1), m2_1);
  n2_1 = m5_4 * b_m2_4_tmp + m2_3 * m2_4_tmp;
  m2_1 = (m5_4 * sin(0.20349304525756276 + d_r_tmp) - m2_3 * cos
          (0.20349304525756276 + d_r_tmp)) / -1.0;
  t57 = rt_atan2d_snf(sqrt(m2_2 * m2_2 + n2_1 * n2_1), m2_1);
  t58 = rt_atan2d_snf(-sqrt(m2_2 * m2_2 + n2_1 * n2_1), m2_1);

  /* t4 */
  m2_1 = sin(t51);
  if (m2_1 == 0.0) {
    t41 = 0.0;
  } else {
    t41 = rt_atan2d_snf(n2_2 / m2_1, (-n3_2 * cos(0.20349304525756276 + r_tmp) -
      n2_4 * sin(0.20349304525756276 + r_tmp)) / m2_1);
  }

  m2_1 = sin(t52);
  if (m2_1 == 0.0) {
    t42 = 0.0;
  } else {
    t42 = rt_atan2d_snf(n2_2 / m2_1, (-n3_2 * cos(0.20349304525756276 + r_tmp) -
      n2_4 * sin(0.20349304525756276 + r_tmp)) / m2_1);
  }

  m2_1 = sin(t53);
  if (m2_1 == 0.0) {
    t43 = 0.0;
  } else {
    t43 = rt_atan2d_snf(n2_2 / m2_1, (-m5_2 * cos(0.20349304525756276 + b_r_tmp)
      - n2_3 * sin(0.20349304525756276 + b_r_tmp)) / m2_1);
  }

  m2_1 = sin(t54);
  if (m2_1 == 0.0) {
    n3_2 = 0.0;
  } else {
    n3_2 = rt_atan2d_snf(n2_2 / m2_1, (-m5_2 * cos(0.20349304525756276 + b_r_tmp)
      - n2_3 * sin(0.20349304525756276 + b_r_tmp)) / m2_1);
  }

  m2_1 = sin(t55);
  if (m2_1 == 0.0) {
    t45 = 0.0;
  } else {
    t45 = rt_atan2d_snf(m2_2 / m2_1, (-n3_1 * cos(0.20349304525756276 + c_r_tmp)
      - m2_4 * sin(0.20349304525756276 + c_r_tmp)) / m2_1);
  }

  m2_1 = sin(t56);
  if (m2_1 == 0.0) {
    n2_4 = 0.0;
  } else {
    n2_4 = rt_atan2d_snf(m2_2 / m2_1, (-n3_1 * cos(0.20349304525756276 + c_r_tmp)
      - m2_4 * sin(0.20349304525756276 + c_r_tmp)) / m2_1);
  }

  m2_1 = sin(t57);
  if (m2_1 == 0.0) {
    n3_1 = 0.0;
  } else {
    n3_1 = rt_atan2d_snf(m2_2 / m2_1, (-m5_4 * cos(0.20349304525756276 + d_r_tmp)
      - m2_3 * sin(0.20349304525756276 + d_r_tmp)) / m2_1);
  }

  m2_1 = sin(t58);
  if (m2_1 == 0.0) {
    n2_3 = 0.0;
  } else {
    n2_3 = rt_atan2d_snf(m2_2 / m2_1, (-m5_4 * cos(0.20349304525756276 + d_r_tmp)
      - m2_3 * sin(0.20349304525756276 + d_r_tmp)) / m2_1);
  }

  /* t6 */
  m2_4 = inputArg1 * b_n3_1_tmp - inputArg5 * n3_1_tmp;
  n2_2 = inputArg2 * b_n3_1_tmp - inputArg6 * n3_1_tmp;
  m2_3 = inputArg1 * b_n3_2_tmp - inputArg5 * n3_2_tmp;
  n2_1 = inputArg2 * b_n3_2_tmp - inputArg6 * n3_2_tmp;
  outputArg1[0] = t11;
  outputArg1[8] = t21;
  outputArg1[16] = 0.20349304525756276 + r_tmp;
  outputArg1[24] = t41;
  outputArg1[32] = t51;
  m2_2 = cos(t41);
  m2_1 = cos(t51) * sin(t41);
  outputArg1[40] = rt_atan2d_snf(m2_2 * m2_4 - m2_1 * n2_2, m2_2 * n2_2 + m2_1 *
    m2_4);
  outputArg1[1] = t11;
  outputArg1[9] = t21;
  outputArg1[17] = 0.20349304525756276 + r_tmp;
  outputArg1[25] = t42;
  outputArg1[33] = t52;
  m2_2 = cos(t42);
  m2_1 = cos(t52) * sin(t42);
  outputArg1[41] = rt_atan2d_snf(m2_2 * m2_4 - m2_1 * n2_2, m2_2 * n2_2 + m2_1 *
    m2_4);
  outputArg1[2] = t11;
  outputArg1[10] = t22;
  outputArg1[18] = 0.20349304525756276 + b_r_tmp;
  outputArg1[26] = t43;
  outputArg1[34] = t53;
  m2_2 = cos(t43);
  m2_1 = cos(t53) * sin(t43);
  outputArg1[42] = rt_atan2d_snf(m2_2 * m2_4 - m2_1 * n2_2, m2_2 * n2_2 + m2_1 *
    m2_4);
  outputArg1[3] = t11;
  outputArg1[11] = t22;
  outputArg1[19] = 0.20349304525756276 + b_r_tmp;
  outputArg1[27] = n3_2;
  outputArg1[35] = t54;
  m2_2 = cos(n3_2);
  m2_1 = cos(t54) * sin(n3_2);
  outputArg1[43] = rt_atan2d_snf(m2_2 * m2_4 - m2_1 * n2_2, m2_2 * n2_2 + m2_1 *
    m2_4);
  outputArg1[4] = t12;
  outputArg1[12] = t23;
  outputArg1[20] = 0.20349304525756276 + c_r_tmp;
  outputArg1[28] = t45;
  outputArg1[36] = t55;
  m2_2 = cos(t45);
  m2_1 = cos(t55) * sin(t45);
  outputArg1[44] = rt_atan2d_snf(m2_2 * m2_3 - m2_1 * n2_1, m2_2 * n2_1 + m2_1 *
    m2_3);
  outputArg1[5] = t12;
  outputArg1[13] = t23;
  outputArg1[21] = 0.20349304525756276 + c_r_tmp;
  outputArg1[29] = n2_4;
  outputArg1[37] = t56;
  m2_2 = cos(n2_4);
  m2_1 = cos(t56) * sin(n2_4);
  outputArg1[45] = rt_atan2d_snf(m2_2 * m2_3 - m2_1 * n2_1, m2_2 * n2_1 + m2_1 *
    m2_3);
  outputArg1[6] = t12;
  outputArg1[14] = t24;
  outputArg1[22] = 0.20349304525756276 + d_r_tmp;
  outputArg1[30] = n3_1;
  outputArg1[38] = t57;
  m2_2 = cos(n3_1);
  m2_1 = cos(t57) * sin(n3_1);
  outputArg1[46] = rt_atan2d_snf(m2_2 * m2_3 - m2_1 * n2_1, m2_2 * n2_1 + m2_1 *
    m2_3);
  outputArg1[7] = t12;
  outputArg1[15] = t24;
  outputArg1[23] = 0.20349304525756276 + d_r_tmp;
  outputArg1[31] = n2_3;
  outputArg1[39] = t58;
  m2_2 = cos(n2_3);
  m2_1 = cos(t58) * sin(n2_3);
  outputArg1[47] = rt_atan2d_snf(m2_2 * m2_3 - m2_1 * n2_1, m2_2 * n2_1 + m2_1 *
    m2_3);
}

/*
 * File trailer for nifunction.c
 *
 * [EOF]
 */
