#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

int main(){
  char fifoname[]="data";
  char buff[100]="sent from writer";
  int fd;
  fd=open(fifoname, O_WRONLY);
  write(fd,buff,strlen(buff)*sizeof(char));
  close(fd);
  return 0;
}
 
