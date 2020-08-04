#include "common.h"
#include "seqlist.h"

void AdjustSqlist(SeqList  *L)
{
	int i=0,j=L->last;
	int temp;
	while(i<j)
	{  
		while(L->elem[i]%2 != 0)
			i++;   /*从表的左半部分开始检测，若为奇数，则i加1,直到找到偶数为止*/
	    while(L->elem[j]%2 == 0)
			j--;      /* 从表的右半部分开始检测，若为偶数，则j减1,直到找到奇数为止*/
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
	printf("请输入线性表的长度:");
	scanf("%d",&r);
	l->last = r-1;
	printf("请输入线性表的各元素值:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	printf("线性表元素为:\n");
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
	AdjustSqlist(l);
	printf("\n");
	printf("调整后的线性表元素为:\n");
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
}
