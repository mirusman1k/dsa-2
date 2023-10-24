#include <iostream>
#include <cmath>

using namespace std;

// node templete
struct node
{
    int data;
    struct node *next;
};

// Global Head and tail pointer
struct node *head = NULL;
struct node *tail = NULL;

// function definations

void create() // creating list
{
    int n;
    struct node *temp;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        temp = new (struct node[sizeof(struct node)]);
        cout << "Enter data: ";
        cin >> temp->data;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}

void view() // printing function
{
    struct node *traverse = head;
    while (traverse != NULL)
    {
        cout << "Data = " << traverse->data << endl;
        traverse = traverse->next;
    }
}

void insertByIndex() // inserstion using index
{
    struct node *ptr, *temp;
    ptr = new (struct node[sizeof(struct node)]);

    int index;

    cout << "Enter the element you want to insert: ";
    cin >> ptr->data;

    cout << "Enter the place you want to insert: ";
    cin >> index;

    cout << "Inserting " << ptr->data << " at " << index << " index!!" << endl;

    if (index == 1)
    {
        ptr->next = head;
        head = ptr;
    }
    else
    {
        temp = head;
        for (int i = 0; i < index - 2; i++)
        {
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        if (temp == tail)
        {
            tail = ptr;
        }
    }
}

void insertByElement() // insertion after element
{
    struct node *ptr = head, *temp;

    cout << "Enter the element after you want to insert:" << endl;
    int element;
    cin >> element;

    while (ptr != NULL && ptr->data != element)
    {
        ptr = ptr->next;
    }

    temp = new (struct node[sizeof(struct node)]);

    cout << "Enter the element you want to insert:" << endl;
    cin >> temp->data;
    temp->next = ptr->next;
    ptr->next = temp;
    if (ptr == tail)
    {
        tail = ptr;
    }
}

void deletion() // deleting elements from list
{
    struct node *ptr, *temp;
    ptr = head;

    cout << "Enter element to delete:" << endl;
    int element;
    cin >> element;

    while (ptr != NULL && ptr->data != element)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    if (ptr == head)
    {
        head = head->next;
        free(ptr);
    }
    else
    {
        temp->next = ptr->next; // this step unlinkes the element from linked list
        free(ptr);
    }
}

void average() // finding average
{
    struct node *ptr = head;
    float average, sum = 0, number = 0;
    while (ptr != NULL)
    {
        sum = sum + ptr->data;
        number++;
        ptr = ptr->next;
    }
    average = sum / number;
    cout << "The average of the linked list = " << average << endl;
}

void bubbleSort() // bubble sorting the list
{
    struct node *current = head, *nextt = NULL;
    int temp;

    cout << "Sorting the list....." << endl;

    while (current != NULL)
    {
        // Node nextt will point to node next to current
        nextt = current->next;

        while (nextt != NULL)
        {
            // swapping
            if (current->data > nextt->data)
            {
                temp = current->data;
                current->data = nextt->data;
                nextt->data = temp;
            }
            nextt = nextt->next;
        }
        current = current->next;
    }
}

void primeCheck() // check for prime numbers in list
{
    struct node *ptr = head;

    while (ptr != NULL)
    {
        int flag = 0;

        if (ptr->data == 1)
        {
            cout << "1 is prime:)" << endl;
        }
        else if (ptr->data == 0)
        {
            cout << "0 is not a prime:(" << endl;
        }
        else
        {
            for (int i = 2; i < ptr->data; i++)
            {
                if (ptr->data % 2 == 0)
                {
                    flag++;
                }
            }
            if (flag == 0)
            {
                cout << ptr->data << " is a prime:)" << endl;
            }
            else
            {
                cout << ptr->data << " is not a prime:(" << endl;
            }
        }

        ptr = ptr->next;
    }
}

void variance_StandardDeviation() // variance and standard de
{
    struct node *ptr = head;
    float standardDeviation, variance, temp, squaredSum = 0, mean, sum = 0, number = 0;

    while (ptr != NULL) // mean
    {
        sum = sum + ptr->data;
        number++;
        ptr = ptr->next;
    }
    mean = sum / number;

    ptr = head;
    while (ptr != NULL) // variance
    {
        temp = (ptr->data - mean);
        squaredSum = squaredSum + pow(temp, 2);
        ptr = ptr->next;
    }
    variance = squaredSum / number;

    cout << "The variance of the node = " << variance << endl;

    standardDeviation = sqrt(variance); // standard deviation
    cout << "The standard deviation of the node = " << standardDeviation << endl;
}

void bigAndSmall() // finding biggest and smallest element in the node
{
    struct node *ptr = head;
    int big = 0, small = 999999999;
    while (ptr != NULL)
    {
        if (ptr->data > big)
        {
            big = ptr->data;
        }
        if (ptr->data < small)
        {
            small = ptr->data;
        }
        ptr = ptr->next;
    }
    cout << "The biggest node in the list is " << big << endl;
    cout << "The smallest node in the list is " << small << endl;
}

void reverse() // reversing the node
{
    struct node *previous = NULL;
    struct node *current = head;
    struct node *nexxt = NULL;
    tail = head;
    while (current != NULL)
    {
        nexxt = current->next;    // store the address of next in nexxt
        current->next = previous; // reverse the current node's pointer to point to the prev node
        previous = current;       // move the pointers one position ahead
        current = nexxt;          // same function
    }
    head = previous;
}

// main function
int main()
{
    int ch;
    cout << "Create a node......" << endl;
    create();
    while (ch != 0)
    {
        cout << "\nEnter your choice.....!" << endl
             << "1 to view a node:" << endl
             << "2 to insert a node by index:" << endl
             << "3 to insert a node by Element:" << endl
             << "4 to delete a node:" << endl
             << "5 to find average of the list:" << endl
             << "6 to sort the list:" << endl
             << "7 to check for primes:" << endl
             << "8 to find varaince and standard deviation:" << endl
             << "9 to find the biggest and smallest node:" << endl
             << "10 to find reverse the node:" << endl
             << "0 to end:" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            view();
            break;
        case 2:
            insertByIndex();
            break;
        case 3:
            insertByElement();
            break;
        case 4:
            deletion();
            break;
        case 5:
            average();
            break;
        case 6:
            bubbleSort();
            break;
        case 7:
            primeCheck();
            break;
        case 8:
            variance_StandardDeviation();
            break;
        case 9:
            bigAndSmall();
            break;
        case 10:
            reverse();
            break;
        default:
            cout << "Invalid argument:(\nTry again";
        }
    }

    return 0;
}