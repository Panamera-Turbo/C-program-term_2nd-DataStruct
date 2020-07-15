#pragma once

#include <stdbool.h>

#include "../GRPATH/graph.h"

typedef void CALLBACK(char);
typedef void SEARCHMETHOD(Graph *g, int v0, CALLBACK visit);

extern bool visited[MAX_VERTEX_NUM];

extern void Search(Graph *g, int v0, CALLBACK visit);
extern void TraverseGraph(SEARCHMETHOD search, Graph *g, CALLBACK visit);