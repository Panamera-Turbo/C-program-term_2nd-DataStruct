#include <stdio.h>

#include "BiTree.h"

#define EOL putchar('\n')
//-------------------------------------------------------------------------------------------------------
void print(DataType e)
{
    printf("%2c", e);
}

//-------------------------------------------------------------------------------------------------------
int main()
{
    BiTree root;
    //const DataType *tree = "AB.DF..G..C.E.H..";
    const DataType *tree = "ABDHL..M...E.I..CF.JN...G.K.O.."; //这里用 . 表示空

    CreateBiTree(&root, tree);

    PreOrder(root, print);
    EOL;
    InOrder(root, print);
    EOL;
    PostOrder(root, print);
    EOL;

    PreOrder_IfLeaf(root, print, isLeaf);
    // printf("%6d leaf(leaves) in total", total);
    EOL;

    DestroyBiTree(root);

    return 0;
}