#include<stdio.h>
#include "shared_lib/shared.h"

int main (){

 int *common;
 common = (int *)getmem(0212);
 *common=0;
 printf("the initial value is %d.\n",*common);

} 

