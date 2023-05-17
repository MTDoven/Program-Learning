print(8 > 7)
print(8 == 7)
print(8 < 7)
#Python 返回布尔值答案
print(bool("Hello"))
print(bool(10))
#评估字符串和数字的布尔值
x = "Hello"
y = 10
print(bool(x))
print(bool(y))
#评估两个变量

print(bool(123))
print(bool('Hello'))
print(bool(['1','2']))
#下例将返回 True
bool(False)
bool(None)
bool(0)
bool("")
bool(())
bool([])
bool({})
#下例会返回 False

class myclass():
  def __len__(self):
    return 0
myobj = myclass()
print(bool(myobj))
#（类的bool，还有未知）

x = 200
print(isinstance(x, int))
#isinstance() 方法用于判断一个对象是否是一个已知的类型，
#Python 还有很多返回布尔值的内置函数，例如 isinstance() 函数，该函数可用于确定对象是否具有某种数据类型：




