"""
文本类型：   str
数值类型：   int, float, complex
序列类型：   list, tuple, range
映射类型：   dict
集合类型：   set, frozenset
布尔类型：   bool
二进制类型：  bytes, bytearray, memoryview
"""

x = 10
print(type(x))
#打印变量类型

'''''
x = "Hello World"	                            str
x = 29	                                        int
x = 29.5	                                    float
x = 2+1j	                                    complex         #用来表示虚数，其中j或J是虚数符号即‘i’
x = ["apple", "banana", "cherry"]	            list
x = ("apple", "banana", "cherry")	            tuple
x = range(6)	                                range           #相对于list占内存小
x = {"name" : "Bill", "age" : 63}	            dict
x = {"apple", "banana", "cherry"}	            set             #无序的列表（还有我未知的东西）
x = frozenset({"apple", "banana", "cherry"})	frozenset       #（还有我未知的东西）
x = True	                                    bool
x = b"Hello"	                                bytes           #bytes是byte的序列，而str是unicode的序列。
x = bytearray(5)	                            bytearray       #bytearray是可变的bytes类型。（还有未知）
x = memoryview(bytes(5))                        memoryview      #（仍有未知）
'''''

x = 2+1j
y = 1+2j
print(x+y)
#复数加法

str = "Hello World，你好世界！"
bytes = str.encode()
print(bytes, type(bytes))
print(bytes.decode(), type(bytes.decode()))
# 使用encode()方法转换为bytes类型，使用decode()方法转换为str类型。
# byte变量

'''''
x = str("Hello World")	                        str
x = int(29)	                                    int
x = float(29.5)	                                float
x = complex(1j)	                                complex
x = list(("apple", "banana", "cherry"))	        list
x = tuple(("apple", "banana", "cherry"))	    tuple
x = range(6)	                                range
x = dict(name="Bill", age=36)	                dict
x = set(("apple", "banana", "cherry"))	        set
x = frozenset(("apple", "banana", "cherry"))	frozenset
x = bool(5)	                                    bool
x = bytes(5)	                                bytes
x = bytearray(5)	                            bytearray
x = memoryview(bytes(5))                        memoryview
'''''
# 设定特定的数据类型，如果希望指定数据类型，则可以使用以下构造函数