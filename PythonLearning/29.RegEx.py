#RegEx 或正则表达式是形成搜索模式的字符序列。
#RegEx 可用于检查字符串是否包含指定的搜索模式。

import re
txt = "China is a great country"
x = re.search("^China.*country$", txt)
print(x)
#检索字符串以查看它是否以 "China" 开头并以 "country" 结尾(存在未知)


# 函数 	    描述
# findall 	返回包含所有匹配项的列表
# search 	如果字符串中的任意位置存在匹配，则返回 Match 对象
# split 	返回在每次匹配时拆分字符串的列表
# sub 	    用字符串替换一个或多个匹配项

# 字符 	描述 	                            示例
# [] 	一组字符 	                        "[a-m]"
# \ 	示意特殊序列（也可用于转义特殊字符） 	"\d"
# . 	任何字符（换行符除外） 	            "he..o"
# ^ 	起始于 	                            "^hello"
# $ 	结束于 	                            "world$"
# * 	零次或多次出现 	                    "aix*"
# + 	一次或多次出现 	                    "aix+"
# {} 	确切地指定的出现次数 	            "al{2}"
# | 	两者任一 	                        "falls|stays"
# () 	捕获和分组

# [arn] 	    返回一个匹配项，其中存在指定字符（a，r 或 n）之一
# [a-n] 	    返回字母顺序 a 和 n 之间的任意小写字符匹配项
# [^arn] 	    返回除 a、r 和 n 之外的任意字符的匹配项
# [0123] 	    返回存在任何指定数字（0、1、2 或 3）的匹配项
# [0-9] 	    返回 0 与 9 之间任意数字的匹配
# [0-5][0-9] 	返回介于 0 到 9 之间的任何数字的匹配项
# [a-zA-Z] 	    返回字母顺序 a 和 z 之间的任何字符的匹配，小写或大写
# [+] 	        在集合中，+、*、.、|、()、$、{} 没有特殊含义，因此 [+] 表示：返回字符串中任何 + 字符的匹配项


import re
str = "China is a great country"
x = re.findall("a", str)
print(x)
#findall函数 #返回包含所有匹配项的列表
import re
str = "China is a great country"
x = re.search("\s", str)
print("The first white-space character is located in position:", x.start())
#在字符串中搜索第一个空白字符
import re
str = "China is a great country"
x = re.split("\s", str)
print(x)
#split函数 #按照特定字符拆分字符串的列表
import re
str = "China is a great country"
x = re.split("\s", str, 2)
print(x)
#仅在前n次出现时拆分字符串
import re
str = "China is a great country"
x = re.sub("\s", "9", str)
print(x)
#用数字 9 替换每个空白字符
import re
str = "China is a great country"
x = re.sub("\s", "9", str, 2)
print(x)
#您可以通过指定 count 参数来控制替换次数


# Match 对象是包含有关搜索和结果信息的对象。
# 注释：如果没有匹配，则返回值 None，而不是 Match 对象。
import re
str = "China is a great country"
x = re.search("a", str)
print(x)
# 将打印一个对象

# Match 对象提供了用于取回有关搜索及结果信息的属性和方法：
#     span() 返回的元组包含了匹配的开始和结束位置
#     .string 返回传入函数的字符串
#     group() 返回匹配的字符串部分

import re
str = "China is a great country"
x = re.search(r"\bC\w+", str)
print(x.span())
#正则表达式查找以大写 "C" 开头的任何单词 #(存在未知)
import re
str = "China is a great country"
x = re.search(r"\bC\w+", str)
print(x.string)
#打印传入函数的字符串

#（存在很多未知）


