#include "common.h"
#include "clinklist.h"

LinkList   merge_1(LinkList LA,LinkList LB)
{  /*此算法将两个采用头指针的循环单链表的首尾连接起来*/
	Node *p, *q;
	p=LA;
	q=LB;
	while (p->next!=LA)	p=p->next;	/*找到表LA的表尾，用p指向它*/
	while (q->next!=LB)	q=q->next;	/*找到表LB的表尾，用q指向它*/
	q->next=LA;	/*修改表LB 的尾指针，使之指向表LA 的头结点*/
	p->next=LB->next; /*修改表LA的尾指针，使之指向表LB 中的第一个结点*/
	free(LB);
	return(LA);
}


void main()
{
	LinkList la,lb,lc;
	Node *p;
	printf("建立循环链表A，请输入数据!:\n");
	la=(Node*)malloc(sizeof(struct Node));
	create_clinklist(la);
	p = la->next;
	while(p!=la)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("建立循环链表B，请输入数据!:\n");
	lb=(Node*)malloc(sizeof(struct Node));
	create_clinklist(lb);
	p = lb->next;
	while(p!=lb)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	lc=merge_1(la,lb);
	printf("合并后的循环链表为:\n");
	p = lc->next;
	while(p!=lc)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
