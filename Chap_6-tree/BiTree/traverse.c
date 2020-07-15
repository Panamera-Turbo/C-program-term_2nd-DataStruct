#include "BiTree.h"
//遍历时，左子树永远先于右子树

//---------------------------------------------------------------------------------------------------------
//前序遍历DLR
void PreOrder(BiTree root, CALLBACK visit)
{
    if (root == NULL)
        return;

    visit(root->data);

    PreOrder(root->LChild, visit);
    PreOrder(root->RChild, visit);
}
//---------------------------------------------------------------------------------------------------------
//中序遍历LDR
void InOrder(BiTree root, CALLBACK visit)
{
    if (root == NULL)
        return;

    InOrder(root->LChild, visit);

    visit(root->data);

    InOrder(root->RChild, visit);
}
//---------------------------------------------------------------------------------------------------------
//后序遍历LRD
void PostOrder(BiTree root, CALLBACK visit)
{
    if (root == NULL)
        return;

    PostOrder(root->LChild, visit);
    PostOrder(root->RChild, visit);

    visit(root->data);
}
//---------------------------------------------------------------------------------------------------------
//

void PreOrder_IfLeaf(BiTree root, CALLBACK visit, PREDICATE pred)
{
    if (root == NULL)
        return;

    if (pred(root))
    {
        visit(root->data);
        // ++total;
    }

    PreOrder_IfLeaf(root->LChild, visit, pred);
    PreOrder_IfLeaf(root->RChild, visit, pred);
}

//-------------------------------------------------------------------------------------------------------
//判断函数
bool isLeaf(BiTree root)
{
    return root->LChild == NULL && root->RChild == NULL;
}