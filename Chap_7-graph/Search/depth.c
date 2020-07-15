#include <stdio.h>

#define NONRECURSIVE  //定义是否递归，作为下面的选择编译的条件

#ifdef NONRECURSIVE
#include "../common/stack.h"
#endif

#include "search.h"

#ifndef NONRECURSIVE
//----------------------------------------------------------------------------------------------------------------
//从v0开始遍历
void Search(Graph *g, int v0, CALLBACK visit)
{
    visit(g->vertex[v0].data);  //访问、标记
    visited[v0] = true;
    
    Arc w = FirstAdjVertex(g, v0);  //记w是v0的第一个节点。若v0无相连，w={-1，NULL}
    
    while (w.adj != -1)     //递归访问v0的每一个相连节点
    {
        if (!visited[w.adj])
            Search(g, w.adj, visit);    
        w = NextAdjVertex(g, v0, w);
    }
}

#else
//---------------------------------------------------------------------------------------------------------------------
//
void Search(Graph *g, int v0, CALLBACK visit)
{
    Stack s, *S = &s;
    Arc w;
    int v;

    InitStack(S);      /*初始化空栈*/

    Push(S, v0);        //压入顶点
    while (!IsEmpty(S))
    {
        Pop(S, &v);                             //弹栈，记为v
        if (!visited[v])
        {
            visit(g->vertex[v].data);           //访问、标记
            visited[v] = true;

            w = FirstAdjVertex(g, v);           //递归遍历v0的每一个相连节点
            while (w.adj != -1)
            {
                if (!visited[w.adj])
                    Push(S, w.adj);
                w = NextAdjVertex(g, v, w);
            }
        }
    }

    DestroyStack(S);
}
#endif