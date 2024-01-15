import matplotlib.pyplot as plt
import nnfs
from loss import *

from nnfs.datasets import spiral_data

nnfs.init()

X, y = spiral_data(samples=100, classes=3)

dense1 = Layer_Dense(2, 3)
activation1 = Activation_ReLU()
dense2 = Layer_Dense(3, 3)
activation2 = Activation_Softmax()

loss_function = Loss_CategoricalCrossentropy()

lowest_loss = 9999999
best_dense1_weights = dense1.weights.copy()
best_dense1_biases = dense1.biases.copy()
best_dense2_weights = dense2.weights.copy()
best_dense2_biases = dense2.biases.copy()

def iterate():
    for iteration in range(100000):
        dense1.weights += 0.05 * np.random.randn(2, 3)
        dense1.biases += 0.05 * np.random.randn(1, 3)
        dense2.weights += 0.05 * np.random.randn(3, 3)
        dense2.biases += 0.05 * np.random.randn(1, 3)
        
        dense1.forward(X)
        activation1.forward(dense1.output)
        dense2.forward(activation1.output)
        activation2.forward(dense2.output)
        
        loss = loss_function.calculate(activation2.output, y)
        
        predictions = np.argmax(activation2.output, axis=1)
        accuracy = np.mean(predictions == y)
        
        if loss < lowest_loss:
            print('New set of weights found, iteration:', iteration,
                'loss:', loss, 'acc:', accuracy)
            best_dense1_weights = dense1.weights.copy()
            best_dense1_biases = dense1.biases.copy()
            best_dense2_weights = dense2.weights.copy()
            best_dense2_biases = dense2.biases.copy()
            lowest_loss = loss
        else:
            dense1.weights = best_dense1_weights.copy()
            dense1.biases = best_dense1_biases.copy()
            dense2.weights = best_dense2_weights.copy()
            dense2.biases = best_dense2_biases.copy()
            
def f(x):
    return 2*x**2

x = np.arange(0, 50, 0.001)
y = f(x)

plt.plot(x, y, label='y = f(x)')
colors = ['r', 'g', 'b', 'y', 'm', 'c', 'k', 'w']

def approximate_tangent_line(x, approximate_derivative, b):
    return approximate_derivative * x + b

for i in range(10):
    p2_delta = 0.0001
    x1 = i
    x2 = x1 + p2_delta

    y1 = f(x1)
    y2 = f(x2)

    print((x1, y1), (x2, y2))

    approximate_derivative = (y2 - y1) / (x2 - x1)
    print(approximate_derivative)

    b = y2 - approximate_derivative * x2

    to_plot = [x1 - 10.9, x1, x1 + 10.9]
    random_color = np.random.randint(0, 8)
    plt.scatter(x1, y1, c=colors[random_color])
    plt.plot(to_plot,
            [approximate_tangent_line(point, approximate_derivative, b) for point in to_plot],
            label='Approximate derivative line',
            c=colors[random_color])

    print('Approximate derivative for f(x)',
            f'where x = {x1} is {approximate_derivative}')

plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.grid()
plt.show()