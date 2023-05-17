# 回归
# 当您尝试找到变量之间的关系时，会用到术语“回归”（regression）。
# 在机器学习和统计建模中，这种关系用于预测未来事件的结果。
# 线性回归
# 线性回归使用数据点之间的关系在所有数据点之间画一条直线。
# 这条线可以用来预测未来的值。
# 在机器学习中，预测未来非常重要。
# 工作原理
# Python 提供了一些方法来查找数据点之间的关系并绘制线性回归线。我们将向您展示如何使用这些方法而不是通过数学公式。
# 在下面的示例中，x 轴表示车龄，y 轴表示速度。我们已经记录了 13 辆汽车通过收费站时的车龄和速度。
# 让我们看看我们收集的数据是否可以用于线性回归：

#首先绘制散点图：
import matplotlib.pyplot as plt
x = [5,7,8,7,2,17,2,9,4,11,12,9,6]
y = [99,86,87,88,111,86,103,87,94,78,77,85,86]
plt.scatter(x, y)
plt.show()
#导入 scipy 并绘制线性回归线：
import matplotlib.pyplot as plt
from scipy import stats
x = [5,7,8,7,2,17,2,9,4,11,12,9,6]
y = [99,86,87,88,111,86,103,87,94,78,77,85,86]
slope, intercept, r, p, std_err = stats.linregress(x, y)
#slope是斜率，intercept是截距，r是相关系数，p是认为xy相关的情况下犯错误的概率，std_err是标准差
def myfunc(x):
  return slope * x + intercept #返回的就是y=mx+b的函数的估计值
mymodel = list(map(myfunc, x)) #map是一个函数，将函数作用于每个元素，返回一个map对象,可以用list转换为list
plt.scatter(x, y)
plt.plot(x, mymodel)
plt.show()
# 例子解释
# 入所需模块：
# import matplotlib.pyplot as plt
# from scipy import stats
# 创建表示 x 和 y 轴值的数组：
# x = [5,7,8,7,2,17,2,9,4,11,12,9,6]
# y = [99,86,87,88,111,86,103,87,94,78,77,85,86]
# 执行一个方法，该方法返回线性回归的一些重要键值：
# slope, intercept, r, p, std_err = stats.linregress(x, y)
# 创建一个使用 slope 和 intercept 值的函数返回新值。这个新值表示相应的 x 值将在 y 轴上放置的位置：
# def myfunc(x):
#   return slope * x + intercept
# 通过函数运行 x 数组的每个值。这将产生一个新的数组，其中的 y 轴具有新值：
# mymodel = list(map(myfunc, x))
# 绘制原始散点图：
# plt.scatter(x, y)
# 绘制线性回归线：
# plt.plot(x, mymodel)
# 显示图：
# plt.show()





# R-Squared
# 重要的是要知道 x 轴的值和 y 轴的值之间的关系有多好，如果没有关系，则线性回归不能用于预测任何东西。
# 该关系用一个称为 r 平方（r-squared）的值来度量。
# r 平方值的范围是 0 到 1，其中 0 表示不相关，而 1 表示 100％ 相关。
# Python 和 Scipy 模块将为您计算该值，您所要做的就是将 x 和 y 值提供给它：

#我的数据在线性回归中的拟合度如何？
from scipy import stats
x = [5,7,8,7,2,17,2,9,4,11,12,9,6]
y = [99,86,87,88,111,86,103,87,94,78,77,85,86]
slope, intercept, r, p, std_err = stats.linregress(x, y)
print(r)
# 注释：结果 -0.76 表明存在某种关系，但不是完美的关系，但它表明我们可以在将来的预测中使用线性回归。
# 预测未来价值
# 现在，我们可以使用收集到的信息来预测未来的值。
# 例如：让我们尝试预测一辆拥有 10 年历史的汽车的速度。
# 为此，我们需要与上例中相同的 myfunc() 函数：
def myfunc(x):
  return slope * x + intercept
# 预测一辆有 10年车龄的汽车的速度：
from scipy import stats
x = [5,7,8,7,2,17,2,9,4,11,12,9,6]
y = [99,86,87,88,111,86,103,87,94,78,77,85,86]
slope, intercept, r, p, std_err = stats.linregress(x, y)
def myfunc(x):
  return slope * x + intercept
speed = myfunc(10)
print(speed)
#该例预测速度为 85.6，我们也可以从图中读取：





# 糟糕的拟合度？
# 让我们创建一个实例，其中的线性回归并不是预测未来值的最佳方法。

#x 和 y 轴的这些值将导致线性回归的拟合度非常差：
import matplotlib.pyplot as plt
from scipy import stats
x = [89,43,36,36,95,10,66,34,38,20,26,29,48,64,6,5,36,66,72,40]
y = [21,46,3,35,67,95,53,72,58,10,26,34,90,33,38,20,56,2,47,15]
slope, intercept, r, p, std_err = stats.linregress(x, y)
def myfunc(x):
  return slope * x + intercept
mymodel = list(map(myfunc, x))
plt.scatter(x, y)
plt.plot(x, mymodel)
plt.show()
# 以及 r-squared 值？
# 您应该得到了一个非常低的 r-squared 值。
print(r)
