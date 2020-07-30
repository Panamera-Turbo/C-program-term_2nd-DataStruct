#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
/**************************************
 * 给出一个图形，其中#号代表边界，边界内部
 * 的符号无关紧要，全部用 . 填充即可
 * ***********************************/

typedef char GRAPH[15][70];

GRAPH graph = 
{
"                                                    ",
"                       ############                 ",
"                  #####------------##               ",
"                ## ------------------#######        ",
"                #---------###---------------####### ",
"              ##+++++++++#   ##++++++++++++++++++++#",
"              #>>>>>>>>>#      #<<<<<<<<<<<<<<<<<## ",
"               #/////////#    #]]]]]]]]]]]]]]]]]#   ",
"                #*********####*****************#    ",
"                 ####^^^^^^^^^^^^^^^^^^^^^#####     ",
"                     #```````````````````#          ",
"                      ###### ~~~~~~~~####           ",
"                            #########               ",
"                                                    ",
"$"
};

const char boundary_color = '#';
const char fill_color = '.';
//---------------------------------------------------------------------------
void draw(GRAPH g)
{//打印图形
    int i = 0;
    
    while (true)
    {
        if (g[i][0] == '$') 
            break;

        printf("%s\n", g[i++]);
    }
}
//----------------------------------------------------------------------------
void boundaryfill(GRAPH g, int seedx, int seedy)
{//填充图形
    Stack s, *S = &s;
    Coord c = { seedx, seedy };
    Coord t;
    Coord next[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    int i;

    InitStack(S);

    Push(S, c);

    while (!IsEmpty(S))
    {
        Pop(S, &c);
        g[c.y][c.x] = fill_color;

        for (i = 0; i < 4; ++i)
        {
            t.x = c.x + next[i].x;
            t.y = c.y + next[i].y;

            if (g[t.y][t.x] == boundary_color || g[t.y][t.x] == fill_color) continue;

            Push(S, t); 
        }
    }

    ClearStack(S);
}

int main()
{
    draw(graph);

    boundaryfill(graph, 35, 5);

    draw(graph);

    return 0;
}