from scipy import optimize
import numpy as np

c = np.array([2, 3, -5])
A = np.array([[-2, 5, -1], [1, 3, 1]])
B = np.array([-10, 12])
Aed = np.array([[1, 1, 1]])
Bed = np.array([7])

res = optimize.linprog(-c, A, B, Aed, Bed)

print(res)