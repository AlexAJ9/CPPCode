#include "msg.h"

int main(){
    char message[]="Hi from the fututure(sender)";
    key_t key;
    int msgid;
    key=ftok(".",1);
    msgid=msgget(key,IPC_CREAT|0755);
    msg m;
    m.mtype=2;
    strcpy(m.mtext,message);
    msgsnd(msgid,(msg*)&m,sizeof(m),0);
    return 0;
}