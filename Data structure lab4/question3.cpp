#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string productID;
    Node* next;

    Node(string id) {
        productID = id;
        next = NULL;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() {
        head = NULL;
    }

    void addProduct(string id) {
        Node* newNode = new Node(id);

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

    void displayCart() {
        if (head == NULL) {
            cout << "Shopping Cart is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->productID;

            if (temp->next != NULL) {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    void removeProduct(string id) {
        if (head == NULL) {
            cout << "Shopping Cart is empty." << endl;
            return;
        }

        if (head->productID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->productID != id) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Product " << id << " not found." << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
    }
};

int main() {
    ShoppingCart cart;

    int n;
    string productID;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Product ID: ";
        cin >> productID;
        cart.addProduct(productID);
    }

    cout << "\nShopping Cart:" << endl;
    cart.displayCart();

    cout << "\nRemove Product: ";
    cin >> productID;

    cart.removeProduct(productID);

    cout << "\nUpdated Cart:" << endl;
    cart.displayCart();

    return 0;
}

