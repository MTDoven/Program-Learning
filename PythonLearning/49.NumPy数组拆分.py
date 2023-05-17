# 拆分 NumPy 数组
# 拆分是连接的反向操作。
# 连接（Joining）是将多个数组合并为一个，拆分（Spliting）将一个数组拆分为多个。
# 我们使用 array_split() 分割数组，将要分割的数组和分割数传递给它。

import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6])
newarr = np.array_split(arr, 3)
print(newarr, type(newarr))
#返回的是一个列表，列表中每个元素都是一个数组，数组的大小是2
import numpy as np
arr = np.array([1, 2, 3, 4, 5, 6])
newarr = np.array_split(arr, 4)
print(newarr)
#先大后小分为四部分
# 我们也有 split() 方法可用，但是当源数组中的元素较少用于拆分时，它将不会调整元素，
# 如上例那样，array_split() 正常工作，但 split() 会失败。
import numpy as np
arr = np.array([[1, 2], [3, 4], [5, 6], [7, 8], [9, 10], [11, 12]])
newarr = np.array_split(arr, 3)
print(newarr)
#把这个 2-D 拆分为三个 2-D 数组。

import numpy as np
arr = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12], [13, 14, 15], [16, 17, 18]])
newarr = np.array_split(arr, 3, axis=1)
print(newarr)
#沿行把这个 2-D 拆分为三个 2-D 数组
import numpy as np
arr = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12], [13, 14, 15], [16, 17, 18]])
newarr = np.hsplit(arr, 3)
print(newarr)
#使用 hsplit() 方法将 2-D 数组沿着行分成三个 2-D 数组。
#提示：vsplit() 和 dsplit() 可以使用与 vstack() 和 dstack() 类似的替代方法。


