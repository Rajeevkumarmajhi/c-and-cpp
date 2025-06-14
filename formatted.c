#include <stdio.h>

int main() {
    int age;
    float salary;

    printf("Enter your age and salary: ");
    scanf("%d %f", &age, &salary);  // Formatted input

    printf("You are %d years old and earn %.2f NRP.\n", age, salary); // Formatted output
    return 0;
}
