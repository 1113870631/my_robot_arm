/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-11-06     111       the first version
 */
#ifndef APPLICATIONS_BSP_DRV88_BSP_DRV88_H_
#define APPLICATIONS_BSP_DRV88_BSP_DRV88_H_
//电机1~6
#define MOTOR_1 1
#define MOTOR_2 2
#define MOTOR_3 3
#define MOTOR_4 4
#define MOTOR_5 5
#define MOTOR_6 6

#define DIR_1 1  //正转
#define DIR_2 2  //反转

//电机转动
void motor_move(int motor_num,int speed,int num,int dir);


#endif /* APPLICATIONS_BSP_DRV88_BSP_DRV88_H_ */
