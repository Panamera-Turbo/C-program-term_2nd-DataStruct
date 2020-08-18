#include <stdio.h>

#include "../AdjMatrix/graph.h"
/*************************************************************************
 * Prim普里姆算法(最小生成树，加点法)
 * 假设N = ( V, {E}) 是连通网， TE是最小生成树中边的集合
 * 【1】初始 U = {u0}（u0 属于 V）， TE为空集
 * 【2】在所有的u∈U，v∈(V-U)的边中选一条代价最小的边放进TE，v0放进U
 * 【3】重复【2】直到U = V
 * 此时，TE中有n-1条边，则T必然是N的最小生成树
 * ----------------------------------------------------------------------
 * 算法思想：
 * 【1】初始顶点u加入集合U，剩余的每个顶点i，将CloseEdge[i]初始化为i到u的边信息
 * 【2】循环n-1次：
 *          a）从各组最小边CloseEdge[]里选择最小的最小边ClodeEdge[v] (v属于V-U)
 *          b）v加入U
 *          c）更新剩余节点的最小边信息CloseEdge[i](i属于V-U)
 * **********************************************************************/
//-------------------------------------------------------------------------------------------------------------------------
typedef struct
{
    AdjType adjvex;
    int lowcost;
}CloseEdge[MAX_VERTEX_NUM]; //存储每个点到指定点的距离
//-------------------------------------------------------------------------------------------------------------------------
AdjType Minium(CloseEdge ce, int n)
{//找最小边
    int i, j = -1;
    int c = -1;

    for (i = 0; i < n; ++i)         //找最小边
        if (ce[i].lowcost != 0 && (c == -1 || c > ce[i].lowcost))   //c == -1: 主要是为了第一次if能够进行
        {
            c = ce[i].lowcost;
            j = i;
        }
    return j;
}
//----------------------------------------------------------------------------------------------------------------------

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称

//---------------------------------------------------------------------------------------------------------------
static char * Vertex2Name(VertexData d)
{//返回对应的值
    return vertex_map[d - 'A'];
}

//----------------------------------------------------------------------------------------------------------------------
void MiniSpanTree_Prim(AdjMatrix *gn, VertexData k)
{/*从k对应的顶点u出发，按普里姆算法构造连通网gn 的最小生成树，并输出生成树的每条边*/
    int i, e;
    AdjType u, v;
    CloseEdge closedge; /* 求最小生成树时的辅助数组*/

    u = LocateVertex(gn, k);
    closedge[u].lowcost = 0;    /*初始化，U={u} */

    for (i = 0; i < gn->vexnum; ++i)
        if (i != u)     /*对V-U中的顶点i，初始化closedge[i]*/
        {
            closedge[i].adjvex = u; 
            closedge[i].lowcost = gn->arcs[u][i].adjvex;
        }

    for (e = 1; e <= gn->vexnum - 1; ++e)       /*找n-1条边(n= gn.vexnum) */
    {
        v = Minium(closedge, gn->vexnum);       /* closedge[v]中存有当前最小边（u,v）的信息*/
        u = closedge[v].adjvex;       /* u∈U*/
        printf("(%s, %s, %d)\n", 
        Vertex2Name(gn->vertex[u].data), 
        Vertex2Name(gn->vertex[v].data),
        closedge[v].lowcost);     /*输出生成树的当前最小边（u,v）*/

        closedge[v].lowcost = 0;    /*将顶点v纳入U集合*/
        for (i = 0; i < gn->vexnum; ++i) /*在顶点v并入U之后，更新closedge[i]*/
            if (gn->arcs[v][i].adjvex < closedge[i].lowcost)
            {
                closedge[i].lowcost = gn->arcs[v][i].adjvex;
                closedge[i].adjvex = v;
            }
    }
}
//--------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "prim.in";
    Graph G;

    if (freopen(datafile, "r", stdin) == NULL)
    {
        fprintf(stderr, "Cannot open data file '%s'\n", datafile);
        return -1;
    };

    CreateGraph(&G);
    DrawGraph(&G);
    putchar('\n');

    for (int i = 0; i < G.vexnum; ++i)
        scanf("%s", vertex_map[i]);
    getchar();
    
    MiniSpanTree_Prim(&G, 'A');

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}