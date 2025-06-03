#include <stdio.h>

void escape(char s[], char t[]);

int get_line(char line[], int maxline);

void copy(char to[], char from[]);

#define MAXLINE 1000 /* maximum input line size */

int main()
{
    char line[MAXLINE];     /* current input line */
    char verified[MAXLINE];
    get_line(line, MAXLINE);

    escape(line, verified);
    

    return 0;
}

void escape(char s[], char t[])
{
    int i;
    int nextIndexFull = 0;
    for (i = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\n':
                t[i++] = '\\';
                t[i] = 'n';
                nextIndexFull = 1;

            case '\t':
                t[i++] = '\\';
                t[i] = 't';
                nextIndexFull = 1;
            default:
            if (nextIndexFull) {
                t[++i] = s[i];
                nextIndexFull = 0;
            }
            else {
                t[i] = s[i];
                nextIndexFull = 0;
            }
        }
    }
    printf("%s", t);

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
