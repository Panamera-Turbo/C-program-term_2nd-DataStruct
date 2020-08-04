#include "common.h"
#include "clinklist.h"

LinkList   merge_1(LinkList LA,LinkList LB)
{  /*���㷨����������ͷָ���ѭ�����������β��������*/
	Node *p, *q;
	p=LA;
	q=LB;
	while (p->next!=LA)	p=p->next;	/*�ҵ���LA�ı�β����pָ����*/
	while (q->next!=LB)	q=q->next;	/*�ҵ���LB�ı�β����qָ����*/
	q->next=LA;	/*�޸ı�LB ��βָ�룬ʹָ֮���LA ��ͷ���*/
	p->next=LB->next; /*�޸ı�LA��βָ�룬ʹָ֮���LB �еĵ�һ�����*/
	free(LB);
	return(LA);
}


void main()
{
	LinkList la,lb,lc;
	Node *p;
	printf("����ѭ������A������������!:\n");
	la=(Node*)malloc(sizeof(struct Node));
	create_clinklist(la);
	p = la->next;
	while(p!=la)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("����ѭ������B������������!:\n");
	lb=(Node*)malloc(sizeof(struct Node));
	create_clinklist(lb);
	p = lb->next;
	while(p!=lb)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	lc=merge_1(la,lb);
	printf("�ϲ����ѭ������Ϊ:\n");
	p = lc->next;
	while(p!=lc)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
