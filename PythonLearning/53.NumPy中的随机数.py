# 什么是随机数？
# 随机数并不意味着每次都有不同的数字。随机意味着无法在逻辑上预测的事物。
# 伪随机和真随机
# 计算机在程序上工作，程序是权威的指令集。因此，这意味着必须有某种算法来生成随机数。
# 如果存在生成随机数的程序，则可以预测它，因此它就不是真正的随机数。
# 通过生成算法生成的随机数称为伪随机数。
# 我们可以生成真正的随机数吗？
# 是的。为了在我们的计算机上生成一个真正的随机数，我们需要从某个外部来源获取随机数据。外部来源通常是我们的击键、鼠标移动、网络数据等。
# 我们不需要真正的随机数，除非它与安全性（例如加密密钥）有关或应用的基础是随机性（例如数字轮盘赌轮）。
# 在本教程中，我们将使用伪随机数。
# 生成随机数
# NumPy 提供了 random 模块来处理随机数。

from numpy import random
x = random.randint(100)
print(x)
#生成一个 0 到 100 之间的随机整数
from numpy import random
x = random.rand()
print(x)
#random 模块的 rand() 方法返回 0 到 1 之间的随机浮点数。
#生成一个 0 到 1 之间的随机浮点数

# 生成随机数组
# 在 NumPy 中，我们可以使用上例中的两种方法来创建随机数组。
# randint() 方法接受 size 参数，您可以在其中指定数组的形状。
from numpy import random
x=random.randint(100, size=(5))
print(x)
# 生成一个 1-D 数组，其中包含 5 个从 0 到 100 之间的随机整数
from numpy import random
x = random.randint(100, size=(3, 5))
print(x)
#生成有 3 行的 2-D 数组，每行包含 5 个从 0 到 100 之间的随机整数
from numpy import random
x = random.rand(5)
print(x)
#生成包含 5 个随机浮点数的 1-D 数组
from numpy import random
x = random.rand(3, 5)
print(x)
#生成有 3 行的 2-D 数组，每行包含 5 个随机数

# 从数组生成随机数
# choice() 方法使您可以基于值数组生成随机值。
# choice() 方法将数组作为参数，并随机返回其中一个值。
import numpy as np
arr = np.random.randint(100, size=(5))
x = np.random.choice(arr)
print(x,type(x))
#返回数组中的值之一 #也可以是列表

# choice() 方法还允许您返回一个值数组。
# 请添加一个 size 参数以指定数组的形状。
from numpy import random
x = random.choice([3, 5, 7, 9], size=(3, 5))
print(x)
# 生成由数组参数（3、5、7 和 9）中的值组成的二维数组


