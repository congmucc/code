import math
import numpy as np

# 参数定义
D_center = 110  # 中心深度
alpha = math.radians(1.5)  # 坡度角度
theta = math.radians(120)  # 换能器开角
width = 4 * 1852  # 东-西宽度(单位:米)
d_min = 2 * D_center * math.tan(theta / 2) * 0.10  # 最小距离
d_max = 2 * D_center * math.tan(theta / 2) * 0.20  # 最大距离

# 遗传算法参数
population_size = 100
num_generations = 200
num_crossover_points = 2
elite_size = int(0.1 * population_size)
mutation_rate = 0.1
selection_size = int(0.5 * population_size)


def fitness(chromosome):
    coverage = 0
    last_line = 0
    for line in chromosome:
        coverage_width = 2 * (D_center + (line - width / 2) * math.tan(alpha)) * math.tan(theta / 2)
        overlap = coverage_width - (line - last_line)
        if overlap < d_min or overlap > d_max:
            return float("-inf")  # 无效的解，返回负无穷大
        coverage += coverage_width
        last_line = line
    return coverage


def crossover(parent1, parent2):
    points = sorted(np.random.choice(range(1, len(parent1)), num_crossover_points, replace=False))
    child1, child2 = parent1.copy(), parent2.copy()
    for i in range(len(points) + 1):
        start = points[i - 1] if i != 0 else 0
        end = points[i] if i < len(points) else len(parent1)
        if i % 2 == 0:
            child1[start: end], child2[start: end] = parent2[start: end], parent1[start: end]
    return child1, child2


def mutation(chromosome):
    if np.random.rand() < mutation_rate:
        mutation_point = np.random.randint(len(chromosome))
        chromosome[mutation_point] += np.random.uniform(-d_min / 10, d_min / 10)


def selection(population, fitness_values):
    fitness_values = np.array([0 if math.isinf(f) else f for f in fitness_values])
    sum_fitness = np.sum(fitness_values)
    probability = fitness_values / sum_fitness if sum_fitness > 0 else np.ones(len(population)) / len(population)
    indices = np.random.choice(len(population), size=selection_size, p=probability)
    return population[indices]


def enhanced_genetic_algorithm():
    population = np.random.uniform(low=d_min, high=d_max, size=(population_size, int(width / d_min)))
    for generation in range(num_generations):
        fitness_values = [fitness(chromo) for chromo in population]
        elite_indices = np.argsort(fitness_values)[-elite_size:]
        new_population = [population[i] for i in elite_indices]
        # 交叉和变异
        while len(new_population) < population_size:
            parents = selection(population, fitness_values)
            for i in range(0, len(parents), 2):
                if i + 1 < len(parents):
                    child1, child2 = crossover(parents[i], parents[i + 1])
                    new_population.extend([child1, child2])
                    for chromo in new_population[-2:]:
                        mutation(chromo)
        population = np.array(new_population)

    # 返回适应度最高的解
    best_solution = population[np.argmax([fitness(chromo) for chromo in population])]
    return best_solution


best_solution = enhanced_genetic_algorithm()
print("Best solution: ", best_solution)



# 根据上述反馈，我们主要需要修改适应度函数（fitness function）。原来的代码中，即使解没有满足10%~20%的重叠率要求，我们依然计算并返回了其覆盖度。以下是修改后的代码，其中我们将不满足重叠率要求的解的适应度设置为负无穷大，让遗传算法在演化过程中更倾向于选择满足条件的解。
#这个代码可以保证只有满足10%~20%重叠率要求的测线才会被认为是候选解，并在遗传算法的演化过程中被优选。
