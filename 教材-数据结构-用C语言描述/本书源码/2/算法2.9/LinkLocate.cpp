
#include "common.h"
#include "linklist.h"

Node *Locate( LinkList L,ElemType key)
/*�ڴ�ͷ���ĵ�����L�в�������ֵ����key�Ľ�㣬���ҵ��򷵻ظý���λ��p�����򷵻�NULL*/ 
{ 
	Node *p;
	p=L->next;    /*�ӱ��е�һ����㿪ʼ */
	while (p!=NULL)
	{
		if (p->data!=key)
			p=p->next; 
		else  
			break;      /*�ҵ����ֵ=keyʱ�˳�ѭ�� */
	}
	return p;
} 

void main()
{
	LinkList l;
	Node *p;
	char c;
	init_linklist(&l); 		
	printf("��������������,��$����!\n");
	CreateFromTail(l);
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
	fflush(stdin);
	scanf("%c",&c);
	p = Locate(l,c);
	if(p!=NULL)
		printf("�ý���ֵΪ:%c\n",p->data);
	else
		printf("δ�ҵ��˽��!\n");
}

