#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// nn that can learn the XOR function
// sum of inputs * weights + bias = x
double sigmoid(double x)
{
    return 1.0f / (1.0f + exp(-x));
}

double derivetive_sigmoid(double x)
{
    return x / (1.0f - x);
}

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

double init_weight(void)
{
    return ((double)rand()) / ((double)RAND_MAX);
}

#define NUM_INPUTS 2
#define NUM_HIDDEN 2
#define NUM_OUTPUTS 1
#define NUM_PATTERNS 4

int main(void)
{
    const double learning_rate = 0.1f;

    double hidden_layer[NUM_HIDDEN];
    double output_layer[NUM_OUTPUTS];

    double hidden_layer_bias[NUM_HIDDEN];
    double output_layer_bias[NUM_OUTPUTS];

    double hidden_weights[NUM_INPUTS][NUM_HIDDEN];
    double output_weights[NUM_HIDDEN][NUM_OUTPUTS];

    double train_inputs[NUM_PATTERNS][NUM_INPUTS] = {
        {0.0f, 0.0f},
        {0.0f, 1.0f},
        {1.0f, 0.0f},
        {1.0f, 1.0f}};

    double train_outputs[NUM_PATTERNS][NUM_OUTPUTS] = {
        {0.0f},
        {1.0f},
        {1.0f},
        {0.0f}};

    // init weights
    for (int i = 0; i < NUM_INPUTS; i++)
    {
        for (int j = 0; j < NUM_HIDDEN; j++)
        {
            hidden_weights[i][j] = init_weight();
        }
    }

    // output weights
    for (int i = 0; i < NUM_HIDDEN; i++)
    {
        for (int j = 0; j < NUM_OUTPUTS; j++)
        {
            output_weights[i][j] = init_weight();
        }
    }

    // init biases
    for (int i = 0; i < NUM_HIDDEN; i++)
    {
        hidden_layer_bias[i] = init_weight();
    }

    int pattern_order[] = {0, 1, 2, 3};

    int number_of_epoch = 10000;

    // train the neural network for a number of epochs
    for (int epoch = 0; epoch < number_of_epoch; epoch++)
    {
        shuffle(pattern_order, NUM_PATTERNS);

        for (int x = 0; x < NUM_PATTERNS; x++)
        {
            int i = pattern_order[x];

            // forward pass

            // compute hidden layer activation
            for (int j = 0; j < NUM_HIDDEN; j++)
            {
                double activation = hidden_layer_bias[j];
                for (int k = 0; k < NUM_INPUTS; k++)
                {
                    activation += train_inputs[i][k] * hidden_weights[k][j];
                }

                hidden_layer[j] = sigmoid(activation);
            }

            // compute output layer activation
            for (int j = 0; j < NUM_OUTPUTS; j++)
            {
                double activation = output_layer_bias[j];
                for (int k = 0; k < NUM_HIDDEN; k++)
                {
                    activation += hidden_layer[k] * output_weights[k][j];
                }

                output_layer[j] = sigmoid(activation);
            }

            printf("epoch: %d pattern: %d\n", epoch, i);
            printf("input: %g %g output: %g expected: %g\n", train_inputs[i][0], train_inputs[i][1], output_layer[0], train_outputs[i][0]);

            // backward propagation

            // compute change in output weights
            double delta_output[NUM_OUTPUTS];
            for (int j = 0; j < NUM_OUTPUTS; j++)
            {
                double error = (train_outputs[i][j] - output_layer[j]);
                delta_output[j] = error * derivetive_sigmoid(output_layer[j]);
            }

            // compute change in hidden weights
            double delta_hidden[NUM_HIDDEN];
            for (int j = 0; j < NUM_HIDDEN; j++)
            {
                double error = 0.0f;
                for (int k = 0; k < NUM_OUTPUTS; k++)
                {
                    error += delta_output[k] * output_weights[k][j];
                }

                delta_hidden[j] = error * derivetive_sigmoid(hidden_layer[j]);
            }

            // apply change in output weights
            for (int j = 0; j < NUM_OUTPUTS; j++)
            {
                output_layer_bias[j] += learning_rate * delta_output[j];
                for (int k = 0; k < NUM_HIDDEN; k++)
                {
                    output_weights[k][j] += learning_rate * hidden_layer[k] * delta_output[j];
                }
            }

            // apply change in hidden weights
            for (int j = 0; j < NUM_HIDDEN; j++)
            {
                hidden_layer_bias[j] += learning_rate * delta_hidden[j];
                for (int k = 0; k < NUM_INPUTS; k++)
                {
                    hidden_weights[k][j] += learning_rate * train_inputs[i][k] * delta_hidden[j];
                }
            }
            
        }
    }


    // print final weights after training
            fputs("Final hidden weights\n[ ", stdout);
            for (int j = 0; j < NUM_INPUTS; j++)
            {
                fputs("[ ", stdout);
                for (int k = 0; k < NUM_HIDDEN; k++)
                {
                    printf("%f ", hidden_weights[k][j]);
                }
                fputs("] ", stdout);
            }

            fputs("]\n", stdout);

            fputs("Final hidden biases\n[ ", stdout);
            for (int j = 0; j < NUM_HIDDEN; j++)
            {
                printf("%f ", hidden_layer_bias[j]);
            }
            fputs("]\n", stdout);

            fputs("Final output weights\n[ ", stdout);
            for (int j = 0; j < NUM_HIDDEN; j++)
            {
                fputs("[ ", stdout);
                for (int k = 0; k < NUM_OUTPUTS; k++)
                {
                    printf("%f ", output_weights[k][j]);
                }
                fputs("] ", stdout);
            }

            fputs("]\n", stdout);

            fputs("Final output biases\n[ ", stdout);
            for (int j = 0; j < NUM_OUTPUTS; j++)
            {
                printf("%f ", output_layer_bias[j]);
            }
            fputs("]\n", stdout);

    return 0;
}