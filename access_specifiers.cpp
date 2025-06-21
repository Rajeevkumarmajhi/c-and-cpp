// Filename: access_specifiers.cpp

#include <iostream>
using namespace std;

// Base class to demonstrate access specifiers
class Person {
private:
    string ssn = "123-45-6789"; // Private: not accessible outside this class

protected:
    int age = 30;               // Protected: accessible in derived classes

public:
    string name = "John Doe";   // Public: accessible from anywhere

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age (accessible within class): " << age << endl;
        cout << "SSN (accessible within class): " << ssn << endl;
    }
};

// Derived class to show protected access
class Employee : public Person {
public:
    void showProtected() {
        cout << "Accessing protected age from derived class: " << age << endl;
        // cout << "SSN: " << ssn << endl; // ❌ Error: ssn is private in base
    }
};

int main() {
    Person personObj;
    Employee empObj;

    cout << "=== Access from main (outside class) ===" << endl;
    cout << "Name: " << personObj.name << endl; // ✅ Public member accessible

    // cout << "Age: " << personObj.age << endl; // ❌ Error: protected member
    // cout << "SSN: " << personObj.ssn << endl; // ❌ Error: private member

    cout << "\n=== Access from member function ===" << endl;
    personObj.displayInfo(); // ✅ All members accessible within class methods

    cout << "\n=== Access from derived class ===" << endl;
    empObj.showProtected(); // ✅ Accessing protected member from derived class

    return 0;
}
