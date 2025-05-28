#include <stdio.h>

int get_line(char line[], int maxline);

void copy(char to[], char from[]);

#define MAXLINE 1000 /* maximum input line size */


int main() { 

    /* print longest input line */
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char verified[MAXLINE];  /* verified line => 80 characters */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > 80) {
            max = len;
            copy(verified, line);
            printf("%s", verified);
        }

    return 0;    
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
