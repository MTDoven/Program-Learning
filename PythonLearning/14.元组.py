thistuple = ("apple", "banana", "cherry")
print(thistuple)
#创建元组
thistuple = ("apple", "banana", "cherry")
print(thistuple[1])
#访问元组中的值

#创建元组后，您将无法更改其值。元组是不可变的，或者也称为恒定的。
#但是有一种解决方法。您可以将元组转换为列表，更改列表，然后将列表转换回元组。
x = ("apple", "banana", "cherry")
y = list(x)
y[1] = "kiwi"
x = tuple(y)
print(x)
#修改元组中的值
thistuple = ("apple", "banana", "cherry")
for x in thistuple:
  print(x)
#遍历元组中的值
thistuple = ("apple", "banana", "cherry")
if "apple" in thistuple:
  print("Yes, 'apple' is in the fruits tuple")
#判断元组中是否存在某个值
thistuple = ("apple", "banana", "cherry")
print(len(thistuple))
#计算元组元素个数

#元组一旦创建，您就无法向其添加项目。元组是不可改变的。
thistuple = ("apple",)
print(type(thistuple))#元组只有一个元素时，需要在元素后面添加逗号
thistuple = ("apple")
print(type(thistuple))#返回字符串
#如需创建仅包含一个项目的元组，您必须在该项目后添加一个逗号，否则 Python 无法将变量识别为元组。
#注释：您无法删除元组中的项目。
#元组是不可更改的，因此您无法从中删除项目，但您可以完全删除元组：
tuple1 = ("a", "b" , "c")
tuple2 = (1, 2, 3)
tuple3 = tuple1 + tuple2
print(tuple3)
#合并这个元组

print(tuple3.count("a"))
# count() 	返回元组中指定值出现的次数。
print(tuple3.index('a'))
# index() 	在元组中搜索指定的值并返回它被找到的位置。
