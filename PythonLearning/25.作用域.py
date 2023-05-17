def myfunc():
  x = 100
  print(x)
myfunc()
# 在函数内部创建的变量属于该函数的局部作用域，并且只能在该函数内部使
def myfunc():
  x = 100
  def myinnerfunc():
    print(x)
  myinnerfunc()
myfunc()
#如上例中所示，变量 x 在函数外部不可用，但对于函数内部的任何函数均可用
x = 100
def myfunc():
  print(x)
myfunc()
print(x)
# 在函数外部创建的变量是全局变量，任何人都可以使用

x = 100
def myfunc():
  x = 200
  print(x)
myfunc()
print(x)
#该函数将打印局部变量 x，然后代码还会打印全局变量 x
def myfunc():
  global x
  x = 100
myfunc()
print(x)
# 如果使用 global 关键字，则该变量属于全局范围
# 另外，如果要在函数内部更改全局变量，也请使用 global 关键字
# global的意思是，里面的这个就是外面的这个
