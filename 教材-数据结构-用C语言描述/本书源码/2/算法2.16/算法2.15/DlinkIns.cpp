
#include "common.h"
#include "dlinklist.h"

int DlinkIns(DoubleList L,int i,ElemType e)
{
	DNode  *s,*p;
	int k;
	p=L;  
	k=0;                     /*从"头"开始，查找第i-1个结点*/
	while(p->next!=L&&k<i)  /*表未查完且未查到第i-1个时重复，找到p指向第i个*/ 
	{ 
		p=p->next;
		k=k+1; 
	}									/*查找第i-1结点*/
	if(p->next == L)      /*如当前位置p为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return ERROR;
	}
	s=(DNode*)malloc(sizeof(DNode));
 	if (s)
	{
		s->data=e;
		s->prior=p->prior;		
		p->prior->next=s;	
		s->next=p;			
		p->prior=s;			
		return OK;
	}
	else 
		return ERROR;
}

void main()
{
	DoubleList l;
	DNode *p;
	int i;
	char e;
	l=(DNode * )malloc(sizeof(DNode));
	printf("请输入双向链表数据!:\n");
	CreateList(l);
	p = l->next;
	while(p!=l)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("情输入插入位置和元素值:\n");
	scanf("%d,%c",&i,&e);
	DlinkIns(l,i,e);
	printf("插入后的链表为:\n");
	p = l->next;
	while(p!=l)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}


