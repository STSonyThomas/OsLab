#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int btime;
    int wtime;
    int atime;
    int priority;
}p;

void readP(int n,p *ptr);
void sortA(int n,p *ptr);
void sortB(int n,p *ptr);
void sortP(int n,p *ptr);
void roundRobin(int n,p *ptr);

int main(){
    int n,control;
    p *ptr;
    printf("ENter the number of processes\n");
    scanf("%d",&n);
    ptr = (p*)malloc(sizeof(p)*n);
    readP(n,ptr);
    printf("Press 1 for fcfs\nPress 2 for sjf\nPress 3 for Priority\nPress 4 for Round Robin : ");
    scanf("%d",&control);
    switch(control){
        case 1 :
            sortA(n,ptr);
            break;
        case 2:
            sortB(n,ptr);
            break;
        case 3:
            sortP(n,ptr);
            break;
        case 4:
            roundRobin(n,ptr);
            break;
        default:
            printf("Invalid choice entered...Terminating program now!\n");
            exit(1);
    }
    // sortA(n,ptr);
    for(int i=0;i<n;i++){
        printf("%d\n",(ptr+i)->atime);
    }
    return 0;
}
//reading processes
void readP(int n,p *ptr){
    int pri;
    int ari;
    for(int i=0;i<n;i++){
        printf("Enter the burst time for process %d\n :",i+1);
        scanf("%d",&((ptr+i)->btime));
        (ptr+i)->priority=0;
    }
    printf("Do you want to give a priority to processes?(1/0): ");
    scanf("%d",&pri);
    if(pri){
        for(int i=0;i<n;i++){
        printf("Enter the priority for process %d\n :",i+1);
        scanf("%d",&((ptr+i)->priority));
    }
    }
    printf("Do you want to enter arrival time to the processes?(1/0): ");
    scanf("%d",&ari);
    if(ari){
        for(int i=0;i<n;i++){
             printf("Enter the arrival time for process %d\n :",i+1);
             scanf("%d",&((ptr+i)->atime));
        }
    }else{
        for(int i=0;i<n;i++){
             ptr[i].atime=0;
        }
    }
}
//sorting arrival time
void sortA(int n, p *ptr){
    int waitt,totwt,btime,totbt;
    for(int i=0;i<n;i++){
        int min = i;
        p minp = *(ptr+i);
        for(int j=i+1;j<n;j++){
            if(ptr[j].atime<minp.atime){
                min =j;
                minp =*(ptr+j);
                ptr[j]=ptr[i];
                ptr[i]=minp;
            }
        }
    }
}
//sorting burst time
void sortB(int n, p *ptr){
    int waitt,totwt,btime,totbt;
    for(int i=0;i<n;i++){
        int min = i;
        p minp = *(ptr+i);
        for(int j=i+1;j<n;j++){
            if(ptr[j].btime<minp.btime){
                min =j;
                minp =*(ptr+j);
                ptr[j]=ptr[i];
                ptr[i]=minp;
            }
        }
    }
}
//sorting priority
void sortP(int n, p *ptr){
    int waitt,totwt,btime,totbt;
    for(int i=0;i<n;i++){
        int min = i;
        p minp = *(ptr+i);
        for(int j=i+1;j<n;j++){
            if(ptr[j].priority<minp.priority){
                min =j;
                minp =*(ptr+j);
                ptr[j]=ptr[i];
                ptr[i]=minp;
            }
        }
    }
}
//round robin
void roundRobin(int n,p *ptr){
    int quanta,temp;
    int burst[n];
    printf("Enter the quanta: ");
    scanf("%d",&quanta);
    while(temp!=0){
        temp=n;
        for(int i=0;i<n;i++){
            if(ptr[i].btime!=0){
                ptr[i].btime-=quanta;
                ptr[i].wtime+=quanta+ptr[i-1].btime;
                if(ptr[i].btime<0){
                    ptr[i].btime=0;
                }

            }
            else if(ptr[i].btime==0){
                temp--;
            }
            
        }
    }
    //printing the result
    for(int j=0;j<n;j++){
        printf("%d\t%d\t%d\t",ptr[j].atime,ptr[j].btime,ptr[j].wtime);
        printf("\n");
    }
}