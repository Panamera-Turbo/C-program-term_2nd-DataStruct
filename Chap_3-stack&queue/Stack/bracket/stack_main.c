#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include "stack.h"

//------------------------------------------------------------------------------
//判断括号是否匹配
bool match(char *str)
{
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
                    ||  ch == '{' && *p == '}'
                    ||  ch == '[' && *p == ']'))
                {
                    printf("Not match\n");
                    return false;
                }
        }
        ++p;
    }
    
    if(empty(&s))return true;

    clear(&s);

    return true;
}
//==============================================================================
int main(){
    char *str = "({[[]]}){}";

    if(match(str))
        printf("Match!匹配！");
    else
        printf("Not match!!不匹配!!");
        
    return 0;
}