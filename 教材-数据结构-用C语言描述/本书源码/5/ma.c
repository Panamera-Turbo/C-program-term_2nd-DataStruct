/*如果矩阵A中存在这样的一个元素A[i][j]满足条件:A[i][j]是第i行中值最小的元素,且又是第j列中值最大的
元素,则称之为该矩阵的一个马鞍点。编写一个函数计算出1×n的矩阵A的所有马鞍点。
算法思想：依题意,先求出每行的最小值元素,放入min[m]之中,再求出每列的最大值元素,放入max[n]之中,若某
元素既在min[i]中,又在max[j]中,则该元素A[i][j]便是马鞍点,找出所有这样的元素,即找到了所有马鞍点。因此,
实现本题功能的程序如下:*/
#include <stdio.h>
#define m 3
#define n 3

void minmax(int a[m][n])
{
	int i1,j,have=0;
	int min[m],max[n];
	for(i1=0;i1<m;i1++)/*计算出每行的最小值元素,放入min[m]之中*/
	{
		min[i1]=a[i1][0];
		for(j=1;j<n;j++)
			if(a[i1][j]<min[i1]) min[i1]=a[i1][j];
	}
	for(j=0;j<n;j++)/*计算出每列的最大值元素,放入max[n]之中*/
	{
		max[j]=a[0][j];
		for(i1=1;i1<m;i1++)
			if(a[i1][j]>max [j]) max[j]=a[i1][j];
	}
	for(i1=0;i1<m;i1++)
		for(j=0;j<n;j++)
			if(min[i1]==max[j])
			{
				printf("(%d,%d):%d\n",i1,j,a[i1][j]);
				have=1; 
			}
			if(!have) printf("没有鞍点＼n");
} 

void main()
{
	int a[m][n];
	int i,j; 
	printf("请输入一个数组\n"); 
	for(i=0;i<m;i++) 
		for(j=0;j<n;j++) 
			scanf("%d",&a[i][j]); 
	minmax(a);
}
