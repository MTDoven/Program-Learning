# 如需写入已有的文件，必须向 open() 函数添加参数：
#     "a" - 追加 - 会追加到文件的末尾
#     "w" - 写入 - 会覆盖任何已有的内容

f = open("demofile2.txt", "a")
f.write("Now the file has more content!")
f.close()
# 打开文件 "demofile2.txt" 并将内容追加到文件中
f = open("demofile3.txt", "w")
f.write("Woops! I have deleted the content!")
f.close()
# 打开文件 "demofile3.txt" 并将内容覆盖文件中的内容

# 如需在 Python 中创建新文件，请使用 open() 方法，并使用以下参数之一：
#     "x" - 创建 - 将创建一个文件，如果文件存在则返回错误
#     "a" - 追加 - 如果指定的文件不存在，将创建一个文件
#     "w" - 写入 - 如果指定的文件不存在，将创建一个文件

