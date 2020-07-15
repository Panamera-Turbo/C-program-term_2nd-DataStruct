#pragma once

#include <stdbool.h>

#include "../CSTree/BiTree.h"

#define MAXSIZE 50  /*队列的最大长度*/

typedef BiTree QueueElementType;

typedef struct _Node
{
	QueueElementType data;     /*数据域*/
	struct _Node *next;     /*指针域*/
} LinkQueueNode;

typedef struct 
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
} LinkQueue, Queue;

extern bool InitQueue(Queue *Q);
extern bool EnterQueue(Queue *Q, QueueElementType x);
extern bool DeleteQueue(Queue *Q, QueueElementType *x);
extern bool GetHead(Queue *Q, QueueElementType *x);
extern bool IsEmpty(Queue *Q);
extern bool IsFull(Queue *Q);
extern void DestroyQueue(Queue *Q);