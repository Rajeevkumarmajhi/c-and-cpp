#include <iostream>
using namespace std;

// Inline function definition
inline int square(int x) {
    return x * x;
}

inline void greet(const string& name) {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    int num = 5;
    cout << "Square of " << num << " is: " << square(num) << endl;

    greet("Rajeev");
    greet("World");

    return 0;
}
