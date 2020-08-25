#include <cstdlib>
#include "../record.h"
/***********************************************************
 * 归并排序：基于合并，将两个或两个以上的有序表合并成一共有序新表
 * 
 * 【2-路归并】
 * 
 * (1)思想：
 * 假设初始序列含有 n个记录,首先将这 n个记录看成 n个有序的子序列，
 * 每个子序列的长度为1,然后两两归并，得到[n/2]个长度为2(n为奇数
 * 时,最后一个序列的长度为1)的有序子序列。在此基础上，再对长度为2
 * 的有序子序列进行两两归并，得到若千个长度为4的有序子序列。如此
 * 重复,直至得到一个长度为n的有序序列为止。
 * 
 * 2-路归并排序法的基本操作是将待排序列中相邻的两个有序子序列合并
 * 成一个有序序列。
 * 
 * (2)在合并过程中,两个有序的子表被遍历了一遍,表中的每一项均被复制
 * 了一次。因此,合并的代价与两个有序子表的长度之和成正比,该算法的
 * 时间复杂度为O(n)，空间复杂度O(n)，通常只运行1024个数据即可。
 * 
 * (3)2-路归并排序可以采用递归方法实现。

 * *********************************************************/
static void Merge(RecordType r1[], RecordType r2[], int low, int mid, int high)
/* 已知r1[low..mid]和r1[mid+1..high]分别按关键字有序排列，将它们合并成一个有序序列，存放在r2[low..high] */
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (r1[i].key <= r1[j].key){
            r2[k] = r1[i];
            ++i;
        }
        else{
            r2[k] = r1[j];
            ++j;
        }
        ++k;
    }
    //下面两个循环只有一个会被执行
    while (i <= mid){
        r2[k] = r1[i];
        ++k;
        ++i;
    }
    while (j <= high){
        r2[k] = r1[j];
        ++k;
        ++j;
    }
} /* Merge */
//----------------------------------------------------------------------------------
static int len;

//----------------------------------------------------------------------------------
static void _MergeSort_(RecordType src[], RecordType dest[], int low, int high)
{/* src[low..high]经过排序后放在dest[low..high]中，aux[low..high]为辅助空间 */
    int mid;

    if (low == high)    //循环退出的条件
    {
        dest[low] = src[low];
        return;
    }

    RecordType *aux = (RecordType *)malloc(sizeof(RecordType) * len);   //辅助空间aux，注意这里是len*sizeof
    mid = (low + high) / 2;
    _MergeSort_(src, aux, low, mid);
    _MergeSort_(src, aux, mid + 1, high);
    Merge(aux, dest, low, mid, high);
    free(aux);

} /*   _MergeSort_  */
//------------------------------------------------------------------------------------
void MergeSort(RecordType r[], int n)
/* 对记录数组r[1..n]做归并排序 */
{
    len = n + 1;
    _MergeSort_(r, r, 1, n);
}
