#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>

//declaring global variables

int main(){
    int i;
    void *sharedMemory;
    char buff[100];
    int shmid;

    shmid=shmget((key_t)2345,1025,0666|IPC_CREAT);
    printf("key of shared memory is %d\n",shmid);
    sharedMemory=shmat(shmid,NULL,0);
    printf("and the process is attached at %p\n",sharedMemory);
    printf("Enter some data to write to shared memory\n");
    read(0,buff,100);
    strcpy(sharedMemory,buff);
    printf("You wrote %s\n",(char*)sharedMemory);
    return 0;
}