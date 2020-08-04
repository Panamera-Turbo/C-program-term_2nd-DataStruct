
#include "common.h"
#include "linklist.h"

int	ListLength(LinkList L)
/*求带头结点的单链表L的长度*/
{   
	Node *p;
	int j;
	p=L->next;
	j=0;   /*用来存放单链表的长度*/
	while(p!=NULL)
	{	  
		p=p->next;
		j++;
	}
	return j;	/*j为求得的单链表长度*/
}  

void main()
{
	LinkList l;
	Node *p;
	init_linklist(&l);		
	printf("请输入链表数据,以$结束!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("该单链表的长度为%d\n",ListLength(l));
}

