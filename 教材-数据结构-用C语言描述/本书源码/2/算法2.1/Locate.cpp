
#include "common.h"
#include "seqlist.h"

int  Locate(SeqList L, ElemType e)
{	
	int i=0;        /*iΪɨ�����������ֵΪ0�����ӵ�һ��Ԫ�ؿ�ʼ�Ƚ�*/
	while ((i<=L.last)&&(L.elem[i]!=e))		/*˳��ɨ���ֱ���ҵ�ֵΪkey��Ԫ��, ��ɨ�赽��β��û�ҵ�*/
		i++; 
	if  (i<=L.last)
		return(i+1);  /*���ҵ�ֵΪe��Ԫ�أ��򷵻������*/
	else
		return(-1);  /*��û�ҵ����򷵻ؿ����*/
}

void main()
{
	SeqList l;
	int p,q,r;
	int i;
	printf("���������Ա�ĳ���:");
	scanf("%d",&r);
	l.last = r-1;
	printf("���������Ա�ĸ�Ԫ��ֵ:\n");
	for(i=0; i<=l.last; i++)
	{
		scanf("%d",&l.elem[i]);
	}
	printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
	scanf("%d",&q);
	p=Locate(l,q);
	if(p == -1)
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
	else
		printf("��Ԫ�������Ա��е�λ��Ϊ:%d\n",p);
}
