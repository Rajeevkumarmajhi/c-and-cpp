// Filename: member_function.cpp

#include <iostream>
using namespace std;

class Demo {
private:
    int value;

public:
    // 1. Constructor: initializes object
    Demo(int val = 0) {
        value = val;
        cout << "Constructor called with value = " << value << endl;
    }

    // 2. Regular Member Function (defined inside class)
    void setValue(int val) {
        value = val;
    }

    // 3. Regular Member Function (defined outside class)
    int getValue();

    // 4. Const Member Function (guarantees no data modification)
    void printValue() const {
        cout << "Const Function: Value = " << value << endl;
    }

    // 5. Static Member Function (no access to non-static data)
    static void showStaticMessage() {
        cout << "Static Function: Called without object instance." << endl;
    }

    // 6. Inline Function (defined inside class; suggested to inline by compiler)
    int square() {
        return value * value;
    }

    // 7. Friend Function (not a member, but has access to private members)
    friend void displayFriend(const Demo& obj);
};

// Outside class member function definition
int Demo::getValue() {
    return value;
}

// Friend function definition
void displayFriend(const Demo& obj) {
    cout << "Friend Function: Accessing private value = " << obj.value << endl;
}

// Main function to demonstrate all types
int main() {
    cout << "=== Member Function Demonstration ===\n" << endl;

    // Constructor demonstration
    Demo obj(10);

    // Regular member functions
    obj.setValue(20);
    cout << "getValue(): " << obj.getValue() << endl;

    // Const member function
    obj.printValue();

    // Static function (can be called without object)
    Demo::showStaticMessage();

    // Inline function
    cout << "square(): " << obj.square() << endl;

    // Friend function
    displayFriend(obj);

    return 0;
}
