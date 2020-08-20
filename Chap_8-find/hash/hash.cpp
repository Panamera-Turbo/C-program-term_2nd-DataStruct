#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

#include "hash.h"
/************************************************************************
 * hash哈希排序：
 * *********************************************************************/

static const double loadfactor = 0.7; //装填因子建议在0.7~0.8之间
static int P;                         //hash表的长度，通过计算得到。最好是个素数

static inline int hash(KeyType k)
{
    return k % P;
}
//------------------------------------------------------------------------
int HashSearch(HashTable ht, KeyType K)
{//找到键值在hash表中的下标
    int h0 = hash(K), hi, i;

    if (ht[h0].key == NULLKEY)  //这个值不在hash表里
        return -1;
    else if (ht[h0].key == K)   //如果是要找的
        return h0;
    else /* 用线性探测再散列解决冲突 */
    {
        for (i = 1; i <= P - 1; ++i)
        {
            //hi = (h0+i) % P;
            hi = hash(h0 + i);
            if (ht[hi].key == NULLKEY)
                return -1;
            else if (ht[hi].key == K)
                return hi;
        }
        return -1;  
    }
}
//------------------------------------------------------------------------
static int FindRoom(HashTable ht, KeyType K)
{//找到一个可以容纳键值K的空单元（.key == NULLKEY）
    int h0 = hash(K), hi, i;

    if (ht[h0].key == NULLKEY)  //这个值不在hash表，空间可以拿来存储
        return h0;
    else /* 用线性探测再散列解决冲突 */
    {
        for (i = 1; i <= P - 1; ++i)
        {
            //hi = (h0+i) % P;
            hi = hash(h0 + i);
            if (ht[hi].key == NULLKEY)
                return hi;
        }
    }

    return -1;  //实际上不会被执行，只是为了避免报错
}
//------------------------------------------------------------------------
static bool isPrime(int n)
{//判断n是否素数
    for (int i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;

    return true;
}
//------------------------------------------------------------------------
//找到第一个小于等于预估hash表长度的素数p
//tablelen是预估长度，由Key的个数和装填因子确定
static int FindP(int tablelen)
{
    for (int n = tablelen; n >= 2; --n)
        if (isPrime(n))
            return n;

    return 2;
}
//------------------------------------------------------------------------
void CreateFromFile(HashTable *ht)
{
    FILE *fp;
    KeyType len;
    int index;
    const int size = sizeof(KeyType);

    fp = fopen(data_file, "rb");
    fread(&len, size, 1, fp); //读取Key的个数

    P = FindP((int)(len / loadfactor)); //尝试找到最佳的hash表长度
    *ht = (HashTable)malloc(P * size);
    for (int i = 0; i < P; ++i)
        (*ht)[i].key = NULLKEY;

    KeyType key;
    for (int i = 0; i < len; ++i) //将每一个key散列到hash表中
    {
        fread(&key, size, 1, fp);
        index = FindRoom(*ht, key);
        if (index != -1)
            (*ht)[index].key = key;
        else
            printf("Cannot find a room\n");
    }

    fclose(fp);
}
//------------------------------------------------------------------------
void Destroy(HashTable *ht)
{
    free(*ht);
}