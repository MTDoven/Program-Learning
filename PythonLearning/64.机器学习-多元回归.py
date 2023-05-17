# 多元回归（Multiple Regression）
# 多元回归就像线性回归一样，但是具有多个独立值，这意味着我们试图基于两个或多个变量来预测一个值。
# 请看下面的数据集，其中包含了一些有关汽车的信息。
# Car 	        Model 	    Volume 	Weight 	CO2
# Toyota 	    Aygo 	    1000 	790 	99
# Mitsubishi 	SpaceStar 	1200 	1160 	95
# Skoda 	    Citigo 	    1000 	929 	95
# Fiat 	        500 	    900 	865 	90
# Mini 	        Cooper 	    1500 	1140 	105
# VW 	        Up! 	    1000 	929 	105
# Skoda 	    Fabia 	    1400 	1109 	90
# Mercedes 	    A-Class 	1500 	1365 	92
# Ford 	        Fiesta 	    1500 	1112 	98
# Audi 	        A1 	        1600 	1150 	99
# Hyundai 	    I20 	    1100 	980 	99
# Suzuki 	    Swift 	    1300 	990 	101
# Ford 	        Fiesta 	    1000 	1112 	99
# Honda 	    Civic 	    1600 	1252 	94
# Hundai 	    I30 	    1600 	1326 	97
# Opel 	        Astra 	    1600 	1330 	97
# BMW 	        1 	        1600 	1365 	99
# Mazda 	    3 	        2200 	1280 	104
# Skoda 	    Rapid 	    1600 	1119 	104
# Ford 	        Focus 	    2000 	1328 	105
# Ford 	        Mondeo 	    1600 	1584 	94
# Opel 	        Insignia 	2000 	1428 	99
# Mercedes 	    C-Class 	2100 	1365 	99
# Skoda 	    Octavia 	1600 	1415 	99
# Volvo 	    S60 	    2000 	1415 	99
# Mercedes 	    CLA 	    1500 	1465 	102
# Audi 	        A4 	        2000 	1490 	104
# Audi 	        A6 	        2000 	1725 	114
# Volvo 	    V70 	    1600 	1523 	109
# BMW 	        5 	        2000 	1705 	114
# Mercedes 	    E-Class 	2100 	1605 	115
# Volvo 	    XC70 	    2000 	1746 	117
# Ford 	        B-Max 	    1600 	1235 	104
# BMW 	        2 	        1600 	1390 	108
# Opel 	        Zafira 	    1600 	1405 	109
# Mercedes 	    SLK 	    2500 	1395 	120
# 我们可以根据发动机排量的大小预测汽车的二氧化碳排放量，但是通过多元回归，我们可以引入更多变量，例如汽车的重量，以使预测更加准确。
# 工作原理
# 在 Python 中，我们拥有可以完成这项工作的模块。首先导入 Pandas 模块：
# import pandas
# Pandas 模块允许我们读取 csv 文件并返回一个 DataFrame 对象。
# 此文件仅用于测试目的，您可以在此处下载：cars.csv
# df = pandas.read_csv("cars.csv")
# 然后列出独立值，并将这个变量命名为 X。
# 将相关值放入名为 y 的变量中。
# X = df[['Weight', 'Volume']]
# y = df['CO2']
# 提示：通常，将独立值列表命名为大写 X(自变量)，将相关值列表命名为小写 y（因变量）。
# 我们将使用 sklearn 模块中的一些方法，因此我们也必须导入该模块：
# from sklearn import linear_model
# 在 sklearn 模块中，我们将使用 LinearRegression() 方法创建一个线性回归对象。
# 该对象有一个名为 fit() 的方法，该方法将独立值（自变量）和从属值（因变量）作为参数，并用描述这种关系的数据填充回归对象：
# regr = linear_model.LinearRegression()
# regr.fit(X, y)
# 现在，我们有了一个回归对象，可以根据汽车的重量和排量预测 CO2 值：
# # 预测重量为 2300kg、排量为 1300ccm 的汽车的二氧化碳排放量：
# predictedCO2 = regr.predict([[2300, 1300]])
#请看完整实例：
import pandas
from sklearn import linear_model
df = pandas.read_csv("./0.Infomation/cars.csv")
X = df[['Weight', 'Volume']]
print(type(X))
y = df['CO2']
regr = linear_model.LinearRegression()
regr.fit(X, y)
predictedCO2 = regr.predict([[2300, 1300]])
print(predictedCO2)
#我们预测，配备 1.3 升发动机，重量为 2300 千克的汽车，每行驶 1 公里，就会释放约 107 克二氧化碳。



# 系数
# 系数是描述与未知变量的关系的因子。
# 例如：如果 x 是变量，则 2x 是 x 的两倍。x 是未知变量，数字 2 是系数。
# 在这种情况下，我们可以要求重量相对于 CO2 的系数值，以及体积相对于 CO2 的系数值。
# 我们得到的答案告诉我们，如果我们增加或减少其中一个独立值，将会发生什么。
# 打印回归对象的系数值：
import pandas
from sklearn import linear_model
df = pandas.read_csv("cars.csv")
X = df[['Weight', 'Volume']]
y = df['CO2']
regr = linear_model.LinearRegression()
regr.fit(X, y)
print(regr.coef_)#打印系数值
# 结果解释
# 结果数组表示重量和排量的系数值。
# Weight: 0.00755095
# Volume: 0.00780526
# 这些值告诉我们，如果重量增加 1g，则 CO2 排放量将增加 0.00755095g。
# 如果发动机尺寸（容积）增加 1 ccm，则 CO2 排放量将增加 0.00780526g。

# 我认为这是一个合理的猜测，但还是请进行测试！
# 我们已经预言过，如果一辆配备 1300ccm 发动机的汽车重 2300 千克，则二氧化碳排放量将约为 107 克。
# 如果我们增加 1000g 的重量会怎样？
# 复制之前的例子，但是将车重从 2300 更改为 3300：
import pandas
from sklearn import linear_model
df = pandas.read_csv("./0.Infomation/cars.csv")
X = df[['Weight', 'Volume']]
y = df['CO2']
regr = linear_model.LinearRegression()
regr.fit(X, y)
predictedCO2 = regr.predict([[3300, 1300]])
print(predictedCO2)
# 我们已经预测，配备 1.3 升发动机，重量为 3.3 吨的汽车，每行驶 1 公里，就会释放约 115 克二氧化碳。
# 这表明 0.00755095 的系数是正确的：
# 107.2087328 + (1000 * 0.00755095) = 114.75968
