#include <stdio.h>

int htoi(char s[]);

int get_line(char line[], int maxline);

void copy(char to[], char from[]);

#define MAXLINE 1000 /* maximum input line size */


int main()
{
    int c;
    char line[MAXLINE];     /* current input line */
    char verified[MAXLINE];
    int len = get_line(line, MAXLINE);




    printf("%d", htoi(line));



    return 0;
}

int htoi(char s[])
{
    int i;
    int n;

    n = 0;
    for (i = 0; 
          (s[i] >= '0' && s[i] <= '9') || 
          (s[i] >= 'a' && s[i] <= 'f') || 
          (s[i] >= 'A' && s[i] <= 'F'); 
          ++i)
    {
        n = 16 * n; 
        if (s[i] >= '0' && s[i] <= '9')
            n += s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            n += s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            n += s[i] - 'A' + 10;
    }
    return n;
}

/* getline: read a line into s, return length */
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
