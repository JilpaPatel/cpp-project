//Link list

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
    struct node *temp;

    temp = new node;

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
        first = t;
    else
    {
        t->next = first;
        first = t;
    }
}

void display()
{
    struct node *t;

    t = first;

    while(t != NULL)
    {
        cout << "Value : " << t->info << endl;
        t = t->next;
    }
}

void insert_last()
{
    int x;
    struct node *t;
    struct node *temp;

    cout << "Enter value: ";
    cin >> x;

    t = create_node(x);

    if(first == nullptr)
        first = t;
    else
    {
        temp = first;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = t;
    }
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

    t = create_node(x);

    if(pos == 1)
    {
        t->next = first;
        first = t;
    }
    else
    {
        temp = first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        t->next = temp->next;
        temp->next = t;
    }
}

void delete_first()
{
    struct node *t;

    if(first == nullptr)
    {
        cout << "List is empty";
    }
    else
    {
        t = first;
        first = first->next;
        delete t;

        cout << "Element deleted";
    }
}

void delete_last()
{
    struct node *t;
    struct node *temp;

    if(first == nullptr)
    {
        cout << "List is empty";
    }
    else if(first->next == nullptr)
    {
        t = first;
        first = nullptr;
        delete t;

        cout << "Element deleted";
    }
    else
    {
        temp = first;

        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        t = temp->next;
        temp->next = nullptr;
        delete t;

        cout << "Element deleted";
    }
}
void delete_anywhere()
{
    int pos, i;
    struct node *t;
    struct node *temp;

    cout << "Enter position: ";
    cin >> pos;

    if(first == nullptr)
    {
        cout << "List is empty";
    }
    else if(pos == 1)
    {
        t = first;
        first = first->next;
        delete t;

        cout << "Element deleted";
    }
    else
    {
        temp = first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        t = temp->next;
        temp->next = t->next;
        delete t;

        cout << "Element deleted";
    }
}


int main()
{
    int choice;
    do
    {
        cout<<"1. Insert at First"<<endl;
        cout<<"2. Insert at last"<<endl;
        cout<<"3. Insert a anywhere"<<endl;
        cout<<"4. Delete at first"<<endl;
        cout<<"5. Delete at last"<<endl;
        cout<<"6. Delete from anywhere"<<endl;
        cout<<"7. Display"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<"Enter your choice: "<<endl;
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
                insert_anywhere();
                break;

            case 4:
                delete_first();
                break;
               
            case 5:
                delete_last();
                break;
                
            case 6:
                delete_anywhere();
                break;
                
            case 7:
                display();
                break;
                
            case 8:
                cout<<"Exit from the code"<<endl;
                break;
                
            default:
                cout << "Invalid choice!";
        }

    }
    while(choice != 9);

    return 0;
}
