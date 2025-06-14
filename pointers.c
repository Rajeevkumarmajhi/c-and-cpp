#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks[3]; // marks in 3 subjects
};

// Function using pointer to structure
void printStudent(struct Student *s) {
    printf("ID: %d\nName: %s\nMarks: %.2f, %.2f, %.2f\n",
           s->id, s->name, s->marks[0], s->marks[1], s->marks[2]);
}

// Function using pointer to calculate average
float calculateAverage(float *marks, int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += *(marks + i);
    }
    return total / size;
}

int main() {
    printf("=== Pointer Types and Mini Project Demo ===\n");

    // 1. Basic Pointer
    int x = 42;
    int *ptr = &x;
    printf("\nBasic Pointer:\nValue of x: %d, Address: %p, Access via pointer: %d\n", x, ptr, *ptr);

    // 2. NULL Pointer
    int *nullPtr = NULL;
    printf("\nNULL Pointer:\nAddress: %p\n", nullPtr);

    // 3. Void Pointer
    void *vptr;
    int y = 100;
    vptr = &y;
    printf("\nVoid Pointer:\nCan point to any type. y = %d\n", *(int *)vptr);

    // 4. Wild Pointer (Uninitialized) — dangerous
    int *wildPtr;
    // printf("%d", *wildPtr); // ⚠️ Uncommenting causes undefined behavior
    printf("\nWild Pointer:\nDeclared but uninitialized, accessing it is unsafe.\n");

    // 5. Pointer with Array
    int nums[5] = {1, 2, 3, 4, 5};
    int *nptr = nums;
    printf("\nPointer with Array:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(nptr + i));
    }
    printf("\n");

    // 6. Pointer with Array of Structures
    struct Student students[2] = {
        {1, "Alice", {85, 90, 88}},
        {2, "Bob",   {75, 70, 72}}
    };

    printf("\nPointer to Array of Structures:\n");
    for (int i = 0; i < 2; i++) {
        printStudent(&students[i]);
        float avg = calculateAverage(students[i].marks, 3);
        printf("Average: %.2f\n\n", avg);
    }

    return 0;
}
