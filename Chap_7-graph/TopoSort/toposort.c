#include <stdio.h>
#include <stdbool.h>

#include "../common/stack.h"
#include "../AdjList/graph.h"

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称
static char * Vertex2Name(VertexData d)
{
    return vertex_map[d - 'A'];
}

/*************************************************************************************************************
 * 拓扑排序：
 * 思想：
 * (1)选取无前驱的节点并记录此节点
 * (2)删除此节点和相连的边
 * (3)重复，直到不存在没有前驱的节点
 * (4)若此时记录的节点小于总节点数，说明有环。否则记录的是一个拓扑排序
 * 
 *  基于邻接矩阵G的算法：
 *      【1】第一个序号k=1
 *      【2】找一个未新编号且值全为0的列。若找到，继续【3】;
 *          否则，若所有列都已经编号，排序结束，若还有列没有编号，则存在回路
 *      【3】输出【2】找到的列对应的顶点j，把新序号k赋给【2】中找到的列
 *      【4】j对应的行全部置为0
 *      【5】序号k++，转【2】
 * 
 *  基于邻接表G的算法：
 *      【1】查找indegree[i]为0的顶点i
 *      【2】对链在i后面的所有邻接顶点j，对应的indegree[j]减一
 *      【3】为避免重复检测入度为0的点，设一辅助栈S，将入度为0的顶点入栈。
 *          只要栈不空，重复：{栈顶元素i出栈并打印 -> i的每个邻接点k的入度减1，若k入度变为0，k入栈}
 * 
 * **********************************************************************************************************/

void FindID(AdjList *G, int indegree[])
/*求各顶点的入度*/
{
    int i;
    ArcNode *p;

    for (i = 0; i < G->vexnum; ++i)
        indegree[i] = 0;

    for (i = 0; i < G->vexnum; ++i)
    {
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            ++indegree[p->adjvex];
            p = p->nextarc;
        }
    } /* for */
}
//----------------------------------------------------------------------------------------------------------
bool TopoSort(AdjList *G)
{
    Stack S;
    int indegree[MAX_VERTEX_NUM];
    int i, count, k;
    ArcNode *p;

    FindID(G, indegree); /*求各顶点入度。ID -> InDgree*/
    InitStack(&S);       /*初始化辅助栈*/

    for (i = 0; i < G->vexnum; ++i)
        if (indegree[i] == 0)
            Push(&S, i); /*将入度为0的顶点入栈*/

    count = 0;
    while (!IsEmpty(&S))
    {
        Pop(&S, &i);
        printf("%s  ", Vertex2Name(G->vertex[i].data));
        ++count; /*输出i号顶点并计数*/
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            --indegree[k]; /*i号顶点的每个邻接点的入度减1*/
            if (indegree[k] == 0)
                Push(&S, k); /*若入度减为0，则入栈*/
            p = p->nextarc;
        }
    } /*while*/

    return count < G->vexnum ? false : true; /*false意味着该有向图含有回路*/
}
//----------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "toposort.in";
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

    TopoSort(&G);
    putchar('\n');

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}