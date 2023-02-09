#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *pushAtEnd(node *&head, int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;

    return head;
}

node *pushAtBegin(node *&head, int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        return head = newnode;
    }

    node *temp = head;
    newnode->next = temp;
    head = newnode;

    return head;
}

node *pushAtpos(node *&head, int val, int index)
{
    node *newnode = new node(val);
    node *temp = head;
    index = index - 1;
    while (index != 1)
    {
        // cout << index;
        temp = temp->next;
        index--;
    }
    newnode->next = temp->next;
    temp->next = newnode;
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

node *popAtEnd(node *head)
{
    if (head == NULL)
        return head;
    node *temp = head;
    node *prev;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return head;
}

node *popAtPos(node *&head, int pos)
{
    if (pos == 0)
        return head;
    node *temp = head;
    node *prev;

    while (pos != 1)
    {
        prev = temp;
        temp = temp->next;
        pos--;
    }
    // temp->next = ;
    prev->next = temp->next;
    free(temp);
    // head = temp;
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
                pushAtBegin(head, val);
                break;
            case 2:
                cout << "Enter the value: ";
                cin >> val;
                pushAtEnd(head, val);
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