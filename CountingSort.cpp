/*
Name: Tamanna Chowdhury
Project: Project 3
CSCI 335 Object Oriented Programming
Description: This file is the implementation file for the CountingSort.cpp file. This file is used to compute the five-number summary using quickSelect1
*/

#include "CountingSort.hpp"


void countingSort(const std::string& header, std::vector<int> data) {
    std::unordered_map<int, int> counts;

    // Count occurrences of each unique value in data
    for (int num : data) {
        counts[num]++;
    }

    // Count number of unique values
    int uniqueValues = counts.size();

    // Copy key-value pairs from the hash map to a vector
    std::vector<std::pair<int, int>> countVector;
    for (const auto& entry : counts) {
        countVector.push_back(entry);
    }

    // Sort the vector based on the keys
    std::sort(countVector.begin(), countVector.end());

    // Calculate cumulative count and find quartiles
    int total = 0;
    int n = data.size();
    int q1 = -1, q2 = -1, q3 = -1;
    for (const auto& pair : countVector) {
        total += pair.second;
        if (q1 == -1 && total >= n / 4) q1 = pair.first;
        if (q2 == -1 && total >= n / 2) q2 = pair.first;
        if (q3 == -1 && total >= 3 * n / 4) q3 = pair.first;
    }

    // Find min and max values
    auto minmax = std::minmax_element(data.begin(), data.end());

    // Output results
    std::cout << header << std::endl;
    std::cout << "Min: " << *minmax.first << std::endl;
    std::cout << "P25: " << q1 << std::endl;
    std::cout << "P50: " << q2 << std::endl;
    std::cout << "P75: " << q3 << std::endl;
    std::cout << "Max: " << *minmax.second << std::endl;
    std::cout << "Unique: " << uniqueValues << std::endl;
}
