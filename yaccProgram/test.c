#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <stdbool.h>

int n;

typedef struct {
    char op;
    char op1[5];
    char op2[5];
    char res[5];
} quadruple;

quadruple quad[10];

bool isint(char *s){
    while(*s){
        if(!isdigit(*s)){
            return false;
        }
        s++;
    }
    return true;
}

int calculate(char *op1,char *op2,char operator){
    int resval = 0;
    switch(operator){
        case '+':
            resval = atoi(op1)+atoi(op2);
            break;
        case '-':
            resval = atoi(op1)-atoi(op2);
            break;
        case '*':
            resval = atoi(op1)*atoi(op2);
            break;
        case '/':
            if(atoi(op2)!=0)
                resval = atoi(op1)/atoi(op2);
            break;
    }
    return resval;
}

char *getconstval(char *s){
    for(int i=0;i<n;i++){
        if(quad[i].op=='=' && !strcmp(quad[i].res,s)){
            return quad[i].op1;
        }
    }
    return s;
}

void fold(){
    for(int i=0;i<n;i++){
        if(isint(quad[i].op1) && isint(quad[i].op2)){
            int result = calculate(quad[i].op1,quad[i].op2,quad[i].op);
            quad[i].op='=';
            snprintf(quad[i].op1,5,"%d",result);
            strcpy(quad[i].op2,"-");
        }
    }
}

void propagate(){
    for(int i=0;i<n;i++){
        strcpy(quad[i].op1,getconstval(quad[i].op1));
        strcpy(quad[i].op2,getconstval(quad[i].op2));
        if(isint(quad[i].op1) && isint(quad[i].op2)){
            fold();
        }
    }
}

int main(){
    memset(quad,0,sizeof(quad));
    printf("Enter the number of quadruples....\n");
    scanf("%d",&n);

    printf("Enter each quadruple (e.g. + 2 3 t1):\n");
    for(int i=0;i<n;i++){
    scanf(" %c %s %s %s",
          &quad[i].op,
          quad[i].op1,
          quad[i].op2,
          quad[i].res);
}

    fold();
    propagate();

    printf("The code after constant folding and propogation is:\n");
    printf("op\topnd1\topnd2\tresult\n");
    printf("==============================\n");
    for(int i=0;i<n;i++){
        printf("%c\t%s\t%s\t%s\n",quad[i].op,quad[i].op1,quad[i].op2,quad[i].res);
    }

    return 0;
}
