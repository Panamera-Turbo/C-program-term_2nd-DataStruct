#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../CSTree/BiTree.h"
#include "queue.h"

#define EOL putchar('\n')
//--------------------------------------------------------------------------------------------------------------
void print(DataType e)
{
    printf("%2c", e);
}
//--------------------------------------------------------------------------------------------------------------
//判断二叉树是不是结构相同（不判断是不是节点数值相同）
bool like(BiTree t1, BiTree t2)
{ //递归函数一开始，必须先判断边界条件
    if (t1 == NULL && t2 == NULL)   //都是空显然相似
        return true;                        
    else if (t1 == NULL || t2 == NULL)//一个空一个不空，显然不等
        return false;                        

    bool LL = like(t1->LChild, t2->LChild); //开始递归了
    bool LR = like(t1->RChild, t2->RChild);

    return LL && LR;       //都成立才真
}
//--------------------------------------------------------------------------------------------------------------
//分层遍历（例如，此文件夹中的tree.png中结果为ABCDEFG……
void LayerOrder(BiTree root, CALLBACK visit)
{
    if (root == NULL)
        return; //先来判断是不是边界
    Queue q, *Q = &q;
    BiTree p;
    InitQueue(Q);

    EnterQueue(Q, root); //进队的经典操作，先进去一个，然后循环到空
    while (!IsEmpty(Q))
    {
        DeleteQueue(Q, &p);
        visit(p->data);

        if (p->LChild != NULL)
            EnterQueue(Q, p->LChild);
        if (p->RChild != NULL)
            EnterQueue(Q, p->RChild);
    }

    DestroyQueue(Q);
}

int main(int argc, char *argv[])
{
    char *const nodes1 = "ABDHL..M...E.I..CF.JN...G.K.O..";
    char *const nodes2 = "12345..6...7.8..9A.BC...D.E.F..";
    BiTree t1 = NULL, t2 = NULL;

    char *p = nodes1;
    t1 = CreateBiTree(&p);
    p = nodes2;
    t2 = CreateBiTree(&p);

    PreOrder(t1, print);
    EOL;
    PreOrder(t2, print);
    EOL;

    printf("t1 is %s t2\n", like(t1, t2) ? "like" : "not like");

    LayerOrder(t1, print);
    EOL;

    DestroyBiTree(t1);
    DestroyBiTree(t2);

    return 0;
}
