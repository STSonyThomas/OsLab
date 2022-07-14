#include<stdio.h>
#include<stdlib.h>

//entering global variables

int mutex=1,full=0,empty=3,x=0;
/*here mutex is the lock full signifies that the array or buffer is full and
empty is there to ensure the size of the buffer*/
//entering the functions required
int signal (int s);
int wait(int s);
void producer();
void consumer();
//main functions
int main(){
  int n;
  while(1){
    printf("Enter\n\t1. Producer\n\t2.Consumer\n\t3.Exit\n");
    scanf("%d",&n);
    switch(n){
      case 1:
        if(mutex==1 && empty!=0){
          producer();
        }else printf("THE BUFFER IS FULL\n");
        break;
      case 2:
        if(mutex==1 && full!=0){
          consumer();
        }else printf("BUFFER EMPTY\n");
        break;
      case 3:
        exit(0);
        break;
    }
  }
}

int signal(int s){
  return s++;
}
int wait(int s){
  return s--;
}

void producer(){
  wait(mutex);
  empty--;
  full++;
  signal(mutex);
  //item produced
  x++;
  printf("Item produced is %d\n",x);
}

void consumer(){
  wait(mutex);
  empty++;
  full--;
  signal(mutex);
  printf("Consumer consumes item %d\n",x);
  x--;
}
