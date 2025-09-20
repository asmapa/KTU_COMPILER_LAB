%{
    int num_of_as=0;
%}
%option noyywrap
%%
a|A {num_of_as ++;}
.
%%
int main(){
    printf("Enter the input to count number of a's init:\n");
    yylex();
    printf("number of a is:%d",num_of_as);
}