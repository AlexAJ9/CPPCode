#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
  
  pid_t pid;
  int fd[2];
  pipe(fd);
  pid=fork();
  
  if(pid == 0){
   int buff;
   close(fd[1]);
   read(fd[0],&buff,sizeof(int));
   printf("Read value: %d \n",buff);
   close(fd[0]);
  }
  else if (pid>0){
    int value=10;
    close(fd[0]);
    write(fd[1],&value,sizeof(int));
    close(fd[1]);
    wait(NULL);
  }
  return 0;
}