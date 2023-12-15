#include <stdio.h>

int main() {
    float sum = 0;
    int count = 0;
    float avarage = 0;

    printf("Please enter a number: \n");
    float x = 1;
    while (x != 0) {
        printf("Try again: \n");
        scanf("%f", &x);
        sum += x;
        count++;
        avarage = sum/(count-1);
    }
    printf("Count: %i\n", count-1);
    printf("Sum: %g\n", sum);
    printf("Average: %g\n", avarage);

    return 0;
}