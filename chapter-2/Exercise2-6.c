#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, int y);

int main()
{

    return 0;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
    // Step 1: Create mask for n bits at position p
    unsigned mask = ((1U << n) - 1) << (p + 1 - n);

    // Step 2: Clear those bits in x
    x = x & ~mask;

    // Step 3: Get rightmost n bits from y and shift into position
    y = (y & ((1U << n) - 1)) << (p + 1 - n);

    // Step 4: Combine
    return x | y;
}
