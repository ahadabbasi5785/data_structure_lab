
#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    Node* left;
    Node* right;

    Node(int value) {
        roll = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* current, int value) {
        if (current == NULL) {
            return new Node(value);
        }

        if (value < current->roll) {
            current->left = insert(current->left, value);
        }
        else if (value > current->roll) {
            current->right = insert(current->right, value);
        }

        return current;
    }

    void inOrder(Node* current) {
        if (current == NULL) {
            return;
        }

        inOrder(current->left);
        cout << current->roll << " ";
        inOrder(current->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void display() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // Insert the given roll numbers
    tree.insert(45);
    tree.insert(25);
    tree.insert(65);
    tree.insert(15);
    tree.insert(35);
    tree.insert(55);
    tree.insert(75);

    // Ask the user for two additional roll numbers
    int roll1, roll2;

    cout << "Enter first additional roll number: ";
    cin >> roll1;

    cout << "Enter second additional roll number: ";
    cin >> roll2;

    tree.insert(roll1);
    tree.insert(roll2);

    // Display roll numbers in ascending order
    cout << "\nRoll numbers in ascending order: ";
    tree.display();

    return 0;
}
