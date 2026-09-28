#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int rollNumber;
    Node* next;

    // Constructor
    Node(int roll) {
        rollNumber = roll;
        next = NULL;
    }
};

// Student List class
class StudentList {
private:
    Node* head;

public:
    // Constructor
    StudentList() {
        head = NULL;
    }

    // Add student at the end
    void addStudent(int rollNumber) {

        Node* newNode = new Node(rollNumber);

        // If list is empty
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Find the last node
        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Add new node at the end
        temp->next = newNode;
    }

    // Display all students
    void displayStudents() {

        if (head == NULL) {
            cout << "No students registered." << endl;
            return;
        }

        cout << "Registered Students: ";

        Node* temp = head;

        while (temp != NULL) {

            cout << temp->rollNumber;

            if (temp->next != NULL) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    // Search student
    void searchStudent(int rollNumber) {

        Node* temp = head;

        while (temp != NULL) {

            if (temp->rollNumber == rollNumber) {
                cout << "Student Found" << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Student Not Found" << endl;
    }
};

int main() {

    StudentList students;

    int n;
    int rollNumber;

    cout << "Enter number of students: ";
    cin >> n;

    // Add students
    for (int i = 0; i < n; i++) {

        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        students.addStudent(rollNumber);
    }

    // Display students
    cout << endl;
    students.displayStudents();

    // Search student
    cout << "\nEnter Roll Number to Search: ";
    cin >> rollNumber;

    students.searchStudent(rollNumber);

    return 0;
}

