
#include <iostream>
using namespace std;

class Node {
public:
    int bookID;
    Node* left;
    Node* right;

    Node(int id) {
        bookID = id;
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

        if (id < current->bookID) {
            current->left = insert(current->left, id);
        }
        else if (id > current->bookID) {
            current->right = insert(current->right, id);
        }

        return current;
    }

    bool search(Node* current, int id, int& comparisons) {
        if (current == NULL) {
            return false;
        }

        comparisons++;

        if (current->bookID == id) {
            return true;
        }
        else if (id < current->bookID) {
            return search(current->left, id, comparisons);
        }
        else {
            return search(current->right, id, comparisons);
        }
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int id) {
        root = insert(root, id);
    }

    void searchBook(int id) {
        int comparisons = 0;

        bool found = search(root, id, comparisons);

        if (found) {
            cout << "Book Found" << endl;
        }
        else {
            cout << "Book Not Found" << endl;
        }

        cout << "Number of comparisons: "
             << comparisons << endl;
    }
};

int main() {
    BST library;

    // Insert the given book IDs
    library.insert(40);
    library.insert(20);
    library.insert(60);
    library.insert(10);
    library.insert(30);
    library.insert(50);
    library.insert(70);

    // Search for a book ID
    int id;

    cout << "Enter book ID to search: ";
    cin >> id;

    library.searchBook(id);

    return 0;
}

