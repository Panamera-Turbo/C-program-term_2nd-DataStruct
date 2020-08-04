#include "common.h"
#include "linklist.h"

void BinAdd(LinkList l)
{
	Node *q,*r,*temp,*s;
	q=l->next;
	r=l;
	while(q!=NULL)
	{
		if(q->data == 0)
			r = q;
		q = q->next;
	}
	if(r != l)
	{
		r->data = 1;
	}
	else
	{	
		temp = r->next;
		s=(Node*)malloc(sizeof(Node));
		s->data=1;
		s->next=temp;
		r->next = s;
		r = s;
	}
	r = r->next;
	while(r!=NULL)
	{
		r->data = 0;
		r = r->next;
	}
}


void main()
{
	LinkList la;
	Node *p;
	printf("请输入二进制数(以-1结束!):\n");
	la=(Node * )malloc(sizeof(Node));
	la->next = NULL;
	CreateFromTail(la);
	printf("二进制数为:\n");
	p = la->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
	printf("\n");
	BinAdd(la);
	printf("加1后的二进制数为:\n");
	p = la->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
}

