//Queue by using linklist

#include<iostream>
using namespace std;

struct node 
{
    int info;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *create_node(int x)
{
    struct node *temp;
    temp = new node;
    temp->info = x;
    temp->next = NULL;
    return temp;
}

void insertion()
{
    int x;
    struct node *t;
    cout<<"Enter the value : "<<endl;
    cin>>x;
    t = create_node(x);
    if(front == NULL)
    {
        front = t;
        rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

void deletion()
{
    struct node *t;
    if(front == NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        t = front;
        front = front->next;
        delete t;
        if(front == NULL)
        {
            rear = NULL;
        }
    }
}

void display()
{
    struct node *t;
    if(front == NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        t = front;
        while(t!=NULL)
        {
            cout<<"Value : "<<t->info<<endl;
            t = t->next;
        }
    }
}

int main()
{
    int choice;
    do
    {
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"Enter the choice :"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            insertion();
            break;
            
            case 2:
            deletion();
            break;
            
            case 3:
            display();
            break;
            
            default:
            cout<<"Invalid choice"<<endl;
        }
    }
    while(choice!=4);
    return 0;
}