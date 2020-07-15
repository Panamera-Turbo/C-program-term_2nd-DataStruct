#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "dsstring.h" 
// #include "tsmatrix.h"
//实现三元组表示的两个稀疏矩阵的加法。相关定义如下：

#define ElemType int 
#define MAXSIZE 100      //假设非零元个数的最大值为100
typedef struct {
    int i,j;			//非零元的行下标和列下标，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
    ElemType e;			//非零元的值
}Triple;

typedef struct {
    Triple data[MAXSIZE];			// 非零元三元组表
    int    m, n, len;				// 矩阵的行数、列数和非零元个数
}TSMatrix;
/*在三元组中，i 和 j 从 1 开始计数，与数学中矩阵元素的编号一致
矩阵加法函数的原型为：bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ);

pM, pN, pQ 分别指向三个矩阵，当 pM 和 pN 两个矩阵不可加时，函数返回 false，否则函数返回 true，且 pQ 指向两个矩阵的和。

*/

bool add_matrix(const TSMatrix *pM, const TSMatrix *pN, TSMatrix *pQ){
    if(pM->m != pN->m || pM->n != pN->n) return false;

    int m = 0, n = 0, k = 0;

    while(m<pM->len && n<pN->len && k<MAXSIZE)
    {
        if (pM->data[m].i == pN->data[n].i)
        {
            if(pM->data[m].j == pN->data[n].j)
            {
                pQ->data[k].e = pM->data[m].e + pN->data[n].e;
                pQ->data[k].i = pM->data[m].i;
                pQ->data[k].j = pM->data[m].j;
                ++m;
                ++n;
                ++k;
                continue;
            }
            else if (pM->data[m].j < pN->data[n].j)
            {
                pQ->data[k].e = pM->data[m].e;
                pQ->data[k].i = pM->data[m].i;
                pQ->data[k].j = pM->data[m].j;
                ++m;
                ++k;
                continue;
            }
            else if(pM->data[m].j > pN->data[n].j)
            {
                pQ->data[k].e = pN->data[n].e;
                pQ->data[k].i = pN->data[n].i;
                pQ->data[k].j = pN->data[n].j;
                ++n;
                ++k;
                continue;
            }
        }
        else if (pM->data[m].i < pN->data[n].i)
        {
                pQ->data[k].e = pM->data[m].e;
                pQ->data[k].i = pM->data[m].i;
                pQ->data[k].j = pM->data[m].j;
                ++m;
                ++k;
                continue;
        }
        else if (pM->data[m].i > pN->data[n].i)
        {
                pQ->data[k].e = pN->data[n].e;
                pQ->data[k].i = pN->data[n].i;
                pQ->data[k].j = pN->data[n].j;
                ++n;
                ++k;
                continue;
        }
    }//end while

    if(k >= MAXSIZE) return false;

    if(pM->len > pN->len)
    {
        while (m<pM->len)
        {
            pQ->data[k].i = pM->data[m].i;
            pQ->data[k].j = pM->data[m].j;
            pQ->data[k].e = pM->data[m].e;
            m++;
            k++;
        }
        
    }//end if

    if(pM->len < pN->len)
    {
        while (n < pN->len)
        {
            pQ->data[k].i = pN->data[n].i;
            pQ->data[k].j = pN->data[n].j;
            pQ->data[k].e = pN->data[n].e;
            n++;
            k++;
        }
        
    }//end if

    pQ->len = k;
    pQ->m = pM->m;
    pQ->n = pM->n;

    return true;
}
/*
矩阵A[3*5]：
  0   0  31   0   0 
  0   0  30   0   0 
  0   0   0   0   0 
矩阵B[3*5]: 
  0   0  31   0   0 
  0   0  30   0   0 
  0   0   0   0   0 

add_matrix 执行后所返回结果中三元组个数应该为“2”，但现在是“3”，请修改。

add_matrix 执行后所返回结果中三元组个数应该为“2”，但现在是“6”，请修改。

add_matrix 执行后所返回结果中三元组 data[0] 的值应该是“(2, 1, 82)”,但现在是“(1, 1, 0)”，请修改。

add_matrix 执行后所返回结果中三元组个数应该为“0”，但现在是“1”，请修改。
*/

