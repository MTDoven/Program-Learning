import numpy as np
arr = np.array([1, 2, 3, 4, 5])
print(arr)
print(type(arr))
# 它表明 arr 是 numpy.ndarray 类型
# 要创建 ndarray，我们可以将列表、元组或任何类似数组的对象传递给 array() 方法
# 然后它将被转换为 ndarray
import numpy as np
arr = np.array((1, 2, 3, 4, 5))
print(arr)
#使用元组创建数组

# 数组中的维是数组深度（嵌套数组）的一个级别。
# 嵌套数组：指的是将数组作为元素的数组。
import numpy as np
arr = np.array(61)
print(arr)
# 创建一个0维数组
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6])
print(arr)
# 创建一个1维数组
import numpy as np
arr = np.array([[1, 2, 3], [4, 5, 6]])
print(arr)
# 创建一个2维数组
import numpy as np
arr = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])
print(arr)
# 创建一个3维数组

import numpy as np
a = np.array(42)
b = np.array([1, 2, 3, 4, 5])
c = np.array([[1, 2, 3], [4, 5, 6]])
d = np.array([[[1, 2, 3], [4, 5, 6]], [[1, 2, 3], [4, 5, 6]]])
print(a.ndim)
print(b.ndim)
print(c.ndim)
print(d.ndim)
# 检查数组的维度

import numpy as np
arr = np.array([[1, 2], [3, 4]], ndmin=5)
print(arr)
print('number of dimensions :', arr.ndim)
# ndmin 参数用于指定数组的最小维度。
# 在此数组中，
# 最里面的维度（第 5 个 dim）有 4 个元素，
# 第 4 个 dim 有 1 个元素作为向量，
# 第 3 个 dim 具有 1 个元素是与向量的矩阵，
# 第 2 个 dim 有 1 个元素是 3D 数组，
# 而第 1 个 dim 有 1 个元素，该元素是 4D 数组。
# (存在未知)