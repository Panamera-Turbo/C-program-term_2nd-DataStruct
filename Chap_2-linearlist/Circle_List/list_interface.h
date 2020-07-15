#pragma once
//--------------------------------------------------------------------
//这个头文件分离了接口和实现
//--------------------------------------------------------------------
//这个头文件适用于顺序表，包括线性表和链表，只是实现方式不同
//--------------------------------------------------------------------
#include"list.h"
#include <stdbool.h>

extern void init_list(LListPtr *L);                     //初始化
extern bool ins_list(LListPtr L, int i, ElemType e);   //插入
extern bool del_list(LListPtr L, int i, ElemType* e);  //删除，同时保留被删除的内容
extern void destroy_list(LListPtr L);

typedef void (*CALLBACK)(ElemType*);                     //CALLBACK：函数类型, 而不是函数或函数指针。说明CALLBACK类型的函数只有一个指针参数，返回值为空。
                                                       //（如果是函数指针，因该是typedef void (*CALLBACK)(ElemType* );

extern void traverse(LListPtr L, CALLBACK f);          //遍历