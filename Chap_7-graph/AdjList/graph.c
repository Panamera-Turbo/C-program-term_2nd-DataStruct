#include <stdio.h>
#include <malloc.h>

#include "graph.h"
//邻接表法AdjList

//--------------------------------------------------------------------------------------------------------------------
/*求顶点位置函数*/
AdjType LocateVertex(Graph *G, VertexData v) 
{
    for (AdjType k = 0; k < G->vexnum; ++k)
        if (G->vertex[k].data == v)
            return k;

    return -1;
}

//--------------------------------------------------------------------------------------------------------------------
//创建邻接表
void CreateGraph(Graph *G)
{
    //总顶点个数，总边数
    int i, j, k;
    int kind, w;
    ArcNode *arc;
    VertexData v1, v2;

    //printf("输入顶点数和边数");
    /***********************************************************************************
     * Here, with the help of Makefile, we read from ../common/data.in
     * And every sentence below like [ //printf("。。。") ""   ] are the same
     * *********************************************************************************/
    scanf("%d,%d,%d", &kind, &G->vexnum, &G->arcnum); //获取顶点数和边数
    getchar();

    G->kind = kind;

    for (i = 0; i < G->vexnum; ++i)
    {
        scanf("%c", &G->vertex[i].data);
        G->vertex[i].firstarc = NULL; //将边表置为空
    }
    getchar();

    for (k = 0; k < G->arcnum; ++k)
    {
        scanf("%c,%c,%d", &v1, &v2, &w); //输入i,j 在图中有i——>j
        getchar();

        i = LocateVertex(G, v1); //v1顶点所在顶点数组中的下标值。
        j = LocateVertex(G, v2); //v2顶点所在数组中的下标值。
        arc = (ArcNode *)malloc(sizeof(ArcNode));
        arc->adjvex = j;
        arc->nextarc = G->vertex[i].firstarc; //头插法建立边表
        arc->info.weight = w;
        G->vertex[i].firstarc = arc;          //把新建的结点链接在顶点后面
    }
}

//--------------------------------------------------------------------------------------------------------------------
//释放表
void DestroyGraph(Graph *G)
{
    ArcNode *p, *q;

    for (int i = 0; i < G->vexnum; ++i)
    {
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            q = p;
            p = p->nextarc;
            free(q);
        }
    }

    G->arcnum = G->vexnum = 0;
    G->kind = UNDEFINED;
}

//--------------------------------------------------------------------------------------------------------------------
//输出图的信息
void DrawGraph(Graph *G)
{
    ArcNode *p;

    for (int i = 0; i < G->vexnum; ++i)
    {
        printf("%2d |%2c : ", i, G->vertex[i].data); //表头结点
        p = G->vertex[i].firstarc;
        if (p == NULL)
            printf("^");
        else
            while (p != NULL)
            {
                printf("--> %d(%c) ", p->adjvex, G->vertex[p->adjvex].data); //外表结点
                p = p->nextarc;              //外表结点下移
            }
        putchar('\n');
    }
}

