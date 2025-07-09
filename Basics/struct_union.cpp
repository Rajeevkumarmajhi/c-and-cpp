// C++ style
#include <iostream>
using namespace std;

struct Point {
    int x, y;
    void print() { cout << "Point: " << x << ", " << y << "\n"; }
};

union Data {
    int i;
    float f;
    Data() { i = 0; }   // Constructor
};

int main() {
    Point p = {10, 20};
    p.print();

    Data d;
    d.i = 10;
    cout << "Union int: " << d.i << "\n";
    d.f = 3.14f;
    cout << "Union float: " << d.f << "\n";

    return 0;
}
