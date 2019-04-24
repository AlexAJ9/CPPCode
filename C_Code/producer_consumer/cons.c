#include <stdio.h>
#include "shared_lib/shared.h"

int main(){
	sem_t sem2;
	sem_t sem1;
	sem2=sem_init(6222);
	sem1=sem_init(6255);
        sem_set(sem2,0);
	sem_set(sem1,1);
	char *c;
	c=(char*)getmem(6166);
	for(char i= 0;i<= 25;++i){
	PS(sem2);
	printf("Value: %c \n",*c);
	VS(sem1);
	}
return 0;
}
