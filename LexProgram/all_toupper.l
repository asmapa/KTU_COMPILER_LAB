%{
    #include<stdio.h>
    #include<ctype.h>
%}

%option noyywrap

%%
[a-z] {putchar(toupper(yytext[0]));}
. {putchar(yytext[0]);}
%%

int main(){
    printf("enter string:");
    yylex();
}