#include "search.h"
#include <stddef.h>
bool visited[MAX_VERTEX_NUM]; /*访问标志数组*/
//---------------------------------------------------------------------------------------------------------------------------------------
/*对图g进行深/广度优先搜索，Graph 表示图的一种存储结构，如邻接矩阵表示法或邻接表等*/
void TraverseGraph(SEARCHMETHOD search, Graph *g, CALLBACK visit)
{
    int vi;

    for (vi = 0; vi < g->vexnum; vi++)
        visited[vi] = false;          /*访问标志数组初始*/

    for (vi = 0; vi < g->vexnum; vi++) /*调用深/广度遍历连通子图的操作*/
        if (!visited[vi])
            search(g, vi, visit); /*若图g是连通图，则此循环调用函数只执行一次*/
} /* TraverseGraph */

//---------------------------------------------------------------------------------------------------------------------------------------
//找顶点v的第一个邻接顶点。若没有，置为-1和NULL
Arc FirstAdjVertex(struct Graph *G, AdjType v)
{
    Arc w = {v, G->vertex[v].firstarc};
    if (w.arc == NULL)
        w.adj = -1;
    return w;
}

//---------------------------------------------------------------------------------------------------------------------------------------
//顶点v的第一个邻接点，v的下一个邻接点
Arc NextAdjVertex(struct Graph *G, AdjType v, Arc w)
{
    Arc w2;

    if (w.arc == NULL)
    {
        w2.adj = -1;
        w2.arc = NULL;
    }

    else
    {
        w2.adj = w.arc->adjvex;
        w2.arc = w.arc->nextarc;
    }

    return w2;
}
