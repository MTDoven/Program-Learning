# NumPy 中的数据类型
# NumPy 有一些额外的数据类型，并通过一个字符引用数据类型，例如 i 代表整数，u 代表无符号整数等。
# 以下是 NumPy 中所有数据类型的列表以及用于表示它们的字符。
#     i - 整数
#     b - 布尔
#     u - 无符号整数
#     f - 浮点
#     c - 复合浮点数
#     m - timedelta
#     M - datetime
#     O - 对象
#     S - 字符串
#     U - unicode 字符串
#     V - 固定的其他类型的内存块 ( void )

import numpy as np
arr = np.array([1, 2, 3, 4])
print(arr.dtype)
#NumPy 数组对象有一个名为 dtype 的属性，该属性返回数组的数据类型
import numpy as np
arr = np.array(['apple', 'banana', 'cherry'])
print(arr.dtype)
#获取包含字符串的数组的数据类型
import numpy as np
arr = np.array([1, 2, 3, 4], dtype='S')
print(arr)
print(arr.dtype)
#我们使用 array() 函数来创建数组，该函数可以使用可选参数：dtype，它允许我们定义数组元素的预期数据类型：
import numpy as np
arr = np.array([1, 2, 3, 4], dtype='i4')
print(arr)
print(arr.dtype)
#创建数据类型为 4 字节整数的数组 #（存在未知）
# 如果给出了不能强制转换元素的类型，则 NumPy 将引发 ValueError。
# ValueError：在 Python 中，如果传递给函数的参数的类型是非预期或错误的，则会引发 ValueError。

# 更改现有数组的数据类型的最佳方法，是使用 astype() 方法复制该数组。
# astype() 函数创建数组的副本，并允许您将数据类型指定为参数。
# 数据类型可以使用字符串指定，例如 'f' 表示浮点数，'i' 表示整数等。
# 或者您也可以直接使用数据类型，例如 float 表示浮点数，int 表示整数。
import numpy as np
arr = np.array([1.1, 2.1, 3.1])
newarr = arr.astype('i')
print(newarr)
print(newarr.dtype)
#通过使用 'i' 作为参数值，将数据类型从浮点数更改为整数
import numpy as np
arr = np.array([1, 0, 3])
newarr = arr.astype(bool)
print(newarr)
print(newarr.dtype)
#将数据类型从整数更改为布尔值

