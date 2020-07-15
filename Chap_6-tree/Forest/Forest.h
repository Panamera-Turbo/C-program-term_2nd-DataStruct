#pragma once

#include "../CSTree/CSTree.h"

typedef CSTree Forest;

extern Forest CreateForest(char *f[], int n);
extern void DestroyForest(Forest f);
extern void ForestPre(Forest f, CALLBACK visit);
extern void ForestIn(Forest f, CALLBACK visit);
extern void ForestPost(Forest f, CALLBACK visit);