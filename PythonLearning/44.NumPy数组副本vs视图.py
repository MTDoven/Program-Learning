# 副本和视图之间的区别
# 副本和数组视图之间的主要区别在于副本是一个新数组，而这个视图只是原始数组的视图。
# 副本拥有数据，对副本所做的任何更改都不会影响原始数组，对原始数组所做的任何更改也不会影响副本。
# 视图不拥有数据，对视图所做的任何更改都会影响原始数组，而对原始数组所做的任何更改都会影响视图。

import numpy as np
arr = np.array([1, 2, 3, 4, 5])
x = arr.copy()
arr[0] = 61
print(arr)
print(x)
#进行复制，更改原始数组并显示两个数组
import numpy as np
arr = np.array([1, 2, 3, 4, 5])
x = arr.view()
arr[0] = 61
print(arr)
print(x)
#进行视图，更改数组并显示两个数组，更改视图同理影响原始数组

# 如上所述，副本拥有数据，而视图不拥有数据，但是我们如何检查呢？
# 每个 NumPy 数组都有一个属性 base，如果该数组拥有数据，则这个 base 属性返回 None。
# 否则，base 属性将引用原始对象。
import numpy as np
arr = np.array([1, 2, 3, 4, 5])
x = arr.copy()
y = arr.view()
print(x.base)
print(y.base)
#base就是查看此数据来自于谁，如果它就是自己，那么就返回了None


