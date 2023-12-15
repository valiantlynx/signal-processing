#include <stdio.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[100];
    int age;
} student_t;

int main() {
    struct Student student1;

    // get the info
    printf("Please enter you ID: \n");
    scanf("%i", &student1.id);

    //consume the new line character
    getchar();


    printf("Please enter you name: \n");
    char name[100];
    fgets(student1.name, 100, stdin);
    student1.name[strlen(student1.name) - 1] = 0;

    printf("Please enter you age: \n");
    scanf("%i", &student1.age);

    // prints the info
    printf("Student id: %i\n", student1.id);
    printf("Name: %s\n", student1.name);
    printf("Age: %i", student1.age);

    return 0;
}