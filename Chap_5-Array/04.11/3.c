/*
十字链表

十字链表相关定义如下：

typedef int ElemType;

// 非零元素结点结构
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
// #include "crosslist.h"
#define ElemType int

typedef struct OLNode
{
    int row,col;
    ElemType value;
    struct OLNode *right,*down;
}OLNode,*OLink;

// 十字链表结构
typedef struct
{
    OLink *rowhead,*colhead;
    int rows,cols,nums;
}CrossList, *PCrossList;
/*
1）实现十字链表的初始化操作：
    int init_cross_list(PCrossList L, const ElemType *A, int m, int n)

    其中 L 指向 CrossList 结构，且各成员已被初始化为0；
    A 为 ElemType 类型数组中第一个元素的地址，元素的个数为 m×n 个，按行优先存储（即A[0] 为十字链表第1行第1列的元素；
    A[1] 为第1行第2列的元素，A[n] 为第2行第1列的元素，A[n+1] 为第2行第2个元素）；
    m 表示十字链表的行数，n 表示十字链表的列数。
    init_cross_list 函数将 ElemType 数组中非0元素保存到十字链表中，函数返回非 0 元素的个数。

2）实现十字链表的删除操作：

    int del_cross_list(PCrossList L, ElemType k);
    其中 L 指向 要处理的 CrossList 结构，k 为要删除的元素；
    del_cross_list 函数删除十字链表中所有值为 k 的结点，并返回删除结点的个数。
*/
//--------------------------------------------------------------------------------------------------------------
int init_cross_list(PCrossList L, const ElemType *A, int m,int n){
    L->cols = n;
    L->rows = m;
    L->nums = 0;

    L->rowhead = (OLink*)malloc((m+1)*sizeof(OLink));
    L->colhead = (OLink*)malloc((m+1)*sizeof(OLink));

    for(int i=0; i<m; ++i)
        L->rowhead[i] = NULL;

    for(int j=0; j<n; ++j)
        L->colhead[j] = NULL;
    
    for(int k=0; k<m*n; ++k, ++L->nums)
    {
        if(A[k] == 0) continue;

        OLNode* p = (OLNode*)malloc(sizeof(OLNode));
        p->row = (k+1)/n + 1;
        p->col = (k+1)%n;
        p->value = A[k];
        p->down = NULL;
        p->right = NULL;

        if(L->rowhead[p->row-1] == NULL)
            L->rowhead[p->row-1] = p;

        if(L->rowhead[p->row-1] != NULL)
        {
            OLNode* q = L->rowhead[p->row-1];

            while(q->right != NULL && q->right->col < n)
                q = q->right;
            
            p->right = q->right;
            q->right = p;
        }

        if(L->colhead[p->col-1] == NULL)
            L->colhead[p->col-1] = p;
        
        if(L->colhead[p->col-1] != NULL)
        {
            OLNode* r = L->colhead[p->col-1];

            while (r->down != NULL && r->down->row < m)
                r = r->down;
            
            p->down = r->down;
            r->down = p;
        }
    }//end for

    return L->nums;
}

//------------------------------------------------------------------------------------------------------------

int del_cross_list(PCrossList L, ElemType k){
    int success = 0;
    int now_row, now_col;

    
    for(now_row=0; now_row<L->rows; ++now_row) 
    {
        if(L->rowhead[now_row] == NULL)
            continue;

        else
        {
            OLNode *r1, *r2;
            r1 = L->rowhead[now_row];
            r2->right = r1;
            while (r1->right != NULL)
            {
                if(r1->value != k)
                {
                    r1 = r1->right;
                    r2 = r2->right;
                    continue;
                }
                else  
                {
                    r2->right = r1->right;
                    OLNode* r3 = L->colhead[r1->col-1]; 
                    if(r3 == r1)
                        r3 = NULL;
                    while (r3->down != r1)
                        r3 = r3->down;

                    r3->down = r1->down;
                    free(r1);
                    ++success;
                }
                
            }
            
        }//end else
        
    }//end for


    return success;
}

