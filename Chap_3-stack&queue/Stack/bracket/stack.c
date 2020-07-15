#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "stack.h"

//-----------------------------------------------------------------------------
//初始化栈
void init_stack(StackPtr s){
    s->next = NULL;
}
//-----------------------------------------------------------------------------
//压栈
void push_stack(StackPtr s, char c){
    Node* p = (Node*)malloc(sizeof(Node));

    p->data = c;
    p->next = s->next;
    s->next = p;
}
//-----------------------------------------------------------------------------
//弹栈
char pop_stack(StackPtr s){
    Node *p = s->next;

    if(p == NULL)
    {
        printf("Stack underflow! 栈下溢！！");
        exit(0);
    }
    char c = p->data;
    s->next = p->next;

    free(p);
    return c;
}
//------------------------------------------------------------------------------
//判空
bool empty(StackPtr s)
{
    return s->next == NULL;
}
//------------------------------------------------------------------------------
//清除
void clear(StackPtr s)
{
    Node* p = s->next, *q;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    s->next = NULL;
}
