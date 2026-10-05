#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string song;
    Node* next;

    Node(string name)
    {
        song = name;
        next = NULL;
    }
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    Node* n1 = new Node("straight up ");
    Node* n2 = new Node("misbehave");
    Node* n3 = new Node("headliner");
    Node* n4 = new Node("life goes on");
    Node* n5 = new Node("money 2X");

    head = n1;
    tail = n5;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n5->next = head;

    cout << "Playlist (One Round):" << endl;

    Node* current = head;

    for (int i = 0; i < 5; i++)
    {
        cout << current->song << endl;
        current = current->next;
    }

    cout << "\nPlaying Playlist for 2 Rounds:" << endl;

    current = head;

    for (int i = 0; i < 10; i++)
    {
        cout << "Playing: " << current->song << endl;
        current = current->next;
    }

    return 0;
}
