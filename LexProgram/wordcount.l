%{
    #include<stdio.h>
    int words=0;
%}
%option noyywrap
%%
[a-zA-Z0-9]+ {words++;}
%%
int main(int argc,char **argv){
    yyin = fopen(argv[1],"r");
    yylex();
    printf("words = %d",words);
    fclose(yyin);
}
