#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct tree{
    int date;
    struct tree *left;
    struct tree *right;
}tree;

void preorder(tree* root) // 전위순회
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ",root -> date);
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(tree* root) // 중위순회
{
    if (root == NULL)
    {
        return;
    }
    inorder (root -> left);
    printf("%d ", root -> date);
    inorder(root -> right);
}

void postorder(tree* root) // 후위순회
{
    if (root == NULL)
    {
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ",root -> date);
}

int main()
{
    tree *a,*b,*c,*d,*e,*f;
    a = (tree*)malloc(sizeof(tree));
    b = (tree*)malloc(sizeof(tree));
    c = (tree*)malloc(sizeof(tree));
    d = (tree*)malloc(sizeof(tree));
    e = (tree*)malloc(sizeof(tree));
    f = (tree*)malloc(sizeof(tree));

    a -> date = 15;
    a -> left = b;
    a -> right = c;

    b -> date = 8;
    b -> left = d;
    b -> right = NULL;

    c -> date = 20;
    c -> left = e;
    c -> right = f;

    d -> date = 4;
    d -> left = NULL;
    d -> right = NULL;

    e -> date = 17;
    e -> left = NULL;
    e -> right = NULL;

    f -> date = 20;
    f -> left = NULL;
    f -> right = NULL;

    printf("루트 및 루트의 자식 노드의 data 직접 출력하기 : %d %d %d\n",a -> date, a -> left -> date, a -> right -> date);
    printf("전위 순회 : ");
    preorder(a);
    printf("\n중위 순회 : ");
    inorder(a);
    printf("\n후위 순회 : ");
    postorder(a);

    return 0;
}