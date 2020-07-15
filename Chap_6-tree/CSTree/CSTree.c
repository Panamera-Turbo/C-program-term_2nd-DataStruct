#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "CSTree.h"
//-------------------------------------------------------------------------------------------------------
CSTree CreateCSTree(DataType **p)
{
    CSTree root;

    if (**p == '.')
    {
        ++*p;
        return NULL;
    }

    root = (CSTree)malloc(sizeof(CSNode)); //生成一个新结点
    root->data = **p;
    ++*p;
    root->FirstChild = CreateCSTree(p); //生成左子树
    root->NextSibling = CreateCSTree(p); //生成右子树
    
    return root;
}
//-------------------------------------------------------------------------------------------------------
void DestroyCSTree(CSTree root)
{
    if (root != NULL)
    {
        DestroyCSTree(root->FirstChild); /*后序遍历左子树*/
        DestroyCSTree(root->NextSibling); /*后序遍历右子树*/
        free(root);                  /*释放结点*/
    }
}
//-------------------------------------------------------------------------------------------------------
//P187
void RootFirst(CSTree root, CALLBACK Visit)
///先根遍历，相当于二叉树的前序遍历
{
    if (root == NULL)
        return;

    Visit(root->data);
    RootFirst(root->FirstChild, Visit);
    RootFirst(root->NextSibling, Visit);
}
//-------------------------------------------------------------------------------------------------------
//后根遍历，相当于二叉树的中序遍历
void RootLast(CSTree root, CALLBACK Visit)
{
    if (root == NULL)
        return;

    RootFirst(root->FirstChild, Visit);
    Visit(root->data);
    RootFirst(root->NextSibling, Visit);
}
//-------------------------------------------------------------------------------------------------------
BiTree CS2Bi(CSTree rootCS)
{
    return NULL;
}