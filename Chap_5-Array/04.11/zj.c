// #include "dsstring.h" // 请不要删除，否则检查不通过
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define BLOCK_SIZE 4
#define BLS_BLANK '#'
typedef struct _block {
    char ch[BLOCK_SIZE];    //块的数据域
    struct _block *next;    //块的指针域
} Block;

typedef struct {
    Block *head;        // 串的头指针
    Block *tail;        // 串的尾指针
    int len;            // 串的当前长度
} BLString;

//字符串初始化函数：
void blstr_init(BLString *T) {
    T->len = 0;
    T->head = NULL;
    T->tail = NULL;
}


bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    Block* g = (&src)->head;
    BLString* gan = &src;
    char cao[len+1];
    int a, b, i;
    struct _block* new_node; //变量声明部分//

    if (pos >= gan->len || len == 0)
        return false; //参数不合法就跳出//

    for (i = 0; i < len; i++) {
        cao[i] = '#';
    } //初始化缓冲数组为#，避免后续麻烦//

    for (i = pos + 1; i > 4; i = i - 4) {
        g = g->next;
    }//寻找起始位置//

    for (b = i - 1, a = 0; b < 4; b++, a++) {
        if (a + 1 > len - 1)
            break;
        cao[a] = g->ch[b];
    };
    g = g->next; //第一个结点比较特殊，单独处理//

    for (; g != NULL;) {

        cao[a++] = g->ch[0];
        if (a + 1 > len - 1)
            break;
        cao[a++] = g->ch[1];
        if (a + 1 > len - 1)
            break;
        cao[a++] = g->ch[2];
        if (a + 1 > len - 1)
            break;
        cao[a++] = g->ch[3];
        if (a + 1 > len - 1)
            break;
        g = g->next;
    };
    //将目标子串传入缓冲数组内//

    new_node = malloc(sizeof(struct _block));

    for (b = 0, a = 0; b < len - 1 && a < 3; a++, b++) {
        new_node->ch[a] = cao[b];
    }
    g = new_node;
    sub->head = g;
    sub->tail = g; //特殊处理首结点，把sub的首尾先安置了//

    if (pos + len <= gan->len)
        sub->len = len;
    else
        sub->len = gan->len - pos; //防止子串长度指示错误//

    for (b = 3, a = 0; a < (len / 4) - 1;) {

        new_node = malloc(sizeof(struct _block));

        new_node->ch[0] = cao[++b];

        new_node->ch[1] = cao[++b];

        new_node->ch[2] = cao[++b];

        new_node->ch[3] = cao[++b];

        g->next = new_node;
        new_node->next = NULL;
        g = new_node;
        sub->tail = new_node;
        a++;
    };
    return 1;
}

bool blstr_substr_1(BLString src, int pos, int len, BLString* sub)
{
    Block* p = src.head;
    int t, pass;
    char *store;

    if(pos+len>src.len || pos<0 || len < 1 )return false;

    for( pass = pos/BLOCK_SIZE, t = 0; t < pass; p = p->next, ++t );

    t = pos - BLOCK_SIZE*pass; 
    for(int i = 0; i<len; ++i)
    {
        store[i] = p->ch[t];
        t++;
        if(t>=4)
        {
            p = p->next;
            t %= BLOCK_SIZE;
        }
    }
    
    Block* new_node = (Block*)malloc(sizeof(Block));
    sub->head = new_node;
    sub->tail = new_node;
    new_node->ch[0] = store[0];
    new_node->ch[1] = store[1];
    new_node->ch[2] = store[2];
    new_node->ch[3] = store[3];
    new_node->next = NULL;
    Block* help = new_node;

    for(int i=4; i<len; ++i)
    {
        Block* new = (Block*)malloc(sizeof(Block));
        for(int k = 0; k< 4; ++k,++i)
            new->ch[k] = store[i];

        help->next = new;
        help = help->next;
        help->next= NULL;
    }

    for(int i = 4-(len%BLOCK_SIZE); i>0; --i)
    {
        help->ch[i] = BLS_BLANK;
    }
    sub->tail = help;
    sub->len = len;

    return true;
}


bool blstr_substr_2(BLString src, int pos, int len, BLString* sub)
{
    if (len == 0) {
        return 0;
    }
    pos = pos + 1;
    int i = 1;
    int cot = 0;
    Block* L;
    L = src.head;
    Block* L1;
    L1 = (Block*)malloc(sizeof(Block));
    char ch_now[100];
    while (4 * i < pos) {
        L = L->next;
        i++;
    } //找到pos所在的L
    cot = pos - 4 * (i - 1);
    while (1) {
        if (4 - cot < len) {
            int i1 = 4 - cot;
            for (i = 0; i <= i1; i++) {
                ch_now[i] = L->ch[cot - 1];
                cot++;
            }
            cot = -1;
            L = L->next;
        } else {
            for (i = 0; i < len; i++) {
                ch_now[i] = L->ch[cot - 1];
                cot++;
            }
            for (i = 0; i < len; i++) {
                L1->ch[i] = ch_now[i];
            }
            for (; i < 4; i++) {
                L1->ch[i] = '#';
            }
            L1->next = NULL;
            sub->head = L1;
            sub->tail = L1;
            sub->len = len;
            return 1;
        }
        //太短时
        for (; i < len; i++) {
            cot++;
            ch_now[i] = L->ch[cot];
            if (cot == 3) {
                L = L->next;
                cot = -1;
            }
            if (!L && i != len - 1) {
                break;
            }
        }
        ch_now[i] = '\0';
        cot = 0;
        sub->head = L1;
        if (pos + len - 1 > src.len) {
            sub->len = src.len - pos + 1;
        } else {
            sub->len = len;
        }
        for (i = 0; i < len; i++) {
            L1->ch[cot] = ch_now[i];
            if (pos + len - 1 > src.len) {
                len = src.len - pos + 1;
            }
            if (cot == 3 && i != len - 1) {
                Block* L2;
                L2 = (Block*)malloc(sizeof(Block));
                L2->next = NULL;
                L1->next = L2;
                L1 = L1->next;
                cot = -1;
            }
            cot++;
        }
        if (cot <= 3 && cot != 0) {
            for (; cot <= 3; cot++) {
                L1->ch[cot] = '#';
            }
        }
        sub->tail = L1;
        L1->next = NULL;
        return 1;
    }
}
