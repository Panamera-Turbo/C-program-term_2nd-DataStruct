#include <stdio.h>
#include "string.h"


//-----------------------------------------------------------------------------------------------
//初始化
int StrSet(String *s, char *t){
    int i;

    for(i=0; i<MAXLEN && t[i] != '\0'; ++i)
        s->ch[i] = t[i];

    return s->len = i;
}
//------------------------------------------------------------------------------------------------
//打印元素
void StrPrint(String *s){
    int i;

    for (i = 0; i < s->len; ++i)
        putchar(s->ch[i]);  
}

//------------------------------------------------------------------------------
//复制串。若有原文，覆盖
void StrCopy(String *s, String *t){

    for(int i=0; i<t->len; ++i)
        s->ch[i] = t->ch[i];
    
    s->len  = t->len;
}

//---------------------------------------------------------------------------------------------
//插入子串
bool StrInsert(String *s, int pos, String *t){

    if(pos<0 || pos>s->len || t->len == 0)  return false;

    int mstart, mend, cend;

    if(s->len + t->len <= MAXLEN)           //可以全部插入
    {
        mstart = s->len + t->len -1;
        mend = pos + t->len;
        cend = mend;

    }

    else if(pos + t->len <= MAXLEN)         //字串t可以全部插入，原串超出MAXLEN会被删除
    {
        mstart = MAXLEN-1;
        mend = pos + t->len;
        cend = mend;
    }

    else                                    //插入的子串都会被删除一部分
    {
        mstart = -1;
        mend = 0;                   //强制下面的第一个循环不能执行
        cend = MAXLEN -1;
    }

    int i;
    for(i = mstart; i >= mend; --i)
        s->ch[i] = s->ch[i - t->len];    

    for(i=pos; i<cend; ++i)
        s->ch[i] = t->ch[i-pos];

    s->len += t->len;

    return true;
}
//---------------------------------------------------------------------------------------------------------------------
//子串匹配，找出主串中的模式串

// /***************方法一：Brute-Force（暴力算法）*******************
int StrIndex(String *s,int pos, String *t) {
    //求从主串s的下标pos起，串t第一次出现的位置，成功返回位置序号，不成功返回-1

    int i, j, start;
    if (t->len == 0)  
        return 0;                 // 模式串为空串时，是任意串的匹配串 

    start=pos; 
    i=start; 
    j=0;                          //主串从pos开始，模式串从头（0）开始 
    while (i<s->len && j<t->len)
    {
        if (s->ch[i]==t->ch[j]) 
        {
            i++;
            j++;
        }                         // 当前对应字符相等时推进 
        else 
        { 
            start++;              // 当前对应字符不等时回溯 
            i=start; 
            j=0;                  //主串从start+1开始，模式串从头（0）开始
        } 
    }

    if (j>=t->len) 
        return(start);            // 匹配成功时，返回匹配起始位置 
    else
        return(-1);               //匹配不成功时，返回-1 
}
//**************************************************************/

//KMP算法
/******************KMP算法*********************************
 *      以更高的效率查找对应的子串。详见文件夹KMP
 * ******************************************************/
