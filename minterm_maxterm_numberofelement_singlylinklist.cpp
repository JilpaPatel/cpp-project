#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *first = NULL;

struct node *create_node(int x)
{
    struct node *temp;

    temp = new node;

    temp->info = x;
    temp->next = NULL;

    return temp;
}

void insert_anywhere()
{
    int x, pos, i;
    struct node *t;
    struct node *temp;

    cout << "Enter value: ";
    cin >> x;

    cout << "Enter position: ";
    cin >> pos;

    if(pos <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    t = create_node(x);

    if(pos == 1)
    {
        t->next = first;
        first = t;

        cout << "Element inserted successfully" << endl;
    }
    else
    {
        temp = first;

        for(i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Invalid position" << endl;
            delete t;
            return;
        }

        t->next = temp->next;
        temp->next = t;

        cout << "Element inserted successfully" << endl;
    }
}

void delete_anywhere()
{
    int pos, i;
    struct node *t;
    struct node *temp;

    if(first == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Enter position: ";
    cin >> pos;

    if(pos <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if(pos == 1)
    {
        t = first;
        first = first->next;

        delete t;

        cout << "Element deleted successfully" << endl;
    }
    else
    {
        temp = first;

        for(i = 1; i < pos - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL || temp->next == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }

        t = temp->next;
        temp->next = t->next;

        delete t;

        cout << "Element deleted successfully" << endl;
    }
}

void minterm()
{
    struct node *temp = first;

    if(first == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    int m = first->info;

    while(temp != NULL)
    {
        if(temp->info < m)
        {
            m = temp->info;
        }

        temp = temp->next;
    }

    cout << "Minimum element of the list: " << m << endl;
}

void maxterm()
{
    struct node *temp = first;

    if(first == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    int m = first->info;

    while(temp != NULL)
    {
        if(temp->info > m)
        {
            m = temp->info;
        }

        temp = temp->next;
    }

    cout << "Maximum element of the list: " << m << endl;
}

void element()
{
    struct node *temp = first;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total elements of the list: " << count << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Minimum element" << endl;
        cout << "4. Maximum element" << endl;
        cout << "5. Number of elements" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter the choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                insert_anywhere();
                break;

            case 2:
                delete_anywhere();
                break;

            case 3:
                minterm();
                break;

            case 4:
                maxterm();
                break;

            case 5:
                element();
                break;

            case 6:
                cout << "Exit from the code" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }

    } while(choice != 6);

    return 0;
}