#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;

    node(int val)
    {
        prev = NULL;
        data = val;
        next = NULL;
    }
};

node *pushAtend(node *&head, int data)
{
    node *newnode = new node(data);
    node *temp = head;
    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

node *pushAtbeging(node *&head, int data)
{
    node *newnode = new node(data);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;

    return head;
}

node *pushAtpos(node *&head, int data, int pos)
{
    pos = pos - 1;
    node *newnode = new node(data);
    node *temp = head;
    node *temp2 = NULL;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    temp2 = temp->next;
    temp->next = newnode;
    temp2->prev = newnode;
    newnode->next = temp2;
    newnode->prev = temp;

    return head;
}

node *popAtBeg(node *&head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

node *popAtEnd(node *&head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    node *temp2;
    while (temp->next != NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    return head;
}

node *popAtPos(node *&head, int pos)
{
    if (head == NULL)
        return head;
    node *temp = head;
    node *prevnode;
    while (pos != 1)
    {
        prevnode = temp;
        temp = temp->next;
        pos--;
    }
    prevnode->next = temp->next;
    temp->next->prev = prevnode;
    delete temp;
    return head;
}

void Display(node *head)
{
    if (head == NULL)
    {
        cout << "The list is Empty!";
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->";
        temp = temp->next;
    }
    cout << "NULL";
}

int main()
{

    node *head = NULL;
    int n, opt, opt2, val, position;
    cout << "Come on Programmers let's START :)" << endl;
    char ch;
    cout << "Do you Want to continue(y/n): ";
    cin >> ch;
    do
    {
        cout << "1. For Insertion.\n2. For Deletion\n3. For Display The List\nEnter Your Choice: ";
        cin >> opt;
        if (opt == 1)
        {
            // Insertion Code
            cout << "1. Insert at Start.\n2. Insert at End.\n3. Insert at a specific position.\n4. Display the list.\nChoose What you want: ";
            cin >> opt2;
            switch (opt2)
            {
            case 1:
                cout << "Enter the value: ";
                cin >> val;
                pushAtbeging(head, val);
                break;
            case 2:
                cout << "Enter the value: ";
                cin >> val;
                pushAtend(head, val);
                break;
            case 3:
                cout << "Enter the value: ";
                cin >> val;
                cout << "Enter Position: ";
                cin >> position;
                pushAtpos(head, val, position);
                break;

            default:
                cout << "OPPS! You entered invalid option" << endl;
                break;
            }
            cout << "\n\n";
        }

        else if (opt == 2)
        {
            // Deltetion Code
            cout << "1. Delete at Start.\n2. Delete at End.\n3. Delete at a specific position.\n4. Display the List.\nChoose What you want: ";
            cin >> opt2;
            switch (opt2)
            {
            case 1:
                // cout << "Enter the value: ";
                // cin >> val;
                popAtBeg(head);
                break;
            case 2:
                // cout << "Enter the value: ";
                // cin >> val;
                popAtEnd(head);
                break;
            case 3:
                cout << "Enter Position: ";
                cin >> position;
                popAtPos(head, position);
                break;

            default:
                cout << "OPPS! You entered invalid option" << endl;
                break;
            }

            cout << "\n\n";
        }

        else if (opt == 3)
        {
            Display(head);
            cout << endl
                 << endl;
        }

        else
        {
            cout << opt << " is not valid option. please try again." << endl
                 << endl;
        }

        cout << "Do you Want to continue(y/n): ";
        cin >> ch;
        /* code */
    } while (ch == 'y' || ch == 'Y');

    return 0;
}