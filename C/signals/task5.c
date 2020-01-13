#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

void handler_c(int num)
{
  psignal(num,"handler for child");
}
void handler_p(int num)
{
  psignal(num,"handler for parent");
}

int main(){
  pid_t pid;
  pid=fork();
  if(pid==0){
   signal(SIGUSR1,handler_c);
   kill(getppid(),SIGUSR1);
   sleep(2);
   pause();
  }
  else if(pid>0){
   signal(SIGUSR2,handler_p);
   kill(pid,SIGUSR2);
   int status;
   wait(&status);
   if(WIFSIGNALED(status)){
   int signo=WTERMSIG(status);
   printf("Child exited by signal %d -%s\n",signo,strsignal(signo));
   }
  }
  return 0;
}
