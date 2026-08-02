#include<iostream>
using namesapce std;
int main()
{
    int arr[100], position, value, key, choice, n, index;
    bool found = false;
    cout<<"Enter the number of element in the array : "<<endl;
    cin>>n;
    cout<<"Enter the element in the array : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<"1. Insertion"<<endl;
    cout<<"2. Deletion"<<endl;
    cout<<"3. Accessing"<<endl;
    cout<<"4. Searching"<<endl;
    cout<<"5. Display"<<endl;
    cout<<"Entre the choice : "<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"Enter the position : "<<endl;
        cin>>position;
        cout<<"Enter the value which you add in the array : "<<endl;
        cin>>value;

        if(position<0 || position>=n)
        {
            cout<<"Invalid position"<<endl;
            break;
        }

        else
        {
            for(int i=n; i>position; i--)
            {
                arr[i] = arr[i-1];
            }
            arr[position]=value;
            n++;
            cout<<"Array after the insertion : "<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<arr[i];
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
                cout<<arr[i];
            }
        }
        break;

        case 3:
        cout<<"Enter the index : "<<endl;
        cin>>index;
        if(index>=0 && index<n)
        {
            cout<<"Element = "<<arr[index];
        }
        else
        {
            cout<<"Invalid index"<<endl;
        }
        break;

        case 4:
        cout<<"Enter the element which you found : "<<endl;
        cin>>key;
        bool found = false;

        for(int i=0; i<n; i++)
        {
            if(arr[i] == key)
            {
               cout<<"Your founded element index number = "<<arr[i];
               found = true;
               break;
            }
            if(!found)
            {
                cout<<"Element is not founded"<<endl;
            }
        }
        break;

        case 5:
        cout<<"Array element : "<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<arr[i];
        }
        break;

        default :
        cout<<"Invalid Choice"<<endl;
    }
    return 0;
}