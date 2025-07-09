#include <stdio.h>

// Call by value example
void increment(int x) {
    x = x + 1;
    printf("Inside increment (call by value): %d\n", x);
}

int main() {
    int num = 5;
    printf("Before increment: %d\n", num);
    increment(num);  // Passes a copy
    printf("After increment: %d\n", num);  // Original unchanged
    return 0;
}
