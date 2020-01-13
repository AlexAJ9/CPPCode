#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
  pid_t pid;
  printf("Before fork\n");
  pid=fork();
  if(pid==-1){
    perror("fork");
    exit(1);
  }else if(pid>0){
    sleep(1);
    printf("After fork,in parent\n");
  }else if(pid==0){
    sleep(1);
    printf("After fork,in child\n");
  }
  return 0;
  }