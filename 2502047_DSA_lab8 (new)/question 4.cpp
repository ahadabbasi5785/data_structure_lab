
#include <iostream>
using namespace std;


class Node
{
public:
    int token;
    int height;

    Node* left;
    Node* right;

    Node(int value)
    {
        token = value;
        height = 1;

        left = NULL;
        right = NULL;
    }
};


int getHeight(Node* node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

int maximum(int a, int b)
{
    if (a > b)
        return a;

    return b;
}
int getBalance(Node* node)
{
    if (node == NULL)
        return 0;

    return getHeight(node->left) -
           getHeight(node->right);
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maximum(
        getHeight(y->left),
        getHeight(y->right));

    x->height = 1 + maximum(
        getHeight(x->left),
        getHeight(x->right));

    return x;
}
Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;

    x->height = 1 + maximum(
        getHeight(x->left),
        getHeight(x->right));

    y->height = 1 + maximum(
        getHeight(y->left),
        getHeight(y->right));

    return y;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (value < root->token)
        root->left = insert(root->left, value);

    else if (value > root->token)
        root->right = insert(root->right, value);

    else
        return root;
    root->height = 1 + maximum(
        getHeight(root->left),
        getHeight(root->right));
    int balance = getBalance(root);
    
    if (balance > 1 &&
        value < root->left->token)
    {
        cout << "LL Rotation at "
             << root->token << endl;

        return rightRotate(root);
    }

    if (balance < -1 &&
        value > root->right->token)
    {
        cout << "RR Rotation at "
             << root->token << endl;

        return leftRotate(root);
    }
    if (balance > 1 &&
        value > root->left->token)
    {
        cout << "LR Rotation at "
             << root->token << endl;

        root->left = leftRotate(root->left);

        return rightRotate(root);
    }
    if (balance < -1 &&
        value < root->right->token)
    {
        cout << "RL Rotation at "
             << root->token << endl;

        root->right = rightRotate(root->right);

        return leftRotate(root);
    }

    return root;
}
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->token << " ";

    inorder(root->right);
}
void displayTree(Node* root, int space)
{
    if (root == NULL)
        return;

    space = space + 5;

    displayTree(root->right, space);

    cout << endl;

    for (int i = 5; i < space; i++)
        cout << " ";

    cout << root->token << endl;

    displayTree(root->left, space);
}
void displayBalance(Node* root)
{
    if (root == NULL)
        return;

    displayBalance(root->left);

    cout << "Token: " << root->token
         << " | Height: " << root->height
         << " | Balance Factor: "
         << getBalance(root) << endl;

    displayBalance(root->right);
}

int main()
{
    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    int size = 7;

    cout << "HOSPITAL APPOINTMENT AVL TREE"<< endl;

    cout << "=============================="<< endl;
    for (int i = 0; i < size; i++)
    {
        cout << "\nInserting: " << tokens[i] << endl;

        root = insert(root, tokens[i]);
    }

    cout << "\nIn-order Traversal: ";

    inorder(root);

    cout << endl;
    cout << "\nNode Heights and Balance Factors:"<< endl;

    displayBalance(root);

    cout << "\nFinal Balanced AVL Tree:"<< endl;

    displayTree(root, 0);

    return 0;
}

