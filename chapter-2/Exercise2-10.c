#include <stdio.h>

int lower(int c);

int main()
{
    int c = getchar();
    printf("%c", lower(c));

    return 0;
}

int lower(int c)
{   
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}
