#include <malloc.h>
#include <stdio.h>

/*十字链表的结构类型定义如下：*/
typedef struct OLNode
{	
	int row,col;        /*非零元素的行和列下标*/
	ElementType value;
	struct OLNode *right;  /*非零元素所在行表、列表的后继链域*/
	struct OLNode *down; 
}OLNode; *OLink;

typedef struct 
{	
	OLink *row_head;  /*行、列链表的头指针向量*/
	OLink *col_head;
	int m,n,len;               /*稀疏矩阵的行数、列数、非零元素的个数*/
}CrossList;

/*建立稀疏矩阵的十字链表的算法*/

void CreateCrossList(CrossList *M)
{
	/*采用十字链表存储结构，创建稀疏矩阵M*/
	scanf(&m,&n,&t);  /*输入M的行数,列数和非零元素的个数*/
	M->m=m;
	M->n=n;
	M->len=t;
	if(!(M->row_head=(OLink *)malloc((m+1)sizeof(OLink)))) 
		exit(OVERFLOW);
	if(!(M->col_head=(OLink * )malloc((n+1)sizeof(OLink)))) 
		exit(OVERFLOW);
	M->row_head[ ]=M->col_head[ ]=NULL;   /*初始化行、列头指针向量，各行、列链表为空的链表*/
	for(scanf(&i,&j,&e);i!=0;scanf(&i,&j,&e))
	{
		if(!(p=(OLNode *)malloc(sizeof(OLNode)))) 
			exit(OVERFLOW);
		p->row=i;
		p->col=j;
		p->value=e;  /*生成结点*/
		if(M->row_head[i]==NULL)   
			M->row_head[i]=p;
		else
		{  
			/*寻找行表中的插入位置*/
			for(q=M->row_head[i];q->right&&q->right->col<j;q=q->right);  /*空循环体*/
			p->right=q->right; 
			q->right=p;  /*完成插入*/
		}
		if(M->col_head[j]==NULL)   
			M->col_head[j]=p;
		else
		{  
			/*寻找列表中的插入位置*/
			for(q=M->col_head[j];q->down&&q->down->row<i;q=q->down);  /*空循环体*/
			p->down=q->down; 
			q->down=p;   /*完成插入*/
		}
	}
}
