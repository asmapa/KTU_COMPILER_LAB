#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUMPROD 6
#define MAX 50
#define MAXPRODLEN 10

char productions[NUMPROD][MAXPRODLEN] = {"E=E+E","E=E*E","E=i","E=(E)","E=E-E","E=E/E"};
char *ptr = &productions[0][0];
char stack={0};
char input ={0};
int top=-1,ip_ptr=0;


void shift(char c){
    stack[top++]=c;
    printf("%s\t\t%s\t\tshift %c in to the stack\n",stack,input+ip_ptr,c);
}

int main(){
  
    printf("Enter the input expresssion :");
    scanf("%[^\n]",input);
    getchar();
    printf("\n shift reduce parser \n");
    printf("stack\t\tinput\t\toperation\n");
    printf("------\t\t-----\t\t----------\n");
    while(input[ip_ptr] != '\0'){
        shift(input[ip_ptr++]);
        for(int j=0;j<n)
    }
}


