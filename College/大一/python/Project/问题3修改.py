import numpy as np

# 参数定义
sea_width = 4 * 1852  # 海域宽度，单位为米
center_depth = 110  # 海域中心的深度，单位为米
transducer_angle = np.radians(120)  # 换能器开角，单位为弧度
slope_angle = np.radians(1.5)  # 坡度，单位为弧度

# 重叠率上下限
overlap_min = 0.1
overlap_max = 0.2

# 计算覆盖宽度的下限和上限
coverage_width_min = 2 * center_depth * np.tan(transducer_angle / 2) - 2 * sea_width / 2 * np.tan(slope_angle) * np.tan(transducer_angle / 2)
coverage_width_max = 2 * center_depth * np.tan(transducer_angle / 2)

# 遗传算法参数
population_size = 100
num_generations = 500
elite_size = 10
mutation_rate = 0.1

# 计算覆盖宽度
def calculate_coverage_width(line):
    depth = center_depth - abs(line - sea_width / 2) * np.tan(slope_angle)
    return 2 * depth * np.tan(transducer_angle / 2)

# 计算覆盖长度
def calculate_coverage_length(chromosome):
    total_coverage_length = 0
    last_line = 0
    for line in chromosome:
        coverage_width = calculate_coverage_width(line)
        if line >= (last_line + coverage_width * (1 - overlap_min)) and line <= (last_line + coverage_width * (1 - overlap_max)):
            total_coverage_length += coverage_width
        else:  # 如果不在有效的覆盖范围内，返回一个非常大的值
            return float('inf')
        last_line = line
    return total_coverage_length

# 初始化种群
def initialize_population():
    population = []
    for _ in range(population_size):
        chromosome = np.random.uniform(sea_width / (coverage_width_max * (1 - overlap_max)), sea_width, population_size)
        population.append(np.sort(chromosome))
    return np.array(population)

# 适应度函数
def fitness(chromosome):
    return 1 / calculate_coverage_length(chromosome)

# 交叉操作
def crossover(parent1, parent2):
    crossover_point = np.random.randint(1, len(parent1) - 1)
    child1 = np.sort(np.concatenate((parent1[:crossover_point], parent2[crossover_point:])))
    child2 = np.sort(np.concatenate((parent2[:crossover_point], parent1[crossover_point:])))
    return child1, child2

# 变异操作
def mutation(chromosome):
    mutation_point = np.random.randint(len(chromosome))
    new_value = chromosome[mutation_point] + np.random.uniform(-0.1, 0.1)
    chromosome[mutation_point] = new_value if new_value >= 0 and new_value <= sea_width else chromosome[mutation_point]
    return np.sort(chromosome)

# 遗传算法
def genetic_algorithm():
    population = initialize_population()
    for _ in range(num_generations):
        population = sorted(population, key=fitness)
        new_population = population[-elite_size:]
        while len(new_population) < population_size:
            parent1, parent2 = population[-2 - np.random.choice(elite_size, 2)]
            child1, child2 = crossover(parent1, parent2)
            new_population.extend((mutation(child1), mutation(child2)))
        population = new_population
    return population[np.argmax([fitness(chromo) for chromo in population])]

best_solution = genetic_algorithm()
print("Best solution: ", best_solution)
