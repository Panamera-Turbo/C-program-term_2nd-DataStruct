#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 共同祖先

// 假设二叉树采用二叉链表方式存储， root指向根结点，p所指结点和q所指结点为二叉树中的两个结点，编写一个计算它们的最近的共同祖先，函数定义如下：

// 其中 root 指向二叉树的根结点，p 和 q 分别指向二叉树中的两个结点。
// 提示：在完成本题时，可利用 path 函数获取p和q两个结点到根结点之间的路径，之后再计算两条公共路径得出最近的共同祖先。path函数及栈相关定义如下：
typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;

bool path(BiTNode* root, BiTNode* node, Stack* s);

#define Stack_Size 50
typedef BiTNode* ElemType;
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

BiTNode * nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q);

void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false

BiTNode* nearest_ancestor(BiTree root, BiTNode* p, BiTNode* q)
{
    Stack S1, S2;
    init_stack(&S1);
    init_stack(&S2);

    // ElemType *px1, *px2;

    path(root, p, &S1);
    path(root, q, &S2);

    for (int i = 0; i <= S1.top && i <= S2.top; ++i)
        if (S1.elem[i] != S2.elem[i])
            return S1.elem[i - 1];

    return NULL;
}
