
#include "common.h"
#include "linklist.h"

Node * Get (LinkList  L, int i)
/*�ڴ�ͷ���ĵ�����L�в��ҵ�i����㣬���ҵ�(1��i��n)���򷵻ظý��Ĵ洢λ��; ���򷵻�NULL*/
{  
	int j;
	Node  *p;
	p=L;
	j=0;   /*��ͷ��㿪ʼɨ��*/ 
	while ((p->next!=NULL)&&(j<i))
	{ 
		p=p->next;    /* ɨ����һ���*/
		j++;   /* ��ɨ��������� */
	}
	if(i == j)
		return p;   /* �ҵ��˵�i����� */
	else 
		return NULL;   /* �Ҳ�����i��0��i>n */
}   


void main()
{
	LinkList l;
	Node *p;
	int j;
	init_linklist(&l);
	printf("��������������,��$����!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("������Ҫ���ҵĽ�����:\n");
	scanf("%d",&j);
	p = Get(l,j);
	if(p!=NULL)
		printf("�ý���ֵΪ:%c\n",p->data);
	else
		printf("δ�ҵ��˽��!\n");
}

