#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>


int main(){
    int i;
    void *sharedMemory;
    char buff[100];
    int shmid;

    shmid=shmget((key_t)2345,1024,0666);
    sharedMemory=shmat(shmid,NULL,0);
    printf("Data read from shared memory is %s\n",(char*)sharedMemory);
    return 0;
}