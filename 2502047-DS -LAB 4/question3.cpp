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
}#include <iostream>
#include <string>
using namespace std;

class Course
{
public:
    string courseCode;
    string courseName;
    int creditHours;
    Course* next;

    Course(string code, string name, int hours)
    {
        courseCode = code;
        courseName = name;
        creditHours = hours;
        next = NULL;
    }
};

class CourseList
{
private:
    Course* head;

public:

    // Constructor
    CourseList()
    {
        head = NULL;
    }

    // 1. Add course at beginning
    void addAtBeginning(string code, string name, int hours)
    {
        Course* newCourse = new Course(code, name, hours);

        newCourse->next = head;
        head = newCourse;

        cout << "Course added at beginning successfully!" << endl;
    }

    // 2. Add course at end
    void addAtEnd(string code, string name, int hours)
    {
        Course* newCourse = new Course(code, name, hours);

        if (head == NULL)
        {
            head = newCourse;
        }
        else
        {
            Course* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newCourse;
        }

        cout << "Course added at end successfully!" << endl;
    }

    // 3. Search course
    void searchCourse(string code)
    {
        Course* temp = head;

        while (temp != NULL)
        {
            if (temp->courseCode == code)
            {
                cout << "\nCourse found!" << endl;
                cout << "Course Code: " << temp->courseCode << endl;
                cout << "Course Name: " << temp->courseName << endl;
                cout << "Credit Hours: " << temp->creditHours << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "Course not found." << endl;
    }

    // 4. Delete course
    void deleteCourse(string code)
    {
        if (head == NULL)
        {
            cout << "Course not found." << endl;
            return;
        }

        // If first course needs to be deleted
        if (head->courseCode == code)
        {
            Course* temp = head;

            head = head->next;

            delete temp;

            cout << "Course deleted successfully!" << endl;
            return;
        }

        Course* temp = head;

        while (temp->next != NULL &&
               temp->next->courseCode != code)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Course not found." << endl;
        }
        else
        {
            Course* deleteCourse = temp->next;

            temp->next = deleteCourse->next;

            delete deleteCourse;

            cout << "Course deleted successfully!" << endl;
        }
    }

    // 5. Display all courses
    void displayCourses()
    {
        if (head == NULL)
        {
            cout << "No courses available." << endl;
            return;
        }

        Course* temp = head;

        cout << "\n===== Course List =====" << endl;

        while (temp != NULL)
        {
            cout << "Course Code: " << temp->courseCode << endl;
            cout << "Course Name: " << temp->courseName << endl;
            cout << "Credit Hours: " << temp->creditHours << endl;
            cout << "------------------------" << endl;

            temp = temp->next;
        }
    }

    // 6. Count total courses
    int countCourses()
    {
        int count = 0;

        Course* temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // 7. Concatenate another course list
    void concatenate(CourseList& anotherList)
    {
        if (anotherList.head == NULL)
        {
            return;
        }

        if (head == NULL)
        {
            head = anotherList.head;
        }
        else
        {
            Course* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = anotherList.head;
        }

        // Prevent both lists from pointing to the same nodes
        anotherList.head = NULL;

        cout << "Course lists concatenated successfully!" << endl;
    }

    // Display only course codes
    void displayCourseCodes()
    {
        if (head == NULL)
        {
            cout << "Empty List";
            return;
        }

        Course* temp = head;

        while (temp != NULL)
        {
            cout << temp->courseCode;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    // Destructor
    ~CourseList()
    {
        Course* temp;

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
    CourseList morning;
    CourseList evening;

    int choice;
    int listChoice;
    string code;
    string name;
    int hours;

    do
    {
        cout << "\n========== UNIVERSITY COURSE MANAGEMENT ==========" << endl;
        cout << "1. Add Course at Beginning" << endl;
        cout << "2. Add Course at End" << endl;
        cout << "3. Search Course" << endl;
        cout << "4. Delete Course" << endl;
        cout << "5. Display All Courses" << endl;
        cout << "6. Count Total Courses" << endl;
        cout << "7. Concatenate Another Course List" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\nSelect List:" << endl;
            cout << "1. Morning Courses" << endl;
            cout << "2. Evening Courses" << endl;
            cout << "Enter choice: ";
            cin >> listChoice;

            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            getline(cin >> ws, name);

            cout << "Enter Credit Hours: ";
            cin >> hours;

            if (listChoice == 1)
            {
                morning.addAtBeginning(code, name, hours);
            }
            else if (listChoice == 2)
            {
                evening.addAtBeginning(code, name, hours);
            }
            else
            {
                cout << "Invalid list choice!" << endl;
            }

            break;


        case 2:

            cout << "\nSelect List:" << endl;
            cout << "1. Morning Courses" << endl;
            cout << "2. Evening Courses" << endl;
            cout << "Enter choice: ";
            cin >> listChoice;

            cout << "Enter Course Code: ";
            cin >> code;

            cout << "Enter Course Name: ";
            getline(cin >> ws, name);

            cout << "Enter Credit Hours: ";
            cin >> hours;

            if (listChoice == 1)
            {
                morning.addAtEnd(code, name, hours);
            }
            else if (listChoice == 2)
            {
                evening.addAtEnd(code, name, hours);
            }
            else
            {
                cout << "Invalid list choice!" << endl;
            }

            break;


        case 3:

            cout << "Enter Course Code to search: ";
            cin >> code;

            cout << "\nSearching Morning List:" << endl;
            morning.searchCourse(code);

            cout << "\nSearching Evening List:" << endl;
            evening.searchCourse(code);

            break;


        case 4:

            cout << "Enter Course Code to delete: ";
            cin >> code;

            cout << "\nDeleting from Morning List:" << endl;
            morning.deleteCourse(code);

            cout << "\nDeleting from Evening List:" << endl;
            evening.deleteCourse(code);

            break;


        case 5:

            cout << "\n===== MORNING COURSES =====" << endl;
            morning.displayCourses();

            cout << "\n===== EVENING COURSES =====" << endl;
            evening.displayCourses();

            break;


        case 6:

            cout << "\nTotal Morning Courses: "
                 << morning.countCourses() << endl;

            cout << "Total Evening Courses: "
                 << evening.countCourses() << endl;

            cout << "Total Courses: "
                 << morning.countCourses() + evening.countCourses()
                 << endl;

            break;


        case 7:

            cout << "\nBefore Concatenation:" << endl;

            cout << "Morning: ";
            morning.displayCourseCodes();

            cout << "Evening: ";
            evening.displayCourseCodes();

            morning.concatenate(evening);

            cout << "\nCombined Course List: ";
            morning.displayCourseCodes();

            break;


        case 8:

            cout << "Program ended." << endl;
            break;


        default:

            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
