
#include <iostream>
#include <stdexcept>

class Node {
public:
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr), listSize(0) {}
    ~LinkedList();

    void push_back(int value);
    size_t size() const { return listSize; }
    int& at(size_t index);
    void remove(size_t index);

private:
    Node* head;
    size_t listSize;
};

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    listSize++;
}

int& LinkedList::at(size_t index) {
    if (index >= listSize) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

void LinkedList::remove(size_t index) {
    if (index >= listSize) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    Node* previous = nullptr;
    for (size_t i = 0; i < index; i++) {
        previous = current;
        current = current->next;
    }
    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    delete current;
    listSize--;
}


// ui
void printMenu() {
    std::cout << "1. Add integer\n"
              << "2. Show integer at index\n"
              << "3. Remove integer at index\n"
              << "4. Print information\n"
              << "5. Exit\n";
}

int main() {
    LinkedList list;
    int choice, value, index;

    while (true) {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter an integer: ";
                std::cin >> value;
                list.push_back(value);
                break;
            case 2:
                std::cout << "Enter index: ";
                std::cin >> index;
                try {
                    std::cout << "Integer at index " << index << ": " << list.at(index) << std::endl;
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter index: ";
                std::cin >> index;
                try {
                    list.remove(index);
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            case 4:
                if (list.size() == 0) {
                    std::cout << "List contains no integers\n";
                } else {
                    std::cout << "List contains " << list.size() << " integers: ";
                    for (size_t i = 0; i < list.size(); i++) {
                        std::cout << list.at(i) << " ";
                    }
                    std::cout << std::endl;
                }
                break;
            case 5:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
