\\Cirular singly link list

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
    struct node *temp = new node;

    temp->info = x;
    temp->next = NULL;

    return temp;
}

void insert()
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

void delete_node()
{
    struct node *temp;
    struct node *t;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
    }
    
    else if(first->next == first)
    {
        t = first;
        first = NULL;

        delete t;

        cout << "Element deleted successfully." << endl;
    }

    else
    {
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
}

void display()
{
    node *temp;

    if(first == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
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
}

int main()
{
    int choice;
    
    do
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter the choice : "<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
            insert();
            break;
            
            case 2:
            delete_node();
            break;
            
            case 3:
            display();
            break;
            
            case 4:
            cout<<"Exit the code"<<endl;
            break;
            
            default:
            cout<<"Invalid choice"<<endl;
        }
    }
    while(choice!=5);
    return 0;
}