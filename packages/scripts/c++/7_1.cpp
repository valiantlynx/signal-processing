#include <iostream>

int main() {
    std::string str1, str2;
    std::cout << "Enter first string: ";
    std::getline(std::cin, str1);
    std::cout << "Enter second string: ";
    std::getline(std::cin, str2);

    if (str1 == str2) {
        std::cout << "The strings are equal\n";
    } else {
        std::cout << "The strings are not equal\n";
        if (str1.find(str2) != std::string::npos) {
            std::cout << "Last string is substring of first string\n";
        } else if (str2.find(str1) != std::string::npos) {
            std::cout << "First string is substring of last string\n";
        } else {
            std::cout << "There are no substrings\n";
        }
    }
    return 0;
}
