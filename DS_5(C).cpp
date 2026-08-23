#include<iostream>
using namespace std;
#define MAX 5
int queue[MAX];
int priorityvalue[MAX];
int size = 0;

void full()
{
    if(size == MAX)
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
    if(size == 0)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        cout<<"Queue is not empty"<<endl;
    }
}

void insertion()
{
    if(size == MAX)
    {
        cout<<"Queue is full"<<endl;
    }
    int value, priority;
    cout<<"Enter the value : "<<endl;
    cin>>value;
    cout<<"Enter the priority : "<<endl;
    cin>>priority;

    queue[size] = value;
    priorityvalue[size] = value;
    size++;
    cout<<"Value inserted in the queue : "<<value<<endl;
}

void deletion()
{
    if(size == 0)
    {
        cout<<"Queue is empty"<<endl;
    }

    int highestpriorityindex = 0;
    for(int i=1; i<size; i++)
    {
        if(priorityvalue[i]>priorityvalue[highestpriorityindex])
        {
            highestpriorityindex = i;
        }
    }
    cout<<"Deleted value : "<<queue[highestpriorityindex]<<endl;
    for(int i=highestpriorityindex; i<size-1; i++)
    {
        queue[i] = queue[i+1];
        priorityvalue[i] = priorityvalue[i+1];
    }
    size--;
}

int main()
{
    int choice;

    do
    {
       cout<<"1. Full"<<endl;
       cout<<"2. Empty"<<endl;
       cout<<"3. Insertion"<<endl;
       cout<<"4. Deletion"<<endl;
       cout<<"Enter the choice : "<<endl;
       cin>>choice;

       switch(choice)
       {
        case 1:
        full();
        break;

        case 2:
        empty();
        break;

        case 3:
        insertion();
        break;

        case 4:
        deletion();
        break;

        default :
        cout<<"Invalid choice"<<endl;
       }
    } 
    while (choice!=5);
    return 0;
}