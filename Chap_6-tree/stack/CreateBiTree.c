#include <stdio.h>

#include "BiTree.h"

void CreateBiTree(BiTree *root, const DataType *p)
{
    static int i = 0;

    if (p[i] == '.')
    {
        *root = NULL;
        ++i;
    }
    else
    {
        *root = (BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
        (*root)->data = p[i++];
        CreateBiTree(&((*root)->LChild), p); //生成左子树
        CreateBiTree(&((*root)->RChild), p); //生成右子树
    }
}

void DestroyBiTree(BiTree root)
{
	if (root == NULL) return;
	
	DestroyBiTree(root->LChild); /*后序遍历左子树*/
	DestroyBiTree(root->RChild); /*后序遍历右子树*/
	free(root);					 /*释放结点*/
}