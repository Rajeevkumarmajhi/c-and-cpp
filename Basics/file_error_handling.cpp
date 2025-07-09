#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ---------- Output: Writing to a file ----------
    ofstream outFile("sample.txt", ios::out);
    
    if (!outFile) {
        cerr << "❌ Error opening file for writing!" << endl;
        return 1;
    }

    outFile << "Hello from C++ file handling!" << endl;
    outFile << "This is a second line." << endl;
    outFile.close();  // Always close the file

    // ---------- Input: Reading from a file ----------
    ifstream inFile("sample.txt", ios::in);

    if (!inFile) {
        cerr << "❌ Error opening file for reading!" << endl;
        return 1;
    }

    string line;
    cout << "📄 Contents of file:" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();

    return 0;
}
