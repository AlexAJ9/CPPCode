#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char fifoname[]="data";
  char buff[10];
  int fd;
  fd=open(fifoname, O_RDONLY);
  read(fd,buff,strlen(buff)*sizeof(int));
  int i;
  for( i=0; i<5; i++)
  {
      printf("Read: %s\n",buff[i]);
  }
  close(fd);
  return 0;
}
