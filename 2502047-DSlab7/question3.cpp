#include <iostream>
using namespace std;

#define SIZE 5

class PriorityQueue {
private:
    int patientID[SIZE];
    int priority[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }
    void enqueue(int id, int p) {
        if (count == SIZE) {
            cout << "Queue Overflow! No space for new patients.\n";
            return;
        }

        patientID[count] = id;
        priority[count] = p;
        count++;

        cout << "Patient P" << id << " added successfully.\n";
    }
    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty! No patients to treat.\n";
            return;
        }

        int highest = 0;

        for (int i = 1; i < count; i++) {
            if (priority[i] < priority[highest]) {
                highest = i;
            }
        }

        cout << "Patient P" << patientID[highest]
             << " with priority " << priority[highest]
             << " is being treated.\n";

        for (int i = highest; i < count - 1; i++) {
            patientID[i] = patientID[i + 1];
            priority[i] = priority[i + 1];
        }

        count--;
    }
    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "\nWaiting Patients:\n";
        cout << "Patient ID\tPriority\n";

        for (int i = 0; i < count; i++) {
            cout << "P" << patientID[i]
                 << "\t\t" << priority[i] << endl;
        }
    }
};

int main() {
    PriorityQueue q;
    int choice, id, p;

    do {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Highest Priority Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter patient ID (e.g. 102): ";
            cin >> id;

            cout << "Enter priority (1 = highest): ";
            cin >> p;

            if (p < 1) {
                cout << "Invalid priority! Priority must be 1 or higher.\n";
            } else {
                q.enqueue(id, p);
            }
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.display();
        }
        else if (choice == 4) {
            cout << "Exiting the system.\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
