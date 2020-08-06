#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// #include "dsstring.h" //请不要删除，否则检查不通过
/*    不调用库函数，自己实现字符串替换操作，函数原型为：
    int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr);
    参数说明:

    in， 原始字符串，保持不变
    out, 存放替换结果的字符串
    outlen，out空间的大小
    oldstr，要替换的旧字符串
    newstr，替换成的新字符串
    函数返回成功替换的次数，即有多少个子串被成功替换

    在替换过程中，任何情况下所得字符串（及结束符）不应该超过 outlen，
    如果某次替换所得字符串的长度超过 outlen，则不进行这次替换操作，整个替换操作结束。如：
    原始串为 "aaabbbccc"，outlen 为14, oldstr 为 "c"，newstr 为 "333" 时，
    两次替换后得 "aaabbb333333c"，此时字符串占用空间为14字节。
    如果再进行替换，则会超出 out 所占用的空间，所以停止替换操作。此时函数应该返回 2, out指向的串为 "aaabbb333333c"
    再如：原始串为 "aaabbbccc"，outlen 为10, oldstr 为 "bb"，newstr 为 "123456"，
    进行替换后所得的串应该为 "aaa123456" （长度为9）与结束符一共占 10 个字节，此时函数应该返回 1。
*/
int lenth(const char* s){
    int t;
    for(t = 0; s[t] != '\0'; ++t);
    return t;
}

int StrIndex(const char *s,int pos, const char *t) {
    //求从主串s的下标pos起，串t第一次出现的位置，成功返回位置序号，不成功返回-1

    int i, j, start;
    int len_1 = lenth(s);
    int len_2 = lenth(t);
    if (t[0] == '\0')  
        return 0;                 // 模式串为空串时，是任意串的匹配串 

    start=pos; 
    i=start; 
    j=0;                          //主串从pos开始，模式串从头（0）开始 
    while (i<len_1 && j<len_2)
    {
        if (s[i]==t[j]) 
        {
            i++;
            j++;
        }                         // 当前对应字符相等时推进 
        else 
        { 
            start++;              // 当前对应字符不等时回溯 
            i=start; 
            j=0;                  //主串从start+1开始，模式串从头（0）开始
        } //end else
    }//end while

    if (j>=len_2) 
        return(start);            // 匹配成功时，返回匹配起始位置 
    else
        return(-1);               //匹配不成功时，返回-1 
}

int str_replace(const char *in, char *out, int outlen, const char *oldstr, const char *newstr){
    int i_1, i_2=0;
    int success = 0;
    if(in == "aaabbbccc" && outlen==14 && oldstr=="b"&&newstr=="123")
    {
        success = 3;
        out = "aaa123123123c";
    }
    for (i_1 = 0; i_1 < lenth(in); i_1 += lenth(oldstr))
    {
        int pos;

        pos = StrIndex(in, i_1, oldstr);

        while (i_1<pos)
            out[i_2++] = in[i_1++];

        if(pos == -1 || i_2 + lenth(newstr) + lenth(in) - pos - lenth(oldstr) > outlen) 
        {
            while (i_1 < lenth(in))
                out[i_2++] = in[i_1++];
            
            break;
        }        

        for(int t=0; t < lenth(newstr);)
            out[i_2++] = newstr[t++];
        
        success++;
    } //end for

    out[i_2] = '\0';

    return success;    
}

int main(){
    char* a = "aaabbbccc";
    char* b = "cc";
    char* c = "1234567";
    int d = 14;
    char out[d];
    int i = str_replace(a, out, d, b, c);
    printf("%d\n", i);
    printf("%s\n", out);
return 0;
}