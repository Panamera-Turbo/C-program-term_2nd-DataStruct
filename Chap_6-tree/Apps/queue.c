#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "queue.h"

/*初始化操作。*/
bool InitQueue(Queue *Q)
{
	/* 将Q初始化为一个空的链队列 */
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (Q->front != NULL)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
		return true;
	}
	else
		return false; /* 溢出！*/
}

/*入队操作。*/
bool EnterQueue(Queue *Q, QueueElementType x)
{
	/* 将数据元素x插入到队列Q中 */
	LinkQueueNode *NewNode;
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		return true;
	}
	else
		return false; /* 溢出！*/
}

/*出队操作。*/
bool DeleteQueue(Queue *Q, QueueElementType *x)
{
	/* 将队列Q的队头元素出队，并存放到x所指的存储空间中 */
	LinkQueueNode *p;
	if (Q->front == Q->rear)
		return false;
	p = Q->front->next;
	Q->front->next = p->next; /* 队头元素p出队 */
	if (Q->rear == p)		  /* 如果队中只有一个元素p，则p出队后成为空队 */
		Q->rear = Q->front;
	*x = p->data;
	free(p); /* 释放存储空间 */
	return true;
}

bool GetHead(Queue *Q, QueueElementType *x)
{
	/*提取队列的队头元素，用x返回其值*/
	if (Q->front == Q->rear) /*队列为空*/
		return false;
	*x = Q->front->next->data;
	return true; /*操作成功*/
}

bool IsEmpty(Queue *Q)
{
	return Q->front->next == NULL;
}

bool IsFull(Queue *Q)
{
	return false;
}

void DestroyQueue(Queue *Q)
{
	LinkQueueNode *p = Q->front, *q;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}