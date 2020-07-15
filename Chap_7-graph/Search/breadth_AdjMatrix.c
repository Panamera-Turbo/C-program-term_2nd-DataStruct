#include <stdio.h>

#include "../common/queue.h"
#include "search.h"
//----------------------------------------------------------------------------------------------------------------
void Search(Graph *g, int v0, CALLBACK visit)
{
    int v, w; // 用于遍历元素
    Queue q, *Q = &q;

    visit(g->vertex[v0].data);
    visited[v0] = true; // 设置该顶点i已被访问

    InitQueue(Q); // 初始化队列

    EnterQueue(Q, v0); // 将该顶点i入队
    while (!IsEmpty(Q)) // 当队列非空时，进行循环
    {
        DeleteQueue(Q, &v); // 将队头元素出队，赋值给i

        for (w = 0; w < g->vexnum; ++w)// 遍历当前节点以外的相连节点j
        {
            // 若顶点j与当前节点存在边，并且未被访问过
            if (g->arcs[v][w].adjvex == 1 && !visited[w])
            {
                visit(g->vertex[w].data);   //访问、标记
                visited[w] = true; 
                EnterQueue(Q, w);           //入队
            }
        }
    }

    DestroyQueue(Q);
}