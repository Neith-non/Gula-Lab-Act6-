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
    cin>>newStudent.name;
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
    bool repeat=true;
    do {
        displayMenu();
        cin >> choice;
        system("cls");

        switch(choice) {
            case 1:
            cout << "\n---Add Studen---\n";
                addStudent();
                repeat=true;
                break;
            case 2:
            cout << "\n---Edit Student---\n";
                editStudent();
                repeat=true;
                break;
            case 3:
            cout << "\n---Delete Student---\n";
                deleteStudent();
                repeat=true;
                break;
            case 4:
            cout << "\n---View Student:---n";
                viewStudents();
                repeat=true;
                break;
            case 5:
                cout << "Exiting program...\n";
                repeat=false;
                break;
            default:
                cout << "Invalid option!\n";
        }
      
    }while(repeat==true);

}