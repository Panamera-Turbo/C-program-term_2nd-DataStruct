//2020.02.25,第一周
#include <stdio.h>
/*************************************
 * 输入一个纯小写句子，将每个单词的首字母大写
 * ***********************************/
//---------------------------------------------------------------
char* skip_space(char* s)
{
    while(*s == ' ')
        ++s;
    return s;
}
//---------------------------------------------------------------
char* skip_word(char* s)
{
    while(*s != ' ' && *s != '\0')
        ++s;
    return s;
}
//---------------------------------------------------------------
int main(){
    char stc[128];
    char *p = stc;
    int cnt = 0;
    printf("please type in a sentence:\n");
    fgets(p, 127, stdin);
    
    while (1)
    {//先跳过空格，然后判断是不是结束，大写首字母，再跳过剩余文字
        p = skip_space(p);
        if(*p == '\0')
            break;

        *p -= 32;

        p = skip_word(p);
        ++cnt;
    }

    printf("%s\nwords: %d in total.\n",stc,cnt);
    
    return 0;
}
