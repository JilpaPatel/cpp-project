//Circular queue

#include<iostream>
using namespace std;
#define size 5
int queue[size];
int front = -1;
int rear = -1;

void insertion()
{
    int value;
    if((rear+1) % size==front)
    {
        cout<<"Queue is full."<<endl;
    }
    else
    {
        cout<<"Enter the value : "<<endl;
        cin>>value;
        if(front == -1)
        {
            front=0;
        }
        rear = (rear+1) % size;
        queue[size] = value;
        cout<<value<<"Value inserted in the queue."<<endl;
    }
}

void deletion()
{
    if(front==rear)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Deletead value : "<<queue[front]<<endl;
        if(front == rear)
        {
            front = -1;
            rear =-1;
        }
        else
        {
            front = (front+1) % size;
        }
    }
}

void full()
{
    if((rear+1) % size==front)
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
    if(front==rear)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty."<<endl;
    }
}

int main()
{
    int choice;
    cout<<"1.Insertion"<<endl;
    cout<<"2.Deletion"<<endl;
    cout<<"3.Full"<<endl;
    cout<<"4.Empty"<<endl;
    cout<<"Enter the choice : "<<endl;
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
        full();
        break;

        case 4:
        empty();
        break;

        default:
        cout<<"Invalid choice"<<endl;
    }
    return 0;
}
