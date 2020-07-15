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

extern void CreateBiTree(BiTree *root, const DataType *p);
extern void DestroyBiTree(BiTree root);

typedef void CALLBACK(DataType); // ==> void (char)
typedef bool PREDICATE(BiTree); //谓词

extern void PreOrder(BiTree root, CALLBACK visit);
extern void PreOrder_If(BiTree root, CALLBACK visit, PREDICATE pred);
extern void PreOrder_Stack(BiTree root, CALLBACK visit);
extern void InOrder(BiTree root);
extern void PostOrder(BiTree root);
// extern static BiTree _Create(char *pre, char *in);
extern BiTree CreateBiTreeByPreIn(char *pre, char *in);