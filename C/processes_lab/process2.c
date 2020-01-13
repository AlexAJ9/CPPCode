#include<stdio.h>
#include<unistd.h>

int main(){

pid_t pid;

pid=fork();

if(pid==-1){
perror("fork");
}
else if(pid>0)
{
printf("after fork in  parent ");
}
else if(pid==0)
{
printf(" child");
}
return 0;
}


