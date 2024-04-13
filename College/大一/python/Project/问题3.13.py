import numpy as np

# 定义参数
width = 4*1852 # 海域宽度，单位为米
D_center = 110 # 海域中心的深度，单位为米
theta = np.radians(120) # 换能器开角，单位为弧度
alpha = np.radians(1.5) # 坡度，单位为弧度

#根据给定的重叠率计算最小和最大的测线间距
d_min = 2 * D_center * np.tan(theta / 2) * (1 - 0.2)
d_max = 2 * D_center * np.tan(theta / 2) * (1 - 0.1)
# 模拟退火算法参数
T0 = 1000 # 初始温度
Tend = 1e-3 # 结束温度
q = 0.98 # 降温系数

# 能量函数 (适应度函数)
def energy(chromosome):
    total_length = 0
    last_line = 0
    for line in chromosome:
        coverage_width = 2 * (D_center + line * np.tan(alpha/2)) * np.tan(theta / 2)
        overlap = coverage_width - (line - last_line)
        # 避免重叠率超出范围
        if overlap < d_min or overlap > d_max:
            return np.inf
        total_length += np.sqrt((line - last_line) ** 2 + (D_center + line * np.tan(alpha / 2)) ** 2)
        last_line = line
    return total_length

# 随机生成新的解
def generate_new_state(chromosome):
    idx = np.random.randint(0, len(chromosome))
    delta = np.random.uniform(-1, 1) * (d_max - d_min)
    new_chromosome = chromosome.copy()
    new_chromosome[idx] += delta
    # 保证新的解在指定范围内
    new_chromosome = np.clip(new_chromosome, 0, width)
    return new_chromosome

# 模拟退火算法
def simulated_annealing():
    # 初始化
    d_avg = (d_min + d_max) / 2
    num_lines = int(width / d_avg)
    # 修改这里，使得第一个测线从其中心开始
    chromosome = np.array([(i * d_avg) + d_avg / 2 for i in range(num_lines)])
    T = T0
    while T > Tend:
        new_chromosome = generate_new_state(chromosome)
        delta_E = energy(new_chromosome) - energy(chromosome)
        # 如果能量降低，则直接接受；否则，根据 Boltzmann分布决定是否接受
        if delta_E < 0 or np.random.rand() < np.exp(-delta_E / T):
            chromosome = new_chromosome
        T *= q
    return chromosome

best_solution = simulated_annealing()
print("Best solution: ", best_solution)
