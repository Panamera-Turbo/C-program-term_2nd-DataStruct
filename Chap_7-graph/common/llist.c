#include <stdio.h>

#include "llist.h"

void InitList(LListPtr L)
{
	L->last = 0;
}

int ListLength(LListPtr L)
{
	return L->last;
}

//algo 2.1
void *Locate(LListPtr L, ElemType e)
{
	int i = 0; /*i为扫描计数器，初值为0，即从第一个元素开始比较*/

	while (i <= L->last && L->elem[i] != e) /*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++;
	return i <= L->last ? L->elem + i : NULL;
}

//algo 2.2
bool InsList(LListPtr L, int i, ElemType e)
{
	int k;

	if ((i < 1) || (i > L->last + 2)) /*首先判断插入位置是否合法*/
	{
		printf("插入位置i值不合法");
		return false;
	}
	if (L->last >= MAXSIZE - 1)
	{
		printf("表已满无法插入");
		return false;
	}
	for (k = L->last; k >= i - 1; k--) /*为插入元素而移动位置*/
		L->elem[k + 1] = L->elem[k];
	L->elem[i - 1] = e; /*在C语言数组中，第i个元素的下标为i-1*/
	L->last++;

	return true;
}

//algo 2.3
bool DelList(LListPtr L, int i, ElemPtr e)
{
	int k;
	if ((i < 1) || (i > L->last + 1))
	{
		printf("删除位置不合法!");
		return false;
	}
	*e = L->elem[i - 1]; /* 将删除的元素存放到e所指向的变量中*/
	for (k = i; k <= L->last; k++)
		L->elem[k - 1] = L->elem[k]; /*将后面的元素依次前移*/
	L->last--;
	return true;
}

void ClearList(LListPtr L)
{
	L->last = 0;
}

void DestroyList(LListPtr L)
{
}

void Traverse(LListPtr L, CALLBACK f)
{
	int i;

	for (i = 0; i < L->last; ++i)
		f(&L->elem[i]);
}

bool AddTail(LListPtr L, ElemType e)
{
	return InsList(L, L->last + 1, e);
}

void JoinList(LListPtr La, LListPtr Lb, LListPtr Lc)
{
	int i, j;

	for (i = 0; i < La->last; ++i)
		Lc->elem[i] = La->elem[i];
	for (--i, j = 0; j < Lb->last; ++i, ++j)
		Lc->elem[i] = Lb->elem[j];
	Lc->last = i;
}