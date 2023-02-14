#include<stdio.h>
#include<stdlib.h>

typedef struct process {
    int btime;
    int wtime;
    int atime;
}p;

void readP(int n,p *ptr){
    int i=0;
    for(i=0;i<n;i++){

        printf("Enter the arrival time of the process %d\n",i+1);
        scanf("%d",&((ptr+i)->atime));
        printf("Enter the burst time of the process %d\n",i+1);
        scanf("%d",&((ptr+i)->btime));
        printf("Enter the wtime time of the process %d\n",i+1);
        scanf("%d",&((ptr+i)->wtime));
    }
}

void sortA(int n, p *ptr){
    for(int i = 0;i<n;i++){
        int mindex = i;
        p minel = *(ptr +i);
        for(int j = i+1;j<n;j++){
            if(ptr[j].atime < minel.atime){
                mindex=j;
                minel= *(ptr+j);
                p temp;
                temp = ptr[j];
                ptr[j]= ptr[i];
                ptr[i] = temp;
            }
        }
    }
}

int main(){
    int pno,tbtime,twtime;
    p* ppointer;
    printf("Enter the number of processes \n");
    scanf("%d",&pno);
    ppointer = (p*)malloc(pno*sizeof(p));
    readP(pno,ppointer);
    // attempting to do srtf(premtive version)

    sortA(pno,ppointer);

    for(int i = 0;i<pno;i++){
        printf("%d",ppointer[i].atime);
    }


    return 0;


}