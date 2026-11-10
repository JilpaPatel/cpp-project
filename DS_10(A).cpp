//Bubble Short

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, temp;
    
    cout<<"Enetr the number of element of the array : "<<endl;
    cin>>n;
    
    cout<<"Enter the element of the array : "<<endl;
    for(int i=0;i<n; i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"Shorting element : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}