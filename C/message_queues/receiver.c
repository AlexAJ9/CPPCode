#include "msg.h"
#include <sys/types.h>

int main(){
  key_t key;
  int msgid;
  msg m;
  key=ftok(".",1);
  msgid=msgget(key,IPC_CREAT|0755);
  msgrcv(msgid,(msg*)&m,sizeof(m),0,0);
  printf("Message:  %s\n",m.mtext);
  msgctl(msgid,IPC_RMID,NULL);
  perror("msgctl");
  return 0;
}