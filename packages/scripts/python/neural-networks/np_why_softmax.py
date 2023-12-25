
import numpy as np
import nnfs

nnfs.init()

layer_outputs = [[4.8, 1.21, 2.385],
                 [8.9, -1.81, 0.2],
                 [1.41, 1.051, 0.026]]

exp_values = np.exp(layer_outputs) # we dont need to do anything to handle the batch, numpy.exp() does this by default

print("exponentiated values: \n", exp_values, "\n")

norm_values = exp_values / np.sum(exp_values, axis=1, keepdims=True)
     
print("normalized exponentiated values: \n", norm_values, "\n")
