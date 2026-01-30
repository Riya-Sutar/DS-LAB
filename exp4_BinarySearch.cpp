#include <iostream>
#include <vector>
#include <algorithm>

// Function to perform binary search (iterative approach)
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> numbers = {2, 9, 12, 34, 45, 67}; // Must be sorted
    int target = 34;
    int result = binarySearch(numbers, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found" << std::endl;
    }

    return 0;
}
