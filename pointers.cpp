#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks[3];
};

// Function using pointer to structure
void printStudent(Student *s) {
    cout << "ID: " << s->id << "\nName: " << s->name
         << "\nMarks: " << s->marks[0] << ", " << s->marks[1] << ", " << s->marks[2] << endl;
}

// Function to calculate average using pointer
float calculateAverage(float *marks, int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += *(marks + i);
    }
    return total / size;
}

int main() {
    cout << "=== Pointer Types and Mini Project Demo ===\n";

    // 1. Basic Pointer
    int x = 10;
    int *ptr = &x;
    cout << "\nBasic Pointer:\nValue: " << x << ", Address: " << ptr << ", Via Pointer: " << *ptr << endl;

    // 2. NULL Pointer
    int *nullPtr = nullptr;
    cout << "\nNULL Pointer:\nAddress: " << nullPtr << endl;

    // 3. Void Pointer
    void *vptr;
    int y = 55;
    vptr = &y;
    cout << "\nVoid Pointer:\nPointing to y = " << *(int *)vptr << endl;

    // 4. Wild Pointer
    int *wildPtr; // Not initialized
    cout << "\nWild Pointer:\nDeclared but uninitialized. Don't dereference it!\n";

    // 5. Pointer with Array
    int arr[] = {10, 20, 30, 40, 50};
    int *aptr = arr;
    cout << "\nPointer with Array:\n";
    for (int i = 0; i < 5; i++) {
        cout << *(aptr + i) << " ";
    }
    cout << endl;

    // 6. Pointer to Array of Structures
    Student students[2] = {
        {1, "Rajeev", {88, 91, 87}},
        {2, "Kriti",  {75, 80, 79}}
    };

    cout << "\nPointer to Array of Structures:\n";
    for (int i = 0; i < 2; i++) {
        printStudent(&students[i]);
        float avg = calculateAverage(students[i].marks, 3);
        cout << "Average: " << avg << "\n\n";
    }

    return 0;
}
