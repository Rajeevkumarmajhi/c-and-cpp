#include <stdio.h>
#include <string.h>

// Function to reverse a string using array
void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Display elements of 2D array
void printMatrix(int matrix[2][3]) {
    printf("2D Array (Matrix):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // 1D Array: store 5 numbers
    int numbers[5] = {10, 20, 30, 40, 50};

    printf("Array Elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("Index %d: %d\n", i, numbers[i]);
    }

    // 2D Array
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printMatrix(matrix);

    // String array demo
    char name[100];
    printf("Enter a word to reverse: ");
    scanf("%s", name);
    printf("Reversed: ");
    reverseString(name);

    return 0;
}
