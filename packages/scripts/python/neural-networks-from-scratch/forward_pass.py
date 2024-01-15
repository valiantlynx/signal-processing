import numpy as np

np.random.seed(0)

# this will serve as our sample data
X = [[1, 2, 3, 2.5],
     [2.0, 5.0, -1.0, 2.0],
     [-1.5, 2.7, 3.3, -0.8]]

class Layer_Dense:
     def __init__(self, n_inputs, n_neurons) -> None:
          self.weights = 0.10 * np.random.randn(n_inputs, n_neurons)
          self.biases = np.zeros((1, n_neurons))
     
     def forward(self, inputs):
          self.output = np.dot(inputs, self.weights) + self.biases
          
          
     
layer1 = Layer_Dense(4, 5)
layer2 = Layer_Dense(5, 2)
layer3 = Layer_Dense(2, 3)
layer4 = Layer_Dense(3, 2)

layer1.forward(X)
print(layer1.output)
layer2.forward(layer1.output)
print(layer2.output)
layer3.forward(layer2.output)
print(layer3.output)
layer4.forward(layer3.output)
print(layer4.output)
