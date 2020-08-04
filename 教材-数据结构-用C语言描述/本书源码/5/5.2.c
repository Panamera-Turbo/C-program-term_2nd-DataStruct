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