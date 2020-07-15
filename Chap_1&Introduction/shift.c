#include <stdio.h>
/************************************
 * 将字符串循环移动n位输出
 * *********************************/
#define N   9
//--------------------------------------------------
void print(int x[], int n)
{
    for (int i = 0; i < n; ++i) printf("%4d", x[i]);
    printf("\n");
}
//---------------------------------------------------
void shift(int x[], int n, int m)
{
    int t;

    while (m-- > 0)
    {
        t = x[0];       //用来存储变量，避免移动时被覆盖
        for (int i = 1; i < n; ++i)
            x[i-1] = x[i];
        x[n-1] = t;
    }
}
//----------------------------------------------------
int main()
{
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num;

    print(a, N);
    printf("输入移动位数：\n");
    scanf("%d",&num);
    shift(a, N, num);

    print(a, N);

    return 0;
}