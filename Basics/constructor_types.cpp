#include <iostream>
#include <cstring>

class Student {
private:
    char* name;
    int age;

public:
    // 1. Default Constructor
    Student() {
        name = new char[8];
        strcpy(name, "Unknown");
        age = 0;
        std::cout << "[Default Constructor] Student created.\n";
    }

    // 2. Parameterized Constructor
    Student(const char* nameInput, int ageInput) {
        name = new char[strlen(nameInput) + 1];
        strcpy(name, nameInput);
        age = ageInput;
        std::cout << "[Parameterized Constructor] Student created: " << name << ", Age: " << age << "\n";
    }

    // 3. Copy Constructor
    Student(const Student& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        std::cout << "[Copy Constructor] Copied student: " << name << "\n";
    }

    // 4. Destructor
    ~Student() {
        std::cout << "[Destructor] Deleting student: " << name << "\n";
        delete[] name; // release dynamically allocated memory
    }

    void show() const {
        std::cout << "Student: " << name << ", Age: " << age << "\n";
    }
};

// Function demonstrating dynamic memory allocation using new/delete
void demoDynamicAllocation() {
    std::cout << "\n--- Dynamic Allocation Demo ---\n";
    Student* s1 = new Student("Ram", 21); // new operator
    s1->show();
    delete s1; // delete operator
}

int main() {
    std::cout << "\n--- Constructor Types Demo ---\n";

    Student s1; // Default constructor
    s1.show();

    Student s2("Shyam", 20); // Parameterized constructor
    s2.show();

    Student s3 = s2; // Copy constructor
    s3.show();

    demoDynamicAllocation(); // dynamic memory allocation demo

    std::cout << "\n--- Program End ---\n";
    return 0;
}
