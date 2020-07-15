#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "BiTree.h"

//algo 6.7
BiTree CreateBiTree(DataType **p)
{
    BiTree root;

    if (**p == '.')
    {
        ++*p;
        return NULL;
    }

    root = (BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
    root->data = **p;
    ++*p;
    root->LChild = CreateBiTree(p); //生成左子树
    root->RChild = CreateBiTree(p); //生成右子树

    return root;
}

//algo 6.1
void PreOrder(BiTree root, CALLBACK Visit)
{
    if (root != NULL)
    {
        Visit(root->data);             /*访问根结点*/
        PreOrder(root->LChild, Visit); /*先序遍历左子树*/
        PreOrder(root->RChild, Visit); /*先序遍历右子树*/
    }
}

//algo 6.2
void InOrder(BiTree root, CALLBACK Visit)
{
    if (root != NULL)
    {
        InOrder(root->LChild, Visit); /*中序遍历左子树*/
        Visit(root->data);            /*访问根结点*/
        InOrder(root->RChild, Visit); /*中序遍历右子树*/
    }
}

//algo 6.3
void PostOrder(BiTree root, CALLBACK Visit)
{
    if (root != NULL)
    {
        PostOrder(root->LChild, Visit); /*后序遍历左子树*/
        PostOrder(root->RChild, Visit); /*后序遍历右子树*/
        Visit(root->data);              /*访问根结点*/
    }
}

void DestroyBiTree(BiTree root)
{
    if (root != NULL)
    {
        DestroyBiTree(root->LChild); /*后序遍历左子树*/
        DestroyBiTree(root->RChild); /*后序遍历右子树*/
        free(root);                  /*释放结点*/
    }
}

BiTree CreateBiTreeByPreIn(char *pre, char *in)
{
    return NULL;
}