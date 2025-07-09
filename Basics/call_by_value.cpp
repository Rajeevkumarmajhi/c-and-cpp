#include <iostream>
using namespace std;

// Call by value
void increment(int x) {
    x = x + 1;
    cout << "Inside increment (call by value): " << x << endl;
}

int main() {
    int num = 5;
    cout << "Before increment: " << num << endl;
    increment(num);  // Copy passed
    cout << "After increment: " << num << endl;  // No change
    return 0;
}
