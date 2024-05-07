/*
Name: Tamanna Chowdhury
Project: Project 3
CSCI 335 Object Oriented Programming
Description: This file is the implementation file for the QuickSelect1.hpp file. This file is used to compute the five-number summary using quickSelect1
*/

#include "QuickSelect1.hpp"

/*
    @param arr: The input vector of integers.
    @param left: The starting index of the range.
    @param right: The ending index of the range.
    @return: The index of the pivot element after partitioning the array.
*/

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
/*
    @param arr: The input vector of integers.
    @param left: The starting index of the range.
    @param right: The ending index of the range.
    @param k: The index of the element to select.
    @return: The selected element.
*/


void quickSelect1(const std::string& header, std::vector<int> data) {
    int n = data.size();
    if (n == 0) {
        std::cerr << "Error: Empty vector!" << std::endl;
        return;
    }

    // Calculate the indices for the median, 25th percentile (Q1), and 75th percentile (Q3)
    int k_median = n / 2;
    int k_q1 = (n + 1) / 4 - 1;
    int k_q3 = 3 * (n + 1) / 4 - 1;

    // Perform QuickSelect to find the median
    int median = quickSelect(data, 0, n - 1, k_median);

    // Perform QuickSelect to find the 25th percentile (Q1)
    int q1 = quickSelect(data, 0, n - 1, k_q1);

    // Perform QuickSelect to find the 75th percentile (Q3)
    int q3 = quickSelect(data, 0, n - 1, k_q3);

    // Find the minimum value before Q1 and maximum value after Q3
    int minVal = data[0];
    int maxVal = data[0];
    for (int i = 1; i < n; ++i) {
        if (data[i] < minVal) {
            minVal = data[i];
        } else if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    // Output the results
    std::cout << header << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    std::cout << "P25: " << q1 << std::endl;
    std::cout << "P50: " << median << std::endl;
    std::cout << "P75: " << q3 << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
}
