/*Write a program to copy its input to its output, 
replacing each tab by \s, each backspace by \b, and each backslash by \\. 
This makes tabs and backspace visible in an unambiguos way.*/
#include <stdio.h>

int main () {
    int c = 0;
    
    while ((c = getchar()) != EOF) {
        if (c = '\\t') {
            putchar ('\\s');
        }
         if (c = '\\b') {
            putchar ('\\b');
        }
         if (c = '\\\\') {
            putchar ('\\\\');
        }
    putchar (c);
    }
}