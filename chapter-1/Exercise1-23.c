#include <stdio.h>

#define MAXLINE 1000


/* single line comments
    else if (line[i] == '/' && line[i] == '/' && isQuotedString == -1) {
            
        }
*/


int main()
{
    int c, next;
    int in_block_comment = 0;
    int in_line_comment = 0;
    int in_string = 0;
    int in_char = 0;
    int prev = 0;

    while ((c = getchar()) != EOF) {
        if (in_block_comment) {
            if (c == '*') {
                next = getchar();
                if (next == '/') {
                    in_block_comment = 0;
                } else if (next != EOF) {
                    // Not end of comment, keep looking
                    ungetc(next, stdin);
                }
            }
            // Skip all characters inside block comment
        }
        else if (in_line_comment) {
            if (c == '\n') {
                in_line_comment = 0;
                putchar(c);
            }
            // Skip all characters until newline
        }
        else if (in_string) {
            putchar(c);
            if (c == '\\') {
                // Escape sequence, print next char too
                c = getchar();
                if (c != EOF) putchar(c);
            } else if (c == '"') {
                in_string = 0;
            }
        }
        else if (in_char) {
            putchar(c);
            if (c == '\\') {
                // Escape sequence, print next char too
                c = getchar();
                if (c != EOF) putchar(c);
            } else if (c == '\'') {
                in_char = 0;
            }
        }
        else {
            if (c == '/') {
                next = getchar();
                if (next == '*') {
                    in_block_comment = 1;
                } else if (next == '/') {
                    in_line_comment = 1;
                } else {
                    putchar(c);
                    if (next != EOF) ungetc(next, stdin);
                }
            } else if (c == '"') {
                in_string = 1;
                putchar(c);
            } else if (c == '\'') {
                in_char = 1;
                putchar(c);
            } else {
                putchar(c);
            }
        }
    }
    return 0;
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
