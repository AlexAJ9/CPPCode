#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void handler(int num)
{
 psignal(num,"Handled"); 
}

int main()
{
  signal(SIGALRM,handler);
  alarm(2);
  sleep(3);
 return 0; 
}