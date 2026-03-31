
# 이진트리 노드 클래스
class TNode:
    def __init__(self, data, left, right):
        self.data = data
        self.left = left
        self.right = right


# ------------------------------
# 노드 개수 계산
# ------------------------------
def count_node(n):
    global dan
    # 종료 조건: 노드가 없으면 0
    if n is None:
        return 0
    dan += n.data
    # 자기 자신(1) + 왼쪽 + 오른쪽
    return 1 + count_node(n.left) + count_node(n.right)


# ------------------------------
# 단말(leaf) 노드 개수 계산
# ------------------------------
def count_leaf(n):
    global dd
    # 노드가 없으면 단말도 없음
    if n is None:
        return 0

    # 왼쪽, 오른쪽이 모두 없으면 단말 노드
    if n.left is None and n.right is None:
        return 1
    dd += n.data
    # 단말이 아니면 왼쪽 + 오른쪽 결과 합
    return count_leaf(n.left) + count_leaf(n.right)


# ------------------------------
# 트리 높이 계산
# ------------------------------
def calc_height(n):
    # 노드가 없으면 높이 0
    if n is None:
        return 0

    # 왼쪽과 오른쪽 높이 계산
    left_h = calc_height(n.left)
    right_h = calc_height(n.right)

    # 더 큰 쪽에 1(현재 노드) 추가
    return max(left_h, right_h) + n.data


if __name__ == "__main__":
    """
            A
           / \
          B   C
         / \
        D   E
    """
    dd = 0
    dan = 0
    # 트리 생성
    g = TNode(70, None, None)
    f = TNode(60,None,g)
    d = TNode(40, None, None)
    e = TNode(50, None, None)
    b = TNode(20, d, e)
    c = TNode(30, f, None)
    a = TNode(10, b, c)

    # 결과 출력
    count_node(a)
    print("노드 개수 :", dan)
    count_leaf(a)
    print("단말 개수 :", dd)
    print("트리 높이 :", calc_height(a))