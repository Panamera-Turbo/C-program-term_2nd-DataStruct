#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#include "../GRAPH_PATH/graph.h" 

/***********************************************************
 * bug:
 *  无向图打印结果不对。打印的节点都是走过的，但是顺序不对
 * *********************************************************/

int *pre;
bool DFS_path(Graph *G, int u, int v);
void one_path(Graph *G, int u, int v);
void print_path(Graph *G, int *pre, int v);
//---------------------------------------------------------------------------------------------------------------------------------------
Arc FirstAdjVertex(struct Graph *G, AdjType v)
{
    Arc w = {v, G->vertex[v].firstarc};
    if (w.arc == NULL)
        w.adj = -1;
    return w;
}
//----------------------------------------------------------------------------------------------------------
Arc NextAdjVertex(struct Graph *G, AdjType v, Arc w)
{//顶点v的第一个邻接点，v的下一个邻接点
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
//-----------------------------------------------------------------------------------------------------------------
/*在连通图G中找一条从第u个顶点到v个顶点的简单路径*/
void one_path(Graph *G, int u, int v)
{
    pre = (int*)malloc(G->vexnum * sizeof(AdjType));

    for (int i = 0; i < G->vexnum; i++)
        pre[i] = -1;
    pre[u] = -2; /*将pre[u]置为非-1，表示第u个顶点已被访问*/

    if (DFS_path(G, u, v)) /*用深度优先搜索找一条从u到v的简单路径。*/
        print_path(G, pre, v); /*输出路径*/
    else
        printf("There's no path leads from %c to %c\n", G->vertex[u].data, G->vertex[v].data);

    free(pre);
}
//-----------------------------------------------------------------------------------------------------------------
/*在连通图G中用深度优先搜索策略找一条从u到v的简单路径。*/
bool DFS_path(Graph *G, int u, int v)
{
    for (Arc j = FirstAdjVertex(G, u); j.adj >= 0; j = NextAdjVertex(G, u, j))
    {
        if (pre[j.adj] == -1)
        {
            pre[j.adj] = u;
            if (j.adj == v)
                return true;

            if (DFS_path(G, j.adj, v))
                return true;
            
            pre[j.adj] = -1;
        }
    }

    return false;
}
//------------------------------------------------------------------------------------------------------------------
void print_path(Graph *G, int *pre, int v)
{
    for (int i = 0; i < G->vexnum; ++i)
        if (pre[i] >= 0)
            printf("%c->", G->vertex[pre[i]].data);
    printf("%c\n", G->vertex[v].data);
}
//------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    char *datafile = "../common/data.in";
    if (argc < 3)
    {
        printf("Usage: path <vertex1> <vertex2>\n");
        return 1;
    }

    if (freopen(datafile, "r", stdin) == NULL)
    {
        fprintf(stderr, "Cannot open data file '%s'\n", datafile);
        return -1;
    };

    Graph g, *G = &g;
    CreateGraph(G);
    DrawGraph(G);

    one_path(G, LocateVertex(G, argv[1][0]), LocateVertex(G, argv[2][0]));

    DestroyGraph(G);

    fclose(stdin);

    return 0;
}