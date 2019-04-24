#include <stdio.h>
#include "shared_lib/shared.h"

int main(){
    sem_t sem1;
    sem_t sem2;
    sem1=sem_init(6255);
    sem2=sem_init(6222);
	char *c;
	c=(char *)getmem(6166);
	for(char i='A';i<='Z';++i){
	       PS(sem1);
	       *c=i;
	       VS(sem2);
	}
	return 0; 
}
