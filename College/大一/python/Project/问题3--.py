import numpy as np

# 遗传算法参数
population_size = 100
num_generations = 200
elite_size = int(0.1 * population_size)
num_crossover_points = 2
mutation_rate = 0.1

# 初始化种群
population = np.random.uniform(low=-10, high=10, size=(population_size, 2))

# 适应度函数
def fitness(chromosome):
    x, y = chromosome
    return -(x**2 + y**2) + 200  # 修改适应度函数为凹函数

# 轮盘赌选择父代
def select_parent(fitness_values):
    total_fitness = sum(fitness_values)
    pick = np.random.uniform(0, total_fitness)
    current = 0
    for index, fitness_value in enumerate(fitness_values):
        current += fitness_value
        if current > pick:
            return index

# 两点交叉函数
def crossover(parent1, parent2):
    num_points = min(len(parent1) - 1, num_crossover_points)
    points = sorted(np.random.choice(range(1, len(parent1)), num_points, replace=False))
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
        chromosome[mutation_point] += np.random.uniform(-1, 1)
        chromosome[mutation_point] = np.clip(chromosome[mutation_point], -10, 10)  # 确保染色体的值在初始范围内

# 遗传算法主循环
for generation in range(num_generations):
    # 评估适应度
    fitness_values = [fitness(chromo) for chromo in population]

    # 精英策略:选择最佳的染色体
    elite_indices = np.argsort(fitness_values)[-elite_size:]
    new_population = [population[i] for i in elite_indices]

    # 交叉和变异
    while len(new_population) < population_size:
        # 选择父代
        parent1 = select_parent(fitness_values)
        parent2 = select_parent(fitness_values)
        while parent2 == parent1:  # 确保两个父代不同
            parent2 = select_parent(fitness_values)
        # 交叉
        child1, child2 = crossover(population[parent1], population[parent2])

        # 变异
        mutation(child1)
        mutation(child2)

        new_population.append(child1)
        if len(new_population) < population_size:
            new_population.append(child2)

    population = np.array(new_population)

# 在所有代数后，打印最优解
best_solution_index = np.argmax([fitness(chromo) for chromo in population])
best_solution = population[best_solution_index]
best_fitness = fitness(best_solution)
print("Best Solution: ", best_solution)
print("Best Solution Fitness: ", best_fitness)
