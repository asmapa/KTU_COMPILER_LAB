%{
    #include "ca.tab.h"
    #include <stdlib.h>
%}
%option noyywrap

%%
[0-9]+   { yylval = atoi(yytext); return num; }
\n       { return '\n'; }
.        { return yytext[0]; }
%%
