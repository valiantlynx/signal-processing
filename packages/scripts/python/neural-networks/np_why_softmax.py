import math 
import numpy as np
import nnfs

nnfs.init()

layer_outputs = [4.8, 1.21, 2.385]

# E = 2.71828182846
E = math.e

exp_values = np.exp(layer_outputs)
    
print("exponentiated values: \n", exp_values, "\n")

norm_values = exp_values / np.sum(exp_values)
     
print("normalized exponentiated values: \n", norm_values, "\n")
