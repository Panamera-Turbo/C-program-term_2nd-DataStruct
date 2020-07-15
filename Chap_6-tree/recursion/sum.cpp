#include <stdio.h>

int sum1(int a[], int len)
{
    int s = 0;
    for (int i = 0; i < len; ++i)
        s += a[i];

    return s;
}

int sum2(int a[], int len)
{
    if (len == 1)
        return a[0];

    return a[0] + sum2(a + 1, len - 1);
}

int sum3(int a[], int len)
{
    if (len == 1)
        return a[0];

    int m = len >> 1;
    return sum3(a, m) + sum3(a + m, len - m);
}

int main()
{
    #define N   10
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d,%d,%d\n", sum1(x, N), sum2(x, N), sum3(x, N));

    return 0;
}