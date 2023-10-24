#include <iostream>
using namespace std;

// node declaration
struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)//printing all the elements
{
    while (ptr != NULL)
    {
        cout << "Data = "<< ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = new(struct Node[sizeof(struct Node)]);
    ptr->next = head;
    ptr->data = data;
    return ptr;
}


int main()
{
    // declaration
    struct Node *first;
    struct Node *second;
    struct Node *third;

    // memory allocation in heap
    first = new (struct Node[sizeof(struct Node)]);
    second = new (struct Node[sizeof(struct Node)]);
    third = new (struct Node[sizeof(struct Node)]);

    // linking nodes
    // setting value of first and linking it with second
    first->data = 7;
    first->next = second;
    // setting value of second and linking it with third
    second->data = 77;
    second->next = third;
    // setting value of third
    third->data = 777;
    third->next = NULL;

    // calling traversal function
    //traversal(first);

    //inserting an element before first
    first = insertAtFirst(first, 707);
    traversal(first);

    return 0;
}