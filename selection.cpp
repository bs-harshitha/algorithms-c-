#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // Assume the current position is the minimum
        int min_idx = i;

        // Check the rest of the array for a smaller value
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        if (min_idx != i) {
            std::swap(arr[min_idx], arr[i]);
        }
    }
}

void printArray(const std::vector<int>& arr) {
    for (int val : arr) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {64, 25, 12, 22, 11};
    
    selectionSort(data);
    
    std::cout << "Sorted array: ";
    printArray(data);
    
    return 0;
}