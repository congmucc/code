# 遗传算法完整代码
import numpy as np
import pandas as pd
from scipy.interpolate import griddata
# 数据加载
data = pd.read_excel("C:\\Users\\Administrator\\Desktop\\数学建模\\附件.xlsx", header=None, skiprows=1)

# 获取深度数据
depth = data.iloc[1:, 0].values.astype(float) * 1852  # 转换为浮点数并单位转换为米

# 创建具有相同长度的 x 和 y 数组
x = np.arange(len(depth)) * 1852  # 从0到len(depth)-1，每隔1单位，单位转换为米
y = depth
z = data.iloc[1:,1:].values
# 数据加载



# 确保 x 和 y 具有相同的维度
if x.shape != y.shape:
    x = x.reshape(y.shape)

# 参数定义
width = 4*1852 # 海域宽度，单位为米
length = 5*1852 # 海域长度，单位为米
theta = np.radians(120) # 换能器开角，单位为孤度

d_min, d_max = 2 * np.min(z) * np.tan(theta / 2) * 0.8, 2 * np.max(z) * np.tan(theta / 2) * 1.1
population_size = 100
num_generations = 500
mutation_rate = 0.1
def get_depth_at_point(x_point, y_point):
    """使用线性插值从给定数据点获取深度值"""
    points = np.column_stack((x.ravel(), y.ravel()))
    values = z.ravel()
    return griddata(points, values, (x_point, y_point), method='linear')



def get_dmin_dmax(depth) :
    """根据深度计算最小和最大的测线间距"""
    d_min = 2 * depth * np.tan(theta / 2) * (1 - 0.2)
    d_max = 2 * depth * np.tan(theta / 2) * (1 + 0.2)
    return d_min, d_max
def fitness(chromosome):
    """评估染色体的适应度"""
    total_length = 0
    last_line = 0
    for line in chromosome:
        depth = get_depth_at_point(line, length / 2)
        coverage_width = 2 * depth * np.tan(theta / 2)
        overlap = coverage_width - (line - last_line)
        d_min, d_max = get_dmin_dmax(depth)
        if overlap < d_min or overlap > d_max:
            return 0
        total_length += line - last_line
        last_line = line
    if last_line + coverage_width < width:
        return 0
    return 1 / total_length

def select_parents(population,fitnesses):
    """使用轮盘赌选择法选择两个父代"""
    idx = np.argsort(fitnesses )
    sorted_population = population[idx]
    sorted_fitnesses = np.array(fitnesses)[idx]
    total_fit = np.sum(sorted_fitnesses )
    r1 = np.random.rand() * total_fit
    r2 = np.random.rand() * total_fit
    idx1, idx2 = -1, -1
    for i, f in enumerate(sorted_fitnesses):
        r1 -= f
        if r1 <= 0:
            idx1 = i
        break
    for i, f in enumerate(sorted_fitnesses):
        r2 -= f
        if r2 <= 0:
            idx2 = i
        break
    return sorted_population[idx1], sorted_population[idx2]

def crossover(parent1,parent2):
    """使用单点交叉"""
    idx = np.random.randint(1,len(parent1))
    child1 = np.concatenate((parent1[:idx], parent2[idx:]))
    child2 = np.concatenate((parent2[:idx],parent1[idx:]))
    return child1, child2
def mutate(chromosome) :
    """使用均匀突变"""
    idx = np.random.randint(0,len(chromosome))
    mutation_value = np.random.uniform(-mutation_rate, mutation_rate) * (d_max - d_min)
    chromosome[idx] += mutation_value
def genetic_algorithm():
    d_avg = (d_min + d_max) / 2
    num_lines = int(width / d_avg)
    population =[]
    for _ in range(population_size):
        start = np.random.uniform(0, d_avg)
        chromosome = [start + i * d_avg for i in range(num_lines)]
        population.append(chromosome)
    population = np.array(population)
    for generation in range(num_generations):
        fitness_values = [fitness(chromo) for chromo in population]
        new_population =[]
        for i in range(population_size // 2):
            parent1,parent2 = select_parents(population, fitness_values)
            child1, child2 = crossover(parent1,parent2)
            if np.random.rand() < mutation_rate:
                mutate(child1)
            if np.random.rand() < mutation_rate:
                mutate(child2)
            new_population.extend([child1, child2])
        population = np.array(new_population)
    best_idx = np.argmax(fitness_values)
    return population[best_idx]

print(genetic_algorithm())