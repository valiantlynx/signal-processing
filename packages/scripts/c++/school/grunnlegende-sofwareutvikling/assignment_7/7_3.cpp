#include <iostream>
#include <string>
#include <map>
#include <vector>

class Student {
public:
    std::string name;
    std::map<std::string, char> courses;

    Student() = default; 
    Student(std::string n) : name(std::move(n)) {}
};

int main() {
    std::map<std::string, Student> students;
    std::string studentName, courseName;
    char grade;

    while (true) {
        std::cout << "Enter student name ('stop' to finish): ";
        std::getline(std::cin, studentName);
        if (studentName == "stop") break;

        Student& student = students[studentName];
        student.name = studentName;

        while (true) {
            std::cout << "Enter course name ('stop' to finish): ";
            std::getline(std::cin, courseName);
            if (courseName == "stop") break;

            std::cout << "Enter grade for " << courseName << ": ";
            std::cin >> grade;
            std::cin.ignore();

            student.courses[courseName] = grade;
        }
    }
    
    for (const auto& pair : students) {
        const Student& student = pair.second;
        for (const auto& coursePair : student.courses) {
            std::cout << student.name << " - " << coursePair.first << " - " << coursePair.second << std::endl;
        }
    }

    return 0;
}
