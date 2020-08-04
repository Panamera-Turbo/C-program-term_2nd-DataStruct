
#include <stdio.h>
#include <stdlib.h>

#define ElemType char
typedef struct Node    /*结点类型定义*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkList为结构指针类型*/


LinkList  CreateFromHead()
/*通过键盘输入表中元素值，利用头插法建单链表,并返回该单链表头指针L*/
{ 
	LinkList   L;
	Node   *s;
	char 	c;
	int 	flag=1;
	L=(LinkList)malloc(sizeof(Node));     /*建立头结点*/
	L->next=NULL;                         /*建立空的单链表L*/
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
	return L;
}

void main()
{
	LinkList l;
	Node *p;
	printf("用头插法建立单链表,请输入链表数据,以$结束!\n");
	l = CreateFromHead();
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}
