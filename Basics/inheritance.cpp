#include <iostream>
using namespace std;

// Base class for Single, Multiple, Hierarchical Inheritance
class Animal {
public:
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

// Single Inheritance: Dog inherits from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

// Multiple Inheritance:
// Class A with method a()
class A {
public:
    void a() {
        cout << "Class A method a()" << endl;
    }
};

// Class B with method b()
class B {
public:
    void b() {
        cout << "Class B method b()" << endl;
    }
};

// Multiple Inheritance: Class C inherits from both A and B
class C : public A, public B {
public:
    void c() {
        cout << "Class C method c()" << endl;
    }
};

// Hierarchical Inheritance:
// Cat and Bird both inherit from Animal
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows." << endl;
    }
};

class Bird : public Animal {
public:
    void chirp() {
        cout << "Bird chirps." << endl;
    }
};

// Multilevel Inheritance:
// Grandparent -> Parent -> Child
class Grandparent {
public:
    void grandparentFunc() {
        cout << "Grandparent function." << endl;
    }
};

class Parent : public Grandparent {
public:
    void parentFunc() {
        cout << "Parent function." << endl;
    }
};

class Child : public Parent {
public:
    void childFunc() {
        cout << "Child function." << endl;
    }
};

// Hybrid Inheritance with virtual inheritance to avoid ambiguity

// Base class Vehicle
class Vehicle {
public:
    void vehicleInfo() {
        cout << "Vehicle info." << endl;
    }
};

// Derived from Vehicle - LandVehicle (virtual inheritance)
class LandVehicle : virtual public Vehicle {
public:
    void landVehicleInfo() {
        cout << "Land vehicle info." << endl;
    }
};

// Derived from Vehicle - WaterVehicle (virtual inheritance)
class WaterVehicle : virtual public Vehicle {
public:
    void waterVehicleInfo() {
        cout << "Water vehicle info." << endl;
    }
};

// AmphibiousVehicle inherits both LandVehicle and WaterVehicle
class AmphibiousVehicle : public LandVehicle, public WaterVehicle {
public:
    void amphibiousInfo() {
        cout << "Amphibious vehicle info." << endl;
    }
};

int main() {
    cout << "----- Single Inheritance -----" << endl;
    Dog dog;
    dog.eat();  // from Animal
    dog.bark();

    cout << "\n----- Multiple Inheritance -----" << endl;
    C objC;
    objC.a();
    objC.b();
    objC.c();

    cout << "\n----- Hierarchical Inheritance -----" << endl;
    Cat cat;
    Bird bird;
    cat.eat();   // from Animal
    cat.meow();
    bird.eat();  // from Animal
    bird.chirp();

    cout << "\n----- Multilevel Inheritance -----" << endl;
    Child child;
    child.grandparentFunc();
    child.parentFunc();
    child.childFunc();

    cout << "\n----- Hybrid Inheritance -----" << endl;
    AmphibiousVehicle amphibious;
    amphibious.vehicleInfo();        // No ambiguity now
    amphibious.landVehicleInfo();
    amphibious.waterVehicleInfo();
    amphibious.amphibiousInfo();

    return 0;
}
