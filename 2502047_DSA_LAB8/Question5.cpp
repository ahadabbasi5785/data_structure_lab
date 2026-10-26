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

class BinaryTree {
private:
    Node* root;

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
    BinaryTree() {
        root = NULL;
    }

    ~BinaryTree() {
        destroy(root);
    }

    void createTree() {
        root = new Node(40);
        root->left = new Node(20);
        root->right = new Node(60);
        root->left->left = new Node(10);
        root->left->right = new Node(30);
        root->right->left = new Node(50);
        root->right->right = new Node(70);
    }

    void showTraversals() {
        cout<<"In-order: ";
        inorder(root);

        cout<<endl<<"Pre-order: ";
        preorder(root);

        cout<<endl<<"Post-order: ";
        postorder(root);

        cout<<endl;
        cout<<"Ascending Order: In-order Traversal"<<endl;
    }
};

int main() {
    BinaryTree tree;

    tree.createTree();
    tree.showTraversals();

    return 0;
}

