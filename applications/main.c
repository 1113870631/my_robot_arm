/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 *
 *
 * double init_data[12]={0.462096828394850,-0.565650218988123,-0.683012701892219,0.305000000000000,
        -0.641456562198425,-0.745009952791698,0.183012701892219 ,-0.528275496308508,
        -0.612372435695795,0.353553390593274 , -0.707106781186548, -0.110384757729337};


 * 2021-11-01     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "my_task.h"
#include "myni.h"
#include "pos.h"
double kp=0,ki=0;
double iterm;
double UMAXSUM=100;
double u_array[6]={0};
#define key2_num 67
#define key1_num 68
#define key3_num 19
#define key4_num 20
//计算结果储存区
double answer_buffer[600]={0};
//初识姿态和位置 目标角度
now_x_y_z nowlocate;
now_pos nowpos;
double goal_angle[6]={0};

int  key_flag =0;
static rt_sem_t dynamic_sem = RT_NULL;

#define THREAD_PRIORITY 25
#define THREAD_STACK_SIZE 1024
#define THREAD_TIMESLICE 5
#define WAIT_TIME 100

/*key1 中断key1 flag*/
void case_key1 (void *args) {

    rt_kprintf("interrupt_1 \n");

    static rt_err_t result;


    result = rt_sem_take(dynamic_sem, 0);
   if (result!=RT_EOK) {
    rt_kprintf("t2 take a dynamic semaphore, failed.\n");
    rt_sem_delete(dynamic_sem);
    return; }
    else
    {
        rt_kprintf("take ok\n");
        if(rt_pin_read(key1_num)==0){
            key_flag=1;
            rt_kprintf("flag =1 \n");
        }
        else{
            key_flag=0;
        rt_kprintf("flag =0 \n");
        }

       result=rt_sem_release(dynamic_sem);
       if(result!=RT_EOK)
       {
           rt_kprintf("release fail\n");
       }
    }




}
/*key2 中断key2 flag*/
void case_key2 (void *args) {

    rt_kprintf("interrupt_2 \n");
   static rt_err_t result;

    result = rt_sem_take(dynamic_sem, 0);
    if (result!=RT_EOK) {

    rt_kprintf("2 take a dynamic semaphore, failed.\n");
    return;
    }
    else
    {
        rt_kprintf("take ok\n");
        if(rt_pin_read(key2_num)==0){
            key_flag=2;
            rt_kprintf("flag =2 \n");
        }
        else{
            key_flag=0;
        rt_kprintf("flag =0 \n");
        }

        rt_sem_release(dynamic_sem);
    }
}

//设置key gpio
void gpio_init()
{
        rt_pin_mode(key1_num, PIN_MODE_INPUT_PULLUP);
        rt_pin_attach_irq(key1_num, PIN_IRQ_MODE_RISING_FALLING, case_key1, RT_NULL);
        rt_pin_irq_enable(key1_num, PIN_IRQ_ENABLE);

        rt_pin_mode(key2_num, PIN_MODE_INPUT_PULLUP);
        rt_pin_attach_irq(key2_num, PIN_IRQ_MODE_RISING_FALLING, case_key2, RT_NULL);
        rt_pin_irq_enable(key2_num, PIN_IRQ_ENABLE);
}
void spi_init()
{



}

void my_hard_init(){

    gpio_init();//gpio初始化
    rt_kprintf("gpio_hardware_init_ok\n");
    spi_init(); //spi 初始化
    rt_kprintf("spi_hardware_init_ok\n");
    rt_kprintf("硬件完毕\n");
}




void init_position(){
   //当前姿态和位置初始化
    nowlocate.x=0.305000000000000;
    nowlocate.y=-0.528275496308508;
    nowlocate.z=-0.110384757729337;
    nowpos.x1=0.462096828394850; nowpos.x2=-0.565650218988123;nowpos.x3=-0.683012701892219;nowpos.y1=-0.641456562198425 ;nowpos.y2=-0.745009952791698 ;nowpos.y3=0.183012701892219;nowpos.z1=-0.612372435695795;nowpos.z2=0.353553390593274;nowpos.z3=-0.707106781186548;
   int i;
   //当前目标角度初始化
   for(i=0;i<6;i++)
   {
       goal_angle[i]=get_angel(i);

   }
   rt_kprintf("归位成功\n");
}




int main(void)


{

    rt_thread_mdelay(2000);
    LOG_D("Hello RT-Thread!");

    my_hard_init();

    init_position();

    dynamic_sem=rt_sem_create("dynamic_sem",
                                        1,
                               RT_IPC_FLAG_FIFO);

    if (dynamic_sem == RT_NULL) {
    rt_kprintf("create dynamic mutex failed.\n");
    return -1;
    }
    else{
        rt_kprintf("sem creat ok\n");
    };


    task_creat();




return 0;
}
