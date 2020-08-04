
#include "common.h"
#include "crlinklist.h"

LinkList  merge_2(LinkList RA,LinkList RB)
{  /*此算法将两个采用尾指针的循环链表首尾连接起来*/
	Node *p;
	p=RA->next; /*保存链表RA的头结点地址*/
	RA->next=RB->next->next;/*链表RB的开始结点链到链表RA的终端结点之后*/
	free(RB->next);/*释放链表RB的头结点*/
	RB->next=p;/*链表RA的头结点链到链表RB的终端结点之后*/
    return  RB;/*返回新循环链表的尾指针*/
}

void main()
{
	LinkList la,lb,lc;
	Node *p;
	printf("建立循环链表A，请输入数据!:\n");
	la=crt_linklist();
	p = la->next->next;
	while(p!=la->next)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("建立循环链表B，请输入数据!:\n");
	lb=crt_linklist();
	p = lb->next->next;
	while(p!=lb->next)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	lc=merge_2(la,lb);
	printf("合并后的循环链表为:\n");
	p = lc->next->next;
	while(p!=lc->next)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}
