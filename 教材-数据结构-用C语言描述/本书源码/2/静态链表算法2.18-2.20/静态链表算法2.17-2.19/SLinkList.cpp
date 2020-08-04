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
	space[0].cursor=0;      /*设置已用静态单链表的头指针指向位置0*/
	for(k=0;k<Maxsize-1;k++)
		space[k].cursor=k+1;    /*连链*/
	space[Maxsize-1].cursor=0;    /*标记链尾*/
	*av=1;  /*设置备用链表头指针初值*/
}

int getnode(StaticList space, int *av)
/*从备用链表摘下一个结点空间，分配给待插入静态链表中的元素*/
{
	int i;
	i=*av;
	*av=space[*av].cursor;
	return i;
}

void   freenode(StaticList space, int *av, int k)
/*将下标为 k的空闲结点插入到备用链表*/
{
	space[k].cursor=*av;
	*av=k;
}

void  insbefore(StaticList space,int i,int *av, char x)
{
	int j,k,m;
	j=getnode(space,av);	               
	space[j].data=x;	
	k=space[0].cursor;      /* k 为已用静态单链表的第一个元素的下标值*/
	for(m=1;m<i-1;m++)		      /*寻找第i -1个元素的位置k */
		k=space[k].cursor;
	space[j].cursor=space[k].cursor; /*修改游标域，实现插入操作*/
	space[k].cursor=j;
}/*insbefore*/


void deleteelem(StaticList space, int i, int *av)
{ 
	int j,k,m;
	k=space[0].cursor;
	for(m=1;m<i-1;m++)	/*寻找第i-1个元素的位置k */
		k=space[k].cursor;
	j=space[k].cursor;
	space[k].cursor=space[j].cursor ;	/*从已用表中删除第i 个元素*/
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
		printf("请输入第%d个数据:",i+1);
		fflush(stdin);
		scanf("%c",&c);
		sp[j].data = c;
	}
	sp[j].cursor=0;
	output(sp);
	
	printf("请输入要插入的位置和数据:\n");
	fflush(stdin);
	scanf("%d,%c",&i,&c);
	insbefore(sp,i,p,c);
	output(sp);
	
	printf("请输入要删除的位置\n");
	fflush(stdin);
	scanf("%d",&i);
	deleteelem(sp,i,p);
	output(sp);
}


			 
