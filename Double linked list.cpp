#include <iostream>
using namespace std;

struct doubleLink
{
    int marks;
    int rollNumber;
    string name;
    char grade;
    struct doubleLink *next;
    struct doubleLink *previous;
};

struct doubleLink *head = NULL;
struct doubleLink *tail = NULL;

void create()
{
    struct doubleLink *ptr;
    int number;

    cout << "Enter number of nodes:" << endl;
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        ptr = new (struct doubleLink[sizeof(struct doubleLink)]);
        cout << "Enter roll number: " << endl;
        cin >> ptr->rollNumber;
        cout << "Enter name: " << endl;
        cin >> ptr->name;
        cout << "Enter grade: " << endl;
        cin >> ptr->grade;
        cout << "Enter marks:" << endl;
        cin >> ptr->marks;
        ptr->next = NULL;

        if (head == NULL)
        {
            ptr->previous = NULL;
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            ptr->previous = tail;
            tail = ptr;
        }
    }
}

void print()
{
    struct doubleLink *ptr;
    int inp;
    cout << "Type 1 to print the list in straight:" << endl
         << "Type 2 to print the list in reverse:" << endl;
    cin >> inp;

    if (inp == 1)
    {
        ptr = head;
        while (ptr != NULL)
        {
            cout << "Name is " << ptr->name << endl;
            cout << "Roll Number is " << ptr->rollNumber << endl;
            cout << "Marks are " << ptr->marks << endl;
            cout << "Grade is " << ptr->grade << endl
                 << endl;
            ptr = ptr->next;
        }
    }
    else if (inp == 2)
    {
        ptr = tail;
        while (ptr != NULL)
        {
            cout << "Name is " << ptr->name << endl
                 << "Roll Number is " << ptr->rollNumber << endl
                 << "Marks are " << ptr->marks << endl
                 << "Grade is " << ptr->grade << endl
                 << endl;
            ptr = ptr->previous;
        }
    }
    else
        cout << "Error:(";
}

void insert()
{
    struct doubleLink *ptr = head, *temp;
    int index;

    temp = new (struct doubleLink[sizeof(struct doubleLink)]);

    cout << "Enter the index where you want to insert:" << endl;
    cin >> index;

    cout << "Enter name: " << endl;
    cin >> temp->name;
    cout << "Enter roll number: " << endl;
    cin >> temp->rollNumber;
    cout << "Enter grade: " << endl;
    cin >> temp->grade;
    cout << "Enter marks: " << endl;
    cin >> temp->marks;

    temp->next = NULL;
    temp->previous = NULL;

    if (index == 1)
    {
        head->previous = temp;
        temp->next = head;
        temp->previous = NULL;
        head = temp;
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == tail)
        {
            tail->next = temp;
            temp->previous = tail;
            tail = temp;
        }
        else
        {
            temp->previous = ptr;
            temp->next = ptr->next;
            ptr->next = temp;
            ptr = temp->next;
            ptr->previous = temp;
        }
    }
}

void deletion()
{
    struct doubleLink *ptr = head, *temp;
    cout << "Enter roll number to delete:" << endl;
    int index;
    cin >> index;

    if(ptr->rollNumber == index)
    {
        head = head->next;
        head->previous = NULL;
        free(ptr);
    }
    while (ptr != tail && ptr->rollNumber != index)
    {
        temp = ptr;
        ptr = ptr->next;
    }

    if (ptr == tail)
    {
        tail = temp;
        temp->next = NULL;
        free(ptr);
    }
    else
    {
        temp->next = ptr->next;
        temp = ptr->next;
        temp->previous = ptr->previous;
        free(ptr);
    }
    
}
int main()
{
    int inp;
    cout << "Create node.....!" << endl;
    create();
    while (inp != 0)
    {
        cout << "Enter your choice:" << endl
             << "1 to print the list:" << endl
             << "2 to insert a node:" << endl
             << "3 to delete a node:" << endl;

        cin >> inp;

        switch (inp)
        {
        case 1:
            print();
            break;
        case 2:
            insert();
            break;
        case 3:
            deletion();
        default:
            break;
        }
    }

    return 0;
}