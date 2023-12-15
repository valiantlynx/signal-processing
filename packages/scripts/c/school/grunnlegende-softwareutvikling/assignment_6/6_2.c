#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Student;

int main() {
    int capacity = 5;
    int count = 0;
    Student *students = malloc(capacity * sizeof(Student));

    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (1) {
        printf("Enter student name: ");  // Changed prompt
        char tempName[50];
        fgets(tempName, 50, stdin);

        // Handle newline character
        size_t len = strlen(tempName);
        if (len > 0 && tempName[len - 1] == '\n') {
            tempName[len - 1] = '\0';
        }

        if (strcmp(tempName, "stop") == 0) {
            break;
        }

        printf("Enter age: ");  // Changed prompt
        int tempAge;
        scanf("%d", &tempAge);
        getchar();  // Consume newline character

        if (count == capacity) {
            capacity *= 2;
            students = realloc(students, capacity * sizeof(Student));
            if (students == NULL) {
                printf("Memory allocation failed\n");
                return 1;
            }
        }

        strcpy(students[count].name, tempName);
        students[count].age = tempAge;
        count++;
    }

    // Print output
    if (count == 0) {
        printf("No students were given\n");
    } else {
        printf("Count: %d\n", count);
        for (int i = 0; i < count; ++i) {
            printf("Name = %s, Age = %d\n", students[i].name, students[i].age);
        }

        // Find youngest and oldest
        int youngestIndex = 0;
        int oldestIndex = 0;
        for (int i = 0; i < count; ++i) {
            if (students[i].age < students[youngestIndex].age) {
                youngestIndex = i;
            }
            if (students[i].age > students[oldestIndex].age) {
                oldestIndex = i;
            }
        }

        printf("Youngest: %s\n", students[youngestIndex].name);
        printf("Oldest: %s\n", students[oldestIndex].name);
    }

    free(students);
    return 0;
}
