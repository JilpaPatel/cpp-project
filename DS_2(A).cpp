#include<iostream>
using namespace std;
int main()
{
    int arr[5];
    int *p;
    cout<<"Enter 5 element : ";
    for(int i=0; i<5; i++)
    {
        cin>>arr[i];
    }

    p = &arr[4];
    cout<<"Array in reverse order : ";
    for(int i=0; i<5; i++)
    {
        cout<<*p<<" ";
        p--;
    }

    return 0;
}