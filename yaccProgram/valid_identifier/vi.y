%{
#include <stdio.h>
int yylex();
int yyerror(char *s);
%}

%token id num

%%
start : S '\n' { printf("Valid identifier...!!!\n"); return 0; }
S : id A
  ;
A : id A
  | num A
  | /* empty */
  ;
%%

int main(){
    printf("Enter an identifier:\n");
    return yyparse();
}

int yyerror(char *s){
    printf("Invalid identifier!!!!\n");
    return 0;
}
