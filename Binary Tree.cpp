#include <iostream>
using namespace std;

struct BinaryTree
{
    int data;
    struct BinaryTree *left;
    struct BinaryTree *right;
};

struct BinaryTree *create()
{
    struct BinaryTree *newNode;
    newNode = new (struct BinaryTree[sizeof(struct BinaryTree)]);

    cout << "Enter data--> ";
    cin >> newNode->data;
    newNode->left = NULL;
    newNode->right = NULL;

    int choice;
    cout << "0 for no node" << endl
         << "1 to enter left node" << endl
         << "2 to enter right node" << endl
         << "3 to enter both left and right node" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        newNode->left = create();
        break;
    case 2:
        newNode->right = create();
        break;
    case 3:
        cout << "Enter left node of " << newNode->data << endl;
        newNode->left = create();
        cout << "Enter right node of " << newNode->data << endl;
        newNode->right = create();
        break;
    case 0:
        break;
    default:
        cout << "Invalid input try again:(\n";
        break;
    }

    return newNode;
}

void insert()
{
}

void deletion(struct BinaryTree *root)
{
}

void preOrderTraversal(struct BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << "The data is " << root->data << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(struct BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << "The data is " << root->data << endl;
}

void inOrderTraversal(struct BinaryTree *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << "The data is " << root->data << endl;
    inOrderTraversal(root->right);
}

int main()
{
    int choice;
    struct BinaryTree *root = NULL;
    cout << "Creating Binary tree--->" << endl;
    root = create();
    while (choice != -1)
    {
        cout << "\nEnter choice--> " << endl
             << "1 to preOrderTraversal " << endl
             << "2 to postOrderTraversal " << endl
             << "3 to inOrderTraversal " << endl
             << "-1 to end " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            preOrderTraversal(root);
            break;
        case 2:
            postOrderTraversal(root);
            break;
        case 3:
            inOrderTraversal(root);
            break;
        case -1:
            cout << "Ending program bye";
            break;
        default:
            cout << "Invalid input try again!!!!";
            break;
        }
    }
    return 0;
}