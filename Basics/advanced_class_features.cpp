#include <iostream>
#include <string>

class College; // Forward declaration

class Student {
private:
    std::string name;
    int age;
    const int rollNo;               // Constant data member
    static int count;              // Static data member

public:
    // Constructor to initialize const member
    Student(std::string name, int age, int rollNo) : name(name), age(age), rollNo(rollNo) {
        count++; // update static member
        std::cout << "[Student Created] Roll No: " << rollNo << ", Name: " << name << "\n";
    }

    // Constant member function (doesn't modify any member variables)
    void display() const {
        std::cout << "Roll No: " << rollNo << ", Name: " << name << ", Age: " << age << "\n";
    }

    // Static function (can only access static members)
    static int getTotalStudents() {
        return count;
    }

    // Friend function
    friend void showStudentDetails(const Student& s);

    // Friend class
    friend class College;
};

// Define static member
int Student::count = 0;

// Friend function definition
void showStudentDetails(const Student& s) {
    std::cout << "[Friend Function] Accessing private data:\n";
    std::cout << "Name: " << s.name << ", Age: " << s.age << ", Roll: " << s.rollNo << "\n";
}

// Friend class definition
class College {
public:
    void announce(const Student& s) {
        std::cout << "[Friend Class: College]\n";
        std::cout << "Top Student: " << s.name << " (Roll No: " << s.rollNo << ")\n";
    }
};

int main() {
    std::cout << "--- Static / Const / Friend Demo ---\n";

    Student s1("Bikash", 20, 101);
    Student s2("Sita", 22, 102);

    s1.display();      // Constant function
    s2.display();

    std::cout << "\nTotal Students: " << Student::getTotalStudents() << "\n"; // Static function

    showStudentDetails(s1); // Friend function

    College c;
    c.announce(s2); // Friend class accessing private data

    return 0;
}
