import numpy as np
import pandas as pd
from scipy.optimize import minimize

# 海域参数定义
sea_width = 4 * 1852  # 海域宽度，单位为米
sea_length = 2 * 1852  # 海域长度，单位为米
center_depth = 110  # 海域中心的深度，单位为米
slope_angle = np.radians(1.5)  # 坡度，单位为弧度
transducer_angle = np.radians(120)  # 换能器开角，单位为弧度


# 计算覆盖宽度
def calculate_coverage_width(depth):
    return 2 * depth * np.tan(transducer_angle / 2)


# 定义适应度函数
def fitness_function(lines):
    total_length = 0
    uncovered_area = 0
    overlap_area = 0
    last_line = 0

    for line in lines:
        # 计算海底深度
        depth = center_depth + (line - sea_length / 2) * np.tan(slope_angle)
        coverage_width = calculate_coverage_width(depth)

        # 计算覆盖区域
        if line - last_line < coverage_width:
            overlap = coverage_width - (line - last_line)
            overlap_area += overlap * sea_width
        else:
            uncovered_area += coverage_width * sea_width

        total_length += line - last_line
        last_line = line

    # 计算未覆盖海区百分比
    uncovered_percentage = (uncovered_area / (sea_width * sea_length)) * 100

    # 计算重叠率超过20%的部分长度
    overlap_percentage = (overlap_area / (sea_width * sea_length)) * 100
    if overlap_percentage > 20:
        overlap_length = (overlap_percentage - 20) * (sea_width * sea_length) / 100
    else:
        overlap_length = 0

    return total_length, uncovered_percentage, overlap_length


# 遗传算法参数
population_size = 100
num_generations = 500
elite_size = 10
mutation_rate = 0.1


# 定义遗传算法
def genetic_algorithm():
    initial_population = np.sort(np.random.uniform(0, sea_length, population_size))

    def objective_function(lines):
        total_length, uncovered_percentage, overlap_length = fitness_function(lines)
        return total_length + uncovered_percentage + overlap_length

    best_solution = minimize(objective_function, initial_population, method='SLSQP',
                             bounds=[(0, sea_length)] * population_size,
                             options={'maxiter': num_generations})

    return best_solution.x


# 运行遗传算法
best_solution = genetic_algorithm()
best_length, best_uncovered_percentage, best_overlap_length = fitness_function(best_solution)

print("最优解的测线位置：", np.round(best_solution, 2))
print("测线的总长度：", np.round(best_length, 2))
print("漏测海区占总待测海域面积的百分比：", np.round(best_uncovered_percentage, 2), "%")
print("在重叠区域中，重叠率超过 20% 部分的总长度：", np.round(best_overlap_length, 2))
