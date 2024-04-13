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
    coverage = 0
    last_line = 0
    for line in chromosome:
        coverage_width= 2 * (D_center + (line - width/2) * math.tan(alpha)) * math.tan(theta/2)
        overlap = coverage_width - (line - last_line)
        if overlap < d_min or overlap > d_max:
            return 0 #无效的解
        coverage += coverage_width
        last_line = line
    return coverage

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
    fitness_values = np.maximum(fitness_values, 0)
    sum_fitness = np.sum(fitness_values)
    if sum_fitness > 0:
        probability = fitness_values / sum_fitness
    else:
        probability = np.ones(len(population)) / len(population)
    indices = np.random.choice(len(population), size=selection_size, p=probability)
    return population[indices]

# 增强版遗传算法
def enhanced_genetic_algorithm():
    # 初始化种群
    population = np.random.uniform(low=d_min, high=d_max, size=(population_size, int(width/d_min)))
    #遗传算法主循环
    for generation in range(num_generations):
        # 评估适应度
        fitness_values = [fitness(chromo) for chromo in population]
        # 精英策略:选择佳的染色体
        elite_indices = np.argsort(fitness_values)[-elite_size:]
        new_population = [population[i] for i in elite_indices]
        #交叉和变异
        while len(new_population) < population_size:
            #选择父代
            parents = selection(population, fitness_values)
            #交叉
            for i in range(0, len(parents), 2):
                if i+1 < len(parents):
                    child1, child2 = crossover(parents[i], parents[i+1])
                    new_population.extend([child1, child2])
                    #变异
                    for chromo in new_population[-2:]:
                        mutation(chromo)
        population = np.array(new_population)
    return population[np.argmax([fitness(chromo) for chromo in population])]

best_solution_with_comments = enhanced_genetic_algorithm()
print("Best solution: ", best_solution_with_comments)


# 代码中的各个部分的解释如下：
#
# 参数定义：这部分定义了问题的一些参数，包括海域的深度、坡度、换能器的开角等。
#
# 适应度函数：这个函数用于评估某个解（即某个测量线的配置）的质量。它首先计算出每一条测量线的覆盖宽度，然后检查相邻的两条线之间的重叠率是否在10%~20%之间。如果不在这个范围内，那么这个解就被认为是无效的，适应度为0。如果在这个范围内，那么它的适应度就是所有测量线的覆盖宽度之和，这表示它覆盖的海域的面积。
#
# 多点交叉函数：这个函数用于生成新的解。它首先随机选择两个解，然后在这两个解之间进行交叉操作，生成两个新的解。
#
# 自适应变异函数：这个函数用于对解进行变异操作，以增加解的多样性。它首先根据解的适应度来确定变异率，如果适应度较低，那么变异率就较高，反之亦然。然后，它以这个变异率进行变异操作。
#
# 增强版遗传算法：这是遗传算法的主循环。它首先初始化一个随机的种群，然后在每一代中，它都会评估种群中每个解的适应度，选择适应度最高的一部分解作为精英，然后通过交叉和变异操作生成新的解，最后更新种群。这个过程重复多次，直到达到预定的代数。
#
# 根据你的代码，我认为可能需要改进的地方是：
#
# 在初始化种群时，你使用了一个均匀分布，但是这可能并不是最好的选择。可能有一些更复杂的分布（比如正态分布或者指数分布）能够更好地初始化种群。
#
# 在选择父代进行交叉操作时，你总是选择适应度最高的两个解。这可能会导致种群的多样性减少，因此可能会考虑使用轮盘赌选择或者锦标赛选择等其他的选择策略。
#
# 在自适应变异函数中，你只是简单地增加了适应度较低的解的变异率，这可能并不是最好的策略。可能有一些更复杂的策略（比如模拟退火或者遗传算法中的温度调度策略）能够更好地调整变异率。
#
# 总的来说，虽然你的代码已经能够解决问题，但是还有一些可能的改进空间。


# 在这个改进的版本中，我做了以下几个主要的修改：
#
# 在选择父代进行交叉操作时，使用了轮盘赌选择法，而不是简单地选择适应度最高的两个解This is a Python script that employs a genetic algorithm approach to solve for optimal survey lines in a sonar survey.
# The genetic algorithm works broadly in the following steps:
#
# Initialization: Create an initial population of survey lines, represented as a list of distances.
# Fitness calculation: Evaluate the fitness of each individual in the population. Here, the fitness is the total coverage of the survey area, subject to the constraint that the overlap between two lines must be between 10% and 20%.
# Selection: Select a subset of the population to reproduce. This uses "roulette wheel selection", where individuals are selected with a probability proportional to their fitness.
# Crossover: Pairs of individuals are selected to produce two offspring by swapping segments of their lines. This is done with "multi-point crossover", where several points are chosen in the line, and segments between these points are swapped.
# Mutation: With a certain probability, a random change is made to an individual. If mutation occurs, a random point in the line is chosen and a small random value is added or subtracted.
# Elite Strategy: The best individuals (elites) from the population are always copied into the next generation to ensure that the best solution found so far is not lost.
# Iteration: Steps 2-6 are repeated for a certain number of generations, or until a satisfactory solution is found.
# Result: The best individual from the final population is returned as the solution.
# The proposed parameters for the genetic algorithm are:
#
# Population size: 100
# Number of generations: 200
# Elite size: 10% of the population
# Number of crossover points: 2
# Mutation rate: 0.1
# Selection size: 50% of the population
# This script is a good starting point, but the performance of a genetic algorithm can be sensitive to the choice of parameters and operators, so it may need to be tuned for this specific problem. Additionally, as a heuristic algorithm, it may not always find the best possible solution, but it can often find a good solution in a reasonable amount of time.

# 这个输出结果是一组浮点数，代表了在海洋声纳测量中的最优测量线路。每个数字代表一条测量线的位置。这些测量线的位置是由遗传算法优化得出的，目标是在满足一定的重叠率约束（10%-20%）的情况下，实现对整个测量区域的最大覆盖。
#
# 具体来说，这个数组中的每个数字代表了一条测量线距离测量区域西侧的距离。例如，第一个数字是58.57465304，这表示第一条测量线距离测量区域西侧的距离是58.57465304米。
#
# 这个解决方案是通过遗传算法得出的，这是一种启发式优化算法，用于在大规模搜索空间中找到最优解。遗传算法通过模拟自然选择过程中的进化机制（如遗传、突变、选择和交叉）来生成新的解决方案。
#
# 这个算法的主要步骤包括：
#
# 初始化：创建一个初始的解决方案群体（在这个问题中，每个解决方案是一组测量线的位置）。
# 适应度计算：对每个解决方案进行评估，计算其适应度值（在这个问题中，适应度值是测量区域的覆盖率，同时要满足测量线之间的重叠率在10%-20%之间）。
# 选择：根据适应度值选择一部分解决方案进行繁殖（在这个算法中，使用了轮盘赌选择法，即适应度高的解决方案有更高的被选择概率）。
# 交叉：从选出的解决方案中随机选择两个，通过交换它们的部分数据来生成两个新的解决方案。
# 突变：以一定的概率对新生成的解决方案进行小的随机改变。
# 精英策略：总是将当前群体中适应度最高的一部分解决方案复制到下一代群体中，以保证最优解不会丢失。
# 迭代：重复上述步骤，直到达到预设的迭代次数，或者找到满意的解决方案。
# 通过这个过程，遗传算法在每一代都会生成一些新的解决方案，并通过自然选择的方式，逐渐改进解决方案的质量，最终找到一个最优解或者近似最优解