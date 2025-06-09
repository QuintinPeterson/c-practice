#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main()
{
    char s[] = "123.45e-6";
    printf("%f\n", atof(s));
    return 0;
}

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign, exp_sign = 1, exponent = 0;

    for (i = 0; isspace(s[i]); i++) /* skips whitespace */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    // Handle scientific notation
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (s[i] == '-') {
            exp_sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        for (exponent = 0; isdigit(s[i]); i++)
            exponent = 10 * exponent + (s[i] - '0');
        val *= pow(10, exp_sign * exponent);
    }

    return val;
}
