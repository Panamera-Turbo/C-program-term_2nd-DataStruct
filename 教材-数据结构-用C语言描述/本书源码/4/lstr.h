#include "stdio.h"
#include "stdlib.h"

/*链式存储方式下的模式匹配，每个字符用一结点表示*/

typedef struct Block{
	char   ch;
	struct Block   *next;
}Block;

typedef struct {
	Block   *head;
	Block   *tail;
	int     len;
}BLString;
