#include <stdio.h>

void escape(char s[], char t[]);

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

    escape(all_input, verified);
    printf("%s", verified);

    
    

    return 0;
}

void escape(char s[], char t[])
{
    int i;
    int j;
    int nextIndexFull = 0;
    for (i = j = 0; s[i] != '\0'; i++) {
        switch(s[i]) {
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;

            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\\':
                if (s[i+1] == 'n') {
                    t[j++] = '\n';
                    i++;
                }
                else if (s[i+1] == 't') {
                    t[j++] = '\t';
                    i++;
                }
                else{
                    t[j++] = s[i];
                }
                break; 
            default:
                t[j++] = s[i];
                break;
            
            
        }
    }
    t[j] = '\0';

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
