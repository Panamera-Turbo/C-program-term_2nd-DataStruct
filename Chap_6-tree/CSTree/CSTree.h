#pragma once

#include "BiTree.h"

typedef char DataType;

typedef struct CSNode
{
	DataType data;
	struct CSNode *FirstChild;
	struct CSNode *NextSibling;
} CSNode, *CSTree;

typedef void CALLBACK(DataType);

extern CSTree CreateCSTree(DataType **p);
extern void DestroyCSTree(CSTree root);
extern void RootFirst(CSTree root, CALLBACK Visit);
extern void RootLast(CSTree root, CALLBACK Visit);
extern BiTree CS2Bi(CSTree rootCS);