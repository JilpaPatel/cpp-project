#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, key;
    bool found = false;
    cout<<"Enter the number element of the array : "<<endl;
    cin>>n;
    cout<<"Enter the elemnt of the array : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter the element which you found : "<<endl;
    cin>>key;
    {
        for(int i=0; i<n; i++)
        {
           if(arr[i]==key)
           {
              cout<<"Your founded element index number : "<<i<<endl;
              found = true;
           }
        }
    }
    
    if(!found)
    {
        cout<<"Your element is not found"<<endl;
    }
    
    return 0;
}