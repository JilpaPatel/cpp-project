// Array Operation(Insertion, deletion , searching, Display, Accessing 

#include<iostream>
using namespace std;
int main()
{
    int arr[100], n, choice, position, value, index, key;
    bool found = false;
    cout<<"Enter the number of element is the arraṀy : "<<endl;
    cin>>n;

    cout<<"Enter the element of the array : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"1. Insertion"<<endl;
    cout<<"2. Deletion"<<endl;
    cout<<"3. Searching"<<endl;
    cout<<"4. Display"<<endl;
    cout<<"5. Accessing"<<endl;
    cout<<"Enter the choice : "<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"Enter the position : "<<endl;
        cin>>position;
        cout<<"Enter the value : "<<endl;
        cin>>value;
        if(position<0 || position>=n)
        {
            cout<<"Enter the invalid choice"<<endl;
            break;
        }

        else
        {
            for(int i=n; i>position; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[position] = value;
            n++;
            cout<<"Array after the insertion : "<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<arr[i]<<endl;
            }
        }
        break;

        case 2: 
        cout<<"Enter the position : "<<endl;
        cin>>position;
        if(position<0 || position>=n)
        {
            cout<<"Invalid position"<<endl;
            break;
        }

        else
        {
            for(int i=position; i<n-1; i++)
            {
                arr[i]=arr[i+1];
            }
            n--;
            cout<<"Array after the deletion : "<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<arr[i]<<endl;
            }
        }
        break;

        case 3:
        cout<<"Enter the element which you found : "<<endl;
        cin>>key;

        for(int i=0; i<n; i++)
        {
            if(arr[i] == key)
            {
                cout<<"Your founded element index number : "<<i;
                found = true;
                break;
            }
        }

        if(!found)
        {
            cout<<"Your enter element innot found"<<endl;
        }
        break;

        case 4:
        for(int i=0; i<n; i++)
        {
            cout<<"array element = "<<arr[i]<<endl;
        }
        break;

        case 5:
        cout<<"Enetr the index number : "<<endl;
        cin>>index;

        if(index>=0 && index<n)
        {
            cout<<"Element : "<<arr[index];
        }
        else 
        {
            cout<<"Invalid Index"<<endl;
        }

        default :
        cout<<"Invalid Position"<<endl;
    }
    return 0;
}