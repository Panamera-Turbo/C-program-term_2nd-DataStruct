
#include "common.h"
#include "crlinklist.h"

LinkList  merge_2(LinkList RA,LinkList RB)
{  /*���㷨����������βָ���ѭ��������β��������*/
	Node *p;
	p=RA->next; /*��������RA��ͷ����ַ*/
	RA->next=RB->next->next;/*����RB�Ŀ�ʼ�����������RA���ն˽��֮��*/
	free(RB->next);/*�ͷ�����RB��ͷ���*/
	RB->next=p;/*����RA��ͷ�����������RB���ն˽��֮��*/
    return  RB;/*������ѭ�������βָ��*/
}

void main()
{
	LinkList la,lb,lc;
	Node *p;
	printf("����ѭ������A������������!:\n");
	la=crt_linklist();
	p = la->next->next;
	while(p!=la->next)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("����ѭ������B������������!:\n");
	lb=crt_linklist();
	p = lb->next->next;
	while(p!=lb->next)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	lc=merge_2(la,lb);
	printf("�ϲ����ѭ������Ϊ:\n");
	p = lc->next->next;
	while(p!=lc->next)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
