#Python 中的日期不是其自身的数据类型，但是我们可以导入名为 datetime 的模块，把日期视作日期对象进行处理。

import datetime
x = datetime.datetime.now()
print(x)
#导入 datetime 模块并显示当前日期
import datetime
x = datetime.datetime.now()
print(x.year)
print(x.strftime("%A"))
#导入 datetime 模块并显示当前日期的年份和星期

#如需创建日期，我们可以使用 datetime 模块的 datetime() 类（构造函数）。
#datetime() 类需要三个参数来创建日期：年、月、日。
import datetime
x = datetime.datetime(2020, 5, 17)
print(x)
#创建日期 2020-05-17对象


#strftime() 方法可以把datetime 对象拥有把日期对象格式化为可读字符串的方法。
#该方法称为 strftime()，并使用一个 format 参数来指定返回字符串的格式：
import datetime
x = datetime.datetime(2019, 10, 1)
print(x.strftime("%B"))

'''''
%a 	Weekday，短版本 	Wed
%A 	Weekday，完整版本 	Wednesday
%w 	Weekday，数字 0-6 	3
%d 	日，数字 01-31 	    31
%b 	月名称，短版本 	    Dec
%B 	月名称，完整版本 	December
%m 	月，数字01-12 	    12
%y 	年，短版本，无世纪 	18
%Y 	年，完整版本 	    2018
%H 	小时，00-23 	    17
%I 	小时，00-12 	    05
%p 	AM/PM 	            PM
%M 	分，00-59 	        41
%S 	秒，00-59 	        08
%f 	微妙，000000-999999 548513
%z 	UTC 偏移 	        +0100
%Z 	时区 	            CST
%j 	天数，001-366 	    365
%c 	日期时间的本地版本 	Mon Dec 31 17:41:00 2018
%x 	日期的本地版本 	    12/31/18
%X 	时间的本地版本 	    17:41:00
%% 	A % character 	    %
'''''
