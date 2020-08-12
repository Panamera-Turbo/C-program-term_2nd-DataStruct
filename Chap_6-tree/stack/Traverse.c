#include "BiTree.h"
#include "stack.h"
#include <string.h>
//---------------------------------------------------------------------------------------------------------
void PreOrder(BiTree root, CALLBACK visit)
{
    if (root == NULL) return;

    //printf("%2c", root->data); //visit(root)
    visit(root->data);
    PreOrder(root->LChild, visit);
    PreOrder(root->RChild, visit);
}
//---------------------------------------------------------------------------------------------------------
void PreOrder_Stack(BiTree root, CALLBACK visit){
    Stack s, *S = &s;
    BiTree p;

    InitStack(S);
    Push(S, root);

    while (!IsEmpty(S))
    {
        Pop(S, &p);

        visit(p->data);

        if(p->RChild != NULL)
            Push(S, p->RChild);  

        if(p->LChild != NULL)
            Push(S, p->LChild);   //先压入右子树，再压入左子树
    }
    
}
//---------------------------------------------------------------------------------------------------------
void InOrder(BiTree root)
{
    if (root == NULL) return;

    InOrder(root->LChild);
    printf("%c", root->data); //visit(root)
    InOrder(root->RChild);
}
//---------------------------------------------------------------------------------------------------------
void PostOrder(BiTree root)
{
    if (root == NULL) return;

    PostOrder(root->LChild);
    PostOrder(root->RChild);
    printf("%c", root->data); //visit(root)
}
//---------------------------------------------------------------------------------------------------------
void PreOrder_If(BiTree root, CALLBACK visit, PREDICATE pred)
{
    if (root == NULL) return;

    if (pred(root))
        visit(root->data);

    PreOrder_If(root->LChild, visit, pred);
    PreOrder_If(root->RChild, visit, pred);
}
//---------------------------------------------------------------------------------------------------------
static BiTree _Create(char *pre, char *in)
{//利用字符串生成树
    BiTNode *root;
    int j;
    
    if (*in == '\0') return NULL; //处理到了叶节点
    
    for (j = 0; in[j] != *pre; ++j); //找到本次处理的根节点在中序遍历里的位置
    in[j++] = '\0';                  //在这位置将中序序列分成两部分：左子树和右子树

    root = (BiTNode*)malloc(sizeof(BiTNode)); //生成本次的根节点并填充数据
    root->data = *pre;
    root->LChild = _Create(pre + 1, in);     //递归生成左子树
    root->RChild = _Create(pre + j, in + j); //递归生成右子树

    return root; 
}
//
BiTree CreateBiTreeByPreIn(char *pre, char *in)
{
    char *t;
    BiTree root;

    t = (char *)malloc(strlen(in) + 1);
    strcpy(t, in);

    root = _Create(pre, t);

    free(t);

    return root;
}
