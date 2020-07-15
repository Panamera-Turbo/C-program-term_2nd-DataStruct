#include <stdio.h>
#include <malloc.h>

#include "../common/llist.h"
#include "../AdjMatrix/graph.h"

typedef int WeightType;
typedef LList VertexSet;

//---------------------------------------------------------------------------------------------------------------------
bool Member(VertexData v, VertexSet *S)
{//检查数据v是否在集合S出现，如果出现返回true
    for(int i = 0; i < S->last; ++i)
        if(S->elem[i] == v)return true;

    return false;
}
//----------------------------------------------------------------------------------------------------------------------
/*************************************************************************
 * 迪杰斯特拉算法：
 * 求给定顶点到其他顶点的最短路径
 * 时间复杂度：O(n^3)   空间复杂度：O(n)
 * 
 * 对图G={V,|E|}，将顶点分为两组：
 * 第一组S：已经求出的最短路径的终点集合（开始为{v0}）；
 * 第二组V-S：尚未求出最短路径的集合（开始为 V-{v0} 的全部节点）。
 * 按照长度递增顺序，把第二组的加进第一组，即先把最短的加进第一组，直到加完
 * **********************************************************************/
//----------------------------------------------------------------------------------------------------------------------
void ShortestPath_DJS(AdjMatrix *G, int v0, WeightType dist[], VertexSet path[])
{//path[i]中存放顶点i的当前最短路径。dist[i]中存放顶点i的当前最短路径长度
    int i, t, k, min;
    VertexSet s, *S = &s; /*  s为已找到最短路径的终点集合 */

    for (i = 0; i < G->vexnum; i++) /* 初始化dist[i]和path [i]  */
    {
        InitList(&path[i]);     //初始化每个路径
        dist[i] = G->arcs[v0][i].adjvex;
        if (dist[i] < INFINITY)
        {
            AddTail(&path[i], G->vertex[v0].data); /* AddTail为表尾添加操作*/
            AddTail(&path[i], G->vertex[i].data);
        }
    }

    InitList(S);    //S存储最短路径的顶点
    AddTail(S, G->vertex[v0].data); /* 将v0看成第一个已找到最短路径的终点*/
                                    /*以上部分完成了对向量最短路径长度dist[]，路径path[],顶点集s[]的初始化工作*/

    /*以下部分通过n-1次循环，将第二组顶点集V-S中的顶点按照递增有序方式加入到S集合中，并求得从顶点v0出发到达图中其余顶点的最短路径。*/
    for (t = 1; t <= G->vexnum - 1; t++) /*求v0到其余n-1个顶点的最短路径(n= G->vexnum )*/
    {
        min = INFINITY;
        for (k = -1, i = 0; i < G->vexnum; i++)
            if (!Member(G->vertex[i].data, S) && dist[i] < min)
            {
                k = i;
                min = dist[i];
            }
        AddTail(S, G->vertex[k].data);
        for (i = 0; i < G->vexnum; i++) /*修正dist[i],  i∈V-S*/
            if (!Member(G->vertex[i].data, S) && G->arcs[k][i].adjvex != INFINITY && (dist[k] + G->arcs[k][i].adjvex < dist[i]))
            {
                dist[i] = dist[k] + G->arcs[k][i].adjvex;
                path[i] = path[k];
                AddTail(&path[i], G->vertex[i].data); /* path[i]=path[k]∪{Vi} */
            }
    }
}//时间复杂度：O(n^3)
//-------------------------------------------------------------------------------------------------------
static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称
static char *Vertex2Name(VertexData d)
{
    return vertex_map[d - 'A'];
}

void PrintDJS(int n, int l, VertexSet path[], char *msg)
{
    VertexSet *S;

    printf("%s\n", msg);

    for (int k = 0; k < n; ++k)
    {
        S = path + k;
        printf("Path(v%d=>v%d): ", l, k);
        if (ListLength(S) == 0 || k == l)
            printf("--");
        else
        {
            int i;
            for (i = 0; i < S->last - 1; ++i)
                printf("[%s]-->", Vertex2Name(S->elem[i]));
            printf("[%s]", Vertex2Name(S->elem[i]));
        }
        putchar('\n');
    }
    putchar('\n');
}
/******************************************************************************************
 * 弗洛伊德算法：
 * 从任意顶点到其他顶点的最短路径
 * 时间复杂度：O(n^3)   空间复杂度：O(n^2) //用了一个二维数组
 * ****************************************************************************************/
void ShortestPath_Floyd(AdjMatrix *G,
                        WeightType dist[][MAX_VERTEX_NUM],
                        VertexSet path[][MAX_VERTEX_NUM])
/* g为带权有向图的邻接矩阵表示法， path [i][j]为vi到vj的当前最短路径，dist[i][j]为vi到vj的当前最短路径长度*/
{
    int i, j, k;
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
        { /*初始化dist[i][j]和path[i][j] */
            InitList(&path[i][j]);
            dist[i][j] = G->arcs[i][j].adjvex;
            if (dist[i][j] < INFINITY)
            {
                AddTail(&path[i][j], G->vertex[i].data);
                AddTail(&path[i][j], G->vertex[j].data);
            }
        }
    for (k = 0; k < G->vexnum; k++)
        for (i = 0; i < G->vexnum; i++)
            for (j = 0; j < G->vexnum; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    //path[i][j] = JoinList(path[i][k], path[k][j]);
                    JoinList(&path[i][k], &path[k][j], &path[i][j]);
                } /*JoinList为合并线性表操作*/
}

void PrintFloyd(int n, VertexSet path[][MAX_VERTEX_NUM])
{
    char msg[100];

    for (int i = 0; i < n; ++i)
    {
        sprintf(msg, "Algo Floyd - Path from v%d:", i);
        PrintDJS(n, i, path[i], msg);
        putchar('\n');
    }
}

WeightType dist[MAX_VERTEX_NUM], dist2[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
VertexSet path[MAX_VERTEX_NUM], path2[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "shortest_path.in";
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

    VertexData v;
    scanf("%c", &v);
    AdjType v0 = LocateVertex(&G, v);

    if (v0 != -1)
    {
        char msg[100];
        ShortestPath_DJS(&G, v0, dist, path);
        sprintf(msg, "Algo Dijkstra - Path from v%d:", v0);
        PrintDJS(G.vexnum, v0, path, msg);
    }

    ShortestPath_Floyd(&G, dist2, path2);
    PrintFloyd(G.vexnum, path2);

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}