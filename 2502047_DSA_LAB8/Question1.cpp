
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string personName) {
        name = personName;
        left = NULL;
        right = NULL;
    }
};

int main() {
    // Creating seven family members
    Node* grandfather = new Node("Grandfather");
    Node* grandmother = new Node("Grandmother");
    Node* father = new Node("Father");
    Node* aunt = new Node("Aunt");
    Node* brother = new Node("Brother");
    Node* sister = new Node("Sister");
    Node* cousin = new Node("Cousin");

    // Connecting parent and child nodes
    grandfather->left = grandmother;
    grandfather->right = father;

    grandmother->left = aunt;
    grandmother->right = brother;

    father->left = sister;
    father->right = cousin;

    // Displaying the tree information
    Node* people[] = {
        grandfather, grandmother, father,
        aunt, brother, sister, cousin
    };

    for (int i = 0; i < 7; i++) {
        cout << "Person: " << people[i]->name;

        if (people[i]->left != NULL)
            cout << " | Left child: " << people[i]->left->name;
        else
            cout << " | Left child: None";

        if (people[i]->right != NULL)
            cout << " | Right child: " << people[i]->right->name;
        else
            cout << " | Right child: None";

        cout << endl;
    }

    return 0;
}

