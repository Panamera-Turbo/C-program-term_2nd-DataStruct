
#include "common.h"
#include "dlinklist.h"

int	DlinkDel(DoubleList L,int i,ElemType *e)
{
	DNode  *p;
	int k;
	p=L;  
	k=0;                     /*从"头"开始，查找第i个结点*/
	while(p->next!=L && k<i)  /*表未查完且未查到第i个时重复，找到p指向第i个*/ 
	{ 
		p=p->next;
		k=k+1; 
	}								
	if(p->next == L)       
	{ 
		return ERROR;
	}
	else
	{
		*e=p->data;
		p->prior->next=p->next;
		p->next->prior=p->prior;
		free(p);
		return OK;
	}
}


void main()
{
	DoubleList l;
	DNode *p;
	int i;
	int flag=0;
	char *e;
	l=(DNode * )malloc(sizeof(DNode));
	printf("请输入链表数据:\n");
	CreateList(l);
	p = l->next;
	while(p!=l)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("请输入要删除的位置:\n");
	scanf("%d",&i);
	e=(char *)malloc(sizeof(char));
	flag=DlinkDel(l,i,e);
	if(flag == 1)
	{
		printf("删除的元素是:%c\n",*e);
	}
	else
		printf("删除位置不合理!");
}


