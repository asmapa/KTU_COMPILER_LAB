%{
#include <stdio.h>
#include <stdlib.h>

int opcode = 0;
float opnd1, opnd2, res;
void calculate();
%}

%option noyywrap
  

%%
[0-9]+|[0-9]*"."[0-9]+      { calculate(); }
"+"        { opcode = 1; }
"-"        { opcode = 2; }
"*"        { opcode = 3; }
"/"        { opcode = 4; }
"\n"       { printf("\nThe result is %g\n", res); }
%%

void calculate()
{
    if (opcode == 0)
        opnd1 = atof(yytext);
    else {
        opnd2 = atof(yytext);
        res = (opcode == 1)? (opnd1+opnd2) :
              (opcode == 2)? (opnd1-opnd2) :
              (opcode == 3)? (opnd1*opnd2) :
                             (opnd1/opnd2);
        opcode = 0;
        opnd1 = res; // store result for next operation
    }
}

int main()
{
    printf("Enter expression (ex: 10+5 then press Enter):\n");
    yylex();
    return 0;
}
