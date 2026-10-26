#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if(node == NULL)
            return new Node(value);

        if(value < node->data)
            node->left = insert(node->left, value);
        else if(value > node->data)
            node->right = insert(node->right, value);

        return node;
    }

    bool search(Node* node, int value) {
        if(node == NULL)
            return false;

        if(node->data == value)
            return true;

        if(value < node->data)
            return search(node->left, value);

        return search(node->right, value);
    }

    Node* findMin(Node* node) {
        while(node->left != NULL)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if(node == NULL)
            return NULL;

        if(value < node->data)
            node->left = deleteNode(node->left, value);
        else if(value > node->data)
            node->right = deleteNode(node->right, value);
        else {
            if(node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if(node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void inorder(Node* node) {
        if(node == NULL)
            return;

        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if(node == NULL)
            return;

        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if(node == NULL)
            return;

        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }

    void destroy(Node* node) {
        if(node == NULL)
            return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        destroy(root);
    }

    void insertValue(int value) {
        if(search(root, value)) {
            cout<<"Duplicate Product ID Not Allowed"<<endl;
            return;
        }

        root = insert(root, value);
        cout<<"Product Inserted Successfully"<<endl;
    }

    void searchValue(int value) {
        if(search(root, value))
            cout<<"Product Found"<<endl;
        else
            cout<<"Product Not Found"<<endl;
    }

    void deleteValue(int value) {
        if(!search(root, value)) {
            cout<<"Product Not Found"<<endl;
            return;
        }

        root = deleteNode(root, value);
        cout<<"Product Deleted Successfully"<<endl;
    }

    void displayInorder() {
        cout<<"In-order: ";
        inorder(root);
        cout<<endl;
    }

    void displayPreorder() {
        cout<<"Pre-order: ";
        preorder(root);
        cout<<endl;
    }

    void displayPostorder() {
        cout<<"Post-order: ";
        postorder(root);
        cout<<endl;
    }
};

int main() {
    BST tree;
    int choice,id;

    do {
        cout<<endl;
        cout<<"1. Insert Product ID"<<endl;
        cout<<"2. Search Product ID"<<endl;
        cout<<"3. Delete Product ID"<<endl;
        cout<<"4. Display In-order"<<endl;
        cout<<"5. Display Pre-order"<<endl;
        cout<<"6. Display Post-order"<<endl;
        cout<<"7. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter Product ID: ";
                cin>>id;
                tree.insertValue(id);
                break;

            case 2:
                cout<<"Enter Product ID to search: ";
                cin>>id;
                tree.searchValue(id);
                break;

            case 3:
                cout<<"Enter Product ID to delete: ";
                cin>>id;
                tree.deleteValue(id);
                break;

            case 4:
                tree.displayInorder();
                break;

            case 5:
                tree.displayPreorder();
                break;

            case 6:
                tree.displayPostorder();
                break;

            case 7:
                cout<<"Exiting Program"<<endl;
                break;

            default:
                cout<<"Invalid Choice"<<endl;
        }

    } while(choice != 7);

    return 0;
}

