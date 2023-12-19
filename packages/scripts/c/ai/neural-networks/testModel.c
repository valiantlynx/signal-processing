#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NUM_INPUTS 2
#define NUM_HIDDEN 2
#define NUM_OUTPUTS 1

double sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

void load_model(const char *filename, double hidden_weights[NUM_INPUTS][NUM_HIDDEN], double output_weights[NUM_HIDDEN][NUM_OUTPUTS], double hidden_biases[NUM_HIDDEN], double output_biases[NUM_OUTPUTS]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Load hidden weights
    for (int i = 0; i < NUM_INPUTS; i++) {
        for (int j = 0; j < NUM_HIDDEN; j++) {
            fscanf(file, "%lf", &hidden_weights[i][j]);
        }
    }

    // Load output weights
    for (int i = 0; i < NUM_HIDDEN; i++) {
        for (int j = 0; j < NUM_OUTPUTS; j++) {
            fscanf(file, "%lf", &output_weights[i][j]);
        }
    }

    // Load hidden biases
    for (int i = 0; i < NUM_HIDDEN; i++) {
        fscanf(file, "%lf", &hidden_biases[i]);
    }

    // Load output biases
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        fscanf(file, "%lf", &output_biases[i]);
    }

    fclose(file);
}

double predict(double input[NUM_INPUTS], double hidden_weights[NUM_INPUTS][NUM_HIDDEN], double output_weights[NUM_HIDDEN][NUM_OUTPUTS], double hidden_biases[NUM_HIDDEN], double output_biases[NUM_OUTPUTS]) {
    double hidden_layer[NUM_HIDDEN];

    // Compute hidden layer activation
    for (int j = 0; j < NUM_HIDDEN; j++) {
        hidden_layer[j] = hidden_biases[j];
        for (int i = 0; i < NUM_INPUTS; i++) {
            hidden_layer[j] += input[i] * hidden_weights[i][j];
        }
        hidden_layer[j] = sigmoid(hidden_layer[j]);
    }

    // Compute output layer activation
    double output = output_biases[0];
    for (int j = 0; j < NUM_HIDDEN; j++) {
        output += hidden_layer[j] * output_weights[j][0];
    }
    return sigmoid(output);
}

int main(void) {
    double hidden_weights[NUM_INPUTS][NUM_HIDDEN];
    double output_weights[NUM_HIDDEN][NUM_OUTPUTS];
    double hidden_biases[NUM_HIDDEN];
    double output_biases[NUM_OUTPUTS];

    // Load the model
    load_model("model.txt", hidden_weights, output_weights, hidden_biases, output_biases);

    // Example input
    double input[NUM_INPUTS] = {1.0, 0.0}; // Change this to the input you want to predict

    // Make a prediction
    double output = predict(input, hidden_weights, output_weights, hidden_biases, output_biases);
    printf("Predicted output: %f\n", output);

    while (1) {
        // Wait for user input
        printf("Enter input: ");
        scanf("%lf %lf", &input[0], &input[1]);

        // Make a prediction
        double output = predict(input, hidden_weights, output_weights, hidden_biases, output_biases);

        // round the output to the nearest integer and print it and whether it is correct
        char *correct = "Incorrect";
        if (round(output) == 1.0) {
            correct = "Correct";
        }

        printf("Predicted output: %f (%s)\n", output, correct);
    }

    return 0;
}
