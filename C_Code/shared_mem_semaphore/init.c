#include<stdio.h>
#include "shared_lib/shared.h"

int main (){

 sem_t sem1;
 sem1 = sem_init(0212);
 sem_set( sem1,1);

 int *common; 
 common = (int *)getmem(0212);
 *common=0;
 printf("the initial value is %d.\n",*common);

} 

