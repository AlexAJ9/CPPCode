#include <stdio.h>
#include "shared_lib/shared.h"

main(){

int *c1,*c2,*queue; 
int *common,i, k, a;
 common = (int *)getmem(0212);
 c1 = (int *)getmem(0213);
 c2 = (int *)getmem(0214);
 queue = (int *)getmem(0215);

for (i=1;i<=1000000;i++){

  *c1 = 2;
 while ( !*c2 ) {
     if(*queue == 2 ){
       *c1 = 1;
       while (*queue == 2) ;
     *c1 = 2;
     }
   }
a=*common;
a=a-1;
*common=a;

 *queue=2;
 *c1=1;
for (k=0;k<1000;k++);
}
printf("Dec process ended.\n");
}
