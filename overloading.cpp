#include <iostream>
using namespace std;

// Class definition
class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor
    Box(double l = 0, double w = 0, double h = 0)
        : length(l), width(w), height(h) {}

    // Function Overloading: display()
    void display() {
        cout << "Box Dimensions: " << length << " x " << width << " x " << height << endl;
    }

    void display(const string& label) {
        cout << label << ": " << length << " x " << width << " x " << height << endl;
    }

    // Operator Overloading: +
    Box operator+(const Box& other) {
        return Box(length + other.length, width + other.width, height + other.height);
    }

    // Operator Overloading: ==
    bool operator==(const Box& other) {
        return length == other.length && width == other.width && height == other.height;
    }
};

int main() {
    Box box1(2, 3, 4);
    Box box2(1, 5, 2);
    Box box3;

    // Function Overloading
    box1.display();                     // Calls display()
    box1.display("Box One");           // Calls display(string)

    // Operator Overloading: +
    box3 = box1 + box2;                // box3 becomes sum of box1 and box2
    box3.display("Box One + Box Two");

    // Operator Overloading: ==
    if (box1 == box2) {
        cout << "Box1 and Box2 are equal." << endl;
    } else {
        cout << "Box1 and Box2 are NOT equal." << endl;
    }

    return 0;
}
