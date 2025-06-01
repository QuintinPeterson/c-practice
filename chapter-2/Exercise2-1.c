#include <stdio.h>
#include <limits.h>


int main()
{
    printf("Range of char signed is: %d to %d \n", CHAR_MIN, CHAR_MAX);
    printf("Range of char unsigned is: %d to %d \n", 0, UCHAR_MAX);
    printf("Range of short signed is: %d to %d \n", SHRT_MIN, SHRT_MAX);
    printf("Range of short unsigned is: %d to %d \n", 0, USHRT_MAX);
    printf("Range of int signed is: %d to %d \n", INT_MIN, INT_MAX);
    printf("Range of int unsigned is: %d to %u \n", 0, UINT_MAX);
    printf("Range of long signed is: %d to %d \n", LONG_MIN, LONG_MAX);
    printf("Range of long unsigned is: %d to %lu \n", 0, ULONG_MAX);


    return 0;
}
