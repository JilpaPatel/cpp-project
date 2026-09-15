//Circular singly link list

#include <iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *first = NULL;

struct node* create_node(int x)
{
    node *temp = new node;

    temp->info = x;
    temp->next = NULL;

    return temp;
}


void insert_first()
{
    int x;
    struct node *t;

    cout << "Enter value: ";
    cin >> x;

    t = create_node(x);

    if(first == NULL)
    {
        first = t;
        t->next = first;
    }
    else
    {
        struct node *temp = first;

        while(temp->next != first)
        {
            temp = temp->next;
        }

        t->next = first;
        first = t;
        temp->next = first;
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
        t->next = first;
    }
    else
    {
        struct node *temp = first;

        while(temp->next != first)
        {
            temp = temp->next;
        }

        temp->next = t;
        t->next = first;
    }
}

void insert_position()
{
    int x, pos, i;
    struct node *t;

    cout << "Enter value: ";
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
            t->next = first;
        }
        else
        {
            cout << "Invalid position." << endl;
            delete t;
        }
    }
    
    if(pos == 1)
    {
        struct node *temp = first;

        while(temp->next != first)
        {
            temp = temp->next;
        }

        t->next = first;
        first = t;
        temp->next = first;

    }

    struct node *temp = first;

    for(i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if(temp == first)
        {
            cout << "Invalid position." << endl;
            delete t;
        }
    }

    t->next = temp->next;
    temp->next = t;
}

void delete_first()
{
    struct node *temp;
    struct node *t;
    
    if(first == NULL)
    {
        cout << "List is empty." << endl;
    }
    
    if(first->next == first)
    {
        delete first;
        first = NULL;
    }

    temp = first;

    while(temp->next != first)
    {
        temp = temp->next;
    }

    t = first;

    first = first->next;
    temp->next = first;

    delete t;
}


void delete_last()
{
    struct node *temp;
    struct node *t;
    
    if(first == NULL)
    {
        cout << "List is empty." << endl;
    }

    if(first->next == first)
    {
        delete first;
        first = NULL;
    }

    temp = first;
    
    while(temp->next->next != first)
    {
        temp = temp->next;
    }

    t = temp->next;

    temp->next = first;

    delete t;

}

void delete_position()
{
    int pos, i;
    struct node *temp;

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

    for(i = 1; i < pos - 1; i++)
    {
        temp = temp->next;

        if(temp == first)
        {
            cout << "Invalid position." << endl;
            return;
        }
    }

    struct node *t = temp->next;

    if(t == first)
    {
        cout << "Invalid position." << endl;
        return;
    }

    temp->next = t->next;

    delete t;

    cout << "Element deleted." << endl;
}

void display()
{
    struct node *temp;
    
    if(first == NULL)
    {
        cout << "List is empty." << endl;
    }

    temp = first;

    cout << "Circular Linked List: ";

    do
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    while(temp != first);

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
        cout << "7. Display" << endl;
        cout << "8. Exit" << endl;

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
                display();
                break;

            case 8:
                cout << "Exit from the program." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    }
    while(choice != 8);

    return 0;
}