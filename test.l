%{
    #include "test.tab.h"
%}
%option noyywrap
%%
[0-9]+ {return num;}
[+\-/*] {return op;}
\( {return '(';}
\) {return ')';}
\n {return '\n';}
. {return yytext[0];}
%%