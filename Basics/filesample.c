#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "records.txt"

typedef struct {
    int id;
    char name[50];
} Record;

// Create (append new record)
void createRecord() {
    FILE *f = fopen(FILENAME, "a");
    if (!f) { perror("Error opening file"); return; }

    Record r;
    printf("Enter ID: ");
    scanf("%d", &r.id);
    printf("Enter Name: ");
    scanf("%s", r.name);

    fwrite(&r, sizeof(Record), 1, f);
    fclose(f);
    printf("Record added!\n");
}

// Read all records
void readRecords() {
    FILE *f = fopen(FILENAME, "r");
    if (!f) { perror("Error opening file"); return; }

    Record r;
    printf("\n--- Records ---\n");
    while (fread(&r, sizeof(Record), 1, f))
        printf("ID: %d, Name: %s\n", r.id, r.name);
    
    fclose(f);
}

// Update record by ID
void updateRecord() {
    FILE *f = fopen(FILENAME, "r+");
    if (!f) { perror("Error opening file"); return; }

    int id, found = 0;
    printf("Enter ID to update: ");
    scanf("%d", &id);

    Record r;
    while (fread(&r, sizeof(Record), 1, f)) {
        if (r.id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", r.name);
            fseek(f, -sizeof(Record), SEEK_CUR);
            fwrite(&r, sizeof(Record), 1, f);
            printf("Record updated.\n");
            break;
        }
    }

    if (!found) printf("Record not found.\n");
    fclose(f);
}

// Delete record by ID (rewrite file)
void deleteRecord() {
    FILE *f = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!f || !temp) { perror("Error opening file"); return; }

    int id, found = 0;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Record r;
    while (fread(&r, sizeof(Record), 1, f)) {
        if (r.id != id)
            fwrite(&r, sizeof(Record), 1, temp);
        else
            found = 1;
    }

    fclose(f);
    fclose(temp);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) printf("Record deleted.\n");
    else printf("Record not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createRecord(); break;
            case 2: readRecords(); break;
            case 3: updateRecord(); break;
            case 4: deleteRecord(); break;
        }
    } while (choice != 5);
    return 0;
}
