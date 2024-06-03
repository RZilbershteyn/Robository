import numpy as np
from pandas import DataFrame

constraint = 50
data = []

for i in range(int(1e3)):
    flag = 1
    delta = 0
    t = 0
    while flag:
        t += 1
        a = np.random.randint(1, 11)
        b = np.random.randint(1, 11)
        delta += a - b
        if (abs(delta)) >= constraint:
            data.append(t)
            break
        
data = DataFrame(data)
print(data.mean(axis=1))
print(data.median(axis=1))
print(data.describe())