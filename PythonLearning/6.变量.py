x = 10
y = "Bill"
print(x)
print(y)
#int和str

x, y, z = "Orange", "Banana", "Cherry"
print(x)
print(y)
print(z)
x = y = z = "Orange"
print(x)
print(y)
print(z)
#向多个变量赋值

x = "Python is "
y = "awesome"
z =  x + y
print(z)
#字符串加法

x = "awesome"
def myfunc():
  print("Python is " + x)
myfunc()
# ！！！！在函数外部创建的变量（如上述所有实例所示）称为全局变量。
x = "awesome"
def myfunc():
  x = "fantastic"
  print("Python is " + x) #输出Python is fantastic
myfunc()
print("Python is " + x) #输出Python is awesome
# 全局变量可以被函数内部和外部的每个人使用。
# 函数内部的变量是局部变量，只能在内部使用，外部不能访问。
def myfunc():
  global x
  x = "fantastic"
myfunc()
print("Python is " + x) #输出Python is fantastic
#要在函数内部创建全局变量，您可以使用 global 关键字。
x = "awesome"
def myfunc():
  global x
  x = "fantastic"
myfunc()
print("Python is " + x) #输出Python is fantastic
#另外，如果要在函数内部！！！更改！！！全局变量，请使用 global 关键字。
