#pragma once

#include "../recordtype.h"

#define AVLTREE__

typedef struct node
{
	KeyType  key; /*关键字的值*/
	struct node  *lchild, *rchild;/*左右指针*/
#ifdef AVLTREE
	int bf; // balance factor, for AVL tree
#endif
} BSTNode, *BSTree;

#ifdef AVLTREE
typedef BSTNode AVLTNode;
typedef BSTree AVLTree;
#endif

extern BSTree BSTSearch(BSTree bst, KeyType key);
extern void CreateFromFile(BSTree *bst);
extern void Destroy(BSTree *bst);
extern void Found(BSTree bst, KeyType key);