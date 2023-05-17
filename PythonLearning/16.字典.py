thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
print(thisdict)
#创建字典
x = thisdict["model_history"]
#访问字典中的值
print(thisdict.get("model_history"))
#访问不存在的键，返回None

thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
thisdict["year"] = 2019
#修改字典中的值
for x in thisdict:
  print(x)
#遍历字典中的键
for x in thisdict:
  print(thisdict[x])
#遍历字典中的值
for x in thisdict.values():
  print(x)
#遍历字典中的值
for x, y in thisdict.items():
  print(x, y)
#遍历字典中的键值对
thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
if "model_history" in thisdict:
  print("Yes, 'model_history' is one of the keys in the thisdict dictionary")
#判断字典中是否存在某个键

thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
thisdict["color"] = "red"
print(thisdict)
#添加字典中的键值对
thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
thisdict.pop("model_history")
print(thisdict)
#删除字典中的键值对
#popitem() 方法删除最后插入的项目（在 3.7 之前的版本中，删除随机项目）
thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
del thisdict["model_history"]
print(thisdict)
#删除字典中的键值对

#您不能通过键入 dict2 = dict1 来复制字典，因为：dict2 只是对 dict1 的引用，而 dict1 中的更改也将自动在 dict2 中进行。
#解决方法
thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
mydict = thisdict.copy()
print(mydict)
#复制字典
thisdict =	{
  "brand": "Porsche",
  "model_history": "911",
  "year": 1963 }
mydict = dict(thisdict)
print(mydict)
#复制字典
#字典可以嵌套

thisdict = dict(brand="Porsche", model="911", year=1963)
print(thisdict)
# 请注意，关键字不是字符串字面量
# 请注意，使用了等号而不是冒号来赋值

# clear() 	  删除字典中的所有元素
# copy() 	  返回字典的副本
# fromkeys()  返回拥有指定键和值的字典
# get() 	  返回指定键的值
# items() 	  返回包含每个键值对的元组的列表
# keys() 	  返回包含字典键的列表
# pop() 	  删除拥有指定键的元素
# popitem()   删除最后插入的键值对
# setdefault()返回指定键的值。如果该键不存在，则插入具有指定值的键。
# update() 	  使用指定的键值对字典进行更新
# values() 	  返回字典中所有值的列表
#字典方法

