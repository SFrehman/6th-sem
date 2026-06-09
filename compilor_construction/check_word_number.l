%{
#include <stdio.h>
%}

%%
if|else|printf   { printf("%s is a keyword\n", yytext); }
[0-9]+           { printf("%s is a number\n", yytext); }
[a-zA-A]+        { printf("%s is a word\n", yytext); }
.|\n             { /* Skip spaces, tabs, and un-matched characters */ }
%%

int main() {
    printf("Enter the string: ");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}