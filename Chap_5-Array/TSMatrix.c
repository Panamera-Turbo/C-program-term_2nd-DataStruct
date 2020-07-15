#include <stdio.h>

#include "TSMatrix.h"

//------------------------------------------------------------------------------------
//转置矩阵
void TransposeTSMatrix(TSMatrix *from, TSMatrix *to)
{
    int i, j, k;

    to->m = from->n;
    to->n = from->m;
    to->len = from->len;

    if (to->len == 0)
        return;

    j = 1;  /*j为辅助计数器，记录转置后的三元组在三元组表B中的下标值*/
    for (k = 1; k <= from->n; k++) /*扫描三元组表A 共k次，每次寻找列值为k的三元组进行转置*/
        for (i = 1; i <= from->len; i++)
            if (from->data[i].col == k)
                to->data[j++] = from->data[i];
}
//------------------------------------------------------------------------------------
//快速转置
void FastTransposeTSMatrix(TSMatrix *from, TSMatrix *to)
{
    /*基于矩阵的三元组表示，采用"按位快速转置"法，将矩阵A转置为矩阵B*/
    int col, t, p, q;
    int num[MAXSIZE], position[MAXSIZE];
    to->len = from->len;
    to->n = from->m;
    to->m = from->n;
    if (to->len)
    {
        for (col = 1; col <= from->n; col++)
            num[col] = 0;
        for (t = 1; t <= from->len; t++)
            num[from->data[t].col]++; /*计算每一列的非零元素的个数*/
        position[1] = 1;
        for (col = 2; col <= from->n; col++) /*求col列中第一个非零元素在B.data[ ]中的正确位置*/
            position[col] = position[col - 1] + num[col - 1];
        for (p = 1; p <= from->len; p++) /*将被转置矩阵的三元组表A从头至尾扫描一次，实现矩阵转置*/
        {
            col = from->data[p].col;
            q = position[col];
            to->data[q] = from->data[p];
            position[col]++; /* position[col]加1，指向下一个列号为col的非零元素在三元组表B中的下标值*/
        }                    /*end of for*/
    }
}


//------------------------------------------------------------------------------------
//
void ShowTSMatrix(TSMatrix *M, const char *msg)
{
    printf("%s\n", msg);
    for (int i = 1; i <= M->len; ++i)
        printf("(%4d, %4d, %4d)\n", M->data[i].row, M->data[i].col, M->data[i].e);
}


//------------------------------------------------------------------------------------
//
void PrintfTSMatrix(TSMatrix *M, const char *msg)
{
    int i, j, k = 1;
    Triple *t;

    printf("%s\n", msg);
    for (i = 1; i <= M->m; ++i)
    {
        for (j = 1; j <= M->n; ++j)
        {
            t = &M->data[k];
            printf("%4d", t->row == i && t->col == j ? (++k, t->e) : 0);
        }
        putchar('\n');
    }
}