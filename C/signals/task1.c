#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
  signal(SIGINT,SIG_IGN);
  int i;
  for( i = 0; i<20; i++)
  {
    printf("I= %d \n", i);
    sleep(1);
    if(i==10)
    {
      signal(SIGINT,SIG_DFL);
    }
  }
 return 0; 
}