# 特征缩放（Scale Features）
# 当您的数据拥有不同的值，甚至使用不同的度量单位时，可能很难比较它们。与米相比，公斤是多少？或者海拔比较时间呢？
# 这个问题的答案是缩放。我们可以将数据缩放为易于比较的新值。
# 请看下表，它与我们在多元回归一章中使用的数据集相同，但是这次，Volume 列包含的单位是升，而不是 ccm（1.0 而不是 1000）。
# Car 	Model 	Volume 	Weight 	CO2
# Toyota 	Aygo 	1.0 	790 	99
# Mitsub 	Space 	1.2 	1160 	95
# Skoda 	Citigo 	1.0 	929 	95
# Fiat 	500 	0.9 	865 	90
# Mini 	Cooper 	1.5 	1140 	105
# VW 	    Up! 	1.0 	929 	105
# Skoda 	Fabia 	1.4 	1109 	90
# Mercede A-Class 1.5 	1365 	92
# Ford 	Fiesta 	1.5 	1112 	98
# Audi 	A1 	    1.6 	1150 	99
# Hyundai I20 	1.1 	980 	99
# Suzuki 	Swift 	1.3 	990 	101
# Ford 	Fiesta 	1.0 	1112 	99
# Honda 	Civic 	1.6 	1252 	94
# Hundai 	I30 	1.6 	1326 	97
# Opel 	Astra 	1.6 	1330 	97
# BMW 	1 	    1.6 	1365 	99
# Mazda 	3 	    2.2 	1280 	104
# Skoda 	Rapid 	1.6 	1119 	104
# Ford 	Focus 	2.0 	1328 	105
# Ford 	Mondeo 	1.6 	1584 	94
# Opel 	Insig 	2.0 	1428 	99
# Merce 	C-Class 2.1 	1365 	99
# Skoda 	Octavia 1.6 	1415 	99
# Volvo 	S60 	2.0 	1415 	99
# Merc 	CLA 	1.5 	1465 	102
# Audi 	A4 	    2.0 	1490 	104
# Audi 	A6 	    2.0 	1725 	114
# Volvo 	V70 	1.7 	1523 	109
# BMW 	5 	    2.0 	1705 	114
# Merce 	E-Class 2.1 	1605 	115
# Volvo 	XC70 	2.0 	1746 	117
# Ford 	B-Max 	1.6 	1235 	104
# BMW 	2 	    1.6 	1390 	108
# Opel 	Zafira 	1.6 	1405 	109
# Merce 	SLK 	2.5 	1395 	120
# 很难将排量 1.0 与车重 790 进行比较，但是如果将它们都缩放为可比较的值，我们可以很容易地看到一个值与另一个值相比有多少。
# 缩放数据有多种方法，在本教程中，我们将使用一种称为标准化（standardization）的方法。
# 标准化方法使用以下公式：
# z = (x - u) / s
# 其中 z 是新值，x 是原始值，u 是平均值，s 是标准差。
# 如果从上述数据集中获取 weight 列，则第一个值为 790，缩放后的值为：
# (790 - 1292.23) / 238.74 = -2.1
# 如果从上面的数据集中获取 volume 列，则第一个值为 1.0，缩放后的值为：
# (1.0 - 1.61) / 0.38 = -1.59
# 现在，您可以将 -2.1 与 -1.59 相比较，而不是比较 790 与 1.0。
# 您不必手动执行此操作，Python sklearn 模块有一个名为 StandardScaler() 的方法，该方法返回带有转换数据集方法的 Scaler 对象。
# 缩放 Weight 和 Volume 列中的所有值：
import pandas
from sklearn import linear_model
from sklearn.preprocessing import StandardScaler
scale = StandardScaler()
df = pandas.read_csv("cars.csv")
X = df[['Weight', 'Volume']]
scaledX = scale.fit_transform(X)
print(scaledX)
# 结果：
# 请注意，前两个值是 -2.1 和 -1.59，与我们的计算相对应：
# [[-2.10389253 -1.59336644]
#  [-0.55407235 -1.07190106]
#  [-1.52166278 -1.59336644]
#  [-1.78973979 -1.85409913]
#  [-0.63784641 -0.28970299]
#  [-1.52166278 -1.59336644]
#  [-0.76769621 -0.55043568]
#  [ 0.3046118  -0.28970299]
#  [-0.7551301  -0.28970299]
#  [-0.59595938 -0.0289703 ]
#  [-1.30803892 -1.33263375]
#  [-1.26615189 -0.81116837]
#  [-0.7551301  -1.59336644]
#  [-0.16871166 -0.0289703 ]
#  [ 0.14125238 -0.0289703 ]
#  [ 0.15800719 -0.0289703 ]
#  [ 0.3046118  -0.0289703 ]
#  [-0.05142797  1.53542584]
#  [-0.72580918 -0.0289703 ]
#  [ 0.14962979  1.01396046]
#  [ 1.2219378  -0.0289703 ]
#  [ 0.5685001   1.01396046]
#  [ 0.3046118   1.27469315]
#  [ 0.51404696 -0.0289703 ]
#  [ 0.51404696  1.01396046]
#  [ 0.72348212 -0.28970299]
#  [ 0.8281997   1.01396046]
#  [ 1.81254495  1.01396046]
#  [ 0.96642691 -0.0289703 ]
#  [ 1.72877089  1.01396046]
#  [ 1.30990057  1.27469315]
#  [ 1.90050772  1.01396046]
#  [-0.23991961 -0.0289703 ]
#  [ 0.40932938 -0.0289703 ]
#  [ 0.47215993 -0.0289703 ]
#  [ 0.4302729   2.31762392]]



# 预测 CO2 值
# 多元回归一章的任务是在仅知道汽车的重量和排量的情况下预测其排放的二氧化碳。
# 缩放数据集后，在预测值时必须使用缩放比例：
# 预测一辆重 2300 公斤的 1.3 升汽车的二氧化碳排放量：
import pandas
from sklearn import linear_model
from sklearn.preprocessing import StandardScaler
scale = StandardScaler()
df = pandas.read_csv("./0.Infomation/cars2.csv")
X = df[['Weight', 'Volume']]
y = df['CO2']
scaledX = scale.fit_transform(X)
regr = linear_model.LinearRegression()
regr.fit(scaledX, y)
scaled = scale.transform([[2300, 1.3]])
predictedCO2 = regr.predict([scaled[0]])
print(predictedCO2)
# 结果：
# [107.2087328]