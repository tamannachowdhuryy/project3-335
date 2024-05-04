/*
Name: Tamanna Chowdhury
Project: Project 3
CSCI 335 Object Oriented Programming
Description: This file is the implementation file for the QuickSelect1.hpp file. This file is used to compute the five-number summary using quickSelect1
*/

/*
For method 2, using quickSelect 3 times, the idea is simple: call quickSelect on the entire input with the middle of the vector as the key, k. This will give you the median, around which your vector will be partitioned. Then, call quickSelect on the half of the vector before the median with the 25% mark of the vector as k. Then, call quickSelect on the half of the vector after the median with the 75% mark as k. Then, search for the minimum only before the 25% mark, and the maximum only after the 75% mark. Default to insertion sort when quickSelect is recursively called on a range of size 20 or less (this means you'll have to write a small in-place insertion sort).
*/
#include "QuickSelect1.hpp"

// Function to partition the array and return the index of the pivot element
int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Function to perform quick select on a range of an array
int quickSelect(std::vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);
        if (k == pivotIndex) {
            return arr[k];
        } else if (k < pivotIndex) {
            return quickSelect(arr, left, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, right, k);
        }
    }
    return -1; // Handle invalid range
}

// Function to output the box plot using quickSelect1
void quickSelect1(const std::string& header, std::vector<int> data) {
    int n = data.size();
    if (n == 0) {
        std::cerr << "Error: Empty vector!" << std::endl;
        return;
    }

    int k_median = n / 2;           // Middle of the vector as the key for median
    int k_q1 = (n + 1) / 4 - 1;     // 25th percentile key
    int k_q3 = 3 * (n + 1) / 4 - 1; // 75th percentile key

    // Perform quickSelect to find the median
    int median = quickSelect(data, 0, n - 1, k_median);

    // Perform quickSelect to find the 25th percentile (Q1)
    int q1 = quickSelect(data, 0, n - 1, k_q1);

    // Perform quickSelect to find the 75th percentile (Q3)
    int q3 = quickSelect(data, 0, n - 1, k_q3);

    int q2 = median; // Q2 (median) is equal to the median value

    // Sort the data vector for finding min and max
    std::sort(data.begin(), data.end());

    int minVal = data.front(); // Get the minimum value
    int maxVal = data.back();  // Get the maximum value

    // Output the results
    std::cout << header << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    std::cout << "P25: " << q1 << std::endl;
    std::cout << "P50: " << q2 << std::endl;
    std::cout << "P75: " << q3 << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
}


