f = open("demofile.txt", "r")
print(f.read())
# 如需打开文件，请使用内建的 open() 函数。
# open() 函数返回文件对象，此对象有一个 read() 方法用于读取文件的内容

f = open("demofile.txt", "r")
print(f.readline())
print(f.readline())
# readline() 方法读取文件的一行内容，并返回一个字符串。
# 通过循环遍历文件中的行，您可以逐行读取整个文件
f = open("demofile.txt", "r")
for x in f:
  print(x)
# 遍历所有行

f.close()
# 关闭文件
# 注释：在某些情况下，由于缓冲，在关闭文件之前，对文件所做的更改可能不会显示。
