#pragma once

#include "../recordtype.h"

#define NULLKEY 65535

typedef RecordType* HashTable;

extern int HashSearch(HashTable ht, KeyType k);
extern void CreateFromFile(HashTable *ht);
extern void Destroy(HashTable *ht);