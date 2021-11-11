/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-11-06     111       the first version
 */

extern double  UMAXSUM;
extern double u_array[6];
extern double kp;
extern double ki;
extern double iterm;
#include "pid.h"


static double pid_get_err(int num)
{

    return 0;
};

void pid_contron_dend_U(int num)
{
    double err;
    err=pid_get_err(num);
    iterm+=err;
    if(iterm>UMAXSUM)
      iterm=UMAXSUM;
    else if(iterm<-UMAXSUM)
      iterm=-UMAXSUM;
    u_array[num]=(kp*err+ki*iterm)/128;
}





