#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform linear search
int linearSearch(const std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    std::vector<int> numbers = {2, 45, 67, 12, 9, 34};
    int target = 12;
    int result = linearSearch(numbers, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found" << std::endl;
    }

    return 0;
}
