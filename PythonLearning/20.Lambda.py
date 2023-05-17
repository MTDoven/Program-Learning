# lambda 函数是一种小的匿名函数。
# lambda 函数可接受任意数量的参数，但只能有一个表达式。
# 语法：lambda 参数 : 表达式

x = lambda a : a + 10
print(x(5))
# 15
x = lambda a, b : a * b
print(x(5, 6))
# 30
x = lambda a, b, c : a + b + c
print(x(5, 6, 2))
# 13

#为啥用lambda函数？
def myfunc(n):
  return lambda a : a * n
mydoubler = myfunc(2)
mytripler = myfunc(3)
print(mydoubler(11))
print(mytripler(11))
#使用该函数定义来创建一个总是使所发送数字加n倍的函数

