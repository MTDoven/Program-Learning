# 确保字符串按预期显示，我们可以使用 format() 方法对结果进行格式化。
# format() 方法允许您格式化字符串的选定部分。
# 有时文本的一部分是你无法控制的，也许它们来自数据库或用户输入？
# 要控制此类值，请在文本中添加占位符（花括号 {}），然后通过 format() 方法运行值
price = 52
txt = "The price is {} dollars"
print(txt.format(price))
#添加要显示价格的占位符
txt = "The price is {:.2f} dollars"
print(txt.format(price))
#您可以在花括号内添加参数以指定如何转换值

quantity = 3
itemno = 567
price = 52
myorder = "I want {} pieces of item number {} for {:.2f} dollars."
print(myorder.format(quantity, itemno, price))
#可以添加多个占位符，输入多个值
quantity = 3
itemno = 567
price = 52
myorder = "I want {0} pieces of item number {1} for {2:.2f} dollars."
print(myorder.format(quantity, itemno, price))
#可以指定参数的顺序
age = 63
name = "Bill"
txt = "His name is {1}. {1} is {0} years old."
print(txt.format(age, name))
#使用多个占位符时，可以使用关键字参数来指定名称

myorder = "I have a {carname}, it is a {model_history}."
print(myorder.format(carname = "Porsche", model = "911"))
# 您还可以通过在花括号 {carname} 中输入名称来使用命名索引
# 但是在传递参数值 txt.format(carname = "Ford") 时，必须使用名称
