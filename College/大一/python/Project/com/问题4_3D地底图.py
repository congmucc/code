import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

from pylab import mpl

# 设置中文显示字体
mpl.rcParams["font.sans-serif"] = ["SimHei"]
# 设置正常显示符号
mpl.rcParams["axes.unicode_minus"] = False

# 读取Excel文件
df = pd.read_excel("C:\\Users\\Administrator\\Desktop\\数学建模\\CUMCM2023Problems\\B题\\附件.xlsx", engine='openpyxl')

# 创建一个新的图形
fig = plt.figure()

# 添加一个三维子图
ax = fig.add_subplot(111, projection='3d')

# 提取X, Y, Z数据
X = df.columns[1:].astype(float)  # 横向坐标/NM（由西向东）
Y = df.iloc[:, 0].values.astype(float)  # 纵向坐标/NM（由南向北）
X, Y = np.meshgrid(X, Y)
Z = -df.iloc[:, 1:].values  # 海水深度/m
# 创建一个三维表面图
ax.plot_surface(X, Y, Z, cmap='viridis')

# 设置坐标轴标签
ax.set_xlabel('横向坐标/NM（由西向东）(X)')
ax.set_ylabel('纵向坐标/NM（由南向北）(Y)')
ax.set_zlabel('海水深度/m(-Z)')

# 显示图形
plt.show()
