//
// Created by sony on 28/6/22.
//
#include<stdio.h>
#include<stdlib.h>
typedef struct rr{
    int bTime;
    int wTime;
    int pNo;
    int arrTime;
}rr;
int main(){
    int i,j,n;
    int ttTime=0,twTime=0;
    printf("Enter the number of processes = ");
    scanf("%d",&n);
    rr *stack, temp;
    stack=(rr*) malloc(sizeof(rr)*n);
    for(int i=0;i<n;i++){
        printf("Enter the burst time of process number %d\n",i+1);
        scanf("%d",&stack[i].bTime);
        printf("Enter the arrival time of process number %d\n",i+1);
        scanf("%d",&stack[i].arrTime);
    }
    for(int i=0;i<n-1;i++){
        for(int j= i+1;i<n;i++){
            if(stack[i].pNo>stack[j].pNo){
                temp=stack[i];
                stack[i]=stack[j];
                stack[j]=stack[i];
            }
        }
    }
    int burst;
    printf("Enter the quanta time");
    scanf("%d",&burst);
    //setting the initial process waiting time to 0
    stack[0].wTime=0;
    stack[0].arrTime=0;
    int yDone;
    while(yDone>0){
        yDone=n;
        for(i=0;i<yDone;i++){
            if(stack[i].bTime<burst && stack[i].bTime>0){
                ttTime+=stack[i].bTime;
                twTime+=stack[i].bTime +
            }
        }

    }


}
