%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror(char *s);
%}

%token num op

%left '+' '-'
%left '*' '/'

%%
start : e '\n' {printf("valid arithmatic expression\n");}
e : e op e 
  | '(' e ')' 
  |num
  ;
%%
int main(){
    printf("Enter expression:\n");
    yyparse();
}
int yyerror(char *s){
    printf("an error occured !!!!\n");
}