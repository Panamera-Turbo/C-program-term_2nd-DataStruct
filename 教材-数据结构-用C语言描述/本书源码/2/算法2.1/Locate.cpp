
#include "common.h"
#include "seqlist.h"

int  Locate(SeqList L, ElemType e)
{	
	int i=0;        /*i为扫描计数器，初值为0，即从第一个元素开始比较*/
	while ((i<=L.last)&&(L.elem[i]!=e))		/*顺序扫描表，直到找到值为key的元素, 或扫描到表尾而没找到*/
		i++; 
	if  (i<=L.last)
		return(i+1);  /*若找到值为e的元素，则返回其序号*/
	else
		return(-1);  /*若没找到，则返回空序号*/
}

void main()
{
	SeqList l;
	int p,q,r;
	int i;
	printf("请输入线性表的长度:");
	scanf("%d",&r);
	l.last = r-1;
	printf("请输入线性表的各元素值:\n");
	for(i=0; i<=l.last; i++)
	{
		scanf("%d",&l.elem[i]);
	}
	printf("请输入要查找的元素值:\n");
	scanf("%d",&q);
	p=Locate(l,q);
	if(p == -1)
		printf("在此线性表中没有该元素!\n");
	else
		printf("该元素在线性表中的位置为:%d\n",p);
}
