#include "linklist.h"
void init_linklist(LinkList *l)/*�Ե�������г�ʼ��*/
{
	*l=(LinkList)malloc(sizeof(Node)); /*������ռ�*/
	(*l)->next=NULL;                   /*��Ϊ�ձ�*/
}

main()
{
  LinkList l;
  init_linklist(&l);
}