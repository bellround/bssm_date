class TNode:
    def __init__(self, date, left, right):
        self.date = date
        self.left = left
        self.right = right
        
def preorder(root):
    if root == None:
        return
    print(root.date)
    preorder(root.left)
    preorder(root.right)
    
def inorder(root):
    if root == None:
        return
    inorder(root.left)
    print(root.date)
    inorder(root.right)
    
def postorder(root):
    if root == None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.date)

e = TNode("E", None, None)
d = TNode('D', None, None)
c = TNode('C',None, None)
b = TNode('B', d, e)
a = TNode('A',b ,c)

print('전위 순회 결과 : ',preorder(a))
print('중위 순회 결과 : ',inorder(a))
print('후위 순회 결과 : ',postorder(a))