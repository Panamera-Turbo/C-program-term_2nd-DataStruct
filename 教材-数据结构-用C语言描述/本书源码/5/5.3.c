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