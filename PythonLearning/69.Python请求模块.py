# #向网页发出请求，并打印响应文本：
import requests
x = requests.get('https://w3school.com.cn/python/demopage.htm')
print(x.text)
#
# 定义和用法
# requests 模块允许您使用 Python 发送 HTTP 请求。
# HTTP 请求返回响应对象，其中包含所有响应数据（内容、编码、状态等）。
# 下载并安装请求模块
# 将命令行导航到 PIP 的位置，然后键入以下内容：
# C:\Users\Your Name\AppData\Local\Programs\Python\Python36-32\Scripts>pip install requests
# requests.methodname(params)
#
# 方法
# delete(url, args) 	        向指定的 URL 发送 DELETE 请求。
# get(url, params, args) 	    向指定的 URL 发送 GET 请求。
# head(url, args) 	            向指定的 URL 发送 HEAD 请求。
# patch(url, data, args) 	    向指定的 URL 发送 PATCH 请求。
# post(url, data, json, args)   向指定的 URL 发送 POST 请求。
# put(url, data, args) 	        向指定的 URL 发送 PUT 请求。
# request(method, url, args) 	将指定方法的请求发送到指定的 URL。