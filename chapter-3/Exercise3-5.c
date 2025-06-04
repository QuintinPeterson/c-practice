#include <stdio.h>
#include <string.h>
#include <ctype.h>

void itob(int n, char s[], int b);

int get_line(char line[], int maxline);

void copy(char to[], char from[]);

#define MAXLINE 1000 

int main()
{
    
    char s[100];

   
    itob(100, s, 2);
    printf("%s\n", s);
    itob(100, s, 8);
    printf("%s\n", s);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = n;
    unsigned num;

    if (n == 0) {
        s[i++] = '0';
        s[i] = '\0';
        return;
    }

    num = (n < 0) ? -n : n;

    while (num > 0) {
        int remainder = num % b;
        if (remainder < 10)
            s[i++] = '0' + remainder;
        else
            s[i++] = 'A' + (remainder-10);
        num /= b;
    }

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = s[j];
        s[j] = s[k];
        s[k] = temp;
    }
    

    
}

int get_line(char s[], int lim)
{
    int c;
    int i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
