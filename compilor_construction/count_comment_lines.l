%{
#include <stdio.h>
int comment_count = 0;
%}

%%
"//".************ { comment_count++; }
"/*"([^*]|\*+[^*/])*\*+"/" { comment_count++; }
.|\n                       { /* Ignore other source code */ }
%%

int main() {
    printf("Enter C code block:\n");
    yylex();
    printf("Total number of comment lines: %d\n", comment_count);
    return 0;
}

int yywrap() {
    return 1;
}