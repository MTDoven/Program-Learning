# 您可以在数组中搜索（检索）某个值，然后返回获得匹配的索引。
# 要搜索数组，请使用 where() 方法。

import numpy as np
arr = np.array([1, 2, 3, 4, 5, 4, 4])
x = np.where(arr == 4)
print(x, type(x))
#查找值为 4 的索引
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])
x = np.where(arr%2 == 0)
print(x)
#查找值为偶数的索引
#where()相当于遍历数组中每一个元素，把计算值为True的元素的索引保存在一个数组中。

# 搜索排序
# 有一个名为 searchsorted() 的方法，该方法在数组中执行二进制搜索，并返回将在其中插入指定值以维持搜索顺序的索引。
# 假定 searchsorted() 方法用于排序数组。
import numpy as np
arr = np.array([6, 7, 8, 9])
x = np.searchsorted(arr, 7)
print(x, type(x))
# 例子解释：应该在索引 1 上插入数字 7，以保持排序顺序。
# 该方法从左侧开始搜索，并返回第一个索引，其中数字 7 不再大于下一个值。
import numpy as np
arr = np.array([6, 7, 8, 9])
x = np.searchsorted(arr, 7, side='right')
print(x, type(x))
# 从右侧搜索：默认情况下，返回最左边的索引，但是我们可以给定 side='right'，以返回最右边的索引。
arr = np.array([1, 1, 3, 5, 7])
x = np.searchsorted(arr, [2, 4, 6])
print(x)
# 确定这些数字应该插入到哪里
#（存在未知）