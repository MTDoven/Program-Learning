print("Hello")
print('Hello')
#'hello' 等同于 "hello"
a = """
Python is a widely used general-purpose, high level programming language. 
It was initially designed by Guido van Rossum in 1991 
and developed by Python Software Foundation. 
It was mainly developed for emphasis on code readability, 
and its syntax allows programmers to express concepts in fewer lines of code.
"""
print(a)
#多行字符串使用三个单引号或三个双引号


a = "Hello, World!"
print(a[1])
#方括号可用于访问字符串的元素。请记住第一个字符的位置为 0
b = "Hello, World!"
print(b[2:5])
#获取从位置 2 到位置 5（不包括）的字符
b = "Hello, World!"
print(b[-5:-2])
#获取从倒数2（不包括）到倒数5的字符，从字符串末尾开始计数
a = " Hello, World! "
print(a.strip()) # 返回 "Hello, World!"
#strip() 方法用于移除字符串头尾指定的字符（默认为空格）
a = "Hello, World!"
print(a.lower())
#lower() 方法用于将字符串中大写转换为小写
a = "Hello, World!"
print(a.upper())
#upper() 方法用于将字符串中小写转换为大写
a = "Hello, World!"
print(a.replace("World", "Kitty"))
#replace() 方法用于替换字符串中的某些字符串
a = "Hello, World!"
print(a.split(",")) # 返回 ['Hello', ' World!']
#split() 方法用于将字符串按照指定分隔符分割成一个字符串列表
txt = "China is a great country"
x = "ina" in txt #返回True或者False
print(x)
#in 判断字符串中是否包含某个字符串
txt = "China is a great country"
x = "ain" not in txt
print(x)
#not in 判断字符串中是否不包含某个字符串


a = "Hello"
b = "World"
c = a + b
print(c)
#+ 操作符用于连接两个字符串
age = 63
txt = "My name is Bill, and I am {}"
print(txt.format(age))
# 正如在 Python 变量一章中所学到的
# 我们不能像这样组合字符串和数字：
# 但是我们可以使用 format() 方法组合字符串和数字
# format() 方法接受传递的参数，格式化它们，
# 并将它们放在占位符 {} 所在的字符串中：
quantity = 3
itemno = 567
price = 49.95
myorder = "I want {} pieces of item {} for {} dollars."
print(myorder.format(quantity, itemno, price))
#format() 方法接受不限数量的参数，并放在各自的占位符中：
quantity = 3
itemno = 567
price = 49.95
myorder = "I want to pay {2} dollars for {0} pieces of item {1}."
print(myorder.format(quantity, itemno, price))
#您可以使用索引号 {0} 来确保参数被放在正确的占位符中：
#其他的字符串方法见 https://www.w3school.com.cn/python/python_strings.asp

