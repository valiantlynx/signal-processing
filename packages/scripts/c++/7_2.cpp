#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>  // Include this header for std::accumulate

int main() {
    std::vector<int> numbers;
    int num;
    std::cout << "Enter numbers (0 to finish): ";
    while (std::cin >> num && num != 0) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cout << "No numbers were entered." << std::endl;
        return 0;
    }

    // Calculate average
    double average = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();

    // Calculate median
    std::nth_element(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.end());
    double median = numbers[numbers.size() / 2];
    if (numbers.size() % 2 == 0) {
        median = (median + *std::max_element(numbers.begin(), numbers.begin() + numbers.size() / 2)) / 2.0;
    }

    // Sort in descending order
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // Output
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Average: " << average << std::endl;
    std::cout << "Median: " << median << std::endl;
    std::cout << "Descending: ";
    for (const auto& n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
