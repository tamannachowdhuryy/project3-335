#include <iostream>
#include <fstream>
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
    
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    
    file.close();
    
    return 0;
}
