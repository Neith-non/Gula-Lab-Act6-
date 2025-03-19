#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int id;
    string name;
    float gpa;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "[1] Add Student\n";
    cout << "[2] Edit Student\n";
    cout << "[3] Delete Student\n";
    cout << "[4] View Student\n";
    cout << "[5] Exit Program\n";
    cout << "Select option: ";
}

bool isDuplicateID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) return true;
    }
    return false;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Error: Database full!\n";
        return;
    }

    Student newStudent;
    cout << "Enter Student ID: ";
    cin >> newStudent.id;
    
    if (isDuplicateID(newStudent.id)) {
        cout << "Error: Duplicate ID!\n";
        return;
    }

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter GPA: ";
    cin >> newStudent.gpa;

    students[studentCount++] = newStudent;
    cout << "Student added successfully!\n";
}

void editStudent() {
    if (studentCount == 0) {
        cout << "No records available!\n";
        return;
    }

    int id;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new GPA: ";
            cin >> students[i].gpa;
            cout << "Student updated successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    if (studentCount == 0) {
        cout << "No records available!\n";
        return;
    }

    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            // Shift elements to fill gap
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void sortByName() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].name > students[j + 1].name) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void sortByGPA() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].gpa > students[j + 1].gpa) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void viewStudents() {
    if (studentCount == 0) {
        cout << "No records available!\n";
        return;
    }

    int option;
    cout << "View Options:\n[1] Alphabetically\n[2] GPA\nSelect option: ";
    cin >> option;

    if (option == 1) {
        sortByName();
    } else if (option == 2) {
        sortByGPA();
    }

    cout << "\nStudent Records:\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id << "\nName: " << students[i].name 
             << "\nGPA: " << students[i].gpa << "\n\n";
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                viewStudents();
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid option!\n";
        }
        
        cin.ignore(1000, '\n');
        cout << "\nPress Enter to continue...";
        cin.get();
    } while (choice != 5);

    return 0;
}