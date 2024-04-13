import numpy as np

# 参数定义
sea_width = 4 * 1852  # 海域宽度，单位为米
center_depth = 110  # 海域中心的深度，单位为米
transducer_angle = np.radians(120)  # 换能器开角，单位为弧度
slope_angle = np.radians(1.5)  # 坡度，单位为弧度

# 计算最小和最大的测线间距
overlap_min = 0.1
overlap_max = 0.2
coverage_width_min = 2 * center_depth * np.tan(transducer_angle / 2)
d_min = coverage_width_min * (1 - overlap_max)
d_max = coverage_width_min * (1 - overlap_min)

# 遗传算法参数
population_size = 100
num_generations = 500
elite_size = 10
mutation_rate = 0.1

def calculate_coverage_width(line):
    depth = center_depth + (line - sea_width / 2) * np.tan(slope_angle)
    coverage_width = 2 * depth * np.tan(transducer_angle / 2)
    return coverage_width

def fitness(chromosome):
    total_length = 0
    last_line = 0
    for line in chromosome:
        coverage_width = calculate_coverage_width(line)
        overlap = coverage_width - (line - last_line)
        if overlap < d_min or overlap > d_max:
            return 0  # 无效的解
        total_length += line - last_line
        last_line = line
    # 如果最后一个测线没有覆盖到东端，适应度为0
    if last_line + calculate_coverage_width(last_line) < sea_width:
        return 0
    return total_length

def crossover(parent1, parent2):
    idx = np.random.randint(1, len(parent1) - 1)
    child1 = np.concatenate((parent1[:idx], parent2[idx:]))
    child2 = np.concatenate((parent2[:idx], parent1[idx:]))
    if fitness(child1) > 0 and fitness(child2) > 0:
        return child1, child2
    else:
        return parent1, parent2

def adaptive_mutation(chromosome):
    if np.random.rand() < mutation_rate:
        idx = np.random.randint(0, len(chromosome))
        delta = np.random.uniform(-mutation_rate, mutation_rate) * (d_max - d_min)
        chromosome[idx] += delta
        chromosome[idx] = np.clip(chromosome[idx], 0, sea_width)  # 确保测线位置在海域范围内

def initialize_population():
    d_avg = (d_min + d_max) / 2
    num_lines = int(sea_width / d_avg)
    initial_population = []
    for _ in range(population_size):
        start = np.random.uniform(0, d_avg)
        chromosome = np.sort([start + i * d_avg for i in range(num_lines)])
        initial_population.append(chromosome)
    return np.array(initial_population)

def enhanced_genetic_algorithm():
    population = initialize_population()
    for generation in range(num_generations):
        fitness_values = [fitness(chromo) for chromo in population]
        if np.sum(fitness_values) == 0:
            population = initialize_population()    # 重新初始化种群
            continue
        elite_indices = np.argsort(fitness_values)[-elite_size:]
        new_population = [population[i] for i in elite_indices]
        while len(new_population) < population_size:
            parents = np.random.choice(population_size, size=2, p=np.array(fitness_values)/sum(fitness_values), replace=False)
            child1, child2 = crossover(population[parents[0]], population[parents[1]])
            adaptive_mutation(child1)
            adaptive_mutation(child2)
            new_population.extend([child1, child2])
        population = np.array(new_population)
    return population[np.argmax([fitness(chromo) for chromo in population])]

best_solution = enhanced_genetic_algorithm()
print("Best solution: ", best_solution)

