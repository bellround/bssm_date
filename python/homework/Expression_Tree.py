class TNode:
    def __init__(self, date, left, right):
        self.date = date
        self.left = left
        self.right = right
        
appro = 0
n = 0
def preorder(root):
    if root == None:
        return
    print(root.date)
    preorder(root.left)
    preorder(root.right)
    
def oror(root):
    if type(root.left.date) == int:
        return root.left.date
    return 1
def order(root):
    if type(root.right.date) == int:
        return root.right.date
    return 1
    
    
def postorder(root):
    global n
    global appro
    if root == None:
        return
    n += 1

    postorder(root.left)
    postorder(root.right)
    if root.date == '+':
        root.date = order(root) + oror(root)
    if root.date == '*':
        root.date = order(root) * oror(root)
    if root.date == '-':
        root.date = oror(root) - order(root)
    if root.date == '/':
        root.date = oror(root) / order(root)


i = TNode(2,None,None)
h = TNode(10,None,None)
g = TNode(4,None,None)
f = TNode(8, None, None)
e =TNode('+',h, i)
d = TNode(6, None, None)
c = TNode('+', f, g)
b = TNode('*', d, e)
a = TNode('-',b,c)


print('후위 순회 결과 : ',end='')
postorder(a)
print()
print(a.date)