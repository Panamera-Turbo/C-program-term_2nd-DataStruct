#define MAXSIZE 1000  /*非零元素的个数最多为1000*/

/*稀疏矩阵三元组表的类型定义*/	
typedef struct
{   
	int row,col;  /*该非零元素的行下标和列下标*/
    ElementType e; /*该非零元素的值*/
}Triple;

typedef struct
{  
	Triple data[MAXSIZE+1];   /* 非零元素的三元组表。data[0]未用*/
	int m,n,len;          /*矩阵的行数、列数和非零元素的个数*/
}TSMatrix;

/*矩阵转置的经典算法*/



/*"列序"递增转置法*/

void TransposeTSMatrix(TSMatrix A,TSMatrix *B)
{ /*把矩阵A转置到B所指向的矩阵中去。矩阵用三元组表表示*/
	int i,j,k;
	B->m=A.n; 
	B->n=A.m; 
	B->len=A.len;
	if(B->len>0)
	{
		j=1;				/*j为辅助计数器，记录转置后的三元组在三元组表B中的下标值*/
		for(k=1; k<=A.n; k++) /*扫描三元组表A 共k次，每次寻找列值为k的三元组进行转置*/
			for(i=1; i<=A.len; i++)
				if(A.data[i].col==k)
				{
					B->data[j].row=A.data[i].col;/*从头至尾扫描三元组表A,寻找col值为k的三元组进行转置*/
					B->data[j].col=A.data[i].row;
					B->data[j].e=A.data[i].e;
					j++;		/*计数器j自加，指向下一个存放转置后三元组的下标*/
				}/*内循环中if的结束*/
	}/* if(B->len>0)的结束*/
}/* end of TransposeTSMatrix */

/*"按位快速转置"法*/

void FastTransposeTSMatrix(TSMatrix A,TSMatrix *B)
{ 
	/*基于矩阵的三元组表示，采用"按位快速转置"法，将矩阵A转置为矩阵B*/
	int col,t,p,q;
	int num[MAXSIZE], position[MAXSIZE];
	B->len=A.len; 
	B->n=A.m; 
	B->m=A.n;
	if(B->len)
	{
		for(col=1;col<=A.n;col++)
			num[col]=0;  
		for(t=1;t<=A.len;t++)
			num[A.data[t].col]++; /*计算每一列的非零元素的个数*/	
		position[1]=1;
		for(col=2;col<=A.n;col++)  /*求col列中第一个非零元素在B.data[ ]中的正确位置*/
			position[col]=position[col-1]+num[col-1]; 
		for(p=1;p<=A.len;p++)/*将被转置矩阵的三元组表A从头至尾扫描一次，实现矩阵转置*/
		{  
			col=A.data[p].col;  
			q=position[col];
			B->data[q].row=A.data[p].col;
			B->data[q].col=A.data[p].row;
			B->data[q].e=A.data[p].e;
			position[col]++;/* position[col]加1，指向下一个列号为col的非零元素在三元组表B中的下标值*/
		}/*end of for*/
	}
}
