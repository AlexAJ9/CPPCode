 
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
int main(){

  char fifoname[]="data";
  char buff[5]={1,2,3,4,5};
  int fd;
  fd=open(fifoname, O_WRONLY);
  write(fd,buff,strlen(buff)*sizeof(int));
  close(fd);
  return 0;
}
 
