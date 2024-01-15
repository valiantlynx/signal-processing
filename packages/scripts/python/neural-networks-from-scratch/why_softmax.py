import math 

layer_outputs = [4.8, 1.21, 2.385]

# E = 2.71828182846
E = math.e

exp_values = []

for output in layer_outputs:
     exp_values.append(E ** output)
    
print("exponentiated values: \n", exp_values, "\n")

norm_base = sum(exp_values)
norm_values = []

for value in exp_values:
     norm_values.append(value / norm_base)
     
print("normalized exponentiated values: \n", norm_values, "\n")
