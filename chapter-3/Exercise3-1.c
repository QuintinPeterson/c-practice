#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{

    return 0;
}

/* binsrearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low;
    int high;
    int mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x != v[mid]) {
            if (x < v[mid])
                high = mid - 1;
            else
                low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1; /* no match */

}
