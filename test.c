#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50
#define LEN 5

int num_inst=0;
char instr[SIZE];

struct{
    char res[LEN];
    char op;
    char opd1[LEN];
    char opd2[LEN];
}tap[SIZE];

void readInstructions(){
    printf("Enter number of instructions:\n");
    scanf("%d",&num_inst);
    printf("Enter the instructions :\n");
    for(int i=0;i<num_inst;i++){
        scanf("%s = %s %c %s",tap[i].res,tap[i].opd1,&tap[i].op,tap[i].opd2);
    }
}

char *getIn(char op){
    char mn[][LEN]={"MUL","ADD","","SUB","","DIV"};
    strcpy(instr,mn[op-'*']);
    return instr;
}

void generate_tc(){
    for(int i=0;i<num_inst;i++){
        printf("MOV AX,%s\n%s AX,%s\nMOV %s,AX\n",tap[i].opd1,getIn(tap[i].op),tap[i].opd2,tap[i].res);
    }
}

int main(){
    readInstructions();
    printf("Target Code:\n");
    generate_tc();
}