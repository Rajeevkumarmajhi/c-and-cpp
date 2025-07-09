#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "=== C++ Control Statement Demo ===" << endl;
    cout << "1. Conditional\n2. Loop\n3. Jump\nChoose category: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int marks;
            cout << "\nEnter your marks: ";
            cin >> marks;

            if (marks >= 90)
                cout << "Grade: A" << endl;
            else if (marks >= 75)
                cout << "Grade: B" << endl;
            else if (marks >= 50)
                cout << "Grade: C" << endl;
            else
                cout << "Grade: F" << endl;
            break;
        }

        case 2: {
            cout << "\nFor loop (1 to 5): ";
            for (int i = 1; i <= 5; i++) {
                cout << i << " ";
            }

            cout << "\nWhile loop (6 to 10): ";
            int i = 6;
            while (i <= 10) {
                cout << i << " ";
                i++;
            }

            cout << "\nDo-while loop (11 to 15): ";
            i = 11;
            do {
                cout << i << " ";
                i++;
            } while (i <= 15);
            cout << endl;
            break;
        }

        case 3: {
            cout << "\nJump Statements Demo:" << endl;

            cout << "Break Example: ";
            for (int i = 1; i <= 5; i++) {
                if (i == 3) break;
                cout << i << " ";
            }

            cout << "\nContinue Example: ";
            for (int i = 1; i <= 5; i++) {
                if (i == 3) continue;
                cout << i << " ";
            }

            cout << "\nGoto Example: ";
            goto skip;

            cout << "This will be skipped" << endl;
        skip:
            cout << "Jumped using goto!" << endl;
            break;
        }

        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
