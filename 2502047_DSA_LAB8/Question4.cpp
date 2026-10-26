
#include <iostream>
using namespace std;

class Node {
public:
    int employeeID;
    Node* left;
    Node* right;

    Node(int id) {
        employeeID = id;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* current, int id) {
        if (current == NULL) {
            return new Node(id);
        }

        if (id < current->employeeID) {
            current->left = insert(current->left, id);
        }
        else if (id > current->employeeID) {
            current->right = insert(current->right, id);
        }

        return current;
    }

    Node* findMin(Node* current) {
        while (current != NULL && current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    Node* deleteNode(Node* current, int id) {
        if (current == NULL) {
            return NULL;
        }

        if (id < current->employeeID) {
            current->left = deleteNode(current->left, id);
        }
        else if (id > current->employeeID) {
            current->right = deleteNode(current->right, id);
        }
        else {
            // Case 1: No children (leaf node)
            if (current->left == NULL &&
                current->right == NULL) {
                delete current;
                return NULL;
            }

            // Case 2: Only right child
            else if (current->left == NULL) {
                Node* temp = current->right;
                delete current;
                return temp;
            }

            // Case 2: Only left child
            else if (current->right == NULL) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            // Case 3: Two children
            else {
                Node* temp = findMin(current->right);

                current->employeeID = temp->employeeID;

                current->right = deleteNode(
                    current->right, temp->employeeID
                );
            }
        }

        return current;
    }

    void inOrder(Node* current) {
        if (current == NULL) {
            return;
        }

        inOrder(current->left);
        cout << current->employeeID << " ";
        inOrder(current->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int id) {
        root = insert(root, id);
    }

    void deleteEmployee(int id) {
        root = deleteNode(root, id);
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST company;

    // Insert the given employee IDs
    company.insert(50);
    company.insert(30);
    company.insert(70);
    company.insert(20);
    company.insert(40);
    company.insert(60);
    company.insert(80);

    int id;

    while (true) {
        cout << "\nCurrent employee IDs: ";
        company.display();

        cout << "Enter employee ID to delete (-1 to stop): ";
        cin >> id;

        if (id == -1) {
            break;
        }

        company.deleteEmployee(id);

        cout << "Employee list after deletion: ";
        company.display();
    }

    return 0;
}

