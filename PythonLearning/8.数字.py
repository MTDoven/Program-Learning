x = 10   # int
y = 6.3  # float
z = 2j   # complex
print(type(x))
print(type(y))
print(type(z))
#为变量赋值时，将创建数值类型的变量

x = 10
y = 37216654545182186317
z = -465167846
print(type(x))
print(type(y))
print(type(z))
#int类型的变量，整数是完整的数字，正数或负数，没有小数，长度不限。

x = 3.50
y = 2.0
z = -63.78
print(type(x))
print(type(y))
print(type(z))
#float类型的变量，浮动或“浮点数”是包含小数的正数或负数。
x = 27e4
y = 15E2
z = -49.8e100
print(type(x))
print(type(y))
print(type(z))
#浮点数也可以是带有“e”的科学数字，表示 10 的幂。

x = 2+3j
y = 7j
z = -7j
print(type(x))
print(type(y))
print(type(z))
#complex类型的变量，复数是由实数和虚数组成的。

x = 10 # int
y = 6.3 # float
z = 1j # complex
# 把整数转换为浮点数
a = float(x)
# 把浮点数转换为整数
b = int(y)
# 把整数转换为复数：
c = complex(x)
print(a)
print(b)
print(c)
print(type(a))
print(type(b))
print(type(c))
#数值之间的相互转换，无法将复数转换为其他数字类型。

import random
print(random.randrange(1,10))
#生成1到10的随机数

