#include "../record.h"
/*******************************************************
 * 插入排序：在已排好序的子集的基础上，将下一个待排序的记录
 *          有序插入到已排序的记录子集。
 * ——————————————————————————————————————————————————————
 * 直接插入排序：
 * 【1】设置监视哨r[0]，存放待排序的记录
 *          ---{作用：备份待插入记录; 防止越界}
 * 【2】所有比关键字大/小的数据后移一位
 * 【3】插入对应位置（移动后空出来的地方）
 * ——————————————————————————————————————————————————————
 * conclusion:
 * 时间复杂度O(n^2),空间复杂度O(1),具有排序的稳定性
 * *****************************************************/
//----------------------------------------------------------------------------------------------------------------------------------
void InsSort(RecordType r[], int length)
/* 对记录数组r做直接插入排序，length为数组中待排序记录的数目*/
{
    int i, j;
    
    for(i = 2; i <= length; ++i){    //从2开始排，因为0号是监视哨，1号相当于已经排序的子集
        r[0] = r[i];

        for(j = i - 1; r[0].key < r[j].key; --j)
            r[j+1] = r[j];

        r[j+1] = r[0];

    }
} /*  InsSort  */