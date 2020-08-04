
#include "common.h"
#include "seqlist.h"

int  DelList(SeqList *L,int i,ElemType *e)
/*��˳���L��ɾ����i������Ԫ�أ�����ָ�����e������ֵ��i�ĺϷ�ȡֵΪ1��i��L.last+1 */    
{ 
	int k;
	if((i<1)||(i>L->last+1))   
	{ 
		printf("ɾ��λ�ò��Ϸ�!");
		return(ERROR);
	}
	*e = L->elem[i-1];  /* ��ɾ����Ԫ�ش�ŵ�e��ָ��ı�����*/
	for(k=i; i<=L->last; k++)
		L->elem[k-1] = L->elem[k];  /*�������Ԫ������ǰ��*/
	L->last--;
	return(OK);
}

void main()
{
	SeqList *l;
	int p,r;
	int *q;
	int i;
	l = (SeqList*)malloc(sizeof(SeqList));
	q = (int*)malloc(sizeof(int));
	printf("���������Ա�ĳ���:");
	scanf("%d",&r);
	l->last = r-1;
	printf("���������Ա�ĸ�Ԫ��ֵ:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	printf("������Ҫɾ����Ԫ��λ��:\n");
	scanf("%d",&p);
	DelList(l,p,q);
	printf("ɾ����Ԫ��ֵΪ:%d\n",*q);
}
