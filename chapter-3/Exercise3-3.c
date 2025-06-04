#include <stdio.h>
#include <ctype.h>
#include <string.h>

void expand(char s1[], char s2[]);

int get_line(char line[], int maxline);

void copy(char to[], char from[]);

#define MAXLINE 1000 /* maximum input line size */

int main()
{
    char all_input[MAXLINE];
    char verified[MAXLINE];
    int len = 0, n;

    // Read all input into all_input
    while ((n = get_line(all_input + len, MAXLINE - len)) > 0) {
        len += n;
    }

    expand(all_input, verified);
    printf("%s", verified);

    return 0;
}

void expand(char s1[], char s2[])
{
    int i;
    int j;
    int t;
    for (i = 0; s1[i] != '\0'; i++) {
        if (i > 0 && s1[i] == '-' && s1[i+1] != '\0' && 
              (isdigit(s1[i]) && s1[i+1] == '-' && isdigit(s1[i+2])) || 
                (isalpha(s1[i]) && s1[i+1] == '-' && isalpha(s1[i+2])))
            for (t = 0, j = s1[i]; j <= s1[i+2]; j++, t++)
                s2[t] = j;
            
    }
    s2[t++] = '\0';


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
