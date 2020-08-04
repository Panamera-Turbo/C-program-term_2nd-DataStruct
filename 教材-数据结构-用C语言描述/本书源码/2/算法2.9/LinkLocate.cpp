
#include "common.h"
#include "linklist.h"

Node *Locate( LinkList L,ElemType key)
/*在带头结点的单链表L中查找其结点值等于key的结点，若找到则返回该结点的位置p，否则返回NULL*/ 
{ 
	Node *p;
	p=L->next;    /*从表中第一个结点开始 */
	while (p!=NULL)
	{
		if (p->data!=key)
			p=p->next; 
		else  
			break;      /*找到结点值=key时退出循环 */
	}
	return p;
} 

void main()
{
	LinkList l;
	Node *p;
	char c;
	init_linklist(&l); 		
	printf("请输入链表数据,以$结束!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("请输入要查找的元素值:\n");
	fflush(stdin);
	scanf("%c",&c);
	p = Locate(l,c);
	if(p!=NULL)
		printf("该结点的值为:%c\n",p->data);
	else
		printf("未找到此结点!\n");
}

