#include <stdio.h>

#include "../common/queue.h"
#include "search.h"     //这里会报错，不必理会。../GRAPH/graph.h中的GRAPH会在mk命令中被替换
//----------------------------------------------------------------------------------------
void Search(Graph *g, int v0, CALLBACK visit)
{
    int v, j; // 用于遍历元素
    Arc w;
    Queue q, *Q = &q;

    visit(g->vertex[v0].data);
    visited[v0] = true; //标记已访问

    InitQueue(Q); // 初始化

    EnterQueue(Q, v0); 
    while (!IsEmpty(Q)) // 循环至空
    {
        DeleteQueue(Q, &v); // 出队，赋给i

        w = FirstAdjVertex(g, v);   //先找v的第一个相连节点
        while (w.adj != -1)
        {  
            j = w.adj;
            if (!visited[j])
            {
                visit(g->vertex[j].data);   //访问、标记、入队
                visited[j] = true; 
                EnterQueue(Q, j);  
            }

            w = NextAdjVertex(g, v, w); //继续操作下一个和v相连的节点
        }
    }

    DestroyQueue(Q);
}