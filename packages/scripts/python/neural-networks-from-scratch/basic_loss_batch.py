import math


softmax_output = [[0.7, 0.1, 0.2],
                  [0.1, 0.5, 0.4],
                  [0.02, 0.9, 0.08]]
class_targets = [0, 1, 1]

loss = []
for target_index, distribution in zip(class_targets, softmax_output):
        loss.append(-math.log(distribution[target_index]))

average_loss = sum(loss) / len(loss)
print(average_loss)

# there is problem, an infinity problem when the distribution is 0 log(0) = -inf. if we take the mean of the loss, we will get infinity.
# so we have to clip the values to a small number, so we don't get infinity.
# lets say we clip the values to 0.000001
# im not sure if this is the right way to do it, but it works.
loss = []
for target_index, distribution in zip(class_targets, softmax_output):
        loss.append(-math.log(distribution[target_index] + 0.000001))

average_loss = sum(loss) / len(loss)
print(average_loss)
     