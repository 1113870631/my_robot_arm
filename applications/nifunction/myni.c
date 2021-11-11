#include "myni.h"
#include "nifunction.h"
void myni(double * array1,double* array2)
{   double outputArg1[48]={0};
     nifunction(*(array1), *(array1+1),*(array1+2),*(array1+3),
             *(array1+4),*(array1+5),*(array1+6),*(array1+7),
             *(array1+8),*(array1+9),*(array1+10),*(array1+11),outputArg1);
     int i;
     for(i=0;i<48;i++)
     {
         *(array2+i)=outputArg1[i];
     }


};
