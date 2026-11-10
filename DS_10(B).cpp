//Selection short

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, temp, min;
    
    cout<<"Enter the element of the array : "<<endl;
    cin>>n;
    
    cout<<"Enetr the element o the array : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    for(int i=0; i<n-1; i++)
    {
        min = i;
        
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    cout<<"Shorted elemnt : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}