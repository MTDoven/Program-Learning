#NumPy 数组有一个名为 shape 的属性，该属性返回一个元组，每个索引具有相应元素的数量。
import numpy as np
arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
print(arr.shape)
#打印 2-D 数组的形状

import numpy as np
arr = np.array([1, 2, 3, 4], ndmin=5)
print(arr)
print('shape of array :', arr.shape)
#利用 ndmin 使用值 1,2,3,4 的向量创建有 5 个维度的数组，并验证最后一个维度的值

# 元组的形状代表什么？
# 每个索引处的整数表明相应维度拥有的元素数量。
# 上例中的索引 4，我们的值为 4，因此可以说第 5 个 ( 4 + 1 th) 维度有 4 个元素