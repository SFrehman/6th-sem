%{
#include <stdio.h>
int identifiers = 0, operators = 0, brackets = 0;
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* { identifiers++; printf("Identifier: %s\n", yytext); }
[0-9]+                  { identifiers++; printf("Constant: %s\n", yytext); }
"+"|"-"|"*"|"/"         { operators++; printf("Operator: %s\n", yytext); }
"("|")"                 { brackets++; }
.|\n                    { /* Ignore whitespace and others */ }
%%

int main() {
    printf("Enter an arithmetic expression: ");
    yylex();
    
    if (brackets % 2 == 0) {
        printf("\nValid Expression Evaluation:\n");
        printf("Total Identifiers/Constants: %d\n", identifiers);
        printf("Total Operators: %d\n", operators);
    } else {
        printf("\nInvalid Expression: Unmatched brackets.\n");
    }
    return 0;
}

int yywrap() {
    return 1;
}