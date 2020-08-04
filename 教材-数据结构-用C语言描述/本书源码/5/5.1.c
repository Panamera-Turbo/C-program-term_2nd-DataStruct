/*采用矩阵的正常存储方式（二维数组）实现矩阵转置：*/
void TransMatrix(ElementType source[m][n],ElementType dest[n][m])
{
	/*Source和dest分别为被转置的矩阵和转置以后的矩阵（用二维数组表示）*/
	int i,j;
	for(i=0;i<m;i++)
		for (j=0;j<n;j++)
			dest[j][i]=source[i][j];
}
