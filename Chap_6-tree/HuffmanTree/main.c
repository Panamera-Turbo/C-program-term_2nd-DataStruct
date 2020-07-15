#include <stdio.h>

#include "Huffman.h"

//哈夫曼树的特征1:有n个叶节点的树总共有2n-1个节点

#define N	10
#define M	(2*N-1)	//宏是表达式时,必须括号

int main()
{ 
	HuffmanTree HT; 
	HuffmanCodeTable HC; 
	int w[N+1] = {-1, 40, 30, 15, 5, 4, 3, 3}; 
	
	CreateHuffmanTree(HT, w, N); 
	CreateHuffmanCodeTable(HT, HC, N);

	PrintHuffmanTree(HT, M); 
	printf("\n");
    PrintHuffmanCodeTable(HT, HC, N);

    return 0;
}