# 从现有数组中取出一些元素并从中创建新数组称为过滤（filtering）。
# 在 NumPy 中，我们使用布尔索引列表来过滤数组。
# 布尔索引列表是与数组中的索引相对应的布尔值列表。
# 如果索引处的值为 True，则该元素包含在过滤后的数组中
# 如果索引处的值为 False，则该元素将从过滤后的数组中排除。
import numpy as np
arr = np.array([61, 62, 63, 64, 65])
x = [True, False, True, False, True]
newarr = arr[x]
print(newarr)
#用索引 0 和 2、4 上的元素创建一个数组
#True的元素将包含在新数组中


import numpy as np
arr = np.array([61, 62, 63, 64, 65])
filter_arr = []# 创建一个空列表
for element in arr:# 遍历 arr 中的每个元素
  if element > 62:
    filter_arr.append(True)
  else:  # 如果元素大于 62，则将值设置为 True，否则为 False：
    filter_arr.append(False)
newarr = arr[filter_arr]
print(filter_arr)
print(newarr)
#创建一个仅返回大于 62 的值的过滤器数组


# 直接从数组创建过滤器
# 上例是 NumPy 中非常常见的任务，NumPy 提供了解决该问题的好方法。
# 我们可以在条件中直接替换数组而不是 iterable 变量，它会如我们期望地那样工作。
import numpy as np
arr = np.array([61, 62, 63, 64, 65])
filter_arr = arr > 62#相当于遍历arr中的每一个元素，将True的保存到filter_arr中
newarr = arr[filter_arr]
print(filter_arr)
print(newarr)

