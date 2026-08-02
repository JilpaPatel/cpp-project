#include<iostream>
using namespace std;
const int Max = 5;
int stack[Max];
int top = -1;

void push()
{
    int value;
    if(top == Max-1)
    {
        cout<<"Stack is full."<<endl;
    }
    else
    {
        cout<<"Enter the value : "<<endl;
        cin>>value;
        top++;
        stack[top] = value;
        cout<<value<<"Value push in the stack."<<endl;
    }
}

void pop()
{
    if(top == -1)
    {
        cout<<"Stack is empty."<<endl;
    }
    else
    {
        cout<<stack[top]<<"Value pop from the stack."<<endl;
        top--;
    }
}

void peek()
{
    if(top == -1)
    {
        cout<<"Stack is empty."<<endl;
    }
    else
    {
        cout<<"Top value of the stack : "<<stack[top]<<endl;
    }
}

void empty()
{
    if(top == -1)
    {
        cout<<"Stack is empty."<<endl;
    }
    else
    {
        cout<<"Stack is not empty."<<endl;
    }
}

void full()
{
    if(top == Max-1)
    {
        cout<<"Stack is full."<<endl;
    }
    else
    {
        cout<<"Stack is not full"<<endl;
    }
}

int main()
{
    int choice;
    do
    {
    cout<<"1.Push()"<<endl;
    cout<<"2.Pop()"<<endl;
    cout<<"3.Peek()"<<endl;
    cout<<"4.empty()"<<endl;
    cout<<"5.full()"<<endl;
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
        peek();
        break;

        case 4:
        empty();
        break;

        case 5:
        full();
        break;

        default:
        cout<<"Enter the invalid choice"<<endl;
    }
    }
    while(choice!=6);
    return 0;
}