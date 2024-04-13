import numpy as np
import math

# 初始化参数
D_center = 110  # 海底深度
alpha = math.radians(1.5)  # 坡度
theta = math.radians(120)  # 开角
width = 4 * 1852  # 区域宽度
d_min = 2 * D_center * math.tan(theta / 2) * 0.10  # 最小测线间距
d_max = 2 * D_center * math.tan(theta / 2) * 0.20  # 最大测线间距
T0 = 1000  # 初始温度
Tend = 1  # 结束温度
q = 0.98  # 冷却系数

# 计算适应度
def fitness(chromosome):
    coverage = 0
    last_line = 0
    for line in chromosome:
        coverage_width = 2 * (D_center + (line - width / 2) * math.tan(alpha)) * math.tan(theta / 2)
        overlap = coverage_width - (line - last_line)
        if overlap < d_min or overlap > d_max:
            return float("-inf")  # 无效的解，返回负无穷
        coverage += coverage_width
        last_line = line
    return coverage

# 生成新的状态
def generate_new_state(chromosome):
    new_chromosome = chromosome.copy()
    i = np.random.randint(len(chromosome))
    new_chromosome[i] += np.random.uniform(-d_max, d_max)
    new_chromosome = np.clip(new_chromosome, d_min, d_max)
    return new_chromosome

# 模拟退火遗传算法
def simulated_annealing_genetic_algorithm():
    d_avg = (d_min + d_max) / 2
    num_lines = int(width / d_avg)
    chromosome = np.array([(i * d_avg) + d_avg / 2 for i in range(num_lines)])
    T = T0
    while T > Tend:
        new_chromosome = generate_new_state(chromosome)
        delta_E = fitness(new_chromosome) - fitness(chromosome)
        if delta_E > 0 or np.random.rand() < np.exp(delta_E / T):
            chromosome = new_chromosome
        T *= q
    return chromosome

best_solution = simulated_annealing_genetic_algorithm()

# 测线的总长度
total_length = len(best_solution) * 2 * 1852  # 2海里转换为米

# 计算重叠率
overlaps = []
for i in range(len(best_solution) - 1):
    line1 = best_solution[i]
    line2 = best_solution[i + 1]
    coverage_width1 = 2 * (D_center + (line1 - width / 2) * math.tan(alpha)) * math.tan(theta / 2)
    coverage_width2 = 2 * (D_center + (line2 - width / 2) * math.tan(alpha)) * math.tan(theta / 2)
    d = line2 - line1
    overlap = 1 - d / min(coverage_width1, coverage_width2)
    overlaps.append(overlap)

# 检查重叠率是否在10%~20%之间
all_in_range = all(0.10 <= overlap <= 0.20 for overlap in overlaps)

print("Total length: ", total_length)
print("All overlaps in range 10%~20%: ", all_in_range)
