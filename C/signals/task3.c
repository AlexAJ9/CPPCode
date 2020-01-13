#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(){
  pid_t pid;
  pid=fork();
  if(pid==0){
   pause();//wait for signal
  }
  else if(pid>0){
   kill(pid,SIGINT);
   int status;
   wait(&status);
   if(WIFSIGNALED(status))
    int signo=WTERMSIG(status);
    printf("Child exited by signal %d -%s\n",signo,strsignal(signo));
   }
  }
  return 0;
}
