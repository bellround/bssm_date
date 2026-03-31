#include <stdio.h>
#include <stdlib.h>

int dan = 0,dd = 0;
// 이진트리의 노드를 표현하는 구조체 정의
typedef struct TreeNode {
    int data;                // 노드에 저장될 데이터
    struct TreeNode *left;    // 왼쪽 자식 포인터
    struct TreeNode *right;   // 오른쪽 자식 포인터
} TreeNode;


/* ==========================
   노드 개수 계산
   ========================== */
int count_node(TreeNode* root) {
    // 노드가 없으면 0개
    if (root == NULL)
        return 0;
    dan += root->data;
    // 자기 자신(1) + 왼쪽 서브트리 + 오른쪽 서브트리
    return 1 + count_node(root->left) + count_node(root->right);
}

/* ==========================
   단말(leaf) 노드 개수 계산
   ========================== */
int count_leaf(TreeNode* root) {
    // 노드가 없으면 단말도 없음
    if (root == NULL)
        return 0;

    // 왼쪽, 오른쪽 자식이 모두 없으면 단말 노드
    if (root->left == NULL && root->right == NULL)
    {
        dd += root->data;
        return 1;
    }
    // 단말이 아니면 왼쪽 + 오른쪽 결과 합
    return count_leaf(root->left) + count_leaf(root->right);
}

/* ==========================
   트리 높이 계산
   ========================== */
int calc_height(TreeNode* root) {
    // 노드가 없으면 높이 0
    if (root == NULL)
        return 0;

    // 왼쪽과 오른쪽 서브트리 높이 계산
    int left_h = calc_height(root->left);
    int right_h = calc_height(root->right);

    // 더 큰 쪽에 1(현재 노드) 추가
    return (left_h > right_h ? left_h : right_h) + root -> data;
}


int main() {

    TreeNode *a, *b, *c, *d, *e, *f, *g;

    // 노드 메모리 할당
    a= (TreeNode*)malloc(sizeof(TreeNode));
    b = (TreeNode*)malloc(sizeof(TreeNode));
    c = (TreeNode*)malloc(sizeof(TreeNode));
    d= (TreeNode*)malloc(sizeof(TreeNode));
    e = (TreeNode*)malloc(sizeof(TreeNode));
    f = (TreeNode*)malloc(sizeof(TreeNode));
    g = (TreeNode*)malloc(sizeof(TreeNode));

    /*
            A
           / \
          B   C
         / \
        D   E
    */

    // 데이터 저장
    a->data = 10;
    b->data = 20;
    c->data = 30;
    d->data = 40;
    e->data = 50;
    f -> data = 60;
    g -> data = 70;

    // 트리 연결
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = NULL;

    d->left = NULL;
    d->right = NULL;

    e->left = NULL;
    e->right = NULL;

    f -> left = NULL;
    f -> right = g;
    
    g -> left = NULL;
    g -> left = NULL;

    // ===== 결과 출력 =====
    count_node(a);
    printf("TotalCost : %d\n",dan);
    count_leaf(a);
    printf("FinalCost : %d\n", dd);
    printf("MaxCost   : %d\n", calc_height(a));

    // 메모리 해제 (자식 → 부모 순서)
    free(g);
    free(f);
    free(d);
    free(e);
    free(b);
    free(c);
    free(a);

    return 0;
}