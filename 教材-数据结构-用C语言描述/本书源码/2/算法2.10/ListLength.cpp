
#include "common.h"
#include "linklist.h"

int	ListLength(LinkList L)
/*���ͷ���ĵ�����L�ĳ���*/
{   
	Node *p;
	int j;
	p=L->next;
	j=0;   /*������ŵ�����ĳ���*/
	while(p!=NULL)
	{	  
		p=p->next;
		j++;
	}
	return j;	/*jΪ��õĵ�������*/
}  

void main()
{
	LinkList l;
	Node *p;
	init_linklist(&l);		
	printf("��������������,��$����!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("�õ�����ĳ���Ϊ%d\n",ListLength(l));
}

