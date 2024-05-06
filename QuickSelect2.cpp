/*
Name: Tamanna Chowdhury
Project: Project 3
CSCI 335 Object Oriented Programming
Description: This file is the implementation file for the QuickSelect2.hpp file. This file is used to compute the five-number summary using quickSelect1
*/

/*
    @param header: The header string for the box plot.
    @param data: The input vector of integers.
    @post: Outputs the minimum, maximum, and quartile values of the input data after sorting it.

*/
#include "QuickSelect2.hpp"
template <typename Comparable>
const Comparable& median(std::vector<Comparable>& a, int left, int right) {
    int center = (left + right) / 2;

    if (a[center] < a[left])
        std::swap(a[left], a[center]);
    if (a[right] < a[left])
        std::swap(a[left], a[right]);
    if (a[right] < a[center])
        std::swap(a[center], a[right]);

    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}

/*
    @param a: The input vector of Comparable objects.
    @param left: The starting index of the range.
    @param right: The ending index of the range.
    @post: Sorts the input vector using insertion sort.
*/
template <typename Comparable>
void insertionSort(std::vector<Comparable>& a, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        Comparable key = std::move(a[i]);
        int j = i - 1;
        while (j >= left && a[j] > key) {
            a[j + 1] = std::move(a[j]);
            --j;
        }
        a[j + 1] = std::move(key);
    }
}

/*
    @param a: The input vector of Comparable objects.
    @param left: The starting index of the range.
    @param right: The ending index of the range.
    @param keys: The set of indices to select the quartiles.
    @post: Sorts the input vector using quick select and insertion sort.
*/
template <typename Comparable>
void quickSelect(std::vector<Comparable>& a, int left, int right, const std::set<int>& keys) {
    if (left + 10 <= right) {
        const Comparable& pivot = median(a, left, right);
        int i = left, j = right - 1;
        for (;;) {
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}
            if (i < j)
                std::swap(a[i], a[j]);
            else
                break;
        }
        std::swap(a[i], a[right - 1]); // Restore pivot

        std::set<int> leftKeys, rightKeys;
        for (int key : keys) {
            if (key < i)
                leftKeys.insert(key);
            else if (key > i)
                rightKeys.insert(key);
        }

        if (!leftKeys.empty())
            quickSelect(a, left, i - 1, leftKeys);
        if (!rightKeys.empty())
            quickSelect(a, i + 1, right, rightKeys);
    } else {
        insertionSort(a, left, right);
    }
}

/*
    @param header: The header string for the box plot.
    @param data: The input vector of integers.
    @post: Outputs the minimum, maximum, and quartile values of the input data after sorting it.
*/
void quickSelect2(const std::string& header, std::vector<int> data) {
    int n = data.size();
    if (n == 0) {
        std::cerr << "Error: Empty vector!" << std::endl;
        return;
    }

    std::set<int> keys = {0, (n + 3) / 4 - 1, (n + 1) / 2 - 1, 3 * (n + 1) / 4 - 1, n - 1};

    quickSelect(data, 0, n - 1, keys);

    std::cout << header << std::endl;
    std::cout << "Min: " << data[0] << std::endl;
    std::cout << "P25: " << data[(n + 3) / 4 - 1] << std::endl;
    std::cout << "P50: " << data[(n + 1) / 2 - 1] << std::endl;
    std::cout << "P75: " << data[3 * (n + 1) / 4 - 1] << std::endl;
    std::cout << "Max: " << data[n - 1] << std::endl;
}
