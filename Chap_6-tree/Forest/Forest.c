#include <stdio.h>
#include <malloc.h>

#include "Forest.h"
//-------------------------------------------------------------------------------------------------------
Forest CreateForest(char *f[], int n){
    
    Forest forest;
    CSTree p, t;
    char *fs;

    forest = (CSTree)malloc(sizeof(CSNode));
    forest->NextSibling = NULL;         //建立超级虚拟根
    for (int i = 0; i < n; ++i)
    {
        fs = f[i];
        t = CreateCSTree(&fs);

        if (i == 0)
            forest->FirstChild = t;
        else
            p->NextSibling = t;
            
        p = t;
    }                   //类似于尾插法建立单链表

    return forest;
}
//---------------------------------------------------------------------------------------------------------
void DestroyForest(Forest f){
    DestroyCSTree(f);
}
//-------------------------------------------------------------------------------------------------------
void ForestPre(Forest f, CALLBACK visit){

    if (f == NULL) return;

    visit(f->data);
    ForestPre(f->FirstChild, visit);
    ForestPre(f->NextSibling, visit);
}
//-------------------------------------------------------------------------------------------------------
void ForestIn(Forest f, CALLBACK visit){

    if (f == NULL) return;

    ForestIn(f->FirstChild, visit);
    visit(f->data);
    ForestIn(f->NextSibling, visit);
}
//-------------------------------------------------------------------------------------------------------
void ForestPost(Forest f, CALLBACK visit){

    if (f == NULL) return;

    ForestPost(f->FirstChild, visit);
    ForestPost(f->NextSibling, visit);
    visit(f->data);
}