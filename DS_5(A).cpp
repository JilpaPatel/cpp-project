#include<iostream>
using namespace std;

#define SIZE 5
int main()
{
    int queue[SIZE];
    int front = -1;
    int rear = -1;
    int value, choice;

    do
    {
        cout<<"1.Insert()"<<endl;
        cout<<"2.Delete()"<<endl;
        cout<<"3.Dispaly()"<<endl;
        cout<<"4.Empty()"<<endl;
        cout<<"5.Full()"<<endl;

        cout<<"Enter the choice : "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
            if(rear == SIZE -1)
            {
                cout<<"Queue is full."<<endl;
            }
            else
            {
                cout<<"Enter the value : "<<endl;
                cin>>value;
                rear++;
                queue[rear] = value;
                cout<<value<<" Value insert into the queue."<<endl;
            }
            break;

            case 2:
            if(front == rear)
            {
                cout<<"Queue is empty."<<endl;
            }
            else
            {
                front++;
                cout<<"Value delete from the queue : "<<queue[front]<<endl;
            }
            break;

            case 3:
            cout<<"Queue : "<<endl;
            for(int i=front+1; i<=rear; i++)
            {
                cout<<queue[i]<<endl;
            }

            case 4:
            if(front == rear)
            {
                cout<<"Queue is empty."<<endl;
            }
            else
            {
                cout<<"Queue is not empty."<<endl;
            }
            break;

            case 5:
            if(front == SIZE -1)
            {
                cout<<"Queue is full."<<endl;
            }
            else
            {
                cout<<"Queue is not full."<<endl;
            }
            break;

            default :
            cout<<"Invalid choice."<<endl;
        }
    }
     while (choice!=6);
     return 0;
}