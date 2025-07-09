#include <stdio.h>

// Call by reference example using pointer
void increment(int *x) {
    *x = *x + 1;
    printf("Inside increment (call by reference): %d\n", *x);
}

int main() {
    int num = 5;
    printf("Before increment: %d\n", num);
    increment(&num);  // Pass address to modify original
    printf("After increment: %d\n", num);  // Original modified
    return 0;
}
