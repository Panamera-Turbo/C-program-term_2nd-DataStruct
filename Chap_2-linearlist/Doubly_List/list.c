#include <stdio.h>
#include <malloc.h>
#include "list_interface.h"
#include "list.h"
//---------------------------------------------------------------------------------------------------------------
void init_list(LListPtr *L)
{
    (*L) = (NodePtr)malloc(sizeof(Node));   //生成头结点
    (*L)->next = NULL;                      //头结点的后继指针域为空
	(*L)->prior = NULL;						//前驱为空
}

//---------------------------------------------------------------------------------------------------------------
bool ins_list(LListPtr L, int i, ElemType e)
{
	NodePtr p = L, q;
	int k = 1;
    
    /*从"头"开始，查找第i-1个结点*/
	while (p != NULL && k < i)              /*表未查完且未查到第i-1个时重复，找到p指向第i-1个*/ 
	{ 
		p = p->next;
		++k; 
	}
    
	if (p == NULL && k < i)                 /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return false;
	}

	q = (NodePtr)malloc(sizeof(Node));      /*申请一个新的结点S */
	q->data = e;   
	if(p->next == NULL)
	{                         /*值e置入s的数据域*/
		p->next = q;
		q->next = NULL;
		q->prior = p;
	}
	else
	{
		p = p->next;

		q->prior = p->prior;
		p->prior->next = q;
		q->next = p;
		p->prior = q;
	}
	
    return true;
}

//---------------------------------------------------------------------------------------------------------------
//待完成
bool del_list(LListPtr L, int i, ElemType *e)
{
    return true;
}
//---------------------------------------------------------------------------------------------------------------
void traverse(LListPtr L, CALLBACK f)
{
    NodePtr p = L->next;
	while (p != NULL)
	{
        f(&p->data);
        p = p->next;
	}
}
//---------------------------------------------------------------------------------------------------------------
void destroy_list(LListPtr L)
{ 
    NodePtr p = L, q;
	while (p != NULL)
	{
        q = p;
		p = p->next;
		free(q);
	}
}
