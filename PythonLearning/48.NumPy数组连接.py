# 连接意味着将两个或多个数组的内容放在单个数组中。
# 在 SQL 中，我们基于键来连接表，而在 NumPy 中，我们按轴连接数组。
# 我们传递了一系列要与轴一起连接到 concatenate() 函数的数组。如果未显式传递轴，则将其视为 0。
#(存在未知)

import numpy as np
arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])
arr = np.concatenate((arr1, arr2))
print(arr)
#连接两个数组
import numpy as np
arr1 = np.array([[1, 2], [3, 4]])
arr2 = np.array([[5, 6], [7, 8]])
arr = np.concatenate((arr1, arr2), axis=1)
print(arr)
#沿着行axis=1连接两个 2-D 数组，axis=0按列连接两个数组


# 使用堆栈函数连接数组
# 堆栈与级联相同，唯一的不同是堆栈是沿着新轴完成的。
# 我们可以沿着第二个轴连接两个一维数组，这将导致它们彼此重叠，即，堆叠（stacking）。
# 我们传递了一系列要与轴一起连接到 concatenate() 方法的数组。如果未显式传递轴，则将其视为 0。
# （存在未知）
import numpy as np
arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])
arr = np.stack((arr1, arr2), axis=1)
print(arr)
#（存在未知）

# 沿行堆叠
# NumPy 提供了一个辅助函数：hstack() 沿行堆叠。
import numpy as np
arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])
arr = np.hstack((arr1, arr2))
print(arr)
# 沿列堆叠
# NumPy 提供了一个辅助函数：vstack() 沿列堆叠。
import numpy as np
arr1 = np.array([1, 2, 3])
arr2 = np.array([4, 5, 6])
arr = np.vstack((arr1, arr2))
print(arr)
# 沿高度堆叠（深度）
# NumPy 提供了一个辅助函数：dstack() 沿高度堆叠，该高度与深度相同。
import numpy as np
arr1 = np.array([[1, 2], [3, 4]])
arr2 = np.array([[4, 5], [6, 7]])
arr = np.dstack((arr1, arr2))#（存在未知）
print(arr)


