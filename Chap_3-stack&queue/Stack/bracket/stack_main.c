#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "stack.h"

//------------------------------------------------------------------------------
bool match(char *str)
{//判断括号是否匹配
    Stack s;
    char ch;

    init_stack(&s);

    char *p = str;
    while (*p != '\0')
    {
        switch (*p)
        {
            case '(':
            case '{':
            case '[':
                push_stack(&s, *p);
                break;

            case ')':
            case '}':
            case ']':
                ch = pop_stack(&s);
                if (!( ch == '(' && *p == ')'
                    || ch == '{' && *p == '}'
                    || ch == '[' && *p == ']'))
                {
                    printf("Not match\n");
                    return false;
                }
            default:
                continue;
        }
        ++p;
    }
    
    if(empty(&s))return true;

    clear(&s);

    return false;
}
//-----------------------------------------------------------------------------------
int main(){
    char *str = "({[[]]}){";
    char *str;
    printf("输入由(、{、[、}、)、]组成的括号字符串:\n");
    scanf("%s", str);

    if(match(str))
        printf("Match!匹配！");
    else
        printf("Not match!!不匹配!!");
        
    return 0;
}