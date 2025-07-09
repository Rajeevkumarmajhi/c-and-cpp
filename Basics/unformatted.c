#include <stdio.h>

int main() {
    char name[50];

    puts("Enter your name:");   // Unformatted output
    gets(name);                 // Unformatted input (⚠️ gets() is unsafe, use fgets instead)

    puts("Hello,");             
    puts(name);                 // Unformatted output
    return 0;
}
