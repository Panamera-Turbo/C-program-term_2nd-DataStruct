
#include "common.h"
#include "dlinklist.h"

int DlinkIns(DoubleList L,int i,ElemType e)
{
	DNode  *s,*p;
	int k;
	p=L;  
	k=0;                     /*��"ͷ"��ʼ�����ҵ�i-1�����*/
	while(p->next!=L&&k<i)  /*��δ������δ�鵽��i-1��ʱ�ظ����ҵ�pָ���i��*/ 
	{ 
		p=p->next;
		k=k+1; 
	}									/*���ҵ�i-1���*/
	if(p->next == L)      /*�統ǰλ��pΪ�ձ������껹δ������i����˵������λ�ò�����*/ 
	{ 
		printf("����λ�ò�����!");
		return ERROR;
	}
	s=(DNode*)malloc(sizeof(DNode));
 	if (s)
	{
		s->data=e;
		s->prior=p->prior;		
		p->prior->next=s;	
		s->next=p;			
		p->prior=s;			
		return OK;
	}
	else 
		return ERROR;
}

void main()
{
	DoubleList l;
	DNode *p;
	int i;
	char e;
	l=(DNode * )malloc(sizeof(DNode));
	printf("������˫����������!:\n");
	CreateList(l);
	p = l->next;
	while(p!=l)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("���������λ�ú�Ԫ��ֵ:\n");
	scanf("%d,%c",&i,&e);
	DlinkIns(l,i,e);
	printf("����������Ϊ:\n");
	p = l->next;
	while(p!=l)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}


