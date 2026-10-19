#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int customers[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow! No more space available.\n";
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        customers[rear] = token;

        cout << "Customer " << token << " added to the queue.\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Underflow! No customers waiting.\n";
            return;
        }

        cout << "Customer " << customers[front]
             << " has been served.\n";

        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Waiting customers: ";

        for (int i = front; i <= rear; i++) {
            cout << customers[i] << " ";
        }

        cout << endl;
    }

    void count() {
        if (front == -1) {
            cout << "Number of waiting customers: 0\n";
        } else {
            cout << "Number of waiting customers: "
                 << rear - front + 1 << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, token;

    do {
        cout << "\n--- Bank Customer Service System ---\n";
        cout << "1. Add Customer (Enqueue)\n";
        cout << "2. Serve Customer (Dequeue)\n";
        cout << "3. Display Waiting Customers\n";
        cout << "4. Count Waiting Customers\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter customer token number: ";
            cin >> token;
            q.enqueue(token);
        }
        else if (choice == 2) {
            q.dequeue();
        }
        else if (choice == 3) {
            q.display();
        }
        else if (choice == 4) {
            q.count();
        }
        else if (choice == 5) {
            cout << "Exiting the system.\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
