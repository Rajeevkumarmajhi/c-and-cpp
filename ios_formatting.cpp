#include <iostream>
using namespace std;

int main() {
    float pi = 3.14159;
    int number = 42;

    // --------- Set precision and fixed flag ---------
    cout.setf(ios::fixed);                  // Fixed-point notation
    cout.precision(2);                      // 2 decimal places
    cout << "Fixed with 2 decimals: " << pi << endl;

    // --------- Change precision ---------
    cout.precision(5);
    cout << "Fixed with 5 decimals: " << pi << endl;

    // --------- Width and fill ---------
    cout.width(10);                         // Width applies to next output only
    cout.fill('*');                         // Fill character for padding
    cout << number << endl;                 // Output: "********42"

    // --------- Set justification using setf ---------
    cout.setf(ios::left);                   // Left alignment
    cout.width(10);
    cout << number << endl;                 // Output: "42        "

    cout.setf(ios::right);                  // Right alignment
    cout.width(10);
    cout << number << endl;                 // Output: "        42"

    // --------- Show positive sign ---------
    cout.setf(ios::showpos);               // Show + for positive
    cout << number << endl;                // Output: "+42"

    // --------- Unset flags ---------
    cout.unsetf(ios::showpos);             // Remove + sign flag
    cout.unsetf(ios::left);                // Reset left alignment
    cout.unsetf(ios::right);               // Reset right alignment

    cout << number << endl;

    return 0;
}
