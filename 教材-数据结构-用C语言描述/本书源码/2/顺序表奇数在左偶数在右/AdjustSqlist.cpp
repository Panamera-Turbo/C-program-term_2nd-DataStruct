#include "common.h"
#include "seqlist.h"

void AdjustSqlist(SeqList  *L)
{
	int i=0,j=L->last;
	int temp;
	while(i<j)
	{  
		while(L->elem[i]%2 != 0)
			i++;   /*�ӱ����벿�ֿ�ʼ��⣬��Ϊ��������i��1,ֱ���ҵ�ż��Ϊֹ*/
	    while(L->elem[j]%2 == 0)
			j--;      /* �ӱ���Ұ벿�ֿ�ʼ��⣬��Ϊż������j��1,ֱ���ҵ�����Ϊֹ*/
		if(i<j) 
		{
			temp = L->elem[i];
			L->elem[i]= L->elem[j];
			L->elem[j]=temp;
		}
	}
	
}

void main()
{
	SeqList *l;
	int r;
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
	printf("���Ա�Ԫ��Ϊ:\n");
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
	AdjustSqlist(l);
	printf("\n");
	printf("����������Ա�Ԫ��Ϊ:\n");
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
}
