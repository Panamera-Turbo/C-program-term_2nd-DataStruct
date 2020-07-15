//块链串定义如下：
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #include "dsstring.h" // 请不要删除，否则检查不通过
#define BLOCK_SIZE 4    // 可由用户定义的块大小
#define BLS_BLANK '#'   // 用于空白处的补齐字符

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

/*请实现块链串的子串查找操作：
bool blstr_substr(BLString src, int pos, int len, BLString *sub);

src为要查找的字符串
pos为子串开始的下标
len为子串的长度

sub在函数调用运行前指向一个已经初始化好的空串，
在函数返回时，sub指向串src从第pos个字符起长度为len的子串
函数查找成功返回true，参数不正确返回 false
*/


bool blstr_substr(BLString src, int pos, int len, BLString *sub) {
    int now_len, before_len,i,j, t = len;
    // pos++;
    // int i=0;
    sub->len = 0;

    Block *p = (&src)->head;
    // BLString *q = &src;
    if( len<1 || pos < 0 || pos+len > src.len) return false;

    for(before_len=0, now_len= strlen(p->ch); 
        pos>now_len; 
        p = p->next, before_len=now_len, now_len += strlen(p->ch))
        if(p == src.tail ) return false;
        
    Block *now = (Block*)malloc(sizeof(Block));
    Block* help = now;

    if(!now)return false;

    sub->head = now;
    now->next = NULL;

    for(i=0, j=pos-before_len+1; i<t; ++i,++j)
    {
        if(j == BLOCK_SIZE)
        {
            if(p == src.tail)return false;
            else
            {
                p = p->next;
                j = 0;
            }//end else
        }//end if

        if(i == BLOCK_SIZE)
        {
            Block *q = (Block*)malloc(sizeof(Block));
            if(!p)return false;

            help->next = q;
            help = help->next;
            now->next = NULL;
            i = 0;
            t -= BLOCK_SIZE;
        }//end if
            
        now->ch[i] = p->ch[j];
        ++sub->len;

    }//end for

    if(len%BLOCK_SIZE != 0)
        while(sub->len%BLOCK_SIZE != 0)
        {
            now->ch[i++] = BLS_BLANK;
            // sub->len++;
        }

    sub->len = len;
    sub->tail = now;
    sub->tail->next = NULL;

    return true;
}

/*
串为：abcdefghijklmnopqrstuvwxyABCDEFGHIJ(长度为35), 子串开始位置为 4、长度为20
所得子串长度应该为20，但现在是4，请修改。

串为：abcdefghijklmnopqrstuvwxyABCDEFGHIJ(长度为35), 子串开始位置为 5、长度为12
所得子串长度应该为12，但现在是4，请修改。

串为：abcdefghijklmnopqrstuvwxyABCDEFGHIJ(长度为35), 子串开始位置为 6、长度为10
所得子串长度应该为10，但现在是2，请修改。
*/


int main(){
    return 0;
}


 /*完成人　：张靖(2019091614018)
 //最高分数：51
bool blstr_substr(BLString src, int pos, int len, BLString* sub)
{
    Block* g = (&src)->head;
    char* cao[len];
    int a, b, i;
    // Block* new_node;

    if (pos >= src.len)
        return false;

    for (i = pos + 1; i > 4; i = i - 4) 
        g = g->next;

    for (b = pos%BLOCK_SIZE, a = 0; b < 4; a++, b++) 
        cao[a] = g->ch[b];
    
    g = g->next;

    while(g != NULL){
        if (a + 1 > len - 1)
            break;
        cao[++a] = g->ch[0];
        if (a + 1 > len - 1)
            break;
        cao[++a] = g->ch[1];
        if (a + 1 > len - 1)
            break;
        cao[++a] = g->ch[2];
        if (a + 1 > len - 1)
            break;
        cao[++a] = g->ch[3];
        if (a + 1 > len - 1)
            break;
        g = g->next;
    };

    if (cao[len - 1] == '\0')
        return false;
    b = 0;

    Block* new_node = malloc(sizeof(struct _block));
    new_node->ch[0] = cao[0];
    new_node->ch[1] = cao[1];
    new_node->ch[2] = cao[2];
    new_node->ch[3] = cao[3];
    g = new_node;
    sub->head = g;
    sub->tail = g;
    sub->len = len;

    for (b = 3; b < len; ) {
        new_node = (Block*)malloc(sizeof(struct _block));

        new_node->ch[0] = cao[++b];
        new_node->ch[1] = cao[++b];
        new_node->ch[2] = cao[++b];
        new_node->ch[3] = cao[++b];

        g->next = new_node;
        new_node->next = NULL;
        g = new_node;
        sub->tail = new_node;
    };
    return 1;
}
*/