def my_function():
  print("Hello from a function")
my_function()
#使用函数
def my_function(fname):
  print(fname + " Gates")
my_function("Bill")
my_function("Steve")
my_function("Elon")
#给函数传递参数
def my_function(country = "China"):
  print("I am from " + country)
my_function("Sweden")
my_function("India")
my_function()
my_function("Brazil")
#设置默认参数值
def my_function(x):
  return 5 * x
print(my_function(3))
print(my_function(5))
print(my_function(9))
#设置返回值return

#如果您不知道将传递给您的函数多少个参数，请在函数定义的参数名称前添加 *。
#这样，函数将接收一个参数元组，并可以相应地访问各项：
def my_function(*kids):
  print("The youngest child is " + kids[2])
my_function("Phoebe", "Jennifer", "Rory")
#如果您不知道将传递给您的函数多少个参数，请在函数定义的参数名称前添加 *

def tri_recursion(k):
  if k>0:
    result = k+tri_recursion(k-1)
    print(result)
  else:
    result = 0
  return result
print("\n\nRecursion Example Results")
tri_recursion(4)
#递归函数
