#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int age;
    float salary;

    cout << "Enter your age and salary: ";
    cin >> age >> salary;

    cout << "You are " << age << " years old and earn Rs. "
         << fixed << setprecision(2) << salary << " NRP." << endl;

    return 0;
}
