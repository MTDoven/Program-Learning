import json
x =  '{ "name":"Bill", "age":63, "city":"Seatle"}'# 一些 JSON:
y = json.loads(x)# 解析 x
print(y["age"])# 结果是 Python 字典
#把 JSON 转换为 Python

import json
x = {"name": "Bill",
  "age": 63,
  "city": "Seatle"} # Python 对象（字典）
y = json.dumps(x)# 转换为 JSON
print(y)# 结果是 JSON 字符串
#把 Python 转换为 JSON

import json
print(json.dumps({"name": "Bill", "age": 63}))
print(json.dumps(["apple", "bananas"]))
print(json.dumps(("apple", "bananas")))
print(json.dumps("hello"))
print(json.dumps(42))
print(json.dumps(31.76))
print(json.dumps(True))
print(json.dumps(False))
print(json.dumps(None))
#把各种类型转换为 JSON 字符串
#当 Python 转换为 JSON 时，Python 对象会被转换为 JSON（JavaScript）等效项
# 详情见：https://www.runoob.com/python/python-json.html


# 使用 indent 参数定义缩进数
# 使用 separators 参数来更改默认分隔符
# 使用 sort_keys 参数来指定是否应对结果进行排序
y = json.dumps(x, indent=4, sort_keys=True, separators=(". ", " = "))
print(y)
#(存在未知)详情见：https://www.w3school.com.cn/python/python_json.asp
