%{
    #include "anbnp.tab.h"
%}
%option noyywrap
%%
a return(A);
b return(B);
\n return('\n');
. return(yytext[0]);
%%