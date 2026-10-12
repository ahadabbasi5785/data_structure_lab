#include <iostream>
#include <string>
using namespace std;

class RestaurantStack {
private:
    struct Node {
        string orderID;
        Node* next;
    };

    Node* top;

public:
    RestaurantStack() {
        top = NULL;
    }

    void push(string id) {
        Node* newNode = new Node;
        newNode->orderID = id;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!" << endl;
        } else {
            Node* temp = top;
            cout << "Processed order: " << top->orderID << endl;
            top = top->next;
            delete temp;
        }
    }

    void displayOrders() {
        if (top == NULL) {
            cout << "No orders remaining." << endl;
            return;
        }

        Node* temp = top;

        while (temp != NULL) {
            cout << temp->orderID << endl;
            temp = temp->next;
        }
    }

    void displayTop() {
        if (top == NULL) {
            cout << "No TOP order available." << endl;
        } else {
            cout << "Current TOP order: " << top->orderID << endl;
        }
    }

    void isEmpty() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack is not empty." << endl;
        }
    }

    ~RestaurantStack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    RestaurantStack restaurant;

    restaurant.push("ORD-101");
    restaurant.push("ORD-102");
    restaurant.push("ORD-103");
    restaurant.push("ORD-104");

    cout << "Restaurant Orders (TOP to Bottom):" << endl;
    restaurant.displayOrders();

    cout << endl;

    restaurant.pop();
    restaurant.pop();

    cout << endl;

    restaurant.displayTop();

    cout << endl;

    cout << "Remaining Orders:" << endl;
    restaurant.displayOrders();

    cout << endl;

    restaurant.isEmpty();

    return 0;
}
