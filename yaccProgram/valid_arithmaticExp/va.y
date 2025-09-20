%{
#include <stdio.h>
int yylex();
int yyerror(const char *s);
%}

%token num op
%left '+' '-'
%left '*' '/'

%%
start : expr '\n' { printf("Valid arithmetic expression!!!\n"); }
      ;

expr : num
     | '(' expr ')'
     | expr op expr
     ;
%%

int main(){
    printf("Enter the input expression:\n");
    return yyparse();
}

int yyerror(const char *s){
    printf("Invalid arithmetic expression!!!\n");
    return 0;
}
