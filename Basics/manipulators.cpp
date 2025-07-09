#include <iostream>
#include <iomanip>  // Required for manipulators with arguments
using namespace std;

int main() {
    int num = 255;
    float pi = 3.14159;
    string input;

    cout << "🔹 Manipulators with arguments:\n";

    // setw + setfill
    cout << setw(10) << setfill('*') << num << endl;      // *****255

    // setbase
    cout << "Decimal: " << setbase(10) << num << endl;
    cout << "Hex    : " << setbase(16) << num << endl;
    cout << "Octal  : " << setbase(8)  << num << endl;

    // setiosflags and resetiosflags
    cout << setiosflags(ios::showpos | ios::scientific);
    cout << "PI with flags: " << pi << endl;

    cout << resetiosflags(ios::showpos | ios::scientific);
    cout << "PI reset flags: " << pi << endl;

    cout << "\n🔸 Manipulators without arguments:\n";

    // fixed + showpoint
    cout << fixed << showpoint << setprecision(2);
    cout << "PI fixed: " << pi << endl;

    // left alignment
    cout << left;
    cout << setw(10) << "Left" << "|" << endl;

    // ends adds '\0' (not visible in output)
    cout << "Hello" << ends << "World" << endl;  // Output: HelloWorld

    // ws (consume leading whitespace from user input)
    cout << "Enter a string with leading spaces: ";
    cin >> ws;        // removes whitespace before input
    getline(cin, input);
    cout << "You typed: [" << input << "]" << endl;

    // flush
    cout << "This line is flushed." << flush;

    return 0;
}
