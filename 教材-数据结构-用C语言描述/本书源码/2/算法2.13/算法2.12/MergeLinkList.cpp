
#include "common.h"
#include "linklist.h"

LinkList MergeLinkList(LinkList LA, LinkList LB)
/*����������ĵ�����LA��LB�ϲ���һ����������ĵ�����LC*/
{  
	Node *pa,*pb;
	Node *r;
	LinkList LC;
/*��LC��ʼ�ÿձ�pa��pb�ֱ�ָ������������LA��LB�еĵ�һ�����,r��ֵΪLC*/
	pa=LA->next;
	pb=LB->next;
	LC=LA;
	LC->next=NULL;
	r=LC;
/*���������о�δ������ʱ���Ƚ�ѡ�񽫽�Сֵ�����뵽�±�LC�С�*/
	while(pa!=NULL && pb!=NULL)
	{
		if(pa->data <= pb->data)
		{
			r->next=pa;
			r=pa;
			pa=pa->next;
		}
		else
		{
			r->next=pb;
			r=pb;
			pb=pb->next;
		}
	}
	if(pa) /*����LAδ�꣬����LA�к���Ԫ�������±�LC��β*/
		r->next=pa;
	else	 /*���򽫱�LB�к���Ԫ�������±�LC��β*/
		r->next=pb;
	free(LB);
	return(LC);
}


void main()
{
	LinkList la,lb,lc;
	Node *p;
	la=(Node * )malloc(sizeof(Node));     
	la->next=NULL; 
	printf("�����뵥����A�е�Ԫ��(��-1����!):\n");
	CreateFromTail(la);
	printf("������A��Ԫ��Ϊ:\n");
	p = la->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
	printf("\n");

	printf("�����뵥����B�е�Ԫ��(��-1����!):\n");
	lb=(Node * )malloc(sizeof(Node));     
	lb->next=NULL; 
	CreateFromTail(lb);
	printf("������B��Ԫ��Ϊ:\n");
	p = lb->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
	printf("\n");

	lc=MergeLinkList(la,lb);
	printf("������C��Ԫ��Ϊ:\n");
	p = lc->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
}

