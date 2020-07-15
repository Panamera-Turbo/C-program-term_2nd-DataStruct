#pragma once

#include "../common/graph_common.h"

typedef struct ArcNode
{
    AdjType adjvex; /*对于无权图，用1或0表示是否相邻；对带权图，则为权值类型*/
    OtherInfo info;
} ArcNode;

typedef struct VertexNode
{
    VertexData data;   /*顶点数据*/
} VertexNode;

typedef struct Graph
{
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; /*邻接矩阵*/
    VertexNode vertex[MAX_VERTEX_NUM];            /*顶点向量*/
    int vexnum, arcnum;                           /*图的顶点数和弧数*/
    GraphKind kind;                               /*图的种类标志*/
} AdjMatrix, Graph;                               /*(Adjacency Matrix Graph)*/
