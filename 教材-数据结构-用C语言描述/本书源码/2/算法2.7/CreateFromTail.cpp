
#include "common.h"
#include "linklist.h"

void init_linklist(LinkList *l)/*�Ե�������г�ʼ��*/
{
	*l=(LinkList)malloc(sizeof(Node)); 
	(*l)->next=NULL;
}

void CreateFromTail(LinkList L)
{ 
	Node *r, *s;
	char c;
	int   flag =1; /*����һ����־����ֵΪ1��������"$"ʱ��flagΪ0���������*/
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
} 

void main()
{
	LinkList l;
	Node *p;
	init_linklist(&l);
	printf("��β�巨����������,��������������,��$����!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}
