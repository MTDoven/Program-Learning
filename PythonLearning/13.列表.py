# Python 编程语言中有四种集合数据类型：
#     列表（List）是一种有序和可更改的集合。允许重复的成员。
#     元组（Tuple）是一种有序且不可更改的集合。允许重复的成员。
#     集合（Set）是一个无序和无索引的集合。没有重复的成员。
#     词典（Dictionary）是一个无序，可变和有索引的集合。没有重复的成员。

thislist = ["apple", "banana", "cherry"]
print(thislist)
#创建列表
thislist = ["apple", "banana", "cherry"]
print(thislist[1])
#访问列表中的值
thislist = ["apple", "banana", "cherry"]
print(thislist[-1])#返回的是值
#打印列表中的最后一个值
thislist = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]
print(thislist[2:5]) #返回的是列表
#打印从第2（不包括）个到第5个的值
thislist = ["apple", "banana", "cherry"]
thislist[1] = "mango"
print(thislist)
#修改列表中的值

thislist = ["apple", "banana", "cherry"]
for x in thislist:
  print(x)
#遍历列表
thislist = ["apple", "banana", "cherry"]
if "apple" in thislist:
  print("Yes, 'apple' is in the fruits list")
#判断列表中是否包含某个值
thislist = ["apple", "banana", "cherry"]
print(len(thislist))
#计算列表长度
thislist = ["apple", "banana", "cherry"]
thislist.append("orange")
print(thislist)
#在列表末尾添加新的值append
thislist = ["apple", "banana", "cherry"]
thislist.insert(1, "orange")
print(thislist)
#在指定位置插入值insert
thislist = ["apple", "banana", "cherry"]
thislist.remove("banana")
print(thislist)
#删除列表中的值remove
thislist = ["apple", "banana", "cherry"]
thislist.pop(0)
print(thislist)
#删除列表中指定位置的值pop（不指定最后一个）
thislist = ["apple", "banana", "cherry"]
del thislist[0]
print(thislist)
#删除列表中指定位置的值del
thislist = ["apple", "banana", "cherry"]
del thislist
#删除整个列表
thislist = ["apple", "banana", "cherry"]
thislist.clear()
print(thislist)
#清空列表clear

#您不能通过键入 list2 = list1 来复制列表，
# 因为：list2 将只是对 list1 的引用，
# list1 中所做的更改也将自动在 list2 中进行。
# 解决方法是：
thislist = ["apple", "banana", "cherry"]
mylist = thislist.copy()
print(mylist)
#复制列表copy
thislist = ["apple", "banana", "cherry"]
mylist = list(thislist)
print(mylist)
#将列表转换为列表，达到复制列表的目的

list1 = ["a", "b" , "c"]
list2 = [1, 2, 3]
list3 = list1 + list2
print(list3)
#将两个列表连接起来
list1 = ["a", "b" , "c"]
list2 = [1, 2, 3]
for x in list2:
  list1.append(x)
print(list1)
#将列表2中的值添加到列表1中，另一种方法
list1 = ["a", "b" , "c"]
list2 = [1, 2, 3]
list1.extend(list2)
print(list1)
#使用 extend() 方法将 list2 添加到 list1 的末尾


# append() 	在列表的末尾添加一个元素
# clear() 	删除列表中的所有元素
# copy() 	返回列表的副本
# count() 	返回具有指定值的元素数量。
# extend() 	将列表元素（或任何可迭代的元素）添加到当前列表的末尾
# index() 	返回具有指定值的第一个元素的索引
# insert() 	在指定位置添加元素
# pop() 	删除指定位置的元素
# remove() 	删除具有指定值的项目
# reverse() 颠倒列表的顺序
# sort() 	对列表进行排序
# 列表的方法
