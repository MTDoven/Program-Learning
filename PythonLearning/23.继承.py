# 继承允许我们定义继承另一个类的所有方法和属性的类。
# 父类是继承的类，也称为基类。
# 子类是从另一个类继承的类，也称为派生类。
# 任何类都可以是父类，因此语法与创建任何其他类相同

class Person:
  def __init__(self, fname, lname):
    self.firstname = fname
    self.lastname = lname
  def printname(self):
    print(self.firstname, self.lastname)
x = Person("Bill", "Gates")
x.printname()
#创建父类
class Student(Person):
  pass
#创建子类
x = Student("Elon", "Musk")
x.printname()
#继承的类可以访问父类的所有方法和属性

#子的__init__()函数会覆盖对父的__init__()函数的继承。
class Student(Person):
  def __init__(self, fname, lname):pass
# 当您添加__init__()函数时，子类将不再继承父的__init__()函数。
class Student(Person):
  def __init__(self, fname, lname):
    Person.__init__(self, fname, lname)
#如需保持父的__init__()函数的继承，请添加对父的__init__()函数的调用

class Student(Person):
  def __init__(self, fname, lname):
    super().__init__(fname, lname)#调用父类的__init__()函数，相当于Person.__init__(self, fname, lname)
#Python 还有一个 super() 函数，它会使用父类的函数

class Student(Person):
  def __init__(self, fname, lname, year):
    super().__init__(fname, lname)
    self.graduationyear = year
x = Student("Elon", "Musk", 2019)
#添加属性
class Student(Person):
  def __init__(self, fname, lname, year):
    super().__init__(fname, lname)
    self.graduationyear = year
  def welcome(self):
    print("Welcome", self.firstname, self.lastname, "to the class of", self.graduationyear)
#添加方法

