#include <stdio.h>

#include "Forest.h"

#define EOL putchar('\n')
//-------------------------------------------------------------------------------------------------------
void print(DataType e)
{
    printf("%4c", e);
}
//-------------------------------------------------------------------------------------------------------
int main()
{
    #define TN 3

    char *s[TN] = {"AB.C.D...", "EF...", "GH.IJ...."};
    Forest f;

    f = CreateForest(s, TN);

    printf("Traverse the forest(pre order):\n");
    ForestPre(f->FirstChild, print);
    EOL;

    printf("Traverse the forest(in order):\n");
    ForestIn(f->FirstChild, print);
    EOL;

    printf("Traverse the forest(post order):\n");
    ForestPost(f->FirstChild, print);
    EOL;

    DestroyForest(f);

    return 0;
}