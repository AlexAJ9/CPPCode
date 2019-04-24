#include<stdio.h>
#include "shared_lib/shared.h"

int main (){
int  *c1;
int  *c2;
int *queue;
int *common;
c1 = (int *)getmem(0213);
c2 = (int *)getmem(0214);
queue = (int *)getmem(0211);
common = (int *)getmem(0212);
 *common=0;
 *c1=1;
 *c2=1;
 *queue=1;
 printf("the initial value is %d.\n",*common);

} 

