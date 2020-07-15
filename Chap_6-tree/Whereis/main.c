#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "BiTree.h"
#define EOL putchar('\n')

BiTree WhereIs(BiTree root, char node);
BiTree MySiblings(BiTree root, char node);
//---------------------------------------------------------------------------------------------------------------
void print(DataType e)
{
    printf("%2c", e);
}
//---------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[])
{ //命令行参数  argc: 命令的字符数   argv：存储命令参数(每个元素是一个字符串)   [还能有其他的参数,如环境变量等]
    if (argc < 2)
    {
        printf("Usage: whereis <node-name>\n");
        return 1;
    }

    char *const nodes = "ABDHL..M...E.I..CF.JN...G.K.O..";
    char *p = nodes;
    char node;
    BiTree BiRoot = NULL, t;

    BiRoot = CreateBiTree(&p);

    PreOrder(BiRoot, print);
    EOL;

    node = argv[1][0];
    t = WhereIs(BiRoot, node);
    if (t != NULL)
        printf("Found node %c\n", node);
    else
        printf("Cannot find node %c\n", node);

    t = MySiblings(BiRoot, node);
    if (t != NULL)
        printf("The sibling of the node %c is %c\n", node, t->data);
    else
        printf("The node %c doesn't have any sibling\n", node);

    DestroyBiTree(BiRoot);

    return 0;
}

//---------------------------------------------------------------------------------------------------------------
//寻找值为node(区分大小写)的节点，返回指针

BiTree WhereIs(BiTree root, char node)
{ //主题框架类似于先序遍历
    if (root == NULL)
        return NULL;

    if (root->data == node)
        return root;

    BiTree t = WhereIs(root->LChild, node);

    return t != NULL ? t : WhereIs(root->RChild, node); //这个三目运算要习惯
}

//---------------------------------------------------------------------------------------------------------------
//找到给定值对应的节点的亲兄弟节点
BiTree MySiblings(BiTree root, char node)
{
    if (root == NULL)
        return NULL;

    DataType l = '\0', r = '\0';  //先初始化成一个不可能的值,即这个值不可能在待求的树的任意节点

    if (root->LChild != NULL)
        l = root->LChild->data;
    if (root->RChild != NULL)
        r = root->RChild->data;

    if (l == node)
        return root->RChild;
    if (r == node)
        return root->LChild;

    BiTree t = MySiblings(root->LChild, node);

    return t != NULL ? t : MySiblings(root->RChild, node);
}