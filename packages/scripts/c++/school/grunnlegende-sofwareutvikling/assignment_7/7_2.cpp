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
        std::cout << "No numbers were entered." << std::ends;
        return 0;
    }

    double average = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();

    std::nth_element(numbers.begin(), numbers.begin() + numbers.size() / 2, numbers.end());
    double median = numbers[numbers.size() / 2];
    if (numbers.size() % 2 == 0) {
        median = (median + *std::max_element(numbers.begin(), numbers.begin() + numbers.size() / 2)) / 2.0;
    }

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    // average. it is annoying as hell to remove traling zeroes
    std::stringstream ss;
    ss << std::fixed << std::setprecision(4) << average; // Write the average to the stringstream
    std::string str = ss.str(); // Extract the string

// Ensure that there is a decimal point somewhere (there should be)
    if(str.find('.') != std::string::npos)
    {
        // Remove trailing zeroes
        str = str.substr(0, str.find_last_not_of('0')+1);
        // If the decimal point is now the last character, remove that as well
        if(str.back() == '.')
        {
            str.pop_back();
        }
    }
    std::cout << "Average : " << str << std::endl;



    // Check if the median is a whole number
    if (median == static_cast<int>(median)) {
        std::cout << "Median : " << static_cast<int>(median) << std::endl;
    } else {
        std::cout << "Median : " << median << std::endl;
    }

    std::cout << "Descending : ";
    for (const auto& n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
