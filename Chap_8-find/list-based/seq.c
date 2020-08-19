#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "seq.h"
/*************************************************************
 * 比较查找法中基于线性表的查找法
 * 在表的一端设置一个附加单元（监视哨），存放待查找元素的关键字。
 * 从表的另一端开始查找，若在监视哨找到，返回false，否则返回对应下标
 * ***********************************************************/
#define Use_Surveillance_Post   //定义是否使用监视哨
//-------------------------------------------------------------------------------------------------
#ifdef Use_Surveillance_Post
int SeqSearch(RecordList  l,  KeyType  k)
/*在顺序表l中顺序查找其关键字等于k的元素，若找到，则函数值为该元素在表中的位置，否则为0*/
{
	int i;
	l.r[0].key=k;
	i=l.length;
	while (l.r[i].key!=k)  i--;
	return(i);
}
//--------------------------------------------------------------------------------------------------
#else
int SeqSearch(RecordList l, KeyType k)
/*不用"监视哨"法，在顺序表中查找关键字等于k的元素*/
{
    int i = l.length;
    while (i >= 1 && l.r[i].key != k)
        i--;
    return i >= 1 ? i : -1;
}
#endif
//---------------------------------------------------------------------------------------------------
void CreateFromFile(RecordList *l)
{
    FILE *fp;
    KeyType len;
    const unsigned size = sizeof(KeyType);

    fp = fopen(data_file, "rb");
    fread(&len, size, 1, fp);
    l->length = len;
    l->r = (RecordType *)malloc((len + 1) * size);
    rewind(fp);         //倒带。让文件重新回到头部
    fread(l->r, size, len + 1, fp);     //读进l->r
    fclose(fp);
}
void Destroy(RecordList *l)
{
    free(l->r);
}
void Found(int i, KeyType key)
{
    if (i != -1)
        printf("--- Found key %d @ %d\n", key, i);
    else
        printf("--- Key %d was not found\n", key);
}