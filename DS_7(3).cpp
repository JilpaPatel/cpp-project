//Doubly circular link list

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
    struct node *last;

    cout << "Enter value: ";
    cin >> x;

    t = create_node(x);

    if(first == NULL)
    {
        first = t;

        t->next = first;
        t->prev = first;
    }
    else
    {
        last = first->prev;

        t->next = first;
        t->prev = last;

        last->next = t;
        first->prev = t;

        first = t;
    }
}


void insert_last()
{
    int x;
    struct node *t;
    struct node *last;

    cout << "Enter value: ";
    cin >> x;

    t = create_node(x);

    if(first == NULL)
    {
        first = t;

        t->next = first;
        t->prev = first;
    }
    else
    {
        last = first->prev;

        t->next = first;
        t->prev = last;

        last->next = t;
        first->prev = t;
    }
}


void insert_position()
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
        cout << "Invalid position." << endl;
        return;
    }

    t = create_node(x);

    if(first == NULL)
    {
        if(pos == 1)
        {
            first = t;

            t->next = first;
            t->prev = first;
        }
        else
        {
            cout << "Invalid position." << endl;
            delete t;
        }

        return;
    }

    if(pos == 1)
    {
        struct node *last = first->prev;

        t->next = first;
        t->prev = last;

        last->next = t;
        first->prev = t;

        first = t;

        return;
    }

    temp = first;

    for(i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if(temp == first)
        {
            cout << "Invalid position." << endl;
            delete t;
            return;
        }
    }

    t->next = temp->next;
    t->prev = temp;

    temp->next->prev = t;
    temp->next = t;
}


void delete_first()
{
    struct node *last;
    struct node *t;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if(first->next == first)
    {
        delete first;
        first = NULL;
    }
    else
    {
        last = first->prev;
        t = first;

        first = first->next;

        first->prev = last;
        last->next = first;

        delete t;
    }
}


void delete_last()
{
    struct node *last;
    struct node *second_last;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if(first->next == first)
    {
        delete first;
        first = NULL;
    }
    else
    {
        last = first->prev;
        second_last = last->prev;

        second_last->next = first;
        first->prev = second_last;

        delete last;
    }
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
        return;
    }

    temp = first;

    for(i = 1; i < pos; i++)
    {
        temp = temp->next;

        if(temp == first)
        {
            cout << "Invalid position." << endl;
            return;
        }
    }

    t = temp;

    t->prev->next = t->next;
    t->next->prev = t->prev;

    delete t;
}


void display_forward()
{
    struct node *temp;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    temp = first;

    cout << "Doubly Circular Linked List: ";

    do
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    while(temp != first);

    cout << endl;
}


void display_backward()
{
    struct node *temp;
    struct node *last;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    last = first->prev;
    temp = last;

    cout << "Doubly Circular Linked List: ";

    do
    {
        cout << temp->info << " ";
        temp = temp->prev;
    }
    while(temp != last);

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