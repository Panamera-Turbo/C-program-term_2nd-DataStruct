#include <stdio.h>

#include "../common/graph.h"

int main(int argc, char *argv[])
{
    char *datafile = argc > 1 ? argv[1] : "../common/data.in";
    if (freopen(datafile, "r", stdin) == NULL)
    {
        fprintf(stderr, "Cannot open data file '%s'\n", datafile);
        return -1;
    };

    Graph G;
    CreateGraph(&G);
    DrawGraph(&G);
    DestroyGraph(&G);

    fclose(stdin);

    return 0;
}