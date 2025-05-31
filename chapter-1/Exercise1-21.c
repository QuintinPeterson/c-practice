#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

#define TABSTOP 8

void copy(char to[], char from[]);

void enTab(char s[], int len);

int get_line(char s[], int lim);

int main()
{
    int c;
    char line[MAXLINE];     
    char verified[MAXLINE];
    int len = get_line(line, MAXLINE);

    enTab(line, len);



}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void enTab(char s[], int len) {

    int count_blank = 0;

    for (int i = 0; i < len; ++i) {
        if (s[i] == ' ')
            ++count_blank;
       else {
            for (int t = 0; t < count_blank / TABSTOP; ++t)
                putchar('\t');
            for (int t = 0; t < count_blank % TABSTOP; ++t)
                putchar(' ');
            count_blank = 0;
            putchar(s[i]);
        }
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
