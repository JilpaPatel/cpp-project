//Doubly link list

#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *first = NULL;

struct node* create_node(int x)
{
    struct node *temp;

    temp = new node;

    temp->info = x;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}


void insert_first()
{
    int x;
    struct node *t;

    cout << "Enter the value: ";
    cin >> x;

    t = create_node(x);

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        t->next = first;
        first->prev = t;
        first = t;
    }
}

void insert_last()
{
    int x;
    struct node *t;

    cout << "Enter value: ";
    cin >> x;

    t = create_node(x);

    if(first == NULL)
    {
        first = t;
    }
    else
    {
        struct node *temp;
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = t;
        t->prev = temp;
    }
}

void insert_position()
{
    int x, pos, i;
    struct node *t;

    cout << "Enter the value: ";
    cin >> x;

    cout << "Enter position: ";
    cin >> pos;

    if(pos <= 0)
    {
        cout << "Invalid position." << endl;
    }

    t = create_node(x);

    if(first == NULL)
    {
        if(pos == 1)
        {
            first = t;
        }
        else
        {
            cout << "Invalid position." << endl;
            free(t); 
        }
    }

    if(pos == 1)
    {
        t->next = first;
        first->prev = t;
        first = t;
    }

    struct node *temp = first;

    for(i = 1; i < pos - 1; i++)
    {
        if(temp->next == NULL)
        {
            cout << "Invalid position." << endl;
            free(t);
        }

        temp = temp->next;
    }

    t->next = temp->next;
    t->prev = temp;

    if(temp->next != NULL)
    {
        temp->next->prev = t;
    }

    temp->next = t;
}

void delete_first()
{
    struct node *t;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    t = first;

    first = first->next;

    if(first != NULL)
    {
        first->prev = NULL;
    }

    free(t);
}


void delete_last()
{
    struct node *temp;
    struct node *t;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
    }

    temp = first;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    t = temp;

    if(temp->prev == NULL)
    {
        first = NULL;
    }
    else
    {
        temp->prev->next = NULL;
    }

    free(t);
}

void delete_position()
{
    int pos, i;
    struct node *temp;
    struct node *t;

    cout << "Enter position: ";
    cin >> pos;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if(pos <= 0)
    {
        cout << "Invalid position." << endl;
        return;
    }

    if(pos == 1)
    {
        delete_first();
    }

    temp = first;

    for(i = 1; i < pos; i++)
    {
        temp = temp->next;

        if(temp == NULL)
        {
            cout << "Invalid position." << endl;
        }
    }

    t = temp;

    if(t->next != NULL)
    {
        t->next->prev = t->prev;
    }

    if(t->prev != NULL)
    {
        t->prev->next = t->next;
    }

    free(t);
}

void display_forward()
{
    struct node *temp;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
    }

    temp = first;

    cout << "Doubly Linked List (Forward): ";

    while(temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }

    cout << endl;
}


void display_backward()
{
    struct node *temp;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    temp = first;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    cout << "Doubly Linked List (Backward): ";

    while(temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->prev;
    }

    cout << endl;
}


int main()
{
    int choice;

    do
    {
        cout << "1. Insert at First" << endl;
        cout << "2. Insert at Last" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete from First" << endl;
        cout << "5. Delete from Last" << endl;
        cout << "6. Delete from Position" << endl;
        cout << "7. Display Forward" << endl;
        cout << "8. Display Backward" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                insert_first();
                break;

            case 2:
                insert_last();
                break;

            case 3:
                insert_position();
                break;

            case 4:
                delete_first();
                break;

            case 5:
                delete_last();
                break;

            case 6:
                delete_position();
                break;

            case 7:
                display_forward();
                break;

            case 8:
                display_backward();
                break;

            case 9:
                cout << "Exit from the program." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    }
    while(choice != 9);

    return 0;
}
