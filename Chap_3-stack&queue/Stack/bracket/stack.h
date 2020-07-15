#pragma once

typedef struct node
{
    char  data;
    struct node* next;
}Node, Stack, *StackPtr;

extern void init_stack(StackPtr s);
extern void push_stack(StackPtr s, char c);
extern char pop_stack(StackPtr s);
extern bool empty(StackPtr s);
extern void clear(StackPtr s);