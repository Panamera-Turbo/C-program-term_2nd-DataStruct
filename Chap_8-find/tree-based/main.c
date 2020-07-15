#include <stdio.h>

#include "bstree.h"

void test_search(KeyType key)
{
    BSTree l;

    CreateFromFile(&l);

    BSTree i = BSTSearch(l, key);

    Found(i, key);

    Destroy(&l);
}

int main()
{
    KeyType key = 31018;

    test_search(key);
   
    return 0;
}