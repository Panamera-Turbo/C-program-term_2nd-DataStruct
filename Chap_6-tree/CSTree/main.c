#include <stdio.h>

#include "BiTree.h"
#include "CSTree.h"

#define EOL putchar('\n')
//-------------------------------------------------------------------------------------------------------
void print(DataType e)
{
    printf("%4c", e);
}
//-------------------------------------------------------------------------------------------------------
int main()
{
    char *nodes = "ABE..CFH..G..D..."; //p184 figure 6.28~6.29;
    BiTree BiRoot = NULL;
    CSTree CSRoot = NULL;
    
    CSRoot = CreateCSTree(&nodes);
    // BiRoot = CS2Bi(CSRoot);

    PreOrder(BiRoot, print);
    EOL;
    RootFirst(CSRoot, print);
    EOL;

    // PostOrder(BiRoot, print);
    // EOL;
    // RootLast(CSRoot, print);
    // EOL;

    DestroyCSTree(CSRoot);
    DestroyBiTree(BiRoot);

    return 0;
}