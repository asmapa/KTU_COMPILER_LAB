%{
 #include<stdio.h>
 int yyerror(char *);
 int yylex();
%}
%token A B
%%
start:S '\n' {printf("valid input....!!!");}
S:A B
 |A S B
 ;
%%
int main(){
    printf("Enter the input:\n");
    return yyparse();
}
int yyerror(char *s){
    printf("invalid error");
}