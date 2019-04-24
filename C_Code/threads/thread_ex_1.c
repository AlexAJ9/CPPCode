#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define max_threads 5
void *Hello(void *arg){
  printf("Hello world \n");
  pthread_exit(NULL);
}

int main(){
  pthread_t threads[max_threads];
  int result,num;

  for(num=0;num<max_threads;num++){
    printf("creating a thread");

    result=pthread_create(&threads[num],NULL,
			  Hello,NULL);
    if(result){
      perror("pthread_create");
      exit(1);
    }
  }

  pthread_exit(NULL);
}
