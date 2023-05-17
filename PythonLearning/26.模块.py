# 如果使用模块中的函数时，请使用以下语法：
# module_name.function_name()
# 如果使用模块中的变量时，请使用以下语法：
# module_name.variable_name

# 您可以随意对模块文件命名，但是文件扩展名必须是 .py
# 您可以在导入模块时使用 as 关键字创建别名
# Python 中有几个内建模块，您可以随时导入

import platform
x = dir(platform)
print(x)
# dir() 函数可以列出模块中的所有函数名（或变量名）
# dir() 函数可用于所有模块，也可用于您自己创建的模块。

# 您可以使用 from 关键字选择仅从模块导入部件
# 在使用 from 关键字导入时，请勿在引用模块中的元素时使用模块名称
# 示例：person1["age"]，而不是 mymodule.person1["age"]。

