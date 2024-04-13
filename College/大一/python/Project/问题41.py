import numpy as np
# 参数初始化
width = 4*1852
# 海域宽度，单位为米
length = 5*1852 # 海域长度，单位为米
theta = np.radians(12) # 换能器开角，单位为弧度
# 遗传算法参数
population_size = 100
num_generations = 100
elite_size = 10
mutation_rate = 0.1
crossover_rate = .8
#最小和最大的测线间距，根据平均海深计算
avg_depth = np.mean(new_df['depth'].values)
d_min = 2 * avg_depth * np.tan(theta / 2) * (1 - 0.2)
d_max = 2 *avg_depth * np.tan(theta / 2) * (1 +0.2)
#允许稍微超过20%以提供更多的灵活性
d_min, d_max