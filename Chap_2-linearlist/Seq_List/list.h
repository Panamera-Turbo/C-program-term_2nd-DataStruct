//-----------------------------------------------
//  声明数据类型要同时声明接口函数，二者配合使用
//-----------------------------------------------
#pragma once

#define	MAXSIZE  100   /*此处的宏定义常量表示线性表可能达到的最大长度*/
#include"list_elemtype.h"

//数据封装，对外部隐藏，需要接口来配合使用
typedef  struct
{ 
	ElemType  elem[MAXSIZE];  /*线性表占用的数组空间; Elemtype表示一个抽象的元素类型*/

	int       last;    /*记录线性表中最后一个元素在数组elem[ ]中的位置（下标值），空表置为-1*/
	
} SeqList, LList, *LListPtr;//SeqList顺序表， LList线性表, *LListPtr线性表指针

