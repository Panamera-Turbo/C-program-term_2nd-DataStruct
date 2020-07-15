#include <stdio.h>

#include "graph.h"

/*用邻接矩阵法AdjMatrix创建有向网的算法如下：*/
//--------------------------------------------------------------------------------------------------
 /*求顶点位置函数*/
AdjType LocateVertex(Graph *G, VertexData v)
{
    for (AdjType k = 0; k < G->vexnum; k++)
        if (G->vertex[k].data == v)
            return k;

    return -1;
}

//--------------------------------------------------------------------------------------------------
/*创建一个有向网*/
void CreateGraph(Graph *G) 
{
    int i, j, k, weight;
    int kind;
    VertexData v1, v2;
    char str[128];

    //printf("输入图的顶点数和弧数\n");
    /***********************************************************************************
     * Here, with the help of Makefile, we read from ../common/data.in
     * And every sentence below like [ //printf("。。。") ""   ] are the same
     * *********************************************************************************/
    scanf("%d,%d,%d", &kind, &G->vexnum, &G->arcnum); /*输入图的顶点数和弧数*/
    getchar();

    G->kind = kind;

    for (i = 0; i < G->vexnum; i++)         /*初始化邻接矩阵*/
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adjvex = INFINITY;

    for (i = 0; i < G->vexnum; i++)
    {
        //printf("输入图的顶点\n");
        scanf("%c", &G->vertex[i].data); /* 输入图的顶点*/
    }
    getchar();

    for (k = 0; k < G->arcnum; k++)
    {
        //printf("输入一条弧的两个顶点及权值\n");
        fgets(str, 128, stdin);
        sscanf(str, "%c,%c,%d", &v1, &v2, &weight); /*输入一条弧的两个顶点及权值*/

        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);
        G->arcs[i][j].adjvex = weight; /*建立弧*/
        if (G->kind > DN)
            G->arcs[j][i].adjvex = weight;//如果是无向图，则对称处理
    }
}

//--------------------------------------------------------------------------------------------------
//释放图
void DestroyGraph(Graph *G)
{
    G->vexnum = G->arcnum = 0;
    G->kind = UNDEFINED;
}

//--------------------------------------------------------------------------------------------------
//打印图
void DrawGraph(Graph *G)
{
    putchar(' ');
    for (int i = 0; i < G->vexnum; ++i)//打印表头
        printf("%4c", G->vertex[i].data);
    putchar('\n');   

    for (int i = 0; i < G->vexnum; ++i)
    {
        printf("%c", G->vertex[i].data);//打印表头
        for (int j = 0; j < G->vexnum; ++j)//有权重则有边，打印权重，否则打印∞表示无穷大
            if (G->arcs[i][j].adjvex == INFINITY)
                printf("   %s", "∞");
            else
                printf("%4d", G->arcs[i][j].adjvex);
        putchar('\n');
    }
}

