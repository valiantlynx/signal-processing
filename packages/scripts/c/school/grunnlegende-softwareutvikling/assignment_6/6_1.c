#include <stdio.h>
#include <stdlib.h>

int main() {
    int count;
    printf("enter the number of integers: ");
    scanf("%d", &count);

    if (count <= 0) {
        printf("No numbers were given\n");
        return 0;
    }

    int *numbers = malloc(count*sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < count; i++){
        printf("Enter number %d: ", i +1);
        scanf("%d", &numbers[i]);
    }

    printf("Numbers: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    //sorting
    for (int i = 0; i < count -1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j +1];
                numbers[j + 1] = temp;
            }
        }
    }

    printf("Sorted: ");
    for (int i = 0; i < count; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}
