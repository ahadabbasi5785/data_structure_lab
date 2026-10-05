#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name)
    {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    
    Node* n1 = new Node("Google.com");
    Node* n2 = new Node("YouTube.com");
    Node* n3 = new Node("Facebook.com");
    Node* n4 = new Node("Wikipedia.org");
    Node* n5 = new Node("GitHub.com");

    head = n1;
    tail = n5;

    n1->next = n2;
    n2->prev = n1;

    n2->next = n3;
    n3->prev = n2;

    n3->next = n4;
    n4->prev = n3;

    n4->next = n5;
    n5->prev = n4;

    cout << "Browser History (First -> Last):" << endl;

    Node* current = head;

    while (current != NULL)
    {
        cout << current->website << endl;
        current = current->next;
    }

    cout << "\nBrowser History (Last -> First):" << endl;

    current = tail;

    while (current != NULL)
    {
        cout << current->website << endl;
        current = current->prev;
    }

    return 0;
}
