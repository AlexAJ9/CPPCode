#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

void *Hello(void *arg){
printf("I'm a thread %d.\n",arg);
pthread_exit(NULL);
}

int main(){
pthread_t threads[MAX_THREADS];
int result,num;

for(num=0;num<MAX_THREADS;num++){
printf("Creating a thread\n");

result=pthread_create(
&threads[num],NULL,
Hello, (void *)num);
if (result) {
perror("pthread_create");
exit(1);
}
}
pthread_exit(NULL);
}

