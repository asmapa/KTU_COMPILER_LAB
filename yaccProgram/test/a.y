%{
    #include<stdio.h>
    #include "a.h"
    int yyerror(char *s);
    int yylex();
    ASTNode *root=NULL;
%}
%union{
    int INT;
    ASTNode *ptr;
}

%token <INT>num;

%left '+' '-'
%left '*' '/'

%%
start : e '\n' {root=$<ptr>1;return 0;}
e: e '+' e {$<ptr>$=makeNode('+',$<ptr>1,$<ptr>3);}
 | e '-' e {$<ptr>$=makeNode('-',$<ptr>1,$<ptr>3);}
 | e '*' e {$<ptr>$=makeNode('*',$<ptr>1,$<ptr>3);}
 | e '/' e {$<ptr>$=makeNode('/',$<ptr>1,$<ptr>3);}
 | '(' e ')' {$<ptr>$=$<ptr>2;}
 |num {$<ptr>$=makeLeaf($<INT>1);}
%%

int main(){
    printf("Enter the expression:\n");
    yyparse();
    printf("Result:\n");
    printAST(root);
    printf("\n");
}
int yyerror(char *s){
    printf("An error occured!!!!....");
}

