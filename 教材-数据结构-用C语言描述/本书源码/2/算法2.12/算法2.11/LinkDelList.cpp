
#include "common.h"
#include "linklist.h"

int DelList(LinkList L,int i,ElemType *e)
/*�ڴ�ͷ���ĵ�����L��ɾ����i��Ԫ�أ�����ɾ����Ԫ�ر��浽����*e��*/
{  
	Node *pre,*r;
	int k;
	pre=L;
	k=0;
	while(pre->next!=NULL && k<i-1)	/*Ѱ�ұ�ɾ�����i��ǰ�����i-1ʹpָ����*/
	{ 
		pre=pre->next; 
		k=k+1;
	}								/*���ҵ�i-1�����*/
	if(!(pre->next))     /* ��whileѭ������Ϊp->next=NULL��i<1��������,������Ϊû���ҵ��Ϸ���ǰ��λ�ã�˵��ɾ��λ��i���Ϸ���*/
	{
		printf("ɾ������λ��i������!");
		return ERROR;
	}
	r=pre->next;
	pre->next=pre->next->next;    /*�޸�ָ�룬ɾ�����r*/
	*e = r->data;
	free(r);    /*�ͷű�ɾ���Ľ����ռ���ڴ�ռ�*/
	printf("�ɹ�ɾ�����!");
	return OK;
}

void main()
{
	LinkList l;
	Node *p;
	int i;
	char *c;
	l=(Node * )malloc(sizeof(Node));     
	l->next=NULL; 		
	printf("��������������,��$����!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	i = 3;
	c = (char*)malloc(sizeof(char));
	DelList(l,i,c);
	printf("��ɾ����Ԫ����:%c\n",*c);
}

