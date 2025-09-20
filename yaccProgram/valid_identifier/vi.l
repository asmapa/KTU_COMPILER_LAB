%{
#include "vi.tab.h"
%}
%option noyywrap
%%
[_a-zA-Z] { return id; }
[0-9]     { return num; }
'\n'      { return '\n'; }
.         { return yytext[0]; }
%%
