/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-11-07     111       the first version
 */
#ifndef APPLICATIONS_MY_SOLVE_POS_H_
#define APPLICATIONS_MY_SOLVE_POS_H_

typedef struct now_x_y_z
{
    double x;
    double y;
    double z;
}now_x_y_z;
typedef struct now_pos
{
    double x1;
    double y1;
    double z1;
    double x2;
    double y2;
    double z2;
    double x3;
    double y3;
    double z3;
}now_pos;
typedef struct next_x_y_z
{
    double x;
    double y;
    double z;
}next_x_y_z;

#endif /* APPLICATIONS_MY_SOLVE_POS_H_ */
