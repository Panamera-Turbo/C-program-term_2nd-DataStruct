
#include "common.h"
#include "seqlist.h"

int  DelList(SeqList *L,int i,ElemType *e)
/*在顺序表L中删除第i个数据元素，并用指针参数e返回其值。i的合法取值为1≤i≤L.last+1 */    
{ 
	int k;
	if((i<1)||(i>L->last+1))   
	{ 
		printf("删除位置不合法!");
		return(ERROR);
	}
	*e = L->elem[i-1];  /* 将删除的元素存放到e所指向的变量中*/
	for(k=i; i<=L->last; k++)
		L->elem[k-1] = L->elem[k];  /*将后面的元素依次前移*/
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
	printf("请输入线性表的长度:");
	scanf("%d",&r);
	l->last = r-1;
	printf("请输入线性表的各元素值:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	printf("请输入要删除的元素位置:\n");
	scanf("%d",&p);
	DelList(l,p,q);
	printf("删除的元素值为:%d\n",*q);
}
