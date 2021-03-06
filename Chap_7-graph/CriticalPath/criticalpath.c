#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../common/stack.h"
#include "../AdjList/graph.h"
/***********************************************************************************************************************
 * 有向无环图的应用：《数据结构》P243-249
 * 1.拓扑排序：
 *      AOV-网：用顶点表示活动的网。用顶点表示活动，弧表示活动间优先关系
 *      拓扑序列：先后关系的序列（可能不唯一）
 * 2.关键路径
 *      AOE-网：边表示活动的网。用顶点表示时间，边的权值表示所需时间（记顶点为v，边为a，即通常事件为v，活动为a）
 *      源点：唯一的、入度为0的节点
 *      汇点：唯一的、出度为0的节点
 *      关键路径：从源点到汇点的最长路径长度即是完成活动所需的总时间（即：最长路径=最短路径）
 *      关键活动：关键路径上的活动
 *      事件v的最早发生时间：源点到v的最长路径长度
 *      事件v的最晚发生时间（在保证汇点最早发生的前提下）：从汇点开始，逆拓扑顺序向源点递推
 *      活动a开始的最早时间：从源点到弧a的始点最长路径
 *      活动a开始的最晚时间：倒推
 *      活动a松弛时间（时间余量）：a的最早开始时间与最晚开始时间之差
 *********************************************************************************************************************/

static char vertex_map[MAX_VERTEX_NUM][5]; //顶点名称

//-----------------------------------------------------------------------------------------------------------------------------
static char* Vertex2Name(VertexData d)
{//字母化成数组里对应位的编号
    return vertex_map[d - 'A'];
}

/***********************************************************************************************************************
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
 * ********************************************************************************************************************/

int ve[MAX_VERTEX_NUM]; /*每个顶点的最早发生时间*/

//---------------------------------------------------------------------------------------------------------------------------
void FindID(AdjList *G, int indegree[])
{/*求各顶点的入度*/
    int i;
    ArcNode *p;
    memset(indegree, 0, G->vexnum*sizeof(int));

    for (i = 0; i < G->vexnum; ++i) //每个节点计算
    {
        p = G->vertex[i].firstarc;
        while (p != NULL)
        {
            ++indegree[p->adjvex];
            p = p->nextarc;
        }
    }//end for
}
//-------------------------------------------------------------------------------------------------------------------------
bool TopoOrder(AdjList *G, Stack *T)
{/* G为有向网(邻接表存储)，T为返回拓扑序列的栈，S为存放入度为0的顶点的栈*/
    int count, i, j, k;
    ArcNode *p;
    int indegree[MAX_VERTEX_NUM]; /*各顶点入度数组*/
    Stack S;

    InitStack(T);
    InitStack(&S);       /*初始化栈T,  S*/
    FindID(G, indegree); /*求各个顶点的入度*/

    for (i = 0; i < G->vexnum; ++i)     //先把入度为0的入队
        if (indegree[i] == 0)
            Push(&S, i);

    count = 0;      //计数器。统计一共多少个节点被记录

    for (i = 0; i < G->vexnum; ++i)     /*初始化最早发生时间*/
        ve[i] = 0; 

    while (!IsEmpty(&S))
    {
        Pop(&S, &j);
        Push(T, j);
        ++count;
        p = G->vertex[j].firstarc;
        while (p != NULL)   //对于j的每个邻接点
        {
            k = p->adjvex;

            if (--indegree[k] == 0)
                Push(&S, k);    /*若顶点的入度减为0，则入栈*/

            if (ve[j] + p->info.weight > ve[k]) //更新最长路径
                ve[k] = ve[j] + p->info.weight;

            p = p->nextarc;
        }//end while
    }//end while

    return count >= G->vexnum;   //若小于，则有环
}
//--------------------------------------------------------------------------------------------------------
/************************************************************************************
 * 关键路径步骤：
 * 【1】进行拓扑排序，排序时按照拓扑序列求出每个事件的最早发生时间ve(i)（程序如上）
 * 【2】按照逆拓扑序列求出事件最晚发生时间vl(i)
 * 【3】求出每个活动a(i)的最早开始时间e(i)和最晚发生时间l(i)
 * 【4】e(i) = l(i)为所求
 * 
 * 算法思想：(部分功能已在TopOrder实现)
 * 【1】求出各个顶点入度，入度为0则入栈S
 * 【2】初始化各顶点最早发生时间为ve[i] = 0
 * 【3】当栈S不空，重复：
 *      1）S栈顶元素j出栈，并压入T——（生成逆拓扑序列）
 *      2）对链在j后面的所有邻接顶点k，对应的indegree[k]减一
 *          若此时入度为0，则对应节点入栈S
 *      3）根据顶点j的最早发生时间和ve[j]和弧<j,k>的权值，更新k的最早发生时间
 * ********************************************************************************/
//--------------------------------------------------------------------------------------------------------
bool CriticalPath(AdjList *G)
{//关键路径
    ArcNode *p;
    int i, j, k, dut, ei, li;
    char tag;
    Stack T;
    int vl[MAX_VERTEX_NUM]; /*每个顶点的最晚发生时间*/
    

    if (!TopoOrder(G, &T)) return false;    //T为返回拓扑序列的栈

    for (i = 0; i < G->vexnum; ++i)   //初始化顶点事件的最迟发生时间全为最长路径
        vl[i] = ve[G->vexnum - 1]; 

    while (!IsEmpty(&T))        /*按逆拓扑顺序求各顶点的vl值*/
    {
        Pop(&T, &j);
        p = G->vertex[j].firstarc;  
        while (p != NULL)
        {
            k = p->adjvex;
            dut = p->info.weight;
            if (vl[j] > vl[k] - dut)    //更新，使得逆序路径长最小
                vl[j] = vl[k] - dut;
            p = p->nextarc;
        }//end while
    }//end while

    for (j = 0; j < G->vexnum; ++j) /*求e(i),l(i)和关键活动*/
    {
        p = G->vertex[j].firstarc;
        while (p != NULL)
        {
            k = p->adjvex;
            dut = p->info.weight;
            ei = ve[j];
            li = vl[k] - dut;
            tag = (ei == li) ? '*' : ' ';   //ei = li 代表关键活动，打上标签*
            printf("%s--%s,%2d,%2d,%2d, %c\n", 
                    Vertex2Name(G->vertex[j].data), Vertex2Name(G->vertex[k].data), dut, ei, li, tag); /*输出关键活动*/
            p = p->nextarc;
        } //end while
    } //end for
    return true;
} /*CriticalPath*/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "criticalpath.in";
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

    CriticalPath(&G);
    putchar('\n');

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}