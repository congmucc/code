import math
import numpy as np

# 参数定义
D_center = 110 # 中心深度
alpha = math.radians(1.5)  # 坡度角度
theta = math.radians(120)  # 换能器开角
width = 4 *1852 # 东-西宽度(单位:米)
d_min = 2* D_center * math.tan(theta/2) * 0.10 # 基于10%重叠率的两条线之间的最小距离
d_max = 2 * D_center * math.tan(theta/2) *0.2 # 基于20%重叠率的两条线之间的最大距离

#遗传算法参数
population_size = 100
num_generations = 200
elite_size = int(0.1 * population_size)
num_crossover_points = 2
mutation_rate = 0.1
selection_size = int(0.5 * population_size)


# 适应度函数
def fitness(chromosome):
    chromosome = np.array(chromosome) # 将chromosome转为numpy数组
    sorted_chromosome = np.sort(chromosome)  # 将测线按照位置排序
    last_line = np.insert(sorted_chromosome[:-1], 0, 0)
    coverage_width= 2 * (D_center + (sorted_chromosome - width/2) * np.tan(alpha)) * np.tan(theta/2)
    overlap = coverage_width - (sorted_chromosome - last_line)
    penalty = np.sum(np.where(overlap < d_min, abs(overlap - d_min), np.where(overlap > d_max, abs(overlap - d_max), 0)))
    coverage = np.sum(coverage_width)
    return coverage - penalty

#多点交叉函数
def crossover(parent1, parent2):
    points = sorted(np.random.choice(range(1, len(parent1)), num_crossover_points, replace=False))
    child1, child2 = parent1.copy(), parent2.copy()
    for i in range(len(points) + 1):
        start = points[i-1] if i != 0 else 0
        end = points[i] if i < len(points) else len(parent1)
        if i % 2 == 0:
            child1[start : end], child2[start : end] = parent2[start : end], parent1[start : end]
    return child1, child2

# 变异函数
def mutation(chromosome):
    if np.random.rand() < mutation_rate:
        mutation_point = np.random.randint(len(chromosome))
        chromosome[mutation_point] += np.random.uniform(-d_min/10, d_min/10)

#选择函数（轮盘赌选择法）
def selection(population, fitness_values):
    total_fitness = np.sum(fitness_values)
    relative_fitness = [f/total_fitness for f in fitness_values]
    indices = np.random.choice(np.arange(len(population)), size=selection_size, p=relative_fitness)
    return [population[i] for i in indices]

# 增强版遗传算法
def enhanced_genetic_algorithm():
    # 初始化种群
    population = np.random.uniform(low=d_min, high=width, size=(population_size, int(width / d_min)))

    # 遗传算法主循环
    for generation in range(num_generations):
        # 评估适应度
        fitness_values = [fitness(chromo) for chromo in population]

        # 选择适应度最高的染色体
        sorted_pop_indices = np.argsort(fitness_values)[-elite_size:]
        sorted_population = [population[i] for i in sorted_pop_indices]

        # Note: 我们在这里计算适应度
        sorted_fitness_values = [fitness_values[i] for i in sorted_pop_indices]

        new_population = sorted_population[:elite_size]

        # 交叉和变异
        while len(new_population) < population_size:
            # 选择父代
            parents = selection(sorted_population, sorted_fitness_values)
            # 交叉
            for i in range(0, len(parents), 2):
                if i + 1 < len(parents):
                    child1, child2 = crossover(parents[i], parents[i + 1])
                    new_population.extend([child1, child2])
                    # 变异
                    for chromo in new_population[-2:]:
                        mutation(chromo)

        population = np.array(new_population)

    return population[np.argmax([fitness(chromo) for chromo in population])]


best_solution_with_comments = enhanced_genetic_algorithm()
print("Best solution: ", best_solution_with_comments)
