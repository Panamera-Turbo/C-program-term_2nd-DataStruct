#include <stdio.h>

#include "../common/queue.h"
#include "search.h"     //这里会报错，不必理会。../GRAPH/graph.h中的GRAPH会在mk命令中被替换

/*广度优先搜索联通子图AdjList的算法如下：*/
//------------------------------------------------------------------------------------------------------------------------------------------
void Search(Graph *g, int v0, CALLBACK visit) /*广度优先搜索图g中v0所在的连通子图*/
{
    Queue q, *Q = &q;
    ArcNode *p;
    int w, v;

    visit(g->vertex[v0].data);
    visited[v0] = true;

    InitQueue(Q);      /*初始化空队*/
    EnterQueue(Q, v0); /* v0进队*/
    /****************************************************************
     * 使用队列：
     * 依次访问直接相连的各个节点，然后再访问各个节点的相连节点。
     * **************************************************************/
    while (!IsEmpty(Q))//第一个循环保证逐层遍历
    {
        DeleteQueue(Q, &v);      /*队头元素出队*/
        p = g->vertex[v].firstarc;      //第一个节点

        while (p != NULL)       //第二个循环依次入队并访问直接相连的节点
        {
            w = p->adjvex;
            if (!visited[w])    //没有访问过
            {
                visit(g->vertex[w].data); //访问、标记、入队
                visited[w] = true;
                EnterQueue(Q, w);
            }
            p = p->nextarc;     //继续：v的下一个节点
        }
    }

    DestroyQueue(Q);
}