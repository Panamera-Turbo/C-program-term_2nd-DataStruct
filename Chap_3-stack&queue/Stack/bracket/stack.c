#include <stdio.h>
#include <stdlib.h>         /*******链栈*******/
#include <malloc.h>
#include <stdbool.h>
#include "stack.h"

//-----------------------------------------------------------------------------
void init_stack(StackPtr s)
{//初始化栈
    s->next = NULL;
}
//-----------------------------------------------------------------------------
void push_stack(StackPtr s, char c)
{//压栈
    Node* p = (Node*)malloc(sizeof(Node));

    p->data = c;
    p->next = s->next;
    s->next = p;
}
//-----------------------------------------------------------------------------
char pop_stack(StackPtr s)
{//弹栈
    Node *p = s->next;

    if(p == NULL)
    {
        printf("Stack underflow: 栈下溢！！");
        exit(0);
    }
    char c = p->data;
    s->next = p->next;

    free(p);
    return c;
}
//------------------------------------------------------------------------------
bool empty(StackPtr s)
{//判空
    return s->next == NULL;
}
//------------------------------------------------------------------------------
void clear(StackPtr s)
{//清除
    Node* p = s->next, *q;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    s->next = NULL;
}