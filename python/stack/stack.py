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
    
SIZE = int(input('스택의 개수'))
stack = [None for i in range(SIZE)]
top = -1
while 1:
    print("--스택상태--")
    print(stack)
    print('1. 추가')
    print('2. 삭제')
    print('0. 종료')
    a = int(input())
    if a == 1:
        b = input('넣을 문자')
        push(b,stack)
    elif a == 2:
        pop(stack)
    else:
        lllllllllllkjhghjhgffghjufcvhj+=1