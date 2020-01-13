#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

#define SHMSIZE 8

int main() {
  key_t key;
  int shmid;
  pid_t pid;
  pid = fork();
  if (pid == 0) {
    key = ftok (".", 1);
    shmid = shmget(key, SHMSIZE, IPC_CREAT|0755);
    int *ptr;
    ptr = shmat(shmid, NULL, 0);
    *ptr = 100;
    shmdt(ptr);
  }
  else if(pid>0){
    key = ftok(".", 1);
    sleep(1);
    shmid = shmget(key, SHMSIZE, 0755);
    int *ptr;
    ptr = shmat (shmid, NULL, 0);
    printf("Read value: %d \n", *ptr);
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);
  }
  return 0;
}











