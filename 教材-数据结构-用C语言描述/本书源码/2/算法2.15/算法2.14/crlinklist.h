
typedef int ElemType;
typedef struct Node    /*������Ͷ���*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkListΪ�ṹָ������*/

LinkList crt_linklist()/*����βָ���ʾ��ѭ������*/
{
	LinkList l;
	int num;
	Node *p;
	l=(Node*)malloc(sizeof(struct Node));
	l->data=-1;
	l->next=l;
	printf("������ѭ�������Ԫ�� (��-1����):\n");
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