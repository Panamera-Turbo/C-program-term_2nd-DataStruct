#include "../record.h"
/******************************************************************
 * shell希尔排序
 * （又称缩小增量排序，基于插入思想的排序方法）
 * 附注： 结合PPT理解
 * ----------------------------------------------------------------
 * 【1】i = 1
 * 【2】选定间隔数 delta(i)，将原待排序序列中所有间隔为D的记录分成一组，
 *      进行组内直接插入排序
 * 【3】++i；
 * 【4】记录间的距离为 delta(i),其中 delta(i) < delta(i-1)。在整个待
 *      排序序列中，将所有间隔为为delta(i)的记录分成一组，进行组内插入
 *      排序。
 * 【5】重复【3】【4】，直到delta(i) == 1.
 * ----------------------------------------------------------------
 *  排序方法不稳定
 * ****************************************************************/
static void ShellInsert(RecordType r[], int length, int delta)
/*对记录数组r做一趟希尔插入排序，length为数组的长度,delta 为增量*/
{
    int i, j;

    for (i = 1 + delta; i <= length; ++i){ /* 1+delta为第一个子序列的第二个元素的下标 */
        if (r[i].key < r[i - delta].key)    //对子序列插入排序
        {
            r[0] = r[i]; /*  备份r[i]  (不做监视哨) */

            for (j = i - delta; j > 0 && r[0].key < r[j].key; j -= delta)
                r[j + delta] = r[j];

            r[j + delta] = r[0];
        }//end if
    }//end for
}

void ShellSort(RecordType r[], int length)
{
    int delta = length / 2;

    while (delta >= 1)
    {
        ShellInsert(r, length, delta);
        delta /= 2;                     // delta的取值有多种方法，对算法有影响。详细百度。
    }
}