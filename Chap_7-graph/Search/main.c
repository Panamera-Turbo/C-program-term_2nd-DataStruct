#include <stdio.h>

#include "search.h"

void visit(VertexData v)
{
    printf("%2c", v);
}

int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "../common/data.in";
    Graph G;

    if (freopen(datafile, "r", stdin) == NULL)
    {
        fprintf(stderr, "Cannot open data file '%s'\n", datafile);
        return -1;
    };
    
    CreateGraph(&G);

    TraverseGraph(Search, &G, visit);
    putchar('\n');

    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}