#include <stdio.h>

int sum(int a[], int len)
{
    if (len == 1) return a[0];

    return a[0] + sum(a + 1, len - 1);
}
// {
//     int s = 0;
//     for (int i = 0; i < len; ++i)
//         s += a[i];

//     return s;
// }

int main()
{
    #define N   10
    int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("%d\n", sum(x, N));

    return 0;
}