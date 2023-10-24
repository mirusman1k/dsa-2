#include<iostream>

using namespace std;

struct myNode
{
    int total_size;
    int used_size;
    int *ptr;
};

// functions
void createNode(struct myNode *a)
{
    // memory allocation
    int tSize, uSize;
    cout << "Enter total size and number of elements to enter:" << endl;
    cin >> tSize >> uSize;
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = new int[tSize * sizeof(int)];

    // setting values
    int j = 1;
    for (int i = 0; i < a->used_size; i++)
    {

        cout << "Enter element number " << j << endl;
        cin >> a->ptr[i];
        j++;
    }
}

void show(struct myNode *a)
{
    cout << "Printing Node:" << endl;
    for (int i = 0; i < a->used_size; i++)
    {
        cout << a->ptr[i] << endl;
    }
}

void insertion(struct myNode *a)
{
    int element, index;
    cout << "Enter element and index:" << endl;
    cin >> element >> index;
    if (a->used_size >= a->total_size)
    {
        a->total_size++;
    }
    for (int i = (a->used_size) - 1; i >= index; i--)
    {
        a->ptr[i + 1] = a->ptr[i];
    }

    a->ptr[index] = element;
    (a->used_size) = (a->used_size + 1);
}

void deletion(struct myNode *a)
{
    int element;
    cout << "Enter the element to delete:" << endl;
    cin >> element;

    int i = 0;
    while (a->ptr[i] != element)
    {
        i++;
    }
    for (int j = i; j < a->used_size; j++)
    {
        a->ptr[i] = a->ptr[i + 1];
        i++;
    }
    a->used_size = a->used_size - 1;
}

void linearSearch(struct myNode *a)
{
    int element, flag = 0;
    cout << "Enter the element you want to search:" << endl;
    cin >> element;

    for (int i = 0; i < a->used_size; i++)
    {
        if (a->ptr[i] == element)
        {
            flag++;
        }
    }
    if (flag >= 1)
    {
        cout << "The element is present " << flag << " time in the node:)" << endl;
    }
    else
    {
        cout << "The element was not found in the node:(" << endl;
    }
}

void binarySearch(const myNode &list)
{
    int element,result;
    cout << "Enter the element you want to search: " << endl;
    cin >> element;
    int left = 0;
    int right = list.used_size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (list.ptr[mid] == element)
        {
            result = mid;
        }

        if (list.ptr[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (result == element)
    {
        cout << "element " << element << " not found :(" << endl;
    }
    else
    {
        cout << "element " << element << " is in the list :)" << endl;
    }
}

void bubbleSort(myNode &list)
{
    cout << "list is getting sorted....." << endl;
    int n = list.used_size;
    int *arr = list.ptr;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    // declaration
    struct myNode node;
    int choice;
    bool end = false;
    // creating and setting values
    cout << "Creating and setting values of myNode:" << endl;
    createNode(&node);
    while (end != true)
    {
        cout << "Enter your choice:" << endl
             << "1 to print the node" << endl
             << "2 to insert an elemnet" << endl
             << "3 to delete an element" << endl
             << "4 to perform a linear search" << endl
             << "5 to perform binary search" << endl
             << "6 to sort the node" << endl
             << "0 to end the task!" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
                show(&node);// printing elemnents
                break;
            case 2:
                insertion(&node);// inserting an element
                break;
            case 3:
                deletion(&node);// deleting an element
                break;
            case 4:
                linearSearch(&node);// linear search
                break;
            case 5:
                binarySearch(node); // binary search
                break;
            case 6:
                bubbleSort(node); // sorting
                break;
            case 0:
                end = true; // ending loop
                break;
            default:
                cout << "Invalid input try again!!!" << endl;
                break;
        }
    }
    return 0;
}