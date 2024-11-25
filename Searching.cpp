#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

// Binary search function for std::array
template <typename T, size_t N>
int binarySearch(const std::array<T, N>& arr, T target) {
    int left = 0, right = N - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Return -1 if target is not found
}

// Binary search function for std::vector
template <typename T>
int binarySearch(const std::vector<T>& vec, T target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) return mid;
        if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // Return -1 if target is not found
}

// Find the first occurrence of a target in std::array
template <typename T, size_t N>
int binarySearchFirst(const std::array<T, N>& arr, T target) {
    int index = binarySearch(arr, target);
    if (index == -1) return -1;  // Return -1 if target is not found
    
    // Check for the first occurrence of the target
    while (index > 0 && arr[index - 1] == target) {
        --index;
    }
    return index;
}

// Find the first occurrence of a target in std::vector
template <typename T>
int binarySearchFirst(const std::vector<T>& vec, T target) {
    int index = binarySearch(vec, target);
    if (index == -1) return -1;  // Return -1 if target is not found
    
    // Check for the first occurrence of the target
    while (index > 0 && vec[index - 1] == target) {
        --index;
    }
    return index;
}

int main() {
    std::array<int, 6> arr = {1, 2, 2, 3, 4, 5};
    std::vector<int> vec = {1, 2, 2, 3, 4, 5};

    // Test binary search in array
    int indexArr = binarySearch(arr, 3);
    std::cout << "Array: Found 3 at index " << indexArr << std::endl;

    // Test binary search in vector
    int indexVec = binarySearch(vec, 3);
    std::cout << "Vector: Found 3 at index " << indexVec << std::endl;

    // Test binarySearchFirst in array
    int firstArr = binarySearchFirst(arr, 2);
    std::cout << "Array: First occurrence of 2 at index " << firstArr << std::endl;

    // Test binarySearchFirst in vector
    int firstVec = binarySearchFirst(vec, 2);
    std::cout << "Vector: First occurrence of 2 at index " << firstVec << std::endl;

    return 0;
}
