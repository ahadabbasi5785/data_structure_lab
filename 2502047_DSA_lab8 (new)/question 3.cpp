#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string folder;
    Node* left;
    Node* right;

    Node(string f)
    {
    folder = f;
    left = NULL;
    right = NULL;
    }
};
void inorder(Node* root){
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->folder << " ";

    inorder(root->right);
}

void preorder(Node* root){
    if (root == NULL)
        return;

    cout << root->folder << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if (root == NULL)
        return;

    postorder(root->left);

    postorder(root->right);

    cout << root->folder << " ";
}

int main(){
    Node* root = new Node("C Drive");

    root->left = new Node("Documents");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Notes");

    root->right->left = new Node("Vacations");
    root->right->right = new Node("Screenshots");

    cout << "COMPUTER FILE EXPLORER" << endl;
    cout << "========================" << endl;

    cout << "In-order Traversal: ";
    inorder(root);

    cout << endl;

    cout << "Pre-order Traversal: ";
    preorder(root);

    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}

