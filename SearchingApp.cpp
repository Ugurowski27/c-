#include "Searching.cpp"
#include <iostream>
#include <vector>
#include <array>

int main() {
    // Array and vector with some repeated elements
    std::array<int, 10> arr = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8};
    std::vector<int> vec = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8};

    int target = 3;  // Element to search for

    // Test binarySearchFirst for std::array
    int firstIndexArr = binarySearchFirst(arr, target);
    if (firstIndexArr != -1) {
        std::cout << "First occurrence of " << target << " in array is at index " << firstIndexArr << ".\n";
    } else {
        std::cout << target << " not found in the array.\n";
    }

    // Test binarySearchFirst for std::vector
    int firstIndexVec = binarySearchFirst(vec, target);
    if (firstIndexVec != -1) {
        std::cout << "First occurrence of " << target << " in vector is at index " << firstIndexVec << ".\n";
    } else {
        std::cout << target << " not found in the vector.\n";
    }

    return 0;
}
