#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void handler(int num)
{
  psignal(num,"handled");
}

int main(){
  pid_t pid;
  pid=fork();
  if(pid==0){
   sleep(2);
  }else if(pid>0){
   signal(SIGCHLD,handler);
   int status;
   wait(&status);
   if(WIFSIGNALED(status)){
    int signo=WTERMSIG(status);
    printf("Child exited by signal %d -%s\n",signo,strsignal(signo));
   }
  }
  return 0;
}
