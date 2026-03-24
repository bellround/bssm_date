# 삭제 연산
number = [1, 2, 3, 4, 5, 1, 3]
del(number[2])
print(number)

x = number.pop(2)
print(number)
print(x)

y = number.pop()
print(number)
print(y)

number.remove(1)
print(number)
