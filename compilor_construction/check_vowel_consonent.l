%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]             { vowels++; }
[a-zA-Z]                 { consonants++; }
.|\n                     { /* Ignore spaces, digits, and special characters */ }
%%

int main() {
    printf("Enter text: ");
    yylex();
    printf("Vowels: %d\nConsonants: %d\n", vowels, consonants);
    return 0;
}

int yywrap() {
    return 1;
}