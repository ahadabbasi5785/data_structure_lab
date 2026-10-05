#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name)
    {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    Node* n1 = new Node("Image1.jpg");
    Node* n2 = new Node("Image2.jpg");
    Node* n3 = new Node("Image3.jpg");
    Node* n4 = new Node("Image4.jpg");
    Node* n5 = new Node("Image5.jpg");

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
    
    cout << "Images (First -> Last):" << endl;

    Node* current = head;

    while (current != NULL)
    {
        cout << current->image << endl;
        current = current->next;
    }
    cout << "\nImages (Last -> First):" << endl;

    current = tail;

    while (current != NULL)
    {
        cout << current->image << endl;
        current = current->prev;
    }

    return 0;
}
