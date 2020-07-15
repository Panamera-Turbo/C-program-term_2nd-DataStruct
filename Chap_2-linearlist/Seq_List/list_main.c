#include "list_interface.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------
void print(ElemType *e)
{
    printf("%4d", *e);
}

//---------------------------------------------------
int main(){
    LList list, *L = &list;

    init_list(&L);

    for(int i=1; i<10; ++i)
        ins_list(L, i, i+10);
    
    traverse(L, print);
    
    puts("");
    return 0;
}