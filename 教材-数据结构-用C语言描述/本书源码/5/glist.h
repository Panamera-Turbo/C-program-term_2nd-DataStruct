#include <malloc.h>
/*广义表的头尾链表存储结构类型定义如下：*/
typedef enum {ATOM, LIST} ElemTag;  /* ATOM＝0，表示原子；LIST＝1，表示子表*/
typedef struct GLNode
{   
	ElemTag tag;             /*标志位tag用来区别原子结点和表结点*/
	union
	{ 
		AtomType atom;                 /*原子结点的值域atom*/
		struct 
		{ 
			struct GLNode *hp,*tp;
		}htp;   /*表结点的指针域htp,包括表头指针域hp和表尾指针域tp*/
	}atom_htp;  /* atom_htp 是原子结点的值域atom和表结点的指针域htp的联合体域*/
}GLNode,*GList;

/*求广义表的表头*/

GList Head(GList L)
{
	if(L==NULL) 
		return(NULL);    /* 空表无表头 */
	if(L->tag==ATOM) 
		exit(0);    /* 原子不是表 */
	else 
		return(L->atom_htp.htp.hp);
}

/*求广义表的表尾*/

GList Tail(GList L)
{
	if(L==NULL) 
		return(NULL);    /* 空表无表尾 */
	if(L->tag==ATOM) 
		exit(0);    /* 原子不是表*/
	else 
		return(L->atom_htp.htp.tp);
}

/*求广义表的长度*/

int Length(GList L)
{ 
	int n=0;
	GLNode *s;
	if(L==NULL) 
		return(0);    /* 空表长度为0 */
	if(L->tag==ATOM) 
		exit(0);    /* 原子不是表 */
	s=L;
	while(s!=NULL)    /* 统计最上层表的长度 */
	{ 
		k++;
		s=s->atom_htp.htp.tp;
	}
	return(k);
}

/*求广义表的深度*/

int Depth(GList L)
{ 
	int d,max;
	GLNode *s;
	if(L==NULL) 
		return(1);    /* 空表深度为1 */
	if(L->tag==ATOM) 
		return(0);    /* 原子深度为0 */
	s=L;
	while(s!=NULL)    /* 求每个子表的深度的最大值 */
	{ 
		d=Depth(s->atom_htp.htp.hp);
		if(d>max) 
			max=d;
		s=s->atom_htp.htp.tp;
	}
	return(max+1);    /* 表的深度等于最深子表的深度加1 */
}

/*统计广义表中原子数目方法一*/

int CountAtom1(GList L)
{ 
	int n;
	GLNode *s;
	if(L==NULL) 
		return(0);    /* 空表中没有原子 */
	if(L->tag==ATOM) 
		return(1);    /* L指向单个原子 */
	s=L; 
	n=0;
	while(s!=NULL)    /* 求每个子表的原子数目之和 */
	{ 
		n=n+CountAtom(s->atom_htp.htp.hp);
		s=s->atom_htp.htp.tp;
	}
	return(n);
}

/*统计广义表中原子数目方法二*/

int CountAtom2(GList L)
{ 
	int n1, n2;
	if(L==NULL) 
		return(0);    /* 空表中没有原子 */
	if(L->tag==ATOM) 
		return(1);    /* L指向单个原子 */
	n1=CountAtom(L->atom_htp.htp.hp);    /* 求表头中的原子数目 */
	n2=CountAtom(L->atom_htp.htp.tp);    /* 求表尾中的原子数目 */
	return(n1+n2);
}

/*复制广义表*/
int CopyGList(GList S, GList *T)
{ 
	if(S==NULL) 
	{ 
		*T=NULL; 
		return(OK); 
	}    /* 复制空表 */
	*T=(GLNode *)malloc(sizeof(GLNode));
	if(*T==NULL) 
		return(ERROR);
	(*T)->tag=S->tag;
	if(S->tag==ATOM) 
		(*T)->atom=S->atom;    /* 复制单个原子 */
	else
	{
		CopyGList(S->atom_htp.htp.hp, &((*T)->atom_htp.htp.hp));    /* 复制表头 */
		CopyGList(S->atom_htp.htp.tp, &((*T)->atom_htp.htp.tp));    /* 复制表尾 */
	}
	return(OK);
}
