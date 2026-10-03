#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;
    string attendance;
    Student* next;

    Student(int r, string n, string a)
    {
        rollNo = r;
        name = n;
        attendance = a;
        next = NULL;
    }
};

class AttendanceList
{
private:
    Student* head;

public:
    AttendanceList()
    {
        head = NULL;
    }
    void addStudent(int rollNo, string name, string attendance)
    {
        Student* newStudent = new Student(rollNo, name, attendance);

        if (head == NULL)
        {
            head = newStudent;
        }
        else
        {
            Student* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newStudent;
        }

        cout << "Student added successfully!" << endl;
    }
    void searchStudent(int rollNo)
    {
        Student* temp = head;

        while (temp != NULL)
        {
            if (temp->rollNo == rollNo)
            {
                cout << "\nStudent found!" << endl;
                cout << "Roll Number: " << temp->rollNo << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Attendance: " << temp->attendance << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "Student not found." << endl;
    }
    void deleteStudent(int rollNo)
    {
        if (head == NULL)
        {
            cout << "Student not found." << endl;
            return;
        }
        if (head->rollNo == rollNo)
        {
            Student* temp = head;
            head = head->next;

            delete temp;

            cout << "Student deleted successfully!" << endl;
            return;
        }

        Student* temp = head;

        while (temp->next != NULL &&
               temp->next->rollNo != rollNo)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Student not found." << endl;
        }
        else
        {
            Student* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            cout << "Student deleted successfully!" << endl;
        }
    }
    void displayStudents()
    {
        if (head == NULL)
        {
            cout << "No students in the attendance list." << endl;
            return;
        }

        Student* temp = head;

        cout << "\n===== Attendance List =====" << endl;

        while (temp != NULL)
        {
            cout << "Roll Number: " << temp->rollNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Attendance: " << temp->attendance << endl;
            cout << "------------------------" << endl;

            temp = temp->next;
        }
    }
    int countPresent()
    {
        int count = 0;

        Student* temp = head;

        while (temp != NULL)
        {
            if (temp->attendance == "Present" ||
                temp->attendance == "present")
            {
                count++;
            }

            temp = temp->next;
        }

        return count;
    }
    void finalAttendanceList()
    {
        cout << "\n===== FINAL ATTENDANCE LIST =====" << endl;

        displayStudents();

        cout << "Total Students Present: "
             << countPresent() << endl;
    }
    ~AttendanceList()
    {
        Student* temp;

        while (head != NULL)
        {
            temp = head;
            head = head->next;

            delete temp;
        }
    }
};

int main()
{
    AttendanceList list;

    int choice;
    int rollNo;
    string name;
    string attendance;

    do
    {
        cout << "\n===== UNIVERSITY ATTENDANCE SYSTEM =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display All Students" << endl;
        cout << "5. Count Students Present" << endl;
        cout << "6. Display Final Attendance List" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> rollNo;

            cout << "Enter Student Name: ";
            getline(cin >> ws, name);

            cout << "Enter Attendance (Present/Absent): ";
            cin >> attendance;

            list.addStudent(rollNo, name, attendance);
            break;

        case 2:
            cout << "Enter Roll Number to search: ";
            cin >> rollNo;

            list.searchStudent(rollNo);
            break;

        case 3:
            cout << "Enter Roll Number to delete: ";
            cin >> rollNo;

            list.deleteStudent(rollNo);
            break;

        case 4:
            list.displayStudents();
            break;

        case 5:
            cout << "Total Students Present: "
                 << list.countPresent() << endl;
            break;

        case 6:
            list.finalAttendanceList();
            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
