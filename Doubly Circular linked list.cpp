#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *previ;
};

struct node *HEAD = NULL;

void create()
{
    int i = 0, num;
    struct node *temp, *ptr;
    cout << "Enter number of nodes: " << endl;
    cin >> num;
    while (i < num)
    {
        temp = new (struct node[sizeof(struct node)]);
        cout << "Enter data  ";
        cin >> temp->data;
        temp->next = NULL;
        temp->previ = NULL;

        if (HEAD == NULL)
        {
            HEAD = temp;
            ptr = temp;
        }
        else
        {
            temp->previ = ptr;
            ptr->next = temp;
            ptr = temp;
        }
        temp->next = HEAD;
        HEAD->previ = temp;
        i++;
    }
}
void view()
{
    int choice;
    struct node *temp = HEAD;

    cout << "Press 1 to view in straigth order:" << endl
         << "Press 2 to view in reverse order:" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            cout << "The data is " << temp->data << endl;
            temp = temp->next;
        } while (temp != HEAD);
        break;
    case 2:
        do
        {
            temp = temp->previ;
            cout << temp->data << endl;
        } while (temp != HEAD);
        break;
    default:
        cout << "Invalid try agian!!!!!!!!!" << endl;
        view();
        break;
    }
}
void insertByIndex()
{
    struct node *temp = HEAD, *ptr;
    int index;
    ptr = new (struct node[sizeof(struct node)]);
    cout << "Enter data: ";
    cin >> ptr->data;
    cout << "Enter index: ";
    cin >> index;
    if (index == 1)
    {
        temp = temp->previ;
        temp->next = ptr;
        HEAD->previ = ptr;
        ptr->next = HEAD;
        ptr->previ = temp;
        HEAD = ptr;
    }
    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        ptr->previ = temp;
        temp->next = ptr;
        temp = ptr->next;
        temp->previ = ptr;
    }
}

void deletion()
{
    struct node *ptr = HEAD, *temp;
    int data;
    cout << "Enter the data you want to delete:" << endl;
    cin >> data;

    do
    {
        temp = ptr;
        ptr = ptr->next;
    } while (ptr->data != data && ptr != HEAD);
    temp->next = ptr->next;
    temp = ptr->next;
    temp->previ = ptr->previ;
    free(ptr);
    if (ptr == HEAD)
    {
        HEAD = temp;
    }
}

int main()
{
    int choice;
    cout << "Creating doubly circular linked list!!!!!" << endl;
    create();

    while (choice != 0)
    {
        cout << "Enter choice: " << endl
             << "1 to view" << endl
             << "2 to insert" << endl
             << "3 to delete" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            view();
            break;
        case 2:
            insertByIndex();
            break;
        case 3:
            deletion();
            break;
        default:
            break;
        }
    }
    return 0;
}