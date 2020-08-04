
#include "common.h"
#include "linklist.h"

LinkList MergeLinkList(LinkList LA, LinkList LB)
/*将递增有序的单链表LA和LB合并成一个递增有序的单链表LC*/
{  
	Node *pa,*pb;
	Node *r;
	LinkList LC;
/*将LC初始置空表。pa和pb分别指向两个单链表LA和LB中的第一个结点,r初值为LC*/
	pa=LA->next;
	pb=LB->next;
	LC=LA;
	LC->next=NULL;
	r=LC;
/*当两个表中均未处理完时，比较选择将较小值结点插入到新表LC中。*/
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
	if(pa) /*若表LA未完，将表LA中后续元素链到新表LC表尾*/
		r->next=pa;
	else	 /*否则将表LB中后续元素链到新表LC表尾*/
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
	printf("请输入单链表A中的元素(以-1结束!):\n");
	CreateFromTail(la);
	printf("单链表A中元素为:\n");
	p = la->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
	printf("\n");

	printf("请输入单链表B中的元素(以-1结束!):\n");
	lb=(Node * )malloc(sizeof(Node));     
	lb->next=NULL; 
	CreateFromTail(lb);
	printf("单链表B中元素为:\n");
	p = lb->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
	printf("\n");

	lc=MergeLinkList(la,lb);
	printf("单链表C中元素为:\n");
	p = lc->next;
	while(p!=NULL)
	{
		printf("%d   ",p->data);
		p=p->next;
	}
}

