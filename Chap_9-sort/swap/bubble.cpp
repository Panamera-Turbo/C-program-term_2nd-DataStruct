#include "../record.h"
/*******************************************
 * 
 * ---------------冒泡排序-------------------
 * 
 * *****************************************/
void BubbleSort(RecordType r[], int length)
{/*对记录数组r做冒泡排序，length为数组的长度*/
    int i, j;
    RecordType x;
    bool is_swapped = true;

    for(i  = 1; i <= length-1 && is_swapped; ++i)
    {
        is_swapped = false;

        for(j = 1; j <= length-1 ; ++j)
        {
            if (r[j + 1].key < r[j].key)
            {
                x = r[j];
                r[j] = r[j + 1];
                r[j + 1] = x;
                is_swapped = true;
            }//end if
        }//end for
    }//end for

} /*  BubbleSort  */