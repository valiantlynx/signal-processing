#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    char name[100];
    int age;
} student_t;

int read_student_info();
int write_student_info();

int main() {
    int choice;

    printf("1. Read student information from file\n2. Write student information to file\n3. Exit\n");
    scanf("%i", &choice);

    switch (choice) {
        case 1:
            read_student_info();
            break;

        case 2:
            write_student_info();
            break;
        case 3:
            break;
    }


    return 0;
}

int read_student_info() {
    char name[100];
    char id[100];
    char age[100];

    FILE* read = fopen("student_read.txt", "r");
    fgets(id, sizeof(id), read);
    fgets(name, sizeof(name), read);
    fgets(age, sizeof(age), read);


    fclose(read);

    // prints the info
    printf("Student id: %s\n", id);
    printf("Name: %s\n", name);
    printf("Age: %s", age);

    return 0;
}

int write_student_info() {
    FILE* write = fopen("student_write.txt", "w");
    char name[100];
    char id[100];
    char age[100];

    // get the info
    printf("Please enter you ID: \n");
    scanf("%s", id);
    fprintf(write, "%s\n", id);

    //consume the new line character
    getchar();


    printf("Please enter you name: \n");
    fgets(name, 100, stdin);
    fprintf(write, "%s", name);

    printf("Please enter you age: \n");
    scanf("%s", age);
    fprintf(write, "%s\n", age);

    return 0;
}