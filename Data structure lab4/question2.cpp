#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = NULL;
    }

    void addPatient(string patientID) {
        Node* newNode = new Node(patientID);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void displayPatients() {
        if (head == NULL) {
            cout << "No patients are waiting." << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->patientID;

            if (temp->next != NULL) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    void servePatient() {
        if (head == NULL) {
            cout << "No patients to serve." << endl;
            return;
        }

        Node* temp = head;

        cout << "Patient " << temp->patientID
             << " is being served." << endl;

        head = head->next;

        delete temp;
    }
};

int main() {
    PatientQueue queue;

    int n;
    string patientID;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Patient ID: ";
        cin >> patientID;

        queue.addPatient(patientID);
    }

    cout << "\nWaiting Patients:" << endl;
    queue.displayPatients();

    queue.servePatient();

    cout << "Updated Queue:" << endl;
    queue.displayPatients();

    return 0;
}

