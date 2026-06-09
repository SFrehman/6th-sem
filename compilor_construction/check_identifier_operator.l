%{
#include <stdio.h>
int id_count = 0, op_count = 0, valid = 1, top = -1;
char stack[100];
%}

%%
[a-zA-Z0-9_]+   { id_count++; printf("Identifier: %s\n", yytext); }
"+"|"-"|"*"|"/" { op_count++; printf("Operator: %s\n", yytext); }
"("             { top++; stack[top] = '('; }
")"             { if (top >= 0 && stack[top] == '(') { top--; } else { valid = 0; } }
.|\n            { /* Skip spaces or stray layout elements */ }
%%

int main() {
    printf("Enter arithmetic expression: ");
    yylex();
    
    if (valid == 1 && top == -1 && id_count == (op_count + 1)) {
        printf("\nExpression status: VALID\n");
        printf("Total Identifiers: %d\nTotal Operators: %d\n", id_count, op_count);
    } else {
        printf("\nExpression status: INVALID\n");
    }
    return 0;
}

int yywrap() {
    return 1;
}