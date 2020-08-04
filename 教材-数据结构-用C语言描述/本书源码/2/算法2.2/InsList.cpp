#include "common.h"
#include "seqlist.h"

/*��˳���L�е�i������Ԫ��֮ǰ����һ��Ԫ��e�� ����ǰ��n=L->last+1��
i�ĺϷ�ȡֵ��Χ�� 1��i��L->last+2  */
int  InsList(SeqList *L,int i,ElemType e)
{ 
	int k;
	if((i<1) || (i>L->last+2)) /*�����жϲ���λ���Ƿ�Ϸ�*/
	{
		printf("����λ��iֵ���Ϸ�");
		return(ERROR);
	}
	if(L->last>= MAXSIZE-1)
	{
		printf("�������޷�����");
		return(ERROR);
	}
	for(k=L->last;k>=i-1;k--)   /*Ϊ����Ԫ�ض��ƶ�λ��*/
		L->elem[k+1]=L->elem[k];
	L->elem[i-1]=e;   /*��C���������У���i��Ԫ�ص��±�Ϊi-1*/
	L->last++;
	return(OK);
}


void main()
{
	SeqList *l;
	int p,q,r;
	int i;
	l=(SeqList*)malloc(sizeof(SeqList));
	printf("���������Ա�ĳ���:");
	scanf("%d",&r);
	l->last = r-1;
	printf("���������Ա�ĸ�Ԫ��ֵ:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	printf("������Ҫ�����λ��:\n");
	scanf("%d",&p);
	printf("������Ҫ�����Ԫ��ֵ:\n");
	scanf("%d",&q);
	InsList(l,p,q);
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
}
