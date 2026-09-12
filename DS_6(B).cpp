//stack using linklist

#include<iostream>
using namespace std;

struct node
{
    int info;
    struct node *next;
};

struct node *top = NULL;

struct node *create_node(int x)
{
    struct node *temp;
    temp = new node;
    temp->info = x;
    temp->next = NULL;
    return temp;
}

void push()
{
    int x;
    struct node *t;
    cout<<"Enter the value : "<<endl;
    cin>>x;
    t = create_node(x);
    t->next = top;
    top = t;
}

void pop()
{
    struct node *t;
    if(top==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        t = top;
        top = top->next;
        delete t;
    }
}

void display()
{
    struct node *t;
    if(top ==NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        t = top;
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
        cout<<"1. push"<<endl;
        cout<<"2. pop"<<endl;
        cout<<"3. display"<<endl;
        cout<<"Enter the choice : "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            push();
            break;
            
            case 2:
            pop();
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