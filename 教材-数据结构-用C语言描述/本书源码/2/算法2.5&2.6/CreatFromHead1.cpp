#include "common.h"
#include "linklist.h"

void init_linklist(LinkList *l)/*对单链表进行初始化*/
{
	*l=(LinkList)malloc(sizeof(Node)); 
	(*l)->next=NULL;
}


void CreateFromHead(LinkList  L)
{ 
	Node   *s;
	char 	c;
	int 	flag=1;
 	while(flag)   /* flag初值为1，当输入"$"时，置flag为0，建表结束*/
	{
		c=getchar();   
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node)); /*建立新结点s*/
			s->data=c;
			s->next=L->next;/*将s结点插入表头*/
			L->next=s;
		}
		else
			flag=0;
	}
}

void main()
{
	LinkList l;
	Node *p;
	init_linklist(&l);
	printf("用头插法建立单链表,请输入链表数据,以$结束!\n");
	CreateFromHead(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}
