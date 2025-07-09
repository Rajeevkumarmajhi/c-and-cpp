// File: polymorphism.cpp

#include <iostream>
using namespace std;

//
// --------- 1. Compile-time Polymorphism ---------
//

// Function Overloading Example
class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

// Operator Overloading Example
class Point {
public:
    int x, y;

    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    // Overload + operator
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};


//
// --------- 2. Runtime Polymorphism ---------
//

// Base class
class Animal {
public:
    virtual void sound() {
        cout << "Some generic animal sound" << endl;
    }
};

// Derived class Dog
class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    cout << "=== Compile-time Polymorphism ===" << endl;

    Math math;
    cout << "add(2, 3) = " << math.add(2, 3) << endl;
    cout << "add(2.5, 3.5) = " << math.add(2.5, 3.5) << endl;
    cout << "add(1, 2, 3) = " << math.add(1, 2, 3) << endl;

    Point p1(1, 2), p2(3, 4);
    Point p3 = p1 + p2;  // Uses overloaded + operator
    cout << "p1 + p2 = ";
    p3.display();

    cout << "\n=== Runtime Polymorphism ===" << endl;

    Animal* animal;  // base class pointer

    Dog dog;
    Cat cat;

    animal = &dog;
    animal->sound();  // Calls Dog's sound()

    animal = &cat;
    animal->sound();  // Calls Cat's sound()

    return 0;
}
