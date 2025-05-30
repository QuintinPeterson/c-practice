#include <stdio.h>

int get_line(char line[], int maxline);

void copy(char to[], char from[]);

void remove_trailing_blanks(char s[]);

#define MAXLINE 1000 /* maximum input line size */


int main() { 

    int c;

    char line[MAXLINE];     /* current input line */
    char verified[MAXLINE];

   while (get_line(line, MAXLINE) > 0) {
    remove_trailing_blanks(line);

    if (line[0] != '\n' && line[0] != '\0') {
        copy(verified, line);
        printf("%s", verified);
    }
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

void remove_trailing_blanks(char s[]) {
    int i = 0;
    while (s[i] != '\0')
        ++i;
    --i;

    s[i+1] = '\0';
}
