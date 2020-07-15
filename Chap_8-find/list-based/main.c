#include <stdio.h>

#include "seq.h"

void test_search(KeyType key)
{
    RecordList l;

    CreateFromFile(&l);

    int i = SeqSearch(l, key);

    Found(i, key);

    Destroy(&l);
}

int main()
{
    KeyType key = 31018;

    test_search(key);
   
    return 0;
}