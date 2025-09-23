%{
    #include "a.h"
    #include "a.tab.h"
    #include<stdlib.h>
%}

%option noyywrap

%%
[0-9]+ {yylval.INT=atoi(yytext); return num;}
\n {return '\n';}
. {return yytext[0];}
%%