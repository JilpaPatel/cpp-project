#include<iostream>
using namespace std;

void swapValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout<<"Inside Function : a =  "<<a<<"b = "<<b<<endl;
}

int main()
{
    int x, y;
    cout<<"Enter value of x : "<<endl;
    cin>>x;
    cout<<"Enter value of y : "<<endl;
    cin>>y;
    cout<<"Before Function : x = "<<x<<"y = "<<y<<endl;
    swapValue(x, y);
    cout<<"After Function : x = "<<x<<"y = "<<y<<endl;
    return 0;
}