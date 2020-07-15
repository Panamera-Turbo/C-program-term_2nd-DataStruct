#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "seq.h"

// int SeqSearch(RecordList  l,  KeyType  k)
// /*在顺序表l中顺序查找其关键字等于k的元素，若找到，则函数值为该元素在表中的位置，否则为0*/
// {
// 	int i;
// 	l.r[0].key=k;
// 	i=l.length;
// 	while (l.r[i].key!=k)  i--;
// 	return(i);
// }

int SeqSearch(RecordList l, KeyType k)
/*不用"监视哨"法，在顺序表中查找关键字等于k的元素*/
{
    int i = l.length;
    while (i >= 1 && l.r[i].key != k)
        i--;
    return i >= 1 ? i : -1;
}

void CreateFromFile(RecordList *l)
{
    FILE *fp;
    KeyType len;
    const unsigned size = sizeof(KeyType);

    fp = fopen(data_file, "rb");
    fread(&len, size, 1, fp);
    l->length = len;
    l->r = (RecordType *)malloc((len + 1) * size);
    rewind(fp);
    fread(l->r, size, len + 1, fp);
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