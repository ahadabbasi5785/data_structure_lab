#include <iostream>
#include <string>
using namespace std;

class Order
{
public:
    string orderID;
    string customerName;
    string foodItem;
    Order* next;

    Order(string id, string name, string food)
    {
        orderID = id;
        customerName = name;
        foodItem = food;
        next = NULL;
    }
};

class FoodDelivery
{
private:
    Order* head;

public:
    FoodDelivery()
    {
        head = NULL;
    }
    void addOrder(string id, string name, string food)
    {
        Order* newOrder = new Order(id, name, food);

        if (head == NULL)
        {
            head = newOrder;
        }
        else
        {
            Order* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newOrder;
        }

        cout << "Order added successfully!" << endl;
    }
    void displayOrders()
    {
        if (head == NULL)
        {
            cout << "No pending orders." << endl;
            return;
        }

        Order* temp = head;

        cout << "\n===== Pending Orders =====" << endl;

        while (temp != NULL)
        {
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Customer Name: " << temp->customerName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            cout << "------------------------" << endl;

            temp = temp->next;
        }
    }
    void searchOrder(string id)
    {
        Order* temp = head;

        while (temp != NULL)
        {
            if (temp->orderID == id)
            {
                cout << "\nOrder found!" << endl;
                cout << "Order ID: " << temp->orderID << endl;
                cout << "Customer Name: " << temp->customerName << endl;
                cout << "Food Item: " << temp->foodItem << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "Order not found." << endl;
    }
    void removeOrder(string id)
    {
        if (head == NULL)
        {
            cout << "Order not found." << endl;
            return;
        }
        if (head->orderID == id)
        {
            Order* temp = head;

            head = head->next;

            delete temp;

            cout << "Order delivered and removed successfully!" << endl;
            return;
        }

        Order* temp = head;

        while (temp->next != NULL &&
               temp->next->orderID != id)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Order not found." << endl;
        }
        else
        {
            Order* deleteOrder = temp->next;

            temp->next = deleteOrder->next;

            delete deleteOrder;

            cout << "Order delivered and removed successfully!" << endl;
        }
    }
    void addUrgentOrder(string id, string name, string food)
    {
        Order* newOrder = new Order(id, name, food);

        newOrder->next = head;

        head = newOrder;

        cout << "Urgent order added at the beginning!" << endl;
    }
    void displayUpdatedList()
    {
        if (head == NULL)
        {
            cout << "No pending orders." << endl;
            return;
        }

        Order* temp = head;

        cout << "\n===== Updated Pending Orders =====" << endl;

        while (temp != NULL)
        {
            cout << temp->orderID;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << " -> NULL" << endl;
    }
    ~FoodDelivery()
    {
        Order* temp;

        while (head != NULL)
        {
            temp = head;

            head = head->next;

            delete temp;
        }
    }
};

int main()
{
    FoodDelivery restaurant;

    int choice;
    string id;
    string name;
    string food;

    do
    {
        cout << "\n===== ONLINE FOOD DELIVERY SYSTEM =====" << endl;
        cout << "1. Add New Order" << endl;
        cout << "2. Display Pending Orders" << endl;
        cout << "3. Search Order" << endl;
        cout << "4. Remove Delivered Order" << endl;
        cout << "5. Add Urgent Order" << endl;
        cout << "6. Display Updated Order List" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Order ID: ";
            cin >> id;

            cout << "Enter Customer Name: ";
            getline(cin >> ws, name);

            cout << "Enter Food Item: ";
            getline(cin >> ws, food);

            restaurant.addOrder(id, name, food);
            break;

        case 2:
            restaurant.displayOrders();
            break;

        case 3:
            cout << "Enter Order ID to search: ";
            cin >> id;

            restaurant.searchOrder(id);
            break;

        case 4:
            cout << "Enter Order ID to remove: ";
            cin >> id;

            restaurant.removeOrder(id);
            break;

        case 5:
            cout << "Enter Urgent Order ID: ";
            cin >> id;

            cout << "Enter Customer Name: ";
            getline(cin >> ws, name);

            cout << "Enter Food Item: ";
            getline(cin >> ws, food);

            restaurant.addUrgentOrder(id, name, food);
            break;

        case 6:
            restaurant.displayUpdatedList();
            break;

        case 7:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
