#include <iostream>
using namespace std;

// Call by reference using pointers
void increment(int *x) {
    *x = *x + 1;
    cout << "Inside increment (call by reference): " << *x << endl;
}

int main() {
    int num = 5;
    cout << "Before increment: " << num << endl;
    increment(&num);  // Address passed, original changes
    cout << "After increment: " << num << endl;
    return 0;
}
