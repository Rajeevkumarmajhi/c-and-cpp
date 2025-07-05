#include <iostream>
using namespace std;

// Abstract base class
class Animal {
public:
    virtual void speak() = 0;  // Pure virtual function
    void identity() {
        cout << "I am an Animal" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog says Woof!" << endl;
    }

    void identity() {
        cout << "I am a Dog" << endl;
    }
};

int main() {
    Dog d;
    Animal* a = &d;

    // Early Binding
    d.identity();   // I am a Dog (object, compile time)
    a->identity();  // I am an Animal (base class method, no virtual)

    // Late Binding
    d.speak();      // Dog says Woof!
    a->speak();     // Dog says Woof! (runtime polymorphism)
}
