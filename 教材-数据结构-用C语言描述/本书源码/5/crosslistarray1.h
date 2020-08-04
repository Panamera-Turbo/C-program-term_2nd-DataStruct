#include <malloc.h>
#include <stdio.h>
#define NULL 0;
/*十字链表的结构类型定义如下：*/
typedef struct OLNode
{	
	int row,col;        /*非零元素的行和列下标*/
	int value;
	struct OLNode *right;  /*非零元素所在行表、列表的后继链域*/
	struct OLNode *down; 
}OLNode,* OLink;

typedef struct 
{	
	OLink *row_head;  /*行、列链表的头指针向量*/
	OLink *col_head;
	int m,n,len;               /*稀疏矩阵的行数、列数、非零元素的个数*/
}CrossList;

