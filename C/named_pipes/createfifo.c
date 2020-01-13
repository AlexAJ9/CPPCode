#include<stdio.h>
#include<unistd.h>

int main(){
char fifoname[]="data";
mkfifo(fifoname,0775);
//ili mknod(fifoname,S_IFIFO|0775|0)'
return 0;
}
