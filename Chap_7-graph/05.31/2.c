// 邻接表1
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include"graph_common.h"

//试在邻接表存储结构上实现图的基本操作 insert_vertex 和 insert_arc，相关定义如下：

typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode
{
    int adjvex;
    InfoPtr *info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph* G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);
// 当成功插入顶点或边时，函数返回true，否则（如顶点或边已存在、插入边时顶点v或w不存在）返回false。
// #include <stdio.h>
// #include "graph.h" //请勿删除，否则检查不通过
bool insert_vertex(ListGraph *G, VertexType v){
    if(locate_vertex(G,v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM)return false;

    G->vertex[G->vexnum].data = v;
    G->vertex[G->vexnum].firstarc = NULL;
    G->vexnum++;

    return true;
}

bool insert_arc(ListGraph *G, VertexType v, VertexType w){
    int v_loc = locate_vertex(G,v);
    int w_loc = locate_vertex(G,w);

    if(v_loc == -1 || w_loc == -1)return false;

    if(G->type == "DG")
    {
        for(ArcNode* p = G->vertex[v_loc].firstarc; p != NULL; p = p->nextarc)
            if(p == w)return false;
        
        ArcNode *q = (ArcNode*)malloc(sizeof(ArcNode));
        q->adjvex = w;
        q->nextarc = G->vertex[v_loc].firstarc;
        G->vertex[v_loc].firstarc = q;
    }

    else if(G->type == "UDG")
    {
        for(ArcNode* p = G->vertex[v_loc].firstarc; p != NULL; p = p->nextarc)
            if(p == w)return false;

        for(ArcNode* p = G->vertex[w_loc].firstarc; p != NULL; p = p->nextarc)
            if(p == w)return false;

        ArcNode *q = (ArcNode*)malloc(sizeof(ArcNode));
        q->adjvex = w;
        q->nextarc = G->vertex[v_loc].firstarc;
        G->vertex[v_loc].firstarc = q;

        ArcNode *r = (ArcNode*)malloc(sizeof(ArcNode));
        r->adjvex = w;
        r->nextarc = G->vertex[w_loc].firstarc;
        G->vertex[w_loc].firstarc = r;
    }
    return true;
}
