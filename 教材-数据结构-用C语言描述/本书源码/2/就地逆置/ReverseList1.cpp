
#include "common.h"
#include "linklist.h"

void  ReverseList(LinkList  L)
{ 
	Node *p,*q;
	p=L->next;
	L->next=NULL;
	while(p!=NULL)
	{ 
		q=p->next;     /*qָ�뱣��p->next��ֵ*/
		p->next=L->next;
		L->next=p;    /*��p���ͷ���뵽������L��*/
		p=q;          /*pָ����һ��Ҫ����Ľ��*/
	} 
}

void main()
{
	LinkList l;
	Node *p;
	l=(Node * )malloc(sizeof(Node));
	l->next = NULL;
	printf("��β�巨����������,��������������,��$����!\n");
    CreateFromTail(l);
	printf("����ĵ�����Ϊ:\n");
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	ReverseList(l);
	printf("���ú�ĵ�����Ϊ:\n");
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}
