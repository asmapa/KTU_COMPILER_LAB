%{
    #include<stdio.h>
%}
%option noyywrap
%%
[a-z] {printf("%c",yytext[0]-32);}
.|\n {printf("%s",yytext);}
%%

int main(){
    printf("converted string:");
    yylex();
}