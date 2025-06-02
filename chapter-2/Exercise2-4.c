#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "colour";
    char s2[] = "color";

    squeeze(s1, s2);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i;
    int j;

    for (i = j = 0; s1[i] != '\0'; i++) {
        int found = 0;
        for (int t = 0; s2[t] != '\0'; t++) {
            if (s1[i] == s2[t]) {
                found = 1;
                break;
            }
        }
        if (!found)
            s1[j++] = s1[i];
    }    
    s1[j] = '\0';

    printf("%s", s1);
}
