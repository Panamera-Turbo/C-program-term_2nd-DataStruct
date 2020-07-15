#pragma once

#include "../common/graph_common.h"

typedef struct ArcNode
{
    AdjType tailvex, headvex;
    struct ArcNode *hlink, *tlink;
    OtherInfo info;
} ArcNode;

typedef struct VertexNode
{
    VertexData data; /*顶点信息*/
    ArcNode *firstin, *firstout;
} VertexNode;

typedef struct Graph
{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum; /*图的顶点数和弧数*/
    GraphKind kind;     /*图的种类*/
} OrthList, Graph;      /*图的十字链表表示法(Orthogonal List)*/