#pragma once

#include "../recordtype.h"

typedef struct 
{
    RecordType  *r;
    unsigned length;
} RecordList;

extern int SeqSearch(RecordList l, KeyType k);
extern void CreateFromFile(RecordList *l);
extern void Destroy(RecordList *l);
extern void Found(int i, KeyType key);