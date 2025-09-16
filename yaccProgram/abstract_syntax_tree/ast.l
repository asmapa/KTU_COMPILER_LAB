%option noyywrap
%{
#include "ast.h"
#include "ast.tab.h"
%}
%%
[0-9]+ {yylval.INT=atoi(yytext);return NUMBER;}
\n {return NL;} 
. {return yytext[0];}
%%