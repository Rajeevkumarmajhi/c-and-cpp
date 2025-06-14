#include <iostream>
using namespace std;

// 1. No argument, no return
void greet() {
    cout << "Hello! Welcome to the C++ Function Demo." << endl;
}

// 2. With argument, no return
void printSquare(int x) {
    cout << "Square of " << x << " is " << (x * x) << endl;
}

// 3. No argument, returns value
int getFixedNumber() {
    return 100;
}

// 4. With argument and return
int multiply(int a, int b) {
    return a * b;
}

int main() {
    greet();

    int num;
    cout << "Enter a number to square: ";
    cin >> num;
    printSquare(num);

    int fixed = getFixedNumber();
    cout << "Fixed number returned: " << fixed << endl;

    int x, y;
    cout << "Enter two numbers to multiply: ";
    cin >> x >> y;
    int product = multiply(x, y);
    cout << "Product is: " << product << endl;

    return 0;
}
