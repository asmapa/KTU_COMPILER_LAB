%{
    #include<stdio.h>
    int yylex();
    int yyerror();
%}
%token num
%left '+' '-'
%left '*' '/'

%%
start : e '\n' {printf("=%d",$1);}
e: e'+'e {$$=$1+$3;}
 | e'-'e {$$=$1-$3;}
 | e'*'e {$$=$1*$3;}
 | num {$$=$1;}
%%

int main(){
    printf("Enter the expression:\n");
    yyparse();
}
int yyerror(){
    printf("invalid expression !!!");
}