//Double ended queue

#include<iostream>
using namespace std;
#define MAX 5

int dequeue[MAX];
int rear = -1;
int front = -1;

void insertion_front()
{
    int value;
    if(front == 0)
    {
        cout<<"Value can not inserted."<<endl;
    }
    else
    {
        cout<<"Enter the choice : "<<endl;
        cin>>value;
        
        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front--;
        }
        dequeue[front] = value;
        cout<<"Value inserted in the queue : "<<value<<endl;
    }
}

void insertion_rear()
{
    int value;
    if(rear == MAX-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        cout<<"Enter the value : "<<endl;
        cin>>value;
        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        dequeue[rear] = value;
        cout<<"Value inserted in the queue : "<<value<<endl;
    }
}

void deletetion_front()
{
    if(front==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Deleted value in the queue : "<<dequeue[front]<<endl;
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void deletion_rear()
{
    if(front == rear)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Deleted value in the queue : "<<dequeue[rear]<<endl;
        if(front==rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear--;
        }
    }
}

void full()
{
    if(rear == MAX -1)
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        cout<<"Queue is not full"<<endl;
    }
}

void empty()
{
    if(front == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout<<"1. Insertion front"<<endl;
        cout<<"2. Insertion rear"<<endl;
        cout<<"3. Deletion front"<<endl;
        cout<<"3. Deletion rear"<<endl;
        cout<<"Enter the choice : "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            insertion_front();
            break;

            case 2:
            insertion_rear();
            break;

            case 3:
            deletetion_front();
            break;

            case 4:
            deletion_rear();
            break;

            case 5:
            full();
            break;

            case 6:
            empty();
            break;

            default:
            cout<<"Invalid choice"<<endl;
        }
    } 
    while (choice!=7);
    return 0;
}
