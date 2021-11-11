#include "my_task.h"
#include <rtthread.h>
#include <rtdevice.h>
#include "key_solve.h"
#include "pid.h"
extern rt_sem_t dynamic_sem ;
extern float angel_array;
extern  int  key_flag;
#define THREAD_PRIORITY 25
#define THREAD_STACK_SIZE 1024
#define THREAD_TIMESLICE 5
extern double u_array[6];


static void timeout1(void *parameter) {
     pid_contron_dend_U(0);
}


ALIGN(RT_ALIGN_SIZE)
//static struct rt_thread thread1;
/* ��� ��� 1 ��� ��� */
static void thread1_solve_entry(void *param) {
        int num1=0;
        int num2=0;
    while(1)
    {
        switch(key_flag)
        {
        case 1://������key1 ������
            if (num1==100){break;}
            key1_solve(num1);
            num1++;
            rt_kprintf("1\n");
            break;

        case 2://������key2 ������
            key2_solve();
            num2++;
            rt_kprintf("2\n");

            break;
        default://������������
            num1=num2=0;
            break;
        };
    }
}

static void thread2_motro0_pid_move_entry(void *param) {

   //创建定时器
    static rt_timer_t timer1;
    timer1 = rt_timer_create("timer1", timeout1,
    RT_NULL, 5000,
    RT_TIMER_FLAG_PERIODIC|RT_TIMER_FLAG_SOFT_TIMER);

    /* 启 动 定 时 器 1 */
  //  if (timer1 != RT_NULL) rt_timer_start(timer1);

  while(1)
  {


      rt_thread_mdelay(20);
     //获取输出值
      int num=100;
      double tmp;
      int dir=0;
      if(u_array[0]>0)
      {
          dir=1;
      }
      else{
          dir=-1;
      }
      tmp=u_array[0];
      //进行输出
      motor_move(0,u_array[0], num, dir);


   }
}

void task_creat()
{

    static rt_thread_t tid1 = RT_NULL;
    static rt_thread_t tid2 = RT_NULL;

tid1 = rt_thread_create("thread1_solve",
            thread1_solve_entry, RT_NULL,
            4000,
            THREAD_PRIORITY, THREAD_TIMESLICE);if (tid1 != RT_NULL)
            rt_thread_startup(tid1);

tid2 = rt_thread_create("thread2_move0",
        thread2_motro0_pid_move_entry, RT_NULL,
                        THREAD_STACK_SIZE,
                        THREAD_PRIORITY+1, THREAD_TIMESLICE); if (tid2 != RT_NULL)
                        rt_thread_startup(tid2)
                        ;

}
