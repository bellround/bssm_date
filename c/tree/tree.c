#include <stdio.h>
#include <stdlib.h> //malloc 함수
#include <memory.h>

typedef struct treeNode{
    int date;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

int main()
{
    treeNode *n1, *n2, *n3;
    n1 = (treeNode*)malloc(sizeof(treeNode));
    n2 = (treeNode*)malloc(sizeof(treeNode));
    n3 = (treeNode*)malloc(sizeof(treeNode));

    n1 -> date = 10;
    n1 -> left = n2;
    n1 -> right = n3;

    n2 -> date = 20;
    n2 -> left = NULL;
    n2 -> right = NULL;

    n3 -> date = 30;
    n3 -> left = NULL;
    n3 -> right = NULL;

    printf("n1의 데이터 : %d\n",n1 -> date);
    printf("n2의 데이터 : %d\n",n2 -> date);
    printf("n2의 데이터 : %d\n",n1 -> left -> date);
    printf("n3의 데이터 : %d\n",n1 -> right -> date);
    printf("n3의 데이터 : %d\n",n3 -> date);

    free(n1);
    free(n2);
    free(n3);

    return 0;
}