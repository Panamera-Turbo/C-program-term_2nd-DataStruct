
#include "common.h"
#include "seqlist.h"

void merge(SeqList *LA,  SeqList *LB,  SeqList *LC)
{
	int i,j,k;
	i=0;j=0;k=0;
	while(i<=LA->last&&j<=LB->last)
		if(LA->elem[i] <= LB->elem[j])
		{
			LC->elem[k]= LA->elem[i];
			i++; 
			k++;
		}
		else
		{
			LC->elem[k]=LB->elem[j];
			j++; 
			k++;
        }
	while(i<=LA->last)	
	{
		LC->elem[k]= LA->elem[i];
		i++; 
		k++;
	}
	while(j<=LB->last)  	
	{
		LC->elem[k]= LB->elem[j];
		j++; 
		k++;
	}
	LC->last=LA->last+LB->last+1;
}


void main()
{
	SeqList *la,*lb,*lc;
	int r;
	int i;
	la=(SeqList*)malloc(sizeof(SeqList));
	printf("���������Ա�A�ĳ���:");
	scanf("%d",&r);
	la->last = r-1;
	printf("���������Ա�A�ĸ�Ԫ��ֵ:\n");
	for(i=0; i<=la->last; i++)
	{
		scanf("%d",&la->elem[i]);
	}
	lb=(SeqList*)malloc(sizeof(SeqList));
	printf("���������Ա�B�ĳ���:");
	scanf("%d",&r);
	lb->last = r-1;
	printf("���������Ա�B�ĸ�Ԫ��ֵ:\n");
	for(i=0; i<=lb->last; i++)
	{
		scanf("%d",&lb->elem[i]);
	}

	lc=(SeqList*)malloc(sizeof(SeqList));

	merge(la,lb,lc);
	printf("�ϲ������Ա�C�е�Ԫ��Ϊ:\n");
	for(i=0; i<=lc->last; i++)
	{
		printf("%d  ",lc->elem[i]);
	}
}

