#include "list_interface.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------------------------------------------------
//打印
void print(ElemType *e)
{
    printf("%4d", *e);
}
//-------------------------------------------------------------------------------------------------------------------------
//寻找倒数第i个元素
ElemType reverse_i(LListPtr L, int i)
{
    NodePtr p,q;
    int k;
    for(k=0, p = L; k<i; p = p->next, ++k) ;
    for(q = L; p != NULL; p = p->next, q = q->next);
    return q->data;
}
//---------------------------------------------------------------------------------------------------------------------
int main(){
    LListPtr list;
    ElemType e;

    init_list(&list);                   //初始化

    for(int i=1; i<10; ++i)             //赋值
        ins_list(list, i, i+10);
    
    traverse(list, print), puts("");    //遍历一下

    del_list(list, 3, &e);              //删除一个元素

    traverse(list, print), puts("");    //遍历一下
    
    

    printf("%4d\n", reverse_i(list, 3)); //  

    destroy_list(list);                 //释放

    return 0;
}