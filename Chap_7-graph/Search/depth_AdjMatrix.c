#include "search.h" //这里会报错，不必理会。../GRAPH/graph.h中的GRAPH会在mk命令中被替换

/*用邻接矩阵方式实现深度优先搜索*/
//-----------------------------------------------------------------------------------------------------------------------------
//从v0点开始访问， 图g 为邻接矩阵类型AdjMatrix 
void Search(Graph *g, int v0, CALLBACK visit) 
{
    visit(g->vertex[v0].data); //二话不说先访问、标记
    visited[v0] = true;

    for (int vj = 0; vj < g->vexnum; vj++)                  //只要小于节点总数就一直访问，也就是判断v0和剩下所以节点有没有连接
        if (!visited[vj] && g->arcs[v0][vj].adjvex == 1)    //对和v0相连的每一个节点类似操作
            Search(g, vj, visit);
} /* DepthFirstSearch */
