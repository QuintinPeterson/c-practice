#include <stdio.h>

#define TABSTOP 8

int main()
{
    int c;

    while((c = getchar()) != EOF) {
        if (c == '\t')
            for (int i = 0; i <= TABSTOP; ++i)
                putchar(' ');
        else
            putchar(c);
    }





}
