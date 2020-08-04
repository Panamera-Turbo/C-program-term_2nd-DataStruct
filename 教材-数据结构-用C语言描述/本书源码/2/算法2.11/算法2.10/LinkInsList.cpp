
#include "common.h"
#include "linklist.h"

int InsList(LinkList L,int i,ElemType e)
/*在带头结点的单链表L中第i个位置插入值为e的新结点s*/
{  
	Node *pre,*s;
	int k;
	pre=L;  
	k=0;                     /*从"头"开始，查找第i-1个结点*/
	while(pre!=NULL&&k<i-1)  /*表未查完且未查到第i-1个时重复，找到pre指向第i-1个*/ 
	{ 
		pre=pre->next;
		k=k+1; 
	}									/*查找第i-1结点*/
	if(!pre)      /*如当前位置pre为空表已找完还未数到第i个，说明插入位置不合理*/ 
	{ 
		printf("插入位置不合理!");
		return ERROR;
	}
	s=(Node*)malloc(sizeof(Node));   /*申请一个新的结点S */
	s->data=e;                       /*值e置入s的数据域*/
	s->next=pre->next;				/*修改指针，完成插入操作*/
	pre->next=s;
	return OK;
}

void main()
{
	LinkList l;
	Node *p;
	int flag=0;
	int i;
	char c;
	init_linklist(&l);		
	printf("请输入链表数据,以$结束!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("请输入插入的位置和元素:\n");
	scanf("%d,%c",&i,&c);
	flag=InsList(l, i, c);
	if(flag)
		printf("插入操作成功!\n");
	else
		printf("插入操作失败!\n");
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}

