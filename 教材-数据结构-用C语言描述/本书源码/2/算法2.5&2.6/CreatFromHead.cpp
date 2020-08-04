
#include <stdio.h>
#include <stdlib.h>

#define ElemType char
typedef struct Node    /*������Ͷ���*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkListΪ�ṹָ������*/


LinkList  CreateFromHead()
/*ͨ�������������Ԫ��ֵ������ͷ�巨��������,�����ظõ�����ͷָ��L*/
{ 
	LinkList   L;
	Node   *s;
	char 	c;
	int 	flag=1;
	L=(LinkList)malloc(sizeof(Node));     /*����ͷ���*/
	L->next=NULL;                         /*�����յĵ�����L*/
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
	return L;
}

void main()
{
	LinkList l;
	Node *p;
	printf("��ͷ�巨����������,��������������,��$����!\n");
	l = CreateFromHead();
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}
