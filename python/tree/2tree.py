class TNode:
    def __init__(self, date, left, right):
        self.date = date
        self.left = left
        self.right = right

if __name__ == "__main__":
    e = TNode(35, None, None)
    d = TNode(40, None, None)
    c = TNode(30, e, None)
    b = TNode(20, d, None)
    a = TNode(10, b, c)
    print("전부 출력",a.date, b.date, c.date, d.date, e.date)
    print("직접 출력",a.left.left.date, a.left.date, a.date)
    st = int(input('추가 공격력 : '))
    a.left.left.date += st
    print("태양의 검 최종 루트 공격력 합계 :",a.left.left.date + a.left.date + a.date)