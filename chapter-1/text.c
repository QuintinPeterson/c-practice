#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

#define TABSTOP 8

#define FOLDSTOP 20

void copy(char to[], char from[]);

void fold(char s[], int len);

void enTab(char s[], int len);

int get_line(char s[], int lim);

int main()
{
    int c;
    char line[MAXLINE];     
    char verified[MAXLINE];
    int len = get_line(line, MAXLINE);

    fold(line, len);
    
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void fold(char s[], int len) {
    int counter = 0;
    int last_blank = -1;
    int start = 0;

    for (int i = 0; i < len; ++i, ++counter) {
        if (s[i] == ' ' || s[i] == '\t')
            last_blank = i;

        if (counter == FOLDSTOP) {
            if (last_blank != -1) {
                /* Print up to last_blank */
                for (int j = start; j <= last_blank; ++j)
                    putchar(s[j]);
                putchar('\n');
                i = last_blank; /* restart after the blank */
                start = last_blank + 1;
                counter = 0;
                last_blank = -1;
            } else {
                /* No blank found, break at FOLDSTOP */
                for (int j = start; j <= i; ++j)
                    putchar(s[j]);
                putchar('\n');
                start = i + 1;
                counter = 0;
            }
        }
    }
    /* Print any remaining characters */
    for (int j = start; j < len; ++j)
        putchar(s[j]);
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
