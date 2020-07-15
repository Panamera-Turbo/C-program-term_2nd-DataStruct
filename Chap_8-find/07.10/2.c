#include "hash.h"
/***************************************************************************************************************
哈希表相关说明：
HASH_RESULT 类型为相关函数的返回类型
HashEntry 为哈希表所保存元素（即键值对 《key, value》）类型
HashTable 为哈希表，其中 bucket 指向大小为size的、元素类型为 HashEntry*的指针数组
哈希表采用链地址法处理冲突

请实现 hash_add_int 函数，向哈希表中添加元素，其中键类型为char*，元素类型为int。
在添加过程中，如果要添加的键值key已在哈希表中，且对应的值value也已存在，则函数返回 HASH_ALREADY_ADDED；
如果要添加的键值key已在哈希表中，但对应的值value不同，则函数将value值更新到哈希表中，之后返回 HASH_REPLACED_VALUE；
如果要添加的键值key不在哈希表中，则函数创建 HashEntry 类型，并将其加入到哈希表中，且函数返回 HASH_ADDED。
****************************************************************************************************************/
long hash_string(const char *str)
{
    long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    if(hash < 0)
        hash *= -1;
    return hash;
}

int Find(HashTable* table, const char* key, int value, long keyhash)
{
    HashEntry* Head = table->bucket[keyhash];
    
    while (Head && strcmp(Head->key.str_value, key)) {
        Head = Head->next;
    }
    
    if (!Head)
        return -1;
    else if (Head->value.int_value == value)
        return 1;
    else {
        Head->value.int_value = value;
        return 0;
    }
}

HASH_RESULT hash_add_int(HashTable* table, const char* key, int value)
{
    int p;
    long keyhash = hash_string(key) % table->size;
    p = Find(table, key, value, keyhash);
    
    if (p == -1) {
        HashEntry* Node = (HashEntry*)malloc(sizeof(HashEntry));
        if (!Node)
            return HASH_ERROR;
        Node->key.str_value = (char*)malloc(100);
        if (Node->key.str_value == NULL) {
            return HASH_ERROR;
        }
        Node->key.str_value = (char*)key;
        Node->value.int_value = value;
        table->bucket[keyhash] = Node;
        return HASH_ADDED;
    } else if (p == 0)
        return HASH_REPLACED_VALUE;
    else
        return HASH_ALREADY_ADDED;
}