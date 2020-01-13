#include "msg.h"

int main(){
    int x = 10;
    key_t key;
    int msgid;
    key=ftok(".",1);
    msgid=msgget(key,IPC_CREAT|0755);
    msg m;
    m.mtype=1;
    m.num=x;
    msgsnd(msgid,(msg*)&m,sizeof(m),0);
    return 0;
} 
