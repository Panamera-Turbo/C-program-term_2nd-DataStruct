
typedef int ElemType;
typedef struct Node    /*结点类型定义*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkList为结构指针类型*/

LinkList crt_linklist()/*创建尾指针表示的循环链表*/
{
	LinkList l;
	int num;
	Node *p;
	l=(Node*)malloc(sizeof(struct Node));
	l->data=-1;
	l->next=l;
	printf("请输入循环链表的元素 (以-1结束):\n");
	scanf("%d",&num);
	while(num != -1)
	{
		p=(Node*)malloc(sizeof(struct Node));
		p->data=num;
		p->next=l->next;
		l->next=p;
		scanf("%d",&num);
	}
	p=l;
	while(p->next!=l)
	{
		p=p->next;
	}
	return p;
}