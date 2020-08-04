
#include <stdio.h>
#include <stdlib.h>

#define ElemType char
typedef struct Node    /*������Ͷ���*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkListΪ�ṹָ������*/


LinkList CreateFromTail()
/*ͨ�������������Ԫ��ֵ������β�巨��������,�����ظõ�����ͷָ��L*/
{ 
	LinkList L;
	Node *r, *s;
	char c;
	int   flag =1; /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
	L=(Node * )malloc(sizeof(Node));     
	L->next=NULL;	 		/*Ϊͷ������洢�ռ䣬�����յĵ�����L*/
	r=L;                /*rָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬���ֵָ��ͷ���*/
	while(flag)         /*ѭ���������Ԫ��ֵ���������½��s�����β*/
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
			r->next=NULL;   /*�����һ������next������Ϊ�գ���ʾ����Ľ���*/
		}
	}  
	return L;
} 

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
	printf("��β�巨����������,��������������,��$����!\n");
    l = CreateFromTail();
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
