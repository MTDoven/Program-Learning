# python 中裁切的意思是将元素从一个给定的索引带到另一个给定的索引。
# 我们像这样传递切片而不是索引：[start：end]。
# 我们还可以定义步长，如下所示：[start：end：step]。
# 如果我们不传递 start，则将其视为 0。
# 如果我们不传递 end，则视为该维度内数组的长度。
# 如果我们不传递 step，则视为 1。

import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7])
print(arr[1:5])
#从上面的数组中裁切索引 1 到索引 5 的元素
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7])
print(arr[1:5:2])
#从上面的数组中裁切索引 1 到索引 5 的元素，步长为 2
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6, 7])
print(arr[::2])
#相当于两个缺省

import numpy as np
arr = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
print(arr[1, 1:4])
#二维数组裁剪
import numpy as np
arr = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
print(arr[0:2, 2])
#二维数组纵向裁剪
import numpy as np
arr = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
print(arr[0:2, 1:4])
#二维数组矩形裁剪

