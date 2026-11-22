//Insertion Short

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, temp;
    
    cout<<"Enetr the number of element of the array : "<<endl;
    cin>>n;
    
    cout<<"Enetr the element of the array : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    for(int i=1; i<n; i++)
    {
        temp = arr[i];
        int j = i-1;
        
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    cout<<"Shorted element : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}