#include "common.h"
#include "linklist.h"

void init_linklist(LinkList *l)/*�Ե�������г�ʼ��*/
{
	*l=(LinkList)malloc(sizeof(Node)); 
	(*l)->next=NULL;
}


void CreateFromHead(LinkList  L)
{ 
	Node   *s;
	char 	c;
	int 	flag=1;
 	while(flag)   /* flag��ֵΪ1��������"$"ʱ����flagΪ0���������*/
	{
		c=getchar();   
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node)); /*�����½��s*/
			s->data=c;
			s->next=L->next;/*��s�������ͷ*/
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
	printf("��ͷ�巨����������,��������������,��$����!\n");
	CreateFromHead(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}
