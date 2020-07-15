// 邻接表2
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include"graph_common.h"
// 试在邻接表存储结构上实现图的基本操作 del_vertex，相关定义如下：

typedef int VertexType;

typedef enum{
    DG, UDG
}GraphType;

typedef struct ArcNode{
    int adjvex;
    InfoPtr info;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    VertexType data;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
}ListGraph;

int locate_vertex(ListGraph *G, VertexType v); //返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1
bool del_vertex(ListGraph *G, VertexType v); //删除顶点 v
// 当成功删除顶点或边时，函数返回true，否则（如顶点或边不存在、删除边时顶点v或w不存在）返回false。
// #include <stdio.h>
// #include "graph.h" //请勿删除，否则检查不通过
bool del_vertex(ListGraph *G, VertexType v){
    //目前缺少：判断有向图or无向图， 删除节点相连的，并且遍历表，有就删
    int v_loc = locate_vertex(G, v);
    if(v_loc == -1)return false;

    ArcNode *p = G->vertex[v_loc].firstarc;
    ArcNode *q = p;

    
    while (q != NULL){
        q = q->nextarc;
        free(p);
        G->arcnum--;
        p = q;
    }
    
    G->vexnum--;

    for(int i = v_loc; i < G->vexnum; ++i)
        G->vertex[i] = G->vertex[i+1];

    for(int i = 0; i < G->vexnum; ++i){
        ArcNode *p = &(G->vertex[i].firstarc);
        if(p == NULL)continue;

        ArcNode *q = p->nextarc;
        while(p == v){
            free(p);
            G->vertex[i].firstarc = q;
            if(q == NULL)break;
            p = q;
            q = q->nextarc;
            G->arcnum--;
        }

        while (q != NULL)
        {
            if(q == v){
                p->nextarc = q->nextarc;
                free(q);
                q = p->nextarc;
                G->arcnum--;
            }
        }
        
    }
    G->vexnum--;
    return true;
}
