#include <iostream>
using namespace std;

int main() {
    char ch;
    string name;

    cout << "Enter a character: ";
    ch = cin.get();         // Unformatted character input

    cout.put(ch);           // Unformatted character output
    cout << endl;

    cout << "Enter your full name: ";
    cin.ignore();           // Ignore leftover newline
    getline(cin, name);     // Unformatted string input

    cout << "Hello, ";
    cout.write(name.c_str(), name.length()); // Unformatted string output

    return 0;
}
