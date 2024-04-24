/*
Name: Tamanna Chowdhury
Project: Project 3
CSCI 335 Object Oriented Programming
Description: This file is the implementation file for the StdSort.hpp file. This file is used to compute the five-number summary using std::sort
*/

/*
    using std::sort to get the box plot data in ascending order
    For project 3, given an input file of integer values, you will compute all the statistics included in a five-number summary or a box plot: the minimum value, the 25th, 50th, and 75th percentiles, and the maximum value.
    The integers in the input will be sampled from a gamma distribution. Because of the characteristics of gamma distributions, as the input size increases, the number of unique values will grow slowly, and there will be an increasing number of duplicates, yet there is no absolute upper limit on the values. This will make the input a good candidate for a hash-based counting sort.
    You will compute the five-number summary with each of the following methods, and benchmark the time taken for each method:
*/

#include "StdSort.hpp"
// Function to compute the five-number summary using std::sort
void stdSort(const std::string& header, std::vector<int> data) { // this is taking the header and the data vector
    std::vector<int> sortedData = data; // this is copying the data vector to the sortedData vector
    std::sort(sortedData.begin(), sortedData.end()); // this is sorting the sortedData vector

    int size = sortedData.size(); // this is getting the size of the sortedData vector
    int minVal = sortedData[0]; // this is getting the minimum value of the sortedData vector
    int maxVal = sortedData[size - 1]; // this is getting the maximum value of the sortedData vector
    int q1 = sortedData[size / 4]; // this is getting the 25th percentile of the sortedData vector
    int q2 = sortedData[size / 2]; // this is getting the 50th percentile of the sortedData vector
    int q3 = sortedData[3 * size / 4]; // this is getting the 75th percentile of the sortedData vector

    std::cout << header << std::endl; //prints out the header
    std::cout << "Min: " << minVal << std::endl; //prints out the minimum value
    std::cout << "P25: " << q1 << std::endl; // prints out the 25th percentile
    std::cout << "P50: " << q2 << std::endl; // prints out the 50th percentile
    std::cout << "P75: " << q3 << std::endl; // prints out the 75th percentile
    std::cout << "Max: " << maxVal << std::endl; // prints out the maximum value
}