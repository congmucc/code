import numpy as np

# 定义参数
sea_width = 4 * 1852  # 海域宽度，单位为米
center_depth = 110  # 海域中心的深度，单位为米
transducer_angle = np.radians(120)  # 换能器开角，单位为弧度
slope_angle = np.radians(1.5)  # 坡度，单位为弧度

# 计算最小和最大的测线间距
overlap_min = 0.1
overlap_max = 0.2
d_min = 2 * center_depth * np.tan(transducer_angle / 2) * (1 - overlap_max)
d_max = 2 * center_depth * np.tan(transducer_angle / 2) * (1 - overlap_min)

# 遗传算法参数
population_size = 100
num_generations = 500
elite_size = 10
mutation_rate = 0.1


def calculate_coverage_width(line, center_depth, slope_angle, transducer_angle):
    coverage_width = 2 * (center_depth + (line - sea_width / 2) * np.tan(slope_angle)) * np.tan(transducer_angle / 2)
    return coverage_width


def fitness_continuous_coverage(chromosome, sea_width, center_depth, slope_angle, transducer_angle, d_min, d_max):
    total_length = 0
    last_line = 0
    for line in chromosome:
        coverage_width = calculate_coverage_width(line, center_depth, slope_angle, transducer_angle)
        overlap = coverage_width - (line - last_line)
        if overlap < d_min or overlap > d_max:
            return 0  # 无效的解
        total_length += line - last_line
        last_line = line
    # 如果最后一个测线没有覆盖到东端，适应度为0
    if last_line + coverage_width < sea_width:
        return 0
    return total_length


def crossover(parent1, parent2):
    idx = np.random.randint(1, len(parent1) - 1)
    child1 = np.concatenate((parent1[:idx], parent2[idx:]))
    child2 = np.concatenate((parent2[:idx], parent1[idx:]))
    return child1, child2


def adaptive_mutation(chromosome, mutation_rate, d_min, d_max):
    if np.random.rand() < mutation_rate:
        idx = np.random.randint(0, len(chromosome))
        delta = np.random.uniform(-mutation_rate, mutation_rate) * (d_max - d_min)
        chromosome[idx] += delta


def initialize_population(population_size, sea_width, d_min, d_max):
    d_avg = (d_min + d_max) / 2
    num_lines = int(sea_width / d_avg)
    initial_population = []
    for _ in range(population_size):
        start = np.random.uniform(0, d_avg)
        chromosome = [start + i * d_avg for i in range(num_lines)]
        initial_population.append(chromosome)
    return np.array(initial_population)


def enhanced_genetic_algorithm_continuous_coverage():
    population = initialize_population(population_size, sea_width, d_min, d_max)
    for generation in range(num_generations):
        fitness_values = [fitness_continuous_coverage(chromo, sea_width, center_depth, slope_angle, transducer_angle, d_min, d_max) for chromo in population]
        elite_indices = np.argsort(fitness_values)[-elite_size:]
        new_population = [population[i] for i in elite_indices]
        while len(new_population) < population_size:
            parents = np.argsort(fitness_values)[-2:]
            child1, child2 = crossover(population[parents[0]], population[parents[1]])
            new_population.extend([child1, child2])
            for chromo in new_population[-2:]:
                adaptive_mutation(chromo, mutation_rate, d_min, d_max)
        population = np.array(new_population)
    return population[np.argmax([fitness_continuous_coverage(chromo, sea_width, center_depth, slope_angle, transducer_angle, d_min, d_max) for chromo in population])]


best_solution_continuous_coverage = enhanced_genetic_algorithm_continuous_coverage()
print("Best solution: ", best_solution_continuous_coverage)
