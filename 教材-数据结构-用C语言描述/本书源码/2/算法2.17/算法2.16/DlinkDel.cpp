
#include "common.h"
#include "dlinklist.h"

int	DlinkDel(DoubleList L,int i,ElemType *e)
{
	DNode  *p;
	int k;
	p=L;  
	k=0;                     /*��"ͷ"��ʼ�����ҵ�i�����*/
	while(p->next!=L && k<i)  /*��δ������δ�鵽��i��ʱ�ظ����ҵ�pָ���i��*/ 
	{ 
		p=p->next;
		k=k+1; 
	}								
	if(p->next == L)       
	{ 
		return ERROR;
	}
	else
	{
		*e=p->data;
		p->prior->next=p->next;
		p->next->prior=p->prior;
		free(p);
		return OK;
	}
}


void main()
{
	DoubleList l;
	DNode *p;
	int i;
	int flag=0;
	char *e;
	l=(DNode * )malloc(sizeof(DNode));
	printf("��������������:\n");
	CreateList(l);
	p = l->next;
	while(p!=l)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("������Ҫɾ����λ��:\n");
	scanf("%d",&i);
	e=(char *)malloc(sizeof(char));
	flag=DlinkDel(l,i,e);
	if(flag == 1)
	{
		printf("ɾ����Ԫ����:%c\n",*e);
	}
	else
		printf("ɾ��λ�ò�����!");
}


