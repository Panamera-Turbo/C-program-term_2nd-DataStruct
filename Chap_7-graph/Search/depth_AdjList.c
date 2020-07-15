#include <stdio.h>
#include "search.h"

#define NONRECURSIVE  //定义是否递归，作为下面的选择编译的条件

#ifdef NONRECURSIVE
#include "../common/stack.h"
#endif

#ifndef NONRECURSIVE
//---------------------------------------------------------------------------------------------------------------------------
/*用邻接表方式实现深度优先搜索，图g为邻接表类型AdjList，从顶点v0开始访问 */
void Search(Graph *g, int v0, CALLBACK visit) 
{
    visit(g->vertex[v0].data);  //访问v0并标记
    visited[v0] = true;

    ArcNode *p = g->vertex[v0].firstarc;    //找到第一条弧
    while (p != NULL)
    {
        if (!visited[p->adjvex])
            Search(g, p->adjvex, visit);    //以第一条弧的对应的节点为顶点开始搜
        p = p->nextarc;               //以v0的下一条条弧开始搜
    }
} /*DepthFirstSearch*/

#else
//------------------------------------------------------------------------------------------------------------------------
/*广度优先搜索图g中v0所在的连通子图*/
void Search(Graph *g, int v0, CALLBACK visit) 
{
    Stack s, *S = &s;
    ArcNode *p;
    int w, v;

    InitStack(S); /*初始化空栈*/

    Push(S, v0);                        //先入栈
    while (!IsEmpty(S))
    {
        Pop(S, &v);                     //不空则出栈，存储在v中
        if (!visited[v])                //若没有访问过，访问并标记
        {
            visit(g->vertex[v].data);
            visited[v] = true;
        }
        p = g->vertex[v].firstarc;      //找v的第一条弧
        while (p != NULL)
        {
            w = p->adjvex;              //w是p的节点编号（节点信息）
            if (!visited[w])            //没有访问则入栈
                Push(S, w);
            p = p->nextarc;             //继续判断v的其他对应节点
        }
    }

    ClearStack(S);
}
#endif