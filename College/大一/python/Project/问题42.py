# 导入必要的库
import numpy as np
import pandas as pd
#重新导入数据
data_path = '附件修改.xlsx'
data = pd.read_excel(data_path, header=None)
# 获取横纵坐标T
x_coords = data.iloc[0,1:].values
y_coords = data.iloc[1:,].values
# 获取深度数据
depth_data = data.iloc[1:,1:]
# 创建新的数据集，包含x，y和深度
new_data = []
for i, y in enumerate(y_coords):
    for j, x in enumerate(x_coords):
        new_data.append([x, y, depth_data.iloc[i,j]])

#创建新的DataFrame
new_df = pd.DataFrame(new_data, columns=['x','y','depth'])
# 参数初始化
width = 4*1852 # 海域宽度，单位为米
length = 5 *1852 # 海域长度，单位为米
theta = np.radialhs(120) # 换能器开角，单位为弧度
# 遗传算法参数
population_size = 100
num_generations = 100
elite_size = 10
mutation_rate = 0.1
crossover_rate = 0.8

#最小和最大的测线间距，根据平均海深计算
avg_depth = np.mean(new_df['depth'].values)
d_min = 2 *avg_depth * np.tan(theta / 2) * (1 - 0.2)
d_max = 2 * avg_depth * np.tan(theta / 2) * (1 + 0.2) #允许稍微超过20%以提供更多的灵活性
d_min, d_max