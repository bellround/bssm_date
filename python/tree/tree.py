class TNode:
    def __init__(self, date, left, right):
        self.date = date
        self.left = left
        self.right = right

if __name__ == "__main__":
    n2 = TNode(20,None, None)
    n3 = TNode(30, None, None)
    n1 = TNode(10, n2, n3)
    
    print(n1.date)
    print(n2.date)
    print(n1.left.date)
    print(n3.date)
    print(n1.right.date)