#include <iostream>
#include <vector>
#include <algorithm> // for std::swap

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Last i elements are already in place, so we ignore them
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

void printArray(const std::vector<int>& arr) {
    for (int val : arr) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> data = {5, 1, 4, 2, 8};
    
    std::cout << "Original array: ";
    printArray(data);

    bubbleSort(data);

    std::cout << "Sorted array:   ";
    printArray(data);

    return 0;
}