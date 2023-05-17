import os
os.remove("demofile.txt")
#删除文件 "demofile.txt"
import os
if os.path.exists("demofile.txt"):
  os.remove("demofile.txt")
else:
  print("The file does not exist")
# 为避免出现错误，您可能需要在尝试删除文件之前检查该文件是否存在

import os
os.rmdir("myfolder")
#如需删除整个文件夹，请使用 os.rmdir() 方法
# 您只能删除空文件夹。如果文件夹不为空，则会返回错误。