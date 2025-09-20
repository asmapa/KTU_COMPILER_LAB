%{
#include<stdio.h>
int opcode =0;
int opd1=0,opd2=0,res=0;
void calculate();
%}
%option noyywrap

num [0-9]+|[0-9]*"."[0-9]+

%%
{num} {calculate();}
"+" {opcode=1;}
"-" {opcode=2;}
\n {printf("result:%d\n",res);}
%%

void calculate(){
    if(opcode ==0){
        opd1 = atof(yytext);
    }else{
        opd2=atof(yytext);
        if(opcode==1){
            res=opd1+opd2;
        }else if(opcode==2){
            res=opd1-opd2;
        }

        opd1=res;
        opcode=0;
    }
}