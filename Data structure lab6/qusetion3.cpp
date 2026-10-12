#include <iostream>
#include <string>
using namespace std;

class HospitalStack {
private:
    struct Node {
        string patientID;
        Node* next;
    };

    Node* top;

public:
    HospitalStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node;
        newNode->patientID = id;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "No patient requests available!" << endl;
        } else {
            Node* temp = top;
            cout << "Handled patient request: "
                 << top->patientID << endl;
            top = top->next;
            delete temp;
        }
    }

    void displayRequests() {
        if (top == NULL) {
            cout << "No patient requests remaining." << endl;
            return;
        }

        Node* temp = top;

        while (temp != NULL) {
            cout << temp->patientID << endl;
            temp = temp->next;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "No TOP request available." << endl;
        } else {
            cout << "Current TOP request: "
                 << top->patientID << endl;
        }
    }

    ~HospitalStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    HospitalStack hospital;

    hospital.push("P101");
    hospital.push("P102");
    hospital.push("P103");
    hospital.push("P104");

    cout << "Patient Requests (TOP to Bottom):" << endl;
    hospital.displayRequests();

    cout << endl;

    hospital.pop();

    cout << endl;

    hospital.displayTop();

    cout << endl;

    cout << "Remaining Patient Requests:" << endl;
    hospital.displayRequests();

    return 0;
}
