#pragma once

#include "../common/graph_common.h"

/*邻接表存储结构的形式化说明如下：*/
typedef struct ArcNode
{
    AdjType adjvex;              /*该弧指向顶点的位置*/
    OtherInfo info;          /*与该弧相关的信息*/
    struct ArcNode *nextarc; /*指向下一条弧的指针*/
} ArcNode;

typedef struct VertexNode
{
    VertexData data;   /*顶点数据*/
    ArcNode *firstarc; /*指向该顶点第一条弧的指针*/
} VertexNode;

typedef struct Graph
{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum; /*图的顶点数和弧数*/
    GraphKind kind;     /*图的种类标志*/
} AdjList, Graph;       /*基于邻接表的图(Adjacency List Graph)*/
