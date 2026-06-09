%{
#include <stdio.h>
int lines = 0, words = 0, spaces = 0, characters = 0;
%}

%%
\n        { lines++; characters++; }
" "       { spaces++; characters++; }
\t        { spaces += 4; characters++; }
[^\t\n ]+ { words++; characters += yyleng; }
%%

int main() {
    printf("Enter text block (Press Ctrl+Z or Ctrl+D then Enter to finish):\n");
    yylex();
    printf("\n--- Results ---\n");
    printf("Lines: %d\nWords: %d\nSpaces: %d\nCharacters: %d\n", lines, words, spaces, characters);
    return 0;
}

int yywrap() {
    return 1;
}