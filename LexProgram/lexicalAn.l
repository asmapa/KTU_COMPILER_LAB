%{
    #include <stdio.h>
    #include <stdlib.h>
    FILE *fp;
    
%}

%option noyywrap

/* Definitions */
preprocessor   "#".*
identifier     [_a-zA-Z][_a-zA-Z0-9]*
number         [0-9]+
keyword        auto|for|while|switch|int|char|double|main|return|if|else
comment        "/*"([^*]|\*+[^/])*\*\/
ws             [ \t\n]+
operator       [+\-*/=<>!&|]
special        [;:,.(){}[\]]

%%

{keyword}       { printf("\n%s is a keyword", yytext); }
{identifier}    { printf("\n%s is an identifier", yytext); }
{number}        { printf("\n%s is a number", yytext); }
{preprocessor}  { printf("\n%s is a preprocessor directive", yytext); }
{comment}       { printf("\n%s is a comment", yytext); }
{operator}      { printf("\n%s is an operator", yytext); }
{special}       { printf("\n%s is a special symbol", yytext); }
{ws}            { /* ignore whitespace */ }
.               { printf("\n%s is unknown", yytext); }

%%

int main() {
    fp = fopen("input.c", "r");
    if (!fp) {
        printf("Cannot open input file\n");
        exit(1);
    }
    yyin = fp;
    yylex();
    fclose(fp);
    return 0;
}
