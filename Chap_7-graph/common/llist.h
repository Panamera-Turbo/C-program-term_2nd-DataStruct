#pragma once

#include <stdbool.h>

#define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/

typedef char ElemType;
typedef ElemType* ElemPtr;

typedef  struct
{ 
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间*/
	int       last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
} SeqList, LList, *LListPtr;

typedef void CALLBACK(ElemPtr e);

extern void InitList(LListPtr L);
extern int ListLength(LListPtr L);
extern void* Locate(LListPtr L, ElemType e);
extern bool InsList(LListPtr L, int i, ElemType e);
extern bool DelList(LListPtr L, int i, ElemPtr e);
extern void ClearList(LListPtr L);
extern void DestroyList(LListPtr L);
extern void Traverse(LListPtr L, CALLBACK f);

extern bool AddTail(LListPtr L, ElemType e);
extern void JoinList(LListPtr La, LListPtr Lb, LListPtr Lc);