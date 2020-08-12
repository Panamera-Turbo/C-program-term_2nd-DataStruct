// 树转二叉树

// 使用队列，编写transfrom函数，将普通树转换成对应的二叉树
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *left;
    struct Node *right;
} BiTNode, *BiTree;
// 普通树节点的定义如下：

#define MAX_CHILDREN_NUM 5
typedef struct _CSNode
{
    DataType data;
    struct _CSNode *children[MAX_CHILDREN_NUM];
} CSNode;
typedef struct _CSNode CSNode;
// 队列相关定义及操作如下：

typedef struct __Queue
{
    int i, j; //指向数组内元素的游标
    void **array;
} Queue;
// typedef struct __Queue Queue;

Queue *create_queue();                   //创建队列
bool is_empty_queue(Queue *tree);        //队为空返回true,不为空时返回false
void *del_queue(Queue *tree);            //结点指针出队
void add_queue(Queue *tree, void *node); //结点指针入队
void free_queue(Queue *tree);            //释放队列
// transform函数定义如下：
BiTNode* transform_queue(CSNode* root){
    Queue *t = create_queue();

    BiTNode* p = (BiTNode*)malloc(sizeof(BiTNode));

    p->data = root->data;
    if(root->children[0] == NULL)
    {
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    p->left = transform_queue(root->children[0]);
    BiTNode* q = p->left;

    for(int i = 1; root->children[i] != NULL; ++i)add(t, root->children[i]);

    while (!is_empty_queue(t))
    {
        q->right = transform_queue(t->array[t->j]);
        del_queue(t);
    }
    
    return p;
}
// 其中 root 为普通树的根结点，函数返回该树对应二叉树的根结点。
/*
BiTNode *transform(CSNode *root)
{
    int i;
    //先把root放进去
    BiTNode *node = (BiTNode*)malloc(sizeof(BiTNode));
    node->data = root->data;

    //若root是叶子,返回
    if(root->children[0] == NULL){
        node->right = NULL;
        node->left = NULL;
        return node;
    }

    //否则,左孩子是第一个孩子
    node->left = transform(root->children[0]);
    
    BiTNode* p = node->left;

    //左孩子的右孩子依次是原来的兄弟
    for (int i = 1; root->children[i] !=NULL; i++)
    {
        p->right = transform(root->children[i]);//每个孩子又递归
        p = p->right;
    }
    
    //最后一个右孩子的右边是NULL
    p->right = NULL;
    // 返回根
    return node;
}
*/
