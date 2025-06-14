#include <stdio.h>

int main() {
    int choice;

    printf("=== C Control Statement Demo ===\n");
    printf("1. Conditional\n2. Loop\n3. Jump\nChoose category: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int marks;
            printf("\nEnter your marks: ");
            scanf("%d", &marks);

            if (marks >= 90) {
                printf("Grade: A\n");
            } else if (marks >= 75) {
                printf("Grade: B\n");
            } else if (marks >= 50) {
                printf("Grade: C\n");
            } else {
                printf("Grade: F\n");
            }
            break;
        }

        case 2: {
            printf("\nFor loop (1 to 5):\n");
            for (int i = 1; i <= 5; i++) {
                printf("%d ", i);
            }

            printf("\n\nWhile loop (6 to 10):\n");
            int i = 6;
            while (i <= 10) {
                printf("%d ", i);
                i++;
            }

            printf("\n\nDo-while loop (11 to 15):\n");
            i = 11;
            do {
                printf("%d ", i);
                i++;
            } while (i <= 15);

            printf("\n");
            break;
        }

        case 3: {
            printf("\nJump Statements Demo:\n");

            printf("Break Example:\n");
            for (int i = 1; i <= 5; i++) {
                if (i == 3) break;
                printf("%d ", i);
            }

            printf("\nContinue Example:\n");
            for (int i = 1; i <= 5; i++) {
                if (i == 3) continue;
                printf("%d ", i);
            }

            printf("\nGoto Example:\n");
            goto done;

            printf("This will be skipped\n");
        done:
            printf("Jumped using goto!\n");
            break;
        }

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
