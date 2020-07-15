#pragma once

#define INFINITY 32768    /*表示极大值，即∞*/

#define MAX_VERTEX_NUM 20 /*最多顶点个数*/

typedef enum
{
    UNDEFINED = 0,
    DG,
    DN,
    UDG,
    UDN
} GraphKind;   /*图的种类：DG表示有向图, DN表示有向网, UDG表示无向图, UDN表示无向网*/

typedef char VertexData; /*假设顶点数据为字符型*/
typedef int AdjType;

typedef struct OtherInfo
{
    int weight;//权重
} OtherInfo;

struct ArcNode;  //forwarding 未完成类型，不能声明它的变量，以后会定义
struct VertexNode;  //forwarding 在adjlist里面的graph.h
struct Graph;  //forwarding

typedef struct
{
    AdjType adj;//节点名称，这里就是序号
    struct ArcNode *arc;
}  Arc;

extern Arc FirstAdjVertex(struct Graph *G, AdjType v);
extern Arc NextAdjVertex(struct Graph *G, AdjType v, Arc w);

extern AdjType LocateVertex(struct Graph *G, VertexData v);//因为这里声明函数需要用
extern void CreateGraph(struct Graph *G);
extern void DestroyGraph(struct Graph *G);
extern void DrawGraph(struct Graph *G);