#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>

  void myhandler(int signo,siginfo_t *info,void *ctx)
  {
    printf("signal handled: %d \n", info -> si_signo);
    sleep(10);
    printf("end of handler \n");
    
  }
  
  int main () 
   {
     struct sigaction sa;
     memset(&sa, 0, sizeof(sa));
     sa.sa_sigaction = &myhandler;
     sa.sa_flags=SA_SIGINFO | SA_NODEFER;
     sigset_t set;
     sigemptyset(&set);
     sa.sa_mask = set;
     sigaction (SIGINT, &sa, NULL);
     int i;
     for (i = 0; i<10; i++) 
     {
       printf("iteration %d \n",i);
       sleep(1);
     }
     return 0;
   }
   

