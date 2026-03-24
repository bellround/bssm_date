stack = [None, None, None, None]
top = -1

top +=1
stack[top]='컵1'
top +=1
stack[top]='컵2'
top +=1
stack[top]='컵3'
top +=1
stack[top]='컵4'

print('--스택상태--')
for i in reversed(stack):
    print(i)


top = len(stack)-1

date = stack[top]
stack[top] = None
top -= 1
print("스택상태",stack)

date = stack[top]
stack[top] = None
top -= 1
print("스택상태",stack)

date = stack[top]
stack[top] = None
top -= 1
print("스택상태",stack)

SIZE = 5
stack = [None for i in range(SIZE)]
top = -1
print(stack)


def isEmpty(stack):
    if top == -1:
        return 1
    return 0

def pop(stack):
    global top
    if isEmpty(stack):
        print('스택이 공백상태 입니다')
        return
    stack[top] = None
    top -= 1
    
def isFull(stack):
    if top >= len(stack)-1:
        return True
    return False
    
def push(a,stack):
    global top
    if isFull(stack):
        print('스택이 포화상태입니다')
        return
    top += 1
    stack[top] = a
    
SIZE = 3
stack = [None for i in range(SIZE)]
top = -1
print("--스택상태--")
print(stack)
for i in range(SIZE + 1):
    push(chr(ord('A')+i),stack)
    print(stack)
for i in range(SIZE +1):
    pop(stack)
    print(stack)