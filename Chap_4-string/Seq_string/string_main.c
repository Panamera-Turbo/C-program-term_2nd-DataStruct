#include <stdio.h>

#include "string.h"


int main()
{
    String s, t, r;

    StrSet(&s, "Hello, world!Hello,world!");
    StrSet(&r, "Hello, world!Hello,world!");

    StrSet(&t, "world!");

    StrPrint(&s);
    putchar('\n');
    StrPrint(&t);
    putchar('\n');

    // int pos = StrIndex();
    StrInsert(&r, 6, &t);
    StrPrint(&r);
    putchar('\n');

    int pos = 0;
    while (pos != -1)
    {
        pos = StrIndex(&s, pos+1, &t);
        printf("%d\n", pos);
    }
    
    return 0;
}
