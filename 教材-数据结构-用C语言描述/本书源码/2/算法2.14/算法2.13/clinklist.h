
typedef int ElemType;
typedef struct Node    /*������Ͷ���*/ 
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  /* LinkListΪ�ṹָ������*/

void create_clinklist(LinkList l)/*����ѭ������*/
{
	int num;
	Node *p;
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
}
