#include<stdio.h>
#include<stdlib.h>

#define  Maxsize 100
#define  ElemType char

typedef  struct
{	
	ElemType data;
	int cursor;
}Component, StaticList[Maxsize];

void initial(StaticList space, int *av)
{
    int k;
	space[0].cursor=0;      /*�������þ�̬�������ͷָ��ָ��λ��0*/
	for(k=0;k<Maxsize-1;k++)
		space[k].cursor=k+1;    /*����*/
	space[Maxsize-1].cursor=0;    /*�����β*/
	*av=1;  /*���ñ�������ͷָ���ֵ*/
}

int getnode(StaticList space, int *av)
/*�ӱ�������ժ��һ�����ռ䣬����������뾲̬�����е�Ԫ��*/
{
	int i;
	i=*av;
	*av=space[*av].cursor;
	return i;
}

void   freenode(StaticList space, int *av, int k)
/*���±�Ϊ k�Ŀ��н����뵽��������*/
{
	space[k].cursor=*av;
	*av=k;
}

void  insbefore(StaticList space,int i,int *av, char x)
{
	int j,k,m;
	j=getnode(space,av);	               
	space[j].data=x;	
	k=space[0].cursor;      /* k Ϊ���þ�̬������ĵ�һ��Ԫ�ص��±�ֵ*/
	for(m=1;m<i-1;m++)		      /*Ѱ�ҵ�i -1��Ԫ�ص�λ��k */
		k=space[k].cursor;
	space[j].cursor=space[k].cursor; /*�޸��α���ʵ�ֲ������*/
	space[k].cursor=j;
}/*insbefore*/


void deleteelem(StaticList space, int i, int *av)
{ 
	int j,k,m;
	k=space[0].cursor;
	for(m=1;m<i-1;m++)	/*Ѱ�ҵ�i-1��Ԫ�ص�λ��k */
		k=space[k].cursor;
	j=space[k].cursor;
	space[k].cursor=space[j].cursor ;	/*�����ñ���ɾ����i ��Ԫ��*/
	freenode(space, av, j);
}

void output(StaticList space)
{
	int i;
	i= 1;
	while(space[i].cursor != 0)
	{
		printf("%c  ",space[i].data);
		i=space[i].cursor;
	}
	printf("%c\n",space[i].data);
}

void main()
{
	StaticList sp;
	int *p;
	char c;
	int i,j;
	p= (int *)malloc(sizeof(int));
	initial(sp,p);
	for (i=0; i<5; i++)
	{
		j=getnode(sp,p);
		printf("�������%d������:",i+1);
		fflush(stdin);
		scanf("%c",&c);
		sp[j].data = c;
	}
	sp[j].cursor=0;
	output(sp);
	
	printf("������Ҫ�����λ�ú�����:\n");
	fflush(stdin);
	scanf("%d,%c",&i,&c);
	insbefore(sp,i,p,c);
	output(sp);
	
	printf("������Ҫɾ����λ��\n");
	fflush(stdin);
	scanf("%d",&i);
	deleteelem(sp,i,p);
	output(sp);
}


			 
