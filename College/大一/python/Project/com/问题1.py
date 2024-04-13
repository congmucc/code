import numpy as np
r = 1.5
center_depth = 70  # 海域中心的深度，单位为米
transducer_angle = np.radians(120)  # 换能器开角，单位为弧度
slope_angle = np.radians(1.5)  # 坡度，单位为弧度
D=lambda x : (center_depth-x * np.tan(slope_angle))
W=lambda x : (center_depth-x * np.tan(slope_angle)) * (np.sin(transducer_angle/2)/np.sin(np.radians(90) + slope_angle -transducer_angle/2) + np.sin(transducer_angle/2)/np.sin( np.radians(90) - slope_angle -transducer_angle/2)) * np.cos(slope_angle)
T= lambda d: d*(np.sin(np.radians(90) + transducer_angle/2)/np.sin(np.radians(90) - slope_angle -transducer_angle/2))*np.cos(slope_angle)
x = np.arange(-800,1000,200)
print(x)
print(D(x))
print(W(x))
a= W(x)-T(200)
print(a[:-1]/W(x)[1:])