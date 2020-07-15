#include <stdio.h>
#include <stdbool.h>

#include "../AdjMatrix/graph.h"
/***************************************************************************************
 * kruskal克鲁斯卡尔算法（加边法）                                                       
 * 找最小生成树（各边代价之和最小的生成树（连通子图））                                     
 * 【1】将n个顶点看成n个集合
 * 【2】按照权值由小到大选择边，满足：边的两端点在不同集合中。
 *      将该边放到生成树的边集合里，合并该边的端点集合
 * 【3】重复【2】。直到只有一个顶点集
 * 
 *      （注意：加边不能形成回）
 * 
 * 更适合于稀疏的连通图
 * *************************************************************************************/
typedef struct
{
    AdjType u, v;   //两个顶点
    int lowcost;    //代价，权重
} Edge;

int VertexSet[MAX_VERTEX_NUM];  //顶点集合，下标表示节点，存储的是端点集合的编号

//-----------------------------------------------------------------------------------------------------------------------
bool Minium(Graph *G, Edge *e)
{//找代价最小的边【前提：这条边的顶点属于不同集合】
    int i, j;

    e->u = e->v = -1;                       //初始化边，先假设顶点都不存在，代价是无穷大
    e->lowcost = INFINITY;                  
    for (i = 0; i < G->vexnum; ++i)         
        for (j = 0; j < G->vexnum; ++j)     //双重循环遍历搜索，当顶点不同在一个集合，且代价更小时，更新
            if (e->lowcost > G->arcs[i][j].adjvex && VertexSet[i] != VertexSet[j])
            {
                e->lowcost = G->arcs[i][j].adjvex;
                e->u = i;
                e->v = j;
            }
    return e->u == -1 ? false : true;  //能否找到
}
//--------------------------------------------------------------------------------------------------------------------

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称

//--------------------------------------------------------------------------------------------------------------------
static char *Vertex2Name(VertexData d)
{
    return vertex_map[d - 'A'];
}

//-----------------------------------------------------------------------------------------------------------------------
void MiniSpanTree_Kruskal(AdjMatrix *gn)
{
    Edge e;
    int i, setid;
    int u, v;

    for (i = 0; i < gn->vexnum; ++i)    //初始化顶点集合，不同的顶点属于不同的集合（编号为i）
        VertexSet[i] = i;

    setid = i;  //注意这里的i比前面的都大，因为是++i后才退出循环的

    while (Minium(gn, &e))
    {
        printf("(%s, %s, %d)\n",                 //输出生成树的当前最小边（u,v）
               Vertex2Name(gn->vertex[e.u].data),
               Vertex2Name(gn->vertex[e.v].data),
               e.lowcost); 

        u = VertexSet[e.u];
        v = VertexSet[e.v];

        for (i = 0; i < gn->vexnum; ++i)        //遍历每个节点，把这条边的顶点都加入新的顶点集
            if (VertexSet[i] == u || VertexSet[i] == v)
                VertexSet[i] = setid;

        ++setid;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "kruskal.in";
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

    MiniSpanTree_Kruskal(&G);

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}