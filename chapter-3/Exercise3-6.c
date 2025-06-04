#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int padding);

int main()
{
    char s[100];
    itoa(10, s, 5);
    printf("%s", s);

    return 0;
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[], int padding)
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n;         /* make n positive */
    i = 0;
    do {    /* generate digits in reverse order */
        s[i++] = n % 10 + '0';      /* get next digit */
    } while ((n /= 10) > 0);        /* delete it */
    if (sign < 0)
        s[i++] = '-';
    
    for (int p = 0; p <= padding; p++)
        s[i++] = ' ';
    s[i] = '\0';
    strrev(s);

}
