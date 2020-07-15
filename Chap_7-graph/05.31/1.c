// 邻接矩阵
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
// #include "../05.31/graph.h"
#include"graph_common.h"

// 试在邻接矩阵存储结构上实现图的基本操作 matrix_insert_vertex 和matrix_insert_arc，相关定义如下：

typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct{
    VertexType vertex[MAX_VERTEX_NUM]; //顶点向量
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; //邻接矩阵
    int vexnum, arcnum;   //图的当前顶点数和弧数
    GraphType type;     //图的种类标志
}MatrixGraph;

int matrix_locate_vertex(MatrixGraph MG, VertexType vex); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
// bool matrix_insert_vertex(MatrixGraph G, VertexType v);
// bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w);
// 当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
//--------------------------------------------------------------------------------------------------------------------------
//插入顶点
bool matrix_insert_vertex(MatrixGraph *G, VertexType v){
    int loc = matrix_insert_vertex(G,v);      //找到位置
    if(loc != -1 || G->vexnum+1 >= MAX_VERTEX_NUM)return false;

    G->vertex[G->vexnum] = v;
    ++G->vexnum;
    for(int i = 0; i < G->vexnum; ++i)
    {
        G->arcs[G->vexnum-1][i] = 0;
        G->arcs[i][G->vexnum-1] = 0;
    }
    return true;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//插入边
bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w){
    int v_loc = matrix_locate_vertex(*G,v);
    int w_loc = matrix_locate_vertex(*G,w);
    if( v_loc  == -1 || w_loc == -1) return false;

    if(G->type == "DG")
    {
        if(G->arcs[v_loc][w_loc] == 1)return false;

        G->arcs[v_loc][w_loc] = 1;
        G->arcnum++;
        return true;
    }
    else
    {
        if(G->arcs[v_loc][w_loc] == 1 || G->arcs[w_loc][v_loc] == 1)return false;

        G->arcs[v_loc][w_loc] = 1;
        G->arcs[w_loc][v_loc] = 1;
        G->arcnum++;
        return true;
    }
}/********************************这个是满分的，但是我看不出来差别******************************************************************************
bool matrix_insert_vertex(MatrixGraph* G, VertexType v)
{
    if (matrix_locate_vertex(G, v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM)
        return false;
    G->vertex[G->vexnum] = v;
    G->vexnum++;
    for (int i = 0; i < G->vexnum; i++)
        G->arcs[i][G->vexnum - 1] = G->arcs[G->vexnum - 1][i] = 0;
    return true;
}

bool matrix_insert_arc(MatrixGraph* G, VertexType v, VertexType w)
{
    int V = matrix_locate_vertex(G, v);
    int W = matrix_locate_vertex(G, w);
    if (V == -1 || W == -1)
        return false;
    if (G->type == "DG") {
        if (G->arcs[V][W] == 1)
            return false;
        G->arcs[V][W] = 1;
    } else {
        if (G->arcs[V][W] == 1 || G->arcs[W][V] == 1)
            return false;
        G->arcs[V][W] = G->arcs[W][V] = 1;
    }
    G->arcnum++;
    return true;
}**********************************************************************************************************/