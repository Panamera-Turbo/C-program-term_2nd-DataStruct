#include <stdio.h>
#include <stdlib.h>

#define  m  3
#define NULL 0
#define TRUE 1
typedef	int  Boolean; 
typedef int KeyType;

typedef	struct Mbtnode 
{
	struct Mbtnode  *parent;
	int  keynum;
	KeyType  key[m+1];
	struct Mbtnode  *ptr[m+1];
} Mbtnode, *Mbtree;
