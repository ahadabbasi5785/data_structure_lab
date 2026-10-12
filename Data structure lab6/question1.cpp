#include <iostream>
#include <string>
using namespace std;

class BrowserHistory {
private:
    string pages[10];
    int top;

public:
    BrowserHistory() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is Full!" << endl;
        } else {
            pages[++top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No history to go back!" << endl;
        } else {
            cout << "Back button pressed. Removed page: "
                 << pages[top] << endl;
            top--;
        }
    }

    void displayHistory() {
        if (top == -1) {
            cout << "Browsing history is empty." << endl;
            return;
        }

        cout << "Browsing History (TOP to Bottom):" << endl;

        for (int i = top; i >= 0; i--) {
            cout << pages[i] << endl;
        }
    }

    void displayTop() {
        if (top == -1) {
            cout << "No current page in history." << endl;
        } else {
            cout << "Current TOP page: " << pages[top] << endl;
        }
    }
};

int main() {
    BrowserHistory browser;

    browser.push("Google");
    browser.push("YouTube");
    browser.push("Facebook");
    browser.push("GitHub");

    browser.displayHistory();

    cout << endl;

    browser.pop();

    cout << endl;

    browser.displayTop();

    cout << endl;

    cout << "Remaining Browsing History:" << endl;
    browser.displayHistory();

    return 0;
}
