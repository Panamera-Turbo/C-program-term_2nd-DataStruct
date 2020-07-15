#include<stdlib.h>
#include<stdio.h>
// 平衡二叉树，是一种二叉排序树，其中每个结点的左子树和右子树的高度差至多等于1。
// 它是一种高度平衡的二叉排序树。现二叉平衡树结点定义如下：
typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} node_t;
// 请实现平衡二叉树的插入算法：
//向根为 root 的平衡二叉树插入新元素 val，成功后返回新平衡二叉树根结点
//---------------------------------------------------------------------------------------------------------
node_t* Insert(node_t* T, int X);
int GetHeight(node_t* T);
int Max(int a, int b);
node_t* LL(node_t* A);
node_t* LR(node_t* A);
node_t* RR(node_t* A);
node_t* RL(node_t* A);

int Max(int a, int b)
{
    return a > b ? a : b;
}

int GetHeight(node_t* T)
{
    if (T)
        return T->height;
    else
        return 0;
}

node_t* LL(node_t* A) //左单旋
{
    node_t* B;
    B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    return B;
}

node_t* LR(node_t* A) //左右双旋
{
    A->left = RR(A->left);
    return LL(A);
}

node_t* RR(node_t* A) //右单旋
{
    node_t* B;
    B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = Max(GetHeight(A->left), GetHeight(A->right)) + 1;
    B->height = Max(GetHeight(B->left), GetHeight(B->right)) + 1;
    return B;
}

node_t* RL(node_t* A) //右左双旋
{
    A->right = LL(A->right);
    return RR(A);
}

node_t* avl_insert(node_t* root, int val)
{
    node_t* parentNode = NULL;
    if (root == NULL) {
        root = (node_t*)malloc(sizeof(node_t));
        root->left = root->right = root->parent = NULL;
        root->val = val;
        root->height = 1;
    } 
    else if (val < root->val) {
        parentNode = root->left;
        root->left = avl_insert(root->left, val);
        if (GetHeight(root->left) - GetHeight(root->right) == 2) {
            if (val < root->left->val)
                root = LL(root);
            else {
                root = LR(root);
            }
        }
    } 
    else if (val > root->val) {
        parentNode = root->left;
        root->right = avl_insert(root->right, val);
        if (GetHeight(root->right) - GetHeight(root->left) == 2) {
            if (val > root->right->val)
                root = RR(root);
            else
                root = RL(root);
        }
    }
    root->parent = parentNode;
    root->height = Max(GetHeight(root->left), GetHeight(root->right)) + 1;
    return root;
}

// node_t* avl_insert(node_t *root, int val){
//     node_t *S = (node_t*)malloc(sizeof(node_t));
//     S->val = val;
//     S->left = S->right = NULL;
//     S->height = 0;

//     if(root == NULL)
//     {
//         root = S;
//         return root;
//     }
    
//     node_t *A = root;
//     node_t *FA = NULL;
//     node_t *p = root;
//     node_t *fp = NULL;
//     while (p != NULL)
//     {
//         if(p->left->height != p->right->height)
//         {
//             A = p;
//             FA = fp;
//         }
//         fp = p;

//         if(val < p->val)p = p->left;

//         else p = p->right;
//     }

//     if(val < fp->val) fp->left = S;
//     else fp->right = S;

//     if(val < A->val) 
//     {
//         node_t *B = A->left;
//         A->height++;
//     }
//     else
//     {
//         node_t *B = A->right;
//         A->height--;
//     }
    

// }