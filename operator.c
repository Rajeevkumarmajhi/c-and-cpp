#include <stdio.h>

// Function declaration
int calculateTotal(int a, int b);

int main() {
    // Variable declarations (Identifiers, Keywords, Constants)
    int x = 10;      // Constant 10
    int y = 20;      // Constant 20
    int result;

    // Arithmetic Operators
    result = x + y;

    // Relational and Logical Operators
    if (result > 25 && result < 50) {
        printf("Result (%d) is between 25 and 50\n", result);
    }

    // Unary Operator
    result++;  // result = result + 1

    // Bitwise Operator
    int bitwiseAnd = x & y;

    // Assignment Operators
    result += 5;  // result = result + 5

    // Conditional Operator (Ternary)
    int max = (x > y) ? x : y;

    // Function call
    int total = calculateTotal(x, y);

    // Output using string and character constants
    printf("Sum: %d, Total: %d, Max: %d, Bitwise AND: %d\n", result, total, max, bitwiseAnd);

    return 0;
}

// Function definition using operators
int calculateTotal(int a, int b) {
    return a * b;  // Multiplication operator
}
