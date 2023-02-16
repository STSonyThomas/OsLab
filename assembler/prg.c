#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//typedefinitions go here

//function declarations go here

//main program goes here

int main(){
    int operand,locctr,opnum,temp,startadd;
    char lab[10],opcode[10],opcheck[10],oper[10];
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("program.txt","r");
    f2=fopen("sym.txt","w");
    f3=fopen("op.txt","r");
    f4=fopen("int.txt","w");
    fscanf(f1,"%s %s %d",lab,opcode,&operand);
    fprintf(f4,"%s\t%s\t%d\t%s\n",lab,opcode,operand,"-");
    if(strcmp(opcode,"START")==0){
        locctr=operand;
        startadd=operand;
    }
    else{
        locctr=0;
    }
    printf("Location is : %d",locctr);
    fscanf(f1,"%s%s%s",lab,opcode,oper);
    // fprintf(f4,"%s%s%s","LABEL\t","OPCODE\t","OPERAND");
    // fscanf(f1,"%s%s%s",lab,opcode,oper);//read first line of input 
    while(!feof(f1)){
        printf("\n%d\n",locctr);
        // printf("%d",strcmp(lab,"-"));
        if(strcmp(lab,"-")!=0){
        //into symtab
            fprintf(f2,"\n%s\t%d\n",lab,locctr);
        }
        fscanf(f3,"%s%d",opcheck,&opnum);//opnum for the opbject code of opcode
        while(!feof(f3)){
            if(strcmp(opcode,opcheck)==0){
                locctr+=3;

            }
            fscanf(f3,"%s%d",opcheck,&opnum);
        }
        if(strcmp(opcode,"WORD")){
            locctr+=3;
        }
        else if(strcmp(opcode,"RESW")==0){
            temp=atoi(oper);
            locctr+=3*temp;
        }
        else if(strcmp(opcode,"BYTE")==0){
            if(oper[0]=='C'){
                int len=strlen(oper)-3;
                locctr+=len;
            }
            else if(oper[0]=='X'){
                int len=strlen(oper)-3;
                len/=2;
                if(len%2!=0){
                    len=len/2+1;
                }
                locctr+=len;
            }
        }
        else if(strcmp(opcode,"RESB")){
            locctr+=atoi(oper);
        }
    fprintf(f4,"\n%s\t%s\t%s\t%d\n",lab,opcode,oper,locctr);
    fscanf(f1,"%s%s%s",lab,opcode,oper);

    }
    if(strcmp(opcode,"END")==0){
        printf("program length is %d",locctr-startadd);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
}

//function definitons go here