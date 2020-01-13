#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){
  char fifoname[]="data";
  char buff[100]="";
  int fd;
  fd=open(fifoname, O_RDONLY);
  read(fd,buff,100*sizeof(char));
  printf("Read: %s\n",buff);
  close(fd);
  return 0;
}
