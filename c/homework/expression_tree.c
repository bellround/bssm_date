#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    char date;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;


void postorder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    if (root -> date == '+')
        root -> date = root->left->date + root->right->date;
    else if (root -> date == '-')
        root -> date = root->left->date - root->right->date;
    else if (root -> date == '*')
        root -> date = root->left->date * root->right->date;
    else if (root -> date == '/')
        root -> date = root->left->date / root->right->date;
}

int main()
{
    TreeNode *a, *b, *c, *d, *e, *f, *g, *h, *i;
    a = (TreeNode*)malloc(sizeof(TreeNode));
    b = (TreeNode*)malloc(sizeof(TreeNode));
    c = (TreeNode*)malloc(sizeof(TreeNode));
    d = (TreeNode*)malloc(sizeof(TreeNode));
    e = (TreeNode*)malloc(sizeof(TreeNode));
    f = (TreeNode*)malloc(sizeof(TreeNode));
    g = (TreeNode*)malloc(sizeof(TreeNode));
    h = (TreeNode*)malloc(sizeof(TreeNode));
    i = (TreeNode*)malloc(sizeof(TreeNode));

    a -> date = '-';
    a -> left = b;
    a -> right = c;
    
    b -> date = '*';
    b -> left = d;
    b -> right = e;

    c -> date = '+';
    c -> left = f;
    c -> right = g;

    d -> date = 6;
    d -> left = NULL;
    d -> right = NULL;

    e -> date = '+';
    e -> left = h;
    e -> right = i;

    f -> date = 8;
    f -> left = NULL;
    f -> right = NULL;

    g -> date = 4;
    g -> left = NULL;
    g -> right = NULL;

    h -> date = 10;
    h -> left = NULL;
    h -> right = NULL;

    i -> date = 2;
    i -> left = NULL;
    i -> right = NULL;


    printf("\n후위 순회 : ");
    postorder(a);
    printf("%d",a->date);
    return 0;
}