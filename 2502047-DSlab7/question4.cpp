#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
private:
    int requests[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }
    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! No space available.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        requests[front] = id;
        count++;

        cout << "Request " << id << " inserted at the front.\n";
    }

    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque Overflow! No space available.\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        requests[rear] = id;
        count++;

        cout << "Request " << id << " inserted at the rear.\n";
    }

    void deleteFront() {
        if (count == 0) {
            cout << "Deque Underflow! No requests available.\n";
            return;
        }

        cout << "Request " << requests[front]
             << " removed from the front.\n";

        if (count == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        count--;
    }
    void deleteRear() {
        if (count == 0) {
            cout << "Deque Underflow! No requests available.\n";
            return;
        }

        cout << "Request " << requests[rear]
             << " removed from the rear.\n";

        if (count == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }

        count--;
    }
    void display() {
        if (count == 0) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Requests from front to rear: ";

        int i = front;

        for (int j = 0; j < count; j++) {
            cout << requests[i] << " ";
            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, id;

    do {
        cout << "\n--- Train Station Passenger Management ---\n";
        cout << "1. Insert Request at Front\n";
        cout << "2. Insert Request at Rear\n";
        cout << "3. Remove Request from Front\n";
        cout << "4. Remove Request from Rear\n";
        cout << "5. Display All Requests\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter passenger request ID: ";
            cin >> id;
            d.insertFront(id);
        }
        else if (choice == 2) {
            cout << "Enter passenger request ID: ";
            cin >> id;
            d.insertRear(id);
        }
        else if (choice == 3) {
            d.deleteFront();
        }
        else if (choice == 4) {
            d.deleteRear();
        }
        else if (choice == 5) {
            d.display();
        }
        else if (choice == 6) {
            cout << "Exiting the system.\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
