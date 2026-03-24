class TNode:
    def __init__(self, date, left, right):
        self.date = date
        self.left = left
        self.right = right
        
appro = 0
n = 0

def preorder(root):
    global appro
    if root == None:
        return
    if root.left == None and root.right == None:
        appro += root.date
    print(root.date,end=' ')
    preorder(root.left)
    preorder(root.right)
    
def inorder(root):
    if root == None:
        return
    if root.date > 16:
        print("중위 순회를 활용하여 노드의 데이터가 16보다 큰 경우에 해당하는 데이터만 출력하기",root.date)
    inorder(root.left)
    inorder(root.right)
    
def postorder(root):
    global n
    if root == None:
        return
    n += 1
    postorder(root.left)
    postorder(root.right)
    print(root.date,end=' ')

f = TNode(25, None, None)
e =TNode(17,None, None)
d = TNode(4, None, None)
c = TNode(20, e, f)
b = TNode(8, d, None)
a = TNode(15,b,c)

print('루트 및 루트의 자식 노드의 data 직접 출력하기',a.date,a.left.date,a.right.date)
print('전위 순회 결과 : ',end='')
preorder(a)
print()
print('전위 순회를 활용하여 자식 노드가 하나도 없는 노드(단말 노드)의 데이터만 모두 더해서 출력하기',appro)
inorder(a)
print()
print('후위 순회 결과 : ',end='')
postorder(a)
print()
print('후위 순회를 활용하여 전체 노드의 개수를 세어 몇 개인지 출력하기',n)