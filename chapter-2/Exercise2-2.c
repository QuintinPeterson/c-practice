#include <stdio.h>

int get_line(char s[], int lim);

int main()
{

    


    return 0;
}


int get_line(char s[], int lim) 
{
    int c;
    int i = 0;

    while (i < lim - 1) {
        c = getchar();
        if (c == EOF) {
            break;
        }
        if (c == '\n') {
            break;
        }
        s[i] = c;
        ++i;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
