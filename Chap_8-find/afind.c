#include <stdio.h>

#define N   10

int sfind(int a[], int len, int key)
{
    for (int *p = a; p != &a[len]; ++p)
        if (*p == key) return p - a;
    // for (int i = 0; i < len; ++i)
    //     if (key == a[i]) return i;

    return -1;
}

int bfind(int a[], int len, int key)
{
    int l, h, m;

    l = 0;
    h = len - 1;
    while (l <= h)
    {
        m = (l + h) / 2; // m = (l + h) >> 1;
        if (key == a[m]) return m;
        else if (key < a[m]) h = m - 1;
        else l = m + 1;
    }

    return -1;
}

int main()
{
    int x[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 5;

    printf(sfind(x, N, k) >= 0 ? "sfind found\n" : "sfind not found\n");
    printf(bfind(x, N, k) >= 0 ? "bfind found\n" : "bfind not found\n");

    return 0;
}