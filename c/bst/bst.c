
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// [도우미 함수] 오른쪽 서브트리에서 가장 작은 노드(후계자)를 찾는 함수
TreeNode* get_min_node (TreeNode* node) {
    TreeNode* current = node; // 시작 위치를 current 포인터에 저장합니다.
    // 1. 왼쪽 자식이 존재하는 동안(NULL이 아닐 때까지) 계속해서 파고듭니다.
    while (current != NULL) {
        current = node -> left; // "더 작은 값 찾으러 왼쪽 주소로 이동!"
    }
    // 2. 더 이상 갈 곳이 없다면 그곳이 가장 작은 값(후계자)입니다!
    return current;
}

// 1. 데이터 탐색 - 반복문 사용하기
TreeNode* search (TreeNode* node, int key) {
    // 1. 노드가 비어있지 않은 동안 계속 반복
    while (node != NULL) {
        // 2. 찾은 경우 (현재 노드의 데이터와 키 값이 같을 때)
        if (key == node -> data) {
            return node;
        }
        // 3. 나보다 작으면 왼쪽으로 이동
        else if (key < node -> data) {
            node = node->left;
        }
        // 4. 나보다 크면 오른쪽으로 이동
        else {
            node = node->right;
        }
    }
    // 5. 끝까지 찾았는데도 없는 경우 (탐색 실패)
    return NULL;
}

// 2. 데이터 삽입
TreeNode* insert_node (TreeNode* node, int key) {
    // [Step 1] 빈자리를 찾았다면? 새 노드를 생성합니다.
    if (node == NULL) {
        TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode)); // 메모리 공간 빌리기
        temp->data = key; // 전달받은 값을 데이터에 넣기
        temp->left = temp->right = NULL; // 새 노드의 자식은 아직 없으므로 NULL
        return temp; // 나를 호출한 부모에게 내 주소를 알려 줌!
    }
    // [Step 2] 아직 빈자리가 아니라면? 크기를 비교해서 아래로 내려갑니다.
    if (key < node->data) {
        // 내 왼쪽 자식으로 들어가렴! 하고 재귀 호출 후 내 왼쪽 포인터에 연결
        node->left = insert_node(node -> left, key);
    }
    else if (key > node->data) {
        // 내 오른쪽 자식으로 들어가렴! 하고 재귀 호출 후 내 오른쪽 포인터에 연결
        node->right = insert_node(node -> right, key);
    }
    // [Step 3] 연결이 다 끝난 현재 노드를 반환 (부모-자식 연결유지)
    return node;
}

// 3. 데이터 삭제
TreeNode* delete_node (TreeNode* root, int key) {
    // 1. 트리가 비어있거나 끝까지 찾았는데 없는 경우
    if (root == NULL) return NULL;

    // 2. 삭제할 값 찾으러 아래로 내려가기 (재귀 호출)
    if (key < root->data) {
        root->left = delete_node (root -> left, key);
    }
    else if (key > root->data) {
        root->right = delete_node (root -> right, key);
    }
    // 3. 드디어 삭제할 노드를 찾은 경우! (key == root->data)
    else {
        // [Case 1&2] 자식이 없거나(단말 노드), 하나만 있는 경우
        if (root->left == NULL) {
            TreeNode* temp = root -> right; // 오른쪽 자식을 임시 저장
            free(root); // 현재 노드 지우기
            return temp; // 피신시켜 둔 자식을 부모에게 반환해 연결
        } else if (root->right == NULL) {
            TreeNode* temp = root -> left; // 왼쪽 자식을 임시 저장
            free(root); // 현재 노드 지우기
            return temp; // 피신시켜 둔 자식을 부모에게 반환해 연결
        }
        // [Case 3] 자식이 둘다 있는 경우
        // 1단계: 오른쪽 트리로 넘어가서 가장 작은 녀석(후계자)을 찾아 temp로 부릅니다.
        TreeNode* temp = get_min_node(root);
        // 2단계: 빈자리(현재 노드)에 후계자의 '데이터만' 복사해 넣습니다.
        root->data = temp -> data;
        // 3단계: 이제 원래 후계자가 있던 자리는 빈 껍데기이므로, 
        // 오른쪽 트리로 가서 그 중복된 녀석을 지워줍니다. (재귀 호출)
        root->right = delete_node (root, key);
    }
    return root;
}

// 중위 순회
void inorder (TreeNode* root) {
    if (root != NULL) {
        inorder (root->left);
        printf("%d ", root->data);
        inorder (root->right);
    }
}

// === main 부분 ===
int main() {
    TreeNode* root = NULL;
    int choice, val;
    while (1) {
        printf("\n=== 이진탐색트리(BST) 테스트 메뉴 ===\n");
        printf("1. 데이터 삽입\n2. 데이터 탐색\n3. 데이터 삭제\n4. 현재 트리 출력 (중위 순회)\n0. 프로그램 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("삽입할 숫자를 입력하세요: ");
            scanf("%d", &val);
            root = insert_node(root, val);
            printf("[%d] 삽입 완료!\n", val);
        } else if (choice == 2) {
            printf("탐색할 숫자를 입력하세요: ");
            scanf("%d", &val);
            if (search(root, val) != NULL)
                printf("탐색 성공! 트리에 [%d]이(가) 존재합니다.\n", val);
            else
                printf("탐색 실패! 트리에 [%d]이(가) 없습니다.\n", val);
        } else if (choice == 3) {
            printf("삭제할 숫자를 입력하세요: ");
            scanf("%d", &val);
            if (search(root, val) != NULL) {
                root = delete_node(root, val);
                printf("[%d] 삭제 완료!\n", val);
            } else {
                printf("[%d]이(가) 트리에 존재하지 않아 삭제할 수 없습니다.\n", val);
            }
        } else if (choice == 4) {
            printf("현재 트리 (오름차순): ");
            if (root == NULL) printf("트리가 비어있습니다.");
            else inorder(root);
            printf("\n");
        } else if (choice == 0) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
    }
    return 0;
}