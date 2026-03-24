#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct tree{
    int date;
    struct tree *left;
    struct tree *right;
}tree;
int main()
{
    int status;
    tree *a, *b, *c, *d, *e;
    a = (tree*)malloc(sizeof(tree));
    b = (tree*)malloc(sizeof(tree));
    c = (tree*)malloc(sizeof(tree));
    d = (tree*)malloc(sizeof(tree));
    e = (tree*)malloc(sizeof(tree));

    a -> date = 10;
    a -> left = b;
    a -> right = c;

    b -> date = 20;
    b -> left = d;
    b -> right = NULL;

    c -> date = 30;
    c -> left = e;
    c -> right =NULL;

    d -> date = 40;
    d -> left = NULL;
    d -> right = NULL;

    e -> date = 35;
    e -> left = NULL;
    e -> right = NULL;

    printf("전부 출력 : %d, %d, %d, %d, %d\n", a -> date, b -> date, c -> date, d -> date, e -> date);
    printf("직접 출력 : %d, %d, %d\n", a -> date, a ->left -> date, a -> left -> left -> date);
    printf("추가 강화수치 : ");
    scanf("%d", &status);
    a -> left -> left -> date += status;
    printf("태양의 검 최종 공격력 출력 %d\n", a -> date + a ->left -> date + a -> left -> left -> date);
    return 0;
}