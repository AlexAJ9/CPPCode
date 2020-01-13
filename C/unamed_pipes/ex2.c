#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
  pid_t pid;
  int fd[2];
  pipe(fd);
  pid=fork();
  if(pid==0){
    char *strs[]={"a\n","c\n","bc\n"};
    close(fd[0]);
    int i;
    for(i=0;i<3;i++){
    write(fd[1],strs[i],strlen(strs[i])*sizeof(char));
    }
    close(fd[1]);
    }else if(pid>0){
    close(fd[1]);
    dup2(fd[0],STDIN_FILENO);
    close(fd[0]);
    execlp("sort","sort",NULL);
    perror("execlp");
    }
  return 0;
}