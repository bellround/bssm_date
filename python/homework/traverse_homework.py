class TNode:
    def __init__(self, date, left, right):
        self.date = date
        self.left = left
        self.right = right

def preorder(root):
    if root == None:
        return
    print(root.date,end=' ')
    preorder(root.left)
    preorder(root.right)
    
def inorder(root):
    if root == None:
        return
    inorder(root.left)
    print(root.date,end=' ')
    inorder(root.right)
    
def postorder(root):
    if root == None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.date,end=' ')

f = TNode(20, None, None)
e =TNode(17,None, None)
d = TNode(4, None, None)
c = TNode(20, e, f)
b = TNode(8, d, None)
a = TNode(15,b,c)


print('전위 순회 결과 : ',end='')
preorder(a)
print()
print('중위 순회 결과 : ',end='')
inorder(a)
print()
print('후위 순회 결과 : ',end='')
postorder(a)
print()