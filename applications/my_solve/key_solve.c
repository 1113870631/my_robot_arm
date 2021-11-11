/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-11-05     111       the first version
 */

#include "key_solve.h"
#include "myni.h"
#include "pos.h"
extern now_x_y_z nowlocate;
extern now_pos nowpos;

extern double answer_buffer[480];
void key1_solve(int num1)
{

    int i,j,k,n=8,choise=-1;double temp;
    rt_kprintf("solve1\n");
    rt_kprintf("num1 %d\n",num1);
    next_x_y_z next;
    next.x=nowlocate.x+0.1*num1;
    next.y=nowlocate.y;
    next.z=nowlocate.z;

   double array1[24]={0.462096828394850,-0.565650218988123,-0.683012701892219,next.x,-0.641456562198425,-0.745009952791698,0.183012701892219,next.y,-0.612372435695795,0.353553390593274,-0.707106781186548,next.z};

   double array2[48]={0};


    myni(array1,array2);

    double tmpp[48]={0};
//转置到tmpp
for(j=0;j<8;j++)
{
    for(i=0;i<6;i++)
    {
      tmpp[i+j*6]=array2[j+8*i];

    };
};



for(i=0;i<48;i++)
{
   array2[i]=tmpp[i];
}

    //最优解选取

    //目标角度  现在角度  平均差值
       double tmp1[6]={0};
       double tmp2[6]={0};
       double tmp4[8]={0};
       double tmp5[8]={0};
       for (i=0;i<6;i++)
       {
         tmp2[i]=get_angel(i);//当前角度
       };
       for(i=0;i<8;i++)
       {
           for(j=0;j<6;j++)
           {
               tmp1[j]=array2[(i*8+j)];//目标角度
           };
           for(k=0;k<6;k++)
           {
               tmp4[i]=fabs(tmp2[k]-tmp1[k]);//计算累计偏差 绝对值
           };
        };
       //


       for (i=0;i<8;i++)
            {
              tmp5[i]=tmp4[i];
            }


       for (j=0;j<n-1;j++)    //用一个嵌套循环来遍历一遍每一对相邻元素 （所以冒泡函数慢嘛，时间复杂度高）
       {
           for (i=0;i<n-1-j;i++)
           {
               if(tmp4[i]>tmp4[i+1])  //从大到小排就把左边的">"改为"<" ！！！
               {
                   temp=tmp4[i];      //a[i]与a[i+1](即a[i]后面那个) 交换
                   tmp4[i]=tmp4[i+1];    //基本的交换原理"c=a;a=b;b=c"
                   tmp4[i+1]=temp;
               }
           }
       };

       for(i=0;i<8;i++)
       {

             if(tmp5[i]==tmp4[0])
                 {choise = i;
                   break;
                 }//得出组
      }


   for (i=0;i<6;i++)
    {
       int tmp1=choise*6+i;
       answer_buffer[i]=array2[tmp1];
       int tmp2=array2[tmp1]*1000;
        rt_kprintf("%d",tmp2);
       rt_kprintf("\n");
   }


};
void key2_solve()
{

};
