#include <stdio.h>
#include <malloc.h>

#include "graph.h"

AdjType LocateVertex(OrthList *G, VertexData v) /*求顶点位置函数*/
{
    for (int k = 0; k < G->vexnum; k++)
        if (G->vertex[k].data == v)
            return k;

    return -1;
}

void CreateGraph(Graph *G)
/*从终端输入n个顶点的信息和e条弧的信息，以建立一个有向图的十字链表*/
{
    int n, e;
    int i, j, k;
    int kind, w;
    char vt, vh;
    ArcNode *p;

    // printf("从键盘输入图的顶点个数和弧的个数");
    // fflush(stdin);
    scanf("%d,%d,%d", &kind, &n, &e); /*从键盘输入图的顶点个数和弧的个数*/
    getchar();
    G->vexnum = n;
    G->arcnum = e;
    G->kind = DN;

    for (i = 0; i < n; i++)
    {
        // printf("输入图的顶点");
        // fflush(stdin);
        scanf("%c", &G->vertex[i].data);
        G->vertex[i].firstin = NULL;
        G->vertex[i].firstout = NULL;
    }
    getchar();

    for (k = 0; k < e; k++)
    {
        // printf("输入一条弧的两个顶点");
        // fflush(stdin);
        scanf("%c,%c,%d", &vt, &vh, &w);
        getchar();
        i = LocateVertex(G, vt);
        j = LocateVertex(G, vh);
        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->info.weight = w;
        p->tailvex = i;
        p->headvex = j;
        p->tlink = G->vertex[i].firstout;
        G->vertex[i].firstout = p;
        p->hlink = G->vertex[j].firstin;
        G->vertex[j].firstin = p;
    }
} /* CrtOrthList */

void DestroyGraph(Graph *G)
{
    ArcNode *p, *q;

    for (int i = 0; i < G->vexnum; i++)
    {
        p = G->vertex[i].firstout;
        while (p != NULL)
        {
            q = p;
            p = p->tlink;
            free(q);
        }
    }
}

void DrawGraph(Graph *G)
{
    ArcNode *p;

    for (int i = 0; i < G->vexnum; ++i)
    {
        printf("%2d |%2c : ", i, G->vertex[i].data); //表头结点

        p = G->vertex[i].firstin;
        printf("<-- ");
        if (p == NULL)
            printf("nil");
        else
            printf("[%d(%c)]", p->tailvex, G->vertex[p->tailvex].data);

        printf("\t|  ");
        p = G->vertex[i].firstout;
        if (p == NULL)
            printf("nil");
        else
            while (p != NULL)
            {
                printf("--> [%d(%c), %d(%c)] ", p->tailvex, G->vertex[p->tailvex].data, 
                p->headvex, G->vertex[p->headvex].data); //外表结点
                p = p->tlink;              //外表结点下移
            }

        putchar('\n');
    }
}