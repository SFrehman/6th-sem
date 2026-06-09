%{
#include <stdio.h>
int ch_count = 0;
int line_count = 0;
%}

%%
\n      { line_count++; ch_count++; }
.       { ch_count++; }
%%

int main() {
    yylex();
    printf("Lines: %d, Characters: %d\n", line_count, ch_count);
    return 0;
}

int yywrap() {
    return 1;
}