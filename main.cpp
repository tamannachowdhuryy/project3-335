#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Specify the file name here
    string filename = "testInput.txt";

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Read header from the file
    std::string header;
    std::getline(file, header);

    // Read integers from the file and store them in a vector
    vector<int> data;
    int value;
    while (file >> value) {
        data.push_back(value);
    }

    // Call the function to compute the five-number summary
    std::cout << "StdSort:" << std::endl;
    stdSort(header, data); // Pass the header string and the data vector
    std::cout << std::endl;

    std::cout << "QuickSelect1:" << std::endl;
    quickSelect1(header, data); // Pass the header string and the data vector
    std::cout << std::endl;

    std::cout << "QuickSelect2:" << std::endl;
    quickSelect2(header, data); // Pass the header string and the data vector
    std::cout << std::endl;
    
    std::cout << "CountingSort:" << std::endl;
    countingSort(header, data); // Pass the header string and the data vector

    // Close the file after reading
    file.close();

    return 0;
}
