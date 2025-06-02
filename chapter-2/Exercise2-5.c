#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{

    char s1[] = "hello";
    char s2[] = "quintin"; 


    int location = any(s1, s2);

    if (location > -1)
        printf("The first location in the array where s1 appears in s2 is at: %d", location);
    else
        printf("Error: %d", location);

    return 0;
}

int any(char s1[], char s2[])
{
    int i;
    int location = -1;

    for (i = 0; (s1[i] != '\0') && location == -1; i++) {
        for (int t = 0; s2[t] != '\0'; t++) {
            if (s1[i] == s2[t]) {
                location = i;
                break;
            }
            else
                location = -1;
        }
    }   


    return location;
}
