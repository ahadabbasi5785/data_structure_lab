
#include <iostream>
#include <string>
using namespace std;

class Patient
{
public:
    int id;
    string name;
    int age;
    Patient* next;

    Patient(int i, string n, int a)
    {
        id = i;
        name = n;
        age = a;
        next = NULL;
    }
};

class Hospital
{
private:
    Patient* head;

public:
    Hospital()
    {
        head = NULL;
    }
    void addPatient(int id, string name, int age)
    {
        Patient* newPatient = new Patient(id, name, age);

        if (head == NULL)
        {
            head = newPatient;
        }
        else
        {
            Patient* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newPatient;
        }

        cout << "Patient added successfully!" << endl;
    }
    void addEmergencyPatient(int id, string name, int age)
    {
        Patient* newPatient = new Patient(id, name, age);

        newPatient->next = head;
        head = newPatient;

        cout << "Emergency patient added at the beginning!" << endl;
     } 
    void searchPatient(int id)
    {
        Patient* temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
            {
                cout << "Patient found!" << endl;
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Age: " << temp->age << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Patient does not exist!" << endl;
    }
    void removePatient(int id)
    {
        if (head == NULL)
        {
            cout << "No patients are waiting!" << endl;
            return;
        }

        if (head->id == id)
        {
            Patient* temp = head;
            head = head->next;
            delete temp;

            cout << "Patient removed successfully!" << endl;
            return;
        }

        Patient* temp = head;

        while (temp->next != NULL &&
               temp->next->id != id)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Patient does not exist!" << endl;
        }
        else
        {
            Patient* del = temp->next;
            temp->next = del->next;
            delete del;

            cout << "Patient removed successfully!" << endl;
        }
    }
    void displayPatients()
    {
        if (head == NULL)
        {
            cout << "No patients are waiting!" << endl;
            return;
        }

        Patient* temp = head;

        cout << "\n--- Waiting Patients ---" << endl;

        while (temp != NULL)
        {
            cout << "Patient ID: " << temp->id << endl;
            cout << "Patient Name: " << temp->name << endl;
            cout << "Patient Age: " << temp->age << endl;
            cout << "------------------------" << endl;

            temp = temp->next;
        }
    }
    ~Hospital()
    {
        Patient* temp;

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
    Hospital h;
    int choice, id, age;
    string name;

    do
    {
        cout << "\n===== Hospital Patient Management =====" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Add Emergency Patient" << endl;
        cout << "3. Search Patient" << endl;
        cout << "4. Remove Patient After Treatment" << endl;
        cout << "5. Display Waiting Patients" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            getline(cin >> ws, name);

            cout << "Enter Patient Age: ";
            cin >> age;

            h.addPatient(id, name, age);
            break;

        case 2:
            cout << "Enter Emergency Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            getline(cin >> ws, name);

            cout << "Enter Patient Age: ";
            cin >> age;

            h.addEmergencyPatient(id, name, age);
            break;

        case 3:
            cout << "Enter Patient ID to search: ";
            cin >> id;

            h.searchPatient(id);
            break;

        case 4:
            cout << "Enter Patient ID to remove: ";
            cin >> id;

            h.removePatient(id);
            break;

        case 5:
            h.displayPatients();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
