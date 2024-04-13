import math
import pandas as pd
def calculate depths_coverages_overlaps():
#定义参数
D_center = 120 # 中心点的深度
theta = math.radians(120) #换能器开角转换为弧度
alpha =-math.radians(1.5) #坡度角转换为弧度
distances_from_center = [0,0.3,0.6,0.9,1.2,1.5,1.8,2.1] # 测线距中心点处的距离
betas = [math.radians(beta) for-beta in [0, 45,90,135,180,225,270,315]]# 海底坡面的倾料角度转换为孤度
#根据距中心的距离和海底坡面的倾斜角度计算每个位置的深度、覆盖宽度和与前一条测线的重叠率
results = []
for beta in betas:
depths_list =[]
coverage_widths_list =[]
overlap_percentages_list =[]
for dist in distances_from_center:
#当beta大于90度时，海底坡面的倾斜方向与测线方向相反
if beta >math.pi / 2:
    D= D_center + dist * math.tan(alpha + beta - math.pi)
else:
    D = D_center - dist * math .tan(alpha + beta)
depths list.append(D)
W prime = 2 * D * math.tan(theta / 2)
coverage widths list.append(w prime)
if depths list.index(D) != 0:
previous width = coverage widths list[depths list.index(D) - 1
overlap = 1 - (dist / ((previous width + w prime) / 2))