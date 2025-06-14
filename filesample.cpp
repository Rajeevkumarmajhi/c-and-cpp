#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Record {
    int id;
    string name;
};

// Load all records from file
vector<Record> loadRecords() {
    vector<Record> records;
    ifstream in("records.txt");
    Record r;
    while (in >> r.id >> r.name)
        records.push_back(r);
    return records;
}

// Save all records to file
void saveRecords(const vector<Record>& records) {
    ofstream out("records.txt");
    for (auto r : records)
        out << r.id << " " << r.name << endl;
}

// Create
void createRecord() {
    Record r;
    cout << "Enter ID: ";
    cin >> r.id;
    cout << "Enter Name: ";
    cin >> r.name;
    ofstream out("records.txt", ios::app);
    out << r.id << " " << r.name << endl;
    cout << "Record added.\n";
}

// Read
void readRecords() {
    auto records = loadRecords();
    cout << "\n--- Records ---\n";
    for (auto r : records)
        cout << "ID: " << r.id << ", Name: " << r.name << endl;
}

// Update
void updateRecord() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    auto records = loadRecords();
    bool found = false;

    for (auto& r : records) {
        if (r.id == id) {
            cout << "Enter new name: ";
            cin >> r.name;
            found = true;
            break;
        }
    }

    if (found) {
        saveRecords(records);
        cout << "Record updated.\n";
    } else {
        cout << "Record not found.\n";
    }
}

// Delete
void deleteRecord() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    auto records = loadRecords();
    vector<Record> updated;

    bool found = false;
    for (auto r : records) {
        if (r.id != id)
            updated.push_back(r);
        else
            found = true;
    }

    if (found) {
        saveRecords(updated);
        cout << "Record deleted.\n";
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: createRecord(); break;
            case 2: readRecords(); break;
            case 3: updateRecord(); break;
            case 4: deleteRecord(); break;
        }
    } while (choice != 5);
    return 0;
}
