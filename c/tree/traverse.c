#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    char date;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

void preorder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c", root -> date);
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root -> left);
    printf("%c",root -> date);
    inorder(root -> right);
}

void postorder(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%c",root -> date);
}

int main()
{
    TreeNode *a, *b, *c, *d, *e;
    a = (TreeNode*)malloc(sizeof(TreeNode));
    b = (TreeNode*)malloc(sizeof(TreeNode));
    c = (TreeNode*)malloc(sizeof(TreeNode));
    d = (TreeNode*)malloc(sizeof(TreeNode));
    e = (TreeNode*)malloc(sizeof(TreeNode));

    a -> date = 'A';
    a -> left = b;
    a -> right = c;
    
    b -> date = 'B';
    b -> left = d;
    b -> right = e;

    c -> date = 'C';
    c -> left = NULL;
    c -> right = NULL;

    d -> date = 'D';
    d -> left = NULL;
    d -> right = NULL;

    e -> date = 'E';
    e -> left = NULL;
    e -> right = NULL;

    printf("전위 순회 : ");
    preorder(a);
    printf("\n중위 순회 : ");
    inorder(a);
    printf("\n후위 순회 : ");
    postorder(a);

    return 0;
}