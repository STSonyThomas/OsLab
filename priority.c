#include<stdio.h>
#include<stdlib.h>
typedef struct process{
    int priority;
    int pno;
    int wTime;
    int bTime;
}sp;

int main(){
    int i,j,n;
    int totwtime=0,totttime=0;
    sp *p,temp;
    printf("************Priority Scheduling*********\n");
    printf("Enter the number of processes");
    scanf("%d",&n);
    p = (sp*)malloc(sizeof(sp)*n);
    for(int i=0;i<n;i++){
        printf("Enter the priority of process %d = ",i+1);
        scanf("%d",&p[i].priority);
        printf("Enter the burst time of the process %d = ",i+1);
        scanf("%d",&p[i].bTime);
    }
    // sorting the processes based on their priorities
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].priority>p[j].priority){
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    // setting the wait of the first process to 0;
    p[0].wTime=0;
    for(int i=1;i<n;i++){
        p[i].wTime= p[i-1].wTime+p[i-1].bTime;
        totwtime+=p[i].wTime;
    }
    for(int i=0;i<n;i++){
        totttime+=p[i].wTime+p[i].bTime;
    }

    printf("\nProcessNo\tPriority\tWaiting Time\t Burst Time");
    for(int i=0;i<n;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d",p[i].pno,p[i].priority,p[i].wTime,p[i].bTime);
    }
    printf("\nAverage waiting time = %d/%d=%f",totwtime,n,(float)totwtime/n);
    printf("\nAverage turnaround time =%d/%d=%f\n",totttime,n,(float)totttime/n);
    return 0;
}

