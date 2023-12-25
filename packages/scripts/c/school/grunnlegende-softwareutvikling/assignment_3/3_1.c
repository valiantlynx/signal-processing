#include <stdio.h>
#define ARRAY_SIZE 10

void sort(int nums[]){
    //loop through the whole array then the inner loop, loops and edits the array.  do that the next time the outerone does it it loops through the edited array.
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        //loop through the whole array and edit the position. by checking if the number is bigger than the next number. is yes, switch them. the problem is this code exits after editing once. which is why we need the outer loop
        for (int x = 0; x < ARRAY_SIZE - 1; ++x) {
            if (nums[x] > nums[x+1]){
                int temporaryValue = nums[x];
                nums[x] = nums[x+1];
                nums[x+1] = temporaryValue;
            }
        }
    }
}
int minimum(int nums[]){
    sort(nums);
    int result = nums[0];
    return result;
}
int maximum(int nums[]){
    sort(nums);
    int result = nums[ARRAY_SIZE-1];
    return result;
}
int sum(int nums[]){
    int sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += nums[i];
    }
    return sum;
}
float average(int nums[]){
    float sum = 0;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sum += nums[i];
    }
    float result = sum/ARRAY_SIZE;
    return result;
}
float median(int nums[]){
    sort(nums);
    float result;
    result = (nums[(ARRAY_SIZE-1)/2] + nums[ARRAY_SIZE/2])/2.0;
    return result;
}

int main() {
    int numbers[ARRAY_SIZE];
    for (int i = 0; i <= ARRAY_SIZE -1; ++i) {
        scanf("%i", &numbers[i]);
    }

    printf("Minimum: %i\n", minimum(numbers));
    printf("Maximum: %i\n", maximum(numbers));
    printf("Sum: %i\n", sum(numbers));
    printf("Average: %g\n", average(numbers));
    printf("Sorted: ");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    printf("Median: %g\n", median(numbers));
    return 0;
}