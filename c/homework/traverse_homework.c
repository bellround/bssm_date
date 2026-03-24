#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int appro = 0;
int n = 0;
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
    if (root -> left == NULL && root -> right == NULL)
    {
        appro += root -> date;
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
    if (root -> date > 16)
    {
        printf("16보다 큰 데이터는 : %d입니다.\n",root -> date);
    }
    inorder (root -> left);
    inorder(root -> right);
}

void postorder(tree* root) // 후위순회
{
    if (root == NULL)
    {
        return;
    }
    n += 1;
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

    f -> date = 25;
    f -> left = NULL;
    f -> right = NULL;

    printf("루트 및 루트의 자식 노드의 data 직접 출력하기 : %d %d %d\n",a -> date, a -> left -> date, a -> right -> date);
    printf("전위 순회 : \n");
    preorder(a);
    printf("\n전위 순회를 활용하여 자식 노드가 하나도 없는 노드(단말 노드)의 데이터만 모두 더해서 출력하기 : %d",appro);
    printf("\n중위 순회 : \n");
    inorder(a);
    printf("\n후위 순회 : \n");
    postorder(a);
    printf("\n후위 순회를 활용하여 전체 노드의 개수를 세어 몇 개인지 출력하기 : %d\n",n);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);

    return 0;
}