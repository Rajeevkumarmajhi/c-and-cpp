#include <stdio.h>

// 1. No argument, no return
void greet() {
    printf("Hello! Welcome to the C Function Demo.\n");
}

// 2. With argument, no return
void printSquare(int x) {
    printf("Square of %d is %d\n", x, x * x);
}

// 3. No argument, returns value
int getFixedNumber() {
    return 42;
}

// 4. With argument and return
int add(int a, int b) {
    return a + b;
}

int main() {
    greet();

    int number;
    printf("Enter a number to square: ");
    scanf("%d", &number);
    printSquare(number);

    int fixed = getFixedNumber();
    printf("Fixed number returned: %d\n", fixed);

    int x, y;
    printf("Enter two numbers to add: ");
    scanf("%d %d", &x, &y);
    int sum = add(x, y);
    printf("Sum is: %d\n", sum);

    return 0;
}
