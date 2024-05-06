/*
Name: Tamanna Chowdhury
Project: Project 3
CSCI 335 Object Oriented Programming
Description: This file is the implementation file for the StdSort.hpp file. This file is used to compute the five-number summary using std::sort
*/

/*
    @param header: The header string for the box plot.
    @param data: The input vector of integers.
    @post: Outputs the minimum, maximum, and quartile values of the input data after sorting it.
*/


#include "StdSort.hpp"

void stdSort(const std::string& header, std::vector<int> data) {
    std::vector<int> sortedData = data;
    std::sort(sortedData.begin(), sortedData.end());

    int size = sortedData.size();
    int minVal = sortedData[0];
    int maxVal = sortedData[size - 1];
    
    int q1, q2, q3;

    q1 = (sortedData[size / 4 - 1]); // 25th percentile
    q3 = (sortedData[3 * size / 4 - 1]); // 75th percentile
    q2 = sortedData[size / 2]; // 50th percentile

    std::cout << header << std::endl;
    std::cout << "Min: " << minVal << std::endl;
    std::cout << "P25: " << q1 << std::endl;
    std::cout << "P50: " << q2 << std::endl;
    std::cout << "P75: " << q3 << std::endl;
    std::cout << "Max: " << maxVal << std::endl;
}

