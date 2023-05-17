# 数组排序
# 排序是指将元素按有序顺序排列。
# 有序序列是拥有与元素相对应的顺序的任何序列，例如数字或字母、升序或降序。
# NumPy ndarray 对象有一个名为 sort() 的函数，该函数将对指定的数组进行排序。

import numpy as np
arr = np.array([3, 2, 0, 1])
print(np.sort(arr))
#排序 #此方法返回数组的副本，而原始数组保持不变。
# 对字符串和布尔值同样适用
import numpy as np
arr = np.array([[3, 2, 4], [5, 0, 1]])
print(np.sort(arr))
#二维数组排序在每一行上进行排序