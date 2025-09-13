%{
   #include<stdio.h>
   int opcode =0;
   int opd1,opd2,result;

   void calculate();
%}
%option noyywrap
num [0-9]+|[0-9]*"."[0-9]+
%%
{num} {calculate();}
"+" {opcode=1;}
"-" {opcode=2;}
"*" {opcode=3;}\
"\n" {printf("result:%d",result);}
%%

void calculate(){
    if(opcode==0){
        opd1=atof(yytext);
    }else{
        opd2=atof(yytext);
        if(opcode==1){
            result=opd1+opd2;
        }else if(opcode==2){
            result=opd1-opd2;
        }else{
            result=opd1*opd2;
        }
    }
    opcode=0;
    opd1=result;
}

int main(){
    printf("Enter the numbers u want to calculate(1+1+1+1):");
    yylex();
    return 0;
}