#include <iostream>
#include <string>
using namespace std;

class TextEditor {
private:
    string actions[10];
    int top;

public:
    TextEditor() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is Full!" << endl;
        } else {
            actions[++top] = action;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No actions to undo!" << endl;
        } else {
            cout << "Undo action: " << actions[top] << endl;
            top--;
        }
    }

    void displayActions() {
        if (top == -1) {
            cout << "No actions remaining." << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << actions[i] << endl;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No current TOP action." << endl;
        } else {
            cout << "Current TOP action: " << actions[top] << endl;
        }
    }
};

int main() {
    TextEditor editor;

    editor.push("Type Hello");
    editor.push("Type World");
    editor.push("Add !");
    editor.push("Delete !");

    cout << "Actions (TOP to Bottom):" << endl;
    editor.displayActions();

    cout << endl;

    editor.pop();
    editor.pop();

    cout << endl;

    editor.displayTop();

    cout << endl;

    cout << "Remaining Actions:" << endl;
    editor.displayActions();

    return 0;
}

