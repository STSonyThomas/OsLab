#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLEN 20


//typedefinitions go here

//function declarations go here

//main program goes here

int main(){
    char label[MAXLEN],opcode[MAXLEN],operand[MAXLEN],address[MAXLEN],start[MAXLEN],len[MAXLEN];
    char opc[MAXLEN],opn[MAXLEN],symc[MAXLEN],symn[MAXLEN];
    printf("ENter the length of the program: ");
    scanf("%s",len);
    FILE* f1,*f2,*f3,*f4;//f1 for intermediate f2 for symtab f3 for optab f4 for final

    //opening
    f1=fopen("int.txt","r");
    f2=fopen("sym.txt","r");
    f3=fopen("op.txt","r");
    f4=fopen("final.txt","w");

    fscanf(f1,"%s%s%s%s",label,opcode,operand,address);
    printf("%s\n",opcode);
    if(strcmp(opcode,"START")==0){
        strcpy(start,operand);
        fprintf(f4,"H^%s^%s^%s\nT^",label,operand,len);
    }
    //header record over
    fscanf(f1,"%s%s%s%s",label,opcode,operand,address);
    fprintf(f4,"0000%s^",address);
    while(!feof(f1)){
        // printf("\n%s\t%s\t%s\t%s\n",label,opcode,operand,address);
        while(!feof(f3)){
            fscanf(f3,"%s%s",opc,opn);
            // printf("\n%s%s\n",opc,opn);
            if(strcmp(opcode,opc)==0){
                while(!feof(f2)){
                    fscanf(f2,"%s%s",symc,symn);
                    // printf("\n%s%s\n",symc,symn);
                    if(strcmp(operand,symc)==0){
                        fprintf(f4,"%s%s^",opcode,symn);
                        break;
                    };
                    
                }break;
            }
        }
        fseek(f3,0,SEEK_SET);
        fseek(f2,0,SEEK_SET);
        fscanf(f1,"%s%s%s%s",label,opcode,operand,address);

    }
    fseek(f1,0,SEEK_SET);
    while(!feof(f1)){
        fscanf(f1,"%s%s%s%s",label,opcode,operand,address);
        if(!strcmp(opcode,"BYTE")||!strcmp(opcode,"WORD")){
            if(!strcmp(opcode,"WORD")){
                fprintf(f4,"0000%s^",operand);
            }
            else{
                int len =strlen(operand);
                for(int i=2;i<len-1;i++){
                    fprintf(f4,"%d",operand[i]);
                }
                fprintf(f4,"^");
            }
        }
    }
    fseek(f1,0,SEEK_SET);
    while(!feof(f1)){
        if(strcmp(opcode,"END")){
            fprintf(f4,"\nE^%s",start);
        }break;
    }

    //closing
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

}

//function definitons go here