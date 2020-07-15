#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
} BiTNode, *BiTree;

typedef void CALLBACK(DataType);			//定义回调函数,CALLBACK是函数的同义语
typedef bool PREDICATE(BiTree);				//定义判断函数。定义返回值为bool的函数叫做谓词predicate

extern void CreateBiTree(BiTree *root, const DataType *p);
extern void DestroyBiTree(BiTree root);
extern void PreOrder(BiTree root, CALLBACK visit);			//DLR先序遍历
extern void InOrder(BiTree root, CALLBACK visit);			//LDR中序遍历
extern void PostOrder(BiTree root, CALLBACK visit);			//LRD后序遍历
extern bool isLeaf(BiTree root);						//判断函数
extern void PreOrder_IfLeaf(BiTree root, CALLBACK visit, PREDICATE pred);				

// int *total = 0;
