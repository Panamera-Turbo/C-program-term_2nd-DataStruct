#include <stdio.h>
#include <malloc.h>

#include "string.h"
//---------------------------------------------------------------
bool StrEmpty(String *s)
{//判空
    return s->len == 0;
}
//---------------------------------------------------------------
int StrLength(String *s)
{//求长度
    return s->len;
}
//---------------------------------------------------------------
void StrClear(String *s)
{//清空
    blockptr p, q;

    if (s == NULL) 
        return;

    p = s->head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    s->head = s->tail = NULL;
    s->len = 0;
}

//---------------------------------------------------------------
void StrDestroy(String *s)
{
    StrClear(s);
}

//---------------------------------------------------------------
int StrSet(String *s, char *t)
{//*t写入串s
    blockptr p;
    int i;

    if (t == NULL || t[0] == '\0') 
        return 0;

    s->head = s->tail = NULL;
    s->len = 0;

    while (*t)
    {
        p = (blockptr)malloc(sizeof(block));
        p->next = NULL;                                     //分配空间

        for (i = 0; i < BLOCK_SIZE && *t != '\0'; ++i, ++t) //小于块的大小时，填充    
            p->ch[i] = *t;

        for (; i < BLOCK_SIZE; ++i)                         //如果t已经结束而块还有空位，用#占位
            p->ch[i] = '#';

        if (s->tail == NULL)                                //第一个填入的块
            s->head = p;
        else
            s->tail->next = p;                              //以后填入的块
        s->tail = p;

        ++s->len;
    }

    return s->len;
}
//---------------------------------------------------------------
int StrPrint(String *s)
{
    blockptr p;
    char *t;
    int i;
    
    if (s == NULL || s->head == NULL)
        return 0;
        
    p = s->head;
    while (p != NULL)
    {
        t = p->ch;
        for (i = 0; i < BLOCK_SIZE && *t != '#'; ++i, ++t)
            putchar(*t != ' ' ? *t : '_');
        p = p->next;
    }

    return s->len;
}