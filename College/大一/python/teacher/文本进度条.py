import time
incomplete_num = 50   # .的数量
print('='*23+'开始下载'+'='*25)
for i in range(incomplete_num + 1):
    completed = "*" * i   # 表示已完成
    incomplete = "." * (incomplete_num - i)  # 表示未完成
    percentage = (i / incomplete_num) * 100  # 百分比
    print("\r{:.0f}%[{}{}]".format
          (percentage,completed, incomplete), end="")
    time.sleep(0.5)
print("\n" + '='*23+'下载完成'+'='*25)