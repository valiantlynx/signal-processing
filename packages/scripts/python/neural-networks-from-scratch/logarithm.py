'''
solving for x

e**x = 5
'''

import numpy as np
import math

E = math.e

b = 5.2
x = np.log(b)
print(x)

print(f"{b} = {round(E**x, 1)}")