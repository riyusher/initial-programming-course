//Write a program to count blanks, tabs, and newlines.
#include <stdio.h>

int main()
{
int c,nl,nb,nt;
nl,nb,nt = 0;
while ((c = getchar()) != EOF)
if (c == '\\n')
++nl;
if (c == ' ')
++nb;
if (c == '\\t')
++nt;
printf("%d\\n%d\\n%d\\n", nl,nb,nt);
}