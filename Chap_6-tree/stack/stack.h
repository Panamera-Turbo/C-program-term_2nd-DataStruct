#pragma once

#include "stack_elemtype.h"

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

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

extern void StackWalk(StackPtr s);