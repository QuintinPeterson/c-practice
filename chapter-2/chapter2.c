#include <stdio.h>
#include <limits.h>

int atoi(char s[]);

int lower(int c);

int rand(void);
unsigned long int next = 1;

void srand(unsigned int seed);

int main()
{
    



    return 0;
}

int atoi(char s[])
{
    int i;
    int n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c <= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

/* rand: return psuedo-random integer on 0..32767 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int) (next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
    next = seed;
}
