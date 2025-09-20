%{
#include "va.tab.h"
%}

%option noyywrap

%%
[0-9]+    { return num; }
[+\-*/]   { return op; }
\(        { return '('; }
\)        { return ')'; }
\n        { return '\n'; }
[\t ]     ;  // ignore tabs/spaces
.         { return yytext[0]; }
%%
