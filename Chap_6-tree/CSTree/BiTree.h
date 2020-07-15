#pragma once

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *LChild;
	struct Node *RChild;
} BiTNode, *BiTree;

typedef void CALLBACK(DataType);

extern BiTree CreateBiTree(DataType **p);
extern void DestroyBiTree(BiTree root);
extern void PreOrder(BiTree root, CALLBACK Visit);
extern void InOrder(BiTree root, CALLBACK Visit);
extern void PostOrder(BiTree root, CALLBACK Visit);

extern BiTree CreateBiTreeByPreIn(char *pre, char *in);
