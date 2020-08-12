
// 路径
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//  假设二叉树采用二叉链表方式存储， root指向根结点，node 指向二叉树中的一个结点，
//  编写函数 path，计算root到 node 之间的路径，（该路径包括root结点和 node 结点）。path 函数声明如下：

//  其中，root指向二叉树的根结点，node指向二叉树中的另一结点，s 为已经初始化好的栈，该栈用来保存函数所计算的路径，如正确找出路径，则函数返回 true，此时root在栈底，node在栈顶；如未找到，则函数返回 false, 二叉树的相关定义如下：

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *left;
    struct Node *right;
} BiTNode, *BiTree;
// 栈的相关定义及操作如下：

#define Stack_Size 50
typedef BiTNode *ElemType;
typedef struct
{
    ElemType elem[Stack_Size];
    int top;
} Stack;

void init_stack(Stack *S);        // 初始化栈
bool push(Stack *S, ElemType x);  //x 入栈
bool pop(Stack *S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack *S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack *S);          // 栈为空时返回 true，否则返回 false

bool path(BiTNode *root, BiTNode *node, Stack *s)
{
    //压栈root
    push(s,root);

    BiTNode* p, *q;
    // 判断是否node
    if(root == node) return true;

    //判断是否叶子,是否有左右节点
    if(root->left != NULL) 
        p = root->left;

    else if (root->left == NULL && root->right != NULL)
        p = root->right;
    
    else if(root->left == NULL && root->right == NULL)
    {//叶子则pop,记为p
        pop(s,p);
        if(is_empty(s))return false;

        top(s,q);
        //while 如果p是top(s)的右子树,是则继续pop,否则push右子树
        while ((p == q->right || q->right == NULL) && !is_empty(s))
        {
            pop(s,p);
            top(s,q);
        }
        //如果到了empty, return false
        if(is_empty(s)) return false;

        p = q->right;
        // push(s,p);
    }
        
    bool flag = path(p,node,s);
    if(flag) return true;
      //如果成功返回true

    return false;
}

/*
/********the following is mine. I don't know where is wrong**********

bool path(BiTNode *root, BiTNode *node, Stack *s)
{
    BiTNode*p;
    if(root == node)return true;

    push(root,s);

    bool find = false;
    if(root->left != NULL)find = path(root->left, node, s);

    if(!find && root->right != NULL)find = path(root->right,node,s);

    if(!find)pop(s,p);
    return find;
}   

bool path(BiTNode *root, BiTNode *node, Stack *s)
{
    BiTNode*p, *q;
    int i;
    q = NULL;
    p = root;

    while (p!= NULL||!is_empty(s))
    {
        while (p!=NULL) 
        {
            push(s,p);
            p = p->left;
        }

        if(!is_empty(s))
        {
            top(s,p);
            if(p->right == NULL || p->right == q)
            {
                if(p == root)return true;
                else
                {
                    q = p;
                    pop(s, p);
                    p == NULL;
                }
            }

            else p = p->right;
        }
        
    }
    return false;
}*/