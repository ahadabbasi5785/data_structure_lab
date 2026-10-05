#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string player;
    Node* next;

    Node(string name)
    {
        player = name;
        next = NULL;
    }
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    Node* n1 = new Node("Ali");
    Node* n2 = new Node("Ahmed");
    Node* n3 = new Node("Hamza");
    Node* n4 = new Node("Usman");
    Node* n5 = new Node("Bilal");

    head = n1;
    tail = n5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n5->next = head;

    cout << "Player Turns:" << endl;

    Node* current = head;

    for (int i = 0; i < 5; i++)
    {
        cout << current->player << "'s turn" << endl;
        current = current->next;
    }

    cout << "\nAfter the last player:" << endl;
    cout << current->player << "'s turn again" << endl;

    return 0;
}
