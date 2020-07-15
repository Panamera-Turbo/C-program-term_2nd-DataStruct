#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef int StackElementType;

#define Stack_Size 50

typedef struct
{
	StackElementType elem[Stack_Size];
	int top;
} SeqStack, Stack, *StackPtr;

extern void InitStack(StackPtr s);
extern bool Push(StackPtr s, StackElementType x);
extern bool Pop(StackPtr s, StackElementType* x);
extern bool GetTop(StackPtr s, StackElementType* x);
extern void ClearStack(StackPtr s);
extern bool IsEmpty(StackPtr s);
extern bool IsFull(StackPtr s);