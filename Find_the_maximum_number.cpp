#include <iostream>
using namespace std;


int findMax(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int max = findMax(arr, n - 1);

    if (arr[n - 1] > max)
        return arr[n - 1];
    else
        return max;
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Maximum element = " << findMax(arr, n);

    return 0;
}