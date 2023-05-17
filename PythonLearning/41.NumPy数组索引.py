# 访问数组元素
# 数组索引等同于访问数组元素。
# 您可以通过引用其索引号来访问数组元素。
# NumPy 数组中的索引以 0 开头，这意味着第一个元素的索引为 0，第二个元素的索引为 1，以此类推。
import numpy as np
arr = np.array([1, 2, 3, 4])
print(arr[0])
#从以下数组中获取第一个元素
import numpy as np
arr = np.array([[1,2,3,4,5], [6,7,8,9,10]])
print('2nd element on 1st dim: ', arr[0, 1])
#访问第一维中的第二个元素
import numpy as np
arr = np.array([[1,2,3,4,5], [6,7,8,9,10]])
print('Last element from 2nd dim: ', arr[1, -1])
#访问第二维中的最后一个元素