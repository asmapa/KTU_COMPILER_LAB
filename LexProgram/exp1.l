%{
    #include <stdio.h>

    int lines = 0, chars = 0, words = 0;
%}
%option noyywrap

%%
[a-zA-Z]+   { words++; chars += yyleng; }
\n          { lines++; chars++; }
.           { chars++; }
    
%%

int main(int argc,char **argv)
{
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("File open error");
        return 1;
    }

    yylex();

    // ✅ If file had any content but no '\n', count it as 1 line
    if (chars > 0 && lines == 0)
        lines = 1;

    printf("No of lines = %d\nNo of words = %d\nNo of chars = %d\n",
           lines, words, chars);

    fclose(yyin);
    return 0;
}
