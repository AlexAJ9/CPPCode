#include <stdio.h>
#include "shared_lib/shared.h"

main(){
int *common,i, k, a;
 common = (int *)getmem(0212);
for (i=1;i<=1000000;i++){
a=*common;
a=a-1;
*common=a;
for (k=0;k<1000;k++);
}
printf("Dec process ended.\n");
}
