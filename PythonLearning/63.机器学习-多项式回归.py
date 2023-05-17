# 多项式回归（Polynomial Regression）
# 如果您的数据点显然不适合线性回归（穿过数据点之间的直线），那么多项式回归可能是理想的选择。
# 像线性回归一样，多项式回归使用变量 x 和 y 之间的关系来找到绘制数据点线的最佳方法。
# 工作原理
# Python 有一些方法可以找到数据点之间的关系并画出多项式回归线。我们将向您展示如何使用这些方法而不是通过数学公式。
# 在下面的例子中，我们注册了 18 辆经过特定收费站的汽车。
# 我们已经记录了汽车的速度和通过时间（小时）。
# x 轴表示一天中的小时，y 轴表示速度：
# 首先绘制散点图：
import matplotlib.pyplot as plt
x = [1,2,3,5,6,7,8,9,10,12,13,14,15,16,18,19,21,22]
y = [100,90,80,60,60,55,60,65,70,70,75,76,78,79,90,99,99,100]
plt.scatter(x, y)
plt.show()
#导入 numpy 和 matplotlib，然后画出多项式回归线：
import numpy
import matplotlib.pyplot as plt
x = [1,2,3,5,6,7,8,9,10,12,13,14,15,16,18,19,21,22]
y = [100,90,80,60,60,55,60,65,70,70,75,76,78,79,90,99,99,100]
mymodel = numpy.poly1d(numpy.polyfit(x, y, deg=3))
# polyfit() 函数用于计算多项式回归的系数。poly1d() 函数用于创建一个多项式函数。
# 例如可以numpy.poly1d([1,2,3])创建一个多项式函数：这是一个numpy类
myline = numpy.linspace(1, 22, 100) # linspace() 函数用于创建一个 x 轴上的等差数列，共100个数
plt.scatter(x, y)
plt.plot(myline, mymodel(myline))#mymodel传入数组可以遍历计算结果返回数组
plt.show()
# 例子解释
# 导入所需模块：
# import numpy
# import matplotlib.pyplot as plt
# 创建表示 x 和 y 轴值的数组：
# x = [1,2,3,5,6,7,8,9,10,12,13,14,15,16,18,19,21,22]
# y = [100,90,80,60,60,55,60,65,70,70,75,76,78,79,90,99,99,100]
# NumPy 有一种方法可以让我们建立多项式模型：
# mymodel = numpy.poly1d(numpy.polyfit(x, y, deg=3))
# 然后指定行的显示方式，我们从位置 1 开始，到位置 22 结束：
# myline = numpy.linspace(1, 22, 100)
# 绘制原始散点图：
# plt.scatter(x, y)
# 画出多项式回归线：
# plt.plot(myline, mymodel(myline))
# 显示图：
# plt.show()



# R-Squared
# 重要的是要知道 x 轴和 y 轴的值之间的关系有多好，如果没有关系，则多项式回归不能用于预测任何东西。
# 该关系用一个称为 r 平方（ r-squared）的值来度量。
# r 平方值的范围是 0 到 1，其中 0 表示不相关，而 1 表示 100％ 相关。
# Python 和 Sklearn 模块将为您计算该值，您所要做的就是将 x 和 y 数组输入：
# 我的数据在多项式回归中的拟合度如何？
import numpy
from sklearn.metrics import r2_score
x = [1,2,3,5,6,7,8,9,10,12,13,14,15,16,18,19,21,22]
y = [100,90,80,60,60,55,60,65,70,70,75,76,78,79,90,99,99,100]
mymodel = numpy.poly1d(numpy.polyfit(x, y, 3))
print(r2_score(y, mymodel(x)))#计算拟合度即相关系数
# 检查我的数据在多项式回归中的拟合度如何
#注释：结果 0.94 表明存在很好的关系，我们可以在将来的预测中使用多项式回归。



# 预测未来值
# 现在，我们可以使用收集到的信息来预测未来的值。
# 例如：让我们尝试预测在晚上 17 点左右通过收费站的汽车的速度：
# 为此，我们需要与上面的实例相同的 mymodel 数组：
# mymodel = numpy.poly1d(numpy.polyfit(x, y, 3))
# 预测下午 17 点过车的速度：
import numpy
x = [1,2,3,5,6,7,8,9,10,12,13,14,15,16,18,19,21,22]
y = [100,90,80,60,60,55,60,65,70,70,75,76,78,79,90,99,99,100]
mymodel = numpy.poly1d(numpy.polyfit(x, y, 3))
speed = mymodel(17)
print(speed)
#该例预测速度为 88.87，我们也可以在图中看到



# 糟糕的拟合度？
# 让我们创建一个实例，其中多项式回归不是预测未来值的最佳方法。
# x 和 y 轴的这些值会导致多项式回归的拟合度非常差：
import numpy
import matplotlib.pyplot as plt
x = [89,43,36,36,95,10,66,34,38,20,26,29,48,64,6,5,36,66,72,40]
y = [21,46,3,35,67,95,53,72,58,10,26,34,90,33,38,20,56,2,47,15]
mymodel = numpy.poly1d(numpy.polyfit(x, y, 3))
myline = numpy.linspace(2, 95, 100)
plt.scatter(x, y)
plt.plot(myline, mymodel(myline))
plt.show()
# r-squared 值呢？
# 您应该得到一个非常低的 r-squared 值。
print(r2_score(y, mymodel(x)))
