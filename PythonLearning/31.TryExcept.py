try:
  print(x)
except:
  print("An exception occurred")
#排除错误

try:
  print(x)
except NameError:
  print("Variable x is not defined")
except:
  print("Something else went wrong")
# 如果 try 块引发 NameError，则打印一条消息
# 如果是其他错误则打印另一条消息

try:
  print("Hello")
except:
  print("Something went wrong")
else:
  print("Nothing went wrong")
#如果没有引发错误，那么您可以使用 else 关键字来定义要执行的代码块

try:
  print(x)
except:
  print("Something went wrong")
finally:
  print("The 'try except' is finished")
#如果指定了 finally 块，则无论 try 块是否引发错误，都会执行 finally 块
'''''
try:
  f = open("demofile.txt")
  f.write("Lorum Ipsum")
except:
  print("Something went wrong when writing to the file")
finally:
  f.close()
#这对于关闭对象并清理资源非常有用
'''''

'''''
x = -1
if x < 0:
  raise Exception("Sorry, no numbers below zero")
#raise 关键字可以用来抛出一个异常，并终止程序
'''''

x = "hello"
if not type(x) is int:  #此处int是一个type类
  raise TypeError("Only int are allowed")
#如果 x 不是整数，则引发 TypeError
