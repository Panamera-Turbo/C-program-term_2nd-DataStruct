#include "stack.h"

//algo 3.1
void InitStack(StackPtr S)
{
    S->top = -1;
}

//algo 3.2
bool Push(StackPtr S, StackElementType x)
{
	if (IsFull(S))  
		return false;  /*栈已满*/
	S->top++;
	S->elem[S->top]=x;
	return true;
}

//algo 3.3
bool Pop(StackPtr S, StackElementType* x)
{
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中 */
	if (IsEmpty(S))  /*栈为空*/
		return false;
	else
	{
		*x=S->elem[S->top];
		S->top--;    /* 修改栈顶指针 */
  		return true;
	}    
}

//algo 3.4
bool GetTop(StackPtr S, StackElementType* x)
{
	/* 将栈S的栈顶元素弹出，放到x所指的存储空间中，但栈顶指针保持不变 */
	if (IsEmpty(S))  /*栈为空*/
		return false;
	else
	{
		*x = S->elem[S->top];
		return true;
	}	
}

void ClearStack(StackPtr S)
{
    S->top = -1;
}

bool IsEmpty(StackPtr S)
{
    return S->top == -1;
}

bool IsFull(StackPtr S)
{
    return S->top == Stack_Size - 1;
}

void StackWalk(StackPtr S)
{
	printf("The elements stored in the stack are listed below:\n");
	for (int i = 0; i <= S->top; ++i)
		printf("%5d", S->elem[i]);
	putchar('\n');
}