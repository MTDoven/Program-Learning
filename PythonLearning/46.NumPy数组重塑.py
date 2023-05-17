# 数组重塑
# 重塑意味着更改数组的形状。
# 数组的形状是每个维中元素的数量。
# 通过重塑，我们可以添加或删除维度或更改每个维度中的元素数量。

#将以下具有 12 个元素的 1-D 数组转换为 2-D 数组。
# 最外面的维度将有 4 个数组，每个数组包含 3 个元素
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
newarr = arr.reshape(4, 3)#由高维到低维
print(newarr)
'''''
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])
newarr = arr.reshape(3, 3)
print(newarr)
#尝试将具有 8 个元素的 1D 数组转换为每个维度中具有 3 个元素的 2D 数组（将产生错误）
'''''
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])
print(arr.reshape(2, 4).base)
print(arr.reshape(2, 4))
#返回的是一个视图


# 您可以使用一个“未知”维度。
# 这意味着您不必在 reshape 方法中为维度之一指定确切的数字。
# 传递 -1 作为值，NumPy 将为您计算该数字。
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])
newarr = arr.reshape(2, 2, -1)
print(newarr)
#将 8 个元素的 1D 数组转换为 2x2 元素的 3D 数组：
# 注释：我们不能将 -1 传递给一个以上的维度。

# 展平数组（Flattening the arrays）是指将多维数组转换为 1D 数组。
# 我们可以使用 reshape(-1) 来做到这一点。
import numpy as np
arr = np.array([[1, 2, 3], [4, 5, 6]])
newarr = arr.reshape(-1)
print(newarr)
#把数组转换为 1D 数组

# 注释：有很多功能可以更改 numpy flatten、ravel 中数组形状，
# 还可以重新排列元素 rot90、flip、fliplr、flipud 等。
# 这些功能属于 numpy 的中级至高级部分。
#(存在未知)