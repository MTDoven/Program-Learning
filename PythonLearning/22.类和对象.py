class MyClass:
  x = 5
#使用名为 x 的属性，创建一个名为 MyClass 的类
p1 = MyClass()
print(p1.x)
#创建一个名为 p1 的对象，并打印 x 的值

# __init__() 函数
# 上面的例子是最简单形式的类和对象，在实际应用程序中并不真正有用。
# 要理解类的含义，我们必须先了解内置的 __init__() 函数。
# 所有类都有一个名为 __init__() 的函数，它始终在启动类时执行。
# 使用 __init__() 函数将值赋给对象属性，或者在创建对象时需要执行的其他操作
class Person:
  def __init__(self, name, age):
    self.name = name
    self.age = age
p1 = Person("Bill", 63)
print(p1.name)
print(p1.age)
#创建名为 Person 的类，使用 __init__() 函数为 name 和 age 赋值
#每次使用类创建新对象时，都会自动调用 __init__() 函数

class Person:
  def __init__(self, name, age):
    self.name = name
    self.age = age
  def myfunc(self):
    print("Hello my name is " + self.name)
p1 = Person("Bill", 63)
p1.myfunc()
#插入一个打印问候语的函数，并在 p1 对象上执行它
#self 参数是对类的当前实例的引用，用于访问属于该类的变量

class Person:
  def __init__(mysillyobject, name, age):
    mysillyobject.name = name
    mysillyobject.age = age
  def myfunc(abc):
    print("Hello my name is " + abc.name)
p1 = Person("Bill", 63)
p1.myfunc()
#self 参数是对类的当前实例的引用，用于访问属于该类的变量。
#它不必被命名为 self，您可以随意调用它，但它必须是类中任意函数的首个参数
#此处mysillyobject与abc是表示同一个变量

p1.age = 40
#把 p1 的年龄设置为 40：
del p1.age
#删除 p1 的年龄属性
del p1
#删除 p1 对象
