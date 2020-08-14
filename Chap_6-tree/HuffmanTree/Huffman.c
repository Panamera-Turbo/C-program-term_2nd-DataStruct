#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Huffman.h"
//----------------------------------------------------------------------------------------
//在Huffman树的前n个未处理过的节点中,找到两个权值最小的
static void Select(HuffmanTree ht, int n, int *s1, int *s2)
{
    int i, min;

    min = -1;           //先设置最小值为-1，便于第一次的比较
    for (i = 1; i <= n; ++i)
        if (ht[i].parent == 0 && (min == -1 || ht[i].weight < ht[min].weight))  
            //注意这里的min==-1，必须写在前面，否则系统初次读取到ht[min]会越界，写在前面会执行后被略过后项。略危险的做法
            min = i;

    *s1 = min;

    min = -1;
    for (i = 1; i <= n; ++i)
        if (i != *s1 && ht[i].parent == 0 && (min == -1 || ht[i].weight < ht[min].weight))
            min = i;

    *s2 = min;
}

//----------------------------------------------------------------------------------------
//创建Huffman树
void CreateHuffmanTree(HuffmanTree ht, int *w, int n)
{ //w:weight, 权值数组; n：已知的权重的数目
    int i, s1, s2;
    int m = 2 * n - 1;

    for (i = 1; i <= m; ++i)        //初始化权重和孩子、双亲
    {
        ht[i].weight = i <= n ? w[i] : 0;   //大于n的先留空，看下面的for就懂了
        ht[i].parent = ht[i].RChild = ht[i].LChild = 0;
    }

    for (i = n + 1; i <= m; ++i)
    {
        Select(ht, i - 1, &s1, &s2);
        ht[s1].parent = ht[s2].parent = i;
        ht[i].LChild = s1;
        ht[i].RChild = s2;
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }
}
//----------------------------------------------------------------------------------------
//创建Huffman编码:左子树为1, 右子树为0, 从根节点到该节点的数字连起来(二进制)就是对应的编码.
//哈夫曼编码是前缀编码,即任何一个编码的后缀不是另一个编码的前缀
//编码中1的个数等于路过的路径数
void CreateHuffmanCodeTable(HuffmanTree ht, HuffmanCodeTable hc, int n)
{
    HuffmanCode cd;
    int i, start, c;
    int p;

    cd[n] = '\0';            /*从右向左逐位存放编码，首先存放编码结束符*/
    for (i = 1; i <= n; ++i) /*求n个叶子结点对应的哈夫曼编码*/
    {
        start = n;                                                     //初始化编码起始指针

        for (c = i, p = ht[i].parent; p != 0; c = p, p = ht[p].parent) //从叶子到根结点求编码, c:child  p:parent
            cd[--start] = ht[p].LChild == c ? '0' : '1';               //start往往到不了0,所以赋值到另一编码表cd里

        strcpy(hc[i], &cd[start]);
    }
}
//----------------------------------------------------------------------------------------
void PrintHuffmanCodeTable(HuffmanTree ht, HuffmanCode *hc, int n)
{
    for (int i = 1; i <= n; ++i)
        printf("(%d) The node weighs %d was encoded as %s\n", i, ht[i].weight, hc[i]);
    printf("\n");
}
//----------------------------------------------------------------------------------------
//打印Huffman树
void PrintHuffmanTree(HuffmanTree HT, int m)
{
    printf("节点 权重  双亲 左孩子 右孩子\n");
    for (int i = 1; i <= m; ++i)
        printf("%2d:(%4d, %4d, %4d, %4d)\n", i, HT[i].weight, HT[i].parent, HT[i].LChild, HT[i].RChild);
}