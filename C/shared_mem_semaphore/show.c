#include <stdio.h>
#include "shared_lib/shared.h"

int main (){
int *common;
common = (int *)getmem(0212);
printf("the common value is %d.\n", *common);
}
