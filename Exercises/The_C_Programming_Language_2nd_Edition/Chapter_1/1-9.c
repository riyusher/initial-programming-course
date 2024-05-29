//Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
#include <stdio.h>

int main() {
    int c = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == '\\n' && c > '\\n') {
            putchar('\\n');
        }
    putchar(c);
    }
    
}