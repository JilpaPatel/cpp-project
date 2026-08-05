#include<iostream>
using namespace std;

void swapReference(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout<<"Inside Function : "<<endl;
    cout<<"First Number : "<<a<<endl;
    cout<<"Second Number : "<<b<<endl;
}

int main()
{
    int x, y;
    cout<<"Enter the value of x : "<<endl;
    cin>>x;
    cout<<"Enter the value of y : "<<endl;
    cin>>y;

    cout<<"Before function"<<endl;
    cout<<"First Number : "<<x<<endl;
    cout<<"Second Number : "<<y<<endl;
    swapReference(x , y);

    cout<<"After Function"<<endl;
    cout<<"First Number : "<<x<<endl;
    cout<<"Second Number : "<<y<<endl;

    return 0;
}