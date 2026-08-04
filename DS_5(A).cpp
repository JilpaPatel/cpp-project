#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    int choice, value;

    do
    {
        cout << "1. Enter Value (Enqueue)\n";
        cout << "2. Delete Value (Dequeue)\n";
        cout << "3. Check Queue Empty or Not\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.push(value);
                cout << value << " inserted into queue.\n";
                break;

            case 2:
                if (q.empty())
                {
                    cout << "Queue is empty. Cannot delete.\n";
                }
                else
                {
                    cout << "Deleted value: " << q.front() << endl;
                    q.pop();
                }
                break;

            case 3:
                if (q.empty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;

            case 4:
                if (q.empty())
                {
                    cout << "Queue is empty.\n";
                }
                else
                {
                    queue<int> temp = q;
                    cout << "Queue elements: ";

                    while (!temp.empty())
                    {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 5:
                cout << "Program exited.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}