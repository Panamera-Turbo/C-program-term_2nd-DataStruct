#include <stdio.h>

#include "BiTree.h"
// #include "stack.h"
#define EOL putchar('\n')

void print(DataType e)
{
    printf("%c", e);
}

bool isLeaf(BiTree root)
{
    return root->LChild == NULL && root->RChild == NULL;
}

int main()
{
    BiTree root;
    //const DataType *tree = "AB.DF..G..C.E.H..";
    // const DataType *tree = "ABDHL..M...E.I..CF.JN...G.K.O..";
    
    // CreateBiTree(&root, tree);

    root = CreateBiTreeByPreIn("ABDHLMEICFJNGKO", "LHMDBEIAFNJCGKO");

    //PreOrder_If(root, print, isLeaf);
    //EOL;

    PreOrder(root, print);
    EOL;

    PreOrder_Stack(root, print);
    EOL;
    InOrder(root);
    EOL;


    // PostOrder(root);
    // EOL;
    

    DestroyBiTree(root);
    
    return 0;
}