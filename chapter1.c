#include <stdio.h>

// testing git alias

/*
int power(int m, int n);
*/

float fahrCelsius(float fahr);

int main() { 
    float fahr;
    float celsius;
    int lower = 0;
    int upper = 300;
    int step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahrCelsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }








/*
    int i;

    for (i = 0; i < 10; ++i)
        printf("%d %d %d \n", i, power(2,1), power(-3,i));
*/
    return 0;    
}

float fahrCelsius(float fahr){
    float celsius;
    celsius = (5.0/9.0) * (fahr - 32.0);
    return celsius;
    
}

/*
int power(int base, int n) {
    int i;
    int p;

    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
*/

/*
    int c;
    int i;
    int nwhite;
    int nother;
    int ndigit[10];

    nwhite = 0;
    nother = 0;

    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
*/
/*
    int c;
    int freq[128] = {0};

    while((c = getchar()) != EOF) 
        ++freq[c];

    for (int i = 0; i < 128; ++i){
        if (freq[i] > 0){
            printf("\n%c: ", i);
            for (int j = 0; j < freq[i]; ++j){
                putchar('*');
            }
        }
    }
*/ 